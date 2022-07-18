
    #include "../src/SymbolTable.h"


// Generated from /Volumes/study/code/C++/vscode/compiler/compiler/grammar/SysY.g4 by ANTLR 4.8



#include "SysYParser.h"


using namespace antlrcpp;
using namespace antlr4;

SysYParser::SysYParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

SysYParser::~SysYParser() {
  delete _interpreter;
}

std::string SysYParser::getGrammarFileName() const {
  return "SysY.g4";
}

const std::vector<std::string>& SysYParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& SysYParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- CompUnitContext ------------------------------------------------------------------

SysYParser::CompUnitContext::CompUnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SysYParser::CompUnitContext::EOF() {
  return getToken(SysYParser::EOF, 0);
}

std::vector<SysYParser::DeclContext *> SysYParser::CompUnitContext::decl() {
  return getRuleContexts<SysYParser::DeclContext>();
}

SysYParser::DeclContext* SysYParser::CompUnitContext::decl(size_t i) {
  return getRuleContext<SysYParser::DeclContext>(i);
}

std::vector<SysYParser::FuncDefContext *> SysYParser::CompUnitContext::funcDef() {
  return getRuleContexts<SysYParser::FuncDefContext>();
}

SysYParser::FuncDefContext* SysYParser::CompUnitContext::funcDef(size_t i) {
  return getRuleContext<SysYParser::FuncDefContext>(i);
}


size_t SysYParser::CompUnitContext::getRuleIndex() const {
  return SysYParser::RuleCompUnit;
}


SysYParser::CompUnitContext* SysYParser::compUnit() {
  CompUnitContext *_localctx = _tracker.createInstance<CompUnitContext>(_ctx, getState());
  enterRule(_localctx, 0, SysYParser::RuleCompUnit);
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
      ((1ULL << _la) & ((1ULL << SysYParser::T__0)
      | (1ULL << SysYParser::T__3)
      | (1ULL << SysYParser::T__4)
      | (1ULL << SysYParser::T__5)
      | (1ULL << SysYParser::T__6)
      | (1ULL << SysYParser::T__14))) != 0));
    setState(76);
    match(SysYParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclContext ------------------------------------------------------------------

SysYParser::DeclContext::DeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::ConstDeclContext* SysYParser::DeclContext::constDecl() {
  return getRuleContext<SysYParser::ConstDeclContext>(0);
}

SysYParser::VarDeclContext* SysYParser::DeclContext::varDecl() {
  return getRuleContext<SysYParser::VarDeclContext>(0);
}


size_t SysYParser::DeclContext::getRuleIndex() const {
  return SysYParser::RuleDecl;
}


SysYParser::DeclContext* SysYParser::decl() {
  DeclContext *_localctx = _tracker.createInstance<DeclContext>(_ctx, getState());
  enterRule(_localctx, 2, SysYParser::RuleDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(80);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SysYParser::T__0: {
        enterOuterAlt(_localctx, 1);
        setState(78);
        constDecl();
        break;
      }

      case SysYParser::T__3:
      case SysYParser::T__4:
      case SysYParser::T__5:
      case SysYParser::T__6: {
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

SysYParser::ConstDeclContext::ConstDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::BTypeContext* SysYParser::ConstDeclContext::bType() {
  return getRuleContext<SysYParser::BTypeContext>(0);
}

std::vector<SysYParser::ConstDefContext *> SysYParser::ConstDeclContext::constDef() {
  return getRuleContexts<SysYParser::ConstDefContext>();
}

SysYParser::ConstDefContext* SysYParser::ConstDeclContext::constDef(size_t i) {
  return getRuleContext<SysYParser::ConstDefContext>(i);
}


size_t SysYParser::ConstDeclContext::getRuleIndex() const {
  return SysYParser::RuleConstDecl;
}


SysYParser::ConstDeclContext* SysYParser::constDecl() {
  ConstDeclContext *_localctx = _tracker.createInstance<ConstDeclContext>(_ctx, getState());
  enterRule(_localctx, 4, SysYParser::RuleConstDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(82);
    match(SysYParser::T__0);
    setState(83);
    bType();
    setState(84);
    constDef();
    setState(89);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SysYParser::T__1) {
      setState(85);
      match(SysYParser::T__1);
      setState(86);
      constDef();
      setState(91);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(92);
    match(SysYParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BTypeContext ------------------------------------------------------------------

SysYParser::BTypeContext::BTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SysYParser::BTypeContext::getRuleIndex() const {
  return SysYParser::RuleBType;
}


SysYParser::BTypeContext* SysYParser::bType() {
  BTypeContext *_localctx = _tracker.createInstance<BTypeContext>(_ctx, getState());
  enterRule(_localctx, 6, SysYParser::RuleBType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(94);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SysYParser::T__3)
      | (1ULL << SysYParser::T__4)
      | (1ULL << SysYParser::T__5)
      | (1ULL << SysYParser::T__6))) != 0))) {
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

SysYParser::ConstDefContext::ConstDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SysYParser::ConstDefContext::Ident() {
  return getToken(SysYParser::Ident, 0);
}

SysYParser::ConstInitValContext* SysYParser::ConstDefContext::constInitVal() {
  return getRuleContext<SysYParser::ConstInitValContext>(0);
}

tree::TerminalNode* SysYParser::ConstDefContext::IntConst() {
  return getToken(SysYParser::IntConst, 0);
}


size_t SysYParser::ConstDefContext::getRuleIndex() const {
  return SysYParser::RuleConstDef;
}


SysYParser::ConstDefContext* SysYParser::constDef() {
  ConstDefContext *_localctx = _tracker.createInstance<ConstDefContext>(_ctx, getState());
  enterRule(_localctx, 8, SysYParser::RuleConstDef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(96);
    match(SysYParser::Ident);
    setState(100);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SysYParser::T__7) {
      setState(97);
      match(SysYParser::T__7);
      setState(98);
      match(SysYParser::IntConst);
      setState(99);
      match(SysYParser::T__8);
    }
    setState(102);
    match(SysYParser::T__9);
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

SysYParser::ConstInitValContext::ConstInitValContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SysYParser::ConstInitValContext::getRuleIndex() const {
  return SysYParser::RuleConstInitVal;
}

void SysYParser::ConstInitValContext::copyFrom(ConstInitValContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->type = ctx->type;
  this->size = ctx->size;
  this->isArray = ctx->isArray;
}

//----------------- ConstInitValOfVarContext ------------------------------------------------------------------

SysYParser::ConstExpContext* SysYParser::ConstInitValOfVarContext::constExp() {
  return getRuleContext<SysYParser::ConstExpContext>(0);
}

SysYParser::ConstInitValOfVarContext::ConstInitValOfVarContext(ConstInitValContext *ctx) { copyFrom(ctx); }


//----------------- ConstInitValOfArrayContext ------------------------------------------------------------------

std::vector<SysYParser::ConstExpContext *> SysYParser::ConstInitValOfArrayContext::constExp() {
  return getRuleContexts<SysYParser::ConstExpContext>();
}

SysYParser::ConstExpContext* SysYParser::ConstInitValOfArrayContext::constExp(size_t i) {
  return getRuleContext<SysYParser::ConstExpContext>(i);
}

SysYParser::ConstInitValOfArrayContext::ConstInitValOfArrayContext(ConstInitValContext *ctx) { copyFrom(ctx); }


SysYParser::ConstInitValContext* SysYParser::constInitVal() {
  ConstInitValContext *_localctx = _tracker.createInstance<ConstInitValContext>(_ctx, getState());
  enterRule(_localctx, 10, SysYParser::RuleConstInitVal);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(120);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SysYParser::T__1:
      case SysYParser::T__2:
      case SysYParser::BoolConst:
      case SysYParser::IntConst:
      case SysYParser::FloatConst:
      case SysYParser::DoubleConst: {
        _localctx = dynamic_cast<ConstInitValContext *>(_tracker.createInstance<SysYParser::ConstInitValOfVarContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(106);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << SysYParser::BoolConst)
          | (1ULL << SysYParser::IntConst)
          | (1ULL << SysYParser::FloatConst)
          | (1ULL << SysYParser::DoubleConst))) != 0)) {
          setState(105);
          constExp();
        }
        break;
      }

      case SysYParser::T__10: {
        _localctx = dynamic_cast<ConstInitValContext *>(_tracker.createInstance<SysYParser::ConstInitValOfArrayContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(108);
        match(SysYParser::T__10);
        setState(117);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << SysYParser::BoolConst)
          | (1ULL << SysYParser::IntConst)
          | (1ULL << SysYParser::FloatConst)
          | (1ULL << SysYParser::DoubleConst))) != 0)) {
          setState(109);
          constExp();
          setState(114);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == SysYParser::T__1) {
            setState(110);
            match(SysYParser::T__1);
            setState(111);
            constExp();
            setState(116);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
        }
        setState(119);
        match(SysYParser::T__11);
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

SysYParser::VarDeclContext::VarDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::BTypeContext* SysYParser::VarDeclContext::bType() {
  return getRuleContext<SysYParser::BTypeContext>(0);
}

std::vector<SysYParser::VarDefContext *> SysYParser::VarDeclContext::varDef() {
  return getRuleContexts<SysYParser::VarDefContext>();
}

SysYParser::VarDefContext* SysYParser::VarDeclContext::varDef(size_t i) {
  return getRuleContext<SysYParser::VarDefContext>(i);
}


size_t SysYParser::VarDeclContext::getRuleIndex() const {
  return SysYParser::RuleVarDecl;
}


SysYParser::VarDeclContext* SysYParser::varDecl() {
  VarDeclContext *_localctx = _tracker.createInstance<VarDeclContext>(_ctx, getState());
  enterRule(_localctx, 12, SysYParser::RuleVarDecl);
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
    while (_la == SysYParser::T__1) {
      setState(124);
      match(SysYParser::T__1);
      setState(125);
      varDef();
      setState(130);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(131);
    match(SysYParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDefContext ------------------------------------------------------------------

SysYParser::VarDefContext::VarDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SysYParser::VarDefContext::Ident() {
  return getToken(SysYParser::Ident, 0);
}

tree::TerminalNode* SysYParser::VarDefContext::IntConst() {
  return getToken(SysYParser::IntConst, 0);
}

SysYParser::ConstInitValContext* SysYParser::VarDefContext::constInitVal() {
  return getRuleContext<SysYParser::ConstInitValContext>(0);
}


size_t SysYParser::VarDefContext::getRuleIndex() const {
  return SysYParser::RuleVarDef;
}


SysYParser::VarDefContext* SysYParser::varDef() {
  VarDefContext *_localctx = _tracker.createInstance<VarDefContext>(_ctx, getState());
  enterRule(_localctx, 14, SysYParser::RuleVarDef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(133);
    match(SysYParser::Ident);
    setState(137);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SysYParser::T__7) {
      setState(134);
      match(SysYParser::T__7);
      setState(135);
      match(SysYParser::IntConst);
      setState(136);
      match(SysYParser::T__8);
    }
    setState(141);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SysYParser::T__9) {
      setState(139);
      match(SysYParser::T__9);
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

SysYParser::FuncDefContext::FuncDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::FuncTypeContext* SysYParser::FuncDefContext::funcType() {
  return getRuleContext<SysYParser::FuncTypeContext>(0);
}

tree::TerminalNode* SysYParser::FuncDefContext::Ident() {
  return getToken(SysYParser::Ident, 0);
}

SysYParser::FuncBlockContext* SysYParser::FuncDefContext::funcBlock() {
  return getRuleContext<SysYParser::FuncBlockContext>(0);
}

SysYParser::FuncFParamsContext* SysYParser::FuncDefContext::funcFParams() {
  return getRuleContext<SysYParser::FuncFParamsContext>(0);
}


size_t SysYParser::FuncDefContext::getRuleIndex() const {
  return SysYParser::RuleFuncDef;
}


SysYParser::FuncDefContext* SysYParser::funcDef() {
  FuncDefContext *_localctx = _tracker.createInstance<FuncDefContext>(_ctx, getState());
  enterRule(_localctx, 16, SysYParser::RuleFuncDef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(143);
    funcType();
    setState(144);
    match(SysYParser::Ident);
    setState(145);
    match(SysYParser::T__12);
    setState(147);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SysYParser::T__3)
      | (1ULL << SysYParser::T__4)
      | (1ULL << SysYParser::T__5)
      | (1ULL << SysYParser::T__6))) != 0)) {
      setState(146);
      funcFParams();
    }
    setState(149);
    match(SysYParser::T__13);
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

SysYParser::FuncTypeContext::FuncTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SysYParser::FuncTypeContext::getRuleIndex() const {
  return SysYParser::RuleFuncType;
}


SysYParser::FuncTypeContext* SysYParser::funcType() {
  FuncTypeContext *_localctx = _tracker.createInstance<FuncTypeContext>(_ctx, getState());
  enterRule(_localctx, 18, SysYParser::RuleFuncType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(152);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SysYParser::T__3)
      | (1ULL << SysYParser::T__4)
      | (1ULL << SysYParser::T__5)
      | (1ULL << SysYParser::T__6)
      | (1ULL << SysYParser::T__14))) != 0))) {
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

SysYParser::FuncFParamsContext::FuncFParamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SysYParser::FuncFParamContext *> SysYParser::FuncFParamsContext::funcFParam() {
  return getRuleContexts<SysYParser::FuncFParamContext>();
}

SysYParser::FuncFParamContext* SysYParser::FuncFParamsContext::funcFParam(size_t i) {
  return getRuleContext<SysYParser::FuncFParamContext>(i);
}


size_t SysYParser::FuncFParamsContext::getRuleIndex() const {
  return SysYParser::RuleFuncFParams;
}


SysYParser::FuncFParamsContext* SysYParser::funcFParams() {
  FuncFParamsContext *_localctx = _tracker.createInstance<FuncFParamsContext>(_ctx, getState());
  enterRule(_localctx, 20, SysYParser::RuleFuncFParams);
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
    while (_la == SysYParser::T__1) {
      setState(155);
      match(SysYParser::T__1);
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

SysYParser::FuncFParamContext::FuncFParamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::BTypeContext* SysYParser::FuncFParamContext::bType() {
  return getRuleContext<SysYParser::BTypeContext>(0);
}

tree::TerminalNode* SysYParser::FuncFParamContext::Ident() {
  return getToken(SysYParser::Ident, 0);
}

SysYParser::BracketsContext* SysYParser::FuncFParamContext::brackets() {
  return getRuleContext<SysYParser::BracketsContext>(0);
}


size_t SysYParser::FuncFParamContext::getRuleIndex() const {
  return SysYParser::RuleFuncFParam;
}


SysYParser::FuncFParamContext* SysYParser::funcFParam() {
  FuncFParamContext *_localctx = _tracker.createInstance<FuncFParamContext>(_ctx, getState());
  enterRule(_localctx, 22, SysYParser::RuleFuncFParam);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(162);
    bType();
    setState(163);
    match(SysYParser::Ident);
    setState(165);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SysYParser::T__7) {
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

SysYParser::BracketsContext::BracketsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SysYParser::BracketsContext::getRuleIndex() const {
  return SysYParser::RuleBrackets;
}


SysYParser::BracketsContext* SysYParser::brackets() {
  BracketsContext *_localctx = _tracker.createInstance<BracketsContext>(_ctx, getState());
  enterRule(_localctx, 24, SysYParser::RuleBrackets);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(167);
    match(SysYParser::T__7);
    setState(168);
    match(SysYParser::T__8);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncBlockContext ------------------------------------------------------------------

SysYParser::FuncBlockContext::FuncBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SysYParser::FuncBlockItemContext *> SysYParser::FuncBlockContext::funcBlockItem() {
  return getRuleContexts<SysYParser::FuncBlockItemContext>();
}

SysYParser::FuncBlockItemContext* SysYParser::FuncBlockContext::funcBlockItem(size_t i) {
  return getRuleContext<SysYParser::FuncBlockItemContext>(i);
}


size_t SysYParser::FuncBlockContext::getRuleIndex() const {
  return SysYParser::RuleFuncBlock;
}


SysYParser::FuncBlockContext* SysYParser::funcBlock() {
  FuncBlockContext *_localctx = _tracker.createInstance<FuncBlockContext>(_ctx, getState());
  enterRule(_localctx, 26, SysYParser::RuleFuncBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(170);
    match(SysYParser::T__10);
    setState(174);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SysYParser::T__0)
      | (1ULL << SysYParser::T__2)
      | (1ULL << SysYParser::T__3)
      | (1ULL << SysYParser::T__4)
      | (1ULL << SysYParser::T__5)
      | (1ULL << SysYParser::T__6)
      | (1ULL << SysYParser::T__10)
      | (1ULL << SysYParser::T__12)
      | (1ULL << SysYParser::T__15)
      | (1ULL << SysYParser::T__17)
      | (1ULL << SysYParser::T__18)
      | (1ULL << SysYParser::T__21)
      | (1ULL << SysYParser::T__22)
      | (1ULL << SysYParser::T__23)
      | (1ULL << SysYParser::BoolConst)
      | (1ULL << SysYParser::Ident)
      | (1ULL << SysYParser::IntConst)
      | (1ULL << SysYParser::FloatConst)
      | (1ULL << SysYParser::DoubleConst))) != 0)) {
      setState(171);
      funcBlockItem();
      setState(176);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(177);
    match(SysYParser::T__11);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncBlockItemContext ------------------------------------------------------------------

SysYParser::FuncBlockItemContext::FuncBlockItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::DeclContext* SysYParser::FuncBlockItemContext::decl() {
  return getRuleContext<SysYParser::DeclContext>(0);
}

SysYParser::StmtContext* SysYParser::FuncBlockItemContext::stmt() {
  return getRuleContext<SysYParser::StmtContext>(0);
}


size_t SysYParser::FuncBlockItemContext::getRuleIndex() const {
  return SysYParser::RuleFuncBlockItem;
}


SysYParser::FuncBlockItemContext* SysYParser::funcBlockItem() {
  FuncBlockItemContext *_localctx = _tracker.createInstance<FuncBlockItemContext>(_ctx, getState());
  enterRule(_localctx, 28, SysYParser::RuleFuncBlockItem);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(181);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SysYParser::T__0:
      case SysYParser::T__3:
      case SysYParser::T__4:
      case SysYParser::T__5:
      case SysYParser::T__6: {
        enterOuterAlt(_localctx, 1);
        setState(179);
        decl();
        break;
      }

      case SysYParser::T__2:
      case SysYParser::T__10:
      case SysYParser::T__12:
      case SysYParser::T__15:
      case SysYParser::T__17:
      case SysYParser::T__18:
      case SysYParser::T__21:
      case SysYParser::T__22:
      case SysYParser::T__23:
      case SysYParser::BoolConst:
      case SysYParser::Ident:
      case SysYParser::IntConst:
      case SysYParser::FloatConst:
      case SysYParser::DoubleConst: {
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

SysYParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SysYParser::StmtContext::getRuleIndex() const {
  return SysYParser::RuleStmt;
}

void SysYParser::StmtContext::copyFrom(StmtContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->hasReturn = ctx->hasReturn;
  this->returnType = ctx->returnType;
}

//----------------- StmtBlockContext ------------------------------------------------------------------

SysYParser::FuncBlockContext* SysYParser::StmtBlockContext::funcBlock() {
  return getRuleContext<SysYParser::FuncBlockContext>(0);
}

SysYParser::StmtBlockContext::StmtBlockContext(StmtContext *ctx) { copyFrom(ctx); }


//----------------- StmtExpressionContext ------------------------------------------------------------------

SysYParser::ExpContext* SysYParser::StmtExpressionContext::exp() {
  return getRuleContext<SysYParser::ExpContext>(0);
}

SysYParser::StmtExpressionContext::StmtExpressionContext(StmtContext *ctx) { copyFrom(ctx); }


//----------------- StmtAssignmentContext ------------------------------------------------------------------

SysYParser::LValContext* SysYParser::StmtAssignmentContext::lVal() {
  return getRuleContext<SysYParser::LValContext>(0);
}

SysYParser::ExpContext* SysYParser::StmtAssignmentContext::exp() {
  return getRuleContext<SysYParser::ExpContext>(0);
}

SysYParser::StmtAssignmentContext::StmtAssignmentContext(StmtContext *ctx) { copyFrom(ctx); }


//----------------- StmtCtrlSeqContext ------------------------------------------------------------------

SysYParser::CondContext* SysYParser::StmtCtrlSeqContext::cond() {
  return getRuleContext<SysYParser::CondContext>(0);
}

std::vector<SysYParser::StmtContext *> SysYParser::StmtCtrlSeqContext::stmt() {
  return getRuleContexts<SysYParser::StmtContext>();
}

SysYParser::StmtContext* SysYParser::StmtCtrlSeqContext::stmt(size_t i) {
  return getRuleContext<SysYParser::StmtContext>(i);
}

SysYParser::SubStmtContext* SysYParser::StmtCtrlSeqContext::subStmt() {
  return getRuleContext<SysYParser::SubStmtContext>(0);
}

SysYParser::StmtCtrlSeqContext::StmtCtrlSeqContext(StmtContext *ctx) { copyFrom(ctx); }


//----------------- StmtReturnContext ------------------------------------------------------------------

SysYParser::ExpContext* SysYParser::StmtReturnContext::exp() {
  return getRuleContext<SysYParser::ExpContext>(0);
}

SysYParser::StmtReturnContext::StmtReturnContext(StmtContext *ctx) { copyFrom(ctx); }


SysYParser::StmtContext* SysYParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 30, SysYParser::RuleStmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(213);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<SysYParser::StmtAssignmentContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(183);
      lVal();
      setState(184);
      match(SysYParser::T__9);
      setState(185);
      exp();
      setState(186);
      match(SysYParser::T__2);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<SysYParser::StmtExpressionContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(189);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << SysYParser::T__12)
        | (1ULL << SysYParser::T__21)
        | (1ULL << SysYParser::T__22)
        | (1ULL << SysYParser::T__23)
        | (1ULL << SysYParser::BoolConst)
        | (1ULL << SysYParser::Ident)
        | (1ULL << SysYParser::IntConst)
        | (1ULL << SysYParser::FloatConst)
        | (1ULL << SysYParser::DoubleConst))) != 0)) {
        setState(188);
        exp();
      }
      setState(191);
      match(SysYParser::T__2);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<SysYParser::StmtBlockContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(192);
      funcBlock();
      break;
    }

    case 4: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<SysYParser::StmtCtrlSeqContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(193);
      match(SysYParser::T__15);
      setState(194);
      match(SysYParser::T__12);
      setState(195);
      cond();
      setState(196);
      match(SysYParser::T__13);
      setState(197);
      stmt();
      setState(200);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
      case 1: {
        setState(198);
        match(SysYParser::T__16);
        setState(199);
        stmt();
        break;
      }

      }
      break;
    }

    case 5: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<SysYParser::StmtCtrlSeqContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(202);
      match(SysYParser::T__17);
      setState(203);
      match(SysYParser::T__12);
      setState(204);
      cond();
      setState(205);
      match(SysYParser::T__13);
      setState(206);
      subStmt();
      break;
    }

    case 6: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<SysYParser::StmtReturnContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(208);
      match(SysYParser::T__18);
      setState(210);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << SysYParser::T__12)
        | (1ULL << SysYParser::T__21)
        | (1ULL << SysYParser::T__22)
        | (1ULL << SysYParser::T__23)
        | (1ULL << SysYParser::BoolConst)
        | (1ULL << SysYParser::Ident)
        | (1ULL << SysYParser::IntConst)
        | (1ULL << SysYParser::FloatConst)
        | (1ULL << SysYParser::DoubleConst))) != 0)) {
        setState(209);
        exp();
      }
      setState(212);
      match(SysYParser::T__2);
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

SysYParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SysYParser::BlockItemContext *> SysYParser::BlockContext::blockItem() {
  return getRuleContexts<SysYParser::BlockItemContext>();
}

SysYParser::BlockItemContext* SysYParser::BlockContext::blockItem(size_t i) {
  return getRuleContext<SysYParser::BlockItemContext>(i);
}


size_t SysYParser::BlockContext::getRuleIndex() const {
  return SysYParser::RuleBlock;
}


SysYParser::BlockContext* SysYParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 32, SysYParser::RuleBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(215);
    match(SysYParser::T__10);
    setState(219);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SysYParser::T__0)
      | (1ULL << SysYParser::T__2)
      | (1ULL << SysYParser::T__3)
      | (1ULL << SysYParser::T__4)
      | (1ULL << SysYParser::T__5)
      | (1ULL << SysYParser::T__6)
      | (1ULL << SysYParser::T__10)
      | (1ULL << SysYParser::T__12)
      | (1ULL << SysYParser::T__15)
      | (1ULL << SysYParser::T__17)
      | (1ULL << SysYParser::T__18)
      | (1ULL << SysYParser::T__19)
      | (1ULL << SysYParser::T__20)
      | (1ULL << SysYParser::T__21)
      | (1ULL << SysYParser::T__22)
      | (1ULL << SysYParser::T__23)
      | (1ULL << SysYParser::BoolConst)
      | (1ULL << SysYParser::Ident)
      | (1ULL << SysYParser::IntConst)
      | (1ULL << SysYParser::FloatConst)
      | (1ULL << SysYParser::DoubleConst))) != 0)) {
      setState(216);
      blockItem();
      setState(221);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(222);
    match(SysYParser::T__11);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockItemContext ------------------------------------------------------------------

SysYParser::BlockItemContext::BlockItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::DeclContext* SysYParser::BlockItemContext::decl() {
  return getRuleContext<SysYParser::DeclContext>(0);
}

SysYParser::SubStmtContext* SysYParser::BlockItemContext::subStmt() {
  return getRuleContext<SysYParser::SubStmtContext>(0);
}


size_t SysYParser::BlockItemContext::getRuleIndex() const {
  return SysYParser::RuleBlockItem;
}


SysYParser::BlockItemContext* SysYParser::blockItem() {
  BlockItemContext *_localctx = _tracker.createInstance<BlockItemContext>(_ctx, getState());
  enterRule(_localctx, 34, SysYParser::RuleBlockItem);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(226);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SysYParser::T__0:
      case SysYParser::T__3:
      case SysYParser::T__4:
      case SysYParser::T__5:
      case SysYParser::T__6: {
        enterOuterAlt(_localctx, 1);
        setState(224);
        decl();
        break;
      }

      case SysYParser::T__2:
      case SysYParser::T__10:
      case SysYParser::T__12:
      case SysYParser::T__15:
      case SysYParser::T__17:
      case SysYParser::T__18:
      case SysYParser::T__19:
      case SysYParser::T__20:
      case SysYParser::T__21:
      case SysYParser::T__22:
      case SysYParser::T__23:
      case SysYParser::BoolConst:
      case SysYParser::Ident:
      case SysYParser::IntConst:
      case SysYParser::FloatConst:
      case SysYParser::DoubleConst: {
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

SysYParser::SubStmtContext::SubStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SysYParser::SubStmtContext::getRuleIndex() const {
  return SysYParser::RuleSubStmt;
}

void SysYParser::SubStmtContext::copyFrom(SubStmtContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->hasReturn = ctx->hasReturn;
  this->returnType = ctx->returnType;
}

//----------------- SubStmtExpressionContext ------------------------------------------------------------------

SysYParser::ExpContext* SysYParser::SubStmtExpressionContext::exp() {
  return getRuleContext<SysYParser::ExpContext>(0);
}

SysYParser::SubStmtExpressionContext::SubStmtExpressionContext(SubStmtContext *ctx) { copyFrom(ctx); }


//----------------- SubStmtBlockContext ------------------------------------------------------------------

SysYParser::BlockContext* SysYParser::SubStmtBlockContext::block() {
  return getRuleContext<SysYParser::BlockContext>(0);
}

SysYParser::SubStmtBlockContext::SubStmtBlockContext(SubStmtContext *ctx) { copyFrom(ctx); }


//----------------- SubStmtAssignmentContext ------------------------------------------------------------------

SysYParser::LValContext* SysYParser::SubStmtAssignmentContext::lVal() {
  return getRuleContext<SysYParser::LValContext>(0);
}

SysYParser::ExpContext* SysYParser::SubStmtAssignmentContext::exp() {
  return getRuleContext<SysYParser::ExpContext>(0);
}

SysYParser::SubStmtAssignmentContext::SubStmtAssignmentContext(SubStmtContext *ctx) { copyFrom(ctx); }


//----------------- SubStmtCtrlSeqContext ------------------------------------------------------------------

SysYParser::CondContext* SysYParser::SubStmtCtrlSeqContext::cond() {
  return getRuleContext<SysYParser::CondContext>(0);
}

std::vector<SysYParser::SubStmtContext *> SysYParser::SubStmtCtrlSeqContext::subStmt() {
  return getRuleContexts<SysYParser::SubStmtContext>();
}

SysYParser::SubStmtContext* SysYParser::SubStmtCtrlSeqContext::subStmt(size_t i) {
  return getRuleContext<SysYParser::SubStmtContext>(i);
}

SysYParser::SubStmtCtrlSeqContext::SubStmtCtrlSeqContext(SubStmtContext *ctx) { copyFrom(ctx); }


//----------------- SubStmtReturnContext ------------------------------------------------------------------

SysYParser::ExpContext* SysYParser::SubStmtReturnContext::exp() {
  return getRuleContext<SysYParser::ExpContext>(0);
}

SysYParser::SubStmtReturnContext::SubStmtReturnContext(SubStmtContext *ctx) { copyFrom(ctx); }


SysYParser::SubStmtContext* SysYParser::subStmt() {
  SubStmtContext *_localctx = _tracker.createInstance<SubStmtContext>(_ctx, getState());
  enterRule(_localctx, 36, SysYParser::RuleSubStmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(262);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<SubStmtContext *>(_tracker.createInstance<SysYParser::SubStmtAssignmentContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(228);
      lVal();
      setState(229);
      match(SysYParser::T__9);
      setState(230);
      exp();
      setState(231);
      match(SysYParser::T__2);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<SubStmtContext *>(_tracker.createInstance<SysYParser::SubStmtExpressionContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(234);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << SysYParser::T__12)
        | (1ULL << SysYParser::T__21)
        | (1ULL << SysYParser::T__22)
        | (1ULL << SysYParser::T__23)
        | (1ULL << SysYParser::BoolConst)
        | (1ULL << SysYParser::Ident)
        | (1ULL << SysYParser::IntConst)
        | (1ULL << SysYParser::FloatConst)
        | (1ULL << SysYParser::DoubleConst))) != 0)) {
        setState(233);
        exp();
      }
      setState(236);
      match(SysYParser::T__2);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<SubStmtContext *>(_tracker.createInstance<SysYParser::SubStmtBlockContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(237);
      block();
      break;
    }

    case 4: {
      _localctx = dynamic_cast<SubStmtContext *>(_tracker.createInstance<SysYParser::SubStmtCtrlSeqContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(238);
      match(SysYParser::T__15);
      setState(239);
      match(SysYParser::T__12);
      setState(240);
      cond();
      setState(241);
      match(SysYParser::T__13);
      setState(242);
      subStmt();
      setState(245);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
      case 1: {
        setState(243);
        match(SysYParser::T__16);
        setState(244);
        subStmt();
        break;
      }

      }
      break;
    }

    case 5: {
      _localctx = dynamic_cast<SubStmtContext *>(_tracker.createInstance<SysYParser::SubStmtCtrlSeqContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(247);
      match(SysYParser::T__17);
      setState(248);
      match(SysYParser::T__12);
      setState(249);
      cond();
      setState(250);
      match(SysYParser::T__13);
      setState(251);
      subStmt();
      break;
    }

    case 6: {
      _localctx = dynamic_cast<SubStmtContext *>(_tracker.createInstance<SysYParser::SubStmtCtrlSeqContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(253);
      match(SysYParser::T__19);
      setState(254);
      match(SysYParser::T__2);
      break;
    }

    case 7: {
      _localctx = dynamic_cast<SubStmtContext *>(_tracker.createInstance<SysYParser::SubStmtCtrlSeqContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(255);
      match(SysYParser::T__20);
      setState(256);
      match(SysYParser::T__2);
      break;
    }

    case 8: {
      _localctx = dynamic_cast<SubStmtContext *>(_tracker.createInstance<SysYParser::SubStmtReturnContext>(_localctx));
      enterOuterAlt(_localctx, 8);
      setState(257);
      match(SysYParser::T__18);
      setState(259);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << SysYParser::T__12)
        | (1ULL << SysYParser::T__21)
        | (1ULL << SysYParser::T__22)
        | (1ULL << SysYParser::T__23)
        | (1ULL << SysYParser::BoolConst)
        | (1ULL << SysYParser::Ident)
        | (1ULL << SysYParser::IntConst)
        | (1ULL << SysYParser::FloatConst)
        | (1ULL << SysYParser::DoubleConst))) != 0)) {
        setState(258);
        exp();
      }
      setState(261);
      match(SysYParser::T__2);
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

SysYParser::ExpContext::ExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SysYParser::ExpContext::getRuleIndex() const {
  return SysYParser::RuleExp;
}

void SysYParser::ExpContext::copyFrom(ExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->isArray = ctx->isArray;
  this->size = ctx->size;
  this->metaDataType = ctx->metaDataType;
}

//----------------- ExpBoolExpContext ------------------------------------------------------------------

tree::TerminalNode* SysYParser::ExpBoolExpContext::BoolConst() {
  return getToken(SysYParser::BoolConst, 0);
}

SysYParser::ExpBoolExpContext::ExpBoolExpContext(ExpContext *ctx) { copyFrom(ctx); }


//----------------- ExpAddExpContext ------------------------------------------------------------------

SysYParser::AddExpContext* SysYParser::ExpAddExpContext::addExp() {
  return getRuleContext<SysYParser::AddExpContext>(0);
}

SysYParser::ExpAddExpContext::ExpAddExpContext(ExpContext *ctx) { copyFrom(ctx); }


SysYParser::ExpContext* SysYParser::exp() {
  ExpContext *_localctx = _tracker.createInstance<ExpContext>(_ctx, getState());
  enterRule(_localctx, 38, SysYParser::RuleExp);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(266);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SysYParser::T__12:
      case SysYParser::T__21:
      case SysYParser::T__22:
      case SysYParser::T__23:
      case SysYParser::Ident:
      case SysYParser::IntConst:
      case SysYParser::FloatConst:
      case SysYParser::DoubleConst: {
        _localctx = dynamic_cast<ExpContext *>(_tracker.createInstance<SysYParser::ExpAddExpContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(264);
        addExp(0);
        break;
      }

      case SysYParser::BoolConst: {
        _localctx = dynamic_cast<ExpContext *>(_tracker.createInstance<SysYParser::ExpBoolExpContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(265);
        match(SysYParser::BoolConst);
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

SysYParser::CondContext::CondContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::LOrExpContext* SysYParser::CondContext::lOrExp() {
  return getRuleContext<SysYParser::LOrExpContext>(0);
}


size_t SysYParser::CondContext::getRuleIndex() const {
  return SysYParser::RuleCond;
}


SysYParser::CondContext* SysYParser::cond() {
  CondContext *_localctx = _tracker.createInstance<CondContext>(_ctx, getState());
  enterRule(_localctx, 40, SysYParser::RuleCond);

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

SysYParser::LValContext::LValContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SysYParser::LValContext::Ident() {
  return getToken(SysYParser::Ident, 0);
}

SysYParser::ExpContext* SysYParser::LValContext::exp() {
  return getRuleContext<SysYParser::ExpContext>(0);
}


size_t SysYParser::LValContext::getRuleIndex() const {
  return SysYParser::RuleLVal;
}


SysYParser::LValContext* SysYParser::lVal() {
  LValContext *_localctx = _tracker.createInstance<LValContext>(_ctx, getState());
  enterRule(_localctx, 42, SysYParser::RuleLVal);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(270);
    match(SysYParser::Ident);
    setState(275);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
    case 1: {
      setState(271);
      match(SysYParser::T__7);
      setState(272);
      exp();
      setState(273);
      match(SysYParser::T__8);
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

SysYParser::PrimaryExpContext::PrimaryExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SysYParser::PrimaryExpContext::getRuleIndex() const {
  return SysYParser::RulePrimaryExp;
}

void SysYParser::PrimaryExpContext::copyFrom(PrimaryExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->isArray = ctx->isArray;
  this->size = ctx->size;
  this->metaDataType = ctx->metaDataType;
}

//----------------- PrimaryExpNestExpContext ------------------------------------------------------------------

SysYParser::ExpContext* SysYParser::PrimaryExpNestExpContext::exp() {
  return getRuleContext<SysYParser::ExpContext>(0);
}

SysYParser::PrimaryExpNestExpContext::PrimaryExpNestExpContext(PrimaryExpContext *ctx) { copyFrom(ctx); }


//----------------- PrimaryExpNumberContext ------------------------------------------------------------------

SysYParser::NumberContext* SysYParser::PrimaryExpNumberContext::number() {
  return getRuleContext<SysYParser::NumberContext>(0);
}

SysYParser::PrimaryExpNumberContext::PrimaryExpNumberContext(PrimaryExpContext *ctx) { copyFrom(ctx); }


//----------------- PrimaryExplValContext ------------------------------------------------------------------

SysYParser::LValContext* SysYParser::PrimaryExplValContext::lVal() {
  return getRuleContext<SysYParser::LValContext>(0);
}

SysYParser::PrimaryExplValContext::PrimaryExplValContext(PrimaryExpContext *ctx) { copyFrom(ctx); }


SysYParser::PrimaryExpContext* SysYParser::primaryExp() {
  PrimaryExpContext *_localctx = _tracker.createInstance<PrimaryExpContext>(_ctx, getState());
  enterRule(_localctx, 44, SysYParser::RulePrimaryExp);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(283);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SysYParser::T__12: {
        _localctx = dynamic_cast<PrimaryExpContext *>(_tracker.createInstance<SysYParser::PrimaryExpNestExpContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(277);
        match(SysYParser::T__12);
        setState(278);
        exp();
        setState(279);
        match(SysYParser::T__13);
        break;
      }

      case SysYParser::Ident: {
        _localctx = dynamic_cast<PrimaryExpContext *>(_tracker.createInstance<SysYParser::PrimaryExplValContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(281);
        lVal();
        break;
      }

      case SysYParser::IntConst:
      case SysYParser::FloatConst:
      case SysYParser::DoubleConst: {
        _localctx = dynamic_cast<PrimaryExpContext *>(_tracker.createInstance<SysYParser::PrimaryExpNumberContext>(_localctx));
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

SysYParser::UnaryExpContext::UnaryExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SysYParser::UnaryExpContext::getRuleIndex() const {
  return SysYParser::RuleUnaryExp;
}

void SysYParser::UnaryExpContext::copyFrom(UnaryExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->isArray = ctx->isArray;
  this->size = ctx->size;
  this->metaDataType = ctx->metaDataType;
}

//----------------- UnaryExpFuncContext ------------------------------------------------------------------

tree::TerminalNode* SysYParser::UnaryExpFuncContext::Ident() {
  return getToken(SysYParser::Ident, 0);
}

SysYParser::FuncRParamsContext* SysYParser::UnaryExpFuncContext::funcRParams() {
  return getRuleContext<SysYParser::FuncRParamsContext>(0);
}

SysYParser::UnaryExpFuncContext::UnaryExpFuncContext(UnaryExpContext *ctx) { copyFrom(ctx); }


//----------------- UnaryExpPrimaryExpContext ------------------------------------------------------------------

SysYParser::PrimaryExpContext* SysYParser::UnaryExpPrimaryExpContext::primaryExp() {
  return getRuleContext<SysYParser::PrimaryExpContext>(0);
}

SysYParser::UnaryExpPrimaryExpContext::UnaryExpPrimaryExpContext(UnaryExpContext *ctx) { copyFrom(ctx); }


//----------------- UnaryExpNestUnaryExpContext ------------------------------------------------------------------

SysYParser::UnaryOpContext* SysYParser::UnaryExpNestUnaryExpContext::unaryOp() {
  return getRuleContext<SysYParser::UnaryOpContext>(0);
}

SysYParser::UnaryExpContext* SysYParser::UnaryExpNestUnaryExpContext::unaryExp() {
  return getRuleContext<SysYParser::UnaryExpContext>(0);
}

SysYParser::UnaryExpNestUnaryExpContext::UnaryExpNestUnaryExpContext(UnaryExpContext *ctx) { copyFrom(ctx); }


SysYParser::UnaryExpContext* SysYParser::unaryExp() {
  UnaryExpContext *_localctx = _tracker.createInstance<UnaryExpContext>(_ctx, getState());
  enterRule(_localctx, 46, SysYParser::RuleUnaryExp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(295);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<UnaryExpContext *>(_tracker.createInstance<SysYParser::UnaryExpPrimaryExpContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(285);
      primaryExp();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<UnaryExpContext *>(_tracker.createInstance<SysYParser::UnaryExpFuncContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(286);
      match(SysYParser::Ident);
      setState(287);
      match(SysYParser::T__12);
      setState(289);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << SysYParser::T__12)
        | (1ULL << SysYParser::T__21)
        | (1ULL << SysYParser::T__22)
        | (1ULL << SysYParser::T__23)
        | (1ULL << SysYParser::BoolConst)
        | (1ULL << SysYParser::Ident)
        | (1ULL << SysYParser::IntConst)
        | (1ULL << SysYParser::FloatConst)
        | (1ULL << SysYParser::DoubleConst))) != 0)) {
        setState(288);
        funcRParams();
      }
      setState(291);
      match(SysYParser::T__13);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<UnaryExpContext *>(_tracker.createInstance<SysYParser::UnaryExpNestUnaryExpContext>(_localctx));
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

SysYParser::UnaryOpContext::UnaryOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SysYParser::UnaryOpContext::getRuleIndex() const {
  return SysYParser::RuleUnaryOp;
}


SysYParser::UnaryOpContext* SysYParser::unaryOp() {
  UnaryOpContext *_localctx = _tracker.createInstance<UnaryOpContext>(_ctx, getState());
  enterRule(_localctx, 48, SysYParser::RuleUnaryOp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(297);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SysYParser::T__21)
      | (1ULL << SysYParser::T__22)
      | (1ULL << SysYParser::T__23))) != 0))) {
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

SysYParser::FuncRParamsContext::FuncRParamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SysYParser::ExpContext *> SysYParser::FuncRParamsContext::exp() {
  return getRuleContexts<SysYParser::ExpContext>();
}

SysYParser::ExpContext* SysYParser::FuncRParamsContext::exp(size_t i) {
  return getRuleContext<SysYParser::ExpContext>(i);
}


size_t SysYParser::FuncRParamsContext::getRuleIndex() const {
  return SysYParser::RuleFuncRParams;
}


SysYParser::FuncRParamsContext* SysYParser::funcRParams() {
  FuncRParamsContext *_localctx = _tracker.createInstance<FuncRParamsContext>(_ctx, getState());
  enterRule(_localctx, 50, SysYParser::RuleFuncRParams);
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
    while (_la == SysYParser::T__1) {
      setState(300);
      match(SysYParser::T__1);
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

SysYParser::MulExpContext::MulExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SysYParser::MulExpContext::getRuleIndex() const {
  return SysYParser::RuleMulExp;
}

void SysYParser::MulExpContext::copyFrom(MulExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->isArray = ctx->isArray;
  this->size = ctx->size;
  this->metaDataType = ctx->metaDataType;
}

//----------------- MulExpMulExpContext ------------------------------------------------------------------

SysYParser::MulExpContext* SysYParser::MulExpMulExpContext::mulExp() {
  return getRuleContext<SysYParser::MulExpContext>(0);
}

SysYParser::MulOpContext* SysYParser::MulExpMulExpContext::mulOp() {
  return getRuleContext<SysYParser::MulOpContext>(0);
}

SysYParser::UnaryExpContext* SysYParser::MulExpMulExpContext::unaryExp() {
  return getRuleContext<SysYParser::UnaryExpContext>(0);
}

SysYParser::MulExpMulExpContext::MulExpMulExpContext(MulExpContext *ctx) { copyFrom(ctx); }


//----------------- MulExpUnaryExpContext ------------------------------------------------------------------

SysYParser::UnaryExpContext* SysYParser::MulExpUnaryExpContext::unaryExp() {
  return getRuleContext<SysYParser::UnaryExpContext>(0);
}

SysYParser::MulExpUnaryExpContext::MulExpUnaryExpContext(MulExpContext *ctx) { copyFrom(ctx); }



SysYParser::MulExpContext* SysYParser::mulExp() {
   return mulExp(0);
}

SysYParser::MulExpContext* SysYParser::mulExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SysYParser::MulExpContext *_localctx = _tracker.createInstance<MulExpContext>(_ctx, parentState);
  SysYParser::MulExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 52;
  enterRecursionRule(_localctx, 52, SysYParser::RuleMulExp, precedence);

    

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

SysYParser::MulOpContext::MulOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SysYParser::MulOpContext::getRuleIndex() const {
  return SysYParser::RuleMulOp;
}


SysYParser::MulOpContext* SysYParser::mulOp() {
  MulOpContext *_localctx = _tracker.createInstance<MulOpContext>(_ctx, getState());
  enterRule(_localctx, 54, SysYParser::RuleMulOp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(319);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SysYParser::T__24)
      | (1ULL << SysYParser::T__25)
      | (1ULL << SysYParser::T__26))) != 0))) {
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

SysYParser::AddExpContext::AddExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SysYParser::AddExpContext::getRuleIndex() const {
  return SysYParser::RuleAddExp;
}

void SysYParser::AddExpContext::copyFrom(AddExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->isArray = ctx->isArray;
  this->size = ctx->size;
  this->metaDataType = ctx->metaDataType;
}

//----------------- AddExpAddExpContext ------------------------------------------------------------------

SysYParser::AddExpContext* SysYParser::AddExpAddExpContext::addExp() {
  return getRuleContext<SysYParser::AddExpContext>(0);
}

SysYParser::MulExpContext* SysYParser::AddExpAddExpContext::mulExp() {
  return getRuleContext<SysYParser::MulExpContext>(0);
}

SysYParser::AddExpAddExpContext::AddExpAddExpContext(AddExpContext *ctx) { copyFrom(ctx); }


//----------------- AddExpMulExpContext ------------------------------------------------------------------

SysYParser::MulExpContext* SysYParser::AddExpMulExpContext::mulExp() {
  return getRuleContext<SysYParser::MulExpContext>(0);
}

SysYParser::AddExpMulExpContext::AddExpMulExpContext(AddExpContext *ctx) { copyFrom(ctx); }



SysYParser::AddExpContext* SysYParser::addExp() {
   return addExp(0);
}

SysYParser::AddExpContext* SysYParser::addExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SysYParser::AddExpContext *_localctx = _tracker.createInstance<AddExpContext>(_ctx, parentState);
  SysYParser::AddExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 56;
  enterRecursionRule(_localctx, 56, SysYParser::RuleAddExp, precedence);

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
        if (!(_la == SysYParser::T__21

        || _la == SysYParser::T__22)) {
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

SysYParser::RelExpContext::RelExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SysYParser::RelExpContext::getRuleIndex() const {
  return SysYParser::RuleRelExp;
}

void SysYParser::RelExpContext::copyFrom(RelExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->metaDataType = ctx->metaDataType;
}

//----------------- RelExpRelExpContext ------------------------------------------------------------------

SysYParser::RelExpContext* SysYParser::RelExpRelExpContext::relExp() {
  return getRuleContext<SysYParser::RelExpContext>(0);
}

SysYParser::AddExpContext* SysYParser::RelExpRelExpContext::addExp() {
  return getRuleContext<SysYParser::AddExpContext>(0);
}

SysYParser::RelExpRelExpContext::RelExpRelExpContext(RelExpContext *ctx) { copyFrom(ctx); }


//----------------- RelExpAddExpContext ------------------------------------------------------------------

SysYParser::AddExpContext* SysYParser::RelExpAddExpContext::addExp() {
  return getRuleContext<SysYParser::AddExpContext>(0);
}

SysYParser::RelExpAddExpContext::RelExpAddExpContext(RelExpContext *ctx) { copyFrom(ctx); }


//----------------- RelExpBoolConstContext ------------------------------------------------------------------

tree::TerminalNode* SysYParser::RelExpBoolConstContext::BoolConst() {
  return getToken(SysYParser::BoolConst, 0);
}

SysYParser::RelExpBoolConstContext::RelExpBoolConstContext(RelExpContext *ctx) { copyFrom(ctx); }



SysYParser::RelExpContext* SysYParser::relExp() {
   return relExp(0);
}

SysYParser::RelExpContext* SysYParser::relExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SysYParser::RelExpContext *_localctx = _tracker.createInstance<RelExpContext>(_ctx, parentState);
  SysYParser::RelExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 58;
  enterRecursionRule(_localctx, 58, SysYParser::RuleRelExp, precedence);

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
      case SysYParser::T__12:
      case SysYParser::T__21:
      case SysYParser::T__22:
      case SysYParser::T__23:
      case SysYParser::Ident:
      case SysYParser::IntConst:
      case SysYParser::FloatConst:
      case SysYParser::DoubleConst: {
        _localctx = _tracker.createInstance<RelExpAddExpContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(333);
        addExp(0);
        break;
      }

      case SysYParser::BoolConst: {
        _localctx = _tracker.createInstance<RelExpBoolConstContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(334);
        match(SysYParser::BoolConst);
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
          ((1ULL << _la) & ((1ULL << SysYParser::T__27)
          | (1ULL << SysYParser::T__28)
          | (1ULL << SysYParser::T__29)
          | (1ULL << SysYParser::T__30))) != 0))) {
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

SysYParser::EqExpContext::EqExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SysYParser::EqExpContext::getRuleIndex() const {
  return SysYParser::RuleEqExp;
}

void SysYParser::EqExpContext::copyFrom(EqExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->metaDataType = ctx->metaDataType;
}

//----------------- EqExpRelExpContext ------------------------------------------------------------------

SysYParser::RelExpContext* SysYParser::EqExpRelExpContext::relExp() {
  return getRuleContext<SysYParser::RelExpContext>(0);
}

SysYParser::EqExpRelExpContext::EqExpRelExpContext(EqExpContext *ctx) { copyFrom(ctx); }


//----------------- EqExpEqExpContext ------------------------------------------------------------------

SysYParser::EqExpContext* SysYParser::EqExpEqExpContext::eqExp() {
  return getRuleContext<SysYParser::EqExpContext>(0);
}

SysYParser::RelExpContext* SysYParser::EqExpEqExpContext::relExp() {
  return getRuleContext<SysYParser::RelExpContext>(0);
}

SysYParser::EqExpEqExpContext::EqExpEqExpContext(EqExpContext *ctx) { copyFrom(ctx); }



SysYParser::EqExpContext* SysYParser::eqExp() {
   return eqExp(0);
}

SysYParser::EqExpContext* SysYParser::eqExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SysYParser::EqExpContext *_localctx = _tracker.createInstance<EqExpContext>(_ctx, parentState);
  SysYParser::EqExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 60;
  enterRecursionRule(_localctx, 60, SysYParser::RuleEqExp, precedence);

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
        if (!(_la == SysYParser::T__31

        || _la == SysYParser::T__32)) {
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

SysYParser::LAndExpContext::LAndExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SysYParser::LAndExpContext::getRuleIndex() const {
  return SysYParser::RuleLAndExp;
}

void SysYParser::LAndExpContext::copyFrom(LAndExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->metaDataType = ctx->metaDataType;
}

//----------------- LAndExpLAndExpContext ------------------------------------------------------------------

SysYParser::LAndExpContext* SysYParser::LAndExpLAndExpContext::lAndExp() {
  return getRuleContext<SysYParser::LAndExpContext>(0);
}

SysYParser::EqExpContext* SysYParser::LAndExpLAndExpContext::eqExp() {
  return getRuleContext<SysYParser::EqExpContext>(0);
}

SysYParser::LAndExpLAndExpContext::LAndExpLAndExpContext(LAndExpContext *ctx) { copyFrom(ctx); }


//----------------- LAndExpEqExpContext ------------------------------------------------------------------

SysYParser::EqExpContext* SysYParser::LAndExpEqExpContext::eqExp() {
  return getRuleContext<SysYParser::EqExpContext>(0);
}

SysYParser::LAndExpEqExpContext::LAndExpEqExpContext(LAndExpContext *ctx) { copyFrom(ctx); }



SysYParser::LAndExpContext* SysYParser::lAndExp() {
   return lAndExp(0);
}

SysYParser::LAndExpContext* SysYParser::lAndExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SysYParser::LAndExpContext *_localctx = _tracker.createInstance<LAndExpContext>(_ctx, parentState);
  SysYParser::LAndExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 62;
  enterRecursionRule(_localctx, 62, SysYParser::RuleLAndExp, precedence);

    

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
        match(SysYParser::T__33);
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

SysYParser::LOrExpContext::LOrExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SysYParser::LOrExpContext::getRuleIndex() const {
  return SysYParser::RuleLOrExp;
}

void SysYParser::LOrExpContext::copyFrom(LOrExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->metaDataType = ctx->metaDataType;
}

//----------------- LOrExpLAndExpContext ------------------------------------------------------------------

SysYParser::LAndExpContext* SysYParser::LOrExpLAndExpContext::lAndExp() {
  return getRuleContext<SysYParser::LAndExpContext>(0);
}

SysYParser::LOrExpLAndExpContext::LOrExpLAndExpContext(LOrExpContext *ctx) { copyFrom(ctx); }


//----------------- LOrExpLOrExpContext ------------------------------------------------------------------

SysYParser::LOrExpContext* SysYParser::LOrExpLOrExpContext::lOrExp() {
  return getRuleContext<SysYParser::LOrExpContext>(0);
}

SysYParser::LAndExpContext* SysYParser::LOrExpLOrExpContext::lAndExp() {
  return getRuleContext<SysYParser::LAndExpContext>(0);
}

SysYParser::LOrExpLOrExpContext::LOrExpLOrExpContext(LOrExpContext *ctx) { copyFrom(ctx); }



SysYParser::LOrExpContext* SysYParser::lOrExp() {
   return lOrExp(0);
}

SysYParser::LOrExpContext* SysYParser::lOrExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SysYParser::LOrExpContext *_localctx = _tracker.createInstance<LOrExpContext>(_ctx, parentState);
  SysYParser::LOrExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 64;
  enterRecursionRule(_localctx, 64, SysYParser::RuleLOrExp, precedence);

    

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
        match(SysYParser::T__34);
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

SysYParser::ConstExpContext::ConstExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SysYParser::ConstExpContext::getRuleIndex() const {
  return SysYParser::RuleConstExp;
}

void SysYParser::ConstExpContext::copyFrom(ConstExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->metaDataType = ctx->metaDataType;
}

//----------------- ConstExpBoolConstContext ------------------------------------------------------------------

tree::TerminalNode* SysYParser::ConstExpBoolConstContext::BoolConst() {
  return getToken(SysYParser::BoolConst, 0);
}

SysYParser::ConstExpBoolConstContext::ConstExpBoolConstContext(ConstExpContext *ctx) { copyFrom(ctx); }


//----------------- ConstExpNumberContext ------------------------------------------------------------------

SysYParser::NumberContext* SysYParser::ConstExpNumberContext::number() {
  return getRuleContext<SysYParser::NumberContext>(0);
}

SysYParser::ConstExpNumberContext::ConstExpNumberContext(ConstExpContext *ctx) { copyFrom(ctx); }


SysYParser::ConstExpContext* SysYParser::constExp() {
  ConstExpContext *_localctx = _tracker.createInstance<ConstExpContext>(_ctx, getState());
  enterRule(_localctx, 66, SysYParser::RuleConstExp);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(380);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SysYParser::IntConst:
      case SysYParser::FloatConst:
      case SysYParser::DoubleConst: {
        _localctx = dynamic_cast<ConstExpContext *>(_tracker.createInstance<SysYParser::ConstExpNumberContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(378);
        number();
        break;
      }

      case SysYParser::BoolConst: {
        _localctx = dynamic_cast<ConstExpContext *>(_tracker.createInstance<SysYParser::ConstExpBoolConstContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(379);
        match(SysYParser::BoolConst);
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

SysYParser::NumberContext::NumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SysYParser::NumberContext::getRuleIndex() const {
  return SysYParser::RuleNumber;
}

void SysYParser::NumberContext::copyFrom(NumberContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->metaDataType = ctx->metaDataType;
}

//----------------- NumberDoubleConstContext ------------------------------------------------------------------

tree::TerminalNode* SysYParser::NumberDoubleConstContext::DoubleConst() {
  return getToken(SysYParser::DoubleConst, 0);
}

SysYParser::NumberDoubleConstContext::NumberDoubleConstContext(NumberContext *ctx) { copyFrom(ctx); }


//----------------- NumberFloatConstContext ------------------------------------------------------------------

tree::TerminalNode* SysYParser::NumberFloatConstContext::FloatConst() {
  return getToken(SysYParser::FloatConst, 0);
}

SysYParser::NumberFloatConstContext::NumberFloatConstContext(NumberContext *ctx) { copyFrom(ctx); }


//----------------- NumberIntConstContext ------------------------------------------------------------------

tree::TerminalNode* SysYParser::NumberIntConstContext::IntConst() {
  return getToken(SysYParser::IntConst, 0);
}

SysYParser::NumberIntConstContext::NumberIntConstContext(NumberContext *ctx) { copyFrom(ctx); }


SysYParser::NumberContext* SysYParser::number() {
  NumberContext *_localctx = _tracker.createInstance<NumberContext>(_ctx, getState());
  enterRule(_localctx, 68, SysYParser::RuleNumber);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(385);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SysYParser::IntConst: {
        _localctx = dynamic_cast<NumberContext *>(_tracker.createInstance<SysYParser::NumberIntConstContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(382);
        match(SysYParser::IntConst);
        break;
      }

      case SysYParser::DoubleConst: {
        _localctx = dynamic_cast<NumberContext *>(_tracker.createInstance<SysYParser::NumberDoubleConstContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(383);
        match(SysYParser::DoubleConst);
        break;
      }

      case SysYParser::FloatConst: {
        _localctx = dynamic_cast<NumberContext *>(_tracker.createInstance<SysYParser::NumberFloatConstContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(384);
        match(SysYParser::FloatConst);
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

bool SysYParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
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

bool SysYParser::mulExpSempred(MulExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool SysYParser::addExpSempred(AddExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool SysYParser::relExpSempred(RelExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 2: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool SysYParser::eqExpSempred(EqExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool SysYParser::lAndExpSempred(LAndExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 4: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool SysYParser::lOrExpSempred(LOrExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 5: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> SysYParser::_decisionToDFA;
atn::PredictionContextCache SysYParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN SysYParser::_atn;
std::vector<uint16_t> SysYParser::_serializedATN;

std::vector<std::string> SysYParser::_ruleNames = {
  "compUnit", "decl", "constDecl", "bType", "constDef", "constInitVal", 
  "varDecl", "varDef", "funcDef", "funcType", "funcFParams", "funcFParam", 
  "brackets", "funcBlock", "funcBlockItem", "stmt", "block", "blockItem", 
  "subStmt", "exp", "cond", "lVal", "primaryExp", "unaryExp", "unaryOp", 
  "funcRParams", "mulExp", "mulOp", "addExp", "relExp", "eqExp", "lAndExp", 
  "lOrExp", "constExp", "number"
};

std::vector<std::string> SysYParser::_literalNames = {
  "", "'const'", "','", "';'", "'int'", "'bool'", "'double'", "'float'", 
  "'['", "']'", "'='", "'{'", "'}'", "'('", "')'", "'void'", "'if'", "'else'", 
  "'while'", "'return'", "'break'", "'continue'", "'+'", "'-'", "'!'", "'*'", 
  "'/'", "'%'", "'<'", "'>'", "'<='", "'>='", "'=='", "'!='", "'&&'", "'||'"
};

std::vector<std::string> SysYParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "BoolConst", "Ident", "IntConst", "DigitSequence", "FloatConst", "DoubleConst", 
  "NewLine", "WhiteSpace", "BlockComment", "LineComment"
};

dfa::Vocabulary SysYParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> SysYParser::_tokenNames;

SysYParser::Initializer::Initializer() {
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

SysYParser::Initializer SysYParser::_init;
