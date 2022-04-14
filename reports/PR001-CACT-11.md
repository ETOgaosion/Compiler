# 编译原理研讨课实验PR001实验报告

[author]: 高梓源 官奕琳 [Stu.Num]: 2019K8009929026 2019K8009907026

[TOC]

## 任务说明

本次实验为CACT编译器设计的第一个实验，主要完成的任务如下：

- 实验环境的配置，包括：
    - 熟悉ANTLR4工具的安装和使用
    - 服务器和本地编译环境的搭建
- 完成CACT相关词法的设计
    - 根据`CACT_specification.pdf`完善`CACT.g4`，实现对语法产生式规则的描述
- 能够捕获词法分析阶段和语法分析阶段的错误并进行相应的输出处理
    - 若无错误返回0，存在错误返回非0值
- 进行编译测试，正确实现所有语法的识别

## 成员组成

- 高梓源，2019K8009929026
- 官奕琳，2019K8009907026

## 实验设计

### 设计思路

#### CACT语法规则

<!-- TODO -->

#### 错误捕获

##### 错误获取函数寻找

首先需要寻找获取错误信息的函数，可以进行全局搜索正则表达式`get(\w)*Error`，从而快速找到以下错误获取函数：

- `getTokenErrorDisplay`
- `getErrorDisplay`
- `getNumberOfSyntaxErors`

前两者是在运行过程中对于词法语法unmatched情况进行即刻打印，因此仅剩的第三个正好是获取错误数量的函数，在语法、词法分析完成后进行调用判断即可。

##### 关于错误获取函数

关于`getNumberOfSyntaxErrors`更详细的信息：

根据查找结果，在`CACTLexer`的父类`Lexer`中和`CACTParser`的父类`Parser`中分别找到了对应函数的实现：

```C++
// size_t Parser::getNumberOfSyntaxErrors()
size_t Lexer::getNumberOfSyntaxErrors() {
  return _syntaxErrors;
}
```

`_syntaxErrors`是两个类中的私有变量，而产生错误对其进行修改的只有：

```C++
void Lexer::notifyListeners(const LexerNoViableAltException & /*e*/) {
  ++_syntaxErrors;
  // ...
}
```

继续回溯同一类中，调用`notifyListeners`的函数只有：

```C++
std::unique_ptr<Token> Lexer::nextToken() {
    // ...
    do{
        // ...
        try{
            //...
        } catch (LexerNoViableAltException &e) {
            notifyListeners(e); // report error
            // ...
        }
    } while (type == MORE);
}
```

希望获取下一个token即`nextToken`的调用，在同一类中只有`std::vector<std::unique_ptr<Token>> Lexer::getAllTokens()`，而该函数是一个末端函数，不存在调用者。而注意到`nextToken`是public的，因此很有可能被从外部访问，这部分讨论在实验实现部分展开。

因此，想要对`_syntaxErrors`进行修改只有通过`notifyListeners`这一函数，但注意到该函数设置为public，可能有外部调用时出现错误进而进行汇报的考量，但是封装性仍有值得商榷的地方，事实上并没有直接调用的案例，因此笔者更倾向于设置为`protected`甚至是`private`。

### 实验实现

#### 规则文件完善

<!-- TODO -->

#### 主函数修改

经过设计思路中的相关讨论，我们了解到只有通过`notifyListeners`这一函数才能够对语法错误次数进行修改。之所以要了解这一点，是因为需要确定在`main.cpp`插入错误获取函数最早的位置。此前我们通过回溯的方法进行，但事实上只能将搜索范围限定在本类，现在通过正向调用来clarify程序分析、错误产生的流程。

在`main.cpp`中，需要确定获取lexer和parser错误最早的准确位置，有以下可能的位置：

```C++
CACTLexer lexer(&input);
// get lex error pos 1
CommonTokenStream tokens(&lexer);
// get lex error pos 2
CACTParser parser(&tokens);
// get lex error pos 3
// get parser error pos 1
tree::ParseTree *tree = parser.compUnit();
// get lex error pos 4
// get parser error pos 2
tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);
// get lex error pos 5
// get parser error pos 3
```

但是很快就能够排除前三条语句，能够获取错误的时机一定是词法分析与语法分析进行完成，而对前三条语句，只需要查看派生类和父类的构造函数便可知初始化阶段只设置实例化类的相关参数，并不进行分析动作。以Lexer为例，派生类CACTLexer以及父类Lexer构造函数如下：

```C++
// class relation
class  CACTLexer : public antlr4::Lexer
// CACTLexer constructor:
CACTLexer::CACTLexer(CharStream *input) : Lexer(input) {
  _interpreter = new atn::LexerATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}
// LexerATNSimulator constructor:
LexerATNSimulator::LexerATNSimulator(Lexer *recog, const ATN &atn, std::vector<dfa::DFA> &decisionToDFA,
                                     PredictionContextCache &sharedContextCache)
  : ATNSimulator(atn, sharedContextCache), _recog(recog), _decisionToDFA(decisionToDFA) {
  InitializeInstanceFields();
}
void LexerATNSimulator::SimState::InitializeInstanceFields() {
  index = INVALID_INDEX;
  line = 0;
  charPos = INVALID_INDEX;
}
/*=== NO SIGN OF ANALYSIS ACTION ===*/
//Lexer constructor:
Lexer::Lexer(CharStream *input) : Recognizer(), _input(input) {
  InitializeInstanceFields();
}
void Lexer::InitializeInstanceFields() {
  _syntaxErrors = 0;
  token = nullptr;
  _factory = CommonTokenFactory::DEFAULT;
  tokenStartCharIndex = INVALID_INDEX;
  tokenStartLine = 0;
  tokenStartCharPositionInLine = 0;
  hitEOF = false;
  channel = 0;
  type = 0;
  mode = Lexer::DEFAULT_MODE;
}
/*=== NO SIGN OF ANALYSIS ACTION ===*/
```

其余构造函数类似，只是设置`private`参数的作用

于是焦点来到了`compUnit`函数，事实上，通过简单的想法，`walk`函数一定是为最后输出语法分析树服务的，那么在此之前一定已经做好了词法、语法分析，那么也就是在4,2位进行错误检测即可。

但为了深入ANTLR，对`compUnit`进行进一步了解，我们直接指出核心点：

```C++
CACTParser::CompUnitContext* CACTParser::compUnit() {
    _la = _input->LA(1);
}
```

于是就需要了解`_input`，该属性继承自父类Parser，对他的赋值如下：

```C++
// declaration
/*
 * The input stream
 * see also
 * @getInputStream
 * @setInputStream
 */
TokenStream *_input;
// in construction function
Parser::Parser(TokenStream *input) {
  InitializeInstanceFields();
  setInputStream(input);
}
void Parser::setInputStream(IntStream *input) {
  setTokenStream(static_cast<TokenStream*>(input));
}
void Parser::setTokenStream(TokenStream *input) {
  _input = nullptr; // Just a reference we don't own.
  reset();
  _input = input;
}
```

可以总结为在构造函数中，Parser将tokens保存在`_input`私有变量中，事实上tokens的类`CommonTokenStream`继承自`BufferedTokenStream`，后者继承自`TokenStream`，因此此处运用了面向父类编程的思想进行抽象。

了解了`_input`之后，对`_input`调用的操作可以看作调用`token`的动作，那么此处`LA()`函数正是此意，于是锁定在`BufferTokenStream`类中函数：

```C++
size_t BufferedTokenStream::LA(ssize_t i) {
  return LT(i)->getType();
}
Token* BufferedTokenStream::LT(ssize_t k) {
  // ...
  sync(i);
  // ...
}
bool BufferedTokenStream::sync(size_t i) {
    // ...
    size_t fetched = fetch(n);
    // ...
}
size_t BufferedTokenStream::fetch(size_t n) {
    // ...
    std::unique_ptr<Token> t(_tokenSource->nextToken());
    // ...
}
```

`LT`函数中有一个很不起眼的关键语句`sync(i)`，通过它我们最终找到了`nextToken`函数的调用，这里`_tokenSource`字面意即位token处理的源头，事实上的确如此：

```C++
// class var declaration
  protected:
    /**
     * The {@link TokenSource} from which tokens for this stream are fetched.
     */
    TokenSource *_tokenSource;
    
BufferedTokenStream::BufferedTokenStream(TokenSource *tokenSource) : _tokenSource(tokenSource){
  InitializeInstanceFields();
}
// Lexer
class ANTLR4CPP_PUBLIC Lexer : public Recognizer, public TokenSource
```

`TokenSource`事实上是接口(interface)，`Lexer`类对其进行了实现，因此此处体现了面向接口编程的思想，通过使用`nextToken`函数，按照设计思路处的分析，能够进行词法分析并且根据出错打印出错信息并且修改`_syntaxErrors`。

事实上语法分析也是在`compUnit`这个函数调用实现的，最终生成语法树，因此在此后进行错误获取是合理的。

具体设计时，若出错统一跳转到函数末尾，此外复用`errorNum`变量节省时间空间：

```C++
// main.cpp
int main(int argc, const char* argv[]) {
    // ...
    CACTLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    CACTParser parser(&tokens);
    tree::ParseTree *tree = parser.compUnit();
    SemanticAnalysis listener;
    if (errorNum = lexer.getNumberOfSyntaxErrors()) {
        std::cout << "[Error]> Lexer reported " << errorNum << " errors." << std::endl;
        goto exit;
    }
    if (errorNum = parser.getNumberOfSyntaxErrors()) {
        std::cout << "[Error]> Parser reported " << errorNum << " syntax errors." << std::endl;
        goto exit;
    }
    // normal output
exit:
    return errorNum;
}
```

之所以会将`SemanticAnalysis listener;`的声明提前在后面会提到。

### 其它

#### 多平台适配

由于服务器无法使用super user创建ssh公钥，进行git提交极不方便，因此使用本地手段，由于使用MacOS Monterey而非Linux，开虚拟机不很方便，于是搭建Mac下ANTLR环境。

注意需要下载匹配版本的`antlr-complete.jar`和`antlr-runtime`环境，最好是和Linux中相同的4.8版本（4.10版本测试失败），按照STFW获取的方法进行安装，需要能够使用`antlr4`命令。

antlr-runtime相关文件包括预编译需要的头文件，运行时动态链接的库文件，后者在linux下是`.so`结尾，Mac下为`.dylib`结尾，并且由于仍然未能解决的cmake问题，在运行时Mac无法找到本来添加至路径的动态链接，而是固定的访问几个路径下的对应文件，笔者暂时放置在`/usr/local/lib/`目录下。

而后需要做的就是修改cmake，使其能够根据运行平台自动适配，识别平台的常量是`${CMAKE_SYSTEM_NAME}`，Linux下值为`Linux`，目前Mac下值为`Darwin`，使用比较操作`STREQUAL`即可判断平台，将两者runtime相关文件放在不同之处，`include_directories`操作时进行修改即可，制定编译器根据机器而异。*详见根目录下[CMakeLists.txt]*

#### 相关debug过程

##### 语义规则书写

- 经历过最多的bug是关于继承属性和综合属性的locals少加入，课件中指出constExp需要加入`int basic_or_array_and_type`，事实上还有`number, constInitVal`需要加入；

- 此外的问题还有Parser终结符首字母大写，Lexer非终结符首字母小写；

- `fragment`的使用也曾带来问题，`fragment`相当于C语言`inline`函数，起到直接替换、使代码易读的作用，并不是单独的终结符。

##### main函数处理错误

若在之前讨论的2,4处使用goto跳转到结尾进行错误处理返回，那么会跳过`SemanticAnalysis listener;`的声明，这在C++中不被允许，报错。

按照面向过程的思想，尽早进行错误判断能过避免资源的浪费和开销。但是在OOP，需要类的良好排布和预编译的内存分配支持，因此不便如此考虑，空间不会被节省，因此可以后移到声明之后进行错误处理。

##### 环境安装过程

经过一系列错误才能过正确使用mac进行实验，首先是`CMakeLists.txt`中`${CMAKE_SYSTEM_NAME}`变量并非任何时候都可以使用，需要先对`PROJECT`进行配置。在配置`PROJECT`时，服务器Linux环境下无法识别`HOMEPAGE_URL`字段，未找到原因与解决办法，遂删除。

## 总结

### 实验结果总结

按照上述内容完成的语法规则文件和编译器源码，经过编译、测试，对于公开的27个测试样例能够正确通过，`res/log.txt`中error log为空，结果见附录，可见能够正确识别程序中的语法，对于错误也能过正确报告并退出。

通过实验，我们掌握了ANTLR的基本使用方法，感觉到它的强大。在寻找接口的同时通过阅读Antlr生成的词法、语法分析器的源码，并参考其文档，我们大致理解了它们的工作流程，为以后进行更深层次的调用完善奠定基础。

### 分成员总结

#### 官奕琳

<!-- TODO -->

#### 高梓源

主要完成了mac环境的搭建、`main.cpp`中错误处理、运行脚本及测试调试相关工作，以及撰写相应部分的实验报告。此番实验对于编译环境的理解和代码阅读的能力提升非常大，上学期面向对象课程所学又派上了用场。

> OOP是好文明

## 附录

### 27个测试样例输出

请按照项目根目录`README.md`进行编译运行，结果见`res/pass_out.txt`