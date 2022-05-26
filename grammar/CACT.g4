grammar CACT;

// The language generated
options {
    language = Cpp;
}

@header {
    #include "../src/symbolTable.h"
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
        std::string symbolName,
        std::size_t size,
        bool isArray
    ]
    : Ident ('[' IntConst ']')? '=' constInitVal
    ;

constInitVal
    locals [
        MetaDataType type,
        std::size_t size,
        bool isArray
    ]
    : (constExp)?                           #constInitValOfVar
    | '{' (constExp (',' constExp)*)? '}'   #constInitValOfArray
    ;

varDecl
    : bType varDef (',' varDef)* ';'
    ;

varDef
    locals [
        std::string symbolName,
        MetaDataType type,
        bool withType,
        std::size_t size,
        bool isArray
    ]
    : Ident ('[' IntConst ']')? ('=' constInitVal)?
    ;

funcDef
    : funcType Ident '(' (funcFParams)? ')' funcBlock
    ;

funcType
    locals [
        MetaDataType funcMetaDataType
    ]
    : 'void'
    | 'int'
    | 'float'
    | 'double'
    | 'bool'
    ;

funcFParams
    : funcFParam (',' funcFParam)*
    ;

funcFParam
    : bType Ident (brackets)?
    ;

brackets
    :'[' ']'
    ;

funcBlock
    locals [
        bool hasReturn,
        MetaDataType returnType
    ]
    : '{' (funcBlockItem)* '}'
    ;

funcBlockItem
    locals [
        bool hasReturn,
        MetaDataType returnType
    ]
    : decl 
    | stmt
    ;

stmt
    locals [
        bool hasReturn,
        MetaDataType returnType,
        std::vector<IRCode *> codes
    ]
    : lVal '=' exp ';'                                  #stmtAssignment
    | (exp)? ';'                                        #stmtExpression
    | funcBlock                                         #stmtBlock
    | 'if' '(' cond ')' stmt ('else' stmt)?             #stmtCtrlSeq
    | 'while' '(' cond ')' subStmt                      #stmtCtrlSeq
    | 'return' (exp)? ';'                               #stmtReturn
    ;

block
    locals [
        bool hasReturn,
        MetaDataType returnType
    ]
    : '{' (blockItem)* '}'
    ;

blockItem
    locals [
        bool hasReturn,
        MetaDataType returnType
    ]
    : decl 
    | subStmt
    ;

subStmt
    locals [
        bool hasReturn,
        MetaDataType returnType
    ]
    : lVal '=' exp ';'                              #subStmtAssignment
    | (exp)? ';'                                    #subStmtExpression
    | block                                         #subStmtBlock
    | 'if' '(' cond ')' subStmt ('else' subStmt)?   #subStmtCtrlSeq
    | 'while' '(' cond ')' subStmt                  #subStmtCtrlSeq
    | 'break' ';'                                   #subStmtCtrlSeq
    | 'continue' ';'                                #subStmtCtrlSeq
    | 'return' (exp)? ';'                           #subStmtReturn
    ;

exp
    locals [
        bool isArray,
        std::size_t size,
        MetaDataType metaDataType,
        IROperand result
    ]
    : addExp        #expAddExp
    | BoolConst     #expBoolExp
    ;

cond
    locals[
        IRLabel* falseLabel
    ]
    : lOrExp
    ;

lVal
    locals [
        bool isArray,
        std::size_t size,
        SymbolType symbolType,
        MetaDataType lValMetaDataType
    ]
    : Ident ('[' exp ']')?
    ;

primaryExp
    locals [
        bool isArray,
        std::size_t size,
        MetaDataType metaDataType,
        IROperand* operand
    ]
    : '(' exp ')'   #primaryExpNestExp
    | lVal          #primaryExplVal
    | number        #primaryExpNumber
    ;

unaryExp
    locals [
        bool isArray,
        std::size_t size,
        MetaDataType metaDataType,
        IROperand* operand
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
        std::vector<bool> isArrayList,
        std::vector<std::size_t> sizeList,
        std::vector<MetaDataType> metaDataTypeList,
        std::vector<IROperand*> operandsList
    ]
    : exp (',' exp)*
    ;

mulExp
    locals [
        bool isArray,
        std::size_t size,
        MetaDataType metaDataType,
        IROperand* operand
    ]
    : unaryExp                              #mulExpUnaryExp
    | mulExp mulOp unaryExp                 #mulExpMulExp
    ;

mulOp
    : '*' | '/' | '%';

addExp
    locals [
        bool isArray,
        std::size_t size,
        MetaDataType metaDataType,
        IROperand* operand
    ]
    : mulExp                        #addExpMulExp
    | addExp addOp mulExp     #addExpAddExp
    ;

addOp
    : '+' | '-';

relExp
    locals [
        MetaDataType metaDataType,
        IROperand* operand
    ]
    : addExp                                    #relExpAddExp
    | relExp relOp addExp                       #relExpRelExp
    | BoolConst                                 #relExpBoolConst
    ;

relOp
    : '<' | '>' | '<=' | '>=';

eqExp
    locals [
        MetaDataType metaDataType,
        IROperand* operand
    ]
    : relExp                        #eqExpRelExp
    | eqExp eqOp relExp             #eqExpEqExp
    ;

eqOp
    : '==' | '!=';

lAndExp
    locals [
        MetaDataType metaDataType,
        IROperand* operand
    ]
    : eqExp                         #lAndExpEqExp
    | lAndExp ('&&') eqExp          #lAndExpLAndExp
    ;

lOrExp
    locals [
        MetaDataType metaDataType,
        IROperand* operand
    ]
    : lAndExp                       #lOrExpLAndExp
    | lOrExp ('||') lAndExp         #lOrExpLOrExp
    ;

constExp
    locals[
        MetaDataType metaDataType,
        IROperand* operand
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