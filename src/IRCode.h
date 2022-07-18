#include "IROperands.h"
#include "TargetCodes.h"

#pragma once

enum class IROperation {
    ADD,
    SUB,
    NEG,
    MUL,
    DIV,
    MOD,
    NOT,
    OR,
    AND,
    SEQ,
    SNE,
    SLT,
    SGT,
    SLEQ,
    SGEQ,
    BEQZ,
    GOTO,
    PHI,
    REPLACE,
    ASSIGN,
    FETCH_ARRAY_ELEM,
    ASSIGN_ARRAY_ELEM,
    ADD_LABEL,
    ADD_PARAM,
    GET_PARAM,
    CALL,
    RETURN,
    GET_RETURN
};

/* @usage: parent-oriented: IRCode *newCode = new IRAddI(res, arg1, arg2); */
/*         and you can use child's methods which are defined as virtual methods in parent, */
/*         also attributes belong to child */
class IRCode {
protected:
    IROperation operation;
    IROperand *result;
    IROperand *arg1;
    IROperand *arg2;

public:
    /* @initialize: never use these directly, use child's initialize functions */
    IRCode();

    IRCode(IROperation newOp, IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    /* @return: IROperation */
    IROperation getOperation() const { return operation; };

    /* @return: arg1 operand */
    IROperand *getArg1() const { return arg1; };

    /* @return: arg2 operand */
    IROperand *getArg2() const { return arg2; };

    /* @return: args, only for PHI function */
    virtual std::vector<IROperand *> getArgs() const { return {}; };

    /* @return: result operand */
    IROperand *getResult() const { return result; };

    /* @NOTICE: you can set operands, but be aware that you'll still call ex-child's methods */
    /*          so target codes generated will be in the same process */
    /*          in Optimization process, if you hope to change operation */
    /*          you should delete and free original code, and fill in new code, instead of renew operation */
    /* set arg1 field, use it in Optimization process */
    /* @param: arg1 operand */
    /* @return: true if success like any other set operations which return bool */
    bool setArg1(IROperand *arg);

    /* set arg2 field, use it in Optimization process */
    /* @param: arg2 operand */
    bool setArg2(IROperand *arg);

    /* set res field, use it in Optimization process */
    /* @param: res operand */
    bool setResult(IROperand *res);

    /* pretty print code, use it in output process */
    virtual void print() const = 0;

    /* generateTarget Code, once the object created, the method will be fixed */
    virtual void genTargetCode(TargetCodes *t) {};

    /* judge whether an operation has lVal */
    /* @return: true if have lVal, else false */
    static bool isAssignmentOperation(IROperation inOperation);

    /* judge whether an operation has lVal, arg1 and arg2 */
    /* @return: true if have 2 args, else false */
    static bool isTwoArgAssignmentOperation(IROperation inOperation);
};

/* @form: result = arg1 + arg2 */
/* @initialize: res arg1 arg2, all standard three operands operations are the same; */
/*              but never initialize this directly, use its child */
class IRAdd : public IRCode {
public:
    IRAdd(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void print() const override;
};

/* all operands are integer, like any other operations with I as a suffix */
class IRAddI : public IRAdd {
public:
    IRAddI(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void genTargetCode(TargetCodes *t) override;
};

/* all operands are float, like any other operations with F as a suffix */
class IRAddF : public IRAdd {
public:
    IRAddF(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void genTargetCode(TargetCodes *t) override;
};

/* @form: result = arg1 - arg2 */
class IRSub : public IRCode {
public:
    IRSub(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void print() const override;
};

class IRSubI : public IRSub {
public:
    IRSubI(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void genTargetCode(TargetCodes *t) override;
};

class IRSubF : public IRSub {
public:
    IRSubF(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void genTargetCode(TargetCodes *t) override;
};

/* @form: result = -arg1 */
/* @initialize: res arg1, all standard two operands operations are the same; */
/*              but never initialize this directly, use its child */
class IRNeg : public IRCode {
public:
    IRNeg(IROperand *newResult, IROperand *newArg1);

    void print() const override;
};

class IRNegI : public IRNeg {
public:
    IRNegI(IROperand *newResult, IROperand *newArg1);

    void genTargetCode(TargetCodes *t) override;
};

class IRNegF : public IRNeg {
public:
    IRNegF(IROperand *newResult, IROperand *newArg1);

    void genTargetCode(TargetCodes *t) override;
};

/* @form: result = arg1 * arg2 */
class IRMul : public IRCode {
public:
    IRMul(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void print() const override;
};

class IRMulI : public IRMul {
public:
    IRMulI(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void genTargetCode(TargetCodes *t) override;
};

class IRMulF : public IRMul {
public:
    IRMulF(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void genTargetCode(TargetCodes *t) override;
};

/* @form: result = arg1 / arg2 */
class IRDiv : public IRCode {
public:
    IRDiv(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void print() const override;
};

class IRDivI : public IRDiv {
public:
    IRDivI(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void genTargetCode(TargetCodes *t) override;
};

class IRDivF : public IRDiv {
public:
    IRDivF(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void genTargetCode(TargetCodes *t) override;
};

/* @form: result = arg1 % arg2 */
/* @NOTICE: all operands are integer */
/* @initialize: mod is equal to modI, directly initialize this */
/*              like any other operation apparently only support integer */
class IRMod : public IRCode {
public:
    IRMod(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void print() const override;

    void genTargetCode(TargetCodes *t) override;
};

/* @form: result = !arg1 */
/* @NOTICE: Here IR NOT is different from target RISCV code NOT */
/*          Here NOT will turn non-zero -> 0, while 0 -> 1 */
/*          target RISCV code `not a0, t1` is equal to `xori a0, t1, -1` */
class IRNot : public IRCode {
public:
    IRNot(IROperand *newResult, IROperand *newArg1);

    void print() const override;

    void genTargetCode(TargetCodes *t) override;
};

/* @form: result = arg1 || arg2 */
class IROr : public IRCode {
public:
    IROr(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void genTargetCode(TargetCodes *t) override;

    void print() const override;

};

/* @form: result = arg1 && arg2 */
class IRAnd : public IRCode {
public:
    IRAnd(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void genTargetCode(TargetCodes *t) override;

    void print() const override;

};

/* @form: result = (arg1 == arg2) */
class IRSeq: public IRCode {
public:
    IRSeq(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void print() const override;
};

class IRSeqI: public IRSeq {
public:
    IRSeqI(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void genTargetCode(TargetCodes *t) override;
};

class IRSeqF: public IRSeq {
public:
    IRSeqF(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void genTargetCode(TargetCodes *t) override;
};

/* @form: result = (arg1 != arg2) */
class IRSne: public IRCode {
public:
    IRSne(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void print() const override;
};

class IRSneI: public IRSne {
public:
    IRSneI(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void genTargetCode(TargetCodes *t) override;
};

class IRSneF: public IRSne {
public:
    IRSneF(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void genTargetCode(TargetCodes *t) override;
};

/* @form: result = (arg1 < arg2) */
class IRSlt: public IRCode {
public:
    IRSlt(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void print() const override;
};

class IRSltI: public IRSlt {
public:
    IRSltI(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void genTargetCode(TargetCodes *t) override;
};

class IRSltF: public IRSlt {
public:
    IRSltF(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void genTargetCode(TargetCodes *t) override;
};

/* @form: result = (arg1 > arg2) */
class IRSgt: public IRCode {
public:
    IRSgt(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void print() const override;
};

class IRSgtI: public IRSgt {
public:
    IRSgtI(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void genTargetCode(TargetCodes *t) override;
};

class IRSgtF: public IRSgt {
public:
    IRSgtF(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void genTargetCode(TargetCodes *t) override;
};

/* @form: result = (arg1 < arg2) */
class IRSleq: public IRCode {
public:
    IRSleq(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void print() const override;
};

class IRSleqI: public IRSleq {
public:
    IRSleqI(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void genTargetCode(TargetCodes *t) override;
};

class IRSleqF: public IRSleq {
public:
    IRSleqF(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void genTargetCode(TargetCodes *t) override;
};

/* @form: result = (arg1 >= arg2) */
class IRSgeq: public IRCode {
public:
    IRSgeq(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void print() const override;
};

class IRSgeqI: public IRSgeq {
public:
    IRSgeqI(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void genTargetCode(TargetCodes *t) override;
};

class IRSgeqF: public IRSgeq {
public:
    IRSgeqF(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void genTargetCode(TargetCodes *t) override;
};

/* if arg1 == 0, branch to label */
/* @form: beqz arg1, newLabel(arg2) */
class IRBeqz : public IRCode {
public:
    IRBeqz(IROperand *newArg1, IROperand *newLabel);

    void genTargetCode(TargetCodes *t) override;

    void print() const override;
};

/* directly branch to label */
/* @form: goto newLabel(arg1) */
class IRGoto : public IRCode {
public:
    explicit IRGoto(IROperand *newLabel);

    void genTargetCode(TargetCodes *t) override;

    void print() const override;
};

/* PHI operation only use in IR, genTargetCode will do nothing */
/* if some symbols are defined in branch blocks, when coming out these symbols will be in PHI operation as an active announcement */
/* @example: */
/* ``` */
/* if a < b */
/*      t1 <= c */
/*      t1 = 2 */
/* t2 = PHI(c, t1) */
/* ``` */
/* @form: res = PHI(args) */
class IRPhi : public IRCode {
private:
    std::vector<IROperand *> args;
public:
    /* @initialize: this operation is special, we allow it to have multiple args */
    IRPhi(IROperand *newResult, std::vector<IROperand *>newArg1);

    std::vector<IROperand *> getArgs() const override { return args; };

    void print() const override;
};

/* REPLACE operation only use in SSA-style IR, genTargetCode will do nothing */
/* if some symbols are defined previously, and this time the definition lVal will be replaced by a temp var, we add a replace operation to describe this process */
/* you can assume it as the reference to a certain memory(stack) location switched to a new temp var */
/* @example: */
/* ``` */
/* a = 1 */
/* a = 2 */
/* ---Turn into--- */
/* a = 1 */
/* t1 <= a */
/* t1 = 2 */
/* ``` */
/* @form: res <= arg1 */
class IRReplace : public IRCode {
public:
    IRReplace(IROperand *newResult, IROperand *newArg1);

    void genTargetCode(TargetCodes *t) override;

    void print() const override;
};

/* @form: res = arg1 */
class IRAssign : public IRCode {
public:
    IRAssign(IROperand *newResult, IROperand *newArg1);

    void print() const override;
};

class IRAssignI : public IRAssign {
public:
    IRAssignI(IROperand *newResult, IROperand *newArg1);

    void genTargetCode(TargetCodes *t) override;
};

class IRAssignF : public IRAssign {
public:
    IRAssignF(IROperand *newResult, IROperand *newArg1);

    void genTargetCode(TargetCodes *t) override;
};

/* @form: res = arg1[arg2] */
class IRFetchArrayElem : public IRCode {
public:
    IRFetchArrayElem(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void print() const override;
};

class IRFetchArrayElemI : public IRFetchArrayElem {
public:
    IRFetchArrayElemI(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void genTargetCode(TargetCodes *t) override;
};

class IRFetchArrayElemF : public IRFetchArrayElem {
public:
    IRFetchArrayElemF(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void genTargetCode(TargetCodes *t) override;
};

/* @form: arg1[arg2] = src */
class IRAssignArrayElem : public IRCode {
public:
    IRAssignArrayElem(IROperand *newSource, IROperand *newArg1, IROperand *newArg2);

    void print() const override;
};

class IRAssignArrayElemI : public IRAssignArrayElem {
public:
    IRAssignArrayElemI(IROperand *newSource, IROperand *newArg1, IROperand *newArg2);

    void genTargetCode(TargetCodes *t) override;
};

class IRAssignArrayElemF : public IRAssignArrayElem {
public:
    IRAssignArrayElemF(IROperand *newSource, IROperand *newArg1, IROperand *newArg2);

    void genTargetCode(TargetCodes *t) override;
};

/* @form: arg1: */
class IRAddLabel : public IRCode {
public:
    explicit IRAddLabel(IROperand *newArg1);

    void print() const override;

    void genTargetCode(TargetCodes *t) override;
};

/* when you want to call a function, use this to pass its params in */
/* @form: addparam arg1 */
class IRAddParam : public IRCode {
public:
    explicit IRAddParam(IROperand *newArg1);

    void print() const override;
};

class IRAddParamI : public IRAddParam {
public:
    explicit IRAddParamI(IROperand *newArg1);

    void genTargetCode(TargetCodes *t) override;
};

class IRAddParamF : public IRAddParam {
public:
    explicit IRAddParamF(IROperand *newArg1);

    void genTargetCode(TargetCodes *t) override;
};

class IRAddParamA : public IRAddParam {
public:
    explicit IRAddParamA(IROperand *newArg1);

    void genTargetCode(TargetCodes *t) override;
};

/* After you enter a function, use this to get its params passed by caller */
/* @form: getParam res, arg1 */
/* @initialize: arg1 is meant to point to certain register to pass argument */
/*              and consider register type(general purpose or float point) separately */
/*              arg1 operand type is IRValue as an immediate number, use `getValue` to get the number of `a` or `fa` series register */
class IRGetParam : public IRCode {
public:
    explicit IRGetParam(IROperand *newResult, IROperand *newArg1);

    void print() const override;
};

class IRGetParamI : public IRGetParam {
public:
    explicit IRGetParamI(IROperand *newResult, IROperand *newArg1);

    void genTargetCode(TargetCodes *t) override;
};

class IRGetParamF : public IRGetParam {
public:
    explicit IRGetParamF(IROperand *newResult, IROperand *newArg1);

    void genTargetCode(TargetCodes *t) override;
};

class IRGetParamA : public IRGetParam {
public:
    explicit IRGetParamA(IROperand *newResult, IROperand *newArg1);

    void genTargetCode(TargetCodes *t) override;
};

/* call a function */
/* @form: call arg1, arg2 */
/* @initialize: both arg1 and arg2's types are IRSymbolFunction*/
/*              arg1 describe target function, arg2 describe caller function itself */
/*              arg2's existence is to 1. get caller's frame size and `sp -= frameSize` */
/*                                     2. get designated registers fo caller and store them, recover them after calling */
class IRCall : public IRCode {
public:
    IRCall(IROperand *newArg1, IROperand *newArg2);

    void print() const override;

    void genTargetCode(TargetCodes *t) override;
};

/* return from function */
/* @form: return arg2       // return from void functions */
/* @form: return arg1, arg2 */
/* @initialize: arg1 means the value you want to return or void */
/*              arg2 means the function itself, we will use it to operate registers and stack */
class IRReturn : public IRCode {
public:
    explicit IRReturn(IROperand *newArg1, IROperand *newArg2);

    void print() const override;

    void genTargetCode(TargetCodes *t) override;
};

class IRReturnV : public IRReturn {
public:
    IRReturnV(IROperand *newArg2);

    void genTargetCode(TargetCodes *t) override;
};

class IRReturnI : public IRReturn {
public:
    explicit IRReturnI(IROperand *newArg1, IROperand *newArg2);

    void genTargetCode(TargetCodes *t) override;
};

class IRReturnF : public IRReturn {
public:
    explicit IRReturnF(IROperand *newArg1, IROperand *newArg2);

    void genTargetCode(TargetCodes *t) override;
};

/* After calling a function, get its return value */
/* @form: getReturn res */
class IRGetReturn : public IRCode {
public:
    explicit IRGetReturn(IROperand *newResult);

    void print() const override;
};

class IRGetReturnI : public IRGetReturn {
public:
    explicit IRGetReturnI(IROperand *newResult);

    void genTargetCode(TargetCodes *t) override;
};

class IRGetReturnF : public IRGetReturn {
public:
    explicit IRGetReturnF(IROperand *newResult);

    void genTargetCode(TargetCodes *t) override;
};