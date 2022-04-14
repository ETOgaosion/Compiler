
    #include <vector>
    #include <string>


// Generated from CACT.g4 by ANTLR 4.8


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
    setState(62); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(62);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
      case 1: {
        setState(60);
        decl();
        break;
      }

      case 2: {
        setState(61);
        funcDef();
        break;
      }

      }
      setState(64); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CACTParser::T__0)
      | (1ULL << CACTParser::T__3)
      | (1ULL << CACTParser::T__4)
      | (1ULL << CACTParser::T__5)
      | (1ULL << CACTParser::T__6)
      | (1ULL << CACTParser::T__14))) != 0));
    setState(66);
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
    setState(70);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::T__0: {
        enterOuterAlt(_localctx, 1);
        setState(68);
        constDecl();
        break;
      }

      case CACTParser::T__3:
      case CACTParser::T__4:
      case CACTParser::T__5:
      case CACTParser::T__6: {
        enterOuterAlt(_localctx, 2);
        setState(69);
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
    setState(72);
    match(CACTParser::T__0);
    setState(73);
    bType();
    setState(74);
    constDef();
    setState(79);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CACTParser::T__1) {
      setState(75);
      match(CACTParser::T__1);
      setState(76);
      constDef();
      setState(81);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(82);
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
    setState(84);
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
    setState(86);
    match(CACTParser::Ident);
    setState(90);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CACTParser::T__7) {
      setState(87);
      match(CACTParser::T__7);
      setState(88);
      match(CACTParser::IntConst);
      setState(89);
      match(CACTParser::T__8);
    }
    setState(92);
    match(CACTParser::T__9);
    setState(93);
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

std::vector<CACTParser::ConstExpContext *> CACTParser::ConstInitValContext::constExp() {
  return getRuleContexts<CACTParser::ConstExpContext>();
}

CACTParser::ConstExpContext* CACTParser::ConstInitValContext::constExp(size_t i) {
  return getRuleContext<CACTParser::ConstExpContext>(i);
}


size_t CACTParser::ConstInitValContext::getRuleIndex() const {
  return CACTParser::RuleConstInitVal;
}

void CACTParser::ConstInitValContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstInitVal(this);
}

void CACTParser::ConstInitValContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstInitVal(this);
}

CACTParser::ConstInitValContext* CACTParser::constInitVal() {
  ConstInitValContext *_localctx = _tracker.createInstance<ConstInitValContext>(_ctx, getState());
  enterRule(_localctx, 10, CACTParser::RuleConstInitVal);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(108);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::BoolConst:
      case CACTParser::IntConst:
      case CACTParser::FloatConst:
      case CACTParser::DoubleConst: {
        enterOuterAlt(_localctx, 1);
        setState(95);
        constExp();
        break;
      }

      case CACTParser::T__10: {
        enterOuterAlt(_localctx, 2);
        setState(96);
        match(CACTParser::T__10);
        setState(105);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << CACTParser::BoolConst)
          | (1ULL << CACTParser::IntConst)
          | (1ULL << CACTParser::FloatConst)
          | (1ULL << CACTParser::DoubleConst))) != 0)) {
          setState(97);
          constExp();
          setState(102);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == CACTParser::T__1) {
            setState(98);
            match(CACTParser::T__1);
            setState(99);
            constExp();
            setState(104);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
        }
        setState(107);
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
    setState(110);
    bType();
    setState(111);
    varDef();
    setState(116);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CACTParser::T__1) {
      setState(112);
      match(CACTParser::T__1);
      setState(113);
      varDef();
      setState(118);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(119);
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
    setState(121);
    match(CACTParser::Ident);
    setState(125);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CACTParser::T__7) {
      setState(122);
      match(CACTParser::T__7);
      setState(123);
      match(CACTParser::IntConst);
      setState(124);
      match(CACTParser::T__8);
    }
    setState(129);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CACTParser::T__9) {
      setState(127);
      match(CACTParser::T__9);
      setState(128);
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
    setState(131);
    funcType();
    setState(132);
    match(CACTParser::Ident);
    setState(133);
    match(CACTParser::T__12);
    setState(135);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CACTParser::T__3)
      | (1ULL << CACTParser::T__4)
      | (1ULL << CACTParser::T__5)
      | (1ULL << CACTParser::T__6))) != 0)) {
      setState(134);
      funcFParams();
    }
    setState(137);
    match(CACTParser::T__13);
    setState(138);
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
    setState(140);
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
    setState(142);
    funcFParam();
    setState(147);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CACTParser::T__1) {
      setState(143);
      match(CACTParser::T__1);
      setState(144);
      funcFParam();
      setState(149);
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
    setState(150);
    bType();
    setState(151);
    match(CACTParser::Ident);
    setState(154);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CACTParser::T__7) {
      setState(152);
      match(CACTParser::T__7);
      setState(153);
      match(CACTParser::T__8);
    }
   
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
  enterRule(_localctx, 24, CACTParser::RuleBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(156);
    match(CACTParser::T__10);
    setState(160);
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
      | (1ULL << CACTParser::T__19)
      | (1ULL << CACTParser::T__20)
      | (1ULL << CACTParser::T__21)
      | (1ULL << CACTParser::T__22)
      | (1ULL << CACTParser::T__23)
      | (1ULL << CACTParser::BoolConst)
      | (1ULL << CACTParser::Ident)
      | (1ULL << CACTParser::IntConst)
      | (1ULL << CACTParser::FloatConst)
      | (1ULL << CACTParser::DoubleConst))) != 0)) {
      setState(157);
      blockItem();
      setState(162);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(163);
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
  enterRule(_localctx, 26, CACTParser::RuleBlockItem);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(167);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::T__0:
      case CACTParser::T__3:
      case CACTParser::T__4:
      case CACTParser::T__5:
      case CACTParser::T__6: {
        enterOuterAlt(_localctx, 1);
        setState(165);
        decl();
        break;
      }

      case CACTParser::T__2:
      case CACTParser::T__10:
      case CACTParser::T__12:
      case CACTParser::T__15:
      case CACTParser::T__17:
      case CACTParser::T__18:
      case CACTParser::T__19:
      case CACTParser::T__20:
      case CACTParser::T__21:
      case CACTParser::T__22:
      case CACTParser::T__23:
      case CACTParser::BoolConst:
      case CACTParser::Ident:
      case CACTParser::IntConst:
      case CACTParser::FloatConst:
      case CACTParser::DoubleConst: {
        enterOuterAlt(_localctx, 2);
        setState(166);
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

CACTParser::LValContext* CACTParser::StmtContext::lVal() {
  return getRuleContext<CACTParser::LValContext>(0);
}

CACTParser::ExpContext* CACTParser::StmtContext::exp() {
  return getRuleContext<CACTParser::ExpContext>(0);
}

CACTParser::BlockContext* CACTParser::StmtContext::block() {
  return getRuleContext<CACTParser::BlockContext>(0);
}

CACTParser::CondContext* CACTParser::StmtContext::cond() {
  return getRuleContext<CACTParser::CondContext>(0);
}

std::vector<CACTParser::StmtContext *> CACTParser::StmtContext::stmt() {
  return getRuleContexts<CACTParser::StmtContext>();
}

CACTParser::StmtContext* CACTParser::StmtContext::stmt(size_t i) {
  return getRuleContext<CACTParser::StmtContext>(i);
}


size_t CACTParser::StmtContext::getRuleIndex() const {
  return CACTParser::RuleStmt;
}

void CACTParser::StmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmt(this);
}

void CACTParser::StmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmt(this);
}

CACTParser::StmtContext* CACTParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 28, CACTParser::RuleStmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(203);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(169);
      lVal();
      setState(170);
      match(CACTParser::T__9);
      setState(171);
      exp();
      setState(172);
      match(CACTParser::T__2);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(175);
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
        setState(174);
        exp();
      }
      setState(177);
      match(CACTParser::T__2);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(178);
      block();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(179);
      match(CACTParser::T__15);
      setState(180);
      match(CACTParser::T__12);
      setState(181);
      cond();
      setState(182);
      match(CACTParser::T__13);
      setState(183);
      stmt();
      setState(186);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
      case 1: {
        setState(184);
        match(CACTParser::T__16);
        setState(185);
        stmt();
        break;
      }

      }
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(188);
      match(CACTParser::T__17);
      setState(189);
      match(CACTParser::T__12);
      setState(190);
      cond();
      setState(191);
      match(CACTParser::T__13);
      setState(192);
      stmt();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(194);
      match(CACTParser::T__18);
      setState(195);
      match(CACTParser::T__2);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(196);
      match(CACTParser::T__19);
      setState(197);
      match(CACTParser::T__2);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(198);
      match(CACTParser::T__20);
      setState(200);
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
        setState(199);
        exp();
      }
      setState(202);
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

CACTParser::AddExpContext* CACTParser::ExpContext::addExp() {
  return getRuleContext<CACTParser::AddExpContext>(0);
}

tree::TerminalNode* CACTParser::ExpContext::BoolConst() {
  return getToken(CACTParser::BoolConst, 0);
}


size_t CACTParser::ExpContext::getRuleIndex() const {
  return CACTParser::RuleExp;
}

void CACTParser::ExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExp(this);
}

void CACTParser::ExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExp(this);
}

CACTParser::ExpContext* CACTParser::exp() {
  ExpContext *_localctx = _tracker.createInstance<ExpContext>(_ctx, getState());
  enterRule(_localctx, 30, CACTParser::RuleExp);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(207);
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
        enterOuterAlt(_localctx, 1);
        setState(205);
        addExp();
        break;
      }

      case CACTParser::BoolConst: {
        enterOuterAlt(_localctx, 2);
        setState(206);
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
  enterRule(_localctx, 32, CACTParser::RuleCond);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(209);
    lOrExp();
   
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
  enterRule(_localctx, 34, CACTParser::RuleLVal);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(211);
    match(CACTParser::Ident);
    setState(216);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CACTParser::T__7) {
      setState(212);
      match(CACTParser::T__7);
      setState(213);
      exp();
      setState(214);
      match(CACTParser::T__8);
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

CACTParser::ExpContext* CACTParser::PrimaryExpContext::exp() {
  return getRuleContext<CACTParser::ExpContext>(0);
}

CACTParser::LValContext* CACTParser::PrimaryExpContext::lVal() {
  return getRuleContext<CACTParser::LValContext>(0);
}

CACTParser::NumberContext* CACTParser::PrimaryExpContext::number() {
  return getRuleContext<CACTParser::NumberContext>(0);
}


size_t CACTParser::PrimaryExpContext::getRuleIndex() const {
  return CACTParser::RulePrimaryExp;
}

void CACTParser::PrimaryExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimaryExp(this);
}

void CACTParser::PrimaryExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimaryExp(this);
}

CACTParser::PrimaryExpContext* CACTParser::primaryExp() {
  PrimaryExpContext *_localctx = _tracker.createInstance<PrimaryExpContext>(_ctx, getState());
  enterRule(_localctx, 36, CACTParser::RulePrimaryExp);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(224);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::T__12: {
        enterOuterAlt(_localctx, 1);
        setState(218);
        match(CACTParser::T__12);
        setState(219);
        exp();
        setState(220);
        match(CACTParser::T__13);
        break;
      }

      case CACTParser::Ident: {
        enterOuterAlt(_localctx, 2);
        setState(222);
        lVal();
        break;
      }

      case CACTParser::IntConst:
      case CACTParser::FloatConst:
      case CACTParser::DoubleConst: {
        enterOuterAlt(_localctx, 3);
        setState(223);
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

CACTParser::PrimaryExpContext* CACTParser::UnaryExpContext::primaryExp() {
  return getRuleContext<CACTParser::PrimaryExpContext>(0);
}

tree::TerminalNode* CACTParser::UnaryExpContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

CACTParser::FuncRParamsContext* CACTParser::UnaryExpContext::funcRParams() {
  return getRuleContext<CACTParser::FuncRParamsContext>(0);
}

CACTParser::UnaryOpContext* CACTParser::UnaryExpContext::unaryOp() {
  return getRuleContext<CACTParser::UnaryOpContext>(0);
}

CACTParser::UnaryExpContext* CACTParser::UnaryExpContext::unaryExp() {
  return getRuleContext<CACTParser::UnaryExpContext>(0);
}


size_t CACTParser::UnaryExpContext::getRuleIndex() const {
  return CACTParser::RuleUnaryExp;
}

void CACTParser::UnaryExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryExp(this);
}

void CACTParser::UnaryExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryExp(this);
}

CACTParser::UnaryExpContext* CACTParser::unaryExp() {
  UnaryExpContext *_localctx = _tracker.createInstance<UnaryExpContext>(_ctx, getState());
  enterRule(_localctx, 38, CACTParser::RuleUnaryExp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(236);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(226);
      primaryExp();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(227);
      match(CACTParser::Ident);
      setState(228);
      match(CACTParser::T__12);
      setState(230);
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
        setState(229);
        funcRParams();
      }
      setState(232);
      match(CACTParser::T__13);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(233);
      unaryOp();
      setState(234);
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
  enterRule(_localctx, 40, CACTParser::RuleUnaryOp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(238);
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
  enterRule(_localctx, 42, CACTParser::RuleFuncRParams);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(240);
    exp();
    setState(245);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CACTParser::T__1) {
      setState(241);
      match(CACTParser::T__1);
      setState(242);
      exp();
      setState(247);
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

std::vector<CACTParser::UnaryExpContext *> CACTParser::MulExpContext::unaryExp() {
  return getRuleContexts<CACTParser::UnaryExpContext>();
}

CACTParser::UnaryExpContext* CACTParser::MulExpContext::unaryExp(size_t i) {
  return getRuleContext<CACTParser::UnaryExpContext>(i);
}


size_t CACTParser::MulExpContext::getRuleIndex() const {
  return CACTParser::RuleMulExp;
}

void CACTParser::MulExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMulExp(this);
}

void CACTParser::MulExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMulExp(this);
}

CACTParser::MulExpContext* CACTParser::mulExp() {
  MulExpContext *_localctx = _tracker.createInstance<MulExpContext>(_ctx, getState());
  enterRule(_localctx, 44, CACTParser::RuleMulExp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(248);
    unaryExp();
    setState(253);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CACTParser::T__24)
      | (1ULL << CACTParser::T__25)
      | (1ULL << CACTParser::T__26))) != 0)) {
      setState(249);
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
      setState(250);
      unaryExp();
      setState(255);
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

//----------------- AddExpContext ------------------------------------------------------------------

CACTParser::AddExpContext::AddExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CACTParser::MulExpContext *> CACTParser::AddExpContext::mulExp() {
  return getRuleContexts<CACTParser::MulExpContext>();
}

CACTParser::MulExpContext* CACTParser::AddExpContext::mulExp(size_t i) {
  return getRuleContext<CACTParser::MulExpContext>(i);
}


size_t CACTParser::AddExpContext::getRuleIndex() const {
  return CACTParser::RuleAddExp;
}

void CACTParser::AddExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAddExp(this);
}

void CACTParser::AddExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAddExp(this);
}

CACTParser::AddExpContext* CACTParser::addExp() {
  AddExpContext *_localctx = _tracker.createInstance<AddExpContext>(_ctx, getState());
  enterRule(_localctx, 46, CACTParser::RuleAddExp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(256);
    mulExp();
    setState(261);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CACTParser::T__21

    || _la == CACTParser::T__22) {
      setState(257);
      _la = _input->LA(1);
      if (!(_la == CACTParser::T__21

      || _la == CACTParser::T__22)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(258);
      mulExp();
      setState(263);
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

//----------------- RelExpContext ------------------------------------------------------------------

CACTParser::RelExpContext::RelExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CACTParser::AddExpContext *> CACTParser::RelExpContext::addExp() {
  return getRuleContexts<CACTParser::AddExpContext>();
}

CACTParser::AddExpContext* CACTParser::RelExpContext::addExp(size_t i) {
  return getRuleContext<CACTParser::AddExpContext>(i);
}

tree::TerminalNode* CACTParser::RelExpContext::BoolConst() {
  return getToken(CACTParser::BoolConst, 0);
}


size_t CACTParser::RelExpContext::getRuleIndex() const {
  return CACTParser::RuleRelExp;
}

void CACTParser::RelExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelExp(this);
}

void CACTParser::RelExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelExp(this);
}

CACTParser::RelExpContext* CACTParser::relExp() {
  RelExpContext *_localctx = _tracker.createInstance<RelExpContext>(_ctx, getState());
  enterRule(_localctx, 48, CACTParser::RuleRelExp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(273);
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
        enterOuterAlt(_localctx, 1);
        setState(264);
        addExp();
        setState(269);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << CACTParser::T__27)
          | (1ULL << CACTParser::T__28)
          | (1ULL << CACTParser::T__29)
          | (1ULL << CACTParser::T__30))) != 0)) {
          setState(265);
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
          setState(266);
          addExp();
          setState(271);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case CACTParser::BoolConst: {
        enterOuterAlt(_localctx, 2);
        setState(272);
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

//----------------- EqExpContext ------------------------------------------------------------------

CACTParser::EqExpContext::EqExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CACTParser::RelExpContext *> CACTParser::EqExpContext::relExp() {
  return getRuleContexts<CACTParser::RelExpContext>();
}

CACTParser::RelExpContext* CACTParser::EqExpContext::relExp(size_t i) {
  return getRuleContext<CACTParser::RelExpContext>(i);
}


size_t CACTParser::EqExpContext::getRuleIndex() const {
  return CACTParser::RuleEqExp;
}

void CACTParser::EqExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEqExp(this);
}

void CACTParser::EqExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEqExp(this);
}

CACTParser::EqExpContext* CACTParser::eqExp() {
  EqExpContext *_localctx = _tracker.createInstance<EqExpContext>(_ctx, getState());
  enterRule(_localctx, 50, CACTParser::RuleEqExp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(275);
    relExp();
    setState(280);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CACTParser::T__31

    || _la == CACTParser::T__32) {
      setState(276);
      _la = _input->LA(1);
      if (!(_la == CACTParser::T__31

      || _la == CACTParser::T__32)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(277);
      relExp();
      setState(282);
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

//----------------- LAndExpContext ------------------------------------------------------------------

CACTParser::LAndExpContext::LAndExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CACTParser::EqExpContext *> CACTParser::LAndExpContext::eqExp() {
  return getRuleContexts<CACTParser::EqExpContext>();
}

CACTParser::EqExpContext* CACTParser::LAndExpContext::eqExp(size_t i) {
  return getRuleContext<CACTParser::EqExpContext>(i);
}


size_t CACTParser::LAndExpContext::getRuleIndex() const {
  return CACTParser::RuleLAndExp;
}

void CACTParser::LAndExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLAndExp(this);
}

void CACTParser::LAndExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLAndExp(this);
}

CACTParser::LAndExpContext* CACTParser::lAndExp() {
  LAndExpContext *_localctx = _tracker.createInstance<LAndExpContext>(_ctx, getState());
  enterRule(_localctx, 52, CACTParser::RuleLAndExp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(283);
    eqExp();
    setState(288);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CACTParser::T__33) {
      setState(284);
      match(CACTParser::T__33);
      setState(285);
      eqExp();
      setState(290);
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

//----------------- LOrExpContext ------------------------------------------------------------------

CACTParser::LOrExpContext::LOrExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CACTParser::LAndExpContext *> CACTParser::LOrExpContext::lAndExp() {
  return getRuleContexts<CACTParser::LAndExpContext>();
}

CACTParser::LAndExpContext* CACTParser::LOrExpContext::lAndExp(size_t i) {
  return getRuleContext<CACTParser::LAndExpContext>(i);
}


size_t CACTParser::LOrExpContext::getRuleIndex() const {
  return CACTParser::RuleLOrExp;
}

void CACTParser::LOrExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLOrExp(this);
}

void CACTParser::LOrExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLOrExp(this);
}

CACTParser::LOrExpContext* CACTParser::lOrExp() {
  LOrExpContext *_localctx = _tracker.createInstance<LOrExpContext>(_ctx, getState());
  enterRule(_localctx, 54, CACTParser::RuleLOrExp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(291);
    lAndExp();
    setState(296);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CACTParser::T__34) {
      setState(292);
      match(CACTParser::T__34);
      setState(293);
      lAndExp();
      setState(298);
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

//----------------- ConstExpContext ------------------------------------------------------------------

CACTParser::ConstExpContext::ConstExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::ConstExpContext::getRuleIndex() const {
  return CACTParser::RuleConstExp;
}

void CACTParser::ConstExpContext::copyFrom(ConstExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->basic_or_array_and_type = ctx->basic_or_array_and_type;
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
  enterRule(_localctx, 56, CACTParser::RuleConstExp);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(301);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::IntConst:
      case CACTParser::FloatConst:
      case CACTParser::DoubleConst: {
        _localctx = dynamic_cast<ConstExpContext *>(_tracker.createInstance<CACTParser::ConstExpNumberContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(299);
        number();
        break;
      }

      case CACTParser::BoolConst: {
        _localctx = dynamic_cast<ConstExpContext *>(_tracker.createInstance<CACTParser::ConstExpBoolConstContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(300);
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

tree::TerminalNode* CACTParser::NumberContext::IntConst() {
  return getToken(CACTParser::IntConst, 0);
}

tree::TerminalNode* CACTParser::NumberContext::DoubleConst() {
  return getToken(CACTParser::DoubleConst, 0);
}

tree::TerminalNode* CACTParser::NumberContext::FloatConst() {
  return getToken(CACTParser::FloatConst, 0);
}


size_t CACTParser::NumberContext::getRuleIndex() const {
  return CACTParser::RuleNumber;
}

void CACTParser::NumberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumber(this);
}

void CACTParser::NumberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumber(this);
}

CACTParser::NumberContext* CACTParser::number() {
  NumberContext *_localctx = _tracker.createInstance<NumberContext>(_ctx, getState());
  enterRule(_localctx, 58, CACTParser::RuleNumber);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(303);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CACTParser::IntConst)
      | (1ULL << CACTParser::FloatConst)
      | (1ULL << CACTParser::DoubleConst))) != 0))) {
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

// Static vars and initialization.
std::vector<dfa::DFA> CACTParser::_decisionToDFA;
atn::PredictionContextCache CACTParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN CACTParser::_atn;
std::vector<uint16_t> CACTParser::_serializedATN;

std::vector<std::string> CACTParser::_ruleNames = {
  "compUnit", "decl", "constDecl", "bType", "constDef", "constInitVal", 
  "varDecl", "varDef", "funcDef", "funcType", "funcFParams", "funcFParam", 
  "block", "blockItem", "stmt", "exp", "cond", "lVal", "primaryExp", "unaryExp", 
  "unaryOp", "funcRParams", "mulExp", "addExp", "relExp", "eqExp", "lAndExp", 
  "lOrExp", "constExp", "number"
};

std::vector<std::string> CACTParser::_literalNames = {
  "", "'const'", "','", "';'", "'int'", "'bool'", "'double'", "'float'", 
  "'['", "']'", "'='", "'{'", "'}'", "'('", "')'", "'void'", "'if'", "'else'", 
  "'while'", "'break'", "'contine'", "'return'", "'+'", "'-'", "'!'", "'*'", 
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
    0x3, 0x2f, 0x134, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x3, 0x2, 0x3, 0x2, 0x6, 0x2, 0x41, 0xa, 0x2, 0xd, 
    0x2, 0xe, 0x2, 0x42, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 
    0x49, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 
    0x4, 0x50, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x53, 0xb, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 
    0x6, 0x5d, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0x67, 0xa, 0x7, 0xc, 0x7, 0xe, 
    0x7, 0x6a, 0xb, 0x7, 0x5, 0x7, 0x6c, 0xa, 0x7, 0x3, 0x7, 0x5, 0x7, 0x6f, 
    0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x7, 0x8, 0x75, 0xa, 
    0x8, 0xc, 0x8, 0xe, 0x8, 0x78, 0xb, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x80, 0xa, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x5, 0x9, 0x84, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x5, 0xa, 0x8a, 0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0x94, 0xa, 0xc, 0xc, 0xc, 
    0xe, 0xc, 0x97, 0xb, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 
    0xd, 0x9d, 0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 0x7, 0xe, 0xa1, 0xa, 0xe, 0xc, 
    0xe, 0xe, 0xe, 0xa4, 0xb, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 
    0x5, 0xf, 0xaa, 0xa, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0xb2, 0xa, 0x10, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 
    0x10, 0x5, 0x10, 0xbd, 0xa, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0xcb, 0xa, 0x10, 0x3, 0x10, 0x5, 0x10, 
    0xce, 0xa, 0x10, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0xd2, 0xa, 0x11, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 
    0x5, 0x13, 0xdb, 0xa, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0xe3, 0xa, 0x14, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 0xe9, 0xa, 0x15, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 0xef, 0xa, 0x15, 0x3, 0x16, 0x3, 0x16, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x7, 0x17, 0xf6, 0xa, 0x17, 0xc, 0x17, 
    0xe, 0x17, 0xf9, 0xb, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x7, 0x18, 
    0xfe, 0xa, 0x18, 0xc, 0x18, 0xe, 0x18, 0x101, 0xb, 0x18, 0x3, 0x19, 
    0x3, 0x19, 0x3, 0x19, 0x7, 0x19, 0x106, 0xa, 0x19, 0xc, 0x19, 0xe, 0x19, 
    0x109, 0xb, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x7, 0x1a, 0x10e, 
    0xa, 0x1a, 0xc, 0x1a, 0xe, 0x1a, 0x111, 0xb, 0x1a, 0x3, 0x1a, 0x5, 0x1a, 
    0x114, 0xa, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x7, 0x1b, 0x119, 
    0xa, 0x1b, 0xc, 0x1b, 0xe, 0x1b, 0x11c, 0xb, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 
    0x3, 0x1c, 0x7, 0x1c, 0x121, 0xa, 0x1c, 0xc, 0x1c, 0xe, 0x1c, 0x124, 
    0xb, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x7, 0x1d, 0x129, 0xa, 0x1d, 
    0xc, 0x1d, 0xe, 0x1d, 0x12c, 0xb, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x5, 0x1e, 
    0x130, 0xa, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x2, 0x2, 0x20, 0x2, 
    0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 
    0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 
    0x36, 0x38, 0x3a, 0x3c, 0x2, 0xa, 0x3, 0x2, 0x6, 0x9, 0x4, 0x2, 0x6, 
    0x9, 0x11, 0x11, 0x3, 0x2, 0x18, 0x1a, 0x3, 0x2, 0x1b, 0x1d, 0x3, 0x2, 
    0x18, 0x19, 0x3, 0x2, 0x1e, 0x21, 0x3, 0x2, 0x22, 0x23, 0x4, 0x2, 0x28, 
    0x28, 0x2a, 0x2b, 0x2, 0x13f, 0x2, 0x40, 0x3, 0x2, 0x2, 0x2, 0x4, 0x48, 
    0x3, 0x2, 0x2, 0x2, 0x6, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x8, 0x56, 0x3, 0x2, 
    0x2, 0x2, 0xa, 0x58, 0x3, 0x2, 0x2, 0x2, 0xc, 0x6e, 0x3, 0x2, 0x2, 0x2, 
    0xe, 0x70, 0x3, 0x2, 0x2, 0x2, 0x10, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x12, 
    0x85, 0x3, 0x2, 0x2, 0x2, 0x14, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x16, 0x90, 
    0x3, 0x2, 0x2, 0x2, 0x18, 0x98, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x9e, 0x3, 
    0x2, 0x2, 0x2, 0x1c, 0xa9, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xcd, 0x3, 0x2, 
    0x2, 0x2, 0x20, 0xd1, 0x3, 0x2, 0x2, 0x2, 0x22, 0xd3, 0x3, 0x2, 0x2, 
    0x2, 0x24, 0xd5, 0x3, 0x2, 0x2, 0x2, 0x26, 0xe2, 0x3, 0x2, 0x2, 0x2, 
    0x28, 0xee, 0x3, 0x2, 0x2, 0x2, 0x2a, 0xf0, 0x3, 0x2, 0x2, 0x2, 0x2c, 
    0xf2, 0x3, 0x2, 0x2, 0x2, 0x2e, 0xfa, 0x3, 0x2, 0x2, 0x2, 0x30, 0x102, 
    0x3, 0x2, 0x2, 0x2, 0x32, 0x113, 0x3, 0x2, 0x2, 0x2, 0x34, 0x115, 0x3, 
    0x2, 0x2, 0x2, 0x36, 0x11d, 0x3, 0x2, 0x2, 0x2, 0x38, 0x125, 0x3, 0x2, 
    0x2, 0x2, 0x3a, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x131, 0x3, 0x2, 0x2, 
    0x2, 0x3e, 0x41, 0x5, 0x4, 0x3, 0x2, 0x3f, 0x41, 0x5, 0x12, 0xa, 0x2, 
    0x40, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x40, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x41, 
    0x42, 0x3, 0x2, 0x2, 0x2, 0x42, 0x40, 0x3, 0x2, 0x2, 0x2, 0x42, 0x43, 
    0x3, 0x2, 0x2, 0x2, 0x43, 0x44, 0x3, 0x2, 0x2, 0x2, 0x44, 0x45, 0x7, 
    0x2, 0x2, 0x3, 0x45, 0x3, 0x3, 0x2, 0x2, 0x2, 0x46, 0x49, 0x5, 0x6, 
    0x4, 0x2, 0x47, 0x49, 0x5, 0xe, 0x8, 0x2, 0x48, 0x46, 0x3, 0x2, 0x2, 
    0x2, 0x48, 0x47, 0x3, 0x2, 0x2, 0x2, 0x49, 0x5, 0x3, 0x2, 0x2, 0x2, 
    0x4a, 0x4b, 0x7, 0x3, 0x2, 0x2, 0x4b, 0x4c, 0x5, 0x8, 0x5, 0x2, 0x4c, 
    0x51, 0x5, 0xa, 0x6, 0x2, 0x4d, 0x4e, 0x7, 0x4, 0x2, 0x2, 0x4e, 0x50, 
    0x5, 0xa, 0x6, 0x2, 0x4f, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x50, 0x53, 0x3, 
    0x2, 0x2, 0x2, 0x51, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x51, 0x52, 0x3, 0x2, 
    0x2, 0x2, 0x52, 0x54, 0x3, 0x2, 0x2, 0x2, 0x53, 0x51, 0x3, 0x2, 0x2, 
    0x2, 0x54, 0x55, 0x7, 0x5, 0x2, 0x2, 0x55, 0x7, 0x3, 0x2, 0x2, 0x2, 
    0x56, 0x57, 0x9, 0x2, 0x2, 0x2, 0x57, 0x9, 0x3, 0x2, 0x2, 0x2, 0x58, 
    0x5c, 0x7, 0x27, 0x2, 0x2, 0x59, 0x5a, 0x7, 0xa, 0x2, 0x2, 0x5a, 0x5b, 
    0x7, 0x28, 0x2, 0x2, 0x5b, 0x5d, 0x7, 0xb, 0x2, 0x2, 0x5c, 0x59, 0x3, 
    0x2, 0x2, 0x2, 0x5c, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x5e, 0x3, 0x2, 
    0x2, 0x2, 0x5e, 0x5f, 0x7, 0xc, 0x2, 0x2, 0x5f, 0x60, 0x5, 0xc, 0x7, 
    0x2, 0x60, 0xb, 0x3, 0x2, 0x2, 0x2, 0x61, 0x6f, 0x5, 0x3a, 0x1e, 0x2, 
    0x62, 0x6b, 0x7, 0xd, 0x2, 0x2, 0x63, 0x68, 0x5, 0x3a, 0x1e, 0x2, 0x64, 
    0x65, 0x7, 0x4, 0x2, 0x2, 0x65, 0x67, 0x5, 0x3a, 0x1e, 0x2, 0x66, 0x64, 
    0x3, 0x2, 0x2, 0x2, 0x67, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x68, 0x66, 0x3, 
    0x2, 0x2, 0x2, 0x68, 0x69, 0x3, 0x2, 0x2, 0x2, 0x69, 0x6c, 0x3, 0x2, 
    0x2, 0x2, 0x6a, 0x68, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x63, 0x3, 0x2, 0x2, 
    0x2, 0x6b, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6d, 0x3, 0x2, 0x2, 0x2, 
    0x6d, 0x6f, 0x7, 0xe, 0x2, 0x2, 0x6e, 0x61, 0x3, 0x2, 0x2, 0x2, 0x6e, 
    0x62, 0x3, 0x2, 0x2, 0x2, 0x6f, 0xd, 0x3, 0x2, 0x2, 0x2, 0x70, 0x71, 
    0x5, 0x8, 0x5, 0x2, 0x71, 0x76, 0x5, 0x10, 0x9, 0x2, 0x72, 0x73, 0x7, 
    0x4, 0x2, 0x2, 0x73, 0x75, 0x5, 0x10, 0x9, 0x2, 0x74, 0x72, 0x3, 0x2, 
    0x2, 0x2, 0x75, 0x78, 0x3, 0x2, 0x2, 0x2, 0x76, 0x74, 0x3, 0x2, 0x2, 
    0x2, 0x76, 0x77, 0x3, 0x2, 0x2, 0x2, 0x77, 0x79, 0x3, 0x2, 0x2, 0x2, 
    0x78, 0x76, 0x3, 0x2, 0x2, 0x2, 0x79, 0x7a, 0x7, 0x5, 0x2, 0x2, 0x7a, 
    0xf, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x7f, 0x7, 0x27, 0x2, 0x2, 0x7c, 0x7d, 
    0x7, 0xa, 0x2, 0x2, 0x7d, 0x7e, 0x7, 0x28, 0x2, 0x2, 0x7e, 0x80, 0x7, 
    0xb, 0x2, 0x2, 0x7f, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x80, 0x3, 0x2, 
    0x2, 0x2, 0x80, 0x83, 0x3, 0x2, 0x2, 0x2, 0x81, 0x82, 0x7, 0xc, 0x2, 
    0x2, 0x82, 0x84, 0x5, 0xc, 0x7, 0x2, 0x83, 0x81, 0x3, 0x2, 0x2, 0x2, 
    0x83, 0x84, 0x3, 0x2, 0x2, 0x2, 0x84, 0x11, 0x3, 0x2, 0x2, 0x2, 0x85, 
    0x86, 0x5, 0x14, 0xb, 0x2, 0x86, 0x87, 0x7, 0x27, 0x2, 0x2, 0x87, 0x89, 
    0x7, 0xf, 0x2, 0x2, 0x88, 0x8a, 0x5, 0x16, 0xc, 0x2, 0x89, 0x88, 0x3, 
    0x2, 0x2, 0x2, 0x89, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x8b, 0x3, 0x2, 
    0x2, 0x2, 0x8b, 0x8c, 0x7, 0x10, 0x2, 0x2, 0x8c, 0x8d, 0x5, 0x1a, 0xe, 
    0x2, 0x8d, 0x13, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x8f, 0x9, 0x3, 0x2, 0x2, 
    0x8f, 0x15, 0x3, 0x2, 0x2, 0x2, 0x90, 0x95, 0x5, 0x18, 0xd, 0x2, 0x91, 
    0x92, 0x7, 0x4, 0x2, 0x2, 0x92, 0x94, 0x5, 0x18, 0xd, 0x2, 0x93, 0x91, 
    0x3, 0x2, 0x2, 0x2, 0x94, 0x97, 0x3, 0x2, 0x2, 0x2, 0x95, 0x93, 0x3, 
    0x2, 0x2, 0x2, 0x95, 0x96, 0x3, 0x2, 0x2, 0x2, 0x96, 0x17, 0x3, 0x2, 
    0x2, 0x2, 0x97, 0x95, 0x3, 0x2, 0x2, 0x2, 0x98, 0x99, 0x5, 0x8, 0x5, 
    0x2, 0x99, 0x9c, 0x7, 0x27, 0x2, 0x2, 0x9a, 0x9b, 0x7, 0xa, 0x2, 0x2, 
    0x9b, 0x9d, 0x7, 0xb, 0x2, 0x2, 0x9c, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x9c, 
    0x9d, 0x3, 0x2, 0x2, 0x2, 0x9d, 0x19, 0x3, 0x2, 0x2, 0x2, 0x9e, 0xa2, 
    0x7, 0xd, 0x2, 0x2, 0x9f, 0xa1, 0x5, 0x1c, 0xf, 0x2, 0xa0, 0x9f, 0x3, 
    0x2, 0x2, 0x2, 0xa1, 0xa4, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xa0, 0x3, 0x2, 
    0x2, 0x2, 0xa2, 0xa3, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xa5, 0x3, 0x2, 0x2, 
    0x2, 0xa4, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xa6, 0x7, 0xe, 0x2, 0x2, 
    0xa6, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xa7, 0xaa, 0x5, 0x4, 0x3, 0x2, 0xa8, 
    0xaa, 0x5, 0x1e, 0x10, 0x2, 0xa9, 0xa7, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xa8, 
    0x3, 0x2, 0x2, 0x2, 0xaa, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xab, 0xac, 0x5, 
    0x24, 0x13, 0x2, 0xac, 0xad, 0x7, 0xc, 0x2, 0x2, 0xad, 0xae, 0x5, 0x20, 
    0x11, 0x2, 0xae, 0xaf, 0x7, 0x5, 0x2, 0x2, 0xaf, 0xce, 0x3, 0x2, 0x2, 
    0x2, 0xb0, 0xb2, 0x5, 0x20, 0x11, 0x2, 0xb1, 0xb0, 0x3, 0x2, 0x2, 0x2, 
    0xb1, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xb2, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb3, 
    0xce, 0x7, 0x5, 0x2, 0x2, 0xb4, 0xce, 0x5, 0x1a, 0xe, 0x2, 0xb5, 0xb6, 
    0x7, 0x12, 0x2, 0x2, 0xb6, 0xb7, 0x7, 0xf, 0x2, 0x2, 0xb7, 0xb8, 0x5, 
    0x22, 0x12, 0x2, 0xb8, 0xb9, 0x7, 0x10, 0x2, 0x2, 0xb9, 0xbc, 0x5, 0x1e, 
    0x10, 0x2, 0xba, 0xbb, 0x7, 0x13, 0x2, 0x2, 0xbb, 0xbd, 0x5, 0x1e, 0x10, 
    0x2, 0xbc, 0xba, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xbd, 0x3, 0x2, 0x2, 0x2, 
    0xbd, 0xce, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xbf, 0x7, 0x14, 0x2, 0x2, 0xbf, 
    0xc0, 0x7, 0xf, 0x2, 0x2, 0xc0, 0xc1, 0x5, 0x22, 0x12, 0x2, 0xc1, 0xc2, 
    0x7, 0x10, 0x2, 0x2, 0xc2, 0xc3, 0x5, 0x1e, 0x10, 0x2, 0xc3, 0xce, 0x3, 
    0x2, 0x2, 0x2, 0xc4, 0xc5, 0x7, 0x15, 0x2, 0x2, 0xc5, 0xce, 0x7, 0x5, 
    0x2, 0x2, 0xc6, 0xc7, 0x7, 0x16, 0x2, 0x2, 0xc7, 0xce, 0x7, 0x5, 0x2, 
    0x2, 0xc8, 0xca, 0x7, 0x17, 0x2, 0x2, 0xc9, 0xcb, 0x5, 0x20, 0x11, 0x2, 
    0xca, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xca, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xcb, 
    0xcc, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xce, 0x7, 0x5, 0x2, 0x2, 0xcd, 0xab, 
    0x3, 0x2, 0x2, 0x2, 0xcd, 0xb1, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xb4, 0x3, 
    0x2, 0x2, 0x2, 0xcd, 0xb5, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xbe, 0x3, 0x2, 
    0x2, 0x2, 0xcd, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xc6, 0x3, 0x2, 0x2, 
    0x2, 0xcd, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xce, 0x1f, 0x3, 0x2, 0x2, 0x2, 
    0xcf, 0xd2, 0x5, 0x30, 0x19, 0x2, 0xd0, 0xd2, 0x7, 0x26, 0x2, 0x2, 0xd1, 
    0xcf, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xd0, 0x3, 0x2, 0x2, 0x2, 0xd2, 0x21, 
    0x3, 0x2, 0x2, 0x2, 0xd3, 0xd4, 0x5, 0x38, 0x1d, 0x2, 0xd4, 0x23, 0x3, 
    0x2, 0x2, 0x2, 0xd5, 0xda, 0x7, 0x27, 0x2, 0x2, 0xd6, 0xd7, 0x7, 0xa, 
    0x2, 0x2, 0xd7, 0xd8, 0x5, 0x20, 0x11, 0x2, 0xd8, 0xd9, 0x7, 0xb, 0x2, 
    0x2, 0xd9, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xda, 0xd6, 0x3, 0x2, 0x2, 0x2, 
    0xda, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xdb, 0x25, 0x3, 0x2, 0x2, 0x2, 0xdc, 
    0xdd, 0x7, 0xf, 0x2, 0x2, 0xdd, 0xde, 0x5, 0x20, 0x11, 0x2, 0xde, 0xdf, 
    0x7, 0x10, 0x2, 0x2, 0xdf, 0xe3, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xe3, 0x5, 
    0x24, 0x13, 0x2, 0xe1, 0xe3, 0x5, 0x3c, 0x1f, 0x2, 0xe2, 0xdc, 0x3, 
    0x2, 0x2, 0x2, 0xe2, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xe1, 0x3, 0x2, 
    0x2, 0x2, 0xe3, 0x27, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xef, 0x5, 0x26, 0x14, 
    0x2, 0xe5, 0xe6, 0x7, 0x27, 0x2, 0x2, 0xe6, 0xe8, 0x7, 0xf, 0x2, 0x2, 
    0xe7, 0xe9, 0x5, 0x2c, 0x17, 0x2, 0xe8, 0xe7, 0x3, 0x2, 0x2, 0x2, 0xe8, 
    0xe9, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xea, 0x3, 0x2, 0x2, 0x2, 0xea, 0xef, 
    0x7, 0x10, 0x2, 0x2, 0xeb, 0xec, 0x5, 0x2a, 0x16, 0x2, 0xec, 0xed, 0x5, 
    0x28, 0x15, 0x2, 0xed, 0xef, 0x3, 0x2, 0x2, 0x2, 0xee, 0xe4, 0x3, 0x2, 
    0x2, 0x2, 0xee, 0xe5, 0x3, 0x2, 0x2, 0x2, 0xee, 0xeb, 0x3, 0x2, 0x2, 
    0x2, 0xef, 0x29, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xf1, 0x9, 0x4, 0x2, 0x2, 
    0xf1, 0x2b, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xf7, 0x5, 0x20, 0x11, 0x2, 0xf3, 
    0xf4, 0x7, 0x4, 0x2, 0x2, 0xf4, 0xf6, 0x5, 0x20, 0x11, 0x2, 0xf5, 0xf3, 
    0x3, 0x2, 0x2, 0x2, 0xf6, 0xf9, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xf5, 0x3, 
    0x2, 0x2, 0x2, 0xf7, 0xf8, 0x3, 0x2, 0x2, 0x2, 0xf8, 0x2d, 0x3, 0x2, 
    0x2, 0x2, 0xf9, 0xf7, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xff, 0x5, 0x28, 0x15, 
    0x2, 0xfb, 0xfc, 0x9, 0x5, 0x2, 0x2, 0xfc, 0xfe, 0x5, 0x28, 0x15, 0x2, 
    0xfd, 0xfb, 0x3, 0x2, 0x2, 0x2, 0xfe, 0x101, 0x3, 0x2, 0x2, 0x2, 0xff, 
    0xfd, 0x3, 0x2, 0x2, 0x2, 0xff, 0x100, 0x3, 0x2, 0x2, 0x2, 0x100, 0x2f, 
    0x3, 0x2, 0x2, 0x2, 0x101, 0xff, 0x3, 0x2, 0x2, 0x2, 0x102, 0x107, 0x5, 
    0x2e, 0x18, 0x2, 0x103, 0x104, 0x9, 0x6, 0x2, 0x2, 0x104, 0x106, 0x5, 
    0x2e, 0x18, 0x2, 0x105, 0x103, 0x3, 0x2, 0x2, 0x2, 0x106, 0x109, 0x3, 
    0x2, 0x2, 0x2, 0x107, 0x105, 0x3, 0x2, 0x2, 0x2, 0x107, 0x108, 0x3, 
    0x2, 0x2, 0x2, 0x108, 0x31, 0x3, 0x2, 0x2, 0x2, 0x109, 0x107, 0x3, 0x2, 
    0x2, 0x2, 0x10a, 0x10f, 0x5, 0x30, 0x19, 0x2, 0x10b, 0x10c, 0x9, 0x7, 
    0x2, 0x2, 0x10c, 0x10e, 0x5, 0x30, 0x19, 0x2, 0x10d, 0x10b, 0x3, 0x2, 
    0x2, 0x2, 0x10e, 0x111, 0x3, 0x2, 0x2, 0x2, 0x10f, 0x10d, 0x3, 0x2, 
    0x2, 0x2, 0x10f, 0x110, 0x3, 0x2, 0x2, 0x2, 0x110, 0x114, 0x3, 0x2, 
    0x2, 0x2, 0x111, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x112, 0x114, 0x7, 0x26, 
    0x2, 0x2, 0x113, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x113, 0x112, 0x3, 0x2, 
    0x2, 0x2, 0x114, 0x33, 0x3, 0x2, 0x2, 0x2, 0x115, 0x11a, 0x5, 0x32, 
    0x1a, 0x2, 0x116, 0x117, 0x9, 0x8, 0x2, 0x2, 0x117, 0x119, 0x5, 0x32, 
    0x1a, 0x2, 0x118, 0x116, 0x3, 0x2, 0x2, 0x2, 0x119, 0x11c, 0x3, 0x2, 
    0x2, 0x2, 0x11a, 0x118, 0x3, 0x2, 0x2, 0x2, 0x11a, 0x11b, 0x3, 0x2, 
    0x2, 0x2, 0x11b, 0x35, 0x3, 0x2, 0x2, 0x2, 0x11c, 0x11a, 0x3, 0x2, 0x2, 
    0x2, 0x11d, 0x122, 0x5, 0x34, 0x1b, 0x2, 0x11e, 0x11f, 0x7, 0x24, 0x2, 
    0x2, 0x11f, 0x121, 0x5, 0x34, 0x1b, 0x2, 0x120, 0x11e, 0x3, 0x2, 0x2, 
    0x2, 0x121, 0x124, 0x3, 0x2, 0x2, 0x2, 0x122, 0x120, 0x3, 0x2, 0x2, 
    0x2, 0x122, 0x123, 0x3, 0x2, 0x2, 0x2, 0x123, 0x37, 0x3, 0x2, 0x2, 0x2, 
    0x124, 0x122, 0x3, 0x2, 0x2, 0x2, 0x125, 0x12a, 0x5, 0x36, 0x1c, 0x2, 
    0x126, 0x127, 0x7, 0x25, 0x2, 0x2, 0x127, 0x129, 0x5, 0x36, 0x1c, 0x2, 
    0x128, 0x126, 0x3, 0x2, 0x2, 0x2, 0x129, 0x12c, 0x3, 0x2, 0x2, 0x2, 
    0x12a, 0x128, 0x3, 0x2, 0x2, 0x2, 0x12a, 0x12b, 0x3, 0x2, 0x2, 0x2, 
    0x12b, 0x39, 0x3, 0x2, 0x2, 0x2, 0x12c, 0x12a, 0x3, 0x2, 0x2, 0x2, 0x12d, 
    0x130, 0x5, 0x3c, 0x1f, 0x2, 0x12e, 0x130, 0x7, 0x26, 0x2, 0x2, 0x12f, 
    0x12d, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x12e, 0x3, 0x2, 0x2, 0x2, 0x130, 
    0x3b, 0x3, 0x2, 0x2, 0x2, 0x131, 0x132, 0x9, 0x9, 0x2, 0x2, 0x132, 0x3d, 
    0x3, 0x2, 0x2, 0x2, 0x24, 0x40, 0x42, 0x48, 0x51, 0x5c, 0x68, 0x6b, 
    0x6e, 0x76, 0x7f, 0x83, 0x89, 0x95, 0x9c, 0xa2, 0xa9, 0xb1, 0xbc, 0xca, 
    0xcd, 0xd1, 0xda, 0xe2, 0xe8, 0xee, 0xf7, 0xff, 0x107, 0x10f, 0x113, 
    0x11a, 0x122, 0x12a, 0x12f, 
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
