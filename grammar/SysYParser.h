
    #include "../src/SymbolTable.h"
    #include "../src/IROperands.h"
    #include "../src/IRCode.h"
    #include <vector>
    #include <unordered_map>


// Generated from grammar/SysY.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"




class  SysYParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    T__20 = 21, T__21 = 22, T__22 = 23, T__23 = 24, T__24 = 25, T__25 = 26, 
    T__26 = 27, T__27 = 28, T__28 = 29, T__29 = 30, T__30 = 31, T__31 = 32, 
    T__32 = 33, Ident = 34, IntConst = 35, DigitSequence = 36, FloatConst = 37, 
    DoubleConst = 38, NewLine = 39, WhiteSpace = 40, BlockComment = 41, 
    LineComment = 42
  };

  enum {
    RuleCompUnit = 0, RuleDecl = 1, RuleConstDecl = 2, RuleBType = 3, RuleConstDef = 4, 
    RuleConstInitVal = 5, RuleVarDecl = 6, RuleVarDef = 7, RuleInitVal = 8, 
    RuleFuncDef = 9, RuleFuncType = 10, RuleFuncFParams = 11, RuleFuncFParam = 12, 
    RuleBrackets = 13, RuleFuncBlock = 14, RuleFuncBlockItem = 15, RuleStmt = 16, 
    RuleBlock = 17, RuleBlockItem = 18, RuleSubStmt = 19, RuleExp = 20, 
    RuleCond = 21, RuleLVal = 22, RulePrimaryExp = 23, RuleUnaryExp = 24, 
    RuleUnaryOp = 25, RuleFuncRParams = 26, RuleMulExp = 27, RuleMulOp = 28, 
    RuleAddExp = 29, RuleAddOp = 30, RuleRelExp = 31, RuleRelOp = 32, RuleEqExp = 33, 
    RuleEqOp = 34, RuleLAndExp = 35, RuleLOrExp = 36, RuleConstExp = 37, 
    RuleNumber = 38
  };

  SysYParser(antlr4::TokenStream *input);
  ~SysYParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class CompUnitContext;
  class DeclContext;
  class ConstDeclContext;
  class BTypeContext;
  class ConstDefContext;
  class ConstInitValContext;
  class VarDeclContext;
  class VarDefContext;
  class InitValContext;
  class FuncDefContext;
  class FuncTypeContext;
  class FuncFParamsContext;
  class FuncFParamContext;
  class BracketsContext;
  class FuncBlockContext;
  class FuncBlockItemContext;
  class StmtContext;
  class BlockContext;
  class BlockItemContext;
  class SubStmtContext;
  class ExpContext;
  class CondContext;
  class LValContext;
  class PrimaryExpContext;
  class UnaryExpContext;
  class UnaryOpContext;
  class FuncRParamsContext;
  class MulExpContext;
  class MulOpContext;
  class AddExpContext;
  class AddOpContext;
  class RelExpContext;
  class RelOpContext;
  class EqExpContext;
  class EqOpContext;
  class LAndExpContext;
  class LOrExpContext;
  class ConstExpContext;
  class NumberContext; 

  class  CompUnitContext : public antlr4::ParserRuleContext {
  public:
    SymbolTable * globalSymbolTable;
    CompUnitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<DeclContext *> decl();
    DeclContext* decl(size_t i);
    std::vector<FuncDefContext *> funcDef();
    FuncDefContext* funcDef(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  CompUnitContext* compUnit();

  class  DeclContext : public antlr4::ParserRuleContext {
  public:
    DeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ConstDeclContext *constDecl();
    VarDeclContext *varDecl();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  DeclContext* decl();

  class  ConstDeclContext : public antlr4::ParserRuleContext {
  public:
    ConstDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BTypeContext *bType();
    std::vector<ConstDefContext *> constDef();
    ConstDefContext* constDef(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ConstDeclContext* constDecl();

  class  BTypeContext : public antlr4::ParserRuleContext {
  public:
    MetaDataType bMetaDataType;
    BTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BTypeContext* bType();

  class  ConstDefContext : public antlr4::ParserRuleContext {
  public:
    std::string symbolName;
    MetaDataType type;
    bool withType;
    std::vector<std::size_t> shape;
    bool isArray;
    IRValue* value;
    ConstDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Ident();
    std::vector<ConstExpContext *> constExp();
    ConstExpContext* constExp(size_t i);
    ConstInitValContext *constInitVal();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ConstDefContext* constDef();

  class  ConstInitValContext : public antlr4::ParserRuleContext {
  public:
    MetaDataType type;
    std::vector<std::size_t> shape;
    bool isArray;
    IRValue* value;
    ConstInitValContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ConstInitValContext() = default;
    void copyFrom(ConstInitValContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ConstInitValOfVarContext : public ConstInitValContext {
  public:
    ConstInitValOfVarContext(ConstInitValContext *ctx);

    ConstExpContext *constExp();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  ConstInitValOfArrayContext : public ConstInitValContext {
  public:
    ConstInitValOfArrayContext(ConstInitValContext *ctx);

    std::vector<ConstExpContext *> constExp();
    ConstExpContext* constExp(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  ConstInitValContext* constInitVal();

  class  VarDeclContext : public antlr4::ParserRuleContext {
  public:
    VarDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BTypeContext *bType();
    std::vector<VarDefContext *> varDef();
    VarDefContext* varDef(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  VarDeclContext* varDecl();

  class  VarDefContext : public antlr4::ParserRuleContext {
  public:
    std::string symbolName;
    MetaDataType type;
    bool withType;
    std::vector<std::size_t> shape;
    bool isArray;
    IRValue* value;
    VarDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Ident();
    std::vector<ConstExpContext *> constExp();
    ConstExpContext* constExp(size_t i);
    InitValContext *initVal();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  VarDefContext* varDef();

  class  InitValContext : public antlr4::ParserRuleContext {
  public:
    MetaDataType type;
    std::vector<std::size_t> shape;
    bool isArray;
    IRValue* value;
    InitValContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpContext *exp();
    std::vector<InitValContext *> initVal();
    InitValContext* initVal(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  InitValContext* initVal();

  class  FuncDefContext : public antlr4::ParserRuleContext {
  public:
    FuncDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FuncTypeContext *funcType();
    antlr4::tree::TerminalNode *Ident();
    FuncBlockContext *funcBlock();
    FuncFParamsContext *funcFParams();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FuncDefContext* funcDef();

  class  FuncTypeContext : public antlr4::ParserRuleContext {
  public:
    MetaDataType funcMetaDataType;
    FuncTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FuncTypeContext* funcType();

  class  FuncFParamsContext : public antlr4::ParserRuleContext {
  public:
    FuncFParamsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<FuncFParamContext *> funcFParam();
    FuncFParamContext* funcFParam(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FuncFParamsContext* funcFParams();

  class  FuncFParamContext : public antlr4::ParserRuleContext {
  public:
    IRSymbolVariable* symbolVar;
    bool isArray;
    MetaDataType paramType;
    FuncFParamContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BTypeContext *bType();
    antlr4::tree::TerminalNode *Ident();
    BracketsContext *brackets();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FuncFParamContext* funcFParam();

  class  BracketsContext : public antlr4::ParserRuleContext {
  public:
    BracketsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpContext *> exp();
    ExpContext* exp(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BracketsContext* brackets();

  class  FuncBlockContext : public antlr4::ParserRuleContext {
  public:
    bool hasReturn;
    MetaDataType returnType;
    bool docLVal;
    std::unordered_map<IROperand *, std::vector<IROperand *>> lValDoc;
    FuncBlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<FuncBlockItemContext *> funcBlockItem();
    FuncBlockItemContext* funcBlockItem(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FuncBlockContext* funcBlock();

  class  FuncBlockItemContext : public antlr4::ParserRuleContext {
  public:
    bool hasReturn;
    MetaDataType returnType;
    bool docLVal;
    std::unordered_map<IROperand *, std::vector<IROperand *>> lValDoc;
    FuncBlockItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DeclContext *decl();
    StmtContext *stmt();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FuncBlockItemContext* funcBlockItem();

  class  StmtContext : public antlr4::ParserRuleContext {
  public:
    bool hasReturn;
    MetaDataType returnType;
    std::vector<IRCode *> codes;
    IRLabel* beginArray;
    bool docLVal;
    std::unordered_map<IROperand *, std::vector<IROperand *>> lValDoc;
    StmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    StmtContext() = default;
    void copyFrom(StmtContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  StmtBlockContext : public StmtContext {
  public:
    StmtBlockContext(StmtContext *ctx);

    FuncBlockContext *funcBlock();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  StmtExpressionContext : public StmtContext {
  public:
    StmtExpressionContext(StmtContext *ctx);

    ExpContext *exp();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  StmtAssignmentContext : public StmtContext {
  public:
    StmtAssignmentContext(StmtContext *ctx);

    LValContext *lVal();
    ExpContext *exp();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  StmtCtrlSeqContext : public StmtContext {
  public:
    StmtCtrlSeqContext(StmtContext *ctx);

    CondContext *cond();
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);
    SubStmtContext *subStmt();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  StmtReturnContext : public StmtContext {
  public:
    StmtReturnContext(StmtContext *ctx);

    ExpContext *exp();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  StmtContext* stmt();

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    bool hasReturn;
    MetaDataType returnType;
    bool docLVal;
    std::unordered_map<IROperand *, std::vector<IROperand *>> lValDoc;
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<BlockItemContext *> blockItem();
    BlockItemContext* blockItem(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BlockContext* block();

  class  BlockItemContext : public antlr4::ParserRuleContext {
  public:
    bool hasReturn;
    MetaDataType returnType;
    bool docLVal;
    std::unordered_map<IROperand *, std::vector<IROperand *>> lValDoc;
    BlockItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DeclContext *decl();
    SubStmtContext *subStmt();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BlockItemContext* blockItem();

  class  SubStmtContext : public antlr4::ParserRuleContext {
  public:
    bool hasReturn;
    MetaDataType returnType;
    std::vector<IRCode *> codes;
    IRLabel* beginArray;
    bool docLVal;
    std::unordered_map<IROperand *, std::vector<IROperand *>> lValDoc;
    SubStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    SubStmtContext() = default;
    void copyFrom(SubStmtContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  SubStmtExpressionContext : public SubStmtContext {
  public:
    SubStmtExpressionContext(SubStmtContext *ctx);

    ExpContext *exp();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  SubStmtBlockContext : public SubStmtContext {
  public:
    SubStmtBlockContext(SubStmtContext *ctx);

    BlockContext *block();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  SubStmtAssignmentContext : public SubStmtContext {
  public:
    SubStmtAssignmentContext(SubStmtContext *ctx);

    LValContext *lVal();
    ExpContext *exp();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  SubStmtCtrlSeqContext : public SubStmtContext {
  public:
    SubStmtCtrlSeqContext(SubStmtContext *ctx);

    CondContext *cond();
    std::vector<SubStmtContext *> subStmt();
    SubStmtContext* subStmt(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  SubStmtReturnContext : public SubStmtContext {
  public:
    SubStmtReturnContext(SubStmtContext *ctx);

    ExpContext *exp();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  SubStmtContext* subStmt();

  class  ExpContext : public antlr4::ParserRuleContext {
  public:
    bool isArray;
    std::vector<std::size_t> shape;
    MetaDataType metaDataType;
    IROperand* operand;
    IROperand* indexOperand;
    ExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AddExpContext *addExp();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ExpContext* exp();

  class  CondContext : public antlr4::ParserRuleContext {
  public:
    IRLabel* falseLabel;
    CondContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LOrExpContext *lOrExp();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  CondContext* cond();

  class  LValContext : public antlr4::ParserRuleContext {
  public:
    bool isArray;
    std::vector<std::size_t> shape;
    SymbolType symbolType;
    MetaDataType lValMetaDataType;
    IRSymbolVariable* identOperand;
    IROperand* indexOperand;
    LValContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Ident();
    std::vector<ExpContext *> exp();
    ExpContext* exp(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  LValContext* lVal();

  class  PrimaryExpContext : public antlr4::ParserRuleContext {
  public:
    bool isArray;
    std::vector<std::size_t> shape;
    MetaDataType metaDataType;
    IROperand* operand;
    IROperand* indexOperand;
    PrimaryExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    PrimaryExpContext() = default;
    void copyFrom(PrimaryExpContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  PrimaryExpNestExpContext : public PrimaryExpContext {
  public:
    PrimaryExpNestExpContext(PrimaryExpContext *ctx);

    ExpContext *exp();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  PrimaryExpNumberContext : public PrimaryExpContext {
  public:
    PrimaryExpNumberContext(PrimaryExpContext *ctx);

    NumberContext *number();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  PrimaryExplValContext : public PrimaryExpContext {
  public:
    PrimaryExplValContext(PrimaryExpContext *ctx);

    LValContext *lVal();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  PrimaryExpContext* primaryExp();

  class  UnaryExpContext : public antlr4::ParserRuleContext {
  public:
    bool isArray;
    std::vector<std::size_t> shape;
    MetaDataType metaDataType;
    IROperand* operand;
    IROperand* indexOperand;
    UnaryExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    UnaryExpContext() = default;
    void copyFrom(UnaryExpContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  UnaryExpFuncContext : public UnaryExpContext {
  public:
    UnaryExpFuncContext(UnaryExpContext *ctx);

    antlr4::tree::TerminalNode *Ident();
    FuncRParamsContext *funcRParams();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  UnaryExpPrimaryExpContext : public UnaryExpContext {
  public:
    UnaryExpPrimaryExpContext(UnaryExpContext *ctx);

    PrimaryExpContext *primaryExp();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  UnaryExpNestUnaryExpContext : public UnaryExpContext {
  public:
    UnaryExpNestUnaryExpContext(UnaryExpContext *ctx);

    UnaryOpContext *unaryOp();
    UnaryExpContext *unaryExp();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  UnaryExpContext* unaryExp();

  class  UnaryOpContext : public antlr4::ParserRuleContext {
  public:
    UnaryOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  UnaryOpContext* unaryOp();

  class  FuncRParamsContext : public antlr4::ParserRuleContext {
  public:
    std::vector<bool> isArrayList;
    std::vector<std::vector<std::size_t>> shapeList;
    std::vector<MetaDataType> metaDataTypeList;
    std::vector<IROperand*> operandsList;
    FuncRParamsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpContext *> exp();
    ExpContext* exp(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FuncRParamsContext* funcRParams();

  class  MulExpContext : public antlr4::ParserRuleContext {
  public:
    bool isArray;
    std::vector<std::size_t> shape;
    MetaDataType metaDataType;
    IROperand* operand;
    IROperand* indexOperand;
    MulExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    MulExpContext() = default;
    void copyFrom(MulExpContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  MulExpMulExpContext : public MulExpContext {
  public:
    MulExpMulExpContext(MulExpContext *ctx);

    MulExpContext *mulExp();
    MulOpContext *mulOp();
    UnaryExpContext *unaryExp();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  MulExpUnaryExpContext : public MulExpContext {
  public:
    MulExpUnaryExpContext(MulExpContext *ctx);

    UnaryExpContext *unaryExp();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  MulExpContext* mulExp();
  MulExpContext* mulExp(int precedence);
  class  MulOpContext : public antlr4::ParserRuleContext {
  public:
    MulOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  MulOpContext* mulOp();

  class  AddExpContext : public antlr4::ParserRuleContext {
  public:
    bool isArray;
    std::vector<std::size_t> shape;
    MetaDataType metaDataType;
    IROperand* operand;
    IROperand* indexOperand;
    AddExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    AddExpContext() = default;
    void copyFrom(AddExpContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  AddExpAddExpContext : public AddExpContext {
  public:
    AddExpAddExpContext(AddExpContext *ctx);

    AddExpContext *addExp();
    AddOpContext *addOp();
    MulExpContext *mulExp();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  AddExpMulExpContext : public AddExpContext {
  public:
    AddExpMulExpContext(AddExpContext *ctx);

    MulExpContext *mulExp();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  AddExpContext* addExp();
  AddExpContext* addExp(int precedence);
  class  AddOpContext : public antlr4::ParserRuleContext {
  public:
    AddOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AddOpContext* addOp();

  class  RelExpContext : public antlr4::ParserRuleContext {
  public:
    MetaDataType metaDataType;
    IROperand* operand;
    RelExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    RelExpContext() = default;
    void copyFrom(RelExpContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  RelExpRelExpContext : public RelExpContext {
  public:
    RelExpRelExpContext(RelExpContext *ctx);

    RelExpContext *relExp();
    RelOpContext *relOp();
    AddExpContext *addExp();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  RelExpAddExpContext : public RelExpContext {
  public:
    RelExpAddExpContext(RelExpContext *ctx);

    AddExpContext *addExp();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  RelExpContext* relExp();
  RelExpContext* relExp(int precedence);
  class  RelOpContext : public antlr4::ParserRuleContext {
  public:
    RelOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  RelOpContext* relOp();

  class  EqExpContext : public antlr4::ParserRuleContext {
  public:
    MetaDataType metaDataType;
    IROperand* operand;
    EqExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    EqExpContext() = default;
    void copyFrom(EqExpContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  EqExpRelExpContext : public EqExpContext {
  public:
    EqExpRelExpContext(EqExpContext *ctx);

    RelExpContext *relExp();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  EqExpEqExpContext : public EqExpContext {
  public:
    EqExpEqExpContext(EqExpContext *ctx);

    EqExpContext *eqExp();
    EqOpContext *eqOp();
    RelExpContext *relExp();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  EqExpContext* eqExp();
  EqExpContext* eqExp(int precedence);
  class  EqOpContext : public antlr4::ParserRuleContext {
  public:
    EqOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  EqOpContext* eqOp();

  class  LAndExpContext : public antlr4::ParserRuleContext {
  public:
    MetaDataType metaDataType;
    IROperand* operand;
    LAndExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    LAndExpContext() = default;
    void copyFrom(LAndExpContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  LAndExpLAndExpContext : public LAndExpContext {
  public:
    LAndExpLAndExpContext(LAndExpContext *ctx);

    LAndExpContext *lAndExp();
    EqExpContext *eqExp();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  LAndExpEqExpContext : public LAndExpContext {
  public:
    LAndExpEqExpContext(LAndExpContext *ctx);

    EqExpContext *eqExp();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  LAndExpContext* lAndExp();
  LAndExpContext* lAndExp(int precedence);
  class  LOrExpContext : public antlr4::ParserRuleContext {
  public:
    MetaDataType metaDataType;
    IROperand* operand;
    LOrExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    LOrExpContext() = default;
    void copyFrom(LOrExpContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  LOrExpLAndExpContext : public LOrExpContext {
  public:
    LOrExpLAndExpContext(LOrExpContext *ctx);

    LAndExpContext *lAndExp();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  LOrExpLOrExpContext : public LOrExpContext {
  public:
    LOrExpLOrExpContext(LOrExpContext *ctx);

    LOrExpContext *lOrExp();
    LAndExpContext *lAndExp();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  LOrExpContext* lOrExp();
  LOrExpContext* lOrExp(int precedence);
  class  ConstExpContext : public antlr4::ParserRuleContext {
  public:
    MetaDataType metaDataType;
    std::string val;
    ConstExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ConstExpContext() = default;
    void copyFrom(ConstExpContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ConstExpNumberContext : public ConstExpContext {
  public:
    ConstExpNumberContext(ConstExpContext *ctx);

    NumberContext *number();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  ConstExpContext* constExp();

  class  NumberContext : public antlr4::ParserRuleContext {
  public:
    MetaDataType metaDataType;
    NumberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    NumberContext() = default;
    void copyFrom(NumberContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  NumberFloatConstContext : public NumberContext {
  public:
    NumberFloatConstContext(NumberContext *ctx);

    antlr4::tree::TerminalNode *FloatConst();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  NumberIntConstContext : public NumberContext {
  public:
    NumberIntConstContext(NumberContext *ctx);

    antlr4::tree::TerminalNode *IntConst();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  NumberContext* number();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool mulExpSempred(MulExpContext *_localctx, size_t predicateIndex);
  bool addExpSempred(AddExpContext *_localctx, size_t predicateIndex);
  bool relExpSempred(RelExpContext *_localctx, size_t predicateIndex);
  bool eqExpSempred(EqExpContext *_localctx, size_t predicateIndex);
  bool lAndExpSempred(LAndExpContext *_localctx, size_t predicateIndex);
  bool lOrExpSempred(LOrExpContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

