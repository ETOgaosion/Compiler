#include "semanticAnalysis.h"
#include "tools.h"

void SemanticAnalysis::enterCompUnit(SysYParser::CompUnitContext * ctx)
{
    block = 0;
    curSymbolTable = SymbolTable::getGlobalSymbolTable();
    irGenerator = IRGenerator::getIRGenerator(IRProgram::getIRProgram(programName, curSymbolTable));
    SymbolTable *funcSymbolTable = curSymbolTable->insertFuncSymbolTableSafely("putint", MetaDataType::VOID, curSymbolTable);
    funcSymbolTable->insertParamSymbolSafely("", MetaDataType::INT, false, {});
    funcSymbolTable->setParamDataTypeList();
    funcSymbolTable->setParamNum();
    irGenerator->enterFunction(funcSymbolTable);
    irGenerator->exitFunction();
    irGenerator->currentIRFunc->calFrameSize();

    funcSymbolTable = curSymbolTable->insertFuncSymbolTableSafely("putfloat", MetaDataType::VOID, curSymbolTable);
    funcSymbolTable->insertParamSymbolSafely("", MetaDataType::FLOAT, false, {});
    funcSymbolTable->setParamDataTypeList();
    funcSymbolTable->setParamNum();
    irGenerator->enterFunction(funcSymbolTable);
    irGenerator->exitFunction();
    irGenerator->currentIRFunc->calFrameSize();

    funcSymbolTable = curSymbolTable->insertFuncSymbolTableSafely("putarray", MetaDataType::VOID, curSymbolTable);
    funcSymbolTable->insertParamSymbolSafely("", MetaDataType::INT, true, {});
    funcSymbolTable->setParamDataTypeList();
    funcSymbolTable->setParamNum();
    irGenerator->enterFunction(funcSymbolTable);
    irGenerator->exitFunction();
    irGenerator->currentIRFunc->calFrameSize();

    funcSymbolTable = curSymbolTable->insertFuncSymbolTableSafely("putfarray", MetaDataType::VOID, curSymbolTable);
    funcSymbolTable->insertParamSymbolSafely("", MetaDataType::FLOAT, true, {});
    funcSymbolTable->setParamDataTypeList();
    funcSymbolTable->setParamNum();
    irGenerator->enterFunction(funcSymbolTable);
    irGenerator->exitFunction();
    irGenerator->currentIRFunc->calFrameSize();

    funcSymbolTable = curSymbolTable->insertFuncSymbolTableSafely("getint", MetaDataType::INT, curSymbolTable);
    irGenerator->enterFunction(funcSymbolTable);
    irGenerator->exitFunction();
    irGenerator->currentIRFunc->calFrameSize();

    funcSymbolTable = curSymbolTable->insertFuncSymbolTableSafely("getfloat", MetaDataType::FLOAT, curSymbolTable);
    irGenerator->enterFunction(funcSymbolTable);
    irGenerator->exitFunction();
    irGenerator->currentIRFunc->calFrameSize();

    funcSymbolTable = curSymbolTable->insertFuncSymbolTableSafely("getarray", MetaDataType::INT, curSymbolTable);
    funcSymbolTable->setParamDataTypeList();
    funcSymbolTable->setParamNum();
    irGenerator->enterFunction(funcSymbolTable);
    irGenerator->exitFunction();
    irGenerator->currentIRFunc->calFrameSize();

    funcSymbolTable = curSymbolTable->insertFuncSymbolTableSafely("getfarray", MetaDataType::FLOAT, curSymbolTable);
    funcSymbolTable->setParamDataTypeList();
    funcSymbolTable->setParamNum();
    irGenerator->enterFunction(funcSymbolTable);
    irGenerator->exitFunction();
    irGenerator->currentIRFunc->calFrameSize();
}

void SemanticAnalysis::exitCompUnit(SysYParser::CompUnitContext * ctx)
{
    if(curSymbolTable->getSymbolTableType() != TableType::GLOBAL || !curSymbolTable->lookUpFuncSymbolTable("main")) {
        throw std::runtime_error("[ERROR] > There is no main function.\n");
    }
    irGenerator->ir->targetGen(irGenerator->targetCodes, optimizationLevel);
    irGenerator->ir->print();
    irGenerator->ir->write(programName + ".ir");
    IRProgram::targetCodePrint(irGenerator->targetCodes);
    IRProgram::targetCodeWrite(irGenerator->targetCodes, programName + ".S");
}

void SemanticAnalysis::enterDecl(SysYParser::DeclContext * ctx)
{
}

void SemanticAnalysis::exitDecl(SysYParser::DeclContext * ctx)
{
}

void SemanticAnalysis::enterConstDecl(SysYParser::ConstDeclContext * ctx)
{
}

void SemanticAnalysis::exitConstDecl(SysYParser::ConstDeclContext * ctx)
{
    MetaDataType type = ctx->bType()->bMetaDataType;
    SymbolFactory symbolFactory;

    for(const auto & const_def : ctx->constDef())
    {
        // TODO: type conversion
        if (const_def->withType && const_def->type != type && const_def->type != MetaDataType::VOID) {
            const_def->value->setMetaDataType(type);
            std::vector<std::string> value = const_def->value->getValues();
            if (type == MetaDataType::INT) {
                for (auto &val: value) {
                    val = std::to_string(std::stoi(val));
                }
            }
            else {
                for (auto &val: value) {
                    val = std::to_string(std::stof(val));
                }
            }
            const_def->value->setValues(value);
        }
        AbstractSymbol *symbol = SymbolFactory::createSymbol(const_def->symbolName, SymbolType::CONST, type, const_def->isArray, const_def->shape);
        if (!curSymbolTable->insertAbstractSymbolSafely(symbol)) {
            throw std::runtime_error("[ERROR] > Redefine const symbol.\n");
        }

        if(curSymbolTable->getSymbolTableType() == TableType::GLOBAL){
            IRSymbolVariable* newConst = irGenerator->addGlobalVariable(symbol, const_def->value);
        } else {
            IRSymbolVariable* newConst = irGenerator->addSymbolVariable(block, symbol, const_def->value);
            if(const_def->value){
                IRCode* code = nullptr;
                const_def->value->setMetaDataType(type);
                switch (type) {
                    case MetaDataType::INT:
                        code = new IRAssignI(newConst, const_def->value);
                        break;
                    case MetaDataType::FLOAT:
                        code = new IRAssignF(newConst, const_def->value);
                        break;
                }
                irGenerator->addCode(code);
            }
        }
    }
}

void SemanticAnalysis::enterBType(SysYParser::BTypeContext * ctx)
{
    ctx->bMetaDataType = MetaDataType::VOID;
}

void SemanticAnalysis::exitBType(SysYParser::BTypeContext * ctx)
{
    std::string dataTypeText = ctx->getText();
    if (dataTypeText == "int") {
        ctx->bMetaDataType = MetaDataType::INT;
    }
    else if (dataTypeText == "float") {
        ctx->bMetaDataType = MetaDataType::FLOAT;
    }
    else{
        throw std::runtime_error("[ERROR] > Data Type not supported.\n");
    }
}

// ConstDef
void SemanticAnalysis::enterConstDef(SysYParser::ConstDefContext * ctx)
{
    ctx->symbolName = "";
    ctx->type = MetaDataType::VOID;
    ctx->withType = false;
    ctx->shape = {};
    ctx->isArray = false;
    ctx->constInitVal()->outside = true;
    if (!ctx->constExp().empty()) {
        if (ctx->constInitVal()) {
            for (auto val : ctx->constExp()) {
                ctx->constInitVal()->shape.push_back(std::stoi(val->val));
            }
        }
    }
}

void SemanticAnalysis::exitConstDef(SysYParser::ConstDefContext * ctx)
{
    ctx->symbolName = ctx->Ident()->getText();
    if(ctx->constExp().empty()){
        ctx->isArray = false;
    } else {
        ctx->isArray = true;
        ctx->shape.clear();
        for (auto it : ctx->constExp()) {
            ctx->shape.push_back(std::stoi(it->getText()));
        }
    }
    if (ctx->constInitVal()) {
        ctx->withType = true;
        ctx->type = ctx->constInitVal()->type;
        ctx->value = ctx->constInitVal()->value;
    }
    else {
        if (ctx->isArray) {
            ctx->value = irGenerator->ir->addMulSameImmValue(MetaDataType::INT, "0", ctx->shape);
        }
        else {
            ctx->value = new IRValue(MetaDataType::INT, "0", {}, false);
        }
    }
}

// ConstInitVal
void SemanticAnalysis::enterConstInitValOfVar(SysYParser::ConstInitValOfVarContext * ctx)
{
    if (ctx->outside && !ctx->shape.empty()) {
        throw std::runtime_error("declare array but initialize with number");
    }
    ctx->type = MetaDataType::VOID;
    ctx->isArray = false;
    ctx->value = nullptr;
}

void SemanticAnalysis::exitConstInitValOfVar(SysYParser::ConstInitValOfVarContext * ctx)
{
    ctx->type = ctx->constExp()->metaDataType;
    ctx->isArray = false;
    if (ctx->shape.empty()) {
        if (ctx->constExp()->metaDataType == MetaDataType::FLOAT) {
            ctx->value = irGenerator->addImmValue(ctx->constExp()->metaDataType, ctx->constExp()->val);
        } else {
            ctx->value = new IRValue(ctx->constExp()->metaDataType, ctx->constExp()->val, {}, false);
        }
    }
    else {
        ctx->vals.push_back(ctx->getText());
    }
    ctx->shape = {};
}

void SemanticAnalysis::enterConstInitValOfArray(SysYParser::ConstInitValOfArrayContext * ctx)
{
    ctx->type = MetaDataType::VOID;
    ctx->isArray = true;
    ctx->value = nullptr;
    for (auto it : ctx->constInitVal()) {
        it->shape = std::vector<std::size_t>(ctx->shape.begin() + 1, ctx->shape.end());
    }
}

void SemanticAnalysis::exitConstInitValOfArray(SysYParser::ConstInitValOfArrayContext * ctx)
{
    int totalSize = 0, width = 1;
    for (int i = ctx->shape.size() - 1; i >= 0; i--) {
        totalSize += ctx->shape[i] * width;
        width *= ctx->shape[i];
    }
    std::vector<std::size_t> cur(totalSize, 0);
    if(!ctx->constInitVal().empty()){
        ctx->type = ctx->constInitVal(0)->type;
        for (auto it : ctx->constInitVal()) {
            if (it->isArray) {
                if (ctx->vals.size() % ctx->shape[0]) {
                    ctx->vals.insert(ctx->vals.end(), ctx->vals.size() % ctx->shape[0], "0");
                }
                ctx->vals.insert(ctx->vals.end(), it->vals.begin(), it->vals.end());
            }
            else {
                ctx->vals.push_back(it->vals[0]);
            }
        }
    } else {
        ctx->type = MetaDataType::VOID;
        ctx->vals.insert(ctx->vals.end(), totalSize, "0");
    }

    ctx->isArray = true;

    if (ctx->outside) {
        if (!ctx->constInitVal().empty()) {
            ctx->value = irGenerator->ir->addMulImmValue(ctx->type, ctx->vals);
        } else {
            ctx->value = new IRValue(MetaDataType::INT, "0", {}, false);
        }
    }
}

// VarDecl
void SemanticAnalysis::enterVarDecl(SysYParser::VarDeclContext * ctx)
{
}
void SemanticAnalysis::exitVarDecl(SysYParser::VarDeclContext * ctx)
{
    MetaDataType type = ctx->bType()->bMetaDataType;
    SymbolFactory symbolFactory;

    for(const auto & var_def : ctx->varDef())
    {
        if (var_def->withType && var_def->type != type && var_def->type != MetaDataType::VOID) {
            // TODO: type conversion
        }
        AbstractSymbol *symbol = SymbolFactory::createSymbol(var_def->symbolName, SymbolType::VAR, type, var_def->isArray, var_def->shape);
        if (!curSymbolTable->insertAbstractSymbolSafely(symbol)) {
            throw std::runtime_error("[ERROR] > Redefine var symbol. " + symbol->getSymbolName());
        }

        if(curSymbolTable->getSymbolTableType() == TableType::GLOBAL){
            IRSymbolVariable* newVar = irGenerator->addGlobalVariable(symbol, var_def->value);
        } else {
            IRSymbolVariable* newVar = irGenerator->addSymbolVariable(block, symbol, var_def->value);
            newVar->setAssigned();
            IRCode* code = nullptr;
            var_def->value->setMetaDataType(type);
            if(var_def->value){
                switch (type) {
                    case MetaDataType::INT:
                        code = new IRAssignI(newVar, var_def->value);
                        break;
                    case MetaDataType::FLOAT:
                        code = new IRAssignF(newVar, var_def->value);
                        break;
                }
            }
            irGenerator->addCode(code);
        }
    }
}

void SemanticAnalysis::enterVarDef(SysYParser::VarDefContext * ctx)
{
    ctx->symbolName = "";
    ctx->type = MetaDataType::VOID;
    ctx->withType = false;
    ctx->shape = {};
    ctx->isArray = false;
    if (ctx->initVal()) {
        ctx->initVal()->outside = true;
    }
    if (ctx->constExp().size() > 0) {
        if (ctx->initVal()) {
            for (auto val : ctx->constExp()) {
                ctx->initVal()->shape.push_back(std::stoi(val->val));
            }
        }
    }
}

void SemanticAnalysis::exitVarDef(SysYParser::VarDefContext * ctx)
{
    ctx->symbolName = ctx->Ident()->getText();
    if(ctx->constExp().empty()){
        ctx->isArray = false;
    } else {
        ctx->isArray = true;
        ctx->shape.clear();
        for (auto it : ctx->constExp()) {
            ctx->shape.push_back(std::stoi(it->getText()));
        }
    }
    if (ctx->initVal()) {
        ctx->withType = true;
        ctx->type = ctx->initVal()->type;
        ctx->value = ctx->initVal()->value;
    }
    else {
        if (ctx->isArray) {
            ctx->value = irGenerator->ir->addMulSameImmValue(MetaDataType::INT, "0", ctx->shape);
        }
        else {
            ctx->value = new IRValue(MetaDataType::INT, "0", {}, false);
        }
    }
}

void SemanticAnalysis::enterInitValOfVar(SysYParser::InitValOfVarContext *ctx) {
    if (ctx->outside && !ctx->shape.empty()) {
        throw std::runtime_error("declare array but initialize with number");
    }
    ctx->type = MetaDataType::VOID;
    ctx->isArray = false;
    ctx->value = nullptr;
}

void SemanticAnalysis::exitInitValOfVar(SysYParser::InitValOfVarContext *ctx) {
    ctx->type = ctx->exp()->metaDataType;
    ctx->isArray = false;
    if (ctx->shape.empty()) {
        ctx->value = ctx->exp()->operand;
    }
    else {
        ctx->vals.push_back(ctx->getText());
    }
    ctx->shape = {};
}

void SemanticAnalysis::enterInitValOfArray(SysYParser::InitValOfArrayContext *ctx) {
    ctx->type = MetaDataType::VOID;
    ctx->isArray = true;
    ctx->value = nullptr;
    for (auto it : ctx->initVal()) {
        it->shape = std::vector<std::size_t>(ctx->shape.begin() + 1, ctx->shape.end());
    }
}

void SemanticAnalysis::exitInitValOfArray(SysYParser::InitValOfArrayContext *ctx) {
    int totalSize = 0, width = 1;
    for (int i = ctx->shape.size() - 1; i >= 0; i--) {
        totalSize += ctx->shape[i] * width;
        width *= ctx->shape[i];
    }
    std::vector<std::size_t> cur(totalSize, 0);
    if(!ctx->initVal().empty()){
        ctx->type = ctx->initVal(0)->type;
        for (auto it : ctx->initVal()) {
            if (it->isArray) {
                if (ctx->vals.size() % ctx->shape[0]) {
                    ctx->vals.insert(ctx->vals.end(), ctx->vals.size() % ctx->shape[0], "0");
                }
                ctx->vals.insert(ctx->vals.end(), it->vals.begin(), it->vals.end());
            }
            else {
                ctx->vals.push_back(it->vals[0]);
            }
        }
    } else {
        ctx->type = MetaDataType::VOID;
        ctx->vals.insert(ctx->vals.end(), totalSize, "0");
    }

    ctx->isArray = true;

    if (ctx->outside) {
        if (!ctx->initVal().empty()) {
            ctx->value = irGenerator->ir->addMulImmValue(ctx->type, ctx->vals);
        } else {
            ctx->value = new IRValue(MetaDataType::INT, "0", {}, false);
        }
    }
}

void SemanticAnalysis::enterFuncDef(SysYParser::FuncDefContext * ctx)
{
    if (curSymbolTable->getSymbolTableType() != TableType::GLOBAL) {
        throw std::runtime_error("[ERROR] > cannot define function in non-global area.\n");
    }

    std::string datatype = ctx->funcType()->getText();
    MetaDataType returnType;
    if (datatype == "void") {
        returnType = MetaDataType::VOID;
    }
    else if (datatype == "int") {
        returnType = MetaDataType::INT;
    }
    else if (datatype == "float") {
        returnType = MetaDataType::FLOAT;
    }
    else{
        throw std::runtime_error("[ERROR] > Data Type not supported.\n");
    }

    if (ctx->Ident()->getText() == "main") {
        if (returnType != MetaDataType::INT || ctx->funcFParams()) {
            throw std::runtime_error("[ERROR] > wrong definition of main function");
        }
    }

    SymbolTable *funcSymbolTable = new FuncSymbolTable(ctx->Ident()->getText(), returnType);
    if (!curSymbolTable->insertFuncSymbolTableSafely(funcSymbolTable)) {
        throw std::runtime_error("[ERROR] > Redefine function of same name.\n");
    }
    funcSymbolTable->setParentSymbolTable(curSymbolTable);
    curSymbolTable = funcSymbolTable;

    irGenerator->enterFunction(funcSymbolTable);
}

void SemanticAnalysis::exitFuncDef(SysYParser::FuncDefContext * ctx)
{
    if (!ctx->funcBlock()->hasReturn && (curSymbolTable->getReturnType() != MetaDataType::VOID)) {
        throw std::runtime_error("[ERROR] > Non void function has no return.\n");
    }
    if (ctx->funcType()->funcMetaDataType == MetaDataType::VOID && ctx->funcBlock()->funcBlockItem().back()->getText().find("return", 0) != std::string::npos) {
        irGenerator->exitFunction();
    }
}

void SemanticAnalysis::enterFuncType(SysYParser::FuncTypeContext * ctx)
{
}

void SemanticAnalysis::exitFuncType(SysYParser::FuncTypeContext * ctx)
{
}

void SemanticAnalysis::enterFuncFParams(SysYParser::FuncFParamsContext * ctx)
{
}

void SemanticAnalysis::exitFuncFParams(SysYParser::FuncFParamsContext * ctx)
{
    curSymbolTable->setParamNum();
    curSymbolTable->setParamDataTypeList();
    int gr = 0, fr = 0;
    for(auto & param : ctx->funcFParam()){
        IRValue* g_index = nullptr;
        IRValue* f_index = nullptr;
        // add ParamVariable
        irGenerator->currentIRFunc->addParamVariable(param->symbolVar);

        // add getParam code
        IRCode* code = nullptr;
        if(param->isArray){
            g_index = new IRValue(MetaDataType::INT, std::to_string(gr), {}, false);
            code = new IRGetParamA(param->symbolVar, g_index);
            gr++;
        } else {
            switch (param->paramType) {
                case MetaDataType::INT:
                    g_index = new IRValue(MetaDataType::INT, std::to_string(gr), {}, false);
                    code = new IRGetParamI(param->symbolVar, g_index);
                    gr++;
                    break;
                case MetaDataType::FLOAT:
                    f_index = new IRValue(MetaDataType::INT, std::to_string(fr), {}, false);
                    code = new IRGetParamF(param->symbolVar, f_index);
                    fr++;
                    break;
            }
        }
        irGenerator->addCode(code);
    }
}

void SemanticAnalysis::enterFuncFParam(SysYParser::FuncFParamContext * ctx)
{
}
void SemanticAnalysis::exitFuncFParam(SysYParser::FuncFParamContext * ctx)
{
    SymbolFactory symbolFactory;
    AbstractSymbol *funcParamSymbol = nullptr;
    if (ctx->brackets()) {
        funcParamSymbol = SymbolFactory::createSymbol(ctx->Ident()->getText(), SymbolType::PARAM, ctx->bType()->bMetaDataType, true, ctx->brackets()->shape);
    }
    else {
        funcParamSymbol = SymbolFactory::createSymbol(ctx->Ident()->getText(), SymbolType::PARAM, ctx->bType()->bMetaDataType, false, {});
    }
    if (!curSymbolTable->insertParamSymbolSafely(funcParamSymbol)) {
        throw std::runtime_error("[ERROR] > Redefine Function ParamSymbol.\n");
    }

    auto *newParam = new IRSymbolVariable(funcParamSymbol, nullptr, false);
    ctx->symbolVar = newParam;
    irGenerator->currentIRFunc->addParamVariable(newParam);
    ctx->isArray = ctx->brackets() != nullptr;
    ctx->paramType = ctx->bType()->bMetaDataType;
}

void SemanticAnalysis::enterBrackets(SysYParser::BracketsContext * ctx) {}

void SemanticAnalysis::exitBrackets(SysYParser::BracketsContext * ctx) {
    for (auto it : ctx->exp()) {
        ctx->shape.push_back(stoi(it->operand->getValue()));
    }
}

void SemanticAnalysis::enterFuncBlock(SysYParser::FuncBlockContext * ctx)
{
    ctx->hasReturn = false;
    if (curSymbolTable->getSymbolTableType() != TableType::FUNC) {
        SymbolTable *blkSymbolTable = new BlockSymbolTable(curSymbolTable);
        curSymbolTable->insertBlockSymbolTable(blkSymbolTable);
        curSymbolTable = blkSymbolTable;
    }
    if (ctx->docLVal) {
        for(auto it : ctx->funcBlockItem()) {
            it->docLVal = true;
        }
    }
}

void SemanticAnalysis::exitFuncBlock(SysYParser::FuncBlockContext * ctx)
{
    curSymbolTable = curSymbolTable->getParentSymbolTable();
    for (auto & it : ctx->funcBlockItem()) {
        if (it->hasReturn) {
            if (ctx->hasReturn) {
                if (ctx->returnType != it->returnType) {
                    throw std::runtime_error("[ERROR] > return type mismatch");
                }
            }
            else {
                ctx->hasReturn = true;
                ctx->returnType = it->returnType;
            }
        }
    }
    std::unordered_map<IROperand *, std::vector<IROperand *>> toJoinVarDoc;
    if (ctx->docLVal) {
        for(auto it : ctx->funcBlockItem()) {
            for (auto in_it : it->lValDoc) {
                if (toJoinVarDoc.find(in_it.first) != toJoinVarDoc.end()) {
                    for (auto operand : in_it.second) {
                        toJoinVarDoc[in_it.first].push_back(operand);
                    }
                }
                else {
                    toJoinVarDoc[in_it.first] = std::vector<IROperand *>(in_it.second.begin(), in_it.second.end());
                }
            }
        }
        ctx->lValDoc = toJoinVarDoc;
    }
}

void SemanticAnalysis::enterFuncBlockItem(SysYParser::FuncBlockItemContext * ctx)
{
    ctx->hasReturn = false;
    if (ctx->stmt() && ctx->docLVal) {
        ctx->stmt()->docLVal = true;
        ctx->stmt()->lValDoc.clear();
    }
}

void SemanticAnalysis::exitFuncBlockItem(SysYParser::FuncBlockItemContext * ctx)
{
    if (ctx->stmt() && ctx->stmt()->hasReturn) {
        ctx->hasReturn = true;
        ctx->returnType = ctx->stmt()->returnType;
    }
    if (ctx->stmt() && ctx->docLVal) {
        ctx->lValDoc = ctx->stmt()->lValDoc;
    }
}

void SemanticAnalysis::enterBlock(SysYParser::BlockContext * ctx)
{
    ctx->hasReturn = false;
    ctx->returnType = MetaDataType::VOID;
    SymbolTable *blkSymbolTable = new BlockSymbolTable(curSymbolTable);
    curSymbolTable->insertBlockSymbolTable(blkSymbolTable);
    curSymbolTable = blkSymbolTable;

    block++;
    if (ctx->docLVal) {
        for(auto it : ctx->blockItem()) {
            it->docLVal = true;
        }
    }
}

void SemanticAnalysis::exitBlock(SysYParser::BlockContext * ctx)
{
    curSymbolTable = curSymbolTable->getParentSymbolTable();
    for (auto & it : ctx->blockItem()) {
        if (it->hasReturn) {
            throw std::runtime_error("[NO ERROR] Block return");
            if (ctx->hasReturn) {
                if (ctx->returnType != it->returnType) {
                    throw std::runtime_error("[ERROR] > return type mismatch.  " + it->getText());
                }
            }
            else {
                ctx->hasReturn = true;
                ctx->returnType = it->returnType;
            }
        }
    }

    block--;
    std::unordered_map<IROperand *, std::vector<IROperand *>> toJoinVarDoc;
    if (ctx->docLVal) {
        for(auto it : ctx->blockItem()) {
            for (auto in_it : it->lValDoc) {
                if (toJoinVarDoc.find(in_it.first) != toJoinVarDoc.end()) {
                    for (auto operand : in_it.second) {
                        toJoinVarDoc[in_it.first].push_back(operand);
                    }
                }
                else {
                    toJoinVarDoc[in_it.first] = std::vector<IROperand *>(in_it.second.begin(), in_it.second.end());
                }
            }
        }
        ctx->lValDoc = toJoinVarDoc;
    }
}

void SemanticAnalysis::enterBlockItem(SysYParser::BlockItemContext * ctx)
{
    ctx->hasReturn = false;
    ctx->returnType = MetaDataType::VOID;
    if (ctx->subStmt() && ctx->docLVal) {
        ctx->subStmt()->docLVal = true;
        ctx->subStmt()->lValDoc.clear();
    }
}

void SemanticAnalysis::exitBlockItem(SysYParser::BlockItemContext * ctx)
{
    if (ctx->subStmt() && ctx->subStmt()->hasReturn) {
        throw std::runtime_error("[NO ERROR] Block item return");
        ctx->hasReturn = true;
        ctx->returnType = ctx->subStmt()->returnType;
    }
    if (ctx->subStmt() && ctx->docLVal) {
        ctx->lValDoc = ctx->subStmt()->lValDoc;
    }
}

void SemanticAnalysis::enterStmtAssignment(SysYParser::StmtAssignmentContext * ctx)
{
    ctx->hasReturn = false;

    AbstractSymbol *searchLVal = curSymbolTable->lookUpAbstractSymbolGlobal(ctx->lVal()->getText());
}

void SemanticAnalysis::exitStmtAssignment(SysYParser::StmtAssignmentContext * ctx)
{
    if (ctx->lVal()->symbolType == SymbolType::CONST) {
        throw std::runtime_error("[ERROR] > cannot assign to a CONST statement.\n");
    }
    if (ctx->lVal()->lValMetaDataType != ctx->exp()->metaDataType) {
        throw std::runtime_error("[ERROR] > stmt type mismatch in assignment. " + std::to_string(static_cast<int>(ctx->lVal()->lValMetaDataType)) + std::to_string(static_cast<int>(ctx->exp()->metaDataType)));
    }

    if (ctx->lVal()->indexOperand) { // array[index] = value
        IRCode *assignCode = nullptr;
        switch (ctx->lVal()->lValMetaDataType) {
            case MetaDataType::INT:
                assignCode = new IRAssignArrayElemI(ctx->exp()->operand, ctx->lVal()->identOperand,
                                                    ctx->lVal()->indexOperand);
                break;
            case MetaDataType::FLOAT:
                assignCode = new IRAssignArrayElemF(ctx->exp()->operand, ctx->lVal()->identOperand,
                                                    ctx->lVal()->indexOperand);
                break;
        }
        irGenerator->addCode(assignCode);
    } else { // value_a = value_b
        // consider assigned attribute of IRSymbolVariable
        IROperand* operand = nullptr;
        if(ctx->lVal()->identOperand->getAssigned()) {
            IRTempVariable *temp = irGenerator->addTempVariable(ctx->lVal()->identOperand);
            ctx->lVal()->identOperand->addHistorySymbol(temp);
            irGenerator->addCode(new IRReplace(temp, ctx->lVal()->identOperand));
            operand = temp;
            if (ctx->docLVal) {
                if (ctx->lValDoc.find(ctx->lVal()->identOperand) != ctx->lValDoc.end()) {
                    ctx->lValDoc[ctx->lVal()->identOperand].push_back(temp);
                    if (std::find(ctx->lValDoc[ctx->lVal()->identOperand].begin(), ctx->lValDoc[ctx->lVal()->identOperand].end(), ctx->lVal()->identOperand) != ctx->lValDoc[ctx->lVal()->identOperand].end()) {
                        ctx->lValDoc[ctx->lVal()->identOperand].push_back(ctx->lVal()->identOperand);
                    }
                }
                else {
                    ctx->lValDoc[ctx->lVal()->identOperand] = std::vector<IROperand *>(1, temp);
                    ctx->lValDoc[ctx->lVal()->identOperand].push_back(ctx->lVal()->identOperand);
                }
            }
        } else {
            ctx->lVal()->identOperand->setAssigned();
            operand = ctx->lVal()->identOperand;
            if (ctx->docLVal) {
                if (ctx->lValDoc.find(ctx->lVal()->identOperand) != ctx->lValDoc.end()) {
                    ctx->lValDoc[ctx->lVal()->identOperand].push_back(ctx->lVal()->identOperand);
                }
                else {
                    ctx->lValDoc[ctx->lVal()->identOperand] = std::vector<IROperand *>(1, ctx->lVal()->identOperand);
                }
            }
        }
        IRCode *assignCode = nullptr;
        switch (ctx->lVal()->lValMetaDataType) {
            case MetaDataType::INT:
                assignCode = new IRAssignI(operand, ctx->exp()->operand);
                break;
            case MetaDataType::FLOAT:
                assignCode = new IRAssignF(operand, ctx->exp()->operand);
                break;
        }
        irGenerator->addCode(assignCode);
    }

    if(!ctx->codes.empty())
        irGenerator->addCodes(ctx->codes);
}

void SemanticAnalysis::enterStmtExpression(SysYParser::StmtExpressionContext * ctx)
{
    ctx->hasReturn = false;
}

void SemanticAnalysis::exitStmtExpression(SysYParser::StmtExpressionContext * ctx)
{
    if(!ctx->codes.empty())
        irGenerator->addCodes(ctx->codes);
}

void SemanticAnalysis::enterStmtBlock(SysYParser::StmtBlockContext * ctx)
{
    ctx->hasReturn = false;
    SymbolTable *blkSymbolTable = new BlockSymbolTable(curSymbolTable);
    curSymbolTable->insertBlockSymbolTable(blkSymbolTable);
    curSymbolTable = blkSymbolTable;
    if (ctx->docLVal) {
        ctx->funcBlock()->docLVal = true;
        ctx->funcBlock()->lValDoc.clear();
    }
}

void SemanticAnalysis::exitStmtBlock(SysYParser::StmtBlockContext * ctx)
{
    curSymbolTable = curSymbolTable->getParentSymbolTable();
    if (ctx->funcBlock() && ctx->funcBlock()->hasReturn) {
        ctx->hasReturn = true;
        ctx->returnType = ctx->funcBlock()->returnType;
    }

    if(!ctx->codes.empty())
        irGenerator->addCodes(ctx->codes);

    if (ctx->docLVal) {
        ctx->lValDoc = ctx->funcBlock()->lValDoc;
    }
}

void SemanticAnalysis::enterStmtCtrlSeq(SysYParser::StmtCtrlSeqContext * ctx)
{
    ctx->hasReturn = false;


    IRLabel* falseLabel = irGenerator->addLabel();
    ctx->cond()->falseLabel = falseLabel;
    std::vector<IRCode *> codes;
    if(ctx->getText().rfind("if", 0) == 0){
        IRCode *code = new IRAddLabel(falseLabel);
        if (ctx->stmt().size() > 1) {
            IRLabel *exitLabel = irGenerator->addLabel();
            codes.push_back(new IRGoto(exitLabel));
            ctx->stmt(1)->codes = std::vector<IRCode *>(1, new IRAddLabel(exitLabel));
        }
        codes.push_back(code);
        ctx->stmt(0)->codes = codes;
    } else if (ctx->getText().rfind("while", 0) == 0){
        IRLabel* beginLabel = irGenerator->enterWhile();
        IRCode *code = new IRGoto(beginLabel);
        codes.push_back(code);
        code = new IRAddLabel(falseLabel);
        codes.push_back(code);
        ctx->subStmt()->codes = codes;
        whileFalse.push_back(falseLabel);
        whileBegin.push_back(beginLabel);
    } else {
        throw std::runtime_error("[ERROR] > not if or while stmt\n");
    }

    for (auto it : ctx->stmt()) {
        it->docLVal = true;
        it->lValDoc.clear();
    }
    if (ctx->subStmt()) {
        ctx->subStmt()->docLVal = true;
        ctx->subStmt()->lValDoc.clear();
    }
}

void SemanticAnalysis::exitStmtCtrlSeq(SysYParser::StmtCtrlSeqContext * ctx)
{
    for (auto & s : ctx->stmt()) {
        if (s->hasReturn) {
            ctx->hasReturn = true;
            break;
        }
    }
    if (ctx->subStmt() && ctx->subStmt()->hasReturn) {
        ctx->hasReturn = true;
        ctx->returnType = ctx->subStmt()->returnType;
    }

    if (ctx->getText().rfind("while", 0) == 0){
        whileBegin.pop_back();
        whileFalse.pop_back();
    }
    if(!ctx->codes.empty())
        irGenerator->addCodes(ctx->codes);

    std::unordered_map<IROperand *, std::vector<IROperand *>> lVal;
    lVal.clear();
    for (auto stmt : ctx->stmt()) {
        for (const auto& it: stmt->lValDoc) {
            if (lVal.find(it.first) != lVal.end()) {
                for (auto in_it : it.second) {
                    if (std::find(lVal[it.first].begin(), lVal[it.first].end(), in_it) == lVal[it.first].end()) {
                        lVal[it.first].push_back(in_it);
                    }
                }
            }
            else {
                lVal[it.first] = std::vector<IROperand *>(it.second.begin(), it.second.end());
            }
        }
    }

    for (auto it : lVal) {
        IRTempVariable *newTemp = irGenerator->addTempVariable(it.first->getMetaDataType());
        it.first->addHistorySymbol(newTemp);
        newTemp->setAliasToVar();
        newTemp->setParentVariable(it.first);
        irGenerator->addCode(new IRReplace(it.first, newTemp));
        irGenerator->addCode(new IRPhi(newTemp, it.second));

        if (ctx->docLVal) {
            if (ctx->lValDoc.find(it.first) != ctx->lValDoc.end()) {
                ctx->lValDoc[it.first].push_back(newTemp);
            }
            else {
                ctx->lValDoc[it.first] = std::vector<IROperand *>(1, newTemp);
            }
        }
    }

    if (ctx->subStmt()) {
        for (const auto& it: ctx->subStmt()->lValDoc) {
            IRTempVariable *newTemp = irGenerator->addTempVariable(it.first->getMetaDataType());
            it.first->addHistorySymbol(newTemp);
            newTemp->setAliasToVar();
            newTemp->setParentVariable(it.first);
            irGenerator->addCode(new IRReplace(it.first, newTemp));
            irGenerator->addCode(new IRPhi(newTemp, it.second));
            lVal[it.first] = std::vector<IROperand *>(1, newTemp);
        }

        if (ctx->docLVal) {
            ctx->lValDoc = lVal;
        }
    }
}

void SemanticAnalysis::enterStmtReturn(SysYParser::StmtReturnContext * ctx)
{

}

void SemanticAnalysis::exitStmtReturn(SysYParser::StmtReturnContext * ctx)
{
    if (ctx->exp() && ctx->exp()->isArray) {
        throw std::runtime_error("[ERROR] > never return an array.\n");
    }
    if (curSymbolTable->getSymbolTableType() == TableType::FUNC) {
        if ((!ctx->exp() && curSymbolTable->getReturnType() != MetaDataType::VOID) || (ctx->exp() && ctx->exp()->metaDataType != curSymbolTable->getReturnType())) {
            throw std::runtime_error("[ERROR] > stmt return type mismatch." + std::to_string(static_cast<int>(curSymbolTable->getSymbolTableType())));
        }
    }
    ctx->hasReturn = true;
    ctx->returnType = ctx->exp() ? ctx->exp()->metaDataType : MetaDataType::VOID;

    IRCode *code = nullptr;

    if(ctx->exp()){
        switch(ctx->exp()->metaDataType){
            case MetaDataType::INT:
                code = new IRReturnI(ctx->exp()->operand, new IRSymbolFunction(irGenerator->currentIRFunc->getFuncSymbolTable()));
                break;
            case MetaDataType::FLOAT:
                code = new IRReturnF(ctx->exp()->operand, new IRSymbolFunction(irGenerator->currentIRFunc->getFuncSymbolTable()));
                break;
            default:
                break;
        }
    } else {
        code = new IRReturnV(new IRSymbolFunction(irGenerator->currentIRFunc->getFuncSymbolTable()));
    }
    irGenerator->addCode(code);
    if(!ctx->codes.empty())
        irGenerator->addCodes(ctx->codes);
}

void SemanticAnalysis::enterSubStmtAssignment(SysYParser::SubStmtAssignmentContext * ctx)
{
    ctx->hasReturn = false;
    ctx->returnType = MetaDataType::VOID;

    AbstractSymbol *searchLVal = curSymbolTable->lookUpAbstractSymbolGlobal(ctx->lVal()->getText());

    if(searchLVal->getIsArray()){
        IRTempVariable *temp = irGenerator->addTempVariable(searchLVal->getMetaDataType());
        ctx->exp()->indexOperand = temp;
        auto* zero = new IRValue(MetaDataType::INT, std::to_string(0), {}, false);
        IRCode* code = new IRAssignI(temp, zero);
        irGenerator->addCode(code);

        IRLabel* beginArray = irGenerator->enterWhile();
        ctx->beginArray = beginArray;
    }
}

void SemanticAnalysis::exitSubStmtAssignment(SysYParser::SubStmtAssignmentContext * ctx)
{
    if (ctx->lVal()->symbolType == SymbolType::CONST) {
        throw std::runtime_error("[ERROR] > cannot assign to a CONST statement.\n");
    }
    if (ctx->lVal()->lValMetaDataType != ctx->exp()->metaDataType) {
        throw std::runtime_error("[ERROR] > substmt: type mismatch in assignment. " + std::to_string(static_cast<int>(ctx->lVal()->lValMetaDataType)) + std::to_string(static_cast<int>(ctx->exp()->metaDataType)));
    }

    if(ctx->lVal()->indexOperand){ // array[index] = value
        IRCode* assignCode = nullptr;
        switch (ctx->lVal()->lValMetaDataType) {
            case MetaDataType::INT:
                assignCode = new IRAssignArrayElemI(ctx->exp()->operand, ctx->lVal()->identOperand, ctx->lVal()->indexOperand);
                break;
            case MetaDataType::FLOAT:
                assignCode = new IRAssignArrayElemF(ctx->exp()->operand, ctx->lVal()->identOperand, ctx->lVal()->indexOperand);
                break;
        }
        irGenerator->addCode(assignCode);
    } else { // value_a = value_b
        // consider assigned attribute of IRSymbolVariable
        IROperand* operand = nullptr;
        if(ctx->lVal()->identOperand->getAssigned()) {
            IRTempVariable *temp = irGenerator->addTempVariable(ctx->lVal()->identOperand);
            ctx->lVal()->identOperand->addHistorySymbol(temp);
            irGenerator->addCode(new IRReplace(temp, ctx->lVal()->identOperand));
            operand = temp;
            if (ctx->docLVal) {
                if (ctx->lValDoc.find(ctx->lVal()->identOperand) != ctx->lValDoc.end()) {
                    ctx->lValDoc[ctx->lVal()->identOperand].push_back(temp);
                    if (std::find(ctx->lValDoc[ctx->lVal()->identOperand].begin(), ctx->lValDoc[ctx->lVal()->identOperand].end(), ctx->lVal()->identOperand) != ctx->lValDoc[ctx->lVal()->identOperand].end()) {
                        ctx->lValDoc[ctx->lVal()->identOperand].push_back(ctx->lVal()->identOperand);
                    }
                }
                else {
                    ctx->lValDoc[ctx->lVal()->identOperand] = std::vector<IROperand *>(1, temp);
                    ctx->lValDoc[ctx->lVal()->identOperand].push_back(ctx->lVal()->identOperand);
                }
            }
        } else {
            ctx->lVal()->identOperand->setAssigned();
            operand = ctx->lVal()->identOperand;
            if (ctx->docLVal) {
                if (ctx->lValDoc.find(ctx->lVal()->identOperand) != ctx->lValDoc.end()) {
                    ctx->lValDoc[ctx->lVal()->identOperand].push_back(ctx->lVal()->identOperand);
                }
                else {
                    ctx->lValDoc[ctx->lVal()->identOperand] = std::vector<IROperand *>(1, ctx->lVal()->identOperand);
                }
            }
        }
        IRCode *assignCode = nullptr;
        switch (ctx->lVal()->lValMetaDataType) {
            case MetaDataType::INT:
                assignCode = new IRAssignI(operand, ctx->exp()->operand);
                break;
            case MetaDataType::FLOAT:
                assignCode = new IRAssignF(operand, ctx->exp()->operand);
                break;
        }
        irGenerator->addCode(assignCode);
    }

    if(!ctx->codes.empty())
        irGenerator->addCodes(ctx->codes);
}

void SemanticAnalysis::enterSubStmtExpression(SysYParser::SubStmtExpressionContext * ctx)
{
    ctx->hasReturn = false;
    ctx->returnType = MetaDataType::VOID;
}

void SemanticAnalysis::exitSubStmtExpression(SysYParser::SubStmtExpressionContext * ctx)
{
    if(!ctx->codes.empty())
        irGenerator->addCodes(ctx->codes);
}

void SemanticAnalysis::enterSubStmtBlock(SysYParser::SubStmtBlockContext * ctx)
{
    SymbolTable *blkSymbolTable = new BlockSymbolTable(curSymbolTable);
    curSymbolTable->insertBlockSymbolTable(blkSymbolTable);
    curSymbolTable = blkSymbolTable;
    ctx->hasReturn = false;
    ctx->returnType = MetaDataType::VOID;
    if (ctx->docLVal) {
        ctx->block()->docLVal = true;
        ctx->block()->lValDoc.clear();
    }
}

void SemanticAnalysis::exitSubStmtBlock(SysYParser::SubStmtBlockContext * ctx)
{
    curSymbolTable = curSymbolTable->getParentSymbolTable();
    ctx->hasReturn = ctx->block()->hasReturn;
    ctx->returnType = ctx->block()->returnType;
    if (ctx->hasReturn && curSymbolTable->getSymbolTableType() == TableType::FUNC) {
        if (ctx->returnType != curSymbolTable->getReturnType()) {
            throw std::runtime_error("[ERROR] > SubStmtBlock return type mismatch.  " + ctx->getText());
        }
    }
    if(!ctx->codes.empty())
        irGenerator->addCodes(ctx->codes);

    if (ctx->docLVal) {
        ctx->lValDoc = ctx->block()->lValDoc;
    }
}

void SemanticAnalysis::enterSubStmtCtrlSeq(SysYParser::SubStmtCtrlSeqContext * ctx)
{
    ctx->hasReturn = false;
    ctx->returnType = MetaDataType::VOID;

    if (ctx->cond()) {
        IRLabel* falseLabel = irGenerator->addLabel();
        ctx->cond()->falseLabel = falseLabel;
        std::vector<IRCode *> codes;
        if(ctx->getText().rfind("if", 0) == 0){
            IRCode *code = new IRAddLabel(falseLabel);
            if (ctx->subStmt().size() > 1) {
                IRLabel *exitLabel = irGenerator->addLabel();
                codes.push_back(new IRGoto(exitLabel));
                ctx->subStmt(1)->codes = std::vector<IRCode *>(1, new IRAddLabel(exitLabel));
            }
            codes.push_back(code);
            ctx->subStmt(0)->codes = codes;
        } else if (ctx->getText().rfind("while", 0) == 0){
            IRLabel* beginLabel = irGenerator->enterWhile();
            IRCode *code = new IRGoto(beginLabel);
            codes.push_back(code);
            code = new IRAddLabel(falseLabel);
            codes.push_back(code);
            ctx->subStmt(0)->codes = codes;
            whileFalse.push_back(falseLabel);
            whileBegin.push_back(beginLabel);
        }
    }

    for (auto it : ctx->subStmt()) {
        it->docLVal = true;
        it->lValDoc.clear();
    }
}

void SemanticAnalysis::exitSubStmtCtrlSeq(SysYParser::SubStmtCtrlSeqContext * ctx)
{
    for (auto & s : ctx->subStmt()) {
        if (s->hasReturn) {
            if (curSymbolTable->getSymbolTableType() == TableType::FUNC) {
                if (s->returnType != curSymbolTable->getReturnType()) {
                    throw std::runtime_error("[ERROR] > return type mismatch.  " + s->getText());
                }
            }
            else {
                if (ctx->hasReturn) {
                    if (s->returnType != ctx->returnType) {
                        throw std::runtime_error("[ERROR] > return type mismatch.  " + s->getText());
                    }
                }
                else {
                    ctx->hasReturn = true;
                    ctx->returnType = s->returnType;
                }
            }
        }
    }

    if(ctx->getText().rfind("break", 0) == 0){
        IRLabel* falseLabel = whileFalse.back();
        IRCode* code = new IRGoto(falseLabel);
        irGenerator->addCode(code);
    } else if(ctx->getText().rfind("continue", 0) == 0){
        IRLabel* beginLabel = whileBegin.back();
        IRCode* code = new IRGoto(beginLabel);
        irGenerator->addCode(code);
    } else if (ctx->getText().rfind("while", 0) == 0){
        whileFalse.pop_back();
        whileBegin.pop_back();
    }

    if(!ctx->codes.empty())
        irGenerator->addCodes(ctx->codes);

    std::unordered_map<IROperand *, std::vector<IROperand *>> lVal;
    lVal.clear();
    for (auto stmt : ctx->subStmt()) {
        for (const auto& it: stmt->lValDoc) {
            if (lVal.find(it.first) != lVal.end()) {
                for (auto in_it : it.second) {
                    if (std::find(lVal[it.first].begin(), lVal[it.first].end(), in_it) == lVal[it.first].end()) {
                        lVal[it.first].push_back(in_it);
                    }
                }
            }
            else {
                lVal[it.first] = std::vector<IROperand *>(it.second.begin(), it.second.end());
            }
        }
    }

    for (auto it : lVal) {
        IRTempVariable *newTemp = irGenerator->addTempVariable(it.first->getMetaDataType());
        it.first->addHistorySymbol(newTemp);
        newTemp->setAliasToVar();
        newTemp->setParentVariable(it.first);
        irGenerator->addCode(new IRReplace(it.first, newTemp));
        irGenerator->addCode(new IRPhi(newTemp, it.second));

        if (ctx->docLVal) {
            if (ctx->lValDoc.find(it.first) != ctx->lValDoc.end()) {
                ctx->lValDoc[it.first].push_back(newTemp);
            }
            else {
                ctx->lValDoc[it.first] = std::vector<IROperand *>(1, newTemp);
            }
        }
    }
}

void SemanticAnalysis::enterSubStmtReturn(SysYParser::SubStmtReturnContext * ctx)
{
}

void SemanticAnalysis::exitSubStmtReturn(SysYParser::SubStmtReturnContext * ctx)
{
    if (ctx->exp() && ctx->exp()->isArray) {
        throw std::runtime_error("[ERROR] > never return an array.\n");
    }
    if (curSymbolTable->getSymbolTableType() == TableType::FUNC) {
        if ((!ctx->exp() && curSymbolTable->getReturnType() != MetaDataType::VOID) || ctx->exp()->metaDataType != curSymbolTable->getReturnType()) {
            throw std::runtime_error("[ERROR] > SubStmtReturn return type mismatch.  " + ctx->getText());
        }
    }
    else {
        ctx->hasReturn = true;
        if (ctx->exp()){
            ctx->returnType = ctx->exp()->metaDataType;
        }
        else {
            ctx->returnType = MetaDataType::VOID;
        }
    }

    IRCode *code = nullptr;
    if(ctx->exp()){
        switch(ctx->returnType){
            case MetaDataType::INT:
                code = new IRReturnI(ctx->exp()->operand, new IRSymbolFunction(irGenerator->currentIRFunc->getFuncSymbolTable()));
                break;
            case MetaDataType::FLOAT:
                code = new IRReturnF(ctx->exp()->operand, new IRSymbolFunction(irGenerator->currentIRFunc->getFuncSymbolTable()));
                break;
            default:
                break;
        }
    } else {
        code = new IRReturnV(new IRSymbolFunction(irGenerator->currentIRFunc->getFuncSymbolTable()));
    }
    irGenerator->addCode(code);

    if(!ctx->codes.empty())
        irGenerator->addCodes(ctx->codes);
}

void SemanticAnalysis::enterExp(SysYParser::ExpContext *ctx) {
    ctx->isArray = false;
    ctx->shape = {};
    ctx->metaDataType = MetaDataType::VOID;
    ctx->addExp()->indexOperand = ctx->indexOperand;
}

void SemanticAnalysis::exitExp(SysYParser::ExpContext *ctx) {
    ctx->isArray = ctx->addExp()->isArray;
    ctx->shape = ctx->addExp()->shape;
    ctx->metaDataType = ctx->addExp()->metaDataType;
    ctx->operand = ctx->addExp()->operand;
}

// Cond
void SemanticAnalysis::enterCond(SysYParser::CondContext * ctx)
{

}

void SemanticAnalysis::exitCond(SysYParser::CondContext * ctx)
{
    if(ctx->lOrExp()->metaDataType != MetaDataType::INT) {
        throw std::runtime_error("[ERROR] > condition must be bool");
    }
    IRCode* code = new IRBeqz(ctx->lOrExp()->operand,  ctx->falseLabel);
    irGenerator->addCode(code);
}

void SemanticAnalysis::enterLVal(SysYParser::LValContext * ctx)
{
    ctx->isArray = false;
    ctx->shape = {};
    ctx->symbolType = SymbolType::PARAM;
    ctx->lValMetaDataType = MetaDataType::VOID;
    ctx->indexOperand = nullptr;
}

void SemanticAnalysis::exitLVal(SysYParser::LValContext * ctx)
{
    // TODO: calculate inside first, then use index to calculate mem position
    if (!ctx->exp().empty()) {
        if (ctx->exp(0)->metaDataType != MetaDataType::INT) {
            throw std::runtime_error("[ERROR] > array index must be int.\n");
        }
    }
    AbstractSymbol *searchLVal = curSymbolTable->lookUpAbstractSymbolGlobal(ctx->Ident()->getText());
    if (!searchLVal){
        throw std::runtime_error("[ERROR] > var symbol used before defined. " + ctx->Ident()->getText() + " "  + std::to_string(static_cast<int>(curSymbolTable->getSymbolTableType())));
    }
    if (searchLVal->getIsArray() && !ctx->exp().empty()) {
        ctx->isArray = true;
        ctx->shape = std::vector<size_t>(searchLVal->getShape().begin() + ctx->exp().size(), searchLVal->getShape().end());
    }
    else if (searchLVal->getIsArray()) {
        throw std::runtime_error("[ERROR] > cannot directly use array as lVal");
    }
    else {
        ctx->isArray = false;
    }
    ctx->symbolType = searchLVal->getSymbolType();
    ctx->lValMetaDataType = searchLVal->getMetaDataType();

    // search lVal IRSymbolVariable
    IRSymbolVariable* symVar = nullptr;
    std::string varName = searchLVal->getSymbolName();
    symVar = irGenerator->currentIRFunc->getLocalVariable(block, varName);
    if(!symVar)
        symVar = irGenerator->currentIRFunc->getParamVariable(varName);
    if(!symVar)
        symVar = irGenerator->ir->getGlobalVariable(varName);
    ctx->identOperand = symVar;

    // assigned
    if(!ctx->exp().empty()){
        std::vector<size_t> shape = symVar->getArrayShape();
        int width = shape.back();
        IRTempVariable *mulTemp = irGenerator->addTempVariable(MetaDataType::INT);
        IRTempVariable *addTemp = irGenerator->addTempVariable(MetaDataType::INT);
        irGenerator->addCode(new IRAssignI(mulTemp, ctx->exp().back()->operand));
        mulTemp->setAssigned();
        irGenerator->addCode(new IRAssignI(addTemp, new IRValue(MetaDataType::INT, "0", {}, false)));
        addTemp->setAssigned();
        for (int i = ctx->exp().size() - 2; i >= 0; i--) {
            IRTempVariable *replaceTemp = irGenerator->addTempVariable(mulTemp);
            mulTemp->addHistorySymbol(replaceTemp);
            irGenerator->addCode(new IRReplace(replaceTemp, mulTemp));
            irGenerator->addCode(new IRMulI(replaceTemp, ctx->exp(i)->operand,
                                            new IRValue(MetaDataType::INT, std::to_string(width), {}, false)));
            IRTempVariable *replaceAddTemp = irGenerator->addTempVariable(addTemp);
            irGenerator->addCode(new IRReplace(replaceAddTemp, addTemp));
            irGenerator->addCode(new IRAddI(addTemp, mulTemp->getLatestVersionSymbol(), addTemp->getLatestVersionSymbol()));
            addTemp->addHistorySymbol(replaceAddTemp);
            width *= shape[i];
        }
        ctx->indexOperand = addTemp->getLatestVersionSymbol();
    }
}


void SemanticAnalysis::enterPrimaryExpNestExp(SysYParser::PrimaryExpNestExpContext * ctx)
{
    ctx->isArray = false;
    ctx->shape = {};
    ctx->metaDataType = MetaDataType::VOID;
    ctx->exp()->indexOperand = ctx->indexOperand;
}

void SemanticAnalysis::exitPrimaryExpNestExp(SysYParser::PrimaryExpNestExpContext * ctx)
{
    ctx->isArray = ctx->exp()->isArray;
    ctx->shape = ctx->exp()->shape;
    ctx->metaDataType = ctx->exp()->metaDataType;
    ctx->operand = ctx->exp()->operand;
}

void SemanticAnalysis::enterPrimaryExplVal(SysYParser::PrimaryExplValContext * ctx)
{
    ctx->isArray = false;
    ctx->shape = {};
    ctx->metaDataType = MetaDataType::VOID;
}

void SemanticAnalysis::exitPrimaryExplVal(SysYParser::PrimaryExplValContext * ctx)
{
    ctx->isArray = ctx->lVal()->isArray;
    ctx->shape = ctx->lVal()->shape;
    ctx->metaDataType = ctx->lVal()->lValMetaDataType;

    if (ctx->lVal()->isArray && ctx->indexOperand) {
        IRTempVariable* tmp = irGenerator->addTempVariable(ctx->metaDataType);
        IRCode* fetchCode = nullptr;
        switch (ctx->lVal()->lValMetaDataType) {
            case MetaDataType::INT:
                fetchCode = new IRFetchArrayElemI(tmp, ctx->lVal()->identOperand, ctx->indexOperand);
                break;
            case MetaDataType::FLOAT:
                fetchCode = new IRFetchArrayElemF(tmp, ctx->lVal()->identOperand, ctx->indexOperand);
                break;
        }
        irGenerator->addCode(fetchCode);
        ctx->operand = tmp;
    } else { // normal symbolVar
        ctx->operand = ctx->lVal()->identOperand->getLatestVersionSymbol();
    }
}

void SemanticAnalysis::enterPrimaryExpNumber(SysYParser::PrimaryExpNumberContext * ctx)
{
    ctx->isArray = false;
    ctx->shape = {};
    ctx->metaDataType = MetaDataType::VOID;
}

void SemanticAnalysis::exitPrimaryExpNumber(SysYParser::PrimaryExpNumberContext * ctx)
{
    ctx->isArray = false;
    ctx->metaDataType = ctx->number()->metaDataType;
    if (ctx->metaDataType == MetaDataType::FLOAT) {
        ctx->operand = irGenerator->addImmValue(ctx->metaDataType, ctx->getText());
    }
    else {
        if (ctx->metaDataType == MetaDataType::INT) {
            ctx->operand = new IRValue(ctx->metaDataType, ctx->getText(), {}, false);
        }
        else {
            ctx->operand = irGenerator->addImmValue(ctx->metaDataType, ctx->getText());
        }
    }
}


// Unary
void SemanticAnalysis::enterUnaryExpPrimaryExp(SysYParser::UnaryExpPrimaryExpContext * ctx)
{
    ctx->isArray = false;
    ctx->shape = {};
    ctx->metaDataType = MetaDataType::VOID;
}

void SemanticAnalysis::exitUnaryExpPrimaryExp(SysYParser::UnaryExpPrimaryExpContext * ctx)
{
    ctx->isArray = ctx->primaryExp()->isArray;
    ctx->shape = ctx->primaryExp()->shape;
    ctx->metaDataType = ctx->primaryExp()->metaDataType;
    ctx->operand = ctx->primaryExp()->operand;
}

void SemanticAnalysis::enterUnaryExpFunc(SysYParser::UnaryExpFuncContext * ctx)
{
    ctx->isArray = false;
    ctx->shape = {};
    ctx->metaDataType = MetaDataType::VOID;
}

void SemanticAnalysis::exitUnaryExpFunc(SysYParser::UnaryExpFuncContext * ctx)
{
    SymbolTable *funcSymbolTable = curSymbolTable->lookUpFuncSymbolTable(ctx->Ident()->getText());
    if (!funcSymbolTable) {
        throw std::runtime_error("[ERROR] > function called before definined. " + ctx->Ident()->getText());
    }
    if (ctx->funcRParams()) {
        if (ctx->funcRParams()->isArrayList.size() != funcSymbolTable->getParamNum()) {
            throw std::runtime_error("[ERROR] > in function calling, parameter number not match. " + std::to_string(ctx->funcRParams()->isArrayList.size()) + " " + std::to_string(funcSymbolTable->getParamNum()));
        }
        for (int i = 0; i < ctx->funcRParams()->isArrayList.size(); ++i) {
            if (!funcSymbolTable->compareParamSymbolDataType(i, ctx->funcRParams()->metaDataTypeList[i], ctx->funcRParams()->isArrayList[i], ctx->funcRParams()->shapeList[i])) {
                throw std::runtime_error("[ERROR] > calling function parameter type error.\n");
            }
        }
    }
    else {
        if (funcSymbolTable->getParamNum()) {
            throw std::runtime_error("[ERROR] > in function calling, parameter number not match. ");
        }
    }
    ctx->isArray = false;
    ctx->metaDataType = funcSymbolTable->getReturnType();

    IRSymbolFunction *func = irGenerator->getSymbolFunction(funcSymbolTable->getFuncName());
    IRSymbolFunction *selfFunc = irGenerator->ir->getSymbolFunction(irGenerator->currentIRFunc->getFunctionName());
    IRCode *code = new IRCall(func, selfFunc);
    irGenerator->addCode(code);

    if(funcSymbolTable->getReturnType() != MetaDataType::VOID){
        IRTempVariable *newResult = irGenerator->addTempVariable(funcSymbolTable->getReturnType());
        switch (funcSymbolTable->getReturnType())
        {
            case MetaDataType::INT:
                code = new IRGetReturnI(newResult);
                irGenerator->addCode(code);
                break;
            case MetaDataType::FLOAT:
                code = new IRGetReturnF(newResult);
                irGenerator->addCode(code);
                break;
            default:
                break;
        }
        ctx->operand = newResult;
    }
}

void SemanticAnalysis::enterUnaryExpNestUnaryExp(SysYParser::UnaryExpNestUnaryExpContext * ctx)
{
    ctx->isArray = false;
    ctx->shape = {};
    ctx->metaDataType = MetaDataType::VOID;
    ctx->unaryExp()->indexOperand = ctx->indexOperand;
}

void SemanticAnalysis::exitUnaryExpNestUnaryExp(SysYParser::UnaryExpNestUnaryExpContext * ctx)
{
    ctx->isArray = ctx->unaryExp()->isArray;
    ctx->metaDataType = ctx->unaryExp()->metaDataType;
    ctx->shape = ctx->unaryExp()->shape;
    if (ctx->unaryOp()->getText() == "!") {
        if (ctx->isArray) {
            throw std::runtime_error("[ERROR] > use logic operator on non-boolean expression.\n");
        }
    }
    else {
        if (ctx->metaDataType == MetaDataType::INT) {
            throw std::runtime_error("[ERROR] > use non-logic operator on boolean expression.\n");
        }
    }


    IRTempVariable* result = irGenerator->addTempVariable(ctx->metaDataType);
    IRCode* code = nullptr;
    if(ctx->unaryOp()->getText() == "-"){
        switch (ctx->unaryExp()->operand->getMetaDataType()) {
            case MetaDataType::INT:
                code = new IRNegI(result, ctx->unaryExp()->operand);
                break;
            case MetaDataType::FLOAT:
                code = new IRNegF(result, ctx->unaryExp()->operand);
                break;
        }
    }
    else if(ctx->unaryOp()->getText() == "!"){
        code = new IRNot(result, ctx->unaryExp()->operand);
    }
    irGenerator->addCode(code);
    ctx->operand = result;
}

void SemanticAnalysis::enterUnaryOp(SysYParser::UnaryOpContext * ctx)
{
}

void SemanticAnalysis::exitUnaryOp(SysYParser::UnaryOpContext * ctx)
{
}

// funcRParams
void SemanticAnalysis::enterFuncRParams(SysYParser::FuncRParamsContext * ctx)
{
    ctx->isArrayList.clear();
    ctx->shapeList.clear();
    ctx->metaDataTypeList.clear();
}

void SemanticAnalysis::exitFuncRParams(SysYParser::FuncRParamsContext * ctx)
{
    for (auto & it : ctx->exp()) {
        ctx->isArrayList.emplace_back(it->isArray);
        ctx->shapeList.emplace_back(it->shape);
        ctx->metaDataTypeList.emplace_back(it->metaDataType);
        switch (it->metaDataType)
        {
            case MetaDataType::INT:
                irGenerator->addCode(new IRAddParamI(it->operand));
                break;
            case MetaDataType::FLOAT:
                irGenerator->addCode(new IRAddParamF(it->operand));
                break;
            default:
                throw std::runtime_error("[ERROR] > data type fault.\n");
                break;
        }
    }
}

// MulExp
void SemanticAnalysis::enterMulExpMulExp(SysYParser::MulExpMulExpContext * ctx)
{
    ctx->isArray = false;
    ctx->shape = {};
    ctx->metaDataType = MetaDataType::VOID;
    ctx->mulExp()->indexOperand = ctx->indexOperand;
    ctx->unaryExp()->indexOperand = ctx->indexOperand;
}

void SemanticAnalysis::exitMulExpMulExp(SysYParser::MulExpMulExpContext * ctx)
{
    ctx->isArray = ctx->mulExp()->isArray;
    ctx->metaDataType = ctx->mulExp()->metaDataType;
    ctx->shape = ctx->mulExp()->shape;
    if (ctx->metaDataType != ctx->unaryExp()->metaDataType) {
        throw std::runtime_error("[ERROR] > mul: type mismatch in calculation. " + std::to_string(static_cast<int>(ctx->metaDataType)) + std::to_string(static_cast<int>(ctx->unaryExp()->metaDataType)));
    }
    if (ctx->isArray) {
        if (!ctx->unaryExp()->isArray) {
            throw std::runtime_error("[ERROR] > mul: array:non-array calculation.\n");
        }
        if (ctx->shape != ctx->mulExp()->shape) {
            throw std::runtime_error("[ERROR] > array size mismatch in calculation.\n");
        }
    }
    else {
        if (ctx->unaryExp()->isArray) {
            throw std::runtime_error("[ERROR] > mul: non-array:array calculation.\n");
        }
    }

//    TODO: "divisor equals zero"
    if(ctx->mulOp()->getText() == "%"){
        if(ctx->metaDataType != MetaDataType::INT)
            throw std::runtime_error("[ERROR] > mod: operands not INT.\n");
        if(!ctx->unaryExp()->isArray){
            if(ctx->unaryExp()->operand->getValue() == "0")
                throw std::runtime_error("[ERROR] > divisor is zero.\n");
        } else {
            for(auto &val : ctx->unaryExp()->operand->getValues()){
                if(val == "0")
                    throw std::runtime_error("[ERROR] > divisor is zero.\n");
            }
        }
    } else if (ctx->mulOp()->getText() == "/") {
        if(!ctx->unaryExp()->isArray){
            if(ctx->unaryExp()->operand->getValue() == "0")
                throw std::runtime_error("[ERROR] > divisor is zero.\n");
        } else {
            for(auto &val : ctx->unaryExp()->operand->getValues()){
                if(val == "0")
                    throw std::runtime_error("[ERROR] > divisor is zero.\n");
            }
        }
    }

    IRTempVariable* result = irGenerator->addTempVariable(ctx->metaDataType);
    IRCode* code = nullptr;
    if (ctx->mulOp()->getText() == "*"){
        switch (ctx->mulExp()->operand->getMetaDataType()) {
            case MetaDataType::INT:
                code = new IRMulI(result, ctx->mulExp()->operand, ctx->unaryExp()->operand);
                break;
            case MetaDataType::FLOAT:
                code = new IRMulF(result, ctx->mulExp()->operand, ctx->unaryExp()->operand);
                break;
        }
    }
    else if (ctx->mulOp()->getText() == "/"){
        switch (ctx->mulExp()->operand->getMetaDataType()) {
            case MetaDataType::INT:
                code = new IRDivI(result, ctx->mulExp()->operand, ctx->unaryExp()->operand);
                break;
            case MetaDataType::FLOAT:
                code = new IRDivF(result, ctx->mulExp()->operand, ctx->unaryExp()->operand);
                break;
        }
    }
    else if (ctx->mulOp()->getText() == "%"){
        code = new IRMod(result, ctx->mulExp()->operand, ctx->unaryExp()->operand, irGenerator->ir->getSymbolFunction(curSymbolTable->getFuncName()));
    }
    else
        throw std::runtime_error("[ERROR] > mulop illegal.\n");
    irGenerator->addCode(code);
    ctx->operand = result;
}

void SemanticAnalysis::enterMulExpUnaryExp(SysYParser::MulExpUnaryExpContext * ctx)
{
    ctx->isArray = false;
    ctx->shape = {};
    ctx->metaDataType = MetaDataType::VOID;
}

void SemanticAnalysis::exitMulExpUnaryExp(SysYParser::MulExpUnaryExpContext * ctx)
{
    ctx->isArray = ctx->unaryExp()->isArray;
    ctx->metaDataType = ctx->unaryExp()->metaDataType;
    ctx->shape = ctx->unaryExp()->shape;
    ctx->operand = ctx->unaryExp()->operand;
}

void SemanticAnalysis::enterMulOp(SysYParser::MulOpContext * ctx)
{
}

void SemanticAnalysis::exitMulOp(SysYParser::MulOpContext * ctx)
{
}

// AddExp
void SemanticAnalysis::enterAddExpAddExp(SysYParser::AddExpAddExpContext * ctx)
{
    ctx->isArray = false;
    ctx->shape = {};
    ctx->metaDataType = MetaDataType::VOID;
    ctx->addExp()->indexOperand = ctx->indexOperand;
    ctx->mulExp()->indexOperand = ctx->indexOperand;
}

void SemanticAnalysis::exitAddExpAddExp(SysYParser::AddExpAddExpContext * ctx)
{
    ctx->isArray = ctx->addExp()->isArray;
    ctx->metaDataType = ctx->addExp()->metaDataType;
    ctx->shape = ctx->addExp()->shape;
    if (ctx->metaDataType != ctx->mulExp()->metaDataType) {
        throw std::runtime_error("[ERROR] > add: type mismatch in calculation. " + std::to_string(static_cast<int>(ctx->metaDataType)) + std::to_string(static_cast<int>(ctx->mulExp()->metaDataType)));
    }
    if (ctx->isArray) {
        if (!ctx->mulExp()->isArray) {
            throw std::runtime_error("[ERROR] > add: array:non-array calculation.\n");
        }
        if (ctx->shape != ctx->mulExp()->shape) {
            throw std::runtime_error("[ERROR] > array size mismatch in calculation.\n");
        }
    }
    else {
        if (ctx->mulExp()->isArray) {
            throw std::runtime_error("[ERROR] > add: non-array:array calculation. " + curSymbolTable->getFuncName() + " " + ctx->mulExp()->getText());
        }
    }

    IRTempVariable* result = irGenerator->addTempVariable(ctx->metaDataType);
    IRCode* code = nullptr;

    if (ctx->addOp()->getText() == "+"){
        switch (ctx->addExp()->metaDataType) {
            case MetaDataType::INT:
                code = new IRAddI(result, ctx->addExp()->operand, ctx->mulExp()->operand);
                break;
            case MetaDataType::FLOAT:
                code = new IRAddF(result, ctx->addExp()->operand, ctx->mulExp()->operand);
                break;
        }
    }
    else if (ctx->addOp()->getText() == "-"){
        switch (ctx->addExp()->metaDataType) {
            case MetaDataType::INT:
                code = new IRSubI(result, ctx->addExp()->operand, ctx->mulExp()->operand);
                break;
            case MetaDataType::FLOAT:
                code = new IRSubF(result, ctx->addExp()->operand, ctx->mulExp()->operand);
                break;
        }
    }
    else
        throw std::runtime_error("[ERROR] > addop illegal.\n");

    irGenerator->addCode(code);
    ctx->operand = result;
}

void SemanticAnalysis::enterAddExpMulExp(SysYParser::AddExpMulExpContext * ctx)
{
    ctx->isArray = false;
    ctx->shape = {};
    ctx->metaDataType = MetaDataType::VOID;
    ctx->mulExp()->indexOperand = ctx->indexOperand;
}

void SemanticAnalysis::enterAddOp(SysYParser::AddOpContext *ctx) {}
void SemanticAnalysis::exitAddOp(SysYParser::AddOpContext *ctx) {}

void SemanticAnalysis::exitAddExpMulExp(SysYParser::AddExpMulExpContext * ctx)
{
    ctx->isArray = ctx->mulExp()->isArray;
    ctx->metaDataType = ctx->mulExp()->metaDataType;
    ctx->shape = ctx->mulExp()->shape;
    ctx->operand = ctx->mulExp()->operand;
}

// RelExp
void SemanticAnalysis::enterRelExpRelExp(SysYParser::RelExpRelExpContext * ctx)
{
    ctx->metaDataType = MetaDataType::VOID;
}

void SemanticAnalysis::exitRelExpRelExp(SysYParser::RelExpRelExpContext * ctx)
{
    if (ctx->addExp()->isArray) {
        throw std::runtime_error("[ERROR] > rel: array cannot be operands of logic operators.\n");
    }
    ctx->metaDataType = ctx->relExp()->metaDataType;
    if (ctx->metaDataType != ctx->addExp()->metaDataType) {
        throw std::runtime_error("[ERROR] > rel: relation calculation with different types.\n");
    }
    ctx->metaDataType = MetaDataType::INT;

    IRTempVariable* result = irGenerator->addTempVariable(ctx->metaDataType);
    IRCode* code = nullptr;
    if (ctx->relOp()->getText() == "<"){
        switch (ctx->addExp()->metaDataType) {
            case MetaDataType::INT:
                code = new IRSltI(result, ctx->relExp()->operand, ctx->addExp()->operand);
                break;
            case MetaDataType::FLOAT:
                code = new IRSltF(result, ctx->relExp()->operand, ctx->addExp()->operand);
                break;
        }
    }
    else if (ctx->relOp()->getText() == ">"){
        switch (ctx->addExp()->metaDataType) {
            case MetaDataType::INT:
                code = new IRSgtI(result, ctx->relExp()->operand, ctx->addExp()->operand);
                break;
            case MetaDataType::FLOAT:
                code = new IRSgtF(result, ctx->relExp()->operand, ctx->addExp()->operand);
                break;
        }
    }
    else if (ctx->relOp()->getText() == "<="){
        switch (ctx->addExp()->metaDataType) {
            case MetaDataType::INT:
                code = new IRSleqI(result, ctx->relExp()->operand, ctx->addExp()->operand);
                break;
            case MetaDataType::FLOAT:
                code = new IRSleqF(result, ctx->relExp()->operand, ctx->addExp()->operand);
                break;
        }
    }
    else if (ctx->relOp()->getText() == ">="){
        switch (ctx->addExp()->metaDataType) {
            case MetaDataType::INT:
                code = new IRSgeqI(result, ctx->relExp()->operand, ctx->addExp()->operand);
                break;
            case MetaDataType::FLOAT:
                code = new IRSgeqF(result, ctx->relExp()->operand, ctx->addExp()->operand);
                break;
        }
    }
    else
        throw std::runtime_error("[ERROR] > addop illegal.\n");
    irGenerator->addCode(code);
    ctx->operand = result;
}

void SemanticAnalysis::enterRelExpAddExp(SysYParser::RelExpAddExpContext * ctx)
{
    ctx->metaDataType = MetaDataType::VOID;
}

void SemanticAnalysis::exitRelExpAddExp(SysYParser::RelExpAddExpContext * ctx)
{
    if (ctx->addExp()->isArray) {
        throw std::runtime_error("[ERROR] > rel add: array cannot be operands of logic operators. " + curSymbolTable->getFuncName());
    }
    ctx->metaDataType = ctx->addExp()->metaDataType;
    ctx->operand = ctx->addExp()->operand;
}

void SemanticAnalysis::enterRelOp(SysYParser::RelOpContext *ctx) {}
void SemanticAnalysis::exitRelOp(SysYParser::RelOpContext *ctx) {}

//EqExp
void SemanticAnalysis::enterEqExpRelExp(SysYParser::EqExpRelExpContext * ctx)
{
    ctx->metaDataType = MetaDataType::VOID;

}
void SemanticAnalysis::exitEqExpRelExp(SysYParser::EqExpRelExpContext * ctx)
{
    ctx->metaDataType = ctx->relExp()->metaDataType;
    ctx->operand = ctx->relExp()->operand;
}

void SemanticAnalysis::enterEqExpEqExp(SysYParser::EqExpEqExpContext * ctx)
{
    ctx->metaDataType = MetaDataType::VOID;
}

void SemanticAnalysis::exitEqExpEqExp(SysYParser::EqExpEqExpContext * ctx)
{
    if (ctx->eqExp()->metaDataType != ctx->relExp()->metaDataType) {
        throw std::runtime_error("[ERROR] > eq operator with different data type.\n");
    }
    ctx->metaDataType = MetaDataType::INT;

    IRTempVariable* result = irGenerator->addTempVariable(ctx->metaDataType);
    IRCode* code = nullptr;
    if(ctx->eqOp()->getText() == "=="){
        switch (ctx->eqExp()->metaDataType) {
            case MetaDataType::INT:
                code = new IRSeqI(result, ctx->eqExp()->operand, ctx->relExp()->operand);
                break;
            case MetaDataType::FLOAT:
                code = new IRSeqF(result, ctx->eqExp()->operand, ctx->relExp()->operand);
                break;
        }
    } else if(ctx->eqOp()->getText() == "!=") {
        switch (ctx->eqExp()->metaDataType) {
            case MetaDataType::INT:
                code = new IRSneI(result, ctx->eqExp()->operand, ctx->relExp()->operand);
                break;
            case MetaDataType::FLOAT:
                code = new IRSneF(result, ctx->eqExp()->operand, ctx->relExp()->operand);
                break;
        }
    }
    irGenerator->addCode(code);
    ctx->operand = result;
}

void SemanticAnalysis::enterEqOp(SysYParser::EqOpContext *ctx) {}
void SemanticAnalysis::exitEqOp(SysYParser::EqOpContext *ctx) {}

//LAndExp
void SemanticAnalysis::enterLAndExpLAndExp(SysYParser::LAndExpLAndExpContext * ctx)
{
    ctx->metaDataType = MetaDataType::VOID;
}

void SemanticAnalysis::exitLAndExpLAndExp(SysYParser::LAndExpLAndExpContext * ctx)
{
    ctx->metaDataType = ctx->lAndExp()->metaDataType;
    if (ctx->metaDataType != MetaDataType::INT || ctx->eqExp()->metaDataType != MetaDataType::INT) {
        throw std::runtime_error("[ERROR] > logic calculation with non-boolean operands.\n");
    }
    IRTempVariable* result = irGenerator->addTempVariable(ctx->metaDataType);
    auto code = new IRAnd(result, ctx->lAndExp()->operand, ctx->eqExp()->operand);
    irGenerator->addCode(code);
    ctx->operand = result;
}

void SemanticAnalysis::enterLAndExpEqExp(SysYParser::LAndExpEqExpContext * ctx)
{
    ctx->metaDataType = MetaDataType::VOID;
}

void SemanticAnalysis::exitLAndExpEqExp(SysYParser::LAndExpEqExpContext * ctx)
{
    ctx->metaDataType = ctx->eqExp()->metaDataType;
    ctx->operand = ctx->eqExp()->operand;
}

//LOrExp
void SemanticAnalysis::enterLOrExpLAndExp(SysYParser::LOrExpLAndExpContext * ctx)
{
    ctx->metaDataType = MetaDataType::VOID;
}

void SemanticAnalysis::exitLOrExpLAndExp(SysYParser::LOrExpLAndExpContext * ctx)
{
    ctx->metaDataType = ctx->lAndExp()->metaDataType;

    ctx->operand = ctx->lAndExp()->operand;
}
void SemanticAnalysis::enterLOrExpLOrExp(SysYParser::LOrExpLOrExpContext * ctx)
{
    ctx->metaDataType = MetaDataType::VOID;
}

void SemanticAnalysis::exitLOrExpLOrExp(SysYParser::LOrExpLOrExpContext * ctx)
{
    ctx->metaDataType = ctx->lAndExp()->metaDataType;
    if (ctx->metaDataType != MetaDataType::INT || ctx->lAndExp()->metaDataType != MetaDataType::INT) {
        throw std::runtime_error("[ERROR] > logic calculation with non-boolean operands.\n");
    }

    IRTempVariable* result = irGenerator->addTempVariable(ctx->metaDataType);

    IROr *code = new IROr(result, ctx->lOrExp()->operand, ctx->lAndExp()->operand);
    irGenerator->addCode(code);
    ctx->operand = result;
}


// ConstExp
void SemanticAnalysis::enterConstExpNumber(SysYParser::ConstExpNumberContext * ctx)
{
    ctx->metaDataType = MetaDataType::VOID;

}
void SemanticAnalysis::exitConstExpNumber(SysYParser::ConstExpNumberContext * ctx)
{
    ctx->metaDataType = ctx->number()->metaDataType;
    ctx->val = ctx->getText();
}

// Number
void SemanticAnalysis::enterNumberIntConst(SysYParser::NumberIntConstContext * ctx)
{

}
void SemanticAnalysis::exitNumberIntConst(SysYParser::NumberIntConstContext * ctx)
{
    ctx->metaDataType = MetaDataType::INT;
}

void SemanticAnalysis::enterNumberFloatConst(SysYParser::NumberFloatConstContext * ctx)
{

}
void SemanticAnalysis::exitNumberFloatConst(SysYParser::NumberFloatConstContext * ctx)
{
    ctx->metaDataType = MetaDataType::FLOAT;
}

void SemanticAnalysis::enterEveryRule(antlr4::ParserRuleContext * ctx) {}
void SemanticAnalysis::exitEveryRule(antlr4::ParserRuleContext * ctx) {}
void SemanticAnalysis::visitTerminal(antlr4::tree::TerminalNode * node) {}
void SemanticAnalysis::visitErrorNode(antlr4::tree::ErrorNode * node) {}