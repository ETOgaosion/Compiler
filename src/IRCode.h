#include "IROperands.h"

#pragma once

enum class IROperation {
    ADD_PARAM,
    GET_PARAM,
    CALL,
    RETURN,
    GET_RETURN,
    ASSIGN,
    FETCH_ARRAY_ELEM,
    ASSIGN_ARRAY_ELEM,
    ADD,
    SUB,
    NEG,
    MUL,
    DIV,
    MOD,
    NOT,
    ADD_LABEL,
    IF_EQUAL_GOTO,
    IF_NOT_EQUAL_GOTO,
    IF_GREATER_THAN_GOTO,
    IF_GREATER_EQUAL_THAN_GOTO,
    IF_LESS_THAN_GOTO,
    IF_LESS_EQUAL_THAN_GOTO,
    GOTO,
    PHI
};

class IRCode {
private:
    IROperation operation;
    IROperand *result;
    IROperand *arg1;
    IROperand *arg2;

public:
    IRCode();

    IRCode(IROperation newOp, IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    IROperation getOperation() const { return operation; };

    IROperand * getArg1() const { return arg1; };

    IROperand * getArg2() const { return arg2; };

    IROperand * getResult() const { return result; };

    virtual void print() const = 0;
    // void genTargetCode(TargetCodeList * t) = 0;
};

//!!!!!!!! consider immediate and metaDataType when generating target code !!!!!!!!!!

class IRAddLabel : public IRCode {
public:
    IRAddLabel(IROperand *newArg1);

    void print() const override;
    // void genTargetCode(TargetCodeList * t);
};

class IRAddParam : public IRCode {
public:
    IRAddParam(IROperand *newArg1);

    void print() const override;
};

class IRAddParamB : public IRAddParam {
public:
    IRAddParamB(IROperand *newArg1);
    // void genTargetCode(TargetCodeList * t);
};

class IRAddParamI : public IRAddParam {
public:
    IRAddParamI(IROperand *newArg1);
    // void genTargetCode(TargetCodeList * t);
};

class IRAddParamF : public IRAddParam {
public:
    IRAddParamF(IROperand *newArg1);
    // void genTargetCode(TargetCodeList * t);
};

class IRAddParamD : public IRAddParam {
public:
    IRAddParamD(IROperand *newArg1);
    // void genTargetCode(TargetCodeList * t);
};

class IRGetParam : public IRCode {
public:
    IRGetParam(IROperand *newResult);

    void print() const override;
};

class IRGetParamB : public IRGetParam {
public:
    IRGetParamB(IROperand *newResult);
    // void genTargetCode(TargetCodeList * t);
};

class IRGetParamI : public IRGetParam {
public:
    IRGetParamI(IROperand *newResult);
    // void genTargetCode(TargetCodeList * t);
};

class IRGetParamF : public IRGetParam {
public:
    IRGetParamF(IROperand *newResult);
    // void genTargetCode(TargetCodeList * t);
};

class IRGetParamD : public IRGetParam {
public:
    IRGetParamD(IROperand *newResult);
    // void genTargetCode(TargetCodeList * t);
};

class IRCall : public IRCode {
public:
    IRCall(IROperand *newArg1);

    void print() const override;
    // void genTargetCode(TargetCodeList * t);
};

class IRReturn : public IRCode {
public:
    IRReturn(IROperand *newArg1);

    void print() const override;
};

class IRReturnV : public IRReturn {
public:
    IRReturnV();
    // void genTargetCode(TargetCodeList * t);
};

class IRReturnB : public IRReturn {
public:
    IRReturnB(IROperand *newArg1);
    // void genTargetCode(TargetCodeList * t);
};

class IRReturnI : public IRReturn {
public:
    IRReturnI(IROperand *newArg1);
    // void genTargetCode(TargetCodeList * t);
};

class IRReturnF : public IRReturn {
public:
    IRReturnF(IROperand *newArg1);
    // void genTargetCode(TargetCodeList * t);
};

class IRReturnD : public IRReturn {
public:
    IRReturnD(IROperand *newArg1);
    // void genTargetCode(TargetCodeList * t);
};

class IRGetReturn : public IRCode {
public:
    IRGetReturn(IROperand *newResult);

    void print() const override;
};

class IRGetReturnB : public IRGetReturn {
public:
    IRGetReturnB(IROperand *newResult);
    // void genTargetCode(TargetCodeList * t);
};

class IRGetReturnI : public IRGetReturn {
public:
    IRGetReturnI(IROperand *newResult);
    // void genTargetCode(TargetCodeList * t);
};

class IRGetReturnF : public IRGetReturn {
public:
    IRGetReturnF(IROperand *newResult);
    // void genTargetCode(TargetCodeList * t);
};

class IRGetReturnD : public IRGetReturn {
public:
    IRGetReturnD(IROperand *newResult);
    // void genTargetCode(TargetCodeList * t);
};

class IRAssign : public IRCode {
public:
    IRAssign(IROperand *newResult, IROperand *newArg1);

    void print() const override;
};

class IRAssignB : public IRAssign {
public:
    IRAssignB(IROperand *newResult, IROperand *newArg1);
    // void genTargetCode(TargetCodeList * t);
};

class IRAssignI : public IRAssign {
public:
    IRAssignI(IROperand *newResult, IROperand *newArg1);
    // void genTargetCode(TargetCodeList * t);
};

class IRAssignF : public IRAssign {
public:
    IRAssignF(IROperand *newResult, IROperand *newArg1);
    // void genTargetCode(TargetCodeList * t);
};

class IRAssignD : public IRAssign {
public:
    IRAssignD(IROperand *newResult, IROperand *newArg1);
    // void genTargetCode(TargetCodeList * t);
};

class IRFetchArrayElem : public IRCode {
public:
    IRFetchArrayElem(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void print() const override;
};

class IRFetchArrayElemB : public IRFetchArrayElem {
public:
    IRFetchArrayElemB(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);
};

class IRFetchArrayElemI : public IRFetchArrayElem {
public:
    IRFetchArrayElemI(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);
};

class IRFetchArrayElemF : public IRFetchArrayElem {
public:
    IRFetchArrayElemF(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);
};

class IRFetchArrayElemD : public IRFetchArrayElem {
public:
    IRFetchArrayElemD(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);
};

class IRAssignArrayElem : public IRCode {
public:
    IRAssignArrayElem(IROperand *newSource, IROperand *newArg1, IROperand *newArg2);

    void print() const override;
};

class IRAssignArrayElemB : public IRAssignArrayElem {
public:
    IRAssignArrayElemB(IROperand *newSource, IROperand *newArg1, IROperand *newArg2);
};

class IRAssignArrayElemI : public IRAssignArrayElem {
public:
    IRAssignArrayElemI(IROperand *newSource, IROperand *newArg1, IROperand *newArg2);
};

class IRAssignArrayElemF : public IRAssignArrayElem {
public:
    IRAssignArrayElemF(IROperand *newSource, IROperand *newArg1, IROperand *newArg2);
};

class IRAssignArrayElemD : public IRAssignArrayElem {
public:
    IRAssignArrayElemD(IROperand *newSource, IROperand *newArg1, IROperand *newArg2);
};

class IRAdd : public IRCode {
public:
    IRAdd(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void print() const override;
};

class IRAddI : public IRAdd {
public:
    IRAddI(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);
    // void genTargetCode(TargetCodeList * t);
};

class IRAddF : public IRAdd {
public:
    IRAddF(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);
    // void genTargetCode(TargetCodeList * t);
};

class IRAddD : public IRAdd {
public:
    IRAddD(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);
    // void genTargetCode(TargetCodeList * t);
};

class IRSub : public IRCode {
public:
    IRSub(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void print() const override;
};

class IRSubI : public IRSub {
public:
    IRSubI(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);
    // void genTargetCode(TargetCodeList * t);
};

class IRSubF : public IRSub {
public:
    IRSubF(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);
    // void genTargetCode(TargetCodeList * t);
};

class IRSubD : public IRSub {
public:
    IRSubD(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);
    // void genTargetCode(TargetCodeList * t);
};

class IRNeg : public IRCode {
public:
    IRNeg(IROperand *newResult, IROperand *newArg1);

    void print() const override;
};

class IRNegI : public IRNeg {
public:
    IRNegI(IROperand *newResult, IROperand *newArg1);
    // void genTargetCode(TargetCodeList * t);
};

class IRNegF : public IRNeg {
public:
    IRNegF(IROperand *newResult, IROperand *newArg1);
    // void genTargetCode(TargetCodeList * t);
};

class IRNegD : public IRNeg {
public:
    IRNegD(IROperand *newResult, IROperand *newArg1);
    // void genTargetCode(TargetCodeList * t);
};

class IRMul : public IRCode {
public:
    IRMul(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void print() const override;
};

class IRMulI : public IRMul {
public:
    IRMulI(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);
    // void genTargetCode(TargetCodeList * t);
};

class IRMulF : public IRMul {
public:
    IRMulF(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);
    // void genTargetCode(TargetCodeList * t);
};

class IRMulD : public IRMul {
public:
    IRMulD(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);
    // void genTargetCode(TargetCodeList * t);
};

class IRDiv : public IRCode {
public:
    IRDiv(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void print() const override;
};

class IRDivI : public IRDiv {
public:
    IRDivI(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);
    // void genTargetCode(TargetCodeList * t);
};

class IRDivF : public IRDiv {
public:
    IRDivF(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);
    // void genTargetCode(TargetCodeList * t);
};

class IRDivD : public IRDiv {
public:
    IRDivD(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);
    // void genTargetCode(TargetCodeList * t);
};

class IRMod : public IRCode {
public:
    IRMod(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void print() const override;
    // void genTargetCode(TargetCodeList * t);
};

class IRNot : public IRCode {
public:
    IRNot(IROperand *newResult, IROperand *newArg1);

    void print() const override;
    // void genTargetCode(TargetCodeList * t);
};

class IRIfEqualGoto : public IRCode {
public:
    IRIfEqualGoto(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void print() const override;
};

class IRIfEqualGotoB : public IRIfEqualGoto {
public:
    IRIfEqualGotoB(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);
    // void genTargetCode(TargetCodeList * t);
};

class IRIfEqualGotoI : public IRIfEqualGoto {
public:
    IRIfEqualGotoI(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);
    // void genTargetCode(TargetCodeList * t);
};

class IRIfEqualGotoF : public IRIfEqualGoto {
public:
    IRIfEqualGotoF(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);
    // void genTargetCode(TargetCodeList * t);
};

class IRIfEqualGotoD : public IRIfEqualGoto {
public:
    IRIfEqualGotoD(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);
    // void genTargetCode(TargetCodeList * t);
};

class IRIfNotEqualGoto : public IRCode {
public:
    IRIfNotEqualGoto(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void print() const override;
};

class IRIfNotEqualGotoB : public IRIfNotEqualGoto {
public:
    IRIfNotEqualGotoB(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);
    // void genTargetCode(TargetCodeList * t);
};

class IRIfNotEqualGotoI : public IRIfNotEqualGoto {
public:
    IRIfNotEqualGotoI(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);
    // void genTargetCode(TargetCodeList * t);
};

class IRIfNotEqualGotoF : public IRIfNotEqualGoto {
public:
    IRIfNotEqualGotoF(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);
    // void genTargetCode(TargetCodeList * t);
};

class IRIfNotEqualGotoD : public IRIfNotEqualGoto {
public:
    IRIfNotEqualGotoD(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);
    // void genTargetCode(TargetCodeList * t);
};

class IRIfGreaterThanGoto : public IRCode {
public:
    IRIfGreaterThanGoto(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void print() const override;
};

class IRIfGreaterThanGotoI : public IRIfGreaterThanGoto {
public:
    IRIfGreaterThanGotoI(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);
    // void genTargetCode(TargetCodeList * t);
};

class IRIfGreaterThanGotoF : public IRIfGreaterThanGoto {
public:
    IRIfGreaterThanGotoF(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);
    // void genTargetCode(TargetCodeList * t);
};

class IRIfGreaterThanGotoD : public IRIfGreaterThanGoto {
public:
    IRIfGreaterThanGotoD(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);
    // void genTargetCode(TargetCodeList * t);
};

class IRIfGreaterEqualThanGoto : public IRCode {
public:
    IRIfGreaterEqualThanGoto(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void print() const override;
};

class IRIfGreaterEqualThanGotoI : public IRIfGreaterEqualThanGoto {
public:
    IRIfGreaterEqualThanGotoI(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);
    // void genTargetCode(TargetCodeList * t);
};

class IRIfGreaterEqualThanGotoF : public IRIfGreaterEqualThanGoto {
public:
    IRIfGreaterEqualThanGotoF(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);
    // void genTargetCode(TargetCodeList * t);
};

class IRIfGreaterEqualThanGotoD : public IRIfGreaterEqualThanGoto {
public:
    IRIfGreaterEqualThanGotoD(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);
    // void genTargetCode(TargetCodeList * t);
};

class IRIfLessThanGoto : public IRCode {
public:
    IRIfLessThanGoto(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void print() const override;
};

class IRIfLessThanGotoI : public IRIfLessThanGoto {
public:
    IRIfLessThanGotoI(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);
    // void genTargetCode(TargetCodeList * t);
};

class IRIfLessThanGotoF : public IRIfLessThanGoto {
public:
    IRIfLessThanGotoF(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);
    // void genTargetCode(TargetCodeList * t);
};

class IRIfLessThanGotoD : public IRIfLessThanGoto {
public:
    IRIfLessThanGotoD(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);
    // void genTargetCode(TargetCodeList * t);
};

class IRIfLessEqualThanGoto : public IRCode {
public:
    IRIfLessEqualThanGoto(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void print() const override;
};

class IRIfLessEqualThanGotoI : public IRIfLessEqualThanGoto {
public:
    IRIfLessEqualThanGotoI(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);
    // void genTargetCode(TargetCodeList * t);
};

class IRIfLessEqualThanGotoF : public IRIfLessEqualThanGoto {
public:
    IRIfLessEqualThanGotoF(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);
    // void genTargetCode(TargetCodeList * t);
};

class IRIfLessEqualThanGotoD : public IRIfLessEqualThanGoto {
public:
    IRIfLessEqualThanGotoD(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);
    // void genTargetCode(TargetCodeList * t);
};

class IRGoto : public IRCode {
public:
    IRGoto(IROperand *newLabel);
    // void genTargetCode(TargetCodeList * t);
};

class IRPhi : public IRCode {
public:
    IRPhi(IROperand *newResult, IROperand *newArg1, IROperand *newArg2);

    void print() const override;
};