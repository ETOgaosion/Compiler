#include "semanticAnalysis.h"

void SemanticAnalysis::enterCompUnit(CACTParser::CompUnitContext * ctx)
{
    curSymbolTable = SymbolTable::getGlobalSymbolTable();
    
    SymbolTable *funcSymbolTable = curSymbolTable->insertFuncSymbolTableSafely("print_int", MetaDataType::VOID, curSymbolTable);
    funcSymbolTable->insertParamSymbolSafely("", MetaDataType::INT, false, 0);
    funcSymbolTable->setParamDataTypeList();
    funcSymbolTable->setParamNum();
    
    funcSymbolTable = curSymbolTable->insertFuncSymbolTableSafely("print_float", MetaDataType::VOID, curSymbolTable);
    funcSymbolTable->insertParamSymbolSafely("", MetaDataType::FLOAT, false, 0);
    funcSymbolTable->setParamDataTypeList();
    funcSymbolTable->setParamNum();
    
    funcSymbolTable = curSymbolTable->insertFuncSymbolTableSafely("print_double", MetaDataType::VOID, curSymbolTable);
    funcSymbolTable->insertParamSymbolSafely("", MetaDataType::DOUBLE, false, 0);
    funcSymbolTable->setParamDataTypeList();
    funcSymbolTable->setParamNum();

    funcSymbolTable = curSymbolTable->insertFuncSymbolTableSafely("print_bool", MetaDataType::VOID, curSymbolTable);
    funcSymbolTable->insertParamSymbolSafely("", MetaDataType::BOOL, false, 0);
    funcSymbolTable->setParamDataTypeList();
    funcSymbolTable->setParamNum();

    funcSymbolTable = curSymbolTable->insertFuncSymbolTableSafely("get_int", MetaDataType::INT, curSymbolTable);
    funcSymbolTable->insertParamSymbolSafely("", MetaDataType::VOID, false, 0);
    funcSymbolTable->setParamDataTypeList();
    funcSymbolTable->setParamNum();

    funcSymbolTable = curSymbolTable->insertFuncSymbolTableSafely("get_float", MetaDataType::FLOAT, curSymbolTable);
    funcSymbolTable->insertParamSymbolSafely("", MetaDataType::VOID, false, 0);
    funcSymbolTable->setParamDataTypeList();
    funcSymbolTable->setParamNum();

    funcSymbolTable = curSymbolTable->insertFuncSymbolTableSafely("get_double", MetaDataType::DOUBLE, curSymbolTable);
    funcSymbolTable->insertParamSymbolSafely("", MetaDataType::VOID, false, 0);
    funcSymbolTable->setParamDataTypeList();
    funcSymbolTable->setParamNum();
}
void SemanticAnalysis::exitCompUnit(CACTParser::CompUnitContext * ctx)
{
    if(curSymbolTable->getSymbolTableType() != TableType::GLOBAL || !curSymbolTable->lookUpFuncSymbolTable("main")) {
        throw std::runtime_error("[ERROR] > There is no main function.\n");
    }
}

void SemanticAnalysis::enterDecl(CACTParser::DeclContext * ctx)
{
}
void SemanticAnalysis::exitDecl(CACTParser::DeclContext * ctx)
{
}

void SemanticAnalysis::SemanticAnalysis::enterConstDecl(CACTParser::ConstDeclContext * ctx)
{   
}
void SemanticAnalysis::SemanticAnalysis::exitConstDecl(CACTParser::ConstDeclContext * ctx)
{
    MetaDataType type = ctx->bType()->bMetaDataType;
    SymbolFactory symbolFactory;

    for(const auto & const_def : ctx->constDef())
    {
        AbstractSymbol *symbol = symbolFactory.createSymbol(const_def->symbolName, SymbolType::CONST, type, const_def->isArray, const_def->size);
        if (!curSymbolTable->insertAbstractSymbolSafely(symbol)) {
            throw std::runtime_error("[ERROR] > Redefine const symbol.\n");
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
    ctx->size = 0;
    ctx->isArray = false;
}

void SemanticAnalysis::exitConstDef(CACTParser::ConstDefContext * ctx)
{
    ctx->symbolName = ctx->Ident()->getText();
    if(!ctx->IntConst()){
        if(ctx->constInitVal()->isArray)
            throw std::runtime_error("[ERROR] > Non-array const is mistakenly initialized to be array.\n");
        ctx->isArray = false;
    } else {
        ctx->isArray = true;
        ctx->size = stoi(ctx->IntConst()->getText());  
        if(!ctx->constInitVal()->isArray)
            throw std::runtime_error("[ERROR] > Const Array is falsely initialized to be non-array const.\n");
        if(ctx->size < ctx->constInitVal()->size)
            throw std::runtime_error("[ERROR] > Const Array size overflow.\n");
    }
}

// ConstInitVal
void SemanticAnalysis::enterConstInitValOfVar(CACTParser::ConstInitValOfVarContext * ctx)
{
    ctx->type = MetaDataType::VOID;
    ctx->size = 0;
    ctx->isArray = false;
}

void SemanticAnalysis::exitConstInitValOfVar(CACTParser::ConstInitValOfVarContext * ctx)
{
    if(!ctx->constExp()){
        ctx->size = 0;
    } else {
        ctx->type = ctx->constExp()->metaDataType;
        ctx->size = 1;
    }   
    ctx->isArray = false;
}

void SemanticAnalysis::enterConstInitValOfArray(CACTParser::ConstInitValOfArrayContext * ctx)
{

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
}

// VarDecl
void SemanticAnalysis::SemanticAnalysis::enterVarDecl(CACTParser::VarDeclContext * ctx)
{
}
void SemanticAnalysis::SemanticAnalysis::exitVarDecl(CACTParser::VarDeclContext * ctx)
{
    MetaDataType type = ctx->bType()->bMetaDataType;
    SymbolFactory symbolFactory;

    for(const auto & var_def : ctx->varDef())
    {
        if (var_def->withType && var_def->type != type && var_def->type != MetaDataType::VOID) {
            throw std::runtime_error("[ERROR] > error in var initialization: type mismatch.\n");
        }
        AbstractSymbol *symbol = symbolFactory.createSymbol(var_def->symbolName, SymbolType::VAR, type, var_def->isArray, var_def->size);
        if (!curSymbolTable->insertAbstractSymbolSafely(symbol)) {
            throw std::runtime_error("[ERROR] > Redefine var symbol. " + symbol->getSymbolName());
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
            throw std::runtime_error("[ERROR] > wrong defination of main function");
        }
    }

    SymbolTable *funcSymbolTable = new FuncSymbolTable(ctx->Ident()->getText(), returnType);
    if (!curSymbolTable->insertFuncSymbolTableSafely(funcSymbolTable)) {
        throw std::runtime_error("[ERROR] > Redefine function of same name.\n");
    }
    funcSymbolTable->setParentSymbolTable(curSymbolTable);
    curSymbolTable = funcSymbolTable;

    enterFunction(ctx->Ident()->getText());

}

void SemanticAnalysis::exitFuncDef(CACTParser::FuncDefContext * ctx)
{
    if (!ctx->funcBlock()->hasReturn && (curSymbolTable->getReturnType() != MetaDataType::VOID)) {
        throw std::runtime_error("[ERROR] > Non void function has no return.\n");
    }
    exitFunction();
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
}

void SemanticAnalysis::enterFuncFParam(CACTParser::FuncFParamContext * ctx)
{
}
void SemanticAnalysis::exitFuncFParam(CACTParser::FuncFParamContext * ctx)
{
    SymbolFactory symbolFactory;
    AbstractSymbol *funcParamSymbol = symbolFactory.createSymbol(ctx->Ident()->getText(), SymbolType::PARAM, ctx->bType()->bMetaDataType, ctx->brackets(), 0);
    if (!curSymbolTable->insertParamSymbolSafely(funcParamSymbol)) {
        throw std::runtime_error("[ERROR] > Redefine Function ParamSymbol.\n");
    }
}
void SemanticAnalysis::enterBrackets(CACTParser::BracketsContext * ctx) {}
void SemanticAnalysis::exitBrackets(CACTParser::BracketsContext * ctx) { }

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


}

void SemanticAnalysis::enterStmtExpression(CACTParser::StmtExpressionContext * ctx)
{
    ctx->hasReturn = false;
}

void SemanticAnalysis::exitStmtExpression(CACTParser::StmtExpressionContext * ctx)
{
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
}

void SemanticAnalysis::enterStmtCtrlSeq(CACTParser::StmtCtrlSeqContext * ctx)
{
    ctx->hasReturn = false;
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

    // if(ctx->getText().find('if') == ctx->getText().begin()){
        
    // } else if (ctx->getText().find('while') == ctx->getText().begin()){

    // } else {
    //     throw std::runtime_error("[ERROR] > not if or while stmt\n");
    // }
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
}

void SemanticAnalysis::enterSubStmtAssignment(CACTParser::SubStmtAssignmentContext * ctx)
{
    ctx->hasReturn = false;
    ctx->returnType = MetaDataType::VOID;
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
}

void SemanticAnalysis::enterSubStmtExpression(CACTParser::SubStmtExpressionContext * ctx)
{
    ctx->hasReturn = false;
    ctx->returnType = MetaDataType::VOID;
}

void SemanticAnalysis::exitSubStmtExpression(CACTParser::SubStmtExpressionContext * ctx)
{
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
}

void SemanticAnalysis::enterSubStmtCtrlSeq(CACTParser::SubStmtCtrlSeqContext * ctx)
{
    ctx->hasReturn = false;
    ctx->returnType = MetaDataType::VOID;
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
}


// Exp
void SemanticAnalysis::enterExpAddExp(CACTParser::ExpAddExpContext * ctx)
{
    ctx->isArray = false;
    ctx->size = 0;
    ctx->metaDataType = MetaDataType::VOID;
}

void SemanticAnalysis::exitExpAddExp(CACTParser::ExpAddExpContext * ctx)
{
    ctx->isArray = ctx->addExp()->isArray;
    ctx->size = ctx->addExp()->size;
    ctx->metaDataType = ctx->addExp()->metaDataType;

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
    IRCode* code = IRCode::IRCode();
}

void SemanticAnalysis::enterLVal(CACTParser::LValContext * ctx)
{
    ctx->isArray = false;
    ctx->size = 0;
    ctx->symbolType = SymbolType::PARAM;
    ctx->lValMetaDataType = MetaDataType::VOID;
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
}


void SemanticAnalysis::enterPrimaryExpNestExp(CACTParser::PrimaryExpNestExpContext * ctx)
{
    ctx->isArray = false;
    ctx->size = 0;
    ctx->metaDataType = MetaDataType::VOID;
}

void SemanticAnalysis::exitPrimaryExpNestExp(CACTParser::PrimaryExpNestExpContext * ctx)
{
    ctx->isArray = ctx->exp()->isArray;
    ctx->size = ctx->exp()->size;
    ctx->metaDataType = ctx->exp()->metaDataType;
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
}


// Unary
void SemanticAnalysis::enterUnaryExpPrimaryExp(CACTParser::UnaryExpPrimaryExpContext * ctx)
{
    ctx->isArray = false;
    ctx->size = 0;
    ctx->metaDataType = MetaDataType::VOID;
}

void SemanticAnalysis::exitUnaryExpPrimaryExp(CACTParser::UnaryExpPrimaryExpContext * ctx)
{
    ctx->isArray = ctx->primaryExp()->isArray;
    ctx->size = ctx->primaryExp()->size;
    ctx->metaDataType = ctx->primaryExp()->metaDataType;
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

}

void SemanticAnalysis::enterUnaryExpNestUnaryExp(CACTParser::UnaryExpNestUnaryExpContext * ctx)
{
    ctx->isArray = false;
    ctx->size = 0;
    ctx->metaDataType = MetaDataType::VOID;
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
    }
}

// MulExp
void SemanticAnalysis::enterMulExpMulExp(CACTParser::MulExpMulExpContext * ctx)
{
    ctx->isArray = false;
    ctx->size = 0;
    ctx->metaDataType = MetaDataType::VOID;
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

    IROperand* result = new IRGenerator::addTempVariable(ctx->metaDataType);
    IROperation op;
    if (ctx->mulOp()->getText() == '*')
        op = IROperation::MUL;
    else if (ctx->mulOp()->getText() == '/')
        op = IROperation::DIV;
    else if (ctx->mulOp()->getText() == '%')
        op = IROperation::MOD;
    else
        throw std::runtime_error("[ERROR] > mulop illegal.\n");
    IRCode* code = new IRCode::IRCode(op, result, ctx->mulExp()->operand(0), ctx->unaryExp()->operand(0));
    IRGenerator->addCode(code);
}

void SemanticAnalysis::enterMulExpUnaryExp(CACTParser::MulExpUnaryExpContext * ctx)
{
    ctx->isArray = false;
    ctx->size = 0;
    ctx->metaDataType = MetaDataType::VOID;
}

void SemanticAnalysis::exitMulExpUnaryExp(CACTParser::MulExpUnaryExpContext * ctx)
{
    ctx->isArray = ctx->unaryExp()->isArray;
    ctx->metaDataType = ctx->unaryExp()->metaDataType;
    ctx->size = ctx->unaryExp()->size;
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
            throw std::runtime_error("[ERROR] > add: non-array:array calculation. " + curSymbolTable->getFuncName() + " " +ctx->mulExp()->getText());
        }
    }

    IROperand* result = new IRGenerator::addTempVariable(ctx->metaDataType);
    IROperation op;
    if (ctx->addOp()->getText() == '+')
        op = IROperation::ADD;
    else if (ctx->addOp()->getText() == '-')
        op = IROperation::SUB;
    else
        throw std::runtime_error("[ERROR] > addop illegal.\n");
    IRCode* code = new IRCode::IRCode(op, result, ctx->addExp()->operand(0), ctx->mulExp()->operand(0));
    IRGenerator->addCode(code);
}

void SemanticAnalysis::enterAddExpMulExp(CACTParser::AddExpMulExpContext * ctx)
{
    ctx->isArray = false;
    ctx->size = 0;
    ctx->metaDataType = MetaDataType::VOID;
}

void SemanticAnalysis::exitAddExpMulExp(CACTParser::AddExpMulExpContext * ctx)
{
    ctx->isArray = ctx->mulExp()->isArray;
    ctx->metaDataType = ctx->mulExp()->metaDataType;
    ctx->size = ctx->mulExp()->size;
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

    IROperand* result = new IRGenerator::addTempVariable(ctx->metaDataType);
    IROperation op;
    if (ctx->relOp()->getText() == '<')
        op = IROperation::SLT;
    else if (ctx->relOp()->getText() == '>')
        op = IROperation::SGT;
    else if (ctx->relOp()->getText() == '<=')
        op = IROperation::SLEQ;
    else if (ctx->relOp()->getText() == '>=')
        op = IROperation::SGEQ;
    else
        throw std::runtime_error("[ERROR] > addop illegal.\n");
    IRCode* code = new IRCode::IRCode(op, result, ctx->relExp()->operand, ctx->addExp()->operand);
    IRGenerator->addCode(code);
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
    IRValue* boolValue = new IRValue::IRValue(MetaDataType::BOOL, false, 0);
    if(ctx->BoolConst()->getText() == "true")
        boolValue->addValue("1");
    else if (ctx->BOOL()->getText() == "false")
        boolValue->addValue("0");
    ctx->oprand = boolValue;
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

    IROperand* result = new IRGenerator::addTempVariable(ctx->metaDataType);
    IROperation op;
    if(ctx->eqOp()->getText() == "==")
        op = IROperation::SEQ;
    else if(ctx->eqOp()->getText() == "!=")
        op = IROperation::SNE;
    IRCode* code = new IRCode::IRCode(op, result, ctx->eqExp()->operand, ctx->relExp()->operand);
    IRGenerator->addCode(code);
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
    IROperand* result = new IRGenerator::addTempVariable(ctx->metaDataType);
    IRCode* code = new IRCode::IRCode(IROperation::AND, result, ctx->lAndExp()->operand, ctx->eqExp()->operand);
    IRGenerator->addCode(code);
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

    IROperand* result = new IRGenerator::addTempVariable(ctx->metaDataType);
    IRCode *code = IRCode(IROperation::OR, result, ctx->lOrExp()->operand, ctx->lAndExp()->operand);
    IRGenerator->addCode(code);
}


// ConstExp
void SemanticAnalysis::enterConstExpNumber(CACTParser::ConstExpNumberContext * ctx)
{
    ctx->metaDataType = MetaDataType::VOID;

}
void SemanticAnalysis::exitConstExpNumber(CACTParser::ConstExpNumberContext * ctx)
{
    ctx->metaDataType = ctx->number()->metaDataType;   
}

void SemanticAnalysis::enterConstExpBoolConst(CACTParser::ConstExpBoolConstContext * ctx)
{
}

void SemanticAnalysis::exitConstExpBoolConst(CACTParser::ConstExpBoolConstContext * ctx)
{
    ctx->metaDataType = MetaDataType::BOOL;
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