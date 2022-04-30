grammar CACT;

// The language generated
options {
    language = Cpp;
}

@header {
    #include <vector>
    #include <string>
}

/********** Parser **********/
compUnit
    locals [
        SymbolTable *globalSymbolTable
    ]
    : (decl | funcDef)+ EOF
    ;

decl
    : constDecl
    | varDecl
    ;

constDecl
    : 'const' bType constDef (',' constDef)* ';'
    ;

bType
    locals [
        MetaDataType bMetaDataType
    ]
    : 'int'
    | 'bool'
    | 'double'
    | 'float'
    ;

constDef
    locals [
        AbstractSymbol *symbol
    ]
    : Ident ('[' IntConst ']')? '=' constInitVal
    ;

constInitVal
    locals [
        AbstractSymbol *symbol
    ]
    : constExp                              #constInitValOfVar
    | '{' (constExp (',' constExp)*)? '}'   #constInitValOfArray
    ;

varDecl
    : bType varDef (',' varDef)* ';'
    ;

varDef
    locals [
        AbstractSymbol *symbol
    ]
    : Ident ('[' IntConst ']')? ('=' constInitVal)?
    ;

funcDef
    locals [
        SymbolTable *funcSymbolTable
    ]
    : funcType Ident '(' (funcFParams)? ')' block
    ;

funcType
    : 'void'
    | 'int'
    | 'float'
    | 'double'
    | 'bool'
    ;

funcFParams
    locals [
        SymbolTable *funcSymbolTable
    ]
    : funcFParam (',' funcFParam)*
    ;

funcFParam
    locals [
        AbstractSymbol *symbol
    ]
    : bType Ident ('[' ']')?
    ;

block
    locals [
        SymbolTable *blockSymbolTable
    ]
    : '{' (blockItem)* '}'
    ;

blockItem
    : decl 
    | stmt
    ;

stmt
    : lVal '=' exp ';'                          #stmtAssignment
    | (exp)? ';'                                #stmtExpression
    | block                                     #stmtBlock
    | 'if' '(' cond ')' stmt ('else' stmt)?     #stmtCtrlSeq
    | 'while' '(' cond ')' stmt                 #stmtCtrlSeq
    | 'break' ';'                               #stmtCtrlSeq
    | 'contine' ';'                             #stmtCtrlSeq
    | 'return' (exp)? ';'                       #stmtReturn
    ;

exp
    locals [
        bool isArray,
        size_t size,
        MetaDataType metaDataType
    ]
    : addExp        #expAddExp
    | BoolConst     #expBoolExp
    ;

cond
    locals [
        MetaDataType bMetaDataType
    ]
    : lOrExp
    ;

lVal
    locals [
        bool isArray,
        size_t size,
        MetaDataType metaDataType,
        AbstractSymbol *symbol
    ]
    : Ident ('[' exp ']')?
    ;

primaryExp
    locals [
        bool isArray,
        size_t size,
        MetaDataType metaDataType
    ]
    : '(' exp ')'   #primaryExpNestExp
    | lVal          #primaryExplVal
    | number        #primaryExpNumber
    ;

unaryExp
    locals [
        bool isArray,
        size_t size,
        MetaDataType metaDataType,
        SymbolTable *funcSymbolTable
    ]
    : primaryExp                        #unaryExpPrimaryExp
    | Ident '(' (funcRParams)? ')'      #unaryExpFunc
    | unaryOp unaryExp                  #unaryExpNestUnaryExp
    ;

unaryOp
    : '+'
    | '-'
    | '!'
    ;

funcRParams
    locals [
        SymbolTable *funcSymbolTable
    ]
    : exp (',' exp)*
    ;

mulExp
    locals [
        bool isArray,
        size_t size,
        MetaDataType metaDataType
    ]
    : unaryExp                              #mulExpUnaryExp
    | mulExp ('*' | '/' | '%') unaryExp     #mulExpMulExp
    ;

addExp
    locals [
        bool isArray,
        size_t size,
        MetaDataType metaDataType
    ]
    : mulExp                        #addExpMulExp
    | addExp ('+' | '-') mulExp     #addExpAddExp
    ;

relExp
    locals [
        bool isArray,
        size_t size,
        MetaDataType metaDataType
    ]
    : addExp                                    #relExpAddExp
    | relExp ('<' | '>' | '<=' | '>=') addExp   #relExpRelExp
    | BoolConst                                 #relExpBoolConst
    ;

eqExp
    locals [
        bool isArray,
        size_t size,
        MetaDataType metaDataType
    ]
    : relExp                        #eqExpRelExp
    | eqExp ('==' | '!=') relExp    #eqExpEqExp
    ;

lAndExp
    locals [
        bool isArray,
        size_t size,
        MetaDataType metaDataType
    ]
    : eqExp                         #lAndExpEqExp
    | lAndExp ('&&') eqExp          #lAndExpLAndExp
    ;

lOrExp
    locals [
        bool isArray,
        size_t size,
        MetaDataType metaDataType
    ]
    : lAndExp                       #lOrExpLAndExp
    | lOrExp ('||') lAndExp         #lOrExpLOrExp
    ;

constExp
    locals[
        MetaDataType metaDataType
    ]
    : number            #constExpNumber
    | BoolConst         #constExpBoolConst
    ;

number
    locals[
        MetaDataType metaDataType
    ]
    : IntConst          #numberIntConst
    | DoubleConst       #numberDoubleConst
    | FloatConst        #numberFloatConst
    ;

/********** Lexer **********/

BoolConst : 'true' | 'false';

Ident
    : IdentNondigit [a-zA-Z_0-9]*
    ;

fragment
IdentNondigit
    : [a-zA-Z_]
    ;

fragment
Digit
    : [0-9]
    ;

IntConst
    : DecimalConst 
    | OctalConst
    | HexadecimalConst
    ;

fragment
DecimalConst
    : '0'
    | NonzeroDigit Digit*
    ;

fragment
OctalConst
    : '0' OctalDigit+
    ;

fragment
HexadecimalConst
    : HexadecimalPrefix HexadecimalDigit+
    ;

fragment
NonzeroDigit
    : [1-9]
    ;

fragment
OctalDigit
    : [0-7]
    ;

fragment
HexadecimalPrefix
    : '0x'
    | '0X'
    ;

fragment
HexadecimalDigit
    : [0-9a-fA-F]
    ;
    
DigitSequence
    : Digit+
    ;

FloatConst
    : DoubleConst ('f' | 'F')
    ;


DoubleConst
    : FractionalConst ExponentPart?
    | DigitSequence ExponentPart
    ;

fragment
FractionalConst
    : DigitSequence? '.' DigitSequence
    | DigitSequence '.'
    ;

fragment
ExponentPart
    : ('e' | 'E')('+' | '-')? DigitSequence
    ;

NewLine
    : ('\r' '\n'? | '\n') 
      -> skip
    ;

WhiteSpace
    : [ \t]+ 
      -> skip
    ;

BlockComment
    : '/*' .*? '*/'
      -> skip
    ;

LineComment
    : '//' ~[\r\n]*
      -> skip
    ;