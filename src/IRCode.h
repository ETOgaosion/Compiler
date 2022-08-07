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
    GET_RETURN,
    PRINT,
    READ
};

class IRCode {
protected:
    IROperation operation;
    IROperand *result;
    IROperand *arg1;
    IROperand *arg2;

public:
    IRCode();

    IRCode(IROperation newOp, IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    std::vector<IRCode *> use;

    IROperation getOperation() const { return operation; };

    IROperand *getArg1() const { return arg1; };

    IROperand *getArg2() const { return arg2; };

    virtual std::vector<IROperand *> getArgs() const { return {}; };

    IROperand *getResult() const { return result; };

    bool setArg1(IROperand *arg);

    bool setArg2(IROperand *arg);

    bool setResult(IROperand *res);

    bool setOperation(IROperation op);

    virtual void print() const = 0;

    virtual void genTargetCode(TargetCodes *t) {};

    static bool isAssignmentOperation(IROperation inOperation);

    static bool isTwoArgAssignmentOperation(IROperation inOperation);

    static bool isOrderIndependentOperation(IROperation inOperation);

};

//!!!!!!!! consider immediate and metaDataType when generating target code !!!!!!!!!!

class IRAdd : public IRCode {
public:
    IRAdd(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void print() const override;
};

class IRAddI : public IRAdd {
public:
    IRAddI(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void genTargetCode(TargetCodes *t) override;
};

class IRAddF : public IRAdd {
public:
    IRAddF(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void genTargetCode(TargetCodes *t) override;
};

class IRAddD : public IRAdd {
public:
    IRAddD(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void genTargetCode(TargetCodes *t) override;
};

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

class IRSubD : public IRSub {
public:
    IRSubD(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void genTargetCode(TargetCodes *t) override;
};

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

class IRNegD : public IRNeg {
public:
    IRNegD(IROperand *newResult, IROperand *newArg1);

    void genTargetCode(TargetCodes *t) override;
};

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

class IRMulD : public IRMul {
public:
    IRMulD(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void genTargetCode(TargetCodes *t) override;
};

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

class IRDivD : public IRDiv {
public:
    IRDivD(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void genTargetCode(TargetCodes *t) override;
};

class IRMod : public IRCode {
public:
    IRMod(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void print() const override;

    void genTargetCode(TargetCodes *t) override;
};

class IRNot : public IRCode {
public:
    IRNot(IROperand *newResult, IROperand *newArg1);

    void print() const override;

    void genTargetCode(TargetCodes *t) override;
};

class IROr : public IRCode {
public:
    IROr(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void genTargetCode(TargetCodes *t) override;

    void print() const override;

};

class IRAnd : public IRCode {
public:
    IRAnd(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void genTargetCode(TargetCodes *t) override;

    void print() const override;

};

class IRSeq: public IRCode {
public:
    IRSeq(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void print() const override;
};

class IRSeqB: public IRSeq {
public:
    IRSeqB(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void genTargetCode(TargetCodes *t) override;
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

class IRSeqD: public IRSeq {
public:
    IRSeqD(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void genTargetCode(TargetCodes *t) override;
};

class IRSne: public IRCode {
public:
    IRSne(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void print() const override;
};

class IRSneB: public IRSne {
public:
    IRSneB(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void genTargetCode(TargetCodes *t) override;
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

class IRSneD: public IRSne {
public:
    IRSneD(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void genTargetCode(TargetCodes *t) override;
};

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

class IRSltD: public IRSlt {
public:
    IRSltD(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void genTargetCode(TargetCodes *t) override;
};

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

class IRSgtD: public IRSgt {
public:
    IRSgtD(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void genTargetCode(TargetCodes *t) override;
};

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

class IRSleqD: public IRSleq {
public:
    IRSleqD(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void genTargetCode(TargetCodes *t) override;
};

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

class IRSgeqD: public IRSgeq {
public:
    IRSgeqD(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void genTargetCode(TargetCodes *t) override;
};

class IRBeqz : public IRCode {
public:
    int whicn_bb;
    
    IRBeqz(IROperand *newArg1, IROperand *newLabel);

    void genTargetCode(TargetCodes *t) override;

    void print() const override;
};

class IRGoto : public IRCode {
public:
    explicit IRGoto(IROperand *newLabel);

    void genTargetCode(TargetCodes *t) override;

    void print() const override;
};

class IRPhi : public IRCode {
private:
    ;

public:
    std::vector<IROperand *> args;
    IRPhi(IROperand *newResult, std::vector<IROperand *>newArg1);

    std::vector<IROperand *> getArgs() const override { return args; };

    void print() const override;
};

class IRReplace : public IRCode {
public:
    IRReplace(IROperand *newResult, IROperand *newArg1);

    void genTargetCode(TargetCodes *t) override;

    void print() const override;
};

class IRAssign : public IRCode {
public:
    IRAssign(IROperand *newResult, IROperand *newArg1);

    void print() const override;
};


class IRAssignB : public IRAssign {
public:
    IRAssignB(IROperand *newResult, IROperand *newArg1);

    void genTargetCode(TargetCodes *t) override;
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

class IRAssignD : public IRAssign {
public:
    IRAssignD(IROperand *newResult, IROperand *newArg1);

    void genTargetCode(TargetCodes *t) override;
};

class IRFetchArrayElem : public IRCode {
public:
    IRFetchArrayElem(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void print() const override;
};

class IRFetchArrayElemB : public IRFetchArrayElem {
public:
    IRFetchArrayElemB(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void genTargetCode(TargetCodes *t) override;
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

class IRFetchArrayElemD : public IRFetchArrayElem {
public:
    IRFetchArrayElemD(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void genTargetCode(TargetCodes *t) override;
};

class IRAssignArrayElem : public IRCode {
public:
    IRAssignArrayElem(IROperand *newSource, IROperand *newArg1, IROperand *newArg2);

    void print() const override;
};

class IRAssignArrayElemB : public IRAssignArrayElem {
public:
    IRAssignArrayElemB(IROperand *newSource, IROperand *newArg1, IROperand *newArg2);

    void genTargetCode(TargetCodes *t) override;
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

class IRAssignArrayElemD : public IRAssignArrayElem {
public:
    IRAssignArrayElemD(IROperand *newSource, IROperand *newArg1, IROperand *newArg2);

    void genTargetCode(TargetCodes *t) override;
};

class IRAddLabel : public IRCode {
public:
    explicit IRAddLabel(IROperand *newArg1);

    void print() const override;

    void genTargetCode(TargetCodes *t) override;
};

class IRAddParam : public IRCode {
public:
    explicit IRAddParam(IROperand *newArg1);

    void print() const override;
};

class IRAddParamB : public IRAddParam {
public:
    explicit IRAddParamB(IROperand *newArg1);

    void genTargetCode(TargetCodes *t) override;
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

class IRAddParamD : public IRAddParam {
public:
    explicit IRAddParamD(IROperand *newArg1);

    void genTargetCode(TargetCodes *t) override;
};

class IRAddParamA : public IRAddParam {
public:
    explicit IRAddParamA(IROperand *newArg1);

    void genTargetCode(TargetCodes *t) override;
};

class IRGetParam : public IRCode {
public:
    explicit IRGetParam(IROperand *newResult, IROperand *newArg1);

    void print() const override;
};

class IRGetParamB : public IRGetParam {
public:
    explicit IRGetParamB(IROperand *newResult, IROperand *newArg1);

    void genTargetCode(TargetCodes *t) override;
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

class IRGetParamD : public IRGetParam {
public:
    explicit IRGetParamD(IROperand *newResult, IROperand *newArg1);

    void genTargetCode(TargetCodes *t) override;
};

class IRGetParamA : public IRGetParam {
public:
    explicit IRGetParamA(IROperand *newResult, IROperand *newArg1);

    void genTargetCode(TargetCodes *t) override;
};

class IRCall : public IRCode {
public:
    explicit IRCall(IROperand *newArg1, IROperand *newArg2);

    void print() const override;

    void genTargetCode(TargetCodes *t) override;
};

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

class IRReturnB : public IRReturn {
public:
    explicit IRReturnB(IROperand *newArg1, IROperand *newArg2);

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

class IRReturnD : public IRReturn {
public:
    explicit IRReturnD(IROperand *newArg1, IROperand *newArg2);

    void genTargetCode(TargetCodes *t) override;
};

class IRGetReturn : public IRCode {
public:
    explicit IRGetReturn(IROperand *newResult);

    void print() const override;
};

class IRGetReturnB : public IRGetReturn {
public:
    explicit IRGetReturnB(IROperand *newResult);

    void genTargetCode(TargetCodes *t) override;
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

class IRGetReturnD : public IRGetReturn {
public:
    explicit IRGetReturnD(IROperand *newResult);

    void genTargetCode(TargetCodes *t) override;
};

class IRPrint : public IRCode {
public:
    explicit IRPrint(IROperand *newArg1);

    void print() const override;
};

class IRPrintB : public IRPrint {
public:
    explicit IRPrintB(IROperand *newArg1);

    void genTargetCode(TargetCodes *t) override;
};

class IRPrintI : public IRPrint {
public:
    explicit IRPrintI(IROperand *newArg1);

    void genTargetCode(TargetCodes *t) override;
};

class IRPrintF : public IRPrint {
public:
    explicit IRPrintF(IROperand *newArg1);

    void genTargetCode(TargetCodes *t) override;
};

class IRPrintD : public IRPrint {
public:
    explicit IRPrintD(IROperand *newArg1);

    void genTargetCode(TargetCodes *t) override;
};

class IRRead : public IRCode {
public:
    explicit IRRead(IROperand *newResult);

    void print() const override;
};

class IRReadI : public IRRead {
public:
    explicit IRReadI(IROperand *newArg1);

    void genTargetCode(TargetCodes *t) override;
};

class IRReadF : public IRRead {
public:
    explicit IRReadF(IROperand *newArg1);

    void genTargetCode(TargetCodes *t) override;
};

class IRReadD : public IRRead {
public:
    explicit IRReadD(IROperand *newArg1);

    void genTargetCode(TargetCodes *t) override;
};