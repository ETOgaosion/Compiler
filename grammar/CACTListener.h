
    #include "../src/SymbolTable.h"


// Generated from grammar/CACT.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "CACTParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by CACTParser.
 */
class  CACTListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterCompUnit(CACTParser::CompUnitContext *ctx) = 0;
  virtual void exitCompUnit(CACTParser::CompUnitContext *ctx) = 0;

  virtual void enterDecl(CACTParser::DeclContext *ctx) = 0;
  virtual void exitDecl(CACTParser::DeclContext *ctx) = 0;

  virtual void enterConstDecl(CACTParser::ConstDeclContext *ctx) = 0;
  virtual void exitConstDecl(CACTParser::ConstDeclContext *ctx) = 0;

  virtual void enterBType(CACTParser::BTypeContext *ctx) = 0;
  virtual void exitBType(CACTParser::BTypeContext *ctx) = 0;

  virtual void enterConstDef(CACTParser::ConstDefContext *ctx) = 0;
  virtual void exitConstDef(CACTParser::ConstDefContext *ctx) = 0;

  virtual void enterConstInitValOfVar(CACTParser::ConstInitValOfVarContext *ctx) = 0;
  virtual void exitConstInitValOfVar(CACTParser::ConstInitValOfVarContext *ctx) = 0;

  virtual void enterConstInitValOfArray(CACTParser::ConstInitValOfArrayContext *ctx) = 0;
  virtual void exitConstInitValOfArray(CACTParser::ConstInitValOfArrayContext *ctx) = 0;

  virtual void enterVarDecl(CACTParser::VarDeclContext *ctx) = 0;
  virtual void exitVarDecl(CACTParser::VarDeclContext *ctx) = 0;

  virtual void enterVarDef(CACTParser::VarDefContext *ctx) = 0;
  virtual void exitVarDef(CACTParser::VarDefContext *ctx) = 0;

  virtual void enterFuncDef(CACTParser::FuncDefContext *ctx) = 0;
  virtual void exitFuncDef(CACTParser::FuncDefContext *ctx) = 0;

  virtual void enterFuncType(CACTParser::FuncTypeContext *ctx) = 0;
  virtual void exitFuncType(CACTParser::FuncTypeContext *ctx) = 0;

  virtual void enterFuncFParams(CACTParser::FuncFParamsContext *ctx) = 0;
  virtual void exitFuncFParams(CACTParser::FuncFParamsContext *ctx) = 0;

  virtual void enterFuncFParam(CACTParser::FuncFParamContext *ctx) = 0;
  virtual void exitFuncFParam(CACTParser::FuncFParamContext *ctx) = 0;

  virtual void enterBrackets(CACTParser::BracketsContext *ctx) = 0;
  virtual void exitBrackets(CACTParser::BracketsContext *ctx) = 0;

  virtual void enterFuncBlock(CACTParser::FuncBlockContext *ctx) = 0;
  virtual void exitFuncBlock(CACTParser::FuncBlockContext *ctx) = 0;

  virtual void enterFuncBlockItem(CACTParser::FuncBlockItemContext *ctx) = 0;
  virtual void exitFuncBlockItem(CACTParser::FuncBlockItemContext *ctx) = 0;

  virtual void enterStmtAssignment(CACTParser::StmtAssignmentContext *ctx) = 0;
  virtual void exitStmtAssignment(CACTParser::StmtAssignmentContext *ctx) = 0;

  virtual void enterStmtExpression(CACTParser::StmtExpressionContext *ctx) = 0;
  virtual void exitStmtExpression(CACTParser::StmtExpressionContext *ctx) = 0;

  virtual void enterStmtBlock(CACTParser::StmtBlockContext *ctx) = 0;
  virtual void exitStmtBlock(CACTParser::StmtBlockContext *ctx) = 0;

  virtual void enterStmtCtrlSeq(CACTParser::StmtCtrlSeqContext *ctx) = 0;
  virtual void exitStmtCtrlSeq(CACTParser::StmtCtrlSeqContext *ctx) = 0;

  virtual void enterStmtReturn(CACTParser::StmtReturnContext *ctx) = 0;
  virtual void exitStmtReturn(CACTParser::StmtReturnContext *ctx) = 0;

  virtual void enterBlock(CACTParser::BlockContext *ctx) = 0;
  virtual void exitBlock(CACTParser::BlockContext *ctx) = 0;

  virtual void enterBlockItem(CACTParser::BlockItemContext *ctx) = 0;
  virtual void exitBlockItem(CACTParser::BlockItemContext *ctx) = 0;

  virtual void enterSubStmtAssignment(CACTParser::SubStmtAssignmentContext *ctx) = 0;
  virtual void exitSubStmtAssignment(CACTParser::SubStmtAssignmentContext *ctx) = 0;

  virtual void enterSubStmtExpression(CACTParser::SubStmtExpressionContext *ctx) = 0;
  virtual void exitSubStmtExpression(CACTParser::SubStmtExpressionContext *ctx) = 0;

  virtual void enterSubStmtBlock(CACTParser::SubStmtBlockContext *ctx) = 0;
  virtual void exitSubStmtBlock(CACTParser::SubStmtBlockContext *ctx) = 0;

  virtual void enterSubStmtCtrlSeq(CACTParser::SubStmtCtrlSeqContext *ctx) = 0;
  virtual void exitSubStmtCtrlSeq(CACTParser::SubStmtCtrlSeqContext *ctx) = 0;

  virtual void enterSubStmtReturn(CACTParser::SubStmtReturnContext *ctx) = 0;
  virtual void exitSubStmtReturn(CACTParser::SubStmtReturnContext *ctx) = 0;

  virtual void enterExpAddExp(CACTParser::ExpAddExpContext *ctx) = 0;
  virtual void exitExpAddExp(CACTParser::ExpAddExpContext *ctx) = 0;

  virtual void enterExpBoolExp(CACTParser::ExpBoolExpContext *ctx) = 0;
  virtual void exitExpBoolExp(CACTParser::ExpBoolExpContext *ctx) = 0;

  virtual void enterCond(CACTParser::CondContext *ctx) = 0;
  virtual void exitCond(CACTParser::CondContext *ctx) = 0;

  virtual void enterLVal(CACTParser::LValContext *ctx) = 0;
  virtual void exitLVal(CACTParser::LValContext *ctx) = 0;

  virtual void enterPrimaryExpNestExp(CACTParser::PrimaryExpNestExpContext *ctx) = 0;
  virtual void exitPrimaryExpNestExp(CACTParser::PrimaryExpNestExpContext *ctx) = 0;

  virtual void enterPrimaryExplVal(CACTParser::PrimaryExplValContext *ctx) = 0;
  virtual void exitPrimaryExplVal(CACTParser::PrimaryExplValContext *ctx) = 0;

  virtual void enterPrimaryExpNumber(CACTParser::PrimaryExpNumberContext *ctx) = 0;
  virtual void exitPrimaryExpNumber(CACTParser::PrimaryExpNumberContext *ctx) = 0;

  virtual void enterUnaryExpPrimaryExp(CACTParser::UnaryExpPrimaryExpContext *ctx) = 0;
  virtual void exitUnaryExpPrimaryExp(CACTParser::UnaryExpPrimaryExpContext *ctx) = 0;

  virtual void enterUnaryExpFunc(CACTParser::UnaryExpFuncContext *ctx) = 0;
  virtual void exitUnaryExpFunc(CACTParser::UnaryExpFuncContext *ctx) = 0;

  virtual void enterUnaryExpNestUnaryExp(CACTParser::UnaryExpNestUnaryExpContext *ctx) = 0;
  virtual void exitUnaryExpNestUnaryExp(CACTParser::UnaryExpNestUnaryExpContext *ctx) = 0;

  virtual void enterUnaryOp(CACTParser::UnaryOpContext *ctx) = 0;
  virtual void exitUnaryOp(CACTParser::UnaryOpContext *ctx) = 0;

  virtual void enterFuncRParams(CACTParser::FuncRParamsContext *ctx) = 0;
  virtual void exitFuncRParams(CACTParser::FuncRParamsContext *ctx) = 0;

  virtual void enterMulExpMulExp(CACTParser::MulExpMulExpContext *ctx) = 0;
  virtual void exitMulExpMulExp(CACTParser::MulExpMulExpContext *ctx) = 0;

  virtual void enterMulExpUnaryExp(CACTParser::MulExpUnaryExpContext *ctx) = 0;
  virtual void exitMulExpUnaryExp(CACTParser::MulExpUnaryExpContext *ctx) = 0;

  virtual void enterMulOp(CACTParser::MulOpContext *ctx) = 0;
  virtual void exitMulOp(CACTParser::MulOpContext *ctx) = 0;

  virtual void enterAddExpAddExp(CACTParser::AddExpAddExpContext *ctx) = 0;
  virtual void exitAddExpAddExp(CACTParser::AddExpAddExpContext *ctx) = 0;

  virtual void enterAddExpMulExp(CACTParser::AddExpMulExpContext *ctx) = 0;
  virtual void exitAddExpMulExp(CACTParser::AddExpMulExpContext *ctx) = 0;

  virtual void enterRelExpRelExp(CACTParser::RelExpRelExpContext *ctx) = 0;
  virtual void exitRelExpRelExp(CACTParser::RelExpRelExpContext *ctx) = 0;

  virtual void enterRelExpAddExp(CACTParser::RelExpAddExpContext *ctx) = 0;
  virtual void exitRelExpAddExp(CACTParser::RelExpAddExpContext *ctx) = 0;

  virtual void enterRelExpBoolConst(CACTParser::RelExpBoolConstContext *ctx) = 0;
  virtual void exitRelExpBoolConst(CACTParser::RelExpBoolConstContext *ctx) = 0;

  virtual void enterEqExpRelExp(CACTParser::EqExpRelExpContext *ctx) = 0;
  virtual void exitEqExpRelExp(CACTParser::EqExpRelExpContext *ctx) = 0;

  virtual void enterEqExpEqExp(CACTParser::EqExpEqExpContext *ctx) = 0;
  virtual void exitEqExpEqExp(CACTParser::EqExpEqExpContext *ctx) = 0;

  virtual void enterLAndExpLAndExp(CACTParser::LAndExpLAndExpContext *ctx) = 0;
  virtual void exitLAndExpLAndExp(CACTParser::LAndExpLAndExpContext *ctx) = 0;

  virtual void enterLAndExpEqExp(CACTParser::LAndExpEqExpContext *ctx) = 0;
  virtual void exitLAndExpEqExp(CACTParser::LAndExpEqExpContext *ctx) = 0;

  virtual void enterLOrExpLAndExp(CACTParser::LOrExpLAndExpContext *ctx) = 0;
  virtual void exitLOrExpLAndExp(CACTParser::LOrExpLAndExpContext *ctx) = 0;

  virtual void enterLOrExpLOrExp(CACTParser::LOrExpLOrExpContext *ctx) = 0;
  virtual void exitLOrExpLOrExp(CACTParser::LOrExpLOrExpContext *ctx) = 0;

  virtual void enterConstExpNumber(CACTParser::ConstExpNumberContext *ctx) = 0;
  virtual void exitConstExpNumber(CACTParser::ConstExpNumberContext *ctx) = 0;

  virtual void enterConstExpBoolConst(CACTParser::ConstExpBoolConstContext *ctx) = 0;
  virtual void exitConstExpBoolConst(CACTParser::ConstExpBoolConstContext *ctx) = 0;

  virtual void enterNumberIntConst(CACTParser::NumberIntConstContext *ctx) = 0;
  virtual void exitNumberIntConst(CACTParser::NumberIntConstContext *ctx) = 0;

  virtual void enterNumberDoubleConst(CACTParser::NumberDoubleConstContext *ctx) = 0;
  virtual void exitNumberDoubleConst(CACTParser::NumberDoubleConstContext *ctx) = 0;

  virtual void enterNumberFloatConst(CACTParser::NumberFloatConstContext *ctx) = 0;
  virtual void exitNumberFloatConst(CACTParser::NumberFloatConstContext *ctx) = 0;


};

