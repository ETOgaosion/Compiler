
    #include "../src/SymbolTable.h"
    #include "../src/IROperands.h"
    #include "../src/IRCode.h"
    #include "../src/comm.h"
    #include <vector>
    #include <unordered_map>


// Generated from grammar/SysY.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "SysYParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by SysYParser.
 */
class  SysYListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterCompUnit(SysYParser::CompUnitContext *ctx) = 0;
  virtual void exitCompUnit(SysYParser::CompUnitContext *ctx) = 0;

  virtual void enterDecl(SysYParser::DeclContext *ctx) = 0;
  virtual void exitDecl(SysYParser::DeclContext *ctx) = 0;

  virtual void enterConstDecl(SysYParser::ConstDeclContext *ctx) = 0;
  virtual void exitConstDecl(SysYParser::ConstDeclContext *ctx) = 0;

  virtual void enterBType(SysYParser::BTypeContext *ctx) = 0;
  virtual void exitBType(SysYParser::BTypeContext *ctx) = 0;

  virtual void enterConstDef(SysYParser::ConstDefContext *ctx) = 0;
  virtual void exitConstDef(SysYParser::ConstDefContext *ctx) = 0;

  virtual void enterConstInitValOfVar(SysYParser::ConstInitValOfVarContext *ctx) = 0;
  virtual void exitConstInitValOfVar(SysYParser::ConstInitValOfVarContext *ctx) = 0;

  virtual void enterConstInitValOfArray(SysYParser::ConstInitValOfArrayContext *ctx) = 0;
  virtual void exitConstInitValOfArray(SysYParser::ConstInitValOfArrayContext *ctx) = 0;

  virtual void enterVarDecl(SysYParser::VarDeclContext *ctx) = 0;
  virtual void exitVarDecl(SysYParser::VarDeclContext *ctx) = 0;

  virtual void enterVarDef(SysYParser::VarDefContext *ctx) = 0;
  virtual void exitVarDef(SysYParser::VarDefContext *ctx) = 0;

  virtual void enterInitValOfVar(SysYParser::InitValOfVarContext *ctx) = 0;
  virtual void exitInitValOfVar(SysYParser::InitValOfVarContext *ctx) = 0;

  virtual void enterInitValOfArray(SysYParser::InitValOfArrayContext *ctx) = 0;
  virtual void exitInitValOfArray(SysYParser::InitValOfArrayContext *ctx) = 0;

  virtual void enterFuncDef(SysYParser::FuncDefContext *ctx) = 0;
  virtual void exitFuncDef(SysYParser::FuncDefContext *ctx) = 0;

  virtual void enterFuncType(SysYParser::FuncTypeContext *ctx) = 0;
  virtual void exitFuncType(SysYParser::FuncTypeContext *ctx) = 0;

  virtual void enterFuncFParams(SysYParser::FuncFParamsContext *ctx) = 0;
  virtual void exitFuncFParams(SysYParser::FuncFParamsContext *ctx) = 0;

  virtual void enterFuncFParam(SysYParser::FuncFParamContext *ctx) = 0;
  virtual void exitFuncFParam(SysYParser::FuncFParamContext *ctx) = 0;

  virtual void enterBrackets(SysYParser::BracketsContext *ctx) = 0;
  virtual void exitBrackets(SysYParser::BracketsContext *ctx) = 0;

  virtual void enterFuncBlock(SysYParser::FuncBlockContext *ctx) = 0;
  virtual void exitFuncBlock(SysYParser::FuncBlockContext *ctx) = 0;

  virtual void enterFuncBlockItem(SysYParser::FuncBlockItemContext *ctx) = 0;
  virtual void exitFuncBlockItem(SysYParser::FuncBlockItemContext *ctx) = 0;

  virtual void enterStmtAssignment(SysYParser::StmtAssignmentContext *ctx) = 0;
  virtual void exitStmtAssignment(SysYParser::StmtAssignmentContext *ctx) = 0;

  virtual void enterStmtExpression(SysYParser::StmtExpressionContext *ctx) = 0;
  virtual void exitStmtExpression(SysYParser::StmtExpressionContext *ctx) = 0;

  virtual void enterStmtBlock(SysYParser::StmtBlockContext *ctx) = 0;
  virtual void exitStmtBlock(SysYParser::StmtBlockContext *ctx) = 0;

  virtual void enterStmtCtrlSeq(SysYParser::StmtCtrlSeqContext *ctx) = 0;
  virtual void exitStmtCtrlSeq(SysYParser::StmtCtrlSeqContext *ctx) = 0;

  virtual void enterStmtReturn(SysYParser::StmtReturnContext *ctx) = 0;
  virtual void exitStmtReturn(SysYParser::StmtReturnContext *ctx) = 0;

  virtual void enterBlock(SysYParser::BlockContext *ctx) = 0;
  virtual void exitBlock(SysYParser::BlockContext *ctx) = 0;

  virtual void enterBlockItem(SysYParser::BlockItemContext *ctx) = 0;
  virtual void exitBlockItem(SysYParser::BlockItemContext *ctx) = 0;

  virtual void enterSubStmtAssignment(SysYParser::SubStmtAssignmentContext *ctx) = 0;
  virtual void exitSubStmtAssignment(SysYParser::SubStmtAssignmentContext *ctx) = 0;

  virtual void enterSubStmtExpression(SysYParser::SubStmtExpressionContext *ctx) = 0;
  virtual void exitSubStmtExpression(SysYParser::SubStmtExpressionContext *ctx) = 0;

  virtual void enterSubStmtBlock(SysYParser::SubStmtBlockContext *ctx) = 0;
  virtual void exitSubStmtBlock(SysYParser::SubStmtBlockContext *ctx) = 0;

  virtual void enterSubStmtCtrlSeq(SysYParser::SubStmtCtrlSeqContext *ctx) = 0;
  virtual void exitSubStmtCtrlSeq(SysYParser::SubStmtCtrlSeqContext *ctx) = 0;

  virtual void enterSubStmtReturn(SysYParser::SubStmtReturnContext *ctx) = 0;
  virtual void exitSubStmtReturn(SysYParser::SubStmtReturnContext *ctx) = 0;

  virtual void enterExp(SysYParser::ExpContext *ctx) = 0;
  virtual void exitExp(SysYParser::ExpContext *ctx) = 0;

  virtual void enterCond(SysYParser::CondContext *ctx) = 0;
  virtual void exitCond(SysYParser::CondContext *ctx) = 0;

  virtual void enterLVal(SysYParser::LValContext *ctx) = 0;
  virtual void exitLVal(SysYParser::LValContext *ctx) = 0;

  virtual void enterPrimaryExpNestExp(SysYParser::PrimaryExpNestExpContext *ctx) = 0;
  virtual void exitPrimaryExpNestExp(SysYParser::PrimaryExpNestExpContext *ctx) = 0;

  virtual void enterPrimaryExplVal(SysYParser::PrimaryExplValContext *ctx) = 0;
  virtual void exitPrimaryExplVal(SysYParser::PrimaryExplValContext *ctx) = 0;

  virtual void enterPrimaryExpNumber(SysYParser::PrimaryExpNumberContext *ctx) = 0;
  virtual void exitPrimaryExpNumber(SysYParser::PrimaryExpNumberContext *ctx) = 0;

  virtual void enterUnaryExpPrimaryExp(SysYParser::UnaryExpPrimaryExpContext *ctx) = 0;
  virtual void exitUnaryExpPrimaryExp(SysYParser::UnaryExpPrimaryExpContext *ctx) = 0;

  virtual void enterUnaryExpFunc(SysYParser::UnaryExpFuncContext *ctx) = 0;
  virtual void exitUnaryExpFunc(SysYParser::UnaryExpFuncContext *ctx) = 0;

  virtual void enterUnaryExpNestUnaryExp(SysYParser::UnaryExpNestUnaryExpContext *ctx) = 0;
  virtual void exitUnaryExpNestUnaryExp(SysYParser::UnaryExpNestUnaryExpContext *ctx) = 0;

  virtual void enterUnaryOp(SysYParser::UnaryOpContext *ctx) = 0;
  virtual void exitUnaryOp(SysYParser::UnaryOpContext *ctx) = 0;

  virtual void enterFuncRParams(SysYParser::FuncRParamsContext *ctx) = 0;
  virtual void exitFuncRParams(SysYParser::FuncRParamsContext *ctx) = 0;

  virtual void enterMulExpMulExp(SysYParser::MulExpMulExpContext *ctx) = 0;
  virtual void exitMulExpMulExp(SysYParser::MulExpMulExpContext *ctx) = 0;

  virtual void enterMulExpUnaryExp(SysYParser::MulExpUnaryExpContext *ctx) = 0;
  virtual void exitMulExpUnaryExp(SysYParser::MulExpUnaryExpContext *ctx) = 0;

  virtual void enterMulOp(SysYParser::MulOpContext *ctx) = 0;
  virtual void exitMulOp(SysYParser::MulOpContext *ctx) = 0;

  virtual void enterAddExpAddExp(SysYParser::AddExpAddExpContext *ctx) = 0;
  virtual void exitAddExpAddExp(SysYParser::AddExpAddExpContext *ctx) = 0;

  virtual void enterAddExpMulExp(SysYParser::AddExpMulExpContext *ctx) = 0;
  virtual void exitAddExpMulExp(SysYParser::AddExpMulExpContext *ctx) = 0;

  virtual void enterAddOp(SysYParser::AddOpContext *ctx) = 0;
  virtual void exitAddOp(SysYParser::AddOpContext *ctx) = 0;

  virtual void enterRelExpRelExp(SysYParser::RelExpRelExpContext *ctx) = 0;
  virtual void exitRelExpRelExp(SysYParser::RelExpRelExpContext *ctx) = 0;

  virtual void enterRelExpAddExp(SysYParser::RelExpAddExpContext *ctx) = 0;
  virtual void exitRelExpAddExp(SysYParser::RelExpAddExpContext *ctx) = 0;

  virtual void enterRelOp(SysYParser::RelOpContext *ctx) = 0;
  virtual void exitRelOp(SysYParser::RelOpContext *ctx) = 0;

  virtual void enterEqExpRelExp(SysYParser::EqExpRelExpContext *ctx) = 0;
  virtual void exitEqExpRelExp(SysYParser::EqExpRelExpContext *ctx) = 0;

  virtual void enterEqExpEqExp(SysYParser::EqExpEqExpContext *ctx) = 0;
  virtual void exitEqExpEqExp(SysYParser::EqExpEqExpContext *ctx) = 0;

  virtual void enterEqOp(SysYParser::EqOpContext *ctx) = 0;
  virtual void exitEqOp(SysYParser::EqOpContext *ctx) = 0;

  virtual void enterLAndExpLAndExp(SysYParser::LAndExpLAndExpContext *ctx) = 0;
  virtual void exitLAndExpLAndExp(SysYParser::LAndExpLAndExpContext *ctx) = 0;

  virtual void enterLAndExpEqExp(SysYParser::LAndExpEqExpContext *ctx) = 0;
  virtual void exitLAndExpEqExp(SysYParser::LAndExpEqExpContext *ctx) = 0;

  virtual void enterLOrExpLAndExp(SysYParser::LOrExpLAndExpContext *ctx) = 0;
  virtual void exitLOrExpLAndExp(SysYParser::LOrExpLAndExpContext *ctx) = 0;

  virtual void enterLOrExpLOrExp(SysYParser::LOrExpLOrExpContext *ctx) = 0;
  virtual void exitLOrExpLOrExp(SysYParser::LOrExpLOrExpContext *ctx) = 0;

  virtual void enterNumberIntConst(SysYParser::NumberIntConstContext *ctx) = 0;
  virtual void exitNumberIntConst(SysYParser::NumberIntConstContext *ctx) = 0;

  virtual void enterNumberFloatConst(SysYParser::NumberFloatConstContext *ctx) = 0;
  virtual void exitNumberFloatConst(SysYParser::NumberFloatConstContext *ctx) = 0;


};

