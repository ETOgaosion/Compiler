#include "semanticAnalysis.h"
void SemanticAnalysis::enterCompUnit(CACTParser::CompUnitContext * ctx)
{
    curSymbolTable = SymbolTable::getGlobalSymbolTable();
}
void SemanticAnalysis::exitCompUnit(CACTParser::CompUnitContext * ctx)
{
    ctx->globalSymbolTable->lookUpFuncSymbolTable("main");
    
}

void SemanticAnalysis::enterDecl(CACTParser::DeclContext * ctx)
{

}
void SemanticAnalysis::exitDecl(CACTParser::DeclContext * ctx)
{
    if(!ctx->constDecl().empty()){
        ctx->declSymbols = ctx->constDecl(0)->symbols;
    }
    else if(!ctx->varDecl().empty()){
        ctx->declSymbols = ctx->varDecl(0)->symbols;
    } else {
        throw std::runtime_error("No declaration define.\n");
    }
}

void SemanticAnalysis::SemanticAnalysis::enterConstDecl(CACTParser::ConstDeclContext * ctx)
{
    
}
void SemanticAnalysis::SemanticAnalysis::exitConstDecl(CACTParser::ConstDeclContext * ctx)
{
    std::cout << "const variable define: " << std::endl;
    MetaDataType type = ctx->bType(0)->bMetaDataType;

    for(const auto & const_def : ctx->constDef())
    {
        AbstractSymbol *symbol = SymbolFactory::createSymbol(const_def->symbolName, SymbolType::CONST, type, const_def->isArray, const_def->size);
        ctx->symbols.emplace_back(symbol);
    }
}

void SemanticAnalysis::enterBType(CACTParser::BTypeContext * ctx)
{

}

void SemanticAnalysis::exitBType(CACTParser::BTypeContext * ctx)
{
    std::string dataTypeText = ctx->getText();
    switch (dataTypeText)
    {
    case "bool":
        ctx->bMetaDataType = MetaDataType::BOOL;
        break;
    case "int":
        ctx->bMetaDataType = MetaDataType::INT;
        break;
    case "float":
        ctx->bMetaDataType = MetaDataType::FLOAT;
        break;
    case "double":
        ctx->bMetaDataType = MetaDataType::DOUBLE;
        break;
    
    default:
        throw std::runtime_error("Data Type not supportive\n");
        break;
    }
   
}

// ConstDef
void SemanticAnalysis::enterConstDef(CACTParser::ConstDefContext * ctx)
{

}
void SemanticAnalysis::exitConstDef(CACTParser::ConstDefContext * ctx)
{
    ctx-symbolName = ctx->Ident(0)->getText();
    if(ctx->IntConst().empty()){
        if(ctx->constInitVal()->isArray)
            throw std::runtime_error("Non-array const is mistakenly initialized to be array.\n")
        ctx->isArray = false;
    } else {
        ctx->isArray = true;
        ctx->size = stoi(ctx->IntConst(0)->getText());  
        if(!ctx->constInitVal()->isArray)
            throw std::runtime_error("Const Array is falsely initialized to be non-array const.\n");
        if(ctx->size < ctx->constInitVal()->size)
            throw std::runtime_error("Const Array size overflow.\n");
    }
}

// ConstInitVal
void SemanticAnalysis::enterConstInitValOfVar(CACTParser::ConstInitValOfVarContext * ctx)
{

}
void SemanticAnalysis::exitConstInitValOfVar(CACTParser::ConstInitValOfVarContext * ctx)
{
    if(ctx->constExp().emtpy()){
        ctx->size = 0;
    } else {
        ctx->type = ctx->constExp(0)->metaDataType;
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
        ctx->size = 0;
    }

    for(const auto & const_exp : ctx->constExp()){
        if(const_exp->metaDataType != ctx->type)
            throw std::runtime_error("Array data type is not consistent.\n");
    }
    ctx->isArray = true;
}

// VarDecl
void SemanticAnalysis::SemanticAnalysis::enterVarDecl(CACTParser::VarDeclContext * ctx)
{

}
void SemanticAnalysis::SemanticAnalysis::exitVarDecl(CACTParser::VarDeclContext * ctx)
{
    MetaDataType type = ctx->bType(0)->bMetaDataType;

    for(const auto & var_def : ctx->varDef())
    {
        AbstractSymbol *symbol = SymbolFactory::createSymbol(var_def->symbolName, SymbolType::VAR, type, var_def->isArray, var_def->size);
        ctx->symbols.emplace_back(symbol);
    }
}

void SemanticAnalysis::enterVarDef(CACTParser::VarDefContext * ctx)
{

}
void SemanticAnalysis::exitVarDef(CACTParser::VarDefContext * ctx)
{
    ctx->symbolName = ctx->Ident(0)->getText();
    if(ctx->IntConst().empty){
        ctx->isArray = false;
    } else {
        ctx->isArray = true;
        ctx->size = stoi(ctx->IntConst(0)->getText());
    }
}

void SemanticAnalysis::enterFuncDef(CACTParser::FuncDefContext * ctx)
{

}
void SemanticAnalysis::exitFuncDef(CACTParser::FuncDefContext * ctx)
{
    ctx->funcSymbolTable = new FuncSymbolTable(ctx->Ident(0)->getText(), ctx->funcType(0)->funcMetaDataType);
    for(const auto & paramSymbol : ctx->funcFParams(0)->symbols){
        if(!ctx->funcSymbolTable->insertParamSymbolSafely(paramSymbol))
            throw std::runtime_error("Func param insertion is repetitive.\n");
    }
}

void SemanticAnalysis::enterFuncType(CACTParser::FuncTypeContext * ctx)
{

}
void SemanticAnalysis::exitFuncType(CACTParser::FuncTypeContext * ctx)
{
    std::string datatype = ctx->getText();
    switch (datatype)
    {
    case "void":
        ctx->funcMetaDataType = MetaDataType::VOID;
        break;
    case "bool":
        ctx->funcMetaDataType = MetaDataType::BOOL;
        break;
    case "int":
        ctx->funcMetaDataType = MetaDataType::INT;
        break;
    case "float":
        ctx->funcMetaDataType = MetaDataType::FLOAT;
        break;
    case "double":
        ctx->funcMetaDataType = MetaDataType::DOUBLE;
        break;
    
    default:
        throw std::runtime_error("Data Type not supportive\n");
        break;
    }
    
}

void SemanticAnalysis::enterFuncFParams(CACTParser::FuncFParamsContext * ctx)
{

}
void SemanticAnalysis::exitFuncFParams(CACTParser::FuncFParamsContext * ctx)
{
    for(const auto & funcfparam : ctx->funcFParam()){
        ctx->symbols().emplace_back(funcfparam->symbol);
    }
}

void SemanticAnalysis::enterFuncFParam(CACTParser::FuncFParamContext * ctx)
{

}
void SemanticAnalysis::exitFuncFParam(CACTParser::FuncFParamContext * ctx)
{
    ctx->symbol = SymbolFactory::createSymbol(ctx->Ident(0)->getText(), SymbolType::PARAM, ctx->bType(0)->bMetaDataType, !ctx->brackets().empty(), 0);
}

void SemanticAnalysis::enterBlock(CACTParser::BlockContext * ctx)
{

}
void SemanticAnalysis::exitBlock(CACTParser::BlockContext * ctx)
{

}

void SemanticAnalysis::enterBlockItem(CACTParser::BlockItemContext * ctx)
{

}
void SemanticAnalysis::exitBlockItem(CACTParser::BlockItemContext * ctx)
{

}

void SemanticAnalysis::enterStmtAssignment(CACTParser::StmtAssignmentContext * ctx)
{

}
void SemanticAnalysis::exitStmtAssignment(CACTParser::StmtAssignmentContext * ctx)
{
    
}

void SemanticAnalysis::enterStmtExpression(CACTParser::StmtExpressionContext * ctx)
{

}
void SemanticAnalysis::exitStmtExpression(CACTParser::StmtExpressionContext * ctx)
{

}

void SemanticAnalysis::enterStmtBlock(CACTParser::StmtBlockContext * ctx)
{

}
void SemanticAnalysis::exitStmtBlock(CACTParser::StmtBlockContext * ctx)
{

}

void SemanticAnalysis::enterStmtCtrlSeq(CACTParser::StmtCtrlSeqContext * ctx)
{

}
void SemanticAnalysis::exitStmtCtrlSeq(CACTParser::StmtCtrlSeqContext * ctx)
{

}

void SemanticAnalysis::enterStmtReturn(CACTParser::StmtReturnContext * ctx)
{

}
void SemanticAnalysis::exitStmtReturn(CACTParser::StmtReturnContext * ctx)
{

}

// Exp
void SemanticAnalysis::enterExpAddExp(CACTParser::ExpAddExpContext * ctx)
{

}
void SemanticAnalysis::exitExpAddExp(CACTParser::ExpAddExpContext * ctx)
{

}

void SemanticAnalysis::enterExpBoolExp(CACTParser::ExpBoolExpContext * ctx)
{

}
void SemanticAnalysis::exitExpBoolExp(CACTParser::ExpBoolExpContext * ctx)
{

}

// Cond
void SemanticAnalysis::enterCond(CACTParser::CondContext * ctx)
{

}
void SemanticAnalysis::exitCond(CACTParser::CondContext * ctx)
{

}

void SemanticAnalysis::enterLVal(CACTParser::LValContext * ctx)
{
    
}
void SemanticAnalysis::exitLVal(CACTParser::LValContext * ctx)
{
    ctx->isArray = !ctx->exp().empty();
    // size
    ctx->idName = ctx->Ident(0)->getText();
    // if(curSymbolTable->lookUpAbstractSymbol)
}


void SemanticAnalysis::enterPrimaryExpNestExp(CACTParser::PrimaryExpNestExpContext * ctx)
{

}
void SemanticAnalysis::exitPrimaryExpNestExp(CACTParser::PrimaryExpNestExpContext * ctx)
{

}

void SemanticAnalysis::enterPrimaryExplVal(CACTParser::PrimaryExplValContext * ctx)
{

}
void SemanticAnalysis::exitPrimaryExplVal(CACTParser::PrimaryExplValContext * ctx)
{
    
}

void SemanticAnalysis::enterPrimaryExpNumber(CACTParser::PrimaryExpNumberContext * ctx)
{

}
void SemanticAnalysis::exitPrimaryExpNumber(CACTParser::PrimaryExpNumberContext * ctx)
{

}


// Unary
void SemanticAnalysis::enterUnaryExpPrimaryExp(CACTParser::UnaryExpPrimaryExpContext * ctx)
{

}
void SemanticAnalysis::exitUnaryExpPrimaryExp(CACTParser::UnaryExpPrimaryExpContext * ctx)
{
    ctx->isArray = ctx->primaryExp(0)->isArray;
    ctx->size = ctx->primaryExp(0)->size;
    ctx->metaDataType = ctx->primaryExp(0)->metaDataType;
}

void SemanticAnalysis::enterUnaryExpFunc(CACTParser::UnaryExpFuncContext * ctx)
{
    // TODO: check idname
    ctx->isArray = false;
    // type
}
void SemanticAnalysis::exitUnaryExpFunc(CACTParser::UnaryExpFuncContext * ctx)
{
    
}

void SemanticAnalysis::enterUnaryExpNestUnaryExp(CACTParser::UnaryExpNestUnaryExpContext * ctx)
{

}
void SemanticAnalysis::exitUnaryExpNestUnaryExp(CACTParser::UnaryExpNestUnaryExpContext * ctx)
{
    ctx->isArray = ctx->unaryExp(0)->isArray;
    ctx->metaDataType = ctx->unaryExp(0)->metaDataType;
    ctx->size = ctx->unaryExp(0)->size;
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

}
void SemanticAnalysis::exitFuncRParams(CACTParser::FuncRParamsContext * ctx)
{

}

// MulExp
void SemanticAnalysis::enterMulExpMulExp(CACTParser::MulExpMulExpContext * ctx)
{

}
void SemanticAnalysis::exitMulExpMulExp(CACTParser::MulExpMulExpContext * ctx)
{
    ctx->isArray = ctx->mulExp(0)->isArray;
    ctx->metaDataType = ctx->mulExp(0)->metaDataType;
    ctx->size = ctx->mulExp(0)->size;
}

void SemanticAnalysis::enterMulExpUnaryExp(CACTParser::MulExpUnaryExpContext * ctx)
{

}
void SemanticAnalysis::exitMulExpUnaryExp(CACTParser::MulExpUnaryExpContext * ctx)
{
    ctx->isArray = ctx->unaryExp(0)->isArray;
    ctx->metaDataType = ctx->unaryExp(0)->metaDataType;
    ctx->size = ctx->unaryExp(0)->size;
}

// AddExp
void SemanticAnalysis::enterAddExpAddExp(CACTParser::AddExpAddExpContext * ctx)
{

}
void SemanticAnalysis::exitAddExpAddExp(CACTParser::AddExpAddExpContext * ctx)
{
    ctx->isArray = ctx->mulExp(0)->isArray;
    ctx->metaDataType = ctx->mulExp(0)->metaDataType;
    ctx->size = ctx->mulExp(0)->size;
}

void SemanticAnalysis::enterAddExpMulExp(CACTParser::AddExpMulExpContext * ctx)
{

}
void SemanticAnalysis::exitAddExpMulExp(CACTParser::AddExpMulExpContext * ctx)
{
    ctx->isArray = ctx->mulExp(0)->isArray;
    ctx->metaDataType = ctx->mulExp(0)->metaDataType;
    ctx->size = ctx->mulExp(0)->size;
}

// RelExp
void SemanticAnalysis::enterRelExpRelExp(CACTParser::RelExpRelExpContext * ctx)
{

}
void SemanticAnalysis::exitRelExpRelExp(CACTParser::RelExpRelExpContext * ctx)
{
    ctx->isArray = ctx->addExp(0)->isArray;
    ctx->metaDataType = ctx->addExp(0)->metaDataType;
    ctx->size = ctx->addExp(0)->size;
}

void SemanticAnalysis::enterRelExpAddExp(CACTParser::RelExpAddExpContext * ctx)
{

}
void SemanticAnalysis::exitRelExpAddExp(CACTParser::RelExpAddExpContext * ctx)
{
    ctx->isArray = ctx->addExp(0)->isArray;
    ctx->metaDataType = ctx->addExp(0)->metaDataType;
    ctx->size = ctx->addExp(0)->size;
}

void SemanticAnalysis::enterRelExpBoolConst(CACTParser::RelExpBoolConstContext * ctx)
{

}
void SemanticAnalysis::exitRelExpBoolConst(CACTParser::RelExpBoolConstContext * ctx)
{
    ctx->isArray = false;
    ctx->metaDataType = MetaDataType::BOOL;
    ctx->size = 1;
}

//EqExp
void SemanticAnalysis::enterEqExpRelExp(CACTParser::EqExpRelExpContext * ctx)
{

}
void SemanticAnalysis::exitEqExpRelExp(CACTParser::EqExpRelExpContext * ctx)
{
    ctx->isArray = ctx->relExp(0)->isArray;
    ctx->metaDataType = ctx->relExp(0)->metaDataType;
    ctx->size = ctx->relExp(0)->size;
}

void SemanticAnalysis::enterEqExpEqExp(CACTParser::EqExpEqExpContext * ctx)
{

}
void SemanticAnalysis::exitEqExpEqExp(CACTParser::EqExpEqExpContext * ctx)
{
    ctx->isArray = ctx->relExp(0)->isArray;
    ctx->metaDataType = ctx->relExp(0)->metaDataType;
    ctx->size = ctx->relExp(0)->size;
}

//LAndExp
void SemanticAnalysis::enterLAndExpLAndExp(CACTParser::LAndExpLAndExpContext * ctx)
{

}
void SemanticAnalysis::exitLAndExpLAndExp(CACTParser::LAndExpLAndExpContext * ctx)
{
    ctx->isArray = ctx->eqExp(0)->isArray;
    ctx->metaDataType = ctx->eqExp(0)->metaDataType;
    ctx->size = ctx->eqExp(0)->size;
}

void SemanticAnalysis::enterLAndExpEqExp(CACTParser::LAndExpEqExpContext * ctx)
{

}
void SemanticAnalysis::exitLAndExpEqExp(CACTParser::LAndExpEqExpContext * ctx)
{
    ctx->isArray = ctx->eqExp(0)->isArray;
    ctx->metaDataType = ctx->eqExp(0)->metaDataType;
    ctx->size = ctx->eqExp(0)->size;
}

//LOrExp
void SemanticAnalysis::enterLOrExpLAndExp(CACTParser::LOrExpLAndExpContext * ctx)
{

}
void SemanticAnalysis::exitLOrExpLAndExp(CACTParser::LOrExpLAndExpContext * ctx)
{
    ctx->isArray = ctx->lAndExp(0)->isArray;
    ctx->metaDataType = ctx->lAndExp(0)->metaDataType;
    ctx->size = ctx->lAndExp(0)->size;
}
void SemanticAnalysis::enterLOrExpLOrExp(CACTParser::LOrExpLOrExpContext * ctx)
{

}
void SemanticAnalysis::exitLOrExpLOrExp(CACTParser::LOrExpLOrExpContext * ctx)
{
    ctx->isArray = ctx->lAndExp(0)->isArray;
    ctx->metaDataType = ctx->lAndExp(0)->metaDataType;
    ctx->size = ctx->lAndExp(0)->size;
}


// ConstExp
void SemanticAnalysis::enterConstExpNumber(CACTParser::ConstExpNumberContext * ctx)
{

}
void SemanticAnalysis::exitConstExpNumber(CACTParser::ConstExpNumberContext * ctx)
{
    ctx->metaDataType = ctx->number(0)->metaDataType;   
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

