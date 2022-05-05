
    #include "../src/symbolTable.h"


// Generated from grammar/CACT.g4 by ANTLR 4.8


#include "CACTListener.h"

#include "CACTParser.h"


using namespace antlrcpp;
using namespace antlr4;

CACTParser::CACTParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

CACTParser::~CACTParser() {
  delete _interpreter;
}

std::string CACTParser::getGrammarFileName() const {
  return "CACT.g4";
}

const std::vector<std::string>& CACTParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& CACTParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- CompUnitContext ------------------------------------------------------------------

CACTParser::CompUnitContext::CompUnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CACTParser::CompUnitContext::EOF() {
  return getToken(CACTParser::EOF, 0);
}

std::vector<CACTParser::DeclContext *> CACTParser::CompUnitContext::decl() {
  return getRuleContexts<CACTParser::DeclContext>();
}

CACTParser::DeclContext* CACTParser::CompUnitContext::decl(size_t i) {
  return getRuleContext<CACTParser::DeclContext>(i);
}

std::vector<CACTParser::FuncDefContext *> CACTParser::CompUnitContext::funcDef() {
  return getRuleContexts<CACTParser::FuncDefContext>();
}

CACTParser::FuncDefContext* CACTParser::CompUnitContext::funcDef(size_t i) {
  return getRuleContext<CACTParser::FuncDefContext>(i);
}


size_t CACTParser::CompUnitContext::getRuleIndex() const {
  return CACTParser::RuleCompUnit;
}

void CACTParser::CompUnitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompUnit(this);
}

void CACTParser::CompUnitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompUnit(this);
}

CACTParser::CompUnitContext* CACTParser::compUnit() {
  CompUnitContext *_localctx = _tracker.createInstance<CompUnitContext>(_ctx, getState());
  enterRule(_localctx, 0, CACTParser::RuleCompUnit);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(68); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(68);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
      case 1: {
        setState(66);
        decl();
        break;
      }

      case 2: {
        setState(67);
        funcDef();
        break;
      }

      }
      setState(70); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CACTParser::T__0)
      | (1ULL << CACTParser::T__3)
      | (1ULL << CACTParser::T__4)
      | (1ULL << CACTParser::T__5)
      | (1ULL << CACTParser::T__6)
      | (1ULL << CACTParser::T__14))) != 0));
    setState(72);
    match(CACTParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclContext ------------------------------------------------------------------

CACTParser::DeclContext::DeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::ConstDeclContext* CACTParser::DeclContext::constDecl() {
  return getRuleContext<CACTParser::ConstDeclContext>(0);
}

CACTParser::VarDeclContext* CACTParser::DeclContext::varDecl() {
  return getRuleContext<CACTParser::VarDeclContext>(0);
}


size_t CACTParser::DeclContext::getRuleIndex() const {
  return CACTParser::RuleDecl;
}

void CACTParser::DeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDecl(this);
}

void CACTParser::DeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDecl(this);
}

CACTParser::DeclContext* CACTParser::decl() {
  DeclContext *_localctx = _tracker.createInstance<DeclContext>(_ctx, getState());
  enterRule(_localctx, 2, CACTParser::RuleDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(76);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::T__0: {
        enterOuterAlt(_localctx, 1);
        setState(74);
        constDecl();
        break;
      }

      case CACTParser::T__3:
      case CACTParser::T__4:
      case CACTParser::T__5:
      case CACTParser::T__6: {
        enterOuterAlt(_localctx, 2);
        setState(75);
        varDecl();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstDeclContext ------------------------------------------------------------------

CACTParser::ConstDeclContext::ConstDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::BTypeContext* CACTParser::ConstDeclContext::bType() {
  return getRuleContext<CACTParser::BTypeContext>(0);
}

std::vector<CACTParser::ConstDefContext *> CACTParser::ConstDeclContext::constDef() {
  return getRuleContexts<CACTParser::ConstDefContext>();
}

CACTParser::ConstDefContext* CACTParser::ConstDeclContext::constDef(size_t i) {
  return getRuleContext<CACTParser::ConstDefContext>(i);
}


size_t CACTParser::ConstDeclContext::getRuleIndex() const {
  return CACTParser::RuleConstDecl;
}

void CACTParser::ConstDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstDecl(this);
}

void CACTParser::ConstDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstDecl(this);
}

CACTParser::ConstDeclContext* CACTParser::constDecl() {
  ConstDeclContext *_localctx = _tracker.createInstance<ConstDeclContext>(_ctx, getState());
  enterRule(_localctx, 4, CACTParser::RuleConstDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(78);
    match(CACTParser::T__0);
    setState(79);
    bType();
    setState(80);
    constDef();
    setState(85);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CACTParser::T__1) {
      setState(81);
      match(CACTParser::T__1);
      setState(82);
      constDef();
      setState(87);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(88);
    match(CACTParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BTypeContext ------------------------------------------------------------------

CACTParser::BTypeContext::BTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::BTypeContext::getRuleIndex() const {
  return CACTParser::RuleBType;
}

void CACTParser::BTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBType(this);
}

void CACTParser::BTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBType(this);
}

CACTParser::BTypeContext* CACTParser::bType() {
  BTypeContext *_localctx = _tracker.createInstance<BTypeContext>(_ctx, getState());
  enterRule(_localctx, 6, CACTParser::RuleBType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(90);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CACTParser::T__3)
      | (1ULL << CACTParser::T__4)
      | (1ULL << CACTParser::T__5)
      | (1ULL << CACTParser::T__6))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstDefContext ------------------------------------------------------------------

CACTParser::ConstDefContext::ConstDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CACTParser::ConstDefContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

CACTParser::ConstInitValContext* CACTParser::ConstDefContext::constInitVal() {
  return getRuleContext<CACTParser::ConstInitValContext>(0);
}

tree::TerminalNode* CACTParser::ConstDefContext::IntConst() {
  return getToken(CACTParser::IntConst, 0);
}


size_t CACTParser::ConstDefContext::getRuleIndex() const {
  return CACTParser::RuleConstDef;
}

void CACTParser::ConstDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstDef(this);
}

void CACTParser::ConstDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstDef(this);
}

CACTParser::ConstDefContext* CACTParser::constDef() {
  ConstDefContext *_localctx = _tracker.createInstance<ConstDefContext>(_ctx, getState());
  enterRule(_localctx, 8, CACTParser::RuleConstDef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(92);
    match(CACTParser::Ident);
    setState(96);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CACTParser::T__7) {
      setState(93);
      match(CACTParser::T__7);
      setState(94);
      match(CACTParser::IntConst);
      setState(95);
      match(CACTParser::T__8);
    }
    setState(98);
    match(CACTParser::T__9);
    setState(99);
    constInitVal();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstInitValContext ------------------------------------------------------------------

CACTParser::ConstInitValContext::ConstInitValContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::ConstInitValContext::getRuleIndex() const {
  return CACTParser::RuleConstInitVal;
}

void CACTParser::ConstInitValContext::copyFrom(ConstInitValContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->type = ctx->type;
  this->size = ctx->size;
  this->isArray = ctx->isArray;
}

//----------------- ConstInitValOfVarContext ------------------------------------------------------------------

CACTParser::ConstExpContext* CACTParser::ConstInitValOfVarContext::constExp() {
  return getRuleContext<CACTParser::ConstExpContext>(0);
}

CACTParser::ConstInitValOfVarContext::ConstInitValOfVarContext(ConstInitValContext *ctx) { copyFrom(ctx); }

void CACTParser::ConstInitValOfVarContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstInitValOfVar(this);
}
void CACTParser::ConstInitValOfVarContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstInitValOfVar(this);
}
//----------------- ConstInitValOfArrayContext ------------------------------------------------------------------

std::vector<CACTParser::ConstExpContext *> CACTParser::ConstInitValOfArrayContext::constExp() {
  return getRuleContexts<CACTParser::ConstExpContext>();
}

CACTParser::ConstExpContext* CACTParser::ConstInitValOfArrayContext::constExp(size_t i) {
  return getRuleContext<CACTParser::ConstExpContext>(i);
}

CACTParser::ConstInitValOfArrayContext::ConstInitValOfArrayContext(ConstInitValContext *ctx) { copyFrom(ctx); }

void CACTParser::ConstInitValOfArrayContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstInitValOfArray(this);
}
void CACTParser::ConstInitValOfArrayContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstInitValOfArray(this);
}
CACTParser::ConstInitValContext* CACTParser::constInitVal() {
  ConstInitValContext *_localctx = _tracker.createInstance<ConstInitValContext>(_ctx, getState());
  enterRule(_localctx, 10, CACTParser::RuleConstInitVal);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(116);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::T__1:
      case CACTParser::T__2:
      case CACTParser::BoolConst:
      case CACTParser::IntConst:
      case CACTParser::FloatConst:
      case CACTParser::DoubleConst: {
        _localctx = dynamic_cast<ConstInitValContext *>(_tracker.createInstance<CACTParser::ConstInitValOfVarContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(102);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << CACTParser::BoolConst)
          | (1ULL << CACTParser::IntConst)
          | (1ULL << CACTParser::FloatConst)
          | (1ULL << CACTParser::DoubleConst))) != 0)) {
          setState(101);
          constExp();
        }
        break;
      }

      case CACTParser::T__10: {
        _localctx = dynamic_cast<ConstInitValContext *>(_tracker.createInstance<CACTParser::ConstInitValOfArrayContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(104);
        match(CACTParser::T__10);
        setState(113);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << CACTParser::BoolConst)
          | (1ULL << CACTParser::IntConst)
          | (1ULL << CACTParser::FloatConst)
          | (1ULL << CACTParser::DoubleConst))) != 0)) {
          setState(105);
          constExp();
          setState(110);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == CACTParser::T__1) {
            setState(106);
            match(CACTParser::T__1);
            setState(107);
            constExp();
            setState(112);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
        }
        setState(115);
        match(CACTParser::T__11);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDeclContext ------------------------------------------------------------------

CACTParser::VarDeclContext::VarDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::BTypeContext* CACTParser::VarDeclContext::bType() {
  return getRuleContext<CACTParser::BTypeContext>(0);
}

std::vector<CACTParser::VarDefContext *> CACTParser::VarDeclContext::varDef() {
  return getRuleContexts<CACTParser::VarDefContext>();
}

CACTParser::VarDefContext* CACTParser::VarDeclContext::varDef(size_t i) {
  return getRuleContext<CACTParser::VarDefContext>(i);
}


size_t CACTParser::VarDeclContext::getRuleIndex() const {
  return CACTParser::RuleVarDecl;
}

void CACTParser::VarDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDecl(this);
}

void CACTParser::VarDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDecl(this);
}

CACTParser::VarDeclContext* CACTParser::varDecl() {
  VarDeclContext *_localctx = _tracker.createInstance<VarDeclContext>(_ctx, getState());
  enterRule(_localctx, 12, CACTParser::RuleVarDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(118);
    bType();
    setState(119);
    varDef();
    setState(124);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CACTParser::T__1) {
      setState(120);
      match(CACTParser::T__1);
      setState(121);
      varDef();
      setState(126);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(127);
    match(CACTParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDefContext ------------------------------------------------------------------

CACTParser::VarDefContext::VarDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CACTParser::VarDefContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

tree::TerminalNode* CACTParser::VarDefContext::IntConst() {
  return getToken(CACTParser::IntConst, 0);
}

CACTParser::ConstInitValContext* CACTParser::VarDefContext::constInitVal() {
  return getRuleContext<CACTParser::ConstInitValContext>(0);
}


size_t CACTParser::VarDefContext::getRuleIndex() const {
  return CACTParser::RuleVarDef;
}

void CACTParser::VarDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDef(this);
}

void CACTParser::VarDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDef(this);
}

CACTParser::VarDefContext* CACTParser::varDef() {
  VarDefContext *_localctx = _tracker.createInstance<VarDefContext>(_ctx, getState());
  enterRule(_localctx, 14, CACTParser::RuleVarDef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(129);
    match(CACTParser::Ident);
    setState(133);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CACTParser::T__7) {
      setState(130);
      match(CACTParser::T__7);
      setState(131);
      match(CACTParser::IntConst);
      setState(132);
      match(CACTParser::T__8);
    }
    setState(137);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CACTParser::T__9) {
      setState(135);
      match(CACTParser::T__9);
      setState(136);
      constInitVal();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncDefContext ------------------------------------------------------------------

CACTParser::FuncDefContext::FuncDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::FuncTypeContext* CACTParser::FuncDefContext::funcType() {
  return getRuleContext<CACTParser::FuncTypeContext>(0);
}

tree::TerminalNode* CACTParser::FuncDefContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

CACTParser::BlockContext* CACTParser::FuncDefContext::block() {
  return getRuleContext<CACTParser::BlockContext>(0);
}

CACTParser::FuncFParamsContext* CACTParser::FuncDefContext::funcFParams() {
  return getRuleContext<CACTParser::FuncFParamsContext>(0);
}


size_t CACTParser::FuncDefContext::getRuleIndex() const {
  return CACTParser::RuleFuncDef;
}

void CACTParser::FuncDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncDef(this);
}

void CACTParser::FuncDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncDef(this);
}

CACTParser::FuncDefContext* CACTParser::funcDef() {
  FuncDefContext *_localctx = _tracker.createInstance<FuncDefContext>(_ctx, getState());
  enterRule(_localctx, 16, CACTParser::RuleFuncDef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(139);
    funcType();
    setState(140);
    match(CACTParser::Ident);
    setState(141);
    match(CACTParser::T__12);
    setState(143);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CACTParser::T__3)
      | (1ULL << CACTParser::T__4)
      | (1ULL << CACTParser::T__5)
      | (1ULL << CACTParser::T__6))) != 0)) {
      setState(142);
      funcFParams();
    }
    setState(145);
    match(CACTParser::T__13);
    setState(146);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncTypeContext ------------------------------------------------------------------

CACTParser::FuncTypeContext::FuncTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::FuncTypeContext::getRuleIndex() const {
  return CACTParser::RuleFuncType;
}

void CACTParser::FuncTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncType(this);
}

void CACTParser::FuncTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncType(this);
}

CACTParser::FuncTypeContext* CACTParser::funcType() {
  FuncTypeContext *_localctx = _tracker.createInstance<FuncTypeContext>(_ctx, getState());
  enterRule(_localctx, 18, CACTParser::RuleFuncType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(148);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CACTParser::T__3)
      | (1ULL << CACTParser::T__4)
      | (1ULL << CACTParser::T__5)
      | (1ULL << CACTParser::T__6)
      | (1ULL << CACTParser::T__14))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncFParamsContext ------------------------------------------------------------------

CACTParser::FuncFParamsContext::FuncFParamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CACTParser::FuncFParamContext *> CACTParser::FuncFParamsContext::funcFParam() {
  return getRuleContexts<CACTParser::FuncFParamContext>();
}

CACTParser::FuncFParamContext* CACTParser::FuncFParamsContext::funcFParam(size_t i) {
  return getRuleContext<CACTParser::FuncFParamContext>(i);
}


size_t CACTParser::FuncFParamsContext::getRuleIndex() const {
  return CACTParser::RuleFuncFParams;
}

void CACTParser::FuncFParamsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncFParams(this);
}

void CACTParser::FuncFParamsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncFParams(this);
}

CACTParser::FuncFParamsContext* CACTParser::funcFParams() {
  FuncFParamsContext *_localctx = _tracker.createInstance<FuncFParamsContext>(_ctx, getState());
  enterRule(_localctx, 20, CACTParser::RuleFuncFParams);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(150);
    funcFParam();
    setState(155);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CACTParser::T__1) {
      setState(151);
      match(CACTParser::T__1);
      setState(152);
      funcFParam();
      setState(157);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncFParamContext ------------------------------------------------------------------

CACTParser::FuncFParamContext::FuncFParamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::BTypeContext* CACTParser::FuncFParamContext::bType() {
  return getRuleContext<CACTParser::BTypeContext>(0);
}

tree::TerminalNode* CACTParser::FuncFParamContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

CACTParser::BracketsContext* CACTParser::FuncFParamContext::brackets() {
  return getRuleContext<CACTParser::BracketsContext>(0);
}


size_t CACTParser::FuncFParamContext::getRuleIndex() const {
  return CACTParser::RuleFuncFParam;
}

void CACTParser::FuncFParamContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncFParam(this);
}

void CACTParser::FuncFParamContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncFParam(this);
}

CACTParser::FuncFParamContext* CACTParser::funcFParam() {
  FuncFParamContext *_localctx = _tracker.createInstance<FuncFParamContext>(_ctx, getState());
  enterRule(_localctx, 22, CACTParser::RuleFuncFParam);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(158);
    bType();
    setState(159);
    match(CACTParser::Ident);
    setState(161);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CACTParser::T__7) {
      setState(160);
      brackets();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BracketsContext ------------------------------------------------------------------

CACTParser::BracketsContext::BracketsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::BracketsContext::getRuleIndex() const {
  return CACTParser::RuleBrackets;
}

void CACTParser::BracketsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBrackets(this);
}

void CACTParser::BracketsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBrackets(this);
}

CACTParser::BracketsContext* CACTParser::brackets() {
  BracketsContext *_localctx = _tracker.createInstance<BracketsContext>(_ctx, getState());
  enterRule(_localctx, 24, CACTParser::RuleBrackets);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(163);
    match(CACTParser::T__7);
    setState(164);
    match(CACTParser::T__8);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

CACTParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CACTParser::BlockItemContext *> CACTParser::BlockContext::blockItem() {
  return getRuleContexts<CACTParser::BlockItemContext>();
}

CACTParser::BlockItemContext* CACTParser::BlockContext::blockItem(size_t i) {
  return getRuleContext<CACTParser::BlockItemContext>(i);
}


size_t CACTParser::BlockContext::getRuleIndex() const {
  return CACTParser::RuleBlock;
}

void CACTParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void CACTParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}

CACTParser::BlockContext* CACTParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 26, CACTParser::RuleBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(166);
    match(CACTParser::T__10);
    setState(170);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CACTParser::T__0)
      | (1ULL << CACTParser::T__2)
      | (1ULL << CACTParser::T__3)
      | (1ULL << CACTParser::T__4)
      | (1ULL << CACTParser::T__5)
      | (1ULL << CACTParser::T__6)
      | (1ULL << CACTParser::T__10)
      | (1ULL << CACTParser::T__12)
      | (1ULL << CACTParser::T__15)
      | (1ULL << CACTParser::T__17)
      | (1ULL << CACTParser::T__18)
      | (1ULL << CACTParser::T__21)
      | (1ULL << CACTParser::T__22)
      | (1ULL << CACTParser::T__23)
      | (1ULL << CACTParser::BoolConst)
      | (1ULL << CACTParser::Ident)
      | (1ULL << CACTParser::IntConst)
      | (1ULL << CACTParser::FloatConst)
      | (1ULL << CACTParser::DoubleConst))) != 0)) {
      setState(167);
      blockItem();
      setState(172);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(173);
    match(CACTParser::T__11);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockItemContext ------------------------------------------------------------------

CACTParser::BlockItemContext::BlockItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::DeclContext* CACTParser::BlockItemContext::decl() {
  return getRuleContext<CACTParser::DeclContext>(0);
}

CACTParser::StmtContext* CACTParser::BlockItemContext::stmt() {
  return getRuleContext<CACTParser::StmtContext>(0);
}


size_t CACTParser::BlockItemContext::getRuleIndex() const {
  return CACTParser::RuleBlockItem;
}

void CACTParser::BlockItemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlockItem(this);
}

void CACTParser::BlockItemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlockItem(this);
}

CACTParser::BlockItemContext* CACTParser::blockItem() {
  BlockItemContext *_localctx = _tracker.createInstance<BlockItemContext>(_ctx, getState());
  enterRule(_localctx, 28, CACTParser::RuleBlockItem);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(177);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::T__0:
      case CACTParser::T__3:
      case CACTParser::T__4:
      case CACTParser::T__5:
      case CACTParser::T__6: {
        enterOuterAlt(_localctx, 1);
        setState(175);
        decl();
        break;
      }

      case CACTParser::T__2:
      case CACTParser::T__10:
      case CACTParser::T__12:
      case CACTParser::T__15:
      case CACTParser::T__17:
      case CACTParser::T__18:
      case CACTParser::T__21:
      case CACTParser::T__22:
      case CACTParser::T__23:
      case CACTParser::BoolConst:
      case CACTParser::Ident:
      case CACTParser::IntConst:
      case CACTParser::FloatConst:
      case CACTParser::DoubleConst: {
        enterOuterAlt(_localctx, 2);
        setState(176);
        stmt();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

CACTParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::StmtContext::getRuleIndex() const {
  return CACTParser::RuleStmt;
}

void CACTParser::StmtContext::copyFrom(StmtContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->hasReturn = ctx->hasReturn;
  this->returnType = ctx->returnType;
}

//----------------- StmtBlockContext ------------------------------------------------------------------

CACTParser::BlockContext* CACTParser::StmtBlockContext::block() {
  return getRuleContext<CACTParser::BlockContext>(0);
}

CACTParser::StmtBlockContext::StmtBlockContext(StmtContext *ctx) { copyFrom(ctx); }

void CACTParser::StmtBlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmtBlock(this);
}
void CACTParser::StmtBlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmtBlock(this);
}
//----------------- StmtExpressionContext ------------------------------------------------------------------

CACTParser::ExpContext* CACTParser::StmtExpressionContext::exp() {
  return getRuleContext<CACTParser::ExpContext>(0);
}

CACTParser::StmtExpressionContext::StmtExpressionContext(StmtContext *ctx) { copyFrom(ctx); }

void CACTParser::StmtExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmtExpression(this);
}
void CACTParser::StmtExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmtExpression(this);
}
//----------------- StmtAssignmentContext ------------------------------------------------------------------

CACTParser::LValContext* CACTParser::StmtAssignmentContext::lVal() {
  return getRuleContext<CACTParser::LValContext>(0);
}

CACTParser::ExpContext* CACTParser::StmtAssignmentContext::exp() {
  return getRuleContext<CACTParser::ExpContext>(0);
}

CACTParser::StmtAssignmentContext::StmtAssignmentContext(StmtContext *ctx) { copyFrom(ctx); }

void CACTParser::StmtAssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmtAssignment(this);
}
void CACTParser::StmtAssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmtAssignment(this);
}
//----------------- StmtCtrlSeqContext ------------------------------------------------------------------

CACTParser::CondContext* CACTParser::StmtCtrlSeqContext::cond() {
  return getRuleContext<CACTParser::CondContext>(0);
}

std::vector<CACTParser::StmtContext *> CACTParser::StmtCtrlSeqContext::stmt() {
  return getRuleContexts<CACTParser::StmtContext>();
}

CACTParser::StmtContext* CACTParser::StmtCtrlSeqContext::stmt(size_t i) {
  return getRuleContext<CACTParser::StmtContext>(i);
}

CACTParser::SubStmtContext* CACTParser::StmtCtrlSeqContext::subStmt() {
  return getRuleContext<CACTParser::SubStmtContext>(0);
}

CACTParser::StmtCtrlSeqContext::StmtCtrlSeqContext(StmtContext *ctx) { copyFrom(ctx); }

void CACTParser::StmtCtrlSeqContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmtCtrlSeq(this);
}
void CACTParser::StmtCtrlSeqContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmtCtrlSeq(this);
}
//----------------- StmtReturnContext ------------------------------------------------------------------

CACTParser::ExpContext* CACTParser::StmtReturnContext::exp() {
  return getRuleContext<CACTParser::ExpContext>(0);
}

CACTParser::StmtReturnContext::StmtReturnContext(StmtContext *ctx) { copyFrom(ctx); }

void CACTParser::StmtReturnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmtReturn(this);
}
void CACTParser::StmtReturnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmtReturn(this);
}
CACTParser::StmtContext* CACTParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 30, CACTParser::RuleStmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(209);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<CACTParser::StmtAssignmentContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(179);
      lVal();
      setState(180);
      match(CACTParser::T__9);
      setState(181);
      exp();
      setState(182);
      match(CACTParser::T__2);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<CACTParser::StmtExpressionContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(185);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CACTParser::T__12)
        | (1ULL << CACTParser::T__21)
        | (1ULL << CACTParser::T__22)
        | (1ULL << CACTParser::T__23)
        | (1ULL << CACTParser::BoolConst)
        | (1ULL << CACTParser::Ident)
        | (1ULL << CACTParser::IntConst)
        | (1ULL << CACTParser::FloatConst)
        | (1ULL << CACTParser::DoubleConst))) != 0)) {
        setState(184);
        exp();
      }
      setState(187);
      match(CACTParser::T__2);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<CACTParser::StmtBlockContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(188);
      block();
      break;
    }

    case 4: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<CACTParser::StmtCtrlSeqContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(189);
      match(CACTParser::T__15);
      setState(190);
      match(CACTParser::T__12);
      setState(191);
      cond();
      setState(192);
      match(CACTParser::T__13);
      setState(193);
      stmt();
      setState(196);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
      case 1: {
        setState(194);
        match(CACTParser::T__16);
        setState(195);
        stmt();
        break;
      }

      }
      break;
    }

    case 5: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<CACTParser::StmtCtrlSeqContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(198);
      match(CACTParser::T__17);
      setState(199);
      match(CACTParser::T__12);
      setState(200);
      cond();
      setState(201);
      match(CACTParser::T__13);
      setState(202);
      subStmt();
      break;
    }

    case 6: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<CACTParser::StmtReturnContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(204);
      match(CACTParser::T__18);
      setState(206);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CACTParser::T__12)
        | (1ULL << CACTParser::T__21)
        | (1ULL << CACTParser::T__22)
        | (1ULL << CACTParser::T__23)
        | (1ULL << CACTParser::BoolConst)
        | (1ULL << CACTParser::Ident)
        | (1ULL << CACTParser::IntConst)
        | (1ULL << CACTParser::FloatConst)
        | (1ULL << CACTParser::DoubleConst))) != 0)) {
        setState(205);
        exp();
      }
      setState(208);
      match(CACTParser::T__2);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SubStmtContext ------------------------------------------------------------------

CACTParser::SubStmtContext::SubStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::SubStmtContext::getRuleIndex() const {
  return CACTParser::RuleSubStmt;
}

void CACTParser::SubStmtContext::copyFrom(SubStmtContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->hasReturn = ctx->hasReturn;
  this->returnType = ctx->returnType;
}

//----------------- SubStmtExpressionContext ------------------------------------------------------------------

CACTParser::ExpContext* CACTParser::SubStmtExpressionContext::exp() {
  return getRuleContext<CACTParser::ExpContext>(0);
}

CACTParser::SubStmtExpressionContext::SubStmtExpressionContext(SubStmtContext *ctx) { copyFrom(ctx); }

void CACTParser::SubStmtExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubStmtExpression(this);
}
void CACTParser::SubStmtExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubStmtExpression(this);
}
//----------------- SubStmtBlockContext ------------------------------------------------------------------

CACTParser::BlockContext* CACTParser::SubStmtBlockContext::block() {
  return getRuleContext<CACTParser::BlockContext>(0);
}

CACTParser::SubStmtBlockContext::SubStmtBlockContext(SubStmtContext *ctx) { copyFrom(ctx); }

void CACTParser::SubStmtBlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubStmtBlock(this);
}
void CACTParser::SubStmtBlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubStmtBlock(this);
}
//----------------- SubStmtAssignmentContext ------------------------------------------------------------------

CACTParser::LValContext* CACTParser::SubStmtAssignmentContext::lVal() {
  return getRuleContext<CACTParser::LValContext>(0);
}

CACTParser::ExpContext* CACTParser::SubStmtAssignmentContext::exp() {
  return getRuleContext<CACTParser::ExpContext>(0);
}

CACTParser::SubStmtAssignmentContext::SubStmtAssignmentContext(SubStmtContext *ctx) { copyFrom(ctx); }

void CACTParser::SubStmtAssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubStmtAssignment(this);
}
void CACTParser::SubStmtAssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubStmtAssignment(this);
}
//----------------- SubStmtCtrlSeqContext ------------------------------------------------------------------

CACTParser::CondContext* CACTParser::SubStmtCtrlSeqContext::cond() {
  return getRuleContext<CACTParser::CondContext>(0);
}

std::vector<CACTParser::SubStmtContext *> CACTParser::SubStmtCtrlSeqContext::subStmt() {
  return getRuleContexts<CACTParser::SubStmtContext>();
}

CACTParser::SubStmtContext* CACTParser::SubStmtCtrlSeqContext::subStmt(size_t i) {
  return getRuleContext<CACTParser::SubStmtContext>(i);
}

CACTParser::SubStmtCtrlSeqContext::SubStmtCtrlSeqContext(SubStmtContext *ctx) { copyFrom(ctx); }

void CACTParser::SubStmtCtrlSeqContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubStmtCtrlSeq(this);
}
void CACTParser::SubStmtCtrlSeqContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubStmtCtrlSeq(this);
}
//----------------- SubStmtReturnContext ------------------------------------------------------------------

CACTParser::ExpContext* CACTParser::SubStmtReturnContext::exp() {
  return getRuleContext<CACTParser::ExpContext>(0);
}

CACTParser::SubStmtReturnContext::SubStmtReturnContext(SubStmtContext *ctx) { copyFrom(ctx); }

void CACTParser::SubStmtReturnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubStmtReturn(this);
}
void CACTParser::SubStmtReturnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubStmtReturn(this);
}
CACTParser::SubStmtContext* CACTParser::subStmt() {
  SubStmtContext *_localctx = _tracker.createInstance<SubStmtContext>(_ctx, getState());
  enterRule(_localctx, 32, CACTParser::RuleSubStmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(245);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<SubStmtContext *>(_tracker.createInstance<CACTParser::SubStmtAssignmentContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(211);
      lVal();
      setState(212);
      match(CACTParser::T__9);
      setState(213);
      exp();
      setState(214);
      match(CACTParser::T__2);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<SubStmtContext *>(_tracker.createInstance<CACTParser::SubStmtExpressionContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(217);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CACTParser::T__12)
        | (1ULL << CACTParser::T__21)
        | (1ULL << CACTParser::T__22)
        | (1ULL << CACTParser::T__23)
        | (1ULL << CACTParser::BoolConst)
        | (1ULL << CACTParser::Ident)
        | (1ULL << CACTParser::IntConst)
        | (1ULL << CACTParser::FloatConst)
        | (1ULL << CACTParser::DoubleConst))) != 0)) {
        setState(216);
        exp();
      }
      setState(219);
      match(CACTParser::T__2);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<SubStmtContext *>(_tracker.createInstance<CACTParser::SubStmtBlockContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(220);
      block();
      break;
    }

    case 4: {
      _localctx = dynamic_cast<SubStmtContext *>(_tracker.createInstance<CACTParser::SubStmtCtrlSeqContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(221);
      match(CACTParser::T__15);
      setState(222);
      match(CACTParser::T__12);
      setState(223);
      cond();
      setState(224);
      match(CACTParser::T__13);
      setState(225);
      subStmt();
      setState(228);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
      case 1: {
        setState(226);
        match(CACTParser::T__16);
        setState(227);
        subStmt();
        break;
      }

      }
      break;
    }

    case 5: {
      _localctx = dynamic_cast<SubStmtContext *>(_tracker.createInstance<CACTParser::SubStmtCtrlSeqContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(230);
      match(CACTParser::T__17);
      setState(231);
      match(CACTParser::T__12);
      setState(232);
      cond();
      setState(233);
      match(CACTParser::T__13);
      setState(234);
      subStmt();
      break;
    }

    case 6: {
      _localctx = dynamic_cast<SubStmtContext *>(_tracker.createInstance<CACTParser::SubStmtCtrlSeqContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(236);
      match(CACTParser::T__19);
      setState(237);
      match(CACTParser::T__2);
      break;
    }

    case 7: {
      _localctx = dynamic_cast<SubStmtContext *>(_tracker.createInstance<CACTParser::SubStmtCtrlSeqContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(238);
      match(CACTParser::T__20);
      setState(239);
      match(CACTParser::T__2);
      break;
    }

    case 8: {
      _localctx = dynamic_cast<SubStmtContext *>(_tracker.createInstance<CACTParser::SubStmtReturnContext>(_localctx));
      enterOuterAlt(_localctx, 8);
      setState(240);
      match(CACTParser::T__18);
      setState(242);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CACTParser::T__12)
        | (1ULL << CACTParser::T__21)
        | (1ULL << CACTParser::T__22)
        | (1ULL << CACTParser::T__23)
        | (1ULL << CACTParser::BoolConst)
        | (1ULL << CACTParser::Ident)
        | (1ULL << CACTParser::IntConst)
        | (1ULL << CACTParser::FloatConst)
        | (1ULL << CACTParser::DoubleConst))) != 0)) {
        setState(241);
        exp();
      }
      setState(244);
      match(CACTParser::T__2);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpContext ------------------------------------------------------------------

CACTParser::ExpContext::ExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::ExpContext::getRuleIndex() const {
  return CACTParser::RuleExp;
}

void CACTParser::ExpContext::copyFrom(ExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->isArray = ctx->isArray;
  this->size = ctx->size;
  this->metaDataType = ctx->metaDataType;
}

//----------------- ExpBoolExpContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::ExpBoolExpContext::BoolConst() {
  return getToken(CACTParser::BoolConst, 0);
}

CACTParser::ExpBoolExpContext::ExpBoolExpContext(ExpContext *ctx) { copyFrom(ctx); }

void CACTParser::ExpBoolExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpBoolExp(this);
}
void CACTParser::ExpBoolExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpBoolExp(this);
}
//----------------- ExpAddExpContext ------------------------------------------------------------------

CACTParser::AddExpContext* CACTParser::ExpAddExpContext::addExp() {
  return getRuleContext<CACTParser::AddExpContext>(0);
}

CACTParser::ExpAddExpContext::ExpAddExpContext(ExpContext *ctx) { copyFrom(ctx); }

void CACTParser::ExpAddExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpAddExp(this);
}
void CACTParser::ExpAddExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpAddExp(this);
}
CACTParser::ExpContext* CACTParser::exp() {
  ExpContext *_localctx = _tracker.createInstance<ExpContext>(_ctx, getState());
  enterRule(_localctx, 34, CACTParser::RuleExp);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(249);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::T__12:
      case CACTParser::T__21:
      case CACTParser::T__22:
      case CACTParser::T__23:
      case CACTParser::Ident:
      case CACTParser::IntConst:
      case CACTParser::FloatConst:
      case CACTParser::DoubleConst: {
        _localctx = dynamic_cast<ExpContext *>(_tracker.createInstance<CACTParser::ExpAddExpContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(247);
        addExp(0);
        break;
      }

      case CACTParser::BoolConst: {
        _localctx = dynamic_cast<ExpContext *>(_tracker.createInstance<CACTParser::ExpBoolExpContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(248);
        match(CACTParser::BoolConst);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CondContext ------------------------------------------------------------------

CACTParser::CondContext::CondContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::LOrExpContext* CACTParser::CondContext::lOrExp() {
  return getRuleContext<CACTParser::LOrExpContext>(0);
}


size_t CACTParser::CondContext::getRuleIndex() const {
  return CACTParser::RuleCond;
}

void CACTParser::CondContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCond(this);
}

void CACTParser::CondContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCond(this);
}

CACTParser::CondContext* CACTParser::cond() {
  CondContext *_localctx = _tracker.createInstance<CondContext>(_ctx, getState());
  enterRule(_localctx, 36, CACTParser::RuleCond);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(251);
    lOrExp(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LValContext ------------------------------------------------------------------

CACTParser::LValContext::LValContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CACTParser::LValContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

CACTParser::ExpContext* CACTParser::LValContext::exp() {
  return getRuleContext<CACTParser::ExpContext>(0);
}


size_t CACTParser::LValContext::getRuleIndex() const {
  return CACTParser::RuleLVal;
}

void CACTParser::LValContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLVal(this);
}

void CACTParser::LValContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLVal(this);
}

CACTParser::LValContext* CACTParser::lVal() {
  LValContext *_localctx = _tracker.createInstance<LValContext>(_ctx, getState());
  enterRule(_localctx, 38, CACTParser::RuleLVal);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(253);
    match(CACTParser::Ident);
    setState(258);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx)) {
    case 1: {
      setState(254);
      match(CACTParser::T__7);
      setState(255);
      exp();
      setState(256);
      match(CACTParser::T__8);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrimaryExpContext ------------------------------------------------------------------

CACTParser::PrimaryExpContext::PrimaryExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::PrimaryExpContext::getRuleIndex() const {
  return CACTParser::RulePrimaryExp;
}

void CACTParser::PrimaryExpContext::copyFrom(PrimaryExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->isArray = ctx->isArray;
  this->size = ctx->size;
  this->metaDataType = ctx->metaDataType;
}

//----------------- PrimaryExpNestExpContext ------------------------------------------------------------------

CACTParser::ExpContext* CACTParser::PrimaryExpNestExpContext::exp() {
  return getRuleContext<CACTParser::ExpContext>(0);
}

CACTParser::PrimaryExpNestExpContext::PrimaryExpNestExpContext(PrimaryExpContext *ctx) { copyFrom(ctx); }

void CACTParser::PrimaryExpNestExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimaryExpNestExp(this);
}
void CACTParser::PrimaryExpNestExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimaryExpNestExp(this);
}
//----------------- PrimaryExpNumberContext ------------------------------------------------------------------

CACTParser::NumberContext* CACTParser::PrimaryExpNumberContext::number() {
  return getRuleContext<CACTParser::NumberContext>(0);
}

CACTParser::PrimaryExpNumberContext::PrimaryExpNumberContext(PrimaryExpContext *ctx) { copyFrom(ctx); }

void CACTParser::PrimaryExpNumberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimaryExpNumber(this);
}
void CACTParser::PrimaryExpNumberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimaryExpNumber(this);
}
//----------------- PrimaryExplValContext ------------------------------------------------------------------

CACTParser::LValContext* CACTParser::PrimaryExplValContext::lVal() {
  return getRuleContext<CACTParser::LValContext>(0);
}

CACTParser::PrimaryExplValContext::PrimaryExplValContext(PrimaryExpContext *ctx) { copyFrom(ctx); }

void CACTParser::PrimaryExplValContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimaryExplVal(this);
}
void CACTParser::PrimaryExplValContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimaryExplVal(this);
}
CACTParser::PrimaryExpContext* CACTParser::primaryExp() {
  PrimaryExpContext *_localctx = _tracker.createInstance<PrimaryExpContext>(_ctx, getState());
  enterRule(_localctx, 40, CACTParser::RulePrimaryExp);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(266);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::T__12: {
        _localctx = dynamic_cast<PrimaryExpContext *>(_tracker.createInstance<CACTParser::PrimaryExpNestExpContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(260);
        match(CACTParser::T__12);
        setState(261);
        exp();
        setState(262);
        match(CACTParser::T__13);
        break;
      }

      case CACTParser::Ident: {
        _localctx = dynamic_cast<PrimaryExpContext *>(_tracker.createInstance<CACTParser::PrimaryExplValContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(264);
        lVal();
        break;
      }

      case CACTParser::IntConst:
      case CACTParser::FloatConst:
      case CACTParser::DoubleConst: {
        _localctx = dynamic_cast<PrimaryExpContext *>(_tracker.createInstance<CACTParser::PrimaryExpNumberContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(265);
        number();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnaryExpContext ------------------------------------------------------------------

CACTParser::UnaryExpContext::UnaryExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::UnaryExpContext::getRuleIndex() const {
  return CACTParser::RuleUnaryExp;
}

void CACTParser::UnaryExpContext::copyFrom(UnaryExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->isArray = ctx->isArray;
  this->size = ctx->size;
  this->metaDataType = ctx->metaDataType;
}

//----------------- UnaryExpFuncContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::UnaryExpFuncContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

CACTParser::FuncRParamsContext* CACTParser::UnaryExpFuncContext::funcRParams() {
  return getRuleContext<CACTParser::FuncRParamsContext>(0);
}

CACTParser::UnaryExpFuncContext::UnaryExpFuncContext(UnaryExpContext *ctx) { copyFrom(ctx); }

void CACTParser::UnaryExpFuncContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryExpFunc(this);
}
void CACTParser::UnaryExpFuncContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryExpFunc(this);
}
//----------------- UnaryExpPrimaryExpContext ------------------------------------------------------------------

CACTParser::PrimaryExpContext* CACTParser::UnaryExpPrimaryExpContext::primaryExp() {
  return getRuleContext<CACTParser::PrimaryExpContext>(0);
}

CACTParser::UnaryExpPrimaryExpContext::UnaryExpPrimaryExpContext(UnaryExpContext *ctx) { copyFrom(ctx); }

void CACTParser::UnaryExpPrimaryExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryExpPrimaryExp(this);
}
void CACTParser::UnaryExpPrimaryExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryExpPrimaryExp(this);
}
//----------------- UnaryExpNestUnaryExpContext ------------------------------------------------------------------

CACTParser::UnaryOpContext* CACTParser::UnaryExpNestUnaryExpContext::unaryOp() {
  return getRuleContext<CACTParser::UnaryOpContext>(0);
}

CACTParser::UnaryExpContext* CACTParser::UnaryExpNestUnaryExpContext::unaryExp() {
  return getRuleContext<CACTParser::UnaryExpContext>(0);
}

CACTParser::UnaryExpNestUnaryExpContext::UnaryExpNestUnaryExpContext(UnaryExpContext *ctx) { copyFrom(ctx); }

void CACTParser::UnaryExpNestUnaryExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryExpNestUnaryExp(this);
}
void CACTParser::UnaryExpNestUnaryExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryExpNestUnaryExp(this);
}
CACTParser::UnaryExpContext* CACTParser::unaryExp() {
  UnaryExpContext *_localctx = _tracker.createInstance<UnaryExpContext>(_ctx, getState());
  enterRule(_localctx, 42, CACTParser::RuleUnaryExp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(278);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<UnaryExpContext *>(_tracker.createInstance<CACTParser::UnaryExpPrimaryExpContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(268);
      primaryExp();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<UnaryExpContext *>(_tracker.createInstance<CACTParser::UnaryExpFuncContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(269);
      match(CACTParser::Ident);
      setState(270);
      match(CACTParser::T__12);
      setState(272);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CACTParser::T__12)
        | (1ULL << CACTParser::T__21)
        | (1ULL << CACTParser::T__22)
        | (1ULL << CACTParser::T__23)
        | (1ULL << CACTParser::BoolConst)
        | (1ULL << CACTParser::Ident)
        | (1ULL << CACTParser::IntConst)
        | (1ULL << CACTParser::FloatConst)
        | (1ULL << CACTParser::DoubleConst))) != 0)) {
        setState(271);
        funcRParams();
      }
      setState(274);
      match(CACTParser::T__13);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<UnaryExpContext *>(_tracker.createInstance<CACTParser::UnaryExpNestUnaryExpContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(275);
      unaryOp();
      setState(276);
      unaryExp();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnaryOpContext ------------------------------------------------------------------

CACTParser::UnaryOpContext::UnaryOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::UnaryOpContext::getRuleIndex() const {
  return CACTParser::RuleUnaryOp;
}

void CACTParser::UnaryOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryOp(this);
}

void CACTParser::UnaryOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryOp(this);
}

CACTParser::UnaryOpContext* CACTParser::unaryOp() {
  UnaryOpContext *_localctx = _tracker.createInstance<UnaryOpContext>(_ctx, getState());
  enterRule(_localctx, 44, CACTParser::RuleUnaryOp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(280);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CACTParser::T__21)
      | (1ULL << CACTParser::T__22)
      | (1ULL << CACTParser::T__23))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncRParamsContext ------------------------------------------------------------------

CACTParser::FuncRParamsContext::FuncRParamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CACTParser::ExpContext *> CACTParser::FuncRParamsContext::exp() {
  return getRuleContexts<CACTParser::ExpContext>();
}

CACTParser::ExpContext* CACTParser::FuncRParamsContext::exp(size_t i) {
  return getRuleContext<CACTParser::ExpContext>(i);
}


size_t CACTParser::FuncRParamsContext::getRuleIndex() const {
  return CACTParser::RuleFuncRParams;
}

void CACTParser::FuncRParamsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncRParams(this);
}

void CACTParser::FuncRParamsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncRParams(this);
}

CACTParser::FuncRParamsContext* CACTParser::funcRParams() {
  FuncRParamsContext *_localctx = _tracker.createInstance<FuncRParamsContext>(_ctx, getState());
  enterRule(_localctx, 46, CACTParser::RuleFuncRParams);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(282);
    exp();
    setState(287);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CACTParser::T__1) {
      setState(283);
      match(CACTParser::T__1);
      setState(284);
      exp();
      setState(289);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MulExpContext ------------------------------------------------------------------

CACTParser::MulExpContext::MulExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::MulExpContext::getRuleIndex() const {
  return CACTParser::RuleMulExp;
}

void CACTParser::MulExpContext::copyFrom(MulExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->isArray = ctx->isArray;
  this->size = ctx->size;
  this->metaDataType = ctx->metaDataType;
}

//----------------- MulExpMulExpContext ------------------------------------------------------------------

CACTParser::MulExpContext* CACTParser::MulExpMulExpContext::mulExp() {
  return getRuleContext<CACTParser::MulExpContext>(0);
}

CACTParser::MulOpContext* CACTParser::MulExpMulExpContext::mulOp() {
  return getRuleContext<CACTParser::MulOpContext>(0);
}

CACTParser::UnaryExpContext* CACTParser::MulExpMulExpContext::unaryExp() {
  return getRuleContext<CACTParser::UnaryExpContext>(0);
}

CACTParser::MulExpMulExpContext::MulExpMulExpContext(MulExpContext *ctx) { copyFrom(ctx); }

void CACTParser::MulExpMulExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMulExpMulExp(this);
}
void CACTParser::MulExpMulExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMulExpMulExp(this);
}
//----------------- MulExpUnaryExpContext ------------------------------------------------------------------

CACTParser::UnaryExpContext* CACTParser::MulExpUnaryExpContext::unaryExp() {
  return getRuleContext<CACTParser::UnaryExpContext>(0);
}

CACTParser::MulExpUnaryExpContext::MulExpUnaryExpContext(MulExpContext *ctx) { copyFrom(ctx); }

void CACTParser::MulExpUnaryExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMulExpUnaryExp(this);
}
void CACTParser::MulExpUnaryExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMulExpUnaryExp(this);
}

CACTParser::MulExpContext* CACTParser::mulExp() {
   return mulExp(0);
}

CACTParser::MulExpContext* CACTParser::mulExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CACTParser::MulExpContext *_localctx = _tracker.createInstance<MulExpContext>(_ctx, parentState);
  CACTParser::MulExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 48;
  enterRecursionRule(_localctx, 48, CACTParser::RuleMulExp, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<MulExpUnaryExpContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(291);
    unaryExp();
    _ctx->stop = _input->LT(-1);
    setState(299);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<MulExpMulExpContext>(_tracker.createInstance<MulExpContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleMulExp);
        setState(293);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(294);
        mulOp();
        setState(295);
        unaryExp(); 
      }
      setState(301);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- MulOpContext ------------------------------------------------------------------

CACTParser::MulOpContext::MulOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::MulOpContext::getRuleIndex() const {
  return CACTParser::RuleMulOp;
}

void CACTParser::MulOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMulOp(this);
}

void CACTParser::MulOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMulOp(this);
}

CACTParser::MulOpContext* CACTParser::mulOp() {
  MulOpContext *_localctx = _tracker.createInstance<MulOpContext>(_ctx, getState());
  enterRule(_localctx, 50, CACTParser::RuleMulOp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(302);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CACTParser::T__24)
      | (1ULL << CACTParser::T__25)
      | (1ULL << CACTParser::T__26))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AddExpContext ------------------------------------------------------------------

CACTParser::AddExpContext::AddExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::AddExpContext::getRuleIndex() const {
  return CACTParser::RuleAddExp;
}

void CACTParser::AddExpContext::copyFrom(AddExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->isArray = ctx->isArray;
  this->size = ctx->size;
  this->metaDataType = ctx->metaDataType;
}

//----------------- AddExpAddExpContext ------------------------------------------------------------------

CACTParser::AddExpContext* CACTParser::AddExpAddExpContext::addExp() {
  return getRuleContext<CACTParser::AddExpContext>(0);
}

CACTParser::MulExpContext* CACTParser::AddExpAddExpContext::mulExp() {
  return getRuleContext<CACTParser::MulExpContext>(0);
}

CACTParser::AddExpAddExpContext::AddExpAddExpContext(AddExpContext *ctx) { copyFrom(ctx); }

void CACTParser::AddExpAddExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAddExpAddExp(this);
}
void CACTParser::AddExpAddExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAddExpAddExp(this);
}
//----------------- AddExpMulExpContext ------------------------------------------------------------------

CACTParser::MulExpContext* CACTParser::AddExpMulExpContext::mulExp() {
  return getRuleContext<CACTParser::MulExpContext>(0);
}

CACTParser::AddExpMulExpContext::AddExpMulExpContext(AddExpContext *ctx) { copyFrom(ctx); }

void CACTParser::AddExpMulExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAddExpMulExp(this);
}
void CACTParser::AddExpMulExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAddExpMulExp(this);
}

CACTParser::AddExpContext* CACTParser::addExp() {
   return addExp(0);
}

CACTParser::AddExpContext* CACTParser::addExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CACTParser::AddExpContext *_localctx = _tracker.createInstance<AddExpContext>(_ctx, parentState);
  CACTParser::AddExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 52;
  enterRecursionRule(_localctx, 52, CACTParser::RuleAddExp, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<AddExpMulExpContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(305);
    mulExp(0);
    _ctx->stop = _input->LT(-1);
    setState(312);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<AddExpAddExpContext>(_tracker.createInstance<AddExpContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleAddExp);
        setState(307);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(308);
        _la = _input->LA(1);
        if (!(_la == CACTParser::T__21

        || _la == CACTParser::T__22)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(309);
        mulExp(0); 
      }
      setState(314);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- RelExpContext ------------------------------------------------------------------

CACTParser::RelExpContext::RelExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::RelExpContext::getRuleIndex() const {
  return CACTParser::RuleRelExp;
}

void CACTParser::RelExpContext::copyFrom(RelExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->metaDataType = ctx->metaDataType;
}

//----------------- RelExpRelExpContext ------------------------------------------------------------------

CACTParser::RelExpContext* CACTParser::RelExpRelExpContext::relExp() {
  return getRuleContext<CACTParser::RelExpContext>(0);
}

CACTParser::AddExpContext* CACTParser::RelExpRelExpContext::addExp() {
  return getRuleContext<CACTParser::AddExpContext>(0);
}

CACTParser::RelExpRelExpContext::RelExpRelExpContext(RelExpContext *ctx) { copyFrom(ctx); }

void CACTParser::RelExpRelExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelExpRelExp(this);
}
void CACTParser::RelExpRelExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelExpRelExp(this);
}
//----------------- RelExpAddExpContext ------------------------------------------------------------------

CACTParser::AddExpContext* CACTParser::RelExpAddExpContext::addExp() {
  return getRuleContext<CACTParser::AddExpContext>(0);
}

CACTParser::RelExpAddExpContext::RelExpAddExpContext(RelExpContext *ctx) { copyFrom(ctx); }

void CACTParser::RelExpAddExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelExpAddExp(this);
}
void CACTParser::RelExpAddExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelExpAddExp(this);
}
//----------------- RelExpBoolConstContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::RelExpBoolConstContext::BoolConst() {
  return getToken(CACTParser::BoolConst, 0);
}

CACTParser::RelExpBoolConstContext::RelExpBoolConstContext(RelExpContext *ctx) { copyFrom(ctx); }

void CACTParser::RelExpBoolConstContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelExpBoolConst(this);
}
void CACTParser::RelExpBoolConstContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelExpBoolConst(this);
}

CACTParser::RelExpContext* CACTParser::relExp() {
   return relExp(0);
}

CACTParser::RelExpContext* CACTParser::relExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CACTParser::RelExpContext *_localctx = _tracker.createInstance<RelExpContext>(_ctx, parentState);
  CACTParser::RelExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 54;
  enterRecursionRule(_localctx, 54, CACTParser::RuleRelExp, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(318);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::T__12:
      case CACTParser::T__21:
      case CACTParser::T__22:
      case CACTParser::T__23:
      case CACTParser::Ident:
      case CACTParser::IntConst:
      case CACTParser::FloatConst:
      case CACTParser::DoubleConst: {
        _localctx = _tracker.createInstance<RelExpAddExpContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(316);
        addExp(0);
        break;
      }

      case CACTParser::BoolConst: {
        _localctx = _tracker.createInstance<RelExpBoolConstContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(317);
        match(CACTParser::BoolConst);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(325);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<RelExpRelExpContext>(_tracker.createInstance<RelExpContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleRelExp);
        setState(320);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(321);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << CACTParser::T__27)
          | (1ULL << CACTParser::T__28)
          | (1ULL << CACTParser::T__29)
          | (1ULL << CACTParser::T__30))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(322);
        addExp(0); 
      }
      setState(327);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- EqExpContext ------------------------------------------------------------------

CACTParser::EqExpContext::EqExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::EqExpContext::getRuleIndex() const {
  return CACTParser::RuleEqExp;
}

void CACTParser::EqExpContext::copyFrom(EqExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->metaDataType = ctx->metaDataType;
}

//----------------- EqExpRelExpContext ------------------------------------------------------------------

CACTParser::RelExpContext* CACTParser::EqExpRelExpContext::relExp() {
  return getRuleContext<CACTParser::RelExpContext>(0);
}

CACTParser::EqExpRelExpContext::EqExpRelExpContext(EqExpContext *ctx) { copyFrom(ctx); }

void CACTParser::EqExpRelExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEqExpRelExp(this);
}
void CACTParser::EqExpRelExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEqExpRelExp(this);
}
//----------------- EqExpEqExpContext ------------------------------------------------------------------

CACTParser::EqExpContext* CACTParser::EqExpEqExpContext::eqExp() {
  return getRuleContext<CACTParser::EqExpContext>(0);
}

CACTParser::RelExpContext* CACTParser::EqExpEqExpContext::relExp() {
  return getRuleContext<CACTParser::RelExpContext>(0);
}

CACTParser::EqExpEqExpContext::EqExpEqExpContext(EqExpContext *ctx) { copyFrom(ctx); }

void CACTParser::EqExpEqExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEqExpEqExp(this);
}
void CACTParser::EqExpEqExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEqExpEqExp(this);
}

CACTParser::EqExpContext* CACTParser::eqExp() {
   return eqExp(0);
}

CACTParser::EqExpContext* CACTParser::eqExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CACTParser::EqExpContext *_localctx = _tracker.createInstance<EqExpContext>(_ctx, parentState);
  CACTParser::EqExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 56;
  enterRecursionRule(_localctx, 56, CACTParser::RuleEqExp, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<EqExpRelExpContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(329);
    relExp(0);
    _ctx->stop = _input->LT(-1);
    setState(336);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<EqExpEqExpContext>(_tracker.createInstance<EqExpContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleEqExp);
        setState(331);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(332);
        _la = _input->LA(1);
        if (!(_la == CACTParser::T__31

        || _la == CACTParser::T__32)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(333);
        relExp(0); 
      }
      setState(338);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- LAndExpContext ------------------------------------------------------------------

CACTParser::LAndExpContext::LAndExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::LAndExpContext::getRuleIndex() const {
  return CACTParser::RuleLAndExp;
}

void CACTParser::LAndExpContext::copyFrom(LAndExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->metaDataType = ctx->metaDataType;
}

//----------------- LAndExpLAndExpContext ------------------------------------------------------------------

CACTParser::LAndExpContext* CACTParser::LAndExpLAndExpContext::lAndExp() {
  return getRuleContext<CACTParser::LAndExpContext>(0);
}

CACTParser::EqExpContext* CACTParser::LAndExpLAndExpContext::eqExp() {
  return getRuleContext<CACTParser::EqExpContext>(0);
}

CACTParser::LAndExpLAndExpContext::LAndExpLAndExpContext(LAndExpContext *ctx) { copyFrom(ctx); }

void CACTParser::LAndExpLAndExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLAndExpLAndExp(this);
}
void CACTParser::LAndExpLAndExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLAndExpLAndExp(this);
}
//----------------- LAndExpEqExpContext ------------------------------------------------------------------

CACTParser::EqExpContext* CACTParser::LAndExpEqExpContext::eqExp() {
  return getRuleContext<CACTParser::EqExpContext>(0);
}

CACTParser::LAndExpEqExpContext::LAndExpEqExpContext(LAndExpContext *ctx) { copyFrom(ctx); }

void CACTParser::LAndExpEqExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLAndExpEqExp(this);
}
void CACTParser::LAndExpEqExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLAndExpEqExp(this);
}

CACTParser::LAndExpContext* CACTParser::lAndExp() {
   return lAndExp(0);
}

CACTParser::LAndExpContext* CACTParser::lAndExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CACTParser::LAndExpContext *_localctx = _tracker.createInstance<LAndExpContext>(_ctx, parentState);
  CACTParser::LAndExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 58;
  enterRecursionRule(_localctx, 58, CACTParser::RuleLAndExp, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<LAndExpEqExpContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(340);
    eqExp(0);
    _ctx->stop = _input->LT(-1);
    setState(347);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<LAndExpLAndExpContext>(_tracker.createInstance<LAndExpContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleLAndExp);
        setState(342);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");

        setState(343);
        match(CACTParser::T__33);
        setState(344);
        eqExp(0); 
      }
      setState(349);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- LOrExpContext ------------------------------------------------------------------

CACTParser::LOrExpContext::LOrExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::LOrExpContext::getRuleIndex() const {
  return CACTParser::RuleLOrExp;
}

void CACTParser::LOrExpContext::copyFrom(LOrExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->metaDataType = ctx->metaDataType;
}

//----------------- LOrExpLAndExpContext ------------------------------------------------------------------

CACTParser::LAndExpContext* CACTParser::LOrExpLAndExpContext::lAndExp() {
  return getRuleContext<CACTParser::LAndExpContext>(0);
}

CACTParser::LOrExpLAndExpContext::LOrExpLAndExpContext(LOrExpContext *ctx) { copyFrom(ctx); }

void CACTParser::LOrExpLAndExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLOrExpLAndExp(this);
}
void CACTParser::LOrExpLAndExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLOrExpLAndExp(this);
}
//----------------- LOrExpLOrExpContext ------------------------------------------------------------------

CACTParser::LOrExpContext* CACTParser::LOrExpLOrExpContext::lOrExp() {
  return getRuleContext<CACTParser::LOrExpContext>(0);
}

CACTParser::LAndExpContext* CACTParser::LOrExpLOrExpContext::lAndExp() {
  return getRuleContext<CACTParser::LAndExpContext>(0);
}

CACTParser::LOrExpLOrExpContext::LOrExpLOrExpContext(LOrExpContext *ctx) { copyFrom(ctx); }

void CACTParser::LOrExpLOrExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLOrExpLOrExp(this);
}
void CACTParser::LOrExpLOrExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLOrExpLOrExp(this);
}

CACTParser::LOrExpContext* CACTParser::lOrExp() {
   return lOrExp(0);
}

CACTParser::LOrExpContext* CACTParser::lOrExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CACTParser::LOrExpContext *_localctx = _tracker.createInstance<LOrExpContext>(_ctx, parentState);
  CACTParser::LOrExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 60;
  enterRecursionRule(_localctx, 60, CACTParser::RuleLOrExp, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<LOrExpLAndExpContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(351);
    lAndExp(0);
    _ctx->stop = _input->LT(-1);
    setState(358);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<LOrExpLOrExpContext>(_tracker.createInstance<LOrExpContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleLOrExp);
        setState(353);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");

        setState(354);
        match(CACTParser::T__34);
        setState(355);
        lAndExp(0); 
      }
      setState(360);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ConstExpContext ------------------------------------------------------------------

CACTParser::ConstExpContext::ConstExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::ConstExpContext::getRuleIndex() const {
  return CACTParser::RuleConstExp;
}

void CACTParser::ConstExpContext::copyFrom(ConstExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->metaDataType = ctx->metaDataType;
}

//----------------- ConstExpBoolConstContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::ConstExpBoolConstContext::BoolConst() {
  return getToken(CACTParser::BoolConst, 0);
}

CACTParser::ConstExpBoolConstContext::ConstExpBoolConstContext(ConstExpContext *ctx) { copyFrom(ctx); }

void CACTParser::ConstExpBoolConstContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstExpBoolConst(this);
}
void CACTParser::ConstExpBoolConstContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstExpBoolConst(this);
}
//----------------- ConstExpNumberContext ------------------------------------------------------------------

CACTParser::NumberContext* CACTParser::ConstExpNumberContext::number() {
  return getRuleContext<CACTParser::NumberContext>(0);
}

CACTParser::ConstExpNumberContext::ConstExpNumberContext(ConstExpContext *ctx) { copyFrom(ctx); }

void CACTParser::ConstExpNumberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstExpNumber(this);
}
void CACTParser::ConstExpNumberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstExpNumber(this);
}
CACTParser::ConstExpContext* CACTParser::constExp() {
  ConstExpContext *_localctx = _tracker.createInstance<ConstExpContext>(_ctx, getState());
  enterRule(_localctx, 62, CACTParser::RuleConstExp);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(363);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::IntConst:
      case CACTParser::FloatConst:
      case CACTParser::DoubleConst: {
        _localctx = dynamic_cast<ConstExpContext *>(_tracker.createInstance<CACTParser::ConstExpNumberContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(361);
        number();
        break;
      }

      case CACTParser::BoolConst: {
        _localctx = dynamic_cast<ConstExpContext *>(_tracker.createInstance<CACTParser::ConstExpBoolConstContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(362);
        match(CACTParser::BoolConst);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumberContext ------------------------------------------------------------------

CACTParser::NumberContext::NumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::NumberContext::getRuleIndex() const {
  return CACTParser::RuleNumber;
}

void CACTParser::NumberContext::copyFrom(NumberContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->metaDataType = ctx->metaDataType;
}

//----------------- NumberDoubleConstContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::NumberDoubleConstContext::DoubleConst() {
  return getToken(CACTParser::DoubleConst, 0);
}

CACTParser::NumberDoubleConstContext::NumberDoubleConstContext(NumberContext *ctx) { copyFrom(ctx); }

void CACTParser::NumberDoubleConstContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumberDoubleConst(this);
}
void CACTParser::NumberDoubleConstContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumberDoubleConst(this);
}
//----------------- NumberFloatConstContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::NumberFloatConstContext::FloatConst() {
  return getToken(CACTParser::FloatConst, 0);
}

CACTParser::NumberFloatConstContext::NumberFloatConstContext(NumberContext *ctx) { copyFrom(ctx); }

void CACTParser::NumberFloatConstContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumberFloatConst(this);
}
void CACTParser::NumberFloatConstContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumberFloatConst(this);
}
//----------------- NumberIntConstContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::NumberIntConstContext::IntConst() {
  return getToken(CACTParser::IntConst, 0);
}

CACTParser::NumberIntConstContext::NumberIntConstContext(NumberContext *ctx) { copyFrom(ctx); }

void CACTParser::NumberIntConstContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumberIntConst(this);
}
void CACTParser::NumberIntConstContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumberIntConst(this);
}
CACTParser::NumberContext* CACTParser::number() {
  NumberContext *_localctx = _tracker.createInstance<NumberContext>(_ctx, getState());
  enterRule(_localctx, 64, CACTParser::RuleNumber);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(368);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::IntConst: {
        _localctx = dynamic_cast<NumberContext *>(_tracker.createInstance<CACTParser::NumberIntConstContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(365);
        match(CACTParser::IntConst);
        break;
      }

      case CACTParser::DoubleConst: {
        _localctx = dynamic_cast<NumberContext *>(_tracker.createInstance<CACTParser::NumberDoubleConstContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(366);
        match(CACTParser::DoubleConst);
        break;
      }

      case CACTParser::FloatConst: {
        _localctx = dynamic_cast<NumberContext *>(_tracker.createInstance<CACTParser::NumberFloatConstContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(367);
        match(CACTParser::FloatConst);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool CACTParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 24: return mulExpSempred(dynamic_cast<MulExpContext *>(context), predicateIndex);
    case 26: return addExpSempred(dynamic_cast<AddExpContext *>(context), predicateIndex);
    case 27: return relExpSempred(dynamic_cast<RelExpContext *>(context), predicateIndex);
    case 28: return eqExpSempred(dynamic_cast<EqExpContext *>(context), predicateIndex);
    case 29: return lAndExpSempred(dynamic_cast<LAndExpContext *>(context), predicateIndex);
    case 30: return lOrExpSempred(dynamic_cast<LOrExpContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool CACTParser::mulExpSempred(MulExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CACTParser::addExpSempred(AddExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CACTParser::relExpSempred(RelExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 2: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool CACTParser::eqExpSempred(EqExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CACTParser::lAndExpSempred(LAndExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 4: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CACTParser::lOrExpSempred(LOrExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 5: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> CACTParser::_decisionToDFA;
atn::PredictionContextCache CACTParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN CACTParser::_atn;
std::vector<uint16_t> CACTParser::_serializedATN;

std::vector<std::string> CACTParser::_ruleNames = {
  "compUnit", "decl", "constDecl", "bType", "constDef", "constInitVal", 
  "varDecl", "varDef", "funcDef", "funcType", "funcFParams", "funcFParam", 
  "brackets", "block", "blockItem", "stmt", "subStmt", "exp", "cond", "lVal", 
  "primaryExp", "unaryExp", "unaryOp", "funcRParams", "mulExp", "mulOp", 
  "addExp", "relExp", "eqExp", "lAndExp", "lOrExp", "constExp", "number"
};

std::vector<std::string> CACTParser::_literalNames = {
  "", "'const'", "','", "';'", "'int'", "'bool'", "'double'", "'float'", 
  "'['", "']'", "'='", "'{'", "'}'", "'('", "')'", "'void'", "'if'", "'else'", 
  "'while'", "'return'", "'break'", "'continue'", "'+'", "'-'", "'!'", "'*'", 
  "'/'", "'%'", "'<'", "'>'", "'<='", "'>='", "'=='", "'!='", "'&&'", "'||'"
};

std::vector<std::string> CACTParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "BoolConst", "Ident", "IntConst", "DigitSequence", "FloatConst", "DoubleConst", 
  "NewLine", "WhiteSpace", "BlockComment", "LineComment"
};

dfa::Vocabulary CACTParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> CACTParser::_tokenNames;

CACTParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x2f, 0x175, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 
    0x9, 0x22, 0x3, 0x2, 0x3, 0x2, 0x6, 0x2, 0x47, 0xa, 0x2, 0xd, 0x2, 0xe, 
    0x2, 0x48, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x4f, 0xa, 
    0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x56, 
    0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x59, 0xb, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x63, 
    0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x5, 0x7, 0x69, 0xa, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0x6f, 0xa, 0x7, 
    0xc, 0x7, 0xe, 0x7, 0x72, 0xb, 0x7, 0x5, 0x7, 0x74, 0xa, 0x7, 0x3, 0x7, 
    0x5, 0x7, 0x77, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x7, 
    0x8, 0x7d, 0xa, 0x8, 0xc, 0x8, 0xe, 0x8, 0x80, 0xb, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x88, 0xa, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x8c, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x5, 0xa, 0x92, 0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0x9c, 0xa, 
    0xc, 0xc, 0xc, 0xe, 0xc, 0x9f, 0xb, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x5, 0xd, 0xa4, 0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 
    0xf, 0x7, 0xf, 0xab, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0xae, 0xb, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0xb4, 0xa, 0x10, 0x3, 
    0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 
    0xbc, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0xc7, 0xa, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 
    0x11, 0x3, 0x11, 0x5, 0x11, 0xd1, 0xa, 0x11, 0x3, 0x11, 0x5, 0x11, 0xd4, 
    0xa, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x5, 0x12, 0xdc, 0xa, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 
    0xe7, 0xa, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x5, 0x12, 0xf5, 0xa, 0x12, 0x3, 0x12, 0x5, 0x12, 0xf8, 0xa, 0x12, 
    0x3, 0x13, 0x3, 0x13, 0x5, 0x13, 0xfc, 0xa, 0x13, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 0x105, 
    0xa, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 
    0x16, 0x5, 0x16, 0x10d, 0xa, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 
    0x3, 0x17, 0x5, 0x17, 0x113, 0xa, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 
    0x3, 0x17, 0x5, 0x17, 0x119, 0xa, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 
    0x3, 0x19, 0x3, 0x19, 0x7, 0x19, 0x120, 0xa, 0x19, 0xc, 0x19, 0xe, 0x19, 
    0x123, 0xb, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 
    0x3, 0x1a, 0x3, 0x1a, 0x7, 0x1a, 0x12c, 0xa, 0x1a, 0xc, 0x1a, 0xe, 0x1a, 
    0x12f, 0xb, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 
    0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x7, 0x1c, 0x139, 0xa, 0x1c, 0xc, 0x1c, 
    0xe, 0x1c, 0x13c, 0xb, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x5, 0x1d, 
    0x141, 0xa, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x7, 0x1d, 0x146, 
    0xa, 0x1d, 0xc, 0x1d, 0xe, 0x1d, 0x149, 0xb, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 
    0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x7, 0x1e, 0x151, 0xa, 0x1e, 
    0xc, 0x1e, 0xe, 0x1e, 0x154, 0xb, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 
    0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x7, 0x1f, 0x15c, 0xa, 0x1f, 0xc, 0x1f, 
    0xe, 0x1f, 0x15f, 0xb, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 
    0x3, 0x20, 0x3, 0x20, 0x7, 0x20, 0x167, 0xa, 0x20, 0xc, 0x20, 0xe, 0x20, 
    0x16a, 0xb, 0x20, 0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 0x16e, 0xa, 0x21, 
    0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x5, 0x22, 0x173, 0xa, 0x22, 0x3, 0x22, 
    0x2, 0x8, 0x32, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x23, 0x2, 0x4, 0x6, 0x8, 
    0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 
    0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 
    0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x2, 0x9, 0x3, 0x2, 0x6, 0x9, 0x4, 0x2, 
    0x6, 0x9, 0x11, 0x11, 0x3, 0x2, 0x18, 0x1a, 0x3, 0x2, 0x1b, 0x1d, 0x3, 
    0x2, 0x18, 0x19, 0x3, 0x2, 0x1e, 0x21, 0x3, 0x2, 0x22, 0x23, 0x2, 0x188, 
    0x2, 0x46, 0x3, 0x2, 0x2, 0x2, 0x4, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x6, 0x50, 
    0x3, 0x2, 0x2, 0x2, 0x8, 0x5c, 0x3, 0x2, 0x2, 0x2, 0xa, 0x5e, 0x3, 0x2, 
    0x2, 0x2, 0xc, 0x76, 0x3, 0x2, 0x2, 0x2, 0xe, 0x78, 0x3, 0x2, 0x2, 0x2, 
    0x10, 0x83, 0x3, 0x2, 0x2, 0x2, 0x12, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x14, 
    0x96, 0x3, 0x2, 0x2, 0x2, 0x16, 0x98, 0x3, 0x2, 0x2, 0x2, 0x18, 0xa0, 
    0x3, 0x2, 0x2, 0x2, 0x1a, 0xa5, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xa8, 0x3, 
    0x2, 0x2, 0x2, 0x1e, 0xb3, 0x3, 0x2, 0x2, 0x2, 0x20, 0xd3, 0x3, 0x2, 
    0x2, 0x2, 0x22, 0xf7, 0x3, 0x2, 0x2, 0x2, 0x24, 0xfb, 0x3, 0x2, 0x2, 
    0x2, 0x26, 0xfd, 0x3, 0x2, 0x2, 0x2, 0x28, 0xff, 0x3, 0x2, 0x2, 0x2, 
    0x2a, 0x10c, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x118, 0x3, 0x2, 0x2, 0x2, 0x2e, 
    0x11a, 0x3, 0x2, 0x2, 0x2, 0x30, 0x11c, 0x3, 0x2, 0x2, 0x2, 0x32, 0x124, 
    0x3, 0x2, 0x2, 0x2, 0x34, 0x130, 0x3, 0x2, 0x2, 0x2, 0x36, 0x132, 0x3, 
    0x2, 0x2, 0x2, 0x38, 0x140, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x14a, 0x3, 0x2, 
    0x2, 0x2, 0x3c, 0x155, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x160, 0x3, 0x2, 0x2, 
    0x2, 0x40, 0x16d, 0x3, 0x2, 0x2, 0x2, 0x42, 0x172, 0x3, 0x2, 0x2, 0x2, 
    0x44, 0x47, 0x5, 0x4, 0x3, 0x2, 0x45, 0x47, 0x5, 0x12, 0xa, 0x2, 0x46, 
    0x44, 0x3, 0x2, 0x2, 0x2, 0x46, 0x45, 0x3, 0x2, 0x2, 0x2, 0x47, 0x48, 
    0x3, 0x2, 0x2, 0x2, 0x48, 0x46, 0x3, 0x2, 0x2, 0x2, 0x48, 0x49, 0x3, 
    0x2, 0x2, 0x2, 0x49, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x4b, 0x7, 0x2, 
    0x2, 0x3, 0x4b, 0x3, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4f, 0x5, 0x6, 0x4, 
    0x2, 0x4d, 0x4f, 0x5, 0xe, 0x8, 0x2, 0x4e, 0x4c, 0x3, 0x2, 0x2, 0x2, 
    0x4e, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x5, 0x3, 0x2, 0x2, 0x2, 0x50, 
    0x51, 0x7, 0x3, 0x2, 0x2, 0x51, 0x52, 0x5, 0x8, 0x5, 0x2, 0x52, 0x57, 
    0x5, 0xa, 0x6, 0x2, 0x53, 0x54, 0x7, 0x4, 0x2, 0x2, 0x54, 0x56, 0x5, 
    0xa, 0x6, 0x2, 0x55, 0x53, 0x3, 0x2, 0x2, 0x2, 0x56, 0x59, 0x3, 0x2, 
    0x2, 0x2, 0x57, 0x55, 0x3, 0x2, 0x2, 0x2, 0x57, 0x58, 0x3, 0x2, 0x2, 
    0x2, 0x58, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x59, 0x57, 0x3, 0x2, 0x2, 0x2, 
    0x5a, 0x5b, 0x7, 0x5, 0x2, 0x2, 0x5b, 0x7, 0x3, 0x2, 0x2, 0x2, 0x5c, 
    0x5d, 0x9, 0x2, 0x2, 0x2, 0x5d, 0x9, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x62, 
    0x7, 0x27, 0x2, 0x2, 0x5f, 0x60, 0x7, 0xa, 0x2, 0x2, 0x60, 0x61, 0x7, 
    0x28, 0x2, 0x2, 0x61, 0x63, 0x7, 0xb, 0x2, 0x2, 0x62, 0x5f, 0x3, 0x2, 
    0x2, 0x2, 0x62, 0x63, 0x3, 0x2, 0x2, 0x2, 0x63, 0x64, 0x3, 0x2, 0x2, 
    0x2, 0x64, 0x65, 0x7, 0xc, 0x2, 0x2, 0x65, 0x66, 0x5, 0xc, 0x7, 0x2, 
    0x66, 0xb, 0x3, 0x2, 0x2, 0x2, 0x67, 0x69, 0x5, 0x40, 0x21, 0x2, 0x68, 
    0x67, 0x3, 0x2, 0x2, 0x2, 0x68, 0x69, 0x3, 0x2, 0x2, 0x2, 0x69, 0x77, 
    0x3, 0x2, 0x2, 0x2, 0x6a, 0x73, 0x7, 0xd, 0x2, 0x2, 0x6b, 0x70, 0x5, 
    0x40, 0x21, 0x2, 0x6c, 0x6d, 0x7, 0x4, 0x2, 0x2, 0x6d, 0x6f, 0x5, 0x40, 
    0x21, 0x2, 0x6e, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x72, 0x3, 0x2, 0x2, 
    0x2, 0x70, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x70, 0x71, 0x3, 0x2, 0x2, 0x2, 
    0x71, 0x74, 0x3, 0x2, 0x2, 0x2, 0x72, 0x70, 0x3, 0x2, 0x2, 0x2, 0x73, 
    0x6b, 0x3, 0x2, 0x2, 0x2, 0x73, 0x74, 0x3, 0x2, 0x2, 0x2, 0x74, 0x75, 
    0x3, 0x2, 0x2, 0x2, 0x75, 0x77, 0x7, 0xe, 0x2, 0x2, 0x76, 0x68, 0x3, 
    0x2, 0x2, 0x2, 0x76, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x77, 0xd, 0x3, 0x2, 
    0x2, 0x2, 0x78, 0x79, 0x5, 0x8, 0x5, 0x2, 0x79, 0x7e, 0x5, 0x10, 0x9, 
    0x2, 0x7a, 0x7b, 0x7, 0x4, 0x2, 0x2, 0x7b, 0x7d, 0x5, 0x10, 0x9, 0x2, 
    0x7c, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x80, 0x3, 0x2, 0x2, 0x2, 0x7e, 
    0x7c, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x81, 
    0x3, 0x2, 0x2, 0x2, 0x80, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x81, 0x82, 0x7, 
    0x5, 0x2, 0x2, 0x82, 0xf, 0x3, 0x2, 0x2, 0x2, 0x83, 0x87, 0x7, 0x27, 
    0x2, 0x2, 0x84, 0x85, 0x7, 0xa, 0x2, 0x2, 0x85, 0x86, 0x7, 0x28, 0x2, 
    0x2, 0x86, 0x88, 0x7, 0xb, 0x2, 0x2, 0x87, 0x84, 0x3, 0x2, 0x2, 0x2, 
    0x87, 0x88, 0x3, 0x2, 0x2, 0x2, 0x88, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x89, 
    0x8a, 0x7, 0xc, 0x2, 0x2, 0x8a, 0x8c, 0x5, 0xc, 0x7, 0x2, 0x8b, 0x89, 
    0x3, 0x2, 0x2, 0x2, 0x8b, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x11, 0x3, 
    0x2, 0x2, 0x2, 0x8d, 0x8e, 0x5, 0x14, 0xb, 0x2, 0x8e, 0x8f, 0x7, 0x27, 
    0x2, 0x2, 0x8f, 0x91, 0x7, 0xf, 0x2, 0x2, 0x90, 0x92, 0x5, 0x16, 0xc, 
    0x2, 0x91, 0x90, 0x3, 0x2, 0x2, 0x2, 0x91, 0x92, 0x3, 0x2, 0x2, 0x2, 
    0x92, 0x93, 0x3, 0x2, 0x2, 0x2, 0x93, 0x94, 0x7, 0x10, 0x2, 0x2, 0x94, 
    0x95, 0x5, 0x1c, 0xf, 0x2, 0x95, 0x13, 0x3, 0x2, 0x2, 0x2, 0x96, 0x97, 
    0x9, 0x3, 0x2, 0x2, 0x97, 0x15, 0x3, 0x2, 0x2, 0x2, 0x98, 0x9d, 0x5, 
    0x18, 0xd, 0x2, 0x99, 0x9a, 0x7, 0x4, 0x2, 0x2, 0x9a, 0x9c, 0x5, 0x18, 
    0xd, 0x2, 0x9b, 0x99, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x9f, 0x3, 0x2, 0x2, 
    0x2, 0x9d, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x9d, 0x9e, 0x3, 0x2, 0x2, 0x2, 
    0x9e, 0x17, 0x3, 0x2, 0x2, 0x2, 0x9f, 0x9d, 0x3, 0x2, 0x2, 0x2, 0xa0, 
    0xa1, 0x5, 0x8, 0x5, 0x2, 0xa1, 0xa3, 0x7, 0x27, 0x2, 0x2, 0xa2, 0xa4, 
    0x5, 0x1a, 0xe, 0x2, 0xa3, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xa4, 0x3, 
    0x2, 0x2, 0x2, 0xa4, 0x19, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xa6, 0x7, 0xa, 
    0x2, 0x2, 0xa6, 0xa7, 0x7, 0xb, 0x2, 0x2, 0xa7, 0x1b, 0x3, 0x2, 0x2, 
    0x2, 0xa8, 0xac, 0x7, 0xd, 0x2, 0x2, 0xa9, 0xab, 0x5, 0x1e, 0x10, 0x2, 
    0xaa, 0xa9, 0x3, 0x2, 0x2, 0x2, 0xab, 0xae, 0x3, 0x2, 0x2, 0x2, 0xac, 
    0xaa, 0x3, 0x2, 0x2, 0x2, 0xac, 0xad, 0x3, 0x2, 0x2, 0x2, 0xad, 0xaf, 
    0x3, 0x2, 0x2, 0x2, 0xae, 0xac, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xb0, 0x7, 
    0xe, 0x2, 0x2, 0xb0, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xb4, 0x5, 0x4, 
    0x3, 0x2, 0xb2, 0xb4, 0x5, 0x20, 0x11, 0x2, 0xb3, 0xb1, 0x3, 0x2, 0x2, 
    0x2, 0xb3, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xb4, 0x1f, 0x3, 0x2, 0x2, 0x2, 
    0xb5, 0xb6, 0x5, 0x28, 0x15, 0x2, 0xb6, 0xb7, 0x7, 0xc, 0x2, 0x2, 0xb7, 
    0xb8, 0x5, 0x24, 0x13, 0x2, 0xb8, 0xb9, 0x7, 0x5, 0x2, 0x2, 0xb9, 0xd4, 
    0x3, 0x2, 0x2, 0x2, 0xba, 0xbc, 0x5, 0x24, 0x13, 0x2, 0xbb, 0xba, 0x3, 
    0x2, 0x2, 0x2, 0xbb, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xbd, 0x3, 0x2, 
    0x2, 0x2, 0xbd, 0xd4, 0x7, 0x5, 0x2, 0x2, 0xbe, 0xd4, 0x5, 0x1c, 0xf, 
    0x2, 0xbf, 0xc0, 0x7, 0x12, 0x2, 0x2, 0xc0, 0xc1, 0x7, 0xf, 0x2, 0x2, 
    0xc1, 0xc2, 0x5, 0x26, 0x14, 0x2, 0xc2, 0xc3, 0x7, 0x10, 0x2, 0x2, 0xc3, 
    0xc6, 0x5, 0x20, 0x11, 0x2, 0xc4, 0xc5, 0x7, 0x13, 0x2, 0x2, 0xc5, 0xc7, 
    0x5, 0x20, 0x11, 0x2, 0xc6, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xc7, 0x3, 
    0x2, 0x2, 0x2, 0xc7, 0xd4, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xc9, 0x7, 0x14, 
    0x2, 0x2, 0xc9, 0xca, 0x7, 0xf, 0x2, 0x2, 0xca, 0xcb, 0x5, 0x26, 0x14, 
    0x2, 0xcb, 0xcc, 0x7, 0x10, 0x2, 0x2, 0xcc, 0xcd, 0x5, 0x22, 0x12, 0x2, 
    0xcd, 0xd4, 0x3, 0x2, 0x2, 0x2, 0xce, 0xd0, 0x7, 0x15, 0x2, 0x2, 0xcf, 
    0xd1, 0x5, 0x24, 0x13, 0x2, 0xd0, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xd1, 
    0x3, 0x2, 0x2, 0x2, 0xd1, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xd4, 0x7, 
    0x5, 0x2, 0x2, 0xd3, 0xb5, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xbb, 0x3, 0x2, 
    0x2, 0x2, 0xd3, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xbf, 0x3, 0x2, 0x2, 
    0x2, 0xd3, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xce, 0x3, 0x2, 0x2, 0x2, 
    0xd4, 0x21, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xd6, 0x5, 0x28, 0x15, 0x2, 0xd6, 
    0xd7, 0x7, 0xc, 0x2, 0x2, 0xd7, 0xd8, 0x5, 0x24, 0x13, 0x2, 0xd8, 0xd9, 
    0x7, 0x5, 0x2, 0x2, 0xd9, 0xf8, 0x3, 0x2, 0x2, 0x2, 0xda, 0xdc, 0x5, 
    0x24, 0x13, 0x2, 0xdb, 0xda, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xdc, 0x3, 0x2, 
    0x2, 0x2, 0xdc, 0xdd, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xf8, 0x7, 0x5, 0x2, 
    0x2, 0xde, 0xf8, 0x5, 0x1c, 0xf, 0x2, 0xdf, 0xe0, 0x7, 0x12, 0x2, 0x2, 
    0xe0, 0xe1, 0x7, 0xf, 0x2, 0x2, 0xe1, 0xe2, 0x5, 0x26, 0x14, 0x2, 0xe2, 
    0xe3, 0x7, 0x10, 0x2, 0x2, 0xe3, 0xe6, 0x5, 0x22, 0x12, 0x2, 0xe4, 0xe5, 
    0x7, 0x13, 0x2, 0x2, 0xe5, 0xe7, 0x5, 0x22, 0x12, 0x2, 0xe6, 0xe4, 0x3, 
    0x2, 0x2, 0x2, 0xe6, 0xe7, 0x3, 0x2, 0x2, 0x2, 0xe7, 0xf8, 0x3, 0x2, 
    0x2, 0x2, 0xe8, 0xe9, 0x7, 0x14, 0x2, 0x2, 0xe9, 0xea, 0x7, 0xf, 0x2, 
    0x2, 0xea, 0xeb, 0x5, 0x26, 0x14, 0x2, 0xeb, 0xec, 0x7, 0x10, 0x2, 0x2, 
    0xec, 0xed, 0x5, 0x22, 0x12, 0x2, 0xed, 0xf8, 0x3, 0x2, 0x2, 0x2, 0xee, 
    0xef, 0x7, 0x16, 0x2, 0x2, 0xef, 0xf8, 0x7, 0x5, 0x2, 0x2, 0xf0, 0xf1, 
    0x7, 0x17, 0x2, 0x2, 0xf1, 0xf8, 0x7, 0x5, 0x2, 0x2, 0xf2, 0xf4, 0x7, 
    0x15, 0x2, 0x2, 0xf3, 0xf5, 0x5, 0x24, 0x13, 0x2, 0xf4, 0xf3, 0x3, 0x2, 
    0x2, 0x2, 0xf4, 0xf5, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xf6, 0x3, 0x2, 0x2, 
    0x2, 0xf6, 0xf8, 0x7, 0x5, 0x2, 0x2, 0xf7, 0xd5, 0x3, 0x2, 0x2, 0x2, 
    0xf7, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xde, 0x3, 0x2, 0x2, 0x2, 0xf7, 
    0xdf, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xe8, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xee, 
    0x3, 0x2, 0x2, 0x2, 0xf7, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xf2, 0x3, 
    0x2, 0x2, 0x2, 0xf8, 0x23, 0x3, 0x2, 0x2, 0x2, 0xf9, 0xfc, 0x5, 0x36, 
    0x1c, 0x2, 0xfa, 0xfc, 0x7, 0x26, 0x2, 0x2, 0xfb, 0xf9, 0x3, 0x2, 0x2, 
    0x2, 0xfb, 0xfa, 0x3, 0x2, 0x2, 0x2, 0xfc, 0x25, 0x3, 0x2, 0x2, 0x2, 
    0xfd, 0xfe, 0x5, 0x3e, 0x20, 0x2, 0xfe, 0x27, 0x3, 0x2, 0x2, 0x2, 0xff, 
    0x104, 0x7, 0x27, 0x2, 0x2, 0x100, 0x101, 0x7, 0xa, 0x2, 0x2, 0x101, 
    0x102, 0x5, 0x24, 0x13, 0x2, 0x102, 0x103, 0x7, 0xb, 0x2, 0x2, 0x103, 
    0x105, 0x3, 0x2, 0x2, 0x2, 0x104, 0x100, 0x3, 0x2, 0x2, 0x2, 0x104, 
    0x105, 0x3, 0x2, 0x2, 0x2, 0x105, 0x29, 0x3, 0x2, 0x2, 0x2, 0x106, 0x107, 
    0x7, 0xf, 0x2, 0x2, 0x107, 0x108, 0x5, 0x24, 0x13, 0x2, 0x108, 0x109, 
    0x7, 0x10, 0x2, 0x2, 0x109, 0x10d, 0x3, 0x2, 0x2, 0x2, 0x10a, 0x10d, 
    0x5, 0x28, 0x15, 0x2, 0x10b, 0x10d, 0x5, 0x42, 0x22, 0x2, 0x10c, 0x106, 
    0x3, 0x2, 0x2, 0x2, 0x10c, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x10c, 0x10b, 
    0x3, 0x2, 0x2, 0x2, 0x10d, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x10e, 0x119, 0x5, 
    0x2a, 0x16, 0x2, 0x10f, 0x110, 0x7, 0x27, 0x2, 0x2, 0x110, 0x112, 0x7, 
    0xf, 0x2, 0x2, 0x111, 0x113, 0x5, 0x30, 0x19, 0x2, 0x112, 0x111, 0x3, 
    0x2, 0x2, 0x2, 0x112, 0x113, 0x3, 0x2, 0x2, 0x2, 0x113, 0x114, 0x3, 
    0x2, 0x2, 0x2, 0x114, 0x119, 0x7, 0x10, 0x2, 0x2, 0x115, 0x116, 0x5, 
    0x2e, 0x18, 0x2, 0x116, 0x117, 0x5, 0x2c, 0x17, 0x2, 0x117, 0x119, 0x3, 
    0x2, 0x2, 0x2, 0x118, 0x10e, 0x3, 0x2, 0x2, 0x2, 0x118, 0x10f, 0x3, 
    0x2, 0x2, 0x2, 0x118, 0x115, 0x3, 0x2, 0x2, 0x2, 0x119, 0x2d, 0x3, 0x2, 
    0x2, 0x2, 0x11a, 0x11b, 0x9, 0x4, 0x2, 0x2, 0x11b, 0x2f, 0x3, 0x2, 0x2, 
    0x2, 0x11c, 0x121, 0x5, 0x24, 0x13, 0x2, 0x11d, 0x11e, 0x7, 0x4, 0x2, 
    0x2, 0x11e, 0x120, 0x5, 0x24, 0x13, 0x2, 0x11f, 0x11d, 0x3, 0x2, 0x2, 
    0x2, 0x120, 0x123, 0x3, 0x2, 0x2, 0x2, 0x121, 0x11f, 0x3, 0x2, 0x2, 
    0x2, 0x121, 0x122, 0x3, 0x2, 0x2, 0x2, 0x122, 0x31, 0x3, 0x2, 0x2, 0x2, 
    0x123, 0x121, 0x3, 0x2, 0x2, 0x2, 0x124, 0x125, 0x8, 0x1a, 0x1, 0x2, 
    0x125, 0x126, 0x5, 0x2c, 0x17, 0x2, 0x126, 0x12d, 0x3, 0x2, 0x2, 0x2, 
    0x127, 0x128, 0xc, 0x3, 0x2, 0x2, 0x128, 0x129, 0x5, 0x34, 0x1b, 0x2, 
    0x129, 0x12a, 0x5, 0x2c, 0x17, 0x2, 0x12a, 0x12c, 0x3, 0x2, 0x2, 0x2, 
    0x12b, 0x127, 0x3, 0x2, 0x2, 0x2, 0x12c, 0x12f, 0x3, 0x2, 0x2, 0x2, 
    0x12d, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x12d, 0x12e, 0x3, 0x2, 0x2, 0x2, 
    0x12e, 0x33, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x130, 
    0x131, 0x9, 0x5, 0x2, 0x2, 0x131, 0x35, 0x3, 0x2, 0x2, 0x2, 0x132, 0x133, 
    0x8, 0x1c, 0x1, 0x2, 0x133, 0x134, 0x5, 0x32, 0x1a, 0x2, 0x134, 0x13a, 
    0x3, 0x2, 0x2, 0x2, 0x135, 0x136, 0xc, 0x3, 0x2, 0x2, 0x136, 0x137, 
    0x9, 0x6, 0x2, 0x2, 0x137, 0x139, 0x5, 0x32, 0x1a, 0x2, 0x138, 0x135, 
    0x3, 0x2, 0x2, 0x2, 0x139, 0x13c, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x138, 
    0x3, 0x2, 0x2, 0x2, 0x13a, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x13b, 0x37, 0x3, 
    0x2, 0x2, 0x2, 0x13c, 0x13a, 0x3, 0x2, 0x2, 0x2, 0x13d, 0x13e, 0x8, 
    0x1d, 0x1, 0x2, 0x13e, 0x141, 0x5, 0x36, 0x1c, 0x2, 0x13f, 0x141, 0x7, 
    0x26, 0x2, 0x2, 0x140, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x140, 0x13f, 0x3, 
    0x2, 0x2, 0x2, 0x141, 0x147, 0x3, 0x2, 0x2, 0x2, 0x142, 0x143, 0xc, 
    0x4, 0x2, 0x2, 0x143, 0x144, 0x9, 0x7, 0x2, 0x2, 0x144, 0x146, 0x5, 
    0x36, 0x1c, 0x2, 0x145, 0x142, 0x3, 0x2, 0x2, 0x2, 0x146, 0x149, 0x3, 
    0x2, 0x2, 0x2, 0x147, 0x145, 0x3, 0x2, 0x2, 0x2, 0x147, 0x148, 0x3, 
    0x2, 0x2, 0x2, 0x148, 0x39, 0x3, 0x2, 0x2, 0x2, 0x149, 0x147, 0x3, 0x2, 
    0x2, 0x2, 0x14a, 0x14b, 0x8, 0x1e, 0x1, 0x2, 0x14b, 0x14c, 0x5, 0x38, 
    0x1d, 0x2, 0x14c, 0x152, 0x3, 0x2, 0x2, 0x2, 0x14d, 0x14e, 0xc, 0x3, 
    0x2, 0x2, 0x14e, 0x14f, 0x9, 0x8, 0x2, 0x2, 0x14f, 0x151, 0x5, 0x38, 
    0x1d, 0x2, 0x150, 0x14d, 0x3, 0x2, 0x2, 0x2, 0x151, 0x154, 0x3, 0x2, 
    0x2, 0x2, 0x152, 0x150, 0x3, 0x2, 0x2, 0x2, 0x152, 0x153, 0x3, 0x2, 
    0x2, 0x2, 0x153, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x154, 0x152, 0x3, 0x2, 0x2, 
    0x2, 0x155, 0x156, 0x8, 0x1f, 0x1, 0x2, 0x156, 0x157, 0x5, 0x3a, 0x1e, 
    0x2, 0x157, 0x15d, 0x3, 0x2, 0x2, 0x2, 0x158, 0x159, 0xc, 0x3, 0x2, 
    0x2, 0x159, 0x15a, 0x7, 0x24, 0x2, 0x2, 0x15a, 0x15c, 0x5, 0x3a, 0x1e, 
    0x2, 0x15b, 0x158, 0x3, 0x2, 0x2, 0x2, 0x15c, 0x15f, 0x3, 0x2, 0x2, 
    0x2, 0x15d, 0x15b, 0x3, 0x2, 0x2, 0x2, 0x15d, 0x15e, 0x3, 0x2, 0x2, 
    0x2, 0x15e, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x15f, 0x15d, 0x3, 0x2, 0x2, 0x2, 
    0x160, 0x161, 0x8, 0x20, 0x1, 0x2, 0x161, 0x162, 0x5, 0x3c, 0x1f, 0x2, 
    0x162, 0x168, 0x3, 0x2, 0x2, 0x2, 0x163, 0x164, 0xc, 0x3, 0x2, 0x2, 
    0x164, 0x165, 0x7, 0x25, 0x2, 0x2, 0x165, 0x167, 0x5, 0x3c, 0x1f, 0x2, 
    0x166, 0x163, 0x3, 0x2, 0x2, 0x2, 0x167, 0x16a, 0x3, 0x2, 0x2, 0x2, 
    0x168, 0x166, 0x3, 0x2, 0x2, 0x2, 0x168, 0x169, 0x3, 0x2, 0x2, 0x2, 
    0x169, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x16a, 0x168, 0x3, 0x2, 0x2, 0x2, 0x16b, 
    0x16e, 0x5, 0x42, 0x22, 0x2, 0x16c, 0x16e, 0x7, 0x26, 0x2, 0x2, 0x16d, 
    0x16b, 0x3, 0x2, 0x2, 0x2, 0x16d, 0x16c, 0x3, 0x2, 0x2, 0x2, 0x16e, 
    0x41, 0x3, 0x2, 0x2, 0x2, 0x16f, 0x173, 0x7, 0x28, 0x2, 0x2, 0x170, 
    0x173, 0x7, 0x2b, 0x2, 0x2, 0x171, 0x173, 0x7, 0x2a, 0x2, 0x2, 0x172, 
    0x16f, 0x3, 0x2, 0x2, 0x2, 0x172, 0x170, 0x3, 0x2, 0x2, 0x2, 0x172, 
    0x171, 0x3, 0x2, 0x2, 0x2, 0x173, 0x43, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x46, 
    0x48, 0x4e, 0x57, 0x62, 0x68, 0x70, 0x73, 0x76, 0x7e, 0x87, 0x8b, 0x91, 
    0x9d, 0xa3, 0xac, 0xb3, 0xbb, 0xc6, 0xd0, 0xd3, 0xdb, 0xe6, 0xf4, 0xf7, 
    0xfb, 0x104, 0x10c, 0x112, 0x118, 0x121, 0x12d, 0x13a, 0x140, 0x147, 
    0x152, 0x15d, 0x168, 0x16d, 0x172, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

CACTParser::Initializer CACTParser::_init;
