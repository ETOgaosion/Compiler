
    #include "../src/SymbolTable.h"
    #include "../src/IROperands.h"
    #include "../src/IRCode.h"
    #include <vector>
    #include <unordered_map>


// Generated from grammar/SysY.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "SysYListener.h"


/**
 * This class provides an empty implementation of SysYListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  SysYBaseListener : public SysYListener {
public:

  virtual void enterCompUnit(SysYParser::CompUnitContext * /*ctx*/) override { }
  virtual void exitCompUnit(SysYParser::CompUnitContext * /*ctx*/) override { }

  virtual void enterDecl(SysYParser::DeclContext * /*ctx*/) override { }
  virtual void exitDecl(SysYParser::DeclContext * /*ctx*/) override { }

  virtual void enterConstDecl(SysYParser::ConstDeclContext * /*ctx*/) override { }
  virtual void exitConstDecl(SysYParser::ConstDeclContext * /*ctx*/) override { }

  virtual void enterBType(SysYParser::BTypeContext * /*ctx*/) override { }
  virtual void exitBType(SysYParser::BTypeContext * /*ctx*/) override { }

  virtual void enterConstDef(SysYParser::ConstDefContext * /*ctx*/) override { }
  virtual void exitConstDef(SysYParser::ConstDefContext * /*ctx*/) override { }

  virtual void enterConstInitValOfVar(SysYParser::ConstInitValOfVarContext * /*ctx*/) override { }
  virtual void exitConstInitValOfVar(SysYParser::ConstInitValOfVarContext * /*ctx*/) override { }

  virtual void enterConstInitValOfArray(SysYParser::ConstInitValOfArrayContext * /*ctx*/) override { }
  virtual void exitConstInitValOfArray(SysYParser::ConstInitValOfArrayContext * /*ctx*/) override { }

  virtual void enterVarDecl(SysYParser::VarDeclContext * /*ctx*/) override { }
  virtual void exitVarDecl(SysYParser::VarDeclContext * /*ctx*/) override { }

  virtual void enterVarDef(SysYParser::VarDefContext * /*ctx*/) override { }
  virtual void exitVarDef(SysYParser::VarDefContext * /*ctx*/) override { }

  virtual void enterInitVal(SysYParser::InitValContext * /*ctx*/) override { }
  virtual void exitInitVal(SysYParser::InitValContext * /*ctx*/) override { }

  virtual void enterFuncDef(SysYParser::FuncDefContext * /*ctx*/) override { }
  virtual void exitFuncDef(SysYParser::FuncDefContext * /*ctx*/) override { }

  virtual void enterFuncType(SysYParser::FuncTypeContext * /*ctx*/) override { }
  virtual void exitFuncType(SysYParser::FuncTypeContext * /*ctx*/) override { }

  virtual void enterFuncFParams(SysYParser::FuncFParamsContext * /*ctx*/) override { }
  virtual void exitFuncFParams(SysYParser::FuncFParamsContext * /*ctx*/) override { }

  virtual void enterFuncFParam(SysYParser::FuncFParamContext * /*ctx*/) override { }
  virtual void exitFuncFParam(SysYParser::FuncFParamContext * /*ctx*/) override { }

  virtual void enterBrackets(SysYParser::BracketsContext * /*ctx*/) override { }
  virtual void exitBrackets(SysYParser::BracketsContext * /*ctx*/) override { }

  virtual void enterFuncBlock(SysYParser::FuncBlockContext * /*ctx*/) override { }
  virtual void exitFuncBlock(SysYParser::FuncBlockContext * /*ctx*/) override { }

  virtual void enterFuncBlockItem(SysYParser::FuncBlockItemContext * /*ctx*/) override { }
  virtual void exitFuncBlockItem(SysYParser::FuncBlockItemContext * /*ctx*/) override { }

  virtual void enterStmtAssignment(SysYParser::StmtAssignmentContext * /*ctx*/) override { }
  virtual void exitStmtAssignment(SysYParser::StmtAssignmentContext * /*ctx*/) override { }

  virtual void enterStmtExpression(SysYParser::StmtExpressionContext * /*ctx*/) override { }
  virtual void exitStmtExpression(SysYParser::StmtExpressionContext * /*ctx*/) override { }

  virtual void enterStmtBlock(SysYParser::StmtBlockContext * /*ctx*/) override { }
  virtual void exitStmtBlock(SysYParser::StmtBlockContext * /*ctx*/) override { }

  virtual void enterStmtCtrlSeq(SysYParser::StmtCtrlSeqContext * /*ctx*/) override { }
  virtual void exitStmtCtrlSeq(SysYParser::StmtCtrlSeqContext * /*ctx*/) override { }

  virtual void enterStmtReturn(SysYParser::StmtReturnContext * /*ctx*/) override { }
  virtual void exitStmtReturn(SysYParser::StmtReturnContext * /*ctx*/) override { }

  virtual void enterBlock(SysYParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(SysYParser::BlockContext * /*ctx*/) override { }

  virtual void enterBlockItem(SysYParser::BlockItemContext * /*ctx*/) override { }
  virtual void exitBlockItem(SysYParser::BlockItemContext * /*ctx*/) override { }

  virtual void enterSubStmtAssignment(SysYParser::SubStmtAssignmentContext * /*ctx*/) override { }
  virtual void exitSubStmtAssignment(SysYParser::SubStmtAssignmentContext * /*ctx*/) override { }

  virtual void enterSubStmtExpression(SysYParser::SubStmtExpressionContext * /*ctx*/) override { }
  virtual void exitSubStmtExpression(SysYParser::SubStmtExpressionContext * /*ctx*/) override { }

  virtual void enterSubStmtBlock(SysYParser::SubStmtBlockContext * /*ctx*/) override { }
  virtual void exitSubStmtBlock(SysYParser::SubStmtBlockContext * /*ctx*/) override { }

  virtual void enterSubStmtCtrlSeq(SysYParser::SubStmtCtrlSeqContext * /*ctx*/) override { }
  virtual void exitSubStmtCtrlSeq(SysYParser::SubStmtCtrlSeqContext * /*ctx*/) override { }

  virtual void enterSubStmtReturn(SysYParser::SubStmtReturnContext * /*ctx*/) override { }
  virtual void exitSubStmtReturn(SysYParser::SubStmtReturnContext * /*ctx*/) override { }

  virtual void enterExp(SysYParser::ExpContext * /*ctx*/) override { }
  virtual void exitExp(SysYParser::ExpContext * /*ctx*/) override { }

  virtual void enterCond(SysYParser::CondContext * /*ctx*/) override { }
  virtual void exitCond(SysYParser::CondContext * /*ctx*/) override { }

  virtual void enterLVal(SysYParser::LValContext * /*ctx*/) override { }
  virtual void exitLVal(SysYParser::LValContext * /*ctx*/) override { }

  virtual void enterPrimaryExpNestExp(SysYParser::PrimaryExpNestExpContext * /*ctx*/) override { }
  virtual void exitPrimaryExpNestExp(SysYParser::PrimaryExpNestExpContext * /*ctx*/) override { }

  virtual void enterPrimaryExplVal(SysYParser::PrimaryExplValContext * /*ctx*/) override { }
  virtual void exitPrimaryExplVal(SysYParser::PrimaryExplValContext * /*ctx*/) override { }

  virtual void enterPrimaryExpNumber(SysYParser::PrimaryExpNumberContext * /*ctx*/) override { }
  virtual void exitPrimaryExpNumber(SysYParser::PrimaryExpNumberContext * /*ctx*/) override { }

  virtual void enterUnaryExpPrimaryExp(SysYParser::UnaryExpPrimaryExpContext * /*ctx*/) override { }
  virtual void exitUnaryExpPrimaryExp(SysYParser::UnaryExpPrimaryExpContext * /*ctx*/) override { }

  virtual void enterUnaryExpFunc(SysYParser::UnaryExpFuncContext * /*ctx*/) override { }
  virtual void exitUnaryExpFunc(SysYParser::UnaryExpFuncContext * /*ctx*/) override { }

  virtual void enterUnaryExpNestUnaryExp(SysYParser::UnaryExpNestUnaryExpContext * /*ctx*/) override { }
  virtual void exitUnaryExpNestUnaryExp(SysYParser::UnaryExpNestUnaryExpContext * /*ctx*/) override { }

  virtual void enterUnaryOp(SysYParser::UnaryOpContext * /*ctx*/) override { }
  virtual void exitUnaryOp(SysYParser::UnaryOpContext * /*ctx*/) override { }

  virtual void enterFuncRParams(SysYParser::FuncRParamsContext * /*ctx*/) override { }
  virtual void exitFuncRParams(SysYParser::FuncRParamsContext * /*ctx*/) override { }

  virtual void enterMulExpMulExp(SysYParser::MulExpMulExpContext * /*ctx*/) override { }
  virtual void exitMulExpMulExp(SysYParser::MulExpMulExpContext * /*ctx*/) override { }

  virtual void enterMulExpUnaryExp(SysYParser::MulExpUnaryExpContext * /*ctx*/) override { }
  virtual void exitMulExpUnaryExp(SysYParser::MulExpUnaryExpContext * /*ctx*/) override { }

  virtual void enterMulOp(SysYParser::MulOpContext * /*ctx*/) override { }
  virtual void exitMulOp(SysYParser::MulOpContext * /*ctx*/) override { }

  virtual void enterAddExpAddExp(SysYParser::AddExpAddExpContext * /*ctx*/) override { }
  virtual void exitAddExpAddExp(SysYParser::AddExpAddExpContext * /*ctx*/) override { }

  virtual void enterAddExpMulExp(SysYParser::AddExpMulExpContext * /*ctx*/) override { }
  virtual void exitAddExpMulExp(SysYParser::AddExpMulExpContext * /*ctx*/) override { }

  virtual void enterAddOp(SysYParser::AddOpContext * /*ctx*/) override { }
  virtual void exitAddOp(SysYParser::AddOpContext * /*ctx*/) override { }

  virtual void enterRelExpRelExp(SysYParser::RelExpRelExpContext * /*ctx*/) override { }
  virtual void exitRelExpRelExp(SysYParser::RelExpRelExpContext * /*ctx*/) override { }

  virtual void enterRelExpAddExp(SysYParser::RelExpAddExpContext * /*ctx*/) override { }
  virtual void exitRelExpAddExp(SysYParser::RelExpAddExpContext * /*ctx*/) override { }

  virtual void enterRelOp(SysYParser::RelOpContext * /*ctx*/) override { }
  virtual void exitRelOp(SysYParser::RelOpContext * /*ctx*/) override { }

  virtual void enterEqExpRelExp(SysYParser::EqExpRelExpContext * /*ctx*/) override { }
  virtual void exitEqExpRelExp(SysYParser::EqExpRelExpContext * /*ctx*/) override { }

  virtual void enterEqExpEqExp(SysYParser::EqExpEqExpContext * /*ctx*/) override { }
  virtual void exitEqExpEqExp(SysYParser::EqExpEqExpContext * /*ctx*/) override { }

  virtual void enterEqOp(SysYParser::EqOpContext * /*ctx*/) override { }
  virtual void exitEqOp(SysYParser::EqOpContext * /*ctx*/) override { }

  virtual void enterLAndExpLAndExp(SysYParser::LAndExpLAndExpContext * /*ctx*/) override { }
  virtual void exitLAndExpLAndExp(SysYParser::LAndExpLAndExpContext * /*ctx*/) override { }

  virtual void enterLAndExpEqExp(SysYParser::LAndExpEqExpContext * /*ctx*/) override { }
  virtual void exitLAndExpEqExp(SysYParser::LAndExpEqExpContext * /*ctx*/) override { }

  virtual void enterLOrExpLAndExp(SysYParser::LOrExpLAndExpContext * /*ctx*/) override { }
  virtual void exitLOrExpLAndExp(SysYParser::LOrExpLAndExpContext * /*ctx*/) override { }

  virtual void enterLOrExpLOrExp(SysYParser::LOrExpLOrExpContext * /*ctx*/) override { }
  virtual void exitLOrExpLOrExp(SysYParser::LOrExpLOrExpContext * /*ctx*/) override { }

  virtual void enterConstExpNumber(SysYParser::ConstExpNumberContext * /*ctx*/) override { }
  virtual void exitConstExpNumber(SysYParser::ConstExpNumberContext * /*ctx*/) override { }

  virtual void enterNumberIntConst(SysYParser::NumberIntConstContext * /*ctx*/) override { }
  virtual void exitNumberIntConst(SysYParser::NumberIntConstContext * /*ctx*/) override { }

  virtual void enterNumberFloatConst(SysYParser::NumberFloatConstContext * /*ctx*/) override { }
  virtual void exitNumberFloatConst(SysYParser::NumberFloatConstContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

