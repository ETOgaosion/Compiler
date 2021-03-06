#include "../grammar/CACTBaseListener.h"
#include "IRGenerator.h"
#include "tools.h"

#pragma once

class SemanticAnalysis : public CACTBaseListener
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

  void enterCompUnit(CACTParser::CompUnitContext * /*ctx*/) override;
  void exitCompUnit(CACTParser::CompUnitContext * /*ctx*/) override;

  void enterDecl(CACTParser::DeclContext * /*ctx*/) override;
  void exitDecl(CACTParser::DeclContext * /*ctx*/) override;

  void enterConstDecl(CACTParser::ConstDeclContext * /*ctx*/) override;
  void exitConstDecl(CACTParser::ConstDeclContext * /*ctx*/) override;

  void enterBType(CACTParser::BTypeContext * /*ctx*/) override;
  void exitBType(CACTParser::BTypeContext * /*ctx*/) override;

  void enterConstDef(CACTParser::ConstDefContext * /*ctx*/) override;
  void exitConstDef(CACTParser::ConstDefContext * /*ctx*/) override;

  void enterConstInitValOfVar(CACTParser::ConstInitValOfVarContext * /*ctx*/) override;
  void exitConstInitValOfVar(CACTParser::ConstInitValOfVarContext * /*ctx*/) override;

  void enterConstInitValOfArray(CACTParser::ConstInitValOfArrayContext * /*ctx*/) override;
  void exitConstInitValOfArray(CACTParser::ConstInitValOfArrayContext * /*ctx*/) override;

  void enterVarDecl(CACTParser::VarDeclContext * /*ctx*/) override;
  void exitVarDecl(CACTParser::VarDeclContext * /*ctx*/) override;

  void enterVarDef(CACTParser::VarDefContext * /*ctx*/) override;
  void exitVarDef(CACTParser::VarDefContext * /*ctx*/) override;

  void enterFuncDef(CACTParser::FuncDefContext * /*ctx*/) override;
  void exitFuncDef(CACTParser::FuncDefContext * /*ctx*/) override;

  void enterFuncType(CACTParser::FuncTypeContext * /*ctx*/) override;
  void exitFuncType(CACTParser::FuncTypeContext * /*ctx*/) override;

  void enterFuncFParams(CACTParser::FuncFParamsContext * /*ctx*/) override;
  void exitFuncFParams(CACTParser::FuncFParamsContext * /*ctx*/) override;

  void enterFuncFParam(CACTParser::FuncFParamContext * /*ctx*/) override;
  void exitFuncFParam(CACTParser::FuncFParamContext * /*ctx*/) override;

  void enterBrackets(CACTParser::BracketsContext * /*ctx*/) override;
  void exitBrackets(CACTParser::BracketsContext * /*ctx*/) override;

  void enterFuncBlock(CACTParser::FuncBlockContext * /*ctx*/) override;
  void exitFuncBlock(CACTParser::FuncBlockContext * /*ctx*/) override;

  void enterFuncBlockItem(CACTParser::FuncBlockItemContext * /*ctx*/) override;
  void exitFuncBlockItem(CACTParser::FuncBlockItemContext * /*ctx*/) override;

  void enterBlock(CACTParser::BlockContext * /*ctx*/) override;
  void exitBlock(CACTParser::BlockContext * /*ctx*/) override;

  void enterBlockItem(CACTParser::BlockItemContext * /*ctx*/) override;
  void exitBlockItem(CACTParser::BlockItemContext * /*ctx*/) override;

  void enterStmtAssignment(CACTParser::StmtAssignmentContext * /*ctx*/) override;
  void exitStmtAssignment(CACTParser::StmtAssignmentContext * /*ctx*/) override;

  void enterStmtExpression(CACTParser::StmtExpressionContext * /*ctx*/) override;
  void exitStmtExpression(CACTParser::StmtExpressionContext * /*ctx*/) override;

  void enterStmtBlock(CACTParser::StmtBlockContext * /*ctx*/) override;
  void exitStmtBlock(CACTParser::StmtBlockContext * /*ctx*/) override;

  void enterStmtCtrlSeq(CACTParser::StmtCtrlSeqContext * /*ctx*/) override;
  void exitStmtCtrlSeq(CACTParser::StmtCtrlSeqContext * /*ctx*/) override;

  void enterStmtReturn(CACTParser::StmtReturnContext * /*ctx*/) override;
  void exitStmtReturn(CACTParser::StmtReturnContext * /*ctx*/) override;

  void enterSubStmtAssignment(CACTParser::SubStmtAssignmentContext * /*ctx*/) override;
  void exitSubStmtAssignment(CACTParser::SubStmtAssignmentContext * /*ctx*/) override;

  void enterSubStmtExpression(CACTParser::SubStmtExpressionContext * /*ctx*/) override;
  void exitSubStmtExpression(CACTParser::SubStmtExpressionContext * /*ctx*/) override;

  void enterSubStmtBlock(CACTParser::SubStmtBlockContext * /*ctx*/) override;
  void exitSubStmtBlock(CACTParser::SubStmtBlockContext * /*ctx*/) override;

  void enterSubStmtCtrlSeq(CACTParser::SubStmtCtrlSeqContext * /*ctx*/) override;
  void exitSubStmtCtrlSeq(CACTParser::SubStmtCtrlSeqContext * /*ctx*/) override;

  void enterSubStmtReturn(CACTParser::SubStmtReturnContext * /*ctx*/) override;
  void exitSubStmtReturn(CACTParser::SubStmtReturnContext * /*ctx*/) override;

  void enterExpAddExp(CACTParser::ExpAddExpContext * /*ctx*/) override;
  void exitExpAddExp(CACTParser::ExpAddExpContext * /*ctx*/) override;

  void enterExpBoolExp(CACTParser::ExpBoolExpContext * /*ctx*/) override;
  void exitExpBoolExp(CACTParser::ExpBoolExpContext * /*ctx*/) override;

  void enterCond(CACTParser::CondContext * /*ctx*/) override;
  void exitCond(CACTParser::CondContext * /*ctx*/) override;

  void enterLVal(CACTParser::LValContext * /*ctx*/) override;
  void exitLVal(CACTParser::LValContext * /*ctx*/) override;

  void enterPrimaryExpNestExp(CACTParser::PrimaryExpNestExpContext * /*ctx*/) override;
  void exitPrimaryExpNestExp(CACTParser::PrimaryExpNestExpContext * /*ctx*/) override;

  void enterPrimaryExplVal(CACTParser::PrimaryExplValContext * /*ctx*/) override;
  void exitPrimaryExplVal(CACTParser::PrimaryExplValContext * /*ctx*/) override;

  void enterPrimaryExpNumber(CACTParser::PrimaryExpNumberContext * /*ctx*/) override;
  void exitPrimaryExpNumber(CACTParser::PrimaryExpNumberContext * /*ctx*/) override;

  void enterUnaryExpPrimaryExp(CACTParser::UnaryExpPrimaryExpContext * /*ctx*/) override;
  void exitUnaryExpPrimaryExp(CACTParser::UnaryExpPrimaryExpContext * /*ctx*/) override;

  void enterUnaryExpFunc(CACTParser::UnaryExpFuncContext * /*ctx*/) override;
  void exitUnaryExpFunc(CACTParser::UnaryExpFuncContext * /*ctx*/) override;

  void enterUnaryExpNestUnaryExp(CACTParser::UnaryExpNestUnaryExpContext * /*ctx*/) override;
  void exitUnaryExpNestUnaryExp(CACTParser::UnaryExpNestUnaryExpContext * /*ctx*/) override;

  void enterUnaryOp(CACTParser::UnaryOpContext * /*ctx*/) override;
  void exitUnaryOp(CACTParser::UnaryOpContext * /*ctx*/) override;

  void enterFuncRParams(CACTParser::FuncRParamsContext * /*ctx*/) override;
  void exitFuncRParams(CACTParser::FuncRParamsContext * /*ctx*/) override;

  void enterMulExpMulExp(CACTParser::MulExpMulExpContext * /*ctx*/) override;
  void exitMulExpMulExp(CACTParser::MulExpMulExpContext * /*ctx*/) override;

  void enterMulExpUnaryExp(CACTParser::MulExpUnaryExpContext * /*ctx*/) override;
  void exitMulExpUnaryExp(CACTParser::MulExpUnaryExpContext * /*ctx*/) override;

  void enterMulOp(CACTParser::MulOpContext * /*ctx*/) override;
  void exitMulOp(CACTParser::MulOpContext * /*ctx*/) override;

  void enterAddExpAddExp(CACTParser::AddExpAddExpContext * /*ctx*/) override;
  void exitAddExpAddExp(CACTParser::AddExpAddExpContext * /*ctx*/) override;

  void enterAddExpMulExp(CACTParser::AddExpMulExpContext * /*ctx*/) override;
  void exitAddExpMulExp(CACTParser::AddExpMulExpContext * /*ctx*/) override;

  void enterRelExpRelExp(CACTParser::RelExpRelExpContext * /*ctx*/) override;
  void exitRelExpRelExp(CACTParser::RelExpRelExpContext * /*ctx*/) override;

  void enterRelExpAddExp(CACTParser::RelExpAddExpContext * /*ctx*/) override;
  void exitRelExpAddExp(CACTParser::RelExpAddExpContext * /*ctx*/) override;

  void enterRelExpBoolConst(CACTParser::RelExpBoolConstContext * /*ctx*/) override;
  void exitRelExpBoolConst(CACTParser::RelExpBoolConstContext * /*ctx*/) override;

  void enterEqExpRelExp(CACTParser::EqExpRelExpContext * /*ctx*/) override;
  void exitEqExpRelExp(CACTParser::EqExpRelExpContext * /*ctx*/) override;

  void enterEqExpEqExp(CACTParser::EqExpEqExpContext * /*ctx*/) override;
  void exitEqExpEqExp(CACTParser::EqExpEqExpContext * /*ctx*/) override;

  void enterLAndExpLAndExp(CACTParser::LAndExpLAndExpContext * /*ctx*/) override;
  void exitLAndExpLAndExp(CACTParser::LAndExpLAndExpContext * /*ctx*/) override;

  void enterLAndExpEqExp(CACTParser::LAndExpEqExpContext * /*ctx*/) override;
  void exitLAndExpEqExp(CACTParser::LAndExpEqExpContext * /*ctx*/) override;

  void enterLOrExpLAndExp(CACTParser::LOrExpLAndExpContext * /*ctx*/) override;
  void exitLOrExpLAndExp(CACTParser::LOrExpLAndExpContext * /*ctx*/) override;

  void enterLOrExpLOrExp(CACTParser::LOrExpLOrExpContext * /*ctx*/) override;
  void exitLOrExpLOrExp(CACTParser::LOrExpLOrExpContext * /*ctx*/) override;

  void enterConstExpNumber(CACTParser::ConstExpNumberContext * /*ctx*/) override;
  void exitConstExpNumber(CACTParser::ConstExpNumberContext * /*ctx*/) override;

  void enterConstExpBoolConst(CACTParser::ConstExpBoolConstContext * /*ctx*/) override;
  void exitConstExpBoolConst(CACTParser::ConstExpBoolConstContext * /*ctx*/) override;

  void enterNumberIntConst(CACTParser::NumberIntConstContext * /*ctx*/) override;
  void exitNumberIntConst(CACTParser::NumberIntConstContext * /*ctx*/) override;

  void enterNumberDoubleConst(CACTParser::NumberDoubleConstContext * /*ctx*/) override;
  void exitNumberDoubleConst(CACTParser::NumberDoubleConstContext * /*ctx*/) override;

  void enterNumberFloatConst(CACTParser::NumberFloatConstContext * /*ctx*/) override;
  void exitNumberFloatConst(CACTParser::NumberFloatConstContext * /*ctx*/) override;


  void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override;
  void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override;
  void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override;
  void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override;
};
