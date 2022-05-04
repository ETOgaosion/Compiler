#pragma

#include "../grammar/CACTBaseListener.h"

class SemanticAnalysis : public CACTBaseListener
{
private:
    SymbolTable* curSymbolTable;
public:
    SemanticAnalysis(/* args */){}
    ~SemanticAnalysis(){}

  virtual void enterCompUnit(CACTParser::CompUnitContext * /*ctx*/) override { }
  virtual void exitCompUnit(CACTParser::CompUnitContext * /*ctx*/) override { }

  virtual void enterDecl(CACTParser::DeclContext * /*ctx*/) override { }
  virtual void exitDecl(CACTParser::DeclContext * /*ctx*/) override { }

  virtual void enterConstDecl(CACTParser::ConstDeclContext * /*ctx*/) override { }
  virtual void exitConstDecl(CACTParser::ConstDeclContext * /*ctx*/) override { }

  virtual void enterBType(CACTParser::BTypeContext * /*ctx*/) override { }
  virtual void exitBType(CACTParser::BTypeContext * /*ctx*/) override { }

  virtual void enterConstDef(CACTParser::ConstDefContext * /*ctx*/) override { }
  virtual void exitConstDef(CACTParser::ConstDefContext * /*ctx*/) override { }

  virtual void enterConstInitValOfVar(CACTParser::ConstInitValOfVarContext * /*ctx*/) override { }
  virtual void exitConstInitValOfVar(CACTParser::ConstInitValOfVarContext * /*ctx*/) override { }

  virtual void enterConstInitValOfArray(CACTParser::ConstInitValOfArrayContext * /*ctx*/) override { }
  virtual void exitConstInitValOfArray(CACTParser::ConstInitValOfArrayContext * /*ctx*/) override { }

  virtual void enterVarDecl(CACTParser::VarDeclContext * /*ctx*/) override { }
  virtual void exitVarDecl(CACTParser::VarDeclContext * /*ctx*/) override { }

  virtual void enterVarDef(CACTParser::VarDefContext * /*ctx*/) override { }
  virtual void exitVarDef(CACTParser::VarDefContext * /*ctx*/) override { }

  virtual void enterFuncDef(CACTParser::FuncDefContext * /*ctx*/) override { }
  virtual void exitFuncDef(CACTParser::FuncDefContext * /*ctx*/) override { }

  virtual void enterFuncType(CACTParser::FuncTypeContext * /*ctx*/) override { }
  virtual void exitFuncType(CACTParser::FuncTypeContext * /*ctx*/) override { }

  virtual void enterFuncFParams(CACTParser::FuncFParamsContext * /*ctx*/) override { }
  virtual void exitFuncFParams(CACTParser::FuncFParamsContext * /*ctx*/) override { }

  virtual void enterFuncFParam(CACTParser::FuncFParamContext * /*ctx*/) override { }
  virtual void exitFuncFParam(CACTParser::FuncFParamContext * /*ctx*/) override { }

  virtual void enterBlock(CACTParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(CACTParser::BlockContext * /*ctx*/) override { }

  virtual void enterBlockItem(CACTParser::BlockItemContext * /*ctx*/) override { }
  virtual void exitBlockItem(CACTParser::BlockItemContext * /*ctx*/) override { }

  virtual void enterStmtAssignment(CACTParser::StmtAssignmentContext * /*ctx*/) override { }
  virtual void exitStmtAssignment(CACTParser::StmtAssignmentContext * /*ctx*/) override { }

  virtual void enterStmtExpression(CACTParser::StmtExpressionContext * /*ctx*/) override { }
  virtual void exitStmtExpression(CACTParser::StmtExpressionContext * /*ctx*/) override { }

  virtual void enterStmtBlock(CACTParser::StmtBlockContext * /*ctx*/) override { }
  virtual void exitStmtBlock(CACTParser::StmtBlockContext * /*ctx*/) override { }

  virtual void enterStmtCtrlSeq(CACTParser::StmtCtrlSeqContext * /*ctx*/) override { }
  virtual void exitStmtCtrlSeq(CACTParser::StmtCtrlSeqContext * /*ctx*/) override { }

  virtual void enterStmtReturn(CACTParser::StmtReturnContext * /*ctx*/) override { }
  virtual void exitStmtReturn(CACTParser::StmtReturnContext * /*ctx*/) override { }

  virtual void enterExpAddExp(CACTParser::ExpAddExpContext * /*ctx*/) override { }
  virtual void exitExpAddExp(CACTParser::ExpAddExpContext * /*ctx*/) override { }

  virtual void enterExpBoolExp(CACTParser::ExpBoolExpContext * /*ctx*/) override { }
  virtual void exitExpBoolExp(CACTParser::ExpBoolExpContext * /*ctx*/) override { }

  virtual void enterCond(CACTParser::CondContext * /*ctx*/) override { }
  virtual void exitCond(CACTParser::CondContext * /*ctx*/) override { }

  virtual void enterLVal(CACTParser::LValContext * /*ctx*/) override { }
  virtual void exitLVal(CACTParser::LValContext * /*ctx*/) override { }

  virtual void enterPrimaryExpNestExp(CACTParser::PrimaryExpNestExpContext * /*ctx*/) override { }
  virtual void exitPrimaryExpNestExp(CACTParser::PrimaryExpNestExpContext * /*ctx*/) override { }

  virtual void enterPrimaryExplVal(CACTParser::PrimaryExplValContext * /*ctx*/) override { }
  virtual void exitPrimaryExplVal(CACTParser::PrimaryExplValContext * /*ctx*/) override { }

  virtual void enterPrimaryExpNumber(CACTParser::PrimaryExpNumberContext * /*ctx*/) override { }
  virtual void exitPrimaryExpNumber(CACTParser::PrimaryExpNumberContext * /*ctx*/) override { }

  virtual void enterUnaryExpPrimaryExp(CACTParser::UnaryExpPrimaryExpContext * /*ctx*/) override { }
  virtual void exitUnaryExpPrimaryExp(CACTParser::UnaryExpPrimaryExpContext * /*ctx*/) override { }

  virtual void enterUnaryExpFunc(CACTParser::UnaryExpFuncContext * /*ctx*/) override { }
  virtual void exitUnaryExpFunc(CACTParser::UnaryExpFuncContext * /*ctx*/) override { }

  virtual void enterUnaryExpNestUnaryExp(CACTParser::UnaryExpNestUnaryExpContext * /*ctx*/) override { }
  virtual void exitUnaryExpNestUnaryExp(CACTParser::UnaryExpNestUnaryExpContext * /*ctx*/) override { }

  virtual void enterUnaryOp(CACTParser::UnaryOpContext * /*ctx*/) override { }
  virtual void exitUnaryOp(CACTParser::UnaryOpContext * /*ctx*/) override { }

  virtual void enterFuncRParams(CACTParser::FuncRParamsContext * /*ctx*/) override { }
  virtual void exitFuncRParams(CACTParser::FuncRParamsContext * /*ctx*/) override { }

  virtual void enterMulExpMulExp(CACTParser::MulExpMulExpContext * /*ctx*/) override { }
  virtual void exitMulExpMulExp(CACTParser::MulExpMulExpContext * /*ctx*/) override { }

  virtual void enterMulExpUnaryExp(CACTParser::MulExpUnaryExpContext * /*ctx*/) override { }
  virtual void exitMulExpUnaryExp(CACTParser::MulExpUnaryExpContext * /*ctx*/) override { }

  virtual void enterAddExpAddExp(CACTParser::AddExpAddExpContext * /*ctx*/) override { }
  virtual void exitAddExpAddExp(CACTParser::AddExpAddExpContext * /*ctx*/) override { }

  virtual void enterAddExpMulExp(CACTParser::AddExpMulExpContext * /*ctx*/) override { }
  virtual void exitAddExpMulExp(CACTParser::AddExpMulExpContext * /*ctx*/) override { }

  virtual void enterRelExpRelExp(CACTParser::RelExpRelExpContext * /*ctx*/) override { }
  virtual void exitRelExpRelExp(CACTParser::RelExpRelExpContext * /*ctx*/) override { }

  virtual void enterRelExpAddExp(CACTParser::RelExpAddExpContext * /*ctx*/) override { }
  virtual void exitRelExpAddExp(CACTParser::RelExpAddExpContext * /*ctx*/) override { }

  virtual void enterRelExpBoolConst(CACTParser::RelExpBoolConstContext * /*ctx*/) override { }
  virtual void exitRelExpBoolConst(CACTParser::RelExpBoolConstContext * /*ctx*/) override { }

  virtual void enterEqExpRelExp(CACTParser::EqExpRelExpContext * /*ctx*/) override { }
  virtual void exitEqExpRelExp(CACTParser::EqExpRelExpContext * /*ctx*/) override { }

  virtual void enterEqExpEqExp(CACTParser::EqExpEqExpContext * /*ctx*/) override { }
  virtual void exitEqExpEqExp(CACTParser::EqExpEqExpContext * /*ctx*/) override { }

  virtual void enterLAndExpLAndExp(CACTParser::LAndExpLAndExpContext * /*ctx*/) override { }
  virtual void exitLAndExpLAndExp(CACTParser::LAndExpLAndExpContext * /*ctx*/) override { }

  virtual void enterLAndExpEqExp(CACTParser::LAndExpEqExpContext * /*ctx*/) override { }
  virtual void exitLAndExpEqExp(CACTParser::LAndExpEqExpContext * /*ctx*/) override { }

  virtual void enterLOrExpLAndExp(CACTParser::LOrExpLAndExpContext * /*ctx*/) override { }
  virtual void exitLOrExpLAndExp(CACTParser::LOrExpLAndExpContext * /*ctx*/) override { }

  virtual void enterLOrExpLOrExp(CACTParser::LOrExpLOrExpContext * /*ctx*/) override { }
  virtual void exitLOrExpLOrExp(CACTParser::LOrExpLOrExpContext * /*ctx*/) override { }

  virtual void enterConstExpNumber(CACTParser::ConstExpNumberContext * /*ctx*/) override { }
  virtual void exitConstExpNumber(CACTParser::ConstExpNumberContext * /*ctx*/) override { }

  virtual void enterConstExpBoolConst(CACTParser::ConstExpBoolConstContext * /*ctx*/) override { }
  virtual void exitConstExpBoolConst(CACTParser::ConstExpBoolConstContext * /*ctx*/) override { }

  virtual void enterNumberIntConst(CACTParser::NumberIntConstContext * /*ctx*/) override { }
  virtual void exitNumberIntConst(CACTParser::NumberIntConstContext * /*ctx*/) override { }

  virtual void enterNumberDoubleConst(CACTParser::NumberDoubleConstContext * /*ctx*/) override { }
  virtual void exitNumberDoubleConst(CACTParser::NumberDoubleConstContext * /*ctx*/) override { }

  virtual void enterNumberFloatConst(CACTParser::NumberFloatConstContext * /*ctx*/) override { }
  virtual void exitNumberFloatConst(CACTParser::NumberFloatConstContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }
};
