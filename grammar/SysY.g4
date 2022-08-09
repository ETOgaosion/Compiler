grammar SysY;

// The language generated
options {
    language = Cpp;
}

@header {
    #include "../src/SymbolTable.h"
    #include "../src/IROperands.h"
    #include "../src/IRCode.h"
    #include "../src/comm.h"
    #include <vector>
    #include <unordered_map>
}

/********** Parser **********/
compUnit
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
    | 'float'
    ;

constDef
    locals [
        std::string symbolName,
        MetaDataType type,
        bool withType,
        std::vector<std::size_t> shape,
        bool isArray,
        IRValue* value
    ]
    : Ident ('[' exp ']')* ('=' constInitVal)?
    ;

constInitVal
    locals [
        bool outside,
        MetaDataType type,
        std::vector<std::size_t> shape,
        bool isArray,
        std::vector<std::string> vals,
        IRValue* value,
        std::vector<Comm *> commVal
    ]
    : exp                                      #constInitValOfVar
    | '{' (constInitVal (',' constInitVal)*)? '}'   #constInitValOfArray
    ;

varDecl
    : bType varDef (',' varDef)* ';'
    ;

varDef
    locals [
        std::string symbolName,
        MetaDataType type,
        bool withType,
        std::vector<std::size_t> shape,
        bool isArray,
        IROperand* value
    ]
    : Ident ('[' exp ']')* ('=' initVal)?
    ;

initVal
    locals [
        bool outside,
        MetaDataType type,
        std::vector<std::size_t> shape,
        bool isArray,
        std::vector<std::string> vals,
        IROperand* value,
        std::vector<Comm *> commVal
    ]
    : exp                                   #initValOfVar
    | '{' (initVal (',' initVal)*)? '}'     #initValOfArray
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
    ;

funcFParams
    : funcFParam (',' funcFParam)*
    ;

funcFParam
    locals [
        IRSymbolVariable* symbolVar,
        bool isArray,
        MetaDataType paramType,
        std::vector<size_t> shape
    ]
    : bType Ident (brackets)?
    ;

brackets
    locals [
        std::vector<size_t> shape
    ]
    :'[' ']' ('[' exp ']')*
    ;

funcBlock
    locals [
        bool hasReturn,
        MetaDataType returnType,
        bool docLVal,
        std::unordered_map<IROperand *, std::vector<IROperand *>> lValDoc
    ]
    : '{' (funcBlockItem)* '}'
    ;

funcBlockItem
    locals [
        bool hasReturn,
        MetaDataType returnType,
        bool docLVal,
        std::unordered_map<IROperand *, std::vector<IROperand *>> lValDoc
    ]
    : decl 
    | stmt
    ;

stmt
    locals [
        bool hasReturn,
        MetaDataType returnType,
        std::vector<IRCode *> codes,
        IRLabel* beginWhileLabel,
        bool docLVal,
        std::unordered_map<IROperand *, std::vector<IROperand *>> lValDoc,
        std::unordered_map<IROperand *, IROperand *> latestSymbolList
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
        MetaDataType returnType,
        bool docLVal,
        std::unordered_map<IROperand *, std::vector<IROperand *>> lValDoc
    ]
    : '{' (blockItem)* '}'
    ;

blockItem
    locals [
        bool hasReturn,
        MetaDataType returnType,
        bool docLVal,
        std::unordered_map<IROperand *, std::vector<IROperand *>> lValDoc
    ]
    : decl 
    | subStmt
    ;

subStmt
    locals [
        bool hasReturn,
        MetaDataType returnType,
        std::vector<IRCode *> codes,
        IRLabel* beginWhileLabel,
        bool docLVal,
        std::unordered_map<IROperand *, std::vector<IROperand *>> lValDoc,
        std::unordered_map<IROperand *, IROperand *> latestSymbolList
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
        std::vector<std::size_t> shape,
        MetaDataType metaDataType,
        IROperand* operand,
        IROperand* indexOperand,
        bool fromVarDecl,
        int sizeNum,
        Comm *commVal
    ]
    : addExp
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
        std::vector<std::size_t> shape,
        SymbolType symbolType,
        MetaDataType lValMetaDataType,
        IRSymbolVariable* identOperand,
        IROperand* indexOperand,
        bool fromVarDecl,
        int sizeNum
    ]
    : Ident ('[' exp ']')*
    ;

primaryExp
    locals [
        bool isArray,
        std::vector<std::size_t> shape,
        MetaDataType metaDataType,
        IROperand* operand,
        IROperand* indexOperand,
        bool fromVarDecl,
        int sizeNum
    ]
    : '(' exp ')'   #primaryExpNestExp
    | lVal          #primaryExplVal
    | number        #primaryExpNumber
    ;

unaryExp
    locals [
        bool isArray,
        std::vector<std::size_t> shape,
        MetaDataType metaDataType,
        IROperand* operand,
        IROperand* indexOperand,
        bool fromVarDecl,
        int sizeNum
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
        std::vector<std::vector<std::size_t>> shapeList,
        std::vector<MetaDataType> metaDataTypeList,
        std::vector<IROperand*> operandsList
    ]
    : exp (',' exp)*
    ;

mulExp
    locals [
        bool isArray,
        std::vector<std::size_t> shape,
        MetaDataType metaDataType,
        IROperand* operand,
        IROperand* indexOperand,
        bool fromVarDecl,
        int sizeNum
    ]
    : unaryExp                              #mulExpUnaryExp
    | mulExp mulOp unaryExp                 #mulExpMulExp
    ;

mulOp
    : '*' | '/' | '%';

addExp
    locals [
        bool isArray,
        std::vector<std::size_t> shape,
        MetaDataType metaDataType,
        IROperand* operand,
        IROperand* indexOperand,
        bool fromVarDecl,
        int sizeNum
    ]
    : mulExp                        #addExpMulExp
    | addExp addOp mulExp           #addExpAddExp
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

number
    locals[
        MetaDataType metaDataType
    ]
    : IntConst          #numberIntConst
    | FloatConst        #numberFloatConst
    ;

/********** Lexer **********/

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
    : DoubleConst ('f' | 'F')?
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