
    #include "../src/symbolTable.h"


// Generated from /Volumes/study/code/C++/vscode/compiler/compiler/grammar/CACT.g4 by ANTLR 4.8



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


CACTParser::CompUnitContext* CACTParser::compUnit() {
  CompUnitContext *_localctx = _tracker.createInstance<CompUnitContext>(_ctx, getState());
  enterRule(_localctx, 0, CACTParser::RuleCompUnit);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(72); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(72);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
      case 1: {
        setState(70);
        decl();
        break;
      }

      case 2: {
        setState(71);
        funcDef();
        break;
      }

      }
      setState(74); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CACTParser::T__0)
      | (1ULL << CACTParser::T__3)
      | (1ULL << CACTParser::T__4)
      | (1ULL << CACTParser::T__5)
      | (1ULL << CACTParser::T__6)
      | (1ULL << CACTParser::T__14))) != 0));
    setState(76);
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


CACTParser::DeclContext* CACTParser::decl() {
  DeclContext *_localctx = _tracker.createInstance<DeclContext>(_ctx, getState());
  enterRule(_localctx, 2, CACTParser::RuleDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(80);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::T__0: {
        enterOuterAlt(_localctx, 1);
        setState(78);
        constDecl();
        break;
      }

      case CACTParser::T__3:
      case CACTParser::T__4:
      case CACTParser::T__5:
      case CACTParser::T__6: {
        enterOuterAlt(_localctx, 2);
        setState(79);
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


CACTParser::ConstDeclContext* CACTParser::constDecl() {
  ConstDeclContext *_localctx = _tracker.createInstance<ConstDeclContext>(_ctx, getState());
  enterRule(_localctx, 4, CACTParser::RuleConstDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(82);
    match(CACTParser::T__0);
    setState(83);
    bType();
    setState(84);
    constDef();
    setState(89);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CACTParser::T__1) {
      setState(85);
      match(CACTParser::T__1);
      setState(86);
      constDef();
      setState(91);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(92);
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


CACTParser::BTypeContext* CACTParser::bType() {
  BTypeContext *_localctx = _tracker.createInstance<BTypeContext>(_ctx, getState());
  enterRule(_localctx, 6, CACTParser::RuleBType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(94);
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


CACTParser::ConstDefContext* CACTParser::constDef() {
  ConstDefContext *_localctx = _tracker.createInstance<ConstDefContext>(_ctx, getState());
  enterRule(_localctx, 8, CACTParser::RuleConstDef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(96);
    match(CACTParser::Ident);
    setState(100);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CACTParser::T__7) {
      setState(97);
      match(CACTParser::T__7);
      setState(98);
      match(CACTParser::IntConst);
      setState(99);
      match(CACTParser::T__8);
    }
    setState(102);
    match(CACTParser::T__9);
    setState(103);
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


//----------------- ConstInitValOfArrayContext ------------------------------------------------------------------

std::vector<CACTParser::ConstExpContext *> CACTParser::ConstInitValOfArrayContext::constExp() {
  return getRuleContexts<CACTParser::ConstExpContext>();
}

CACTParser::ConstExpContext* CACTParser::ConstInitValOfArrayContext::constExp(size_t i) {
  return getRuleContext<CACTParser::ConstExpContext>(i);
}

CACTParser::ConstInitValOfArrayContext::ConstInitValOfArrayContext(ConstInitValContext *ctx) { copyFrom(ctx); }


CACTParser::ConstInitValContext* CACTParser::constInitVal() {
  ConstInitValContext *_localctx = _tracker.createInstance<ConstInitValContext>(_ctx, getState());
  enterRule(_localctx, 10, CACTParser::RuleConstInitVal);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(120);
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
        setState(106);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << CACTParser::BoolConst)
          | (1ULL << CACTParser::IntConst)
          | (1ULL << CACTParser::FloatConst)
          | (1ULL << CACTParser::DoubleConst))) != 0)) {
          setState(105);
          constExp();
        }
        break;
      }

      case CACTParser::T__10: {
        _localctx = dynamic_cast<ConstInitValContext *>(_tracker.createInstance<CACTParser::ConstInitValOfArrayContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(108);
        match(CACTParser::T__10);
        setState(117);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << CACTParser::BoolConst)
          | (1ULL << CACTParser::IntConst)
          | (1ULL << CACTParser::FloatConst)
          | (1ULL << CACTParser::DoubleConst))) != 0)) {
          setState(109);
          constExp();
          setState(114);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == CACTParser::T__1) {
            setState(110);
            match(CACTParser::T__1);
            setState(111);
            constExp();
            setState(116);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
        }
        setState(119);
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


CACTParser::VarDeclContext* CACTParser::varDecl() {
  VarDeclContext *_localctx = _tracker.createInstance<VarDeclContext>(_ctx, getState());
  enterRule(_localctx, 12, CACTParser::RuleVarDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(122);
    bType();
    setState(123);
    varDef();
    setState(128);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CACTParser::T__1) {
      setState(124);
      match(CACTParser::T__1);
      setState(125);
      varDef();
      setState(130);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(131);
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


CACTParser::VarDefContext* CACTParser::varDef() {
  VarDefContext *_localctx = _tracker.createInstance<VarDefContext>(_ctx, getState());
  enterRule(_localctx, 14, CACTParser::RuleVarDef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(133);
    match(CACTParser::Ident);
    setState(137);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CACTParser::T__7) {
      setState(134);
      match(CACTParser::T__7);
      setState(135);
      match(CACTParser::IntConst);
      setState(136);
      match(CACTParser::T__8);
    }
    setState(141);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CACTParser::T__9) {
      setState(139);
      match(CACTParser::T__9);
      setState(140);
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

CACTParser::FuncBlockContext* CACTParser::FuncDefContext::funcBlock() {
  return getRuleContext<CACTParser::FuncBlockContext>(0);
}

CACTParser::FuncFParamsContext* CACTParser::FuncDefContext::funcFParams() {
  return getRuleContext<CACTParser::FuncFParamsContext>(0);
}


size_t CACTParser::FuncDefContext::getRuleIndex() const {
  return CACTParser::RuleFuncDef;
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
    setState(143);
    funcType();
    setState(144);
    match(CACTParser::Ident);
    setState(145);
    match(CACTParser::T__12);
    setState(147);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CACTParser::T__3)
      | (1ULL << CACTParser::T__4)
      | (1ULL << CACTParser::T__5)
      | (1ULL << CACTParser::T__6))) != 0)) {
      setState(146);
      funcFParams();
    }
    setState(149);
    match(CACTParser::T__13);
    setState(150);
    funcBlock();
   
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


CACTParser::FuncTypeContext* CACTParser::funcType() {
  FuncTypeContext *_localctx = _tracker.createInstance<FuncTypeContext>(_ctx, getState());
  enterRule(_localctx, 18, CACTParser::RuleFuncType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(152);
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


CACTParser::FuncFParamsContext* CACTParser::funcFParams() {
  FuncFParamsContext *_localctx = _tracker.createInstance<FuncFParamsContext>(_ctx, getState());
  enterRule(_localctx, 20, CACTParser::RuleFuncFParams);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(154);
    funcFParam();
    setState(159);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CACTParser::T__1) {
      setState(155);
      match(CACTParser::T__1);
      setState(156);
      funcFParam();
      setState(161);
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


CACTParser::FuncFParamContext* CACTParser::funcFParam() {
  FuncFParamContext *_localctx = _tracker.createInstance<FuncFParamContext>(_ctx, getState());
  enterRule(_localctx, 22, CACTParser::RuleFuncFParam);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(162);
    bType();
    setState(163);
    match(CACTParser::Ident);
    setState(165);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CACTParser::T__7) {
      setState(164);
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


CACTParser::BracketsContext* CACTParser::brackets() {
  BracketsContext *_localctx = _tracker.createInstance<BracketsContext>(_ctx, getState());
  enterRule(_localctx, 24, CACTParser::RuleBrackets);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(167);
    match(CACTParser::T__7);
    setState(168);
    match(CACTParser::T__8);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncBlockContext ------------------------------------------------------------------

CACTParser::FuncBlockContext::FuncBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CACTParser::FuncBlockItemContext *> CACTParser::FuncBlockContext::funcBlockItem() {
  return getRuleContexts<CACTParser::FuncBlockItemContext>();
}

CACTParser::FuncBlockItemContext* CACTParser::FuncBlockContext::funcBlockItem(size_t i) {
  return getRuleContext<CACTParser::FuncBlockItemContext>(i);
}


size_t CACTParser::FuncBlockContext::getRuleIndex() const {
  return CACTParser::RuleFuncBlock;
}


CACTParser::FuncBlockContext* CACTParser::funcBlock() {
  FuncBlockContext *_localctx = _tracker.createInstance<FuncBlockContext>(_ctx, getState());
  enterRule(_localctx, 26, CACTParser::RuleFuncBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(170);
    match(CACTParser::T__10);
    setState(174);
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
      setState(171);
      funcBlockItem();
      setState(176);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(177);
    match(CACTParser::T__11);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncBlockItemContext ------------------------------------------------------------------

CACTParser::FuncBlockItemContext::FuncBlockItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::DeclContext* CACTParser::FuncBlockItemContext::decl() {
  return getRuleContext<CACTParser::DeclContext>(0);
}

CACTParser::StmtContext* CACTParser::FuncBlockItemContext::stmt() {
  return getRuleContext<CACTParser::StmtContext>(0);
}


size_t CACTParser::FuncBlockItemContext::getRuleIndex() const {
  return CACTParser::RuleFuncBlockItem;
}


CACTParser::FuncBlockItemContext* CACTParser::funcBlockItem() {
  FuncBlockItemContext *_localctx = _tracker.createInstance<FuncBlockItemContext>(_ctx, getState());
  enterRule(_localctx, 28, CACTParser::RuleFuncBlockItem);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(181);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::T__0:
      case CACTParser::T__3:
      case CACTParser::T__4:
      case CACTParser::T__5:
      case CACTParser::T__6: {
        enterOuterAlt(_localctx, 1);
        setState(179);
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
        setState(180);
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

CACTParser::FuncBlockContext* CACTParser::StmtBlockContext::funcBlock() {
  return getRuleContext<CACTParser::FuncBlockContext>(0);
}

CACTParser::StmtBlockContext::StmtBlockContext(StmtContext *ctx) { copyFrom(ctx); }


//----------------- StmtExpressionContext ------------------------------------------------------------------

CACTParser::ExpContext* CACTParser::StmtExpressionContext::exp() {
  return getRuleContext<CACTParser::ExpContext>(0);
}

CACTParser::StmtExpressionContext::StmtExpressionContext(StmtContext *ctx) { copyFrom(ctx); }


//----------------- StmtAssignmentContext ------------------------------------------------------------------

CACTParser::LValContext* CACTParser::StmtAssignmentContext::lVal() {
  return getRuleContext<CACTParser::LValContext>(0);
}

CACTParser::ExpContext* CACTParser::StmtAssignmentContext::exp() {
  return getRuleContext<CACTParser::ExpContext>(0);
}

CACTParser::StmtAssignmentContext::StmtAssignmentContext(StmtContext *ctx) { copyFrom(ctx); }


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


//----------------- StmtReturnContext ------------------------------------------------------------------

CACTParser::ExpContext* CACTParser::StmtReturnContext::exp() {
  return getRuleContext<CACTParser::ExpContext>(0);
}

CACTParser::StmtReturnContext::StmtReturnContext(StmtContext *ctx) { copyFrom(ctx); }


CACTParser::StmtContext* CACTParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 30, CACTParser::RuleStmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(213);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<CACTParser::StmtAssignmentContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(183);
      lVal();
      setState(184);
      match(CACTParser::T__9);
      setState(185);
      exp();
      setState(186);
      match(CACTParser::T__2);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<CACTParser::StmtExpressionContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(189);
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
        setState(188);
        exp();
      }
      setState(191);
      match(CACTParser::T__2);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<CACTParser::StmtBlockContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(192);
      funcBlock();
      break;
    }

    case 4: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<CACTParser::StmtCtrlSeqContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(193);
      match(CACTParser::T__15);
      setState(194);
      match(CACTParser::T__12);
      setState(195);
      cond();
      setState(196);
      match(CACTParser::T__13);
      setState(197);
      stmt();
      setState(200);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
      case 1: {
        setState(198);
        match(CACTParser::T__16);
        setState(199);
        stmt();
        break;
      }

      }
      break;
    }

    case 5: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<CACTParser::StmtCtrlSeqContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(202);
      match(CACTParser::T__17);
      setState(203);
      match(CACTParser::T__12);
      setState(204);
      cond();
      setState(205);
      match(CACTParser::T__13);
      setState(206);
      subStmt();
      break;
    }

    case 6: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<CACTParser::StmtReturnContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(208);
      match(CACTParser::T__18);
      setState(210);
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
        setState(209);
        exp();
      }
      setState(212);
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


CACTParser::BlockContext* CACTParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 32, CACTParser::RuleBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(215);
    match(CACTParser::T__10);
    setState(219);
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
      setState(216);
      blockItem();
      setState(221);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(222);
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

CACTParser::SubStmtContext* CACTParser::BlockItemContext::subStmt() {
  return getRuleContext<CACTParser::SubStmtContext>(0);
}


size_t CACTParser::BlockItemContext::getRuleIndex() const {
  return CACTParser::RuleBlockItem;
}


CACTParser::BlockItemContext* CACTParser::blockItem() {
  BlockItemContext *_localctx = _tracker.createInstance<BlockItemContext>(_ctx, getState());
  enterRule(_localctx, 34, CACTParser::RuleBlockItem);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(226);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::T__0:
      case CACTParser::T__3:
      case CACTParser::T__4:
      case CACTParser::T__5:
      case CACTParser::T__6: {
        enterOuterAlt(_localctx, 1);
        setState(224);
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
        setState(225);
        subStmt();
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


//----------------- SubStmtBlockContext ------------------------------------------------------------------

CACTParser::BlockContext* CACTParser::SubStmtBlockContext::block() {
  return getRuleContext<CACTParser::BlockContext>(0);
}

CACTParser::SubStmtBlockContext::SubStmtBlockContext(SubStmtContext *ctx) { copyFrom(ctx); }


//----------------- SubStmtAssignmentContext ------------------------------------------------------------------

CACTParser::LValContext* CACTParser::SubStmtAssignmentContext::lVal() {
  return getRuleContext<CACTParser::LValContext>(0);
}

CACTParser::ExpContext* CACTParser::SubStmtAssignmentContext::exp() {
  return getRuleContext<CACTParser::ExpContext>(0);
}

CACTParser::SubStmtAssignmentContext::SubStmtAssignmentContext(SubStmtContext *ctx) { copyFrom(ctx); }


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


//----------------- SubStmtReturnContext ------------------------------------------------------------------

CACTParser::ExpContext* CACTParser::SubStmtReturnContext::exp() {
  return getRuleContext<CACTParser::ExpContext>(0);
}

CACTParser::SubStmtReturnContext::SubStmtReturnContext(SubStmtContext *ctx) { copyFrom(ctx); }


CACTParser::SubStmtContext* CACTParser::subStmt() {
  SubStmtContext *_localctx = _tracker.createInstance<SubStmtContext>(_ctx, getState());
  enterRule(_localctx, 36, CACTParser::RuleSubStmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(262);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<SubStmtContext *>(_tracker.createInstance<CACTParser::SubStmtAssignmentContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(228);
      lVal();
      setState(229);
      match(CACTParser::T__9);
      setState(230);
      exp();
      setState(231);
      match(CACTParser::T__2);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<SubStmtContext *>(_tracker.createInstance<CACTParser::SubStmtExpressionContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(234);
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
        setState(233);
        exp();
      }
      setState(236);
      match(CACTParser::T__2);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<SubStmtContext *>(_tracker.createInstance<CACTParser::SubStmtBlockContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(237);
      block();
      break;
    }

    case 4: {
      _localctx = dynamic_cast<SubStmtContext *>(_tracker.createInstance<CACTParser::SubStmtCtrlSeqContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(238);
      match(CACTParser::T__15);
      setState(239);
      match(CACTParser::T__12);
      setState(240);
      cond();
      setState(241);
      match(CACTParser::T__13);
      setState(242);
      subStmt();
      setState(245);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
      case 1: {
        setState(243);
        match(CACTParser::T__16);
        setState(244);
        subStmt();
        break;
      }

      }
      break;
    }

    case 5: {
      _localctx = dynamic_cast<SubStmtContext *>(_tracker.createInstance<CACTParser::SubStmtCtrlSeqContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(247);
      match(CACTParser::T__17);
      setState(248);
      match(CACTParser::T__12);
      setState(249);
      cond();
      setState(250);
      match(CACTParser::T__13);
      setState(251);
      subStmt();
      break;
    }

    case 6: {
      _localctx = dynamic_cast<SubStmtContext *>(_tracker.createInstance<CACTParser::SubStmtCtrlSeqContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(253);
      match(CACTParser::T__19);
      setState(254);
      match(CACTParser::T__2);
      break;
    }

    case 7: {
      _localctx = dynamic_cast<SubStmtContext *>(_tracker.createInstance<CACTParser::SubStmtCtrlSeqContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(255);
      match(CACTParser::T__20);
      setState(256);
      match(CACTParser::T__2);
      break;
    }

    case 8: {
      _localctx = dynamic_cast<SubStmtContext *>(_tracker.createInstance<CACTParser::SubStmtReturnContext>(_localctx));
      enterOuterAlt(_localctx, 8);
      setState(257);
      match(CACTParser::T__18);
      setState(259);
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
        setState(258);
        exp();
      }
      setState(261);
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


//----------------- ExpAddExpContext ------------------------------------------------------------------

CACTParser::AddExpContext* CACTParser::ExpAddExpContext::addExp() {
  return getRuleContext<CACTParser::AddExpContext>(0);
}

CACTParser::ExpAddExpContext::ExpAddExpContext(ExpContext *ctx) { copyFrom(ctx); }


CACTParser::ExpContext* CACTParser::exp() {
  ExpContext *_localctx = _tracker.createInstance<ExpContext>(_ctx, getState());
  enterRule(_localctx, 38, CACTParser::RuleExp);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(266);
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
        setState(264);
        addExp(0);
        break;
      }

      case CACTParser::BoolConst: {
        _localctx = dynamic_cast<ExpContext *>(_tracker.createInstance<CACTParser::ExpBoolExpContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(265);
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


CACTParser::CondContext* CACTParser::cond() {
  CondContext *_localctx = _tracker.createInstance<CondContext>(_ctx, getState());
  enterRule(_localctx, 40, CACTParser::RuleCond);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(268);
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


CACTParser::LValContext* CACTParser::lVal() {
  LValContext *_localctx = _tracker.createInstance<LValContext>(_ctx, getState());
  enterRule(_localctx, 42, CACTParser::RuleLVal);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(270);
    match(CACTParser::Ident);
    setState(275);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
    case 1: {
      setState(271);
      match(CACTParser::T__7);
      setState(272);
      exp();
      setState(273);
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


//----------------- PrimaryExpNumberContext ------------------------------------------------------------------

CACTParser::NumberContext* CACTParser::PrimaryExpNumberContext::number() {
  return getRuleContext<CACTParser::NumberContext>(0);
}

CACTParser::PrimaryExpNumberContext::PrimaryExpNumberContext(PrimaryExpContext *ctx) { copyFrom(ctx); }


//----------------- PrimaryExplValContext ------------------------------------------------------------------

CACTParser::LValContext* CACTParser::PrimaryExplValContext::lVal() {
  return getRuleContext<CACTParser::LValContext>(0);
}

CACTParser::PrimaryExplValContext::PrimaryExplValContext(PrimaryExpContext *ctx) { copyFrom(ctx); }


CACTParser::PrimaryExpContext* CACTParser::primaryExp() {
  PrimaryExpContext *_localctx = _tracker.createInstance<PrimaryExpContext>(_ctx, getState());
  enterRule(_localctx, 44, CACTParser::RulePrimaryExp);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(283);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::T__12: {
        _localctx = dynamic_cast<PrimaryExpContext *>(_tracker.createInstance<CACTParser::PrimaryExpNestExpContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(277);
        match(CACTParser::T__12);
        setState(278);
        exp();
        setState(279);
        match(CACTParser::T__13);
        break;
      }

      case CACTParser::Ident: {
        _localctx = dynamic_cast<PrimaryExpContext *>(_tracker.createInstance<CACTParser::PrimaryExplValContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(281);
        lVal();
        break;
      }

      case CACTParser::IntConst:
      case CACTParser::FloatConst:
      case CACTParser::DoubleConst: {
        _localctx = dynamic_cast<PrimaryExpContext *>(_tracker.createInstance<CACTParser::PrimaryExpNumberContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(282);
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


//----------------- UnaryExpPrimaryExpContext ------------------------------------------------------------------

CACTParser::PrimaryExpContext* CACTParser::UnaryExpPrimaryExpContext::primaryExp() {
  return getRuleContext<CACTParser::PrimaryExpContext>(0);
}

CACTParser::UnaryExpPrimaryExpContext::UnaryExpPrimaryExpContext(UnaryExpContext *ctx) { copyFrom(ctx); }


//----------------- UnaryExpNestUnaryExpContext ------------------------------------------------------------------

CACTParser::UnaryOpContext* CACTParser::UnaryExpNestUnaryExpContext::unaryOp() {
  return getRuleContext<CACTParser::UnaryOpContext>(0);
}

CACTParser::UnaryExpContext* CACTParser::UnaryExpNestUnaryExpContext::unaryExp() {
  return getRuleContext<CACTParser::UnaryExpContext>(0);
}

CACTParser::UnaryExpNestUnaryExpContext::UnaryExpNestUnaryExpContext(UnaryExpContext *ctx) { copyFrom(ctx); }


CACTParser::UnaryExpContext* CACTParser::unaryExp() {
  UnaryExpContext *_localctx = _tracker.createInstance<UnaryExpContext>(_ctx, getState());
  enterRule(_localctx, 46, CACTParser::RuleUnaryExp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(295);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<UnaryExpContext *>(_tracker.createInstance<CACTParser::UnaryExpPrimaryExpContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(285);
      primaryExp();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<UnaryExpContext *>(_tracker.createInstance<CACTParser::UnaryExpFuncContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(286);
      match(CACTParser::Ident);
      setState(287);
      match(CACTParser::T__12);
      setState(289);
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
        setState(288);
        funcRParams();
      }
      setState(291);
      match(CACTParser::T__13);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<UnaryExpContext *>(_tracker.createInstance<CACTParser::UnaryExpNestUnaryExpContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(292);
      unaryOp();
      setState(293);
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


CACTParser::UnaryOpContext* CACTParser::unaryOp() {
  UnaryOpContext *_localctx = _tracker.createInstance<UnaryOpContext>(_ctx, getState());
  enterRule(_localctx, 48, CACTParser::RuleUnaryOp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(297);
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


CACTParser::FuncRParamsContext* CACTParser::funcRParams() {
  FuncRParamsContext *_localctx = _tracker.createInstance<FuncRParamsContext>(_ctx, getState());
  enterRule(_localctx, 50, CACTParser::RuleFuncRParams);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(299);
    exp();
    setState(304);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CACTParser::T__1) {
      setState(300);
      match(CACTParser::T__1);
      setState(301);
      exp();
      setState(306);
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


//----------------- MulExpUnaryExpContext ------------------------------------------------------------------

CACTParser::UnaryExpContext* CACTParser::MulExpUnaryExpContext::unaryExp() {
  return getRuleContext<CACTParser::UnaryExpContext>(0);
}

CACTParser::MulExpUnaryExpContext::MulExpUnaryExpContext(MulExpContext *ctx) { copyFrom(ctx); }



CACTParser::MulExpContext* CACTParser::mulExp() {
   return mulExp(0);
}

CACTParser::MulExpContext* CACTParser::mulExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CACTParser::MulExpContext *_localctx = _tracker.createInstance<MulExpContext>(_ctx, parentState);
  CACTParser::MulExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 52;
  enterRecursionRule(_localctx, 52, CACTParser::RuleMulExp, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<MulExpUnaryExpContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(308);
    unaryExp();
    _ctx->stop = _input->LT(-1);
    setState(316);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<MulExpMulExpContext>(_tracker.createInstance<MulExpContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleMulExp);
        setState(310);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(311);
        mulOp();
        setState(312);
        unaryExp(); 
      }
      setState(318);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
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


CACTParser::MulOpContext* CACTParser::mulOp() {
  MulOpContext *_localctx = _tracker.createInstance<MulOpContext>(_ctx, getState());
  enterRule(_localctx, 54, CACTParser::RuleMulOp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(319);
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


//----------------- AddExpMulExpContext ------------------------------------------------------------------

CACTParser::MulExpContext* CACTParser::AddExpMulExpContext::mulExp() {
  return getRuleContext<CACTParser::MulExpContext>(0);
}

CACTParser::AddExpMulExpContext::AddExpMulExpContext(AddExpContext *ctx) { copyFrom(ctx); }



CACTParser::AddExpContext* CACTParser::addExp() {
   return addExp(0);
}

CACTParser::AddExpContext* CACTParser::addExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CACTParser::AddExpContext *_localctx = _tracker.createInstance<AddExpContext>(_ctx, parentState);
  CACTParser::AddExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 56;
  enterRecursionRule(_localctx, 56, CACTParser::RuleAddExp, precedence);

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

    setState(322);
    mulExp(0);
    _ctx->stop = _input->LT(-1);
    setState(329);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<AddExpAddExpContext>(_tracker.createInstance<AddExpContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleAddExp);
        setState(324);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(325);
        _la = _input->LA(1);
        if (!(_la == CACTParser::T__21

        || _la == CACTParser::T__22)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(326);
        mulExp(0); 
      }
      setState(331);
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


//----------------- RelExpAddExpContext ------------------------------------------------------------------

CACTParser::AddExpContext* CACTParser::RelExpAddExpContext::addExp() {
  return getRuleContext<CACTParser::AddExpContext>(0);
}

CACTParser::RelExpAddExpContext::RelExpAddExpContext(RelExpContext *ctx) { copyFrom(ctx); }


//----------------- RelExpBoolConstContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::RelExpBoolConstContext::BoolConst() {
  return getToken(CACTParser::BoolConst, 0);
}

CACTParser::RelExpBoolConstContext::RelExpBoolConstContext(RelExpContext *ctx) { copyFrom(ctx); }



CACTParser::RelExpContext* CACTParser::relExp() {
   return relExp(0);
}

CACTParser::RelExpContext* CACTParser::relExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CACTParser::RelExpContext *_localctx = _tracker.createInstance<RelExpContext>(_ctx, parentState);
  CACTParser::RelExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 58;
  enterRecursionRule(_localctx, 58, CACTParser::RuleRelExp, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(335);
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

        setState(333);
        addExp(0);
        break;
      }

      case CACTParser::BoolConst: {
        _localctx = _tracker.createInstance<RelExpBoolConstContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(334);
        match(CACTParser::BoolConst);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(342);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<RelExpRelExpContext>(_tracker.createInstance<RelExpContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleRelExp);
        setState(337);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(338);
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
        setState(339);
        addExp(0); 
      }
      setState(344);
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


//----------------- EqExpEqExpContext ------------------------------------------------------------------

CACTParser::EqExpContext* CACTParser::EqExpEqExpContext::eqExp() {
  return getRuleContext<CACTParser::EqExpContext>(0);
}

CACTParser::RelExpContext* CACTParser::EqExpEqExpContext::relExp() {
  return getRuleContext<CACTParser::RelExpContext>(0);
}

CACTParser::EqExpEqExpContext::EqExpEqExpContext(EqExpContext *ctx) { copyFrom(ctx); }



CACTParser::EqExpContext* CACTParser::eqExp() {
   return eqExp(0);
}

CACTParser::EqExpContext* CACTParser::eqExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CACTParser::EqExpContext *_localctx = _tracker.createInstance<EqExpContext>(_ctx, parentState);
  CACTParser::EqExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 60;
  enterRecursionRule(_localctx, 60, CACTParser::RuleEqExp, precedence);

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

    setState(346);
    relExp(0);
    _ctx->stop = _input->LT(-1);
    setState(353);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<EqExpEqExpContext>(_tracker.createInstance<EqExpContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleEqExp);
        setState(348);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(349);
        _la = _input->LA(1);
        if (!(_la == CACTParser::T__31

        || _la == CACTParser::T__32)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(350);
        relExp(0); 
      }
      setState(355);
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


//----------------- LAndExpEqExpContext ------------------------------------------------------------------

CACTParser::EqExpContext* CACTParser::LAndExpEqExpContext::eqExp() {
  return getRuleContext<CACTParser::EqExpContext>(0);
}

CACTParser::LAndExpEqExpContext::LAndExpEqExpContext(LAndExpContext *ctx) { copyFrom(ctx); }



CACTParser::LAndExpContext* CACTParser::lAndExp() {
   return lAndExp(0);
}

CACTParser::LAndExpContext* CACTParser::lAndExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CACTParser::LAndExpContext *_localctx = _tracker.createInstance<LAndExpContext>(_ctx, parentState);
  CACTParser::LAndExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 62;
  enterRecursionRule(_localctx, 62, CACTParser::RuleLAndExp, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<LAndExpEqExpContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(357);
    eqExp(0);
    _ctx->stop = _input->LT(-1);
    setState(364);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<LAndExpLAndExpContext>(_tracker.createInstance<LAndExpContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleLAndExp);
        setState(359);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");

        setState(360);
        match(CACTParser::T__33);
        setState(361);
        eqExp(0); 
      }
      setState(366);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx);
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


//----------------- LOrExpLOrExpContext ------------------------------------------------------------------

CACTParser::LOrExpContext* CACTParser::LOrExpLOrExpContext::lOrExp() {
  return getRuleContext<CACTParser::LOrExpContext>(0);
}

CACTParser::LAndExpContext* CACTParser::LOrExpLOrExpContext::lAndExp() {
  return getRuleContext<CACTParser::LAndExpContext>(0);
}

CACTParser::LOrExpLOrExpContext::LOrExpLOrExpContext(LOrExpContext *ctx) { copyFrom(ctx); }



CACTParser::LOrExpContext* CACTParser::lOrExp() {
   return lOrExp(0);
}

CACTParser::LOrExpContext* CACTParser::lOrExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CACTParser::LOrExpContext *_localctx = _tracker.createInstance<LOrExpContext>(_ctx, parentState);
  CACTParser::LOrExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 64;
  enterRecursionRule(_localctx, 64, CACTParser::RuleLOrExp, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<LOrExpLAndExpContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(368);
    lAndExp(0);
    _ctx->stop = _input->LT(-1);
    setState(375);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<LOrExpLOrExpContext>(_tracker.createInstance<LOrExpContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleLOrExp);
        setState(370);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");

        setState(371);
        match(CACTParser::T__34);
        setState(372);
        lAndExp(0); 
      }
      setState(377);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx);
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


//----------------- ConstExpNumberContext ------------------------------------------------------------------

CACTParser::NumberContext* CACTParser::ConstExpNumberContext::number() {
  return getRuleContext<CACTParser::NumberContext>(0);
}

CACTParser::ConstExpNumberContext::ConstExpNumberContext(ConstExpContext *ctx) { copyFrom(ctx); }


CACTParser::ConstExpContext* CACTParser::constExp() {
  ConstExpContext *_localctx = _tracker.createInstance<ConstExpContext>(_ctx, getState());
  enterRule(_localctx, 66, CACTParser::RuleConstExp);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(380);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::IntConst:
      case CACTParser::FloatConst:
      case CACTParser::DoubleConst: {
        _localctx = dynamic_cast<ConstExpContext *>(_tracker.createInstance<CACTParser::ConstExpNumberContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(378);
        number();
        break;
      }

      case CACTParser::BoolConst: {
        _localctx = dynamic_cast<ConstExpContext *>(_tracker.createInstance<CACTParser::ConstExpBoolConstContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(379);
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


//----------------- NumberFloatConstContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::NumberFloatConstContext::FloatConst() {
  return getToken(CACTParser::FloatConst, 0);
}

CACTParser::NumberFloatConstContext::NumberFloatConstContext(NumberContext *ctx) { copyFrom(ctx); }


//----------------- NumberIntConstContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::NumberIntConstContext::IntConst() {
  return getToken(CACTParser::IntConst, 0);
}

CACTParser::NumberIntConstContext::NumberIntConstContext(NumberContext *ctx) { copyFrom(ctx); }


CACTParser::NumberContext* CACTParser::number() {
  NumberContext *_localctx = _tracker.createInstance<NumberContext>(_ctx, getState());
  enterRule(_localctx, 68, CACTParser::RuleNumber);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(385);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::IntConst: {
        _localctx = dynamic_cast<NumberContext *>(_tracker.createInstance<CACTParser::NumberIntConstContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(382);
        match(CACTParser::IntConst);
        break;
      }

      case CACTParser::DoubleConst: {
        _localctx = dynamic_cast<NumberContext *>(_tracker.createInstance<CACTParser::NumberDoubleConstContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(383);
        match(CACTParser::DoubleConst);
        break;
      }

      case CACTParser::FloatConst: {
        _localctx = dynamic_cast<NumberContext *>(_tracker.createInstance<CACTParser::NumberFloatConstContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(384);
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
    case 26: return mulExpSempred(dynamic_cast<MulExpContext *>(context), predicateIndex);
    case 28: return addExpSempred(dynamic_cast<AddExpContext *>(context), predicateIndex);
    case 29: return relExpSempred(dynamic_cast<RelExpContext *>(context), predicateIndex);
    case 30: return eqExpSempred(dynamic_cast<EqExpContext *>(context), predicateIndex);
    case 31: return lAndExpSempred(dynamic_cast<LAndExpContext *>(context), predicateIndex);
    case 32: return lOrExpSempred(dynamic_cast<LOrExpContext *>(context), predicateIndex);

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
  "brackets", "funcBlock", "funcBlockItem", "stmt", "block", "blockItem", 
  "subStmt", "exp", "cond", "lVal", "primaryExp", "unaryExp", "unaryOp", 
  "funcRParams", "mulExp", "mulOp", "addExp", "relExp", "eqExp", "lAndExp", 
  "lOrExp", "constExp", "number"
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
    0x3, 0x2f, 0x186, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 
    0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x3, 0x2, 0x3, 
    0x2, 0x6, 0x2, 0x4b, 0xa, 0x2, 0xd, 0x2, 0xe, 0x2, 0x4c, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x53, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x5a, 0xa, 0x4, 0xc, 0x4, 0xe, 
    0x4, 0x5d, 0xb, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x67, 0xa, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x7, 0x5, 0x7, 0x6d, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0x73, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0x76, 
    0xb, 0x7, 0x5, 0x7, 0x78, 0xa, 0x7, 0x3, 0x7, 0x5, 0x7, 0x7b, 0xa, 0x7, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x7, 0x8, 0x81, 0xa, 0x8, 0xc, 
    0x8, 0xe, 0x8, 0x84, 0xb, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x8c, 0xa, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 
    0x9, 0x90, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 
    0x96, 0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0xa0, 0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 
    0xa3, 0xb, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0xa8, 0xa, 0xd, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x7, 0xf, 0xaf, 0xa, 
    0xf, 0xc, 0xf, 0xe, 0xf, 0xb2, 0xb, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 
    0x3, 0x10, 0x5, 0x10, 0xb8, 0xa, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0xc0, 0xa, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 
    0x11, 0x3, 0x11, 0x5, 0x11, 0xcb, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 
    0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 
    0xd5, 0xa, 0x11, 0x3, 0x11, 0x5, 0x11, 0xd8, 0xa, 0x11, 0x3, 0x12, 0x3, 
    0x12, 0x7, 0x12, 0xdc, 0xa, 0x12, 0xc, 0x12, 0xe, 0x12, 0xdf, 0xb, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x5, 0x13, 0xe5, 0xa, 0x13, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 
    0x14, 0xed, 0xa, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 
    0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0xf8, 0xa, 
    0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 
    0x14, 0x106, 0xa, 0x14, 0x3, 0x14, 0x5, 0x14, 0x109, 0xa, 0x14, 0x3, 
    0x15, 0x3, 0x15, 0x5, 0x15, 0x10d, 0xa, 0x15, 0x3, 0x16, 0x3, 0x16, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0x116, 
    0xa, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 
    0x18, 0x5, 0x18, 0x11e, 0xa, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 
    0x3, 0x19, 0x5, 0x19, 0x124, 0xa, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 
    0x3, 0x19, 0x5, 0x19, 0x12a, 0xa, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 
    0x3, 0x1b, 0x3, 0x1b, 0x7, 0x1b, 0x131, 0xa, 0x1b, 0xc, 0x1b, 0xe, 0x1b, 
    0x134, 0xb, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 
    0x3, 0x1c, 0x3, 0x1c, 0x7, 0x1c, 0x13d, 0xa, 0x1c, 0xc, 0x1c, 0xe, 0x1c, 
    0x140, 0xb, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 
    0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x7, 0x1e, 0x14a, 0xa, 0x1e, 0xc, 0x1e, 
    0xe, 0x1e, 0x14d, 0xb, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x5, 0x1f, 
    0x152, 0xa, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x7, 0x1f, 0x157, 
    0xa, 0x1f, 0xc, 0x1f, 0xe, 0x1f, 0x15a, 0xb, 0x1f, 0x3, 0x20, 0x3, 0x20, 
    0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x7, 0x20, 0x162, 0xa, 0x20, 
    0xc, 0x20, 0xe, 0x20, 0x165, 0xb, 0x20, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 
    0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x7, 0x21, 0x16d, 0xa, 0x21, 0xc, 0x21, 
    0xe, 0x21, 0x170, 0xb, 0x21, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 
    0x3, 0x22, 0x3, 0x22, 0x7, 0x22, 0x178, 0xa, 0x22, 0xc, 0x22, 0xe, 0x22, 
    0x17b, 0xb, 0x22, 0x3, 0x23, 0x3, 0x23, 0x5, 0x23, 0x17f, 0xa, 0x23, 
    0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x5, 0x24, 0x184, 0xa, 0x24, 0x3, 0x24, 
    0x2, 0x8, 0x36, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x25, 0x2, 0x4, 0x6, 0x8, 
    0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 
    0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 
    0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x2, 0x9, 0x3, 0x2, 0x6, 0x9, 
    0x4, 0x2, 0x6, 0x9, 0x11, 0x11, 0x3, 0x2, 0x18, 0x1a, 0x3, 0x2, 0x1b, 
    0x1d, 0x3, 0x2, 0x18, 0x19, 0x3, 0x2, 0x1e, 0x21, 0x3, 0x2, 0x22, 0x23, 
    0x2, 0x199, 0x2, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x4, 0x52, 0x3, 0x2, 0x2, 
    0x2, 0x6, 0x54, 0x3, 0x2, 0x2, 0x2, 0x8, 0x60, 0x3, 0x2, 0x2, 0x2, 0xa, 
    0x62, 0x3, 0x2, 0x2, 0x2, 0xc, 0x7a, 0x3, 0x2, 0x2, 0x2, 0xe, 0x7c, 
    0x3, 0x2, 0x2, 0x2, 0x10, 0x87, 0x3, 0x2, 0x2, 0x2, 0x12, 0x91, 0x3, 
    0x2, 0x2, 0x2, 0x14, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x16, 0x9c, 0x3, 0x2, 
    0x2, 0x2, 0x18, 0xa4, 0x3, 0x2, 0x2, 0x2, 0x1a, 0xa9, 0x3, 0x2, 0x2, 
    0x2, 0x1c, 0xac, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xb7, 0x3, 0x2, 0x2, 0x2, 
    0x20, 0xd7, 0x3, 0x2, 0x2, 0x2, 0x22, 0xd9, 0x3, 0x2, 0x2, 0x2, 0x24, 
    0xe4, 0x3, 0x2, 0x2, 0x2, 0x26, 0x108, 0x3, 0x2, 0x2, 0x2, 0x28, 0x10c, 
    0x3, 0x2, 0x2, 0x2, 0x2a, 0x10e, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x110, 0x3, 
    0x2, 0x2, 0x2, 0x2e, 0x11d, 0x3, 0x2, 0x2, 0x2, 0x30, 0x129, 0x3, 0x2, 
    0x2, 0x2, 0x32, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x34, 0x12d, 0x3, 0x2, 0x2, 
    0x2, 0x36, 0x135, 0x3, 0x2, 0x2, 0x2, 0x38, 0x141, 0x3, 0x2, 0x2, 0x2, 
    0x3a, 0x143, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x151, 0x3, 0x2, 0x2, 0x2, 0x3e, 
    0x15b, 0x3, 0x2, 0x2, 0x2, 0x40, 0x166, 0x3, 0x2, 0x2, 0x2, 0x42, 0x171, 
    0x3, 0x2, 0x2, 0x2, 0x44, 0x17e, 0x3, 0x2, 0x2, 0x2, 0x46, 0x183, 0x3, 
    0x2, 0x2, 0x2, 0x48, 0x4b, 0x5, 0x4, 0x3, 0x2, 0x49, 0x4b, 0x5, 0x12, 
    0xa, 0x2, 0x4a, 0x48, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x49, 0x3, 0x2, 0x2, 
    0x2, 0x4b, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4a, 0x3, 0x2, 0x2, 0x2, 
    0x4c, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x4e, 
    0x4f, 0x7, 0x2, 0x2, 0x3, 0x4f, 0x3, 0x3, 0x2, 0x2, 0x2, 0x50, 0x53, 
    0x5, 0x6, 0x4, 0x2, 0x51, 0x53, 0x5, 0xe, 0x8, 0x2, 0x52, 0x50, 0x3, 
    0x2, 0x2, 0x2, 0x52, 0x51, 0x3, 0x2, 0x2, 0x2, 0x53, 0x5, 0x3, 0x2, 
    0x2, 0x2, 0x54, 0x55, 0x7, 0x3, 0x2, 0x2, 0x55, 0x56, 0x5, 0x8, 0x5, 
    0x2, 0x56, 0x5b, 0x5, 0xa, 0x6, 0x2, 0x57, 0x58, 0x7, 0x4, 0x2, 0x2, 
    0x58, 0x5a, 0x5, 0xa, 0x6, 0x2, 0x59, 0x57, 0x3, 0x2, 0x2, 0x2, 0x5a, 
    0x5d, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x59, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x5c, 
    0x3, 0x2, 0x2, 0x2, 0x5c, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x5b, 0x3, 
    0x2, 0x2, 0x2, 0x5e, 0x5f, 0x7, 0x5, 0x2, 0x2, 0x5f, 0x7, 0x3, 0x2, 
    0x2, 0x2, 0x60, 0x61, 0x9, 0x2, 0x2, 0x2, 0x61, 0x9, 0x3, 0x2, 0x2, 
    0x2, 0x62, 0x66, 0x7, 0x27, 0x2, 0x2, 0x63, 0x64, 0x7, 0xa, 0x2, 0x2, 
    0x64, 0x65, 0x7, 0x28, 0x2, 0x2, 0x65, 0x67, 0x7, 0xb, 0x2, 0x2, 0x66, 
    0x63, 0x3, 0x2, 0x2, 0x2, 0x66, 0x67, 0x3, 0x2, 0x2, 0x2, 0x67, 0x68, 
    0x3, 0x2, 0x2, 0x2, 0x68, 0x69, 0x7, 0xc, 0x2, 0x2, 0x69, 0x6a, 0x5, 
    0xc, 0x7, 0x2, 0x6a, 0xb, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x6d, 0x5, 0x44, 
    0x23, 0x2, 0x6c, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6d, 0x3, 0x2, 0x2, 
    0x2, 0x6d, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x77, 0x7, 0xd, 0x2, 0x2, 
    0x6f, 0x74, 0x5, 0x44, 0x23, 0x2, 0x70, 0x71, 0x7, 0x4, 0x2, 0x2, 0x71, 
    0x73, 0x5, 0x44, 0x23, 0x2, 0x72, 0x70, 0x3, 0x2, 0x2, 0x2, 0x73, 0x76, 
    0x3, 0x2, 0x2, 0x2, 0x74, 0x72, 0x3, 0x2, 0x2, 0x2, 0x74, 0x75, 0x3, 
    0x2, 0x2, 0x2, 0x75, 0x78, 0x3, 0x2, 0x2, 0x2, 0x76, 0x74, 0x3, 0x2, 
    0x2, 0x2, 0x77, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x77, 0x78, 0x3, 0x2, 0x2, 
    0x2, 0x78, 0x79, 0x3, 0x2, 0x2, 0x2, 0x79, 0x7b, 0x7, 0xe, 0x2, 0x2, 
    0x7a, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x7b, 
    0xd, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x7d, 0x5, 0x8, 0x5, 0x2, 0x7d, 0x82, 
    0x5, 0x10, 0x9, 0x2, 0x7e, 0x7f, 0x7, 0x4, 0x2, 0x2, 0x7f, 0x81, 0x5, 
    0x10, 0x9, 0x2, 0x80, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x81, 0x84, 0x3, 0x2, 
    0x2, 0x2, 0x82, 0x80, 0x3, 0x2, 0x2, 0x2, 0x82, 0x83, 0x3, 0x2, 0x2, 
    0x2, 0x83, 0x85, 0x3, 0x2, 0x2, 0x2, 0x84, 0x82, 0x3, 0x2, 0x2, 0x2, 
    0x85, 0x86, 0x7, 0x5, 0x2, 0x2, 0x86, 0xf, 0x3, 0x2, 0x2, 0x2, 0x87, 
    0x8b, 0x7, 0x27, 0x2, 0x2, 0x88, 0x89, 0x7, 0xa, 0x2, 0x2, 0x89, 0x8a, 
    0x7, 0x28, 0x2, 0x2, 0x8a, 0x8c, 0x7, 0xb, 0x2, 0x2, 0x8b, 0x88, 0x3, 
    0x2, 0x2, 0x2, 0x8b, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x8f, 0x3, 0x2, 
    0x2, 0x2, 0x8d, 0x8e, 0x7, 0xc, 0x2, 0x2, 0x8e, 0x90, 0x5, 0xc, 0x7, 
    0x2, 0x8f, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x90, 0x3, 0x2, 0x2, 0x2, 
    0x90, 0x11, 0x3, 0x2, 0x2, 0x2, 0x91, 0x92, 0x5, 0x14, 0xb, 0x2, 0x92, 
    0x93, 0x7, 0x27, 0x2, 0x2, 0x93, 0x95, 0x7, 0xf, 0x2, 0x2, 0x94, 0x96, 
    0x5, 0x16, 0xc, 0x2, 0x95, 0x94, 0x3, 0x2, 0x2, 0x2, 0x95, 0x96, 0x3, 
    0x2, 0x2, 0x2, 0x96, 0x97, 0x3, 0x2, 0x2, 0x2, 0x97, 0x98, 0x7, 0x10, 
    0x2, 0x2, 0x98, 0x99, 0x5, 0x1c, 0xf, 0x2, 0x99, 0x13, 0x3, 0x2, 0x2, 
    0x2, 0x9a, 0x9b, 0x9, 0x3, 0x2, 0x2, 0x9b, 0x15, 0x3, 0x2, 0x2, 0x2, 
    0x9c, 0xa1, 0x5, 0x18, 0xd, 0x2, 0x9d, 0x9e, 0x7, 0x4, 0x2, 0x2, 0x9e, 
    0xa0, 0x5, 0x18, 0xd, 0x2, 0x9f, 0x9d, 0x3, 0x2, 0x2, 0x2, 0xa0, 0xa3, 
    0x3, 0x2, 0x2, 0x2, 0xa1, 0x9f, 0x3, 0x2, 0x2, 0x2, 0xa1, 0xa2, 0x3, 
    0x2, 0x2, 0x2, 0xa2, 0x17, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xa1, 0x3, 0x2, 
    0x2, 0x2, 0xa4, 0xa5, 0x5, 0x8, 0x5, 0x2, 0xa5, 0xa7, 0x7, 0x27, 0x2, 
    0x2, 0xa6, 0xa8, 0x5, 0x1a, 0xe, 0x2, 0xa7, 0xa6, 0x3, 0x2, 0x2, 0x2, 
    0xa7, 0xa8, 0x3, 0x2, 0x2, 0x2, 0xa8, 0x19, 0x3, 0x2, 0x2, 0x2, 0xa9, 
    0xaa, 0x7, 0xa, 0x2, 0x2, 0xaa, 0xab, 0x7, 0xb, 0x2, 0x2, 0xab, 0x1b, 
    0x3, 0x2, 0x2, 0x2, 0xac, 0xb0, 0x7, 0xd, 0x2, 0x2, 0xad, 0xaf, 0x5, 
    0x1e, 0x10, 0x2, 0xae, 0xad, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xb2, 0x3, 0x2, 
    0x2, 0x2, 0xb0, 0xae, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xb1, 0x3, 0x2, 0x2, 
    0x2, 0xb1, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb2, 0xb0, 0x3, 0x2, 0x2, 0x2, 
    0xb3, 0xb4, 0x7, 0xe, 0x2, 0x2, 0xb4, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xb5, 
    0xb8, 0x5, 0x4, 0x3, 0x2, 0xb6, 0xb8, 0x5, 0x20, 0x11, 0x2, 0xb7, 0xb5, 
    0x3, 0x2, 0x2, 0x2, 0xb7, 0xb6, 0x3, 0x2, 0x2, 0x2, 0xb8, 0x1f, 0x3, 
    0x2, 0x2, 0x2, 0xb9, 0xba, 0x5, 0x2c, 0x17, 0x2, 0xba, 0xbb, 0x7, 0xc, 
    0x2, 0x2, 0xbb, 0xbc, 0x5, 0x28, 0x15, 0x2, 0xbc, 0xbd, 0x7, 0x5, 0x2, 
    0x2, 0xbd, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xc0, 0x5, 0x28, 0x15, 0x2, 
    0xbf, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xc0, 
    0xc1, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xd8, 0x7, 0x5, 0x2, 0x2, 0xc2, 0xd8, 
    0x5, 0x1c, 0xf, 0x2, 0xc3, 0xc4, 0x7, 0x12, 0x2, 0x2, 0xc4, 0xc5, 0x7, 
    0xf, 0x2, 0x2, 0xc5, 0xc6, 0x5, 0x2a, 0x16, 0x2, 0xc6, 0xc7, 0x7, 0x10, 
    0x2, 0x2, 0xc7, 0xca, 0x5, 0x20, 0x11, 0x2, 0xc8, 0xc9, 0x7, 0x13, 0x2, 
    0x2, 0xc9, 0xcb, 0x5, 0x20, 0x11, 0x2, 0xca, 0xc8, 0x3, 0x2, 0x2, 0x2, 
    0xca, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xcc, 
    0xcd, 0x7, 0x14, 0x2, 0x2, 0xcd, 0xce, 0x7, 0xf, 0x2, 0x2, 0xce, 0xcf, 
    0x5, 0x2a, 0x16, 0x2, 0xcf, 0xd0, 0x7, 0x10, 0x2, 0x2, 0xd0, 0xd1, 0x5, 
    0x26, 0x14, 0x2, 0xd1, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xd4, 0x7, 0x15, 
    0x2, 0x2, 0xd3, 0xd5, 0x5, 0x28, 0x15, 0x2, 0xd4, 0xd3, 0x3, 0x2, 0x2, 
    0x2, 0xd4, 0xd5, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xd6, 0x3, 0x2, 0x2, 0x2, 
    0xd6, 0xd8, 0x7, 0x5, 0x2, 0x2, 0xd7, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xd7, 
    0xbf, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xc3, 
    0x3, 0x2, 0x2, 0x2, 0xd7, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd2, 0x3, 
    0x2, 0x2, 0x2, 0xd8, 0x21, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xdd, 0x7, 0xd, 
    0x2, 0x2, 0xda, 0xdc, 0x5, 0x24, 0x13, 0x2, 0xdb, 0xda, 0x3, 0x2, 0x2, 
    0x2, 0xdc, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xdb, 0x3, 0x2, 0x2, 0x2, 
    0xdd, 0xde, 0x3, 0x2, 0x2, 0x2, 0xde, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xdf, 
    0xdd, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xe1, 0x7, 0xe, 0x2, 0x2, 0xe1, 0x23, 
    0x3, 0x2, 0x2, 0x2, 0xe2, 0xe5, 0x5, 0x4, 0x3, 0x2, 0xe3, 0xe5, 0x5, 
    0x26, 0x14, 0x2, 0xe4, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xe3, 0x3, 0x2, 
    0x2, 0x2, 0xe5, 0x25, 0x3, 0x2, 0x2, 0x2, 0xe6, 0xe7, 0x5, 0x2c, 0x17, 
    0x2, 0xe7, 0xe8, 0x7, 0xc, 0x2, 0x2, 0xe8, 0xe9, 0x5, 0x28, 0x15, 0x2, 
    0xe9, 0xea, 0x7, 0x5, 0x2, 0x2, 0xea, 0x109, 0x3, 0x2, 0x2, 0x2, 0xeb, 
    0xed, 0x5, 0x28, 0x15, 0x2, 0xec, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xec, 0xed, 
    0x3, 0x2, 0x2, 0x2, 0xed, 0xee, 0x3, 0x2, 0x2, 0x2, 0xee, 0x109, 0x7, 
    0x5, 0x2, 0x2, 0xef, 0x109, 0x5, 0x22, 0x12, 0x2, 0xf0, 0xf1, 0x7, 0x12, 
    0x2, 0x2, 0xf1, 0xf2, 0x7, 0xf, 0x2, 0x2, 0xf2, 0xf3, 0x5, 0x2a, 0x16, 
    0x2, 0xf3, 0xf4, 0x7, 0x10, 0x2, 0x2, 0xf4, 0xf7, 0x5, 0x26, 0x14, 0x2, 
    0xf5, 0xf6, 0x7, 0x13, 0x2, 0x2, 0xf6, 0xf8, 0x5, 0x26, 0x14, 0x2, 0xf7, 
    0xf5, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xf8, 0x3, 0x2, 0x2, 0x2, 0xf8, 0x109, 
    0x3, 0x2, 0x2, 0x2, 0xf9, 0xfa, 0x7, 0x14, 0x2, 0x2, 0xfa, 0xfb, 0x7, 
    0xf, 0x2, 0x2, 0xfb, 0xfc, 0x5, 0x2a, 0x16, 0x2, 0xfc, 0xfd, 0x7, 0x10, 
    0x2, 0x2, 0xfd, 0xfe, 0x5, 0x26, 0x14, 0x2, 0xfe, 0x109, 0x3, 0x2, 0x2, 
    0x2, 0xff, 0x100, 0x7, 0x16, 0x2, 0x2, 0x100, 0x109, 0x7, 0x5, 0x2, 
    0x2, 0x101, 0x102, 0x7, 0x17, 0x2, 0x2, 0x102, 0x109, 0x7, 0x5, 0x2, 
    0x2, 0x103, 0x105, 0x7, 0x15, 0x2, 0x2, 0x104, 0x106, 0x5, 0x28, 0x15, 
    0x2, 0x105, 0x104, 0x3, 0x2, 0x2, 0x2, 0x105, 0x106, 0x3, 0x2, 0x2, 
    0x2, 0x106, 0x107, 0x3, 0x2, 0x2, 0x2, 0x107, 0x109, 0x7, 0x5, 0x2, 
    0x2, 0x108, 0xe6, 0x3, 0x2, 0x2, 0x2, 0x108, 0xec, 0x3, 0x2, 0x2, 0x2, 
    0x108, 0xef, 0x3, 0x2, 0x2, 0x2, 0x108, 0xf0, 0x3, 0x2, 0x2, 0x2, 0x108, 
    0xf9, 0x3, 0x2, 0x2, 0x2, 0x108, 0xff, 0x3, 0x2, 0x2, 0x2, 0x108, 0x101, 
    0x3, 0x2, 0x2, 0x2, 0x108, 0x103, 0x3, 0x2, 0x2, 0x2, 0x109, 0x27, 0x3, 
    0x2, 0x2, 0x2, 0x10a, 0x10d, 0x5, 0x3a, 0x1e, 0x2, 0x10b, 0x10d, 0x7, 
    0x26, 0x2, 0x2, 0x10c, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x10c, 0x10b, 0x3, 
    0x2, 0x2, 0x2, 0x10d, 0x29, 0x3, 0x2, 0x2, 0x2, 0x10e, 0x10f, 0x5, 0x42, 
    0x22, 0x2, 0x10f, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x110, 0x115, 0x7, 0x27, 
    0x2, 0x2, 0x111, 0x112, 0x7, 0xa, 0x2, 0x2, 0x112, 0x113, 0x5, 0x28, 
    0x15, 0x2, 0x113, 0x114, 0x7, 0xb, 0x2, 0x2, 0x114, 0x116, 0x3, 0x2, 
    0x2, 0x2, 0x115, 0x111, 0x3, 0x2, 0x2, 0x2, 0x115, 0x116, 0x3, 0x2, 
    0x2, 0x2, 0x116, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x117, 0x118, 0x7, 0xf, 0x2, 
    0x2, 0x118, 0x119, 0x5, 0x28, 0x15, 0x2, 0x119, 0x11a, 0x7, 0x10, 0x2, 
    0x2, 0x11a, 0x11e, 0x3, 0x2, 0x2, 0x2, 0x11b, 0x11e, 0x5, 0x2c, 0x17, 
    0x2, 0x11c, 0x11e, 0x5, 0x46, 0x24, 0x2, 0x11d, 0x117, 0x3, 0x2, 0x2, 
    0x2, 0x11d, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x11d, 0x11c, 0x3, 0x2, 0x2, 
    0x2, 0x11e, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x12a, 0x5, 0x2e, 0x18, 
    0x2, 0x120, 0x121, 0x7, 0x27, 0x2, 0x2, 0x121, 0x123, 0x7, 0xf, 0x2, 
    0x2, 0x122, 0x124, 0x5, 0x34, 0x1b, 0x2, 0x123, 0x122, 0x3, 0x2, 0x2, 
    0x2, 0x123, 0x124, 0x3, 0x2, 0x2, 0x2, 0x124, 0x125, 0x3, 0x2, 0x2, 
    0x2, 0x125, 0x12a, 0x7, 0x10, 0x2, 0x2, 0x126, 0x127, 0x5, 0x32, 0x1a, 
    0x2, 0x127, 0x128, 0x5, 0x30, 0x19, 0x2, 0x128, 0x12a, 0x3, 0x2, 0x2, 
    0x2, 0x129, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x129, 0x120, 0x3, 0x2, 0x2, 
    0x2, 0x129, 0x126, 0x3, 0x2, 0x2, 0x2, 0x12a, 0x31, 0x3, 0x2, 0x2, 0x2, 
    0x12b, 0x12c, 0x9, 0x4, 0x2, 0x2, 0x12c, 0x33, 0x3, 0x2, 0x2, 0x2, 0x12d, 
    0x132, 0x5, 0x28, 0x15, 0x2, 0x12e, 0x12f, 0x7, 0x4, 0x2, 0x2, 0x12f, 
    0x131, 0x5, 0x28, 0x15, 0x2, 0x130, 0x12e, 0x3, 0x2, 0x2, 0x2, 0x131, 
    0x134, 0x3, 0x2, 0x2, 0x2, 0x132, 0x130, 0x3, 0x2, 0x2, 0x2, 0x132, 
    0x133, 0x3, 0x2, 0x2, 0x2, 0x133, 0x35, 0x3, 0x2, 0x2, 0x2, 0x134, 0x132, 
    0x3, 0x2, 0x2, 0x2, 0x135, 0x136, 0x8, 0x1c, 0x1, 0x2, 0x136, 0x137, 
    0x5, 0x30, 0x19, 0x2, 0x137, 0x13e, 0x3, 0x2, 0x2, 0x2, 0x138, 0x139, 
    0xc, 0x3, 0x2, 0x2, 0x139, 0x13a, 0x5, 0x38, 0x1d, 0x2, 0x13a, 0x13b, 
    0x5, 0x30, 0x19, 0x2, 0x13b, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x13c, 0x138, 
    0x3, 0x2, 0x2, 0x2, 0x13d, 0x140, 0x3, 0x2, 0x2, 0x2, 0x13e, 0x13c, 
    0x3, 0x2, 0x2, 0x2, 0x13e, 0x13f, 0x3, 0x2, 0x2, 0x2, 0x13f, 0x37, 0x3, 
    0x2, 0x2, 0x2, 0x140, 0x13e, 0x3, 0x2, 0x2, 0x2, 0x141, 0x142, 0x9, 
    0x5, 0x2, 0x2, 0x142, 0x39, 0x3, 0x2, 0x2, 0x2, 0x143, 0x144, 0x8, 0x1e, 
    0x1, 0x2, 0x144, 0x145, 0x5, 0x36, 0x1c, 0x2, 0x145, 0x14b, 0x3, 0x2, 
    0x2, 0x2, 0x146, 0x147, 0xc, 0x3, 0x2, 0x2, 0x147, 0x148, 0x9, 0x6, 
    0x2, 0x2, 0x148, 0x14a, 0x5, 0x36, 0x1c, 0x2, 0x149, 0x146, 0x3, 0x2, 
    0x2, 0x2, 0x14a, 0x14d, 0x3, 0x2, 0x2, 0x2, 0x14b, 0x149, 0x3, 0x2, 
    0x2, 0x2, 0x14b, 0x14c, 0x3, 0x2, 0x2, 0x2, 0x14c, 0x3b, 0x3, 0x2, 0x2, 
    0x2, 0x14d, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x14e, 0x14f, 0x8, 0x1f, 0x1, 
    0x2, 0x14f, 0x152, 0x5, 0x3a, 0x1e, 0x2, 0x150, 0x152, 0x7, 0x26, 0x2, 
    0x2, 0x151, 0x14e, 0x3, 0x2, 0x2, 0x2, 0x151, 0x150, 0x3, 0x2, 0x2, 
    0x2, 0x152, 0x158, 0x3, 0x2, 0x2, 0x2, 0x153, 0x154, 0xc, 0x4, 0x2, 
    0x2, 0x154, 0x155, 0x9, 0x7, 0x2, 0x2, 0x155, 0x157, 0x5, 0x3a, 0x1e, 
    0x2, 0x156, 0x153, 0x3, 0x2, 0x2, 0x2, 0x157, 0x15a, 0x3, 0x2, 0x2, 
    0x2, 0x158, 0x156, 0x3, 0x2, 0x2, 0x2, 0x158, 0x159, 0x3, 0x2, 0x2, 
    0x2, 0x159, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x15a, 0x158, 0x3, 0x2, 0x2, 0x2, 
    0x15b, 0x15c, 0x8, 0x20, 0x1, 0x2, 0x15c, 0x15d, 0x5, 0x3c, 0x1f, 0x2, 
    0x15d, 0x163, 0x3, 0x2, 0x2, 0x2, 0x15e, 0x15f, 0xc, 0x3, 0x2, 0x2, 
    0x15f, 0x160, 0x9, 0x8, 0x2, 0x2, 0x160, 0x162, 0x5, 0x3c, 0x1f, 0x2, 
    0x161, 0x15e, 0x3, 0x2, 0x2, 0x2, 0x162, 0x165, 0x3, 0x2, 0x2, 0x2, 
    0x163, 0x161, 0x3, 0x2, 0x2, 0x2, 0x163, 0x164, 0x3, 0x2, 0x2, 0x2, 
    0x164, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x165, 0x163, 0x3, 0x2, 0x2, 0x2, 0x166, 
    0x167, 0x8, 0x21, 0x1, 0x2, 0x167, 0x168, 0x5, 0x3e, 0x20, 0x2, 0x168, 
    0x16e, 0x3, 0x2, 0x2, 0x2, 0x169, 0x16a, 0xc, 0x3, 0x2, 0x2, 0x16a, 
    0x16b, 0x7, 0x24, 0x2, 0x2, 0x16b, 0x16d, 0x5, 0x3e, 0x20, 0x2, 0x16c, 
    0x169, 0x3, 0x2, 0x2, 0x2, 0x16d, 0x170, 0x3, 0x2, 0x2, 0x2, 0x16e, 
    0x16c, 0x3, 0x2, 0x2, 0x2, 0x16e, 0x16f, 0x3, 0x2, 0x2, 0x2, 0x16f, 
    0x41, 0x3, 0x2, 0x2, 0x2, 0x170, 0x16e, 0x3, 0x2, 0x2, 0x2, 0x171, 0x172, 
    0x8, 0x22, 0x1, 0x2, 0x172, 0x173, 0x5, 0x40, 0x21, 0x2, 0x173, 0x179, 
    0x3, 0x2, 0x2, 0x2, 0x174, 0x175, 0xc, 0x3, 0x2, 0x2, 0x175, 0x176, 
    0x7, 0x25, 0x2, 0x2, 0x176, 0x178, 0x5, 0x40, 0x21, 0x2, 0x177, 0x174, 
    0x3, 0x2, 0x2, 0x2, 0x178, 0x17b, 0x3, 0x2, 0x2, 0x2, 0x179, 0x177, 
    0x3, 0x2, 0x2, 0x2, 0x179, 0x17a, 0x3, 0x2, 0x2, 0x2, 0x17a, 0x43, 0x3, 
    0x2, 0x2, 0x2, 0x17b, 0x179, 0x3, 0x2, 0x2, 0x2, 0x17c, 0x17f, 0x5, 
    0x46, 0x24, 0x2, 0x17d, 0x17f, 0x7, 0x26, 0x2, 0x2, 0x17e, 0x17c, 0x3, 
    0x2, 0x2, 0x2, 0x17e, 0x17d, 0x3, 0x2, 0x2, 0x2, 0x17f, 0x45, 0x3, 0x2, 
    0x2, 0x2, 0x180, 0x184, 0x7, 0x28, 0x2, 0x2, 0x181, 0x184, 0x7, 0x2b, 
    0x2, 0x2, 0x182, 0x184, 0x7, 0x2a, 0x2, 0x2, 0x183, 0x180, 0x3, 0x2, 
    0x2, 0x2, 0x183, 0x181, 0x3, 0x2, 0x2, 0x2, 0x183, 0x182, 0x3, 0x2, 
    0x2, 0x2, 0x184, 0x47, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x4a, 0x4c, 0x52, 0x5b, 
    0x66, 0x6c, 0x74, 0x77, 0x7a, 0x82, 0x8b, 0x8f, 0x95, 0xa1, 0xa7, 0xb0, 
    0xb7, 0xbf, 0xca, 0xd4, 0xd7, 0xdd, 0xe4, 0xec, 0xf7, 0x105, 0x108, 
    0x10c, 0x115, 0x11d, 0x123, 0x129, 0x132, 0x13e, 0x14b, 0x151, 0x158, 
    0x163, 0x16e, 0x179, 0x17e, 0x183, 
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
