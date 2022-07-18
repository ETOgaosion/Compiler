#include "../grammar/SysYBaseListener.h"
#include "IRGenerator.h"
#include "tools.h"

#pragma once

class SemanticAnalysis : public SysYBaseListener
{
private:
    int block;
    SymbolTable* curSymbolTable;
    IRGenerator* irGenerator;
    std::vector<IRLabel*> whileFalse;
    std::vector<IRLabel*> whileBegin;
public:
    std::string programName;
    int optimizationLevel;

    SemanticAnalysis(/* args */){}
    ~SemanticAnalysis(){}

     void enterCompUnit(SysYParser::CompUnitContext *ctx) override;
     void exitCompUnit(SysYParser::CompUnitContext *ctx) override;

     void enterDecl(SysYParser::DeclContext *ctx) override;
     void exitDecl(SysYParser::DeclContext *ctx) override;

     void enterConstDecl(SysYParser::ConstDeclContext *ctx) override;
     void exitConstDecl(SysYParser::ConstDeclContext *ctx) override;

     void enterBType(SysYParser::BTypeContext *ctx) override;
     void exitBType(SysYParser::BTypeContext *ctx) override;

     void enterConstDef(SysYParser::ConstDefContext *ctx) override;
     void exitConstDef(SysYParser::ConstDefContext *ctx) override;

     void enterConstInitValOfVar(SysYParser::ConstInitValOfVarContext *ctx) override;
     void exitConstInitValOfVar(SysYParser::ConstInitValOfVarContext *ctx) override;

     void enterConstInitValOfArray(SysYParser::ConstInitValOfArrayContext *ctx) override;
     void exitConstInitValOfArray(SysYParser::ConstInitValOfArrayContext *ctx) override;

     void enterVarDecl(SysYParser::VarDeclContext *ctx) override;
     void exitVarDecl(SysYParser::VarDeclContext *ctx) override;

     void enterVarDef(SysYParser::VarDefContext *ctx) override;
     void exitVarDef(SysYParser::VarDefContext *ctx) override;

     void enterInitVal(SysYParser::InitValContext *ctx) override;
     void exitInitVal(SysYParser::InitValContext *ctx) override;

     void enterFuncDef(SysYParser::FuncDefContext *ctx) override;
     void exitFuncDef(SysYParser::FuncDefContext *ctx) override;

     void enterFuncType(SysYParser::FuncTypeContext *ctx) override;
     void exitFuncType(SysYParser::FuncTypeContext *ctx) override;

     void enterFuncFParams(SysYParser::FuncFParamsContext *ctx) override;
     void exitFuncFParams(SysYParser::FuncFParamsContext *ctx) override;

     void enterFuncFParam(SysYParser::FuncFParamContext *ctx) override;
     void exitFuncFParam(SysYParser::FuncFParamContext *ctx) override;

     void enterBrackets(SysYParser::BracketsContext *ctx) override;
     void exitBrackets(SysYParser::BracketsContext *ctx) override;

     void enterFuncBlock(SysYParser::FuncBlockContext *ctx) override;
     void exitFuncBlock(SysYParser::FuncBlockContext *ctx) override;

     void enterFuncBlockItem(SysYParser::FuncBlockItemContext *ctx) override;
     void exitFuncBlockItem(SysYParser::FuncBlockItemContext *ctx) override;

     void enterStmtAssignment(SysYParser::StmtAssignmentContext *ctx) override;
     void exitStmtAssignment(SysYParser::StmtAssignmentContext *ctx) override;

     void enterStmtExpression(SysYParser::StmtExpressionContext *ctx) override;
     void exitStmtExpression(SysYParser::StmtExpressionContext *ctx) override;

     void enterStmtBlock(SysYParser::StmtBlockContext *ctx) override;
     void exitStmtBlock(SysYParser::StmtBlockContext *ctx) override;

     void enterStmtCtrlSeq(SysYParser::StmtCtrlSeqContext *ctx) override;
     void exitStmtCtrlSeq(SysYParser::StmtCtrlSeqContext *ctx) override;

     void enterStmtReturn(SysYParser::StmtReturnContext *ctx) override;
     void exitStmtReturn(SysYParser::StmtReturnContext *ctx) override;

     void enterBlock(SysYParser::BlockContext *ctx) override;
     void exitBlock(SysYParser::BlockContext *ctx) override;

     void enterBlockItem(SysYParser::BlockItemContext *ctx) override;
     void exitBlockItem(SysYParser::BlockItemContext *ctx) override;

     void enterSubStmtAssignment(SysYParser::SubStmtAssignmentContext *ctx) override;
     void exitSubStmtAssignment(SysYParser::SubStmtAssignmentContext *ctx) override;

     void enterSubStmtExpression(SysYParser::SubStmtExpressionContext *ctx) override;
     void exitSubStmtExpression(SysYParser::SubStmtExpressionContext *ctx) override;

     void enterSubStmtBlock(SysYParser::SubStmtBlockContext *ctx) override;
     void exitSubStmtBlock(SysYParser::SubStmtBlockContext *ctx) override;

     void enterSubStmtCtrlSeq(SysYParser::SubStmtCtrlSeqContext *ctx) override;
     void exitSubStmtCtrlSeq(SysYParser::SubStmtCtrlSeqContext *ctx) override;

     void enterSubStmtReturn(SysYParser::SubStmtReturnContext *ctx) override;
     void exitSubStmtReturn(SysYParser::SubStmtReturnContext *ctx) override;

     void enterExp(SysYParser::ExpContext *ctx) override;
     void exitExp(SysYParser::ExpContext *ctx) override;

     void enterCond(SysYParser::CondContext *ctx) override;
     void exitCond(SysYParser::CondContext *ctx) override;

     void enterLVal(SysYParser::LValContext *ctx) override;
     void exitLVal(SysYParser::LValContext *ctx) override;

     void enterPrimaryExpNestExp(SysYParser::PrimaryExpNestExpContext *ctx) override;
     void exitPrimaryExpNestExp(SysYParser::PrimaryExpNestExpContext *ctx) override;

     void enterPrimaryExplVal(SysYParser::PrimaryExplValContext *ctx) override;
     void exitPrimaryExplVal(SysYParser::PrimaryExplValContext *ctx) override;

     void enterPrimaryExpNumber(SysYParser::PrimaryExpNumberContext *ctx) override;
     void exitPrimaryExpNumber(SysYParser::PrimaryExpNumberContext *ctx) override;

     void enterUnaryExpPrimaryExp(SysYParser::UnaryExpPrimaryExpContext *ctx) override;
     void exitUnaryExpPrimaryExp(SysYParser::UnaryExpPrimaryExpContext *ctx) override;

     void enterUnaryExpFunc(SysYParser::UnaryExpFuncContext *ctx) override;
     void exitUnaryExpFunc(SysYParser::UnaryExpFuncContext *ctx) override;

     void enterUnaryExpNestUnaryExp(SysYParser::UnaryExpNestUnaryExpContext *ctx) override;
     void exitUnaryExpNestUnaryExp(SysYParser::UnaryExpNestUnaryExpContext *ctx) override;

     void enterUnaryOp(SysYParser::UnaryOpContext *ctx) override;
     void exitUnaryOp(SysYParser::UnaryOpContext *ctx) override;

     void enterFuncRParams(SysYParser::FuncRParamsContext *ctx) override;
     void exitFuncRParams(SysYParser::FuncRParamsContext *ctx) override;

     void enterMulExpMulExp(SysYParser::MulExpMulExpContext *ctx) override;
     void exitMulExpMulExp(SysYParser::MulExpMulExpContext *ctx) override;

     void enterMulExpUnaryExp(SysYParser::MulExpUnaryExpContext *ctx) override;
     void exitMulExpUnaryExp(SysYParser::MulExpUnaryExpContext *ctx) override;

     void enterMulOp(SysYParser::MulOpContext *ctx) override;
     void exitMulOp(SysYParser::MulOpContext *ctx) override;

     void enterAddExpAddExp(SysYParser::AddExpAddExpContext *ctx) override;
     void exitAddExpAddExp(SysYParser::AddExpAddExpContext *ctx) override;

     void enterAddExpMulExp(SysYParser::AddExpMulExpContext *ctx) override;
     void exitAddExpMulExp(SysYParser::AddExpMulExpContext *ctx) override;

     void enterAddOp(SysYParser::AddOpContext *ctx) override;
     void exitAddOp(SysYParser::AddOpContext *ctx) override;

     void enterRelExpRelExp(SysYParser::RelExpRelExpContext *ctx) override;
     void exitRelExpRelExp(SysYParser::RelExpRelExpContext *ctx) override;

     void enterRelExpAddExp(SysYParser::RelExpAddExpContext *ctx) override;
     void exitRelExpAddExp(SysYParser::RelExpAddExpContext *ctx) override;

     void enterRelOp(SysYParser::RelOpContext *ctx) override;
     void exitRelOp(SysYParser::RelOpContext *ctx) override;

     void enterEqExpRelExp(SysYParser::EqExpRelExpContext *ctx) override;
     void exitEqExpRelExp(SysYParser::EqExpRelExpContext *ctx) override;

     void enterEqExpEqExp(SysYParser::EqExpEqExpContext *ctx) override;
     void exitEqExpEqExp(SysYParser::EqExpEqExpContext *ctx) override;

     void enterEqOp(SysYParser::EqOpContext *ctx) override;
     void exitEqOp(SysYParser::EqOpContext *ctx) override;

     void enterLAndExpLAndExp(SysYParser::LAndExpLAndExpContext *ctx) override;
     void exitLAndExpLAndExp(SysYParser::LAndExpLAndExpContext *ctx) override;

     void enterLAndExpEqExp(SysYParser::LAndExpEqExpContext *ctx) override;
     void exitLAndExpEqExp(SysYParser::LAndExpEqExpContext *ctx) override;

     void enterLOrExpLAndExp(SysYParser::LOrExpLAndExpContext *ctx) override;
     void exitLOrExpLAndExp(SysYParser::LOrExpLAndExpContext *ctx) override;

     void enterLOrExpLOrExp(SysYParser::LOrExpLOrExpContext *ctx) override;
     void exitLOrExpLOrExp(SysYParser::LOrExpLOrExpContext *ctx) override;

     void enterConstExpNumber(SysYParser::ConstExpNumberContext *ctx) override;
     void exitConstExpNumber(SysYParser::ConstExpNumberContext *ctx) override;

     void enterNumberIntConst(SysYParser::NumberIntConstContext *ctx) override;
     void exitNumberIntConst(SysYParser::NumberIntConstContext *ctx) override;

     void enterNumberFloatConst(SysYParser::NumberFloatConstContext *ctx) override;
     void exitNumberFloatConst(SysYParser::NumberFloatConstContext *ctx) override;


  void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override;
  void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override;
  void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override;
  void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override;
};
