#include "semanticAnalysis.h"
#include <stdio.h>

void SemanticAnalysis::enterCompUnit(CACTParser::CompUnitContext * ctx)
{
    block = 0;
    curSymbolTable = SymbolTable::getGlobalSymbolTable();
    irGenerator = IRGenerator::getIRGenerator(IRProgram::getIRProgram(programName, curSymbolTable));
    irGenerator->targetCodes->addCodeLabel("iobuff");
    irGenerator->targetCodes->addCodeDirectives("\t.zero 80");
    SymbolTable *funcSymbolTable = curSymbolTable->insertFuncSymbolTableSafely("print_int", MetaDataType::VOID, curSymbolTable);
    funcSymbolTable->insertParamSymbolSafely("", MetaDataType::INT, false, 0);
    funcSymbolTable->setParamDataTypeList();
    funcSymbolTable->setParamNum();
    irGenerator->enterFunction(funcSymbolTable);
    irGenerator->exitFunction();
    irGenerator->currentIRFunc->calFrameSize();
    
    funcSymbolTable = curSymbolTable->insertFuncSymbolTableSafely("print_float", MetaDataType::VOID, curSymbolTable);
    funcSymbolTable->insertParamSymbolSafely("", MetaDataType::FLOAT, false, 0);
    funcSymbolTable->setParamDataTypeList();
    funcSymbolTable->setParamNum();
    irGenerator->enterFunction(funcSymbolTable);
    irGenerator->exitFunction();
    irGenerator->currentIRFunc->calFrameSize();

    funcSymbolTable = curSymbolTable->insertFuncSymbolTableSafely("print_double", MetaDataType::VOID, curSymbolTable);
    funcSymbolTable->insertParamSymbolSafely("", MetaDataType::DOUBLE, false, 0);
    funcSymbolTable->setParamDataTypeList();
    funcSymbolTable->setParamNum();
    irGenerator->enterFunction(funcSymbolTable);
    irGenerator->exitFunction();
    irGenerator->currentIRFunc->calFrameSize();

    funcSymbolTable = curSymbolTable->insertFuncSymbolTableSafely("print_bool", MetaDataType::VOID, curSymbolTable);
    funcSymbolTable->insertParamSymbolSafely("", MetaDataType::BOOL, false, 0);
    funcSymbolTable->setParamDataTypeList();
    funcSymbolTable->setParamNum();
    irGenerator->enterFunction(funcSymbolTable);
    irGenerator->exitFunction();
    irGenerator->currentIRFunc->calFrameSize();

    funcSymbolTable = curSymbolTable->insertFuncSymbolTableSafely("get_int", MetaDataType::INT, curSymbolTable);
    irGenerator->enterFunction(funcSymbolTable);
    irGenerator->exitFunction();
    irGenerator->currentIRFunc->calFrameSize();

    funcSymbolTable = curSymbolTable->insertFuncSymbolTableSafely("get_float", MetaDataType::FLOAT, curSymbolTable);
    funcSymbolTable->insertParamSymbolSafely("", MetaDataType::VOID, false, 0);
    irGenerator->enterFunction(funcSymbolTable);
    irGenerator->exitFunction();
    irGenerator->currentIRFunc->calFrameSize();

    funcSymbolTable = curSymbolTable->insertFuncSymbolTableSafely("get_double", MetaDataType::DOUBLE, curSymbolTable);
    funcSymbolTable->setParamDataTypeList();
    funcSymbolTable->setParamNum();
    irGenerator->enterFunction(funcSymbolTable);
    irGenerator->exitFunction();
    irGenerator->currentIRFunc->calFrameSize();
}

void SemanticAnalysis::exitCompUnit(CACTParser::CompUnitContext * ctx)
{
    if(curSymbolTable->getSymbolTableType() != TableType::GLOBAL || !curSymbolTable->lookUpFuncSymbolTable("main")) {
        throw std::runtime_error("[ERROR] > There is no main function.\n");
    }
    irGenerator->ir->print();
    irGenerator->ir->write(programName + ".ir");
    irGenerator->ir->targetGen(irGenerator->targetCodes);
    irGenerator->ir->targetCodePrint(irGenerator->targetCodes);
    irGenerator->ir->targetCodeWrite(irGenerator->targetCodes, programName + ".S");
}

void SemanticAnalysis::enterDecl(CACTParser::DeclContext * ctx)
{
}

void SemanticAnalysis::exitDecl(CACTParser::DeclContext * ctx)
{
}

void SemanticAnalysis::enterConstDecl(CACTParser::ConstDeclContext * ctx)
{   
}

void SemanticAnalysis::exitConstDecl(CACTParser::ConstDeclContext * ctx)
{
    MetaDataType type = ctx->bType()->bMetaDataType;
    SymbolFactory symbolFactory;

    for(const auto & const_def : ctx->constDef())
    {
        if (const_def->withType && const_def->type != type && const_def->type != MetaDataType::VOID) {
            if (const_def->withType && const_def->type == MetaDataType::DOUBLE && type == MetaDataType::FLOAT) {
                const_def->type = MetaDataType::FLOAT;
                const_def->value->setMetaDataType(MetaDataType::FLOAT);
            }
            else {
                throw std::runtime_error("[ERROR] > error in var initialization: type mismatch.\n");
            }
        }
        AbstractSymbol *symbol = SymbolFactory::createSymbol(const_def->symbolName, SymbolType::CONST, type, const_def->isArray, const_def->size);
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
                    case MetaDataType::BOOL:
                        code = new IRAssignB(newConst, const_def->value);
                        break;
                    case MetaDataType::INT:
                        code = new IRAssignI(newConst, const_def->value);
                        break;
                    case MetaDataType::FLOAT:
                        code = new IRAssignF(newConst, const_def->value);
                        break;
                    case MetaDataType::DOUBLE:
                        code = new IRAssignD(newConst, const_def->value);
                        break;
                }
                irGenerator->addCode(code);
            }
        }
    }
}

void SemanticAnalysis::enterBType(CACTParser::BTypeContext * ctx)
{
    ctx->bMetaDataType = MetaDataType::VOID;
}

void SemanticAnalysis::exitBType(CACTParser::BTypeContext * ctx)
{
    std::string dataTypeText = ctx->getText();
    if (dataTypeText == "bool") {
        ctx->bMetaDataType = MetaDataType::BOOL;
    }
    else if (dataTypeText == "int") {
        ctx->bMetaDataType = MetaDataType::INT;
    }
    else if (dataTypeText == "float") {
        ctx->bMetaDataType = MetaDataType::FLOAT;
    }
    else if (dataTypeText == "double") {
        ctx->bMetaDataType = MetaDataType::DOUBLE;
    }
    else{
        throw std::runtime_error("[ERROR] > Data Type not supported.\n");
    }  
}

// ConstDef
void SemanticAnalysis::enterConstDef(CACTParser::ConstDefContext * ctx)
{
    ctx->symbolName = "";
    ctx->type = MetaDataType::VOID;
    ctx->withType = false;
    ctx->size = 0;
    ctx->isArray = false;
}

void SemanticAnalysis::exitConstDef(CACTParser::ConstDefContext * ctx)
{
    ctx->symbolName = ctx->Ident()->getText();
    if(!ctx->IntConst()){
        ctx->isArray = false;
    } else {
        ctx->isArray = true;
        ctx->size = stoi(ctx->IntConst()->getText());
    }
    if (ctx->constInitVal()) {
        if (ctx->constInitVal()->isArray != ctx->isArray || (ctx->isArray && ctx->constInitVal()->size > ctx->size)) {
            throw std::runtime_error("[ERROR] > Const var initialize failure: type not match. " + std::to_string(ctx->constInitVal()->isArray) + " " + std::to_string(ctx->isArray) + " " + std::to_string(ctx->constInitVal()->size) + " " + std::to_string(ctx->size));
        }
        ctx->withType = true;
        ctx->type = ctx->constInitVal()->type;
        if (ctx->isArray && ctx->size > ctx->constInitVal()->value->getArraySize()) {
            std::vector<std::string> valVec = ctx->constInitVal()->value->getValues();
            for (int i = ctx->constInitVal()->value->getArraySize(); i < ctx->size; i++) {
                valVec.push_back("0");
            }
            ctx->value = irGenerator->ir->addMulImmValue(ctx->type, valVec);
        }
        else {
            ctx->value = ctx->constInitVal()->value;
        }
    }
    else {
        if (ctx->isArray) {
            ctx->value = irGenerator->ir->addMulSameImmValue(MetaDataType::INT, "0", ctx->size);
        }
        else {
            ctx->value = new IRValue(MetaDataType::INT, "0", {}, false);
        }
    }
}

// ConstInitVal
void SemanticAnalysis::enterConstInitValOfVar(CACTParser::ConstInitValOfVarContext * ctx)
{
    ctx->type = MetaDataType::VOID;
    ctx->size = 0;
    ctx->isArray = false;
    ctx->value = nullptr;
}

void SemanticAnalysis::exitConstInitValOfVar(CACTParser::ConstInitValOfVarContext * ctx)
{
    ctx->type = ctx->constExp()->metaDataType;
    ctx->size = 1;
    ctx->isArray = false;
    if (ctx->constExp()->metaDataType == MetaDataType::FLOAT || ctx->constExp()->metaDataType == MetaDataType::DOUBLE) {
        ctx->value = irGenerator->addImmValue(ctx->constExp()->metaDataType, ctx->constExp()->val);
    }
    else {
        if (ctx->constExp()->metaDataType == MetaDataType::BOOL || ctx->constExp()->metaDataType == MetaDataType::INT) {
            ctx->value = new IRValue(ctx->constExp()->metaDataType, ctx->constExp()->val, {}, false);
        }
        else {
            ctx->value = irGenerator->addImmValue(ctx->constExp()->metaDataType, ctx->constExp()->val);
        }
    }
}

void SemanticAnalysis::enterConstInitValOfArray(CACTParser::ConstInitValOfArrayContext * ctx)
{
    ctx->type = MetaDataType::VOID;
    ctx->size = 0;
    ctx->isArray = false;
    ctx->value = nullptr;
}

void SemanticAnalysis::exitConstInitValOfArray(CACTParser::ConstInitValOfArrayContext * ctx)
{
    if(!ctx->constExp().empty()){
        ctx->type = ctx->constExp(0)->metaDataType;
        ctx->size = ctx->constExp().size();
    } else {
        ctx->type = MetaDataType::VOID;
        ctx->size = 0;
    }

    for(const auto & const_exp : ctx->constExp()){
        if(const_exp->metaDataType != ctx->type)
            throw std::runtime_error("[ERROR] > Array data type is not consistent.\n");
    }
    ctx->isArray = true;

    if(!ctx->constExp().empty()){
        std::vector<std::string> immVal;
        for(auto &const_exp : ctx->constExp()){
            immVal.push_back(const_exp->val);
        }
        ctx->value = irGenerator->ir->addMulImmValue(ctx->type, immVal);
    }
    else {
        ctx->value = new IRValue(MetaDataType::INT, "0", {}, false);
    }
}

// VarDecl
void SemanticAnalysis::enterVarDecl(CACTParser::VarDeclContext * ctx)
{
}
void SemanticAnalysis::exitVarDecl(CACTParser::VarDeclContext * ctx)
{
    MetaDataType type = ctx->bType()->bMetaDataType;
    SymbolFactory symbolFactory;

    for(const auto & var_def : ctx->varDef())
    {
        if (var_def->withType && var_def->type != type && var_def->type != MetaDataType::VOID) {
            if (var_def->withType && var_def->type == MetaDataType::DOUBLE && type == MetaDataType::FLOAT) {
                var_def->type = MetaDataType::FLOAT;
                var_def->value->setMetaDataType(MetaDataType::FLOAT);
            }
            else {
                throw std::runtime_error("[ERROR] > error in var initialization: type mismatch.\n");
            }
        }
        AbstractSymbol *symbol = SymbolFactory::createSymbol(var_def->symbolName, SymbolType::VAR, type, var_def->isArray, var_def->size);
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
                    case MetaDataType::BOOL:
                        code = new IRAssignB(newVar, var_def->value);
                        break;
                    case MetaDataType::INT:
                        code = new IRAssignI(newVar, var_def->value);
                        break;
                    case MetaDataType::FLOAT:
                        code = new IRAssignF(newVar, var_def->value);
                        break;
                    case MetaDataType::DOUBLE:
                        code = new IRAssignD(newVar, var_def->value);
                        break;
                }
            }
            irGenerator->addCode(code);
        }
    }
}

void SemanticAnalysis::enterVarDef(CACTParser::VarDefContext * ctx)
{
    ctx->symbolName = "";
    ctx->type = MetaDataType::VOID;
    ctx->withType = false;
    ctx->size = 0;
    ctx->isArray = false;
}

void SemanticAnalysis::exitVarDef(CACTParser::VarDefContext * ctx)
{
    ctx->symbolName = ctx->Ident()->getText();
    if(!ctx->IntConst()){
        ctx->isArray = false;
    } else {
        ctx->isArray = true;
        ctx->size = stoi(ctx->IntConst()->getText());
    }
    if (ctx->constInitVal()) {
        if (ctx->constInitVal()->isArray != ctx->isArray || (ctx->isArray && ctx->constInitVal()->size > ctx->size)) {
            throw std::runtime_error("[ERROR] > var initialize failure: type not match. " + std::to_string(ctx->constInitVal()->isArray) + " " + std::to_string(ctx->isArray) + " " + std::to_string(ctx->constInitVal()->size) + " " + std::to_string(ctx->size));
        }
        ctx->withType = true;
        ctx->type = ctx->constInitVal()->type;
        if (ctx->isArray && ctx->size > ctx->constInitVal()->value->getArraySize()) {
            std::vector<std::string> valVec = ctx->constInitVal()->value->getValues();
            for (int i = ctx->constInitVal()->value->getArraySize(); i < ctx->size; i++) {
                valVec.push_back("0");
            }
            ctx->value = irGenerator->ir->addMulImmValue(ctx->type, valVec);
        }
        else {
            ctx->value = ctx->constInitVal()->value;
        }
    }
    else {
        if (ctx->isArray) {
            ctx->value = irGenerator->ir->addMulSameImmValue(MetaDataType::INT, "0", ctx->size);
        }
        else {
            ctx->value = new IRValue(MetaDataType::INT, "0", {}, false);
        }
    }
}

void SemanticAnalysis::enterFuncDef(CACTParser::FuncDefContext * ctx)
{
    if (curSymbolTable->getSymbolTableType() != TableType::GLOBAL) {
        throw std::runtime_error("[ERROR] > cannot define function in non-global area.\n");
    }

    std::string datatype = ctx->funcType()->getText();
    MetaDataType returnType;
    if (datatype == "void") {
        returnType = MetaDataType::VOID;
    }
    else if (datatype == "bool") {
        returnType = MetaDataType::BOOL;
    }
    else if (datatype == "int") {
        returnType = MetaDataType::INT;
    }
    else if (datatype == "float") {
        returnType = MetaDataType::FLOAT;
    }
    else if (datatype == "double") {
        returnType = MetaDataType::DOUBLE;
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

void SemanticAnalysis::exitFuncDef(CACTParser::FuncDefContext * ctx)
{
    if (!ctx->funcBlock()->hasReturn && (curSymbolTable->getReturnType() != MetaDataType::VOID)) {
        throw std::runtime_error("[ERROR] > Non void function has no return.\n");
    }
    if (ctx->funcBlock()->funcBlockItem().back()->getText().find("return", 0) != 0) {
        irGenerator->exitFunction();
    }
    irGenerator->currentIRFunc->calFrameSize();
}

void SemanticAnalysis::enterFuncType(CACTParser::FuncTypeContext * ctx)
{
}

void SemanticAnalysis::exitFuncType(CACTParser::FuncTypeContext * ctx)
{   
}

void SemanticAnalysis::enterFuncFParams(CACTParser::FuncFParamsContext * ctx)
{
}

void SemanticAnalysis::exitFuncFParams(CACTParser::FuncFParamsContext * ctx)
{
    curSymbolTable->setParamNum();
    curSymbolTable->setParamDataTypeList();

    for(auto & param : ctx->funcFParam()){
        int gr = 0, fr = 0;
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
                case MetaDataType::BOOL:
                    g_index = new IRValue(MetaDataType::INT, std::to_string(gr), {}, false);
                    code = new IRGetParamB(param->symbolVar, g_index);
                    gr++;
                    break;
                case MetaDataType::INT:
                    g_index = new IRValue(MetaDataType::INT, std::to_string(gr), {}, false);
                    code = new IRGetParamB(param->symbolVar, g_index);
                    gr++;
                    break;
                case MetaDataType::FLOAT:
                    f_index = new IRValue(MetaDataType::INT, std::to_string(fr), {}, false);
                    code = new IRGetParamB(param->symbolVar, f_index);
                    fr++;
                    break;
                case MetaDataType::DOUBLE:
                    f_index = new IRValue(MetaDataType::INT, std::to_string(fr), {}, false);
                    code = new IRGetParamB(param->symbolVar, f_index);
                    fr++;
                    break;
            }
        }
        irGenerator->addCode(code);
    }
}

void SemanticAnalysis::enterFuncFParam(CACTParser::FuncFParamContext * ctx)
{
}
void SemanticAnalysis::exitFuncFParam(CACTParser::FuncFParamContext * ctx)
{
    SymbolFactory symbolFactory;
    AbstractSymbol *funcParamSymbol = SymbolFactory::createSymbol(ctx->Ident()->getText(), SymbolType::PARAM, ctx->bType()->bMetaDataType, ctx->brackets(), 0);
    if (!curSymbolTable->insertParamSymbolSafely(funcParamSymbol)) {
        throw std::runtime_error("[ERROR] > Redefine Function ParamSymbol.\n");
    }

    IRSymbolVariable *newParam = new IRSymbolVariable(funcParamSymbol, nullptr, false);
    ctx->symbolVar = newParam;
    irGenerator->currentIRFunc->addParamVariable(newParam);
    ctx->isArray = ctx->brackets() != nullptr;
    ctx->paramType = ctx->bType()->bMetaDataType;
}

void SemanticAnalysis::enterBrackets(CACTParser::BracketsContext * ctx) {}

void SemanticAnalysis::exitBrackets(CACTParser::BracketsContext * ctx) {}

void SemanticAnalysis::enterFuncBlock(CACTParser::FuncBlockContext * ctx) 
{
    ctx->hasReturn = false;
    if (curSymbolTable->getSymbolTableType() != TableType::FUNC) {
        SymbolTable *blkSymbolTable = new BlockSymbolTable(curSymbolTable);
        curSymbolTable->insertBlockSymbolTable(blkSymbolTable);
        curSymbolTable = blkSymbolTable;
    }
}

void SemanticAnalysis::exitFuncBlock(CACTParser::FuncBlockContext * ctx) 
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
}

void SemanticAnalysis::enterFuncBlockItem(CACTParser::FuncBlockItemContext * ctx) 
{
    ctx->hasReturn = false;
}

void SemanticAnalysis::exitFuncBlockItem(CACTParser::FuncBlockItemContext * ctx) 
{
    if (ctx->stmt() && ctx->stmt()->hasReturn) {
        ctx->hasReturn = true;
        ctx->returnType = ctx->stmt()->returnType;
    }
}

void SemanticAnalysis::enterBlock(CACTParser::BlockContext * ctx)
{
    ctx->hasReturn = false;
    ctx->returnType = MetaDataType::VOID;
    SymbolTable *blkSymbolTable = new BlockSymbolTable(curSymbolTable);
    curSymbolTable->insertBlockSymbolTable(blkSymbolTable);
    curSymbolTable = blkSymbolTable;

    block++;
}

void SemanticAnalysis::exitBlock(CACTParser::BlockContext * ctx)
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
}

void SemanticAnalysis::enterBlockItem(CACTParser::BlockItemContext * ctx)
{
    ctx->hasReturn = false;
    ctx->returnType = MetaDataType::VOID;
}

void SemanticAnalysis::exitBlockItem(CACTParser::BlockItemContext * ctx)
{
    if (ctx->subStmt() && ctx->subStmt()->hasReturn) {
        throw std::runtime_error("[NO ERROR] Block item return");
        ctx->hasReturn = true;
        ctx->returnType = ctx->subStmt()->returnType;
    }
}

void SemanticAnalysis::enterStmtAssignment(CACTParser::StmtAssignmentContext * ctx)
{
    ctx->hasReturn = false;

    AbstractSymbol *searchLVal = curSymbolTable->lookUpAbstractSymbolGlobal(ctx->lVal()->getText());

    if(searchLVal->getIsArray()){
        IROperand* temp = irGenerator->addTempVariable(searchLVal->getMetaDataType());
        ctx->exp()->indexOperand = temp;
        IRValue* zero = new IRValue(MetaDataType::INT, std::to_string(0), {}, false);
        IRCode* code = new IRAssignI(temp, zero);
        irGenerator->addCode(code);

        IRLabel* beginArray = irGenerator->enterWhile();
        ctx->beginArray = beginArray;
    }
}

void SemanticAnalysis::exitStmtAssignment(CACTParser::StmtAssignmentContext * ctx)
{
    if (ctx->lVal()->symbolType == SymbolType::CONST) {
        throw std::runtime_error("[ERROR] > cannot assign to a CONST statement.\n");
    }
    if (ctx->lVal()->lValMetaDataType != ctx->exp()->metaDataType) {
        throw std::runtime_error("[ERROR] > stmt type mismatch in assignment. " + std::to_string(static_cast<int>(ctx->lVal()->lValMetaDataType)) + std::to_string(static_cast<int>(ctx->exp()->metaDataType)));
    }
    if (ctx->lVal()->isArray) {
        if (!ctx->exp()->isArray) {
            throw std::runtime_error("[ERROR] > non-array assignment to array.\n");
        }
        if (ctx->lVal()->size != ctx->exp()->size) {
            throw std::runtime_error("[ERROR] > array size mismatch in assignment.\n");
        }
    }
    else {
        if (ctx->exp()->isArray) {
            throw std::runtime_error("[ERROR] > non-array assignment to non-array.\n");
        }
    }

    if(ctx->lVal()->isArray && ctx->exp()->isArray) {
        IRCode* assignCode = nullptr;
        switch (ctx->lVal()->lValMetaDataType) {
            case MetaDataType::BOOL:
                assignCode = new IRAssignArrayElemB(ctx->exp()->operand, ctx->lVal()->identOperand, ctx->exp()->indexOperand);
                break;
            case MetaDataType::INT:
                assignCode = new IRAssignArrayElemI(ctx->exp()->operand, ctx->lVal()->identOperand, ctx->exp()->indexOperand);
                break;
            case MetaDataType::FLOAT:
                assignCode = new IRAssignArrayElemF(ctx->exp()->operand, ctx->lVal()->identOperand, ctx->exp()->indexOperand);
                break;
            case MetaDataType::DOUBLE:
                assignCode = new IRAssignArrayElemD(ctx->exp()->operand, ctx->lVal()->identOperand, ctx->exp()->indexOperand);
                break;
        }
        irGenerator->addCode(assignCode);
        IRValue* one = new IRValue(MetaDataType::INT, std::to_string(1), {}, false);
        IRCode *code = new IRAddI(ctx->exp()->indexOperand, ctx->exp()->indexOperand, one);
        irGenerator->addCode(code);
        IRValue* sizeVal = new IRValue(MetaDataType::INT, std::to_string(ctx->lVal()->size), {}, false);
        IRTempVariable *tmp = irGenerator->addTempVariable(MetaDataType::INT);
        code = new IRSgeqI(tmp, ctx->exp()->indexOperand, sizeVal);
        irGenerator->addCode(code);
        code = new IRBeqz(tmp, ctx->beginArray);
        irGenerator->addCode(code);
    } else {
        if (ctx->lVal()->indexOperand) { // array[index] = value
            IRCode *assignCode = nullptr;
            switch (ctx->lVal()->lValMetaDataType) {
                case MetaDataType::BOOL:
                    assignCode = new IRAssignArrayElemB(ctx->exp()->operand, ctx->lVal()->identOperand,
                                                        ctx->lVal()->indexOperand);
                    break;
                case MetaDataType::INT:
                    assignCode = new IRAssignArrayElemI(ctx->exp()->operand, ctx->lVal()->identOperand,
                                                        ctx->lVal()->indexOperand);
                    break;
                case MetaDataType::FLOAT:
                    assignCode = new IRAssignArrayElemF(ctx->exp()->operand, ctx->lVal()->identOperand,
                                                        ctx->lVal()->indexOperand);
                    break;
                case MetaDataType::DOUBLE:
                    assignCode = new IRAssignArrayElemD(ctx->exp()->operand, ctx->lVal()->identOperand,
                                                        ctx->lVal()->indexOperand);
                    break;
            }
            irGenerator->addCode(assignCode);
        } else { // value_a = value_b
            // consider assigned attribute of IRSymbolVariable
            IROperand* operand = nullptr;
            if(ctx->lVal()->identOperand->getAssigned()) {
                IRTempVariable *temp = irGenerator->currentIRFunc->addTempVariable(ctx->lVal()->identOperand);
                ctx->lVal()->identOperand->addHistorySymbol(temp);
                irGenerator->addCode(new IRReplace(temp, ctx->lVal()->identOperand));
                operand = temp;
            } else {
                ctx->lVal()->identOperand->setAssigned();
                operand = ctx->lVal()->identOperand;
            }
            IRCode *assignCode = nullptr;
            switch (ctx->lVal()->lValMetaDataType) {
                case MetaDataType::BOOL:
                    assignCode = new IRAssignB(operand, ctx->exp()->operand);
                    break;
                case MetaDataType::INT:
                    assignCode = new IRAssignI(operand, ctx->exp()->operand);
                    break;
                case MetaDataType::FLOAT:
                    assignCode = new IRAssignF(operand, ctx->exp()->operand);
                    break;
                case MetaDataType::DOUBLE:
                    assignCode = new IRAssignD(operand, ctx->exp()->operand);
                    break;
            }
            irGenerator->addCode(assignCode);
        }
    }

    if(!ctx->codes.empty())
        irGenerator->addCodes(ctx->codes);
}

void SemanticAnalysis::enterStmtExpression(CACTParser::StmtExpressionContext * ctx)
{
    ctx->hasReturn = false;
}

void SemanticAnalysis::exitStmtExpression(CACTParser::StmtExpressionContext * ctx)
{
    if(!ctx->codes.empty())
        irGenerator->addCodes(ctx->codes);
}

void SemanticAnalysis::enterStmtBlock(CACTParser::StmtBlockContext * ctx)
{
    ctx->hasReturn = false;
    SymbolTable *blkSymbolTable = new BlockSymbolTable(curSymbolTable);
    curSymbolTable->insertBlockSymbolTable(blkSymbolTable);
    curSymbolTable = blkSymbolTable;
}

void SemanticAnalysis::exitStmtBlock(CACTParser::StmtBlockContext * ctx)
{
    curSymbolTable = curSymbolTable->getParentSymbolTable();
    if (ctx->funcBlock() && ctx->funcBlock()->hasReturn) {
        ctx->hasReturn = true;
        ctx->returnType = ctx->funcBlock()->returnType;
    }

    if(!ctx->codes.empty())
        irGenerator->addCodes(ctx->codes);
}

void SemanticAnalysis::enterStmtCtrlSeq(CACTParser::StmtCtrlSeqContext * ctx)
{
    ctx->hasReturn = false;


    IRLabel* falseLabel = irGenerator->addLabel();
    ctx->cond()->falseLabel = falseLabel;
    std::vector<IRCode *> codes;
    if(ctx->getText().rfind("if", 0) == 0){
        IRCode *code = new IRAddLabel(falseLabel);
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
}

void SemanticAnalysis::exitStmtCtrlSeq(CACTParser::StmtCtrlSeqContext * ctx)
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
}

void SemanticAnalysis::enterStmtReturn(CACTParser::StmtReturnContext * ctx)
{
}

void SemanticAnalysis::exitStmtReturn(CACTParser::StmtReturnContext * ctx)
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
            case MetaDataType::BOOL:
                code = new IRReturnB(ctx->exp()->operand);
                break;
            case MetaDataType::INT:
                code = new IRReturnI(ctx->exp()->operand);
                break;
            case MetaDataType::FLOAT:
                code = new IRReturnF(ctx->exp()->operand);
                break;
            case MetaDataType::DOUBLE:
                code = new IRReturnD(ctx->exp()->operand);
                break;
            default:
                break;
        }        
    } else {
        code = new IRReturnV();
    }
    irGenerator->addCode(code);
    if(!ctx->codes.empty())
        irGenerator->addCodes(ctx->codes);
}

void SemanticAnalysis::enterSubStmtAssignment(CACTParser::SubStmtAssignmentContext * ctx)
{
    ctx->hasReturn = false;
    ctx->returnType = MetaDataType::VOID;

    AbstractSymbol *searchLVal = curSymbolTable->lookUpAbstractSymbolGlobal(ctx->lVal()->getText());

    if(searchLVal->getIsArray()){
        IROperand* temp = irGenerator->addTempVariable(searchLVal->getMetaDataType());
        ctx->exp()->indexOperand = temp;
        IRValue* zero = new IRValue(MetaDataType::INT, std::to_string(0), {}, false);
        IRCode* code = new IRAssignI(temp, zero);
        irGenerator->addCode(code);

        IRLabel* beginArray = irGenerator->enterWhile();
        ctx->beginArray = beginArray;
    }
}

void SemanticAnalysis::exitSubStmtAssignment(CACTParser::SubStmtAssignmentContext * ctx)
{
    if (ctx->lVal()->symbolType == SymbolType::CONST) {
        throw std::runtime_error("[ERROR] > cannot assign to a CONST statement.\n");
    }
    if (ctx->lVal()->lValMetaDataType != ctx->exp()->metaDataType) {
        throw std::runtime_error("[ERROR] > substmt: type mismatch in assignment. " + std::to_string(static_cast<int>(ctx->lVal()->lValMetaDataType)) + std::to_string(static_cast<int>(ctx->exp()->metaDataType)));
    }
    if (ctx->lVal()->isArray) {
        if (ctx->exp() && !ctx->exp()->isArray) {
            throw std::runtime_error("[ERROR] > non-array assignment to array.\n");
        }
        if (ctx->lVal()->size != ctx->exp()->size) {
            throw std::runtime_error("[ERROR] > array size mismatch in assignment.\n");
        }
    }
    else {
        if (ctx->exp() && ctx->exp()->isArray) {
            throw std::runtime_error("[ERROR] > non-array assignment to non-array.\n");
        }
    }

    if(ctx->lVal()->isArray && ctx->exp()->isArray) {
        IRCode* assignCode = nullptr;
        switch (ctx->lVal()->lValMetaDataType) {
            case MetaDataType::BOOL:
                assignCode = new IRAssignArrayElemB(ctx->exp()->operand, ctx->lVal()->identOperand, ctx->exp()->indexOperand);
                break;
            case MetaDataType::INT:
                assignCode = new IRAssignArrayElemI(ctx->exp()->operand, ctx->lVal()->identOperand, ctx->exp()->indexOperand);
                break;
            case MetaDataType::FLOAT:
                assignCode = new IRAssignArrayElemF(ctx->exp()->operand, ctx->lVal()->identOperand, ctx->exp()->indexOperand);
                break;
            case MetaDataType::DOUBLE:
                assignCode = new IRAssignArrayElemD(ctx->exp()->operand, ctx->lVal()->identOperand, ctx->exp()->indexOperand);
                break;
        }
        irGenerator->addCode(assignCode);
        IRValue* one = new IRValue(MetaDataType::INT, std::to_string(1), {}, false);
        IRCode *code = new IRAddI(ctx->exp()->indexOperand, ctx->exp()->indexOperand, one);
        irGenerator->addCode(code);
        IRValue* sizeVal = new IRValue(MetaDataType::INT, std::to_string(ctx->lVal()->size), {}, false);
        IRTempVariable *tmp = irGenerator->addTempVariable(MetaDataType::INT);
        code = new IRSgeqI(tmp, ctx->exp()->indexOperand, sizeVal);
        irGenerator->addCode(code);
        code = new IRBeqz(tmp, ctx->beginArray);
        irGenerator->addCode(code);
    } else {
        if(ctx->lVal()->indexOperand){ // array[index] = value
            IRCode* assignCode = nullptr;
            switch (ctx->lVal()->lValMetaDataType) {
                case MetaDataType::BOOL:
                    assignCode = new IRAssignArrayElemB(ctx->exp()->operand, ctx->lVal()->identOperand, ctx->lVal()->indexOperand);
                    break;
                case MetaDataType::INT:
                    assignCode = new IRAssignArrayElemI(ctx->exp()->operand, ctx->lVal()->identOperand, ctx->lVal()->indexOperand);
                    break;
                case MetaDataType::FLOAT:
                    assignCode = new IRAssignArrayElemF(ctx->exp()->operand, ctx->lVal()->identOperand, ctx->lVal()->indexOperand);
                    break;
                case MetaDataType::DOUBLE:
                    assignCode = new IRAssignArrayElemD(ctx->exp()->operand, ctx->lVal()->identOperand, ctx->lVal()->indexOperand);
                    break;
            }
            irGenerator->addCode(assignCode);
        } else { // value_a = value_b
            // consider assigned attribute of IRSymbolVariable
            IROperand* operand = nullptr;
            if(ctx->lVal()->identOperand->getAssigned()) {
                IRTempVariable *temp = irGenerator->currentIRFunc->addTempVariable(ctx->lVal()->identOperand);
                ctx->lVal()->identOperand->addHistorySymbol(temp);
                irGenerator->addCode(new IRReplace(temp, ctx->lVal()->identOperand));
                operand = temp;
            } else {
                ctx->lVal()->identOperand->setAssigned();
                operand = ctx->lVal()->identOperand;
            }
            IRCode *assignCode = nullptr;
            switch (ctx->lVal()->lValMetaDataType) {
                case MetaDataType::BOOL:
                    assignCode = new IRAssignB(operand, ctx->exp()->operand);
                    break;
                case MetaDataType::INT:
                    assignCode = new IRAssignI(operand, ctx->exp()->operand);
                    break;
                case MetaDataType::FLOAT:
                    assignCode = new IRAssignF(operand, ctx->exp()->operand);
                    break;
                case MetaDataType::DOUBLE:
                    assignCode = new IRAssignD(operand, ctx->exp()->operand);
                    break;
            }
            irGenerator->addCode(assignCode);
        }
    }

    if(!ctx->codes.empty())
        irGenerator->addCodes(ctx->codes);
}

void SemanticAnalysis::enterSubStmtExpression(CACTParser::SubStmtExpressionContext * ctx)
{
    ctx->hasReturn = false;
    ctx->returnType = MetaDataType::VOID;
}

void SemanticAnalysis::exitSubStmtExpression(CACTParser::SubStmtExpressionContext * ctx)
{
    if(!ctx->codes.empty())
        irGenerator->addCodes(ctx->codes);
}

void SemanticAnalysis::enterSubStmtBlock(CACTParser::SubStmtBlockContext * ctx)
{
    SymbolTable *blkSymbolTable = new BlockSymbolTable(curSymbolTable);
    curSymbolTable->insertBlockSymbolTable(blkSymbolTable);
    curSymbolTable = blkSymbolTable;
    ctx->hasReturn = false;
    ctx->returnType = MetaDataType::VOID;
}

void SemanticAnalysis::exitSubStmtBlock(CACTParser::SubStmtBlockContext * ctx)
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
}

void SemanticAnalysis::enterSubStmtCtrlSeq(CACTParser::SubStmtCtrlSeqContext * ctx)
{
    ctx->hasReturn = false;
    ctx->returnType = MetaDataType::VOID;

    if (ctx->cond()) {
        IRLabel* falseLabel = irGenerator->addLabel();
        ctx->cond()->falseLabel = falseLabel;
        std::vector<IRCode *> codes;
        if(ctx->getText().rfind("if", 0) == 0){
            IRCode *code = new IRAddLabel(falseLabel);
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
}

void SemanticAnalysis::exitSubStmtCtrlSeq(CACTParser::SubStmtCtrlSeqContext * ctx)
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
}

void SemanticAnalysis::enterSubStmtReturn(CACTParser::SubStmtReturnContext * ctx)
{
}

void SemanticAnalysis::exitSubStmtReturn(CACTParser::SubStmtReturnContext * ctx)
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
            case MetaDataType::BOOL:
                code = new IRReturnB(ctx->exp()->operand);
                break;
            case MetaDataType::INT:
                code = new IRReturnI(ctx->exp()->operand);
                break;
            case MetaDataType::FLOAT:
                code = new IRReturnF(ctx->exp()->operand);
                break;
            case MetaDataType::DOUBLE:
                code = new IRReturnD(ctx->exp()->operand);
                break;
            default:
                break;
        }        
    } else {
        code = new IRReturnV();
    }
    irGenerator->addCode(code);

    if(!ctx->codes.empty())
        irGenerator->addCodes(ctx->codes);
}


// Exp
void SemanticAnalysis::enterExpAddExp(CACTParser::ExpAddExpContext * ctx)
{
    ctx->isArray = false;
    ctx->size = 0;
    ctx->metaDataType = MetaDataType::VOID;

    ctx->addExp()->indexOperand = ctx->indexOperand;
}

void SemanticAnalysis::exitExpAddExp(CACTParser::ExpAddExpContext * ctx)
{
    ctx->isArray = ctx->addExp()->isArray;
    ctx->size = ctx->addExp()->size;
    ctx->metaDataType = ctx->addExp()->metaDataType;
    ctx->operand = ctx->addExp()->operand;
}

void SemanticAnalysis::enterExpBoolExp(CACTParser::ExpBoolExpContext * ctx)
{
    ctx->isArray = false;
    ctx->size = 0;
    ctx->metaDataType = MetaDataType::VOID;
}

void SemanticAnalysis::exitExpBoolExp(CACTParser::ExpBoolExpContext * ctx)
{
    ctx->isArray = false;
    ctx->metaDataType = MetaDataType::BOOL;
    ctx->operand = new IRValue(MetaDataType::BOOL, ctx->getText(), false);
}

// Cond
void SemanticAnalysis::enterCond(CACTParser::CondContext * ctx)
{
    
}

void SemanticAnalysis::exitCond(CACTParser::CondContext * ctx)
{
    if(ctx->lOrExp()->metaDataType != MetaDataType::BOOL) {
        throw std::runtime_error("[ERROR] > condition must be bool");
    }
    IRCode* code = new IRBeqz(ctx->lOrExp()->operand,  ctx->falseLabel);
    irGenerator->addCode(code);
}

void SemanticAnalysis::enterLVal(CACTParser::LValContext * ctx)
{
    ctx->isArray = false;
    ctx->size = 0;
    ctx->symbolType = SymbolType::PARAM;
    ctx->lValMetaDataType = MetaDataType::VOID;
    ctx->indexOperand = nullptr;
}

void SemanticAnalysis::exitLVal(CACTParser::LValContext * ctx)
{
    if (ctx->exp()) {
        if (ctx->exp()->isArray || ctx->exp()->metaDataType != MetaDataType::INT) {
            throw std::runtime_error("[ERROR] > array index must be int.\n");
        }
    }
    AbstractSymbol *searchLVal = curSymbolTable->lookUpAbstractSymbolGlobal(ctx->Ident()->getText());
    if (!searchLVal){
        throw std::runtime_error("[ERROR] > var symbol used before defined. " + ctx->Ident()->getText() + " "  + std::to_string(static_cast<int>(curSymbolTable->getSymbolTableType())));
    }
    if (searchLVal->getIsArray() && !ctx->exp()) {
        ctx->isArray = true;
        ctx->size = searchLVal->getSize();
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
    if(ctx->exp()){
        ctx->indexOperand = ctx->exp()->operand;
    }
}


void SemanticAnalysis::enterPrimaryExpNestExp(CACTParser::PrimaryExpNestExpContext * ctx)
{
    ctx->isArray = false;
    ctx->size = 0;
    ctx->metaDataType = MetaDataType::VOID;

    ctx->exp()->indexOperand = ctx->indexOperand;
}

void SemanticAnalysis::exitPrimaryExpNestExp(CACTParser::PrimaryExpNestExpContext * ctx)
{
    ctx->isArray = ctx->exp()->isArray;
    ctx->size = ctx->exp()->size;
    ctx->metaDataType = ctx->exp()->metaDataType;

    ctx->operand = ctx->exp()->operand;
}

void SemanticAnalysis::enterPrimaryExplVal(CACTParser::PrimaryExplValContext * ctx)
{
    ctx->isArray = false;
    ctx->size = 0;
    ctx->metaDataType = MetaDataType::VOID;
}

void SemanticAnalysis::exitPrimaryExplVal(CACTParser::PrimaryExplValContext * ctx)
{
    ctx->isArray = ctx->lVal()->isArray;
    ctx->size = ctx->lVal()->size;
    ctx->metaDataType = ctx->lVal()->lValMetaDataType;

    if (ctx->lVal()->isArray && ctx->indexOperand){
        IROperand* tmp = irGenerator->addTempVariable(ctx->metaDataType);
        IRCode* fetchCode = nullptr;
        switch (ctx->lVal()->lValMetaDataType) {
            case MetaDataType::BOOL:
                fetchCode = new IRFetchArrayElemB(tmp, ctx->lVal()->identOperand, ctx->indexOperand);
                break;
            case MetaDataType::INT:
                fetchCode = new IRFetchArrayElemI(tmp, ctx->lVal()->identOperand, ctx->indexOperand);
                break;
            case MetaDataType::FLOAT:
                fetchCode = new IRFetchArrayElemF(tmp, ctx->lVal()->identOperand, ctx->indexOperand);
                break;
            case MetaDataType::DOUBLE:
                fetchCode = new IRFetchArrayElemD(tmp, ctx->lVal()->identOperand, ctx->indexOperand);
                break;
        }
        irGenerator->addCode(fetchCode);
        ctx->operand = tmp;
    }
    else if (ctx->lVal()->indexOperand){ // array[index]
        IROperand *result = irGenerator->addTempVariable(ctx->metaDataType);
        IRCode* code = nullptr;
        switch (ctx->lVal()->lValMetaDataType) {
            case MetaDataType::BOOL:
                code = new IRFetchArrayElemB(result, ctx->lVal()->identOperand, ctx->lVal()->indexOperand);
                break;
            case MetaDataType::INT:
                code = new IRFetchArrayElemI(result, ctx->lVal()->identOperand, ctx->lVal()->indexOperand);
                break;
            case MetaDataType::FLOAT:
                code = new IRFetchArrayElemF(result, ctx->lVal()->identOperand, ctx->lVal()->indexOperand);
                break;
            case MetaDataType::DOUBLE:
                code = new IRFetchArrayElemD(result, ctx->lVal()->identOperand, ctx->lVal()->indexOperand);
                break;
        }
        irGenerator->addCode(code);
        ctx->operand = result;
    } else {
        ctx->operand = ctx->lVal()->identOperand;
    }
}

void SemanticAnalysis::enterPrimaryExpNumber(CACTParser::PrimaryExpNumberContext * ctx)
{
    ctx->isArray = false;
    ctx->size = 0;
    ctx->metaDataType = MetaDataType::VOID;
}

void SemanticAnalysis::exitPrimaryExpNumber(CACTParser::PrimaryExpNumberContext * ctx)
{
    ctx->isArray = false;
    ctx->metaDataType = ctx->number()->metaDataType;
    if (ctx->metaDataType == MetaDataType::FLOAT || ctx->metaDataType == MetaDataType::DOUBLE) {
        ctx->operand = irGenerator->addImmValue(ctx->metaDataType, ctx->getText());
    }
    else {
        if (ctx->metaDataType == MetaDataType::BOOL || ctx->metaDataType == MetaDataType::INT) {
            ctx->operand = new IRValue(ctx->metaDataType, ctx->getText(), {}, false);
        }
        else {
            ctx->operand = irGenerator->addImmValue(ctx->metaDataType, ctx->getText());
        }
    }
}


// Unary
void SemanticAnalysis::enterUnaryExpPrimaryExp(CACTParser::UnaryExpPrimaryExpContext * ctx)
{
    ctx->isArray = false;
    ctx->size = 0;
    ctx->metaDataType = MetaDataType::VOID;

    ctx->primaryExp()->indexOperand = ctx->indexOperand;
}

void SemanticAnalysis::exitUnaryExpPrimaryExp(CACTParser::UnaryExpPrimaryExpContext * ctx)
{
    ctx->isArray = ctx->primaryExp()->isArray;
    ctx->size = ctx->primaryExp()->size;
    ctx->metaDataType = ctx->primaryExp()->metaDataType;
    ctx->operand = ctx->primaryExp()->operand;
}

void SemanticAnalysis::enterUnaryExpFunc(CACTParser::UnaryExpFuncContext * ctx)
{
    ctx->isArray = false;
    ctx->size = 0;
    ctx->metaDataType = MetaDataType::VOID;

}

void SemanticAnalysis::exitUnaryExpFunc(CACTParser::UnaryExpFuncContext * ctx)
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
            if (!funcSymbolTable->compareParamSymbolDataType(i, ctx->funcRParams()->metaDataTypeList[i], ctx->funcRParams()->isArrayList[i], ctx->funcRParams()->sizeList[i])) {
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
        IROperand *newResult = irGenerator->addTempVariable(funcSymbolTable->getReturnType());
        switch (funcSymbolTable->getReturnType())
        {
        case MetaDataType::BOOL:
            code = new IRGetReturnB(newResult);
            irGenerator->addCode(code);
            break;
        case MetaDataType::INT:
            code = new IRGetReturnI(newResult);
            irGenerator->addCode(code);
            break;
        case MetaDataType::FLOAT:
            code = new IRGetReturnF(newResult);
            irGenerator->addCode(code);
            break;
        case MetaDataType::DOUBLE:
            code = new IRGetReturnD(newResult);
            irGenerator->addCode(code);
            break;
        default:
            break;
        }
        ctx->operand = newResult;
    }
}

void SemanticAnalysis::enterUnaryExpNestUnaryExp(CACTParser::UnaryExpNestUnaryExpContext * ctx)
{
    ctx->isArray = false;
    ctx->size = 0;
    ctx->metaDataType = MetaDataType::VOID;

    ctx->unaryExp()->indexOperand = ctx->indexOperand;
}

void SemanticAnalysis::exitUnaryExpNestUnaryExp(CACTParser::UnaryExpNestUnaryExpContext * ctx)
{
    ctx->isArray = ctx->unaryExp()->isArray;
    ctx->metaDataType = ctx->unaryExp()->metaDataType;
    ctx->size = ctx->unaryExp()->size;
    if (ctx->unaryOp()->getText() == "!") {
        if (ctx->metaDataType != MetaDataType::BOOL || ctx->isArray) {
            throw std::runtime_error("[ERROR] > use logic operator on non-boolean expression.\n");
        }
    }
    else {
        if (ctx->metaDataType == MetaDataType::BOOL) {
            throw std::runtime_error("[ERROR] > use non-logic operator on boolean expression.\n");
        }
    }


    IROperand* result = irGenerator->addTempVariable(ctx->metaDataType);
    IRCode* code = nullptr;
    if(ctx->unaryOp()->getText() == "-"){
        switch (ctx->unaryExp()->operand->getMetaDataType()) {
            case MetaDataType::INT:
                code = new IRNegI(result, ctx->unaryExp()->operand);
                break;
            case MetaDataType::FLOAT:
                code = new IRNegF(result, ctx->unaryExp()->operand);
                break;
            case MetaDataType::DOUBLE:
                code = new IRNegD(result, ctx->unaryExp()->operand);
                break;
        } 
    }
    else if(ctx->unaryOp()->getText() == "!"){
        code = new IRNot(result, ctx->unaryExp()->operand);
    }
    irGenerator->addCode(code);
    ctx->operand = result;
}

void SemanticAnalysis::enterUnaryOp(CACTParser::UnaryOpContext * ctx)
{
}

void SemanticAnalysis::exitUnaryOp(CACTParser::UnaryOpContext * ctx)
{
}

// funcRParams
void SemanticAnalysis::enterFuncRParams(CACTParser::FuncRParamsContext * ctx)
{
    ctx->isArrayList.clear();
    ctx->sizeList.clear();
    ctx->metaDataTypeList.clear();
}

void SemanticAnalysis::exitFuncRParams(CACTParser::FuncRParamsContext * ctx)
{
    for (auto & it : ctx->exp()) {
        ctx->isArrayList.emplace_back(it->isArray);
        ctx->sizeList.emplace_back(it->size);
        ctx->metaDataTypeList.emplace_back(it->metaDataType);
        switch (it->metaDataType) 
        {
        case MetaDataType::BOOL:
            irGenerator->addCode(new IRAddParamB(it->operand));
            break;

        case MetaDataType::INT:
            irGenerator->addCode(new IRAddParamI(it->operand));
            break;

        case MetaDataType::FLOAT:
            irGenerator->addCode(new IRAddParamF(it->operand));
            break;

        case MetaDataType::DOUBLE:
            irGenerator->addCode(new IRAddParamD(it->operand));
            break;

        default:
            throw std::runtime_error("[ERROR] > data type fault.\n");
            break;
        }
    }
}

// MulExp
void SemanticAnalysis::enterMulExpMulExp(CACTParser::MulExpMulExpContext * ctx)
{
    ctx->isArray = false;
    ctx->size = 0;
    ctx->metaDataType = MetaDataType::VOID;

    ctx->mulExp()->indexOperand = ctx->indexOperand;
    ctx->unaryExp()->indexOperand = ctx->indexOperand;
}

void SemanticAnalysis::exitMulExpMulExp(CACTParser::MulExpMulExpContext * ctx)
{
    ctx->isArray = ctx->mulExp()->isArray;
    ctx->metaDataType = ctx->mulExp()->metaDataType;
    ctx->size = ctx->mulExp()->size;
    if (ctx->metaDataType == MetaDataType::BOOL) {
        throw std::runtime_error("[ERROR] > mul: arithmetic calculation with boolean expression.\n");
    }
    if (ctx->metaDataType != ctx->unaryExp()->metaDataType) {
        throw std::runtime_error("[ERROR] > mul: type mismatch in calculation. " + std::to_string(static_cast<int>(ctx->metaDataType)) + std::to_string(static_cast<int>(ctx->unaryExp()->metaDataType)));
    }
    if (ctx->isArray) {
        if (!ctx->unaryExp()->isArray) {
            throw std::runtime_error("[ERROR] > mul: array:non-array calculation.\n");
        }
        if (ctx->size != ctx->mulExp()->size) {
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

    IROperand* result = irGenerator->addTempVariable(ctx->metaDataType);
    IRCode* code = nullptr;
    if (ctx->mulOp()->getText() == "*"){
        switch (ctx->mulExp()->operand->getMetaDataType()) {
            case MetaDataType::INT:
                code = new IRMulI(result, ctx->mulExp()->operand, ctx->unaryExp()->operand);
                break;
            case MetaDataType::FLOAT:
                code = new IRMulF(result, ctx->mulExp()->operand, ctx->unaryExp()->operand);
                break;
            case MetaDataType::DOUBLE:
                code = new IRMulD(result, ctx->mulExp()->operand, ctx->unaryExp()->operand);
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
            case MetaDataType::DOUBLE:
                code = new IRDivD(result, ctx->mulExp()->operand, ctx->unaryExp()->operand);
                break;
        }
    }
    else if (ctx->mulOp()->getText() == "%"){
        code = new IRMod(result, ctx->mulExp()->operand, ctx->unaryExp()->operand);
    }
    else
        throw std::runtime_error("[ERROR] > mulop illegal.\n");
    irGenerator->addCode(code);
    ctx->operand = result;
}

void SemanticAnalysis::enterMulExpUnaryExp(CACTParser::MulExpUnaryExpContext * ctx)
{
    ctx->isArray = false;
    ctx->size = 0;
    ctx->metaDataType = MetaDataType::VOID;

    ctx->unaryExp()->indexOperand = ctx->indexOperand;
}

void SemanticAnalysis::exitMulExpUnaryExp(CACTParser::MulExpUnaryExpContext * ctx)
{
    ctx->isArray = ctx->unaryExp()->isArray;
    ctx->metaDataType = ctx->unaryExp()->metaDataType;
    ctx->size = ctx->unaryExp()->size;

    ctx->operand = ctx->unaryExp()->operand;
}

void SemanticAnalysis::enterMulOp(CACTParser::MulOpContext * ctx) 
{
}

void SemanticAnalysis::exitMulOp(CACTParser::MulOpContext * ctx)
{
}

// AddExp
void SemanticAnalysis::enterAddExpAddExp(CACTParser::AddExpAddExpContext * ctx)
{
    ctx->isArray = false;
    ctx->size = 0;
    ctx->metaDataType = MetaDataType::VOID;

    ctx->addExp()->indexOperand = ctx->indexOperand;
    ctx->mulExp()->indexOperand = ctx->indexOperand;
}

void SemanticAnalysis::exitAddExpAddExp(CACTParser::AddExpAddExpContext * ctx)
{
    ctx->isArray = ctx->addExp()->isArray;
    ctx->metaDataType = ctx->addExp()->metaDataType;
    ctx->size = ctx->addExp()->size;
    if (ctx->metaDataType == MetaDataType::BOOL) {
        throw std::runtime_error("[ERROR] > add: arithmetic calculation with boolean expression.\n");
    }
    if (ctx->metaDataType != ctx->mulExp()->metaDataType) {
        throw std::runtime_error("[ERROR] > add: type mismatch in calculation. " + std::to_string(static_cast<int>(ctx->metaDataType)) + std::to_string(static_cast<int>(ctx->mulExp()->metaDataType)));
    }
    if (ctx->isArray) {
        if (!ctx->mulExp()->isArray) {
            throw std::runtime_error("[ERROR] > add: array:non-array calculation.\n");
        }
        if (ctx->size != ctx->mulExp()->size) {
            throw std::runtime_error("[ERROR] > array size mismatch in calculation.\n");
        }
    }
    else {
        if (ctx->mulExp()->isArray) {
            throw std::runtime_error("[ERROR] > add: non-array:array calculation. " + curSymbolTable->getFuncName() + " " + ctx->mulExp()->getText());
        }
    }

    IROperand* result = irGenerator->addTempVariable(ctx->metaDataType);
    IRCode* code = nullptr;
   
    if (ctx->addOp()->getText() == "+"){
        switch (ctx->addExp()->metaDataType) {
            case MetaDataType::INT:
                code = new IRAddI(result, ctx->addExp()->operand, ctx->mulExp()->operand);
                break;
            case MetaDataType::FLOAT:
                code = new IRAddF(result, ctx->addExp()->operand, ctx->mulExp()->operand);
                break;
            case MetaDataType::DOUBLE:
                code = new IRAddD(result, ctx->addExp()->operand, ctx->mulExp()->operand);
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
            case MetaDataType::DOUBLE:
                code = new IRSubD(result, ctx->addExp()->operand, ctx->mulExp()->operand);
                break;
        }
    }
    else
        throw std::runtime_error("[ERROR] > addop illegal.\n");
    
    irGenerator->addCode(code);
    ctx->operand = result;
}

void SemanticAnalysis::enterAddExpMulExp(CACTParser::AddExpMulExpContext * ctx)
{
    ctx->isArray = false;
    ctx->size = 0;
    ctx->metaDataType = MetaDataType::VOID;

    ctx->mulExp()->indexOperand = ctx->indexOperand;
}

void SemanticAnalysis::exitAddExpMulExp(CACTParser::AddExpMulExpContext * ctx)
{
    ctx->isArray = ctx->mulExp()->isArray;
    ctx->metaDataType = ctx->mulExp()->metaDataType;
    ctx->size = ctx->mulExp()->size;

    ctx->operand = ctx->mulExp()->operand;
}

// RelExp
void SemanticAnalysis::enterRelExpRelExp(CACTParser::RelExpRelExpContext * ctx)
{
    ctx->metaDataType = MetaDataType::VOID;
}

void SemanticAnalysis::exitRelExpRelExp(CACTParser::RelExpRelExpContext * ctx)
{
    if (ctx->addExp()->isArray) {
        throw std::runtime_error("[ERROR] > rel: array cannot be operands of logic operators.\n");
    }
    ctx->metaDataType = ctx->relExp()->metaDataType;
    if (ctx->metaDataType == MetaDataType::BOOL || ctx->addExp()->metaDataType == MetaDataType::BOOL) {
        throw std::runtime_error("[ERROR] > rel: relation calculation with boolean expression.\n");
    }
    if (ctx->metaDataType != ctx->addExp()->metaDataType) {
        throw std::runtime_error("[ERROR] > rel: relation calculation with different types.\n");
    }
    ctx->metaDataType = MetaDataType::BOOL;

    IROperand* result = irGenerator->addTempVariable(ctx->metaDataType);
    IRCode* code = nullptr;
    if (ctx->relOp()->getText() == "<"){
        switch (ctx->addExp()->metaDataType) {
            case MetaDataType::INT:
                code = new IRSltI(result, ctx->relExp()->operand, ctx->addExp()->operand);
                break;
            case MetaDataType::FLOAT:
                code = new IRSltF(result, ctx->relExp()->operand, ctx->addExp()->operand);
                break;
            case MetaDataType::DOUBLE:
                code = new IRSltD(result, ctx->relExp()->operand, ctx->addExp()->operand);
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
            case MetaDataType::DOUBLE:
                code = new IRSgtD(result, ctx->relExp()->operand, ctx->addExp()->operand);
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
            case MetaDataType::DOUBLE:
                code = new IRSleqD(result, ctx->relExp()->operand, ctx->addExp()->operand);
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
            case MetaDataType::DOUBLE:
                code = new IRSgeqD(result, ctx->relExp()->operand, ctx->addExp()->operand);
                break;
        }
    }
    else
        throw std::runtime_error("[ERROR] > addop illegal.\n");
    irGenerator->addCode(code);
    ctx->operand = result;
}

void SemanticAnalysis::enterRelExpAddExp(CACTParser::RelExpAddExpContext * ctx)
{
    ctx->metaDataType = MetaDataType::VOID;
}

void SemanticAnalysis::exitRelExpAddExp(CACTParser::RelExpAddExpContext * ctx)
{
    if (ctx->addExp()->isArray) {
        throw std::runtime_error("[ERROR] > rel add: array cannot be operands of logic operators. " + curSymbolTable->getFuncName());
    }
    ctx->metaDataType = ctx->addExp()->metaDataType;
    ctx->operand = ctx->addExp()->operand;
}

void SemanticAnalysis::enterRelExpBoolConst(CACTParser::RelExpBoolConstContext * ctx)
{
    ctx->metaDataType = MetaDataType::VOID;
}

void SemanticAnalysis::exitRelExpBoolConst(CACTParser::RelExpBoolConstContext * ctx)
{
    ctx->metaDataType = MetaDataType::BOOL;

    if (ctx->BoolConst()->getText() == "true") {
        ctx->operand = new IRValue(MetaDataType::BOOL, "1", false);
    }
    else {
        ctx->operand = new IRValue(MetaDataType::BOOL, "0", false);
    }
}

//EqExp
void SemanticAnalysis::enterEqExpRelExp(CACTParser::EqExpRelExpContext * ctx)
{
    ctx->metaDataType = MetaDataType::VOID;

}
void SemanticAnalysis::exitEqExpRelExp(CACTParser::EqExpRelExpContext * ctx)
{
    ctx->metaDataType = ctx->relExp()->metaDataType;
    ctx->operand = ctx->relExp()->operand;
}

void SemanticAnalysis::enterEqExpEqExp(CACTParser::EqExpEqExpContext * ctx)
{
    ctx->metaDataType = MetaDataType::VOID;
}

void SemanticAnalysis::exitEqExpEqExp(CACTParser::EqExpEqExpContext * ctx)
{
    if (ctx->eqExp()->metaDataType != ctx->relExp()->metaDataType) {
        throw std::runtime_error("[ERROR] > eq operator with different data type.\n");
    }
    ctx->metaDataType = MetaDataType::BOOL;

    IROperand* result = irGenerator->addTempVariable(ctx->metaDataType);
    IRCode* code = nullptr;
    if(ctx->eqOp()->getText() == "=="){
        switch (ctx->eqExp()->metaDataType) {
            case MetaDataType::BOOL:
                code = new IRSeqB(result, ctx->eqExp()->operand, ctx->relExp()->operand);
                break;
            case MetaDataType::INT:
                code = new IRSeqI(result, ctx->eqExp()->operand, ctx->relExp()->operand);
                break;
            case MetaDataType::FLOAT:
                code = new IRSeqF(result, ctx->eqExp()->operand, ctx->relExp()->operand);
                break;
            case MetaDataType::DOUBLE:
                code = new IRSeqD(result, ctx->eqExp()->operand, ctx->relExp()->operand);
                break;
        }
    } else if(ctx->eqOp()->getText() == "!=") {
        switch (ctx->eqExp()->metaDataType) {
            case MetaDataType::BOOL:
                code = new IRSneB(result, ctx->eqExp()->operand, ctx->relExp()->operand);
                break;
            case MetaDataType::INT:
                code = new IRSneI(result, ctx->eqExp()->operand, ctx->relExp()->operand);
                break;
            case MetaDataType::FLOAT:
                code = new IRSneF(result, ctx->eqExp()->operand, ctx->relExp()->operand);
                break;
            case MetaDataType::DOUBLE:
                code = new IRSneD(result, ctx->eqExp()->operand, ctx->relExp()->operand);
                break;
        }
    }
    irGenerator->addCode(code);
    ctx->operand = result;
}

//LAndExp
void SemanticAnalysis::enterLAndExpLAndExp(CACTParser::LAndExpLAndExpContext * ctx)
{
    ctx->metaDataType = MetaDataType::VOID;
}

void SemanticAnalysis::exitLAndExpLAndExp(CACTParser::LAndExpLAndExpContext * ctx)
{
    ctx->metaDataType = ctx->lAndExp()->metaDataType;
    if (ctx->metaDataType != MetaDataType::BOOL || ctx->eqExp()->metaDataType != MetaDataType::BOOL) {
        throw std::runtime_error("[ERROR] > logic calculation with non-boolean operands.\n");
    }
    IROperand* result = irGenerator->addTempVariable(ctx->metaDataType);
    auto code = new IRAnd(result, ctx->lAndExp()->operand, ctx->eqExp()->operand);
    irGenerator->addCode(code);
    ctx->operand = result;
}

void SemanticAnalysis::enterLAndExpEqExp(CACTParser::LAndExpEqExpContext * ctx)
{
    ctx->metaDataType = MetaDataType::VOID;
}

void SemanticAnalysis::exitLAndExpEqExp(CACTParser::LAndExpEqExpContext * ctx)
{
    ctx->metaDataType = ctx->eqExp()->metaDataType;
    ctx->operand = ctx->eqExp()->operand;
}

//LOrExp
void SemanticAnalysis::enterLOrExpLAndExp(CACTParser::LOrExpLAndExpContext * ctx)
{
    ctx->metaDataType = MetaDataType::VOID;
}

void SemanticAnalysis::exitLOrExpLAndExp(CACTParser::LOrExpLAndExpContext * ctx)
{
    ctx->metaDataType = ctx->lAndExp()->metaDataType;

    ctx->operand = ctx->lAndExp()->operand;
}
void SemanticAnalysis::enterLOrExpLOrExp(CACTParser::LOrExpLOrExpContext * ctx)
{
    ctx->metaDataType = MetaDataType::VOID;
}

void SemanticAnalysis::exitLOrExpLOrExp(CACTParser::LOrExpLOrExpContext * ctx)
{
    ctx->metaDataType = ctx->lAndExp()->metaDataType;
    if (ctx->metaDataType != MetaDataType::BOOL || ctx->lAndExp()->metaDataType != MetaDataType::BOOL) {
        throw std::runtime_error("[ERROR] > logic calculation with non-boolean operands.\n");
    }

    IROperand* result = irGenerator->addTempVariable(ctx->metaDataType);

    IROr *code = new IROr(result, ctx->lOrExp()->operand, ctx->lAndExp()->operand);
    irGenerator->addCode(code);
    ctx->operand = result;
}


// ConstExp
void SemanticAnalysis::enterConstExpNumber(CACTParser::ConstExpNumberContext * ctx)
{
    ctx->metaDataType = MetaDataType::VOID;

}
void SemanticAnalysis::exitConstExpNumber(CACTParser::ConstExpNumberContext * ctx)
{
    ctx->metaDataType = ctx->number()->metaDataType;
    ctx->val = ctx->getText();
}

void SemanticAnalysis::enterConstExpBoolConst(CACTParser::ConstExpBoolConstContext * ctx)
{
}

void SemanticAnalysis::exitConstExpBoolConst(CACTParser::ConstExpBoolConstContext * ctx)
{
    ctx->metaDataType = MetaDataType::BOOL;
    if(ctx->getText() == "true"){
        ctx->val = std::string("1");
    } else if (ctx->getText() == "false") {
        ctx->val = std::string("0");
    }
}

// Number
void SemanticAnalysis::enterNumberIntConst(CACTParser::NumberIntConstContext * ctx)
{

}
void SemanticAnalysis::exitNumberIntConst(CACTParser::NumberIntConstContext * ctx)
{
    ctx->metaDataType = MetaDataType::INT;
}

void SemanticAnalysis::enterNumberDoubleConst(CACTParser::NumberDoubleConstContext * ctx)
{

}
void SemanticAnalysis::exitNumberDoubleConst(CACTParser::NumberDoubleConstContext * ctx)
{
    ctx->metaDataType = MetaDataType::DOUBLE;
}
void SemanticAnalysis::enterNumberFloatConst(CACTParser::NumberFloatConstContext * ctx)
{

}
void SemanticAnalysis::exitNumberFloatConst(CACTParser::NumberFloatConstContext * ctx)
{
    ctx->metaDataType = MetaDataType::FLOAT;
}

void SemanticAnalysis::enterEveryRule(antlr4::ParserRuleContext * ctx) {}
void SemanticAnalysis::exitEveryRule(antlr4::ParserRuleContext * ctx) {}
void SemanticAnalysis::visitTerminal(antlr4::tree::TerminalNode * node) {}
void SemanticAnalysis::visitErrorNode(antlr4::tree::ErrorNode * node) {}