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
    : 'int'
    | 'bool'
    | 'double'
    | 'float'
    ;

constDef
    : Ident ('[' IntConst ']')? '=' constInitVal
    ;

constInitVal
    locals[
        int basic_or_array_and_type
    ]
    : constExp
    | '{' (constExp (',' constExp)*)? '}'                                             
    ;

varDecl
    : bType varDef (',' varDef)* ';'
    ;

varDef
    : Ident ('[' IntConst ']')? ('=' constInitVal)?
    ;

funcDef
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
    : funcFParam (',' funcFParam)*
    ;

funcFParam
    : bType Ident ('[' ']')?
    ;

block
    : '{' (blockItem)* '}'
    ;

blockItem
    : decl 
    | stmt
    ;

stmt
    : lVal '=' exp ';'
    | (exp)? ';'
    | block
    | 'if' '(' cond ')' stmt ('else' stmt)?
    | 'while' '(' cond ')' stmt
    | 'break' ';' 
    | 'contine' ';'
    | 'return' (exp)? ';'
    ;

exp
    : addExp
    | BoolConst
    ;

cond
    : lOrExp
    ;

lVal
    : Ident ('[' exp ']')?
    ;

primaryExp
    : '(' exp ')' 
    | lVal 
    | number 
    ;

unaryExp
    : primaryExp
    | Ident '(' (funcRParams)? ')'
    | unaryOp unaryExp
    ;

unaryOp
    : '+'
    | '-'
    | '!'
    ;

funcRParams
    : exp (',' exp)*
    ;

mulExp
    : unaryExp ( ('*'|'/'|'%') unaryExp )*
    ;

addExp
    : mulExp (('+' | '-') mulExp)*
    ;

relExp
    : addExp (('<' | '>' | '<=' | '>=') addExp)*
    | BoolConst
    ;

eqExp
    : relExp (('==' | '!=') relExp)*
    ;

lAndExp
    : eqExp (('&&') eqExp)*
    ;

lOrExp
    : lAndExp (('||') lAndExp)*
    ;

constExp
    locals[
        int basic_or_array_and_type,
    ]
    : number        #constExpNumber
    | BoolConst     #constBoolConst
    ;

number
    locals[
        int basic_or_array_and_type,
    ]
    : IntConst
    | DoubleConst
    | FloatConst
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

fragment
Index
    : ('E' | 'e') ('+' | '-')? (Digit)+
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