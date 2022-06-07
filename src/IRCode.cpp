#include <iostream>

#include "IRCode.h"

using namespace std;

IRCode::IRCode() {
    operation = IROperation::ADD_PARAM;
    result = nullptr;
    arg1 = nullptr;
    arg2 = nullptr;
}

IRCode::IRCode(IROperation newOp, IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : operation(newOp), result(newResult), arg1(newArg1), arg2(newArg2) {}

IRAdd::IRAdd(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRCode(IROperation::ADD, newResult, newArg1, newArg2) {}

IRAddI::IRAddI(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRAdd(newResult, newArg1, newArg2) {}

IRAddF::IRAddF(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRAdd(newResult, newArg1, newArg2) {}

IRAddD::IRAddD(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRAdd(newResult, newArg1, newArg2) {}

IRSub::IRSub(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRCode(IROperation::SUB, newResult, newArg1, newArg2) {}

IRSubI::IRSubI(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRSub(newResult, newArg1, newArg2) {}

IRSubF::IRSubF(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRSub(newResult, newArg1, newArg2) {}

IRSubD::IRSubD(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRSub(newResult, newArg1, newArg2) {}

IRNeg::IRNeg(IROperand *newResult, IROperand *newArg1)
        : IRCode(IROperation::NEG, newResult, newArg1, nullptr) {}

IRNegI::IRNegI(IROperand *newResult, IROperand *newArg1)
        : IRNeg(newResult, newArg1) {}

IRNegF::IRNegF(IROperand *newResult, IROperand *newArg1)
        : IRNeg(newResult, newArg1) {}

IRNegD::IRNegD(IROperand *newResult, IROperand *newArg1)
        : IRNeg(newResult, newArg1) {}

IRMul::IRMul(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRCode(IROperation::MUL, newResult, newArg1, newArg2) {}

IRMulI::IRMulI(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRMul(newResult, newArg1, newArg2) {}

IRMulF::IRMulF(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRMul(newResult, newArg1, newArg2) {}

IRMulD::IRMulD(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRMul(newResult, newArg1, newArg2) {}

IRDiv::IRDiv(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRCode(IROperation::DIV, newResult, newArg1, newArg2) {}

IRDivI::IRDivI(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRDiv(newResult, newArg1, newArg2) {}

IRDivF::IRDivF(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRDiv(newResult, newArg1, newArg2) {}

IRDivD::IRDivD(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRDiv(newResult, newArg1, newArg2) {}

IRMod::IRMod(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRCode(IROperation::DIV, newResult, newArg1, newArg2) {}

IRNot::IRNot(IROperand *newResult, IROperand *newArg1)
        : IRCode(IROperation::DIV, newResult, newArg1, nullptr) {}

IROr::IROr(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRCode(IROperation::OR, newResult, newArg1, newArg2) {}

IRAnd::IRAnd(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRCode(IROperation::AND, newResult, newArg1, newArg2) {}

IRSeq::IRSeq(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRCode(IROperation::SEQ, newResult, newArg1, newArg2) {}

IRSeqB::IRSeqB(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRSeq(newResult, newArg1, newArg2) {}

IRSeqI::IRSeqI(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRSeq(newResult, newArg1, newArg2) {}

IRSeqD::IRSeqD(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRSeq(newResult, newArg1, newArg2) {}

IRSeqF::IRSeqF(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRSeq(newResult, newArg1, newArg2) {}

IRSne::IRSne(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRCode(IROperation::SNE, newResult,
                 newArg1, newArg2) {}

IRSneB::IRSneB(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRSne(newResult, newArg1, newArg2) {}

IRSneI::IRSneI(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRSne(newResult, newArg1, newArg2) {}

IRSneF::IRSneF(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRSne(newResult, newArg1, newArg2) {}

IRSneD::IRSneD(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRSne(newResult, newArg1, newArg2) {}

IRSlt::IRSlt(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRCode(IROperation::SLT, newResult, newArg1, newArg2) {}

IRSltI::IRSltI(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRSlt(newResult, newArg1, newArg2) {}

IRSltF::IRSltF(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRSlt(newResult, newArg1, newArg2) {}

IRSltD::IRSltD(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRSlt(newResult, newArg1, newArg2) {}

IRSgt::IRSgt(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRCode(IROperation::SGT, newResult, newArg1, newArg2) {}

IRSgtI::IRSgtI(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRSgt(newResult, newArg1, newArg2) {}

IRSgtF::IRSgtF(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRSgt(newResult, newArg1, newArg2) {}

IRSgtD::IRSgtD(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRSgt(newResult, newArg1, newArg2) {}

IRSleq::IRSleq(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRCode(IROperation::SLEQ, newResult, newArg1, newArg2) {}

IRSleqI::IRSleqI(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRSleq(newResult, newArg1, newArg2) {}

IRSleqF::IRSleqF(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRSleq(newResult, newArg1, newArg2) {}

IRSleqD::IRSleqD(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRSleq(newResult, newArg1, newArg2) {}

IRSgeq::IRSgeq(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRCode(IROperation::SGEQ, newResult, newArg1, newArg2) {}

IRSgeqI::IRSgeqI(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRSgeq(newResult, newArg1, newArg2) {}

IRSgeqF::IRSgeqF(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRSgeq(newResult, newArg1, newArg2) {}

IRSgeqD::IRSgeqD(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRSgeq(newResult, newArg1, newArg2) {}

IRBeqz::IRBeqz(IROperand *newArg1, IROperand *newLabel)
        : IRCode(IROperation::BEQZ, nullptr, newArg1, newLabel) {}

IRGoto::IRGoto(IROperand *newLabel)
        : IRCode(IROperation::GOTO, nullptr, newLabel, nullptr) {}

IRPhi::IRPhi(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRCode(IROperation::PHI, newResult, newArg1, newArg2) {}

IRAssign::IRAssign(IROperand *newResult, IROperand *newArg1)
        : IRCode(IROperation::ASSIGN, newResult, newArg1, nullptr) {}

IRAssignB::IRAssignB(IROperand *newResult, IROperand *newArg1)
        : IRAssign(newResult, newArg1) {}

IRAssignI::IRAssignI(IROperand *newResult, IROperand *newArg1)
        : IRAssign(newResult, newArg1) {}

IRAssignF::IRAssignF(IROperand *newResult, IROperand *newArg1)
        : IRAssign(newResult, newArg1) {}

IRAssignD::IRAssignD(IROperand *newResult, IROperand *newArg1)
        : IRAssign(newResult, newArg1) {}

IRFetchArrayElem::IRFetchArrayElem(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRCode(IROperation::FETCH_ARRAY_ELEM, newResult, newArg1, newArg2) {}

IRFetchArrayElemB::IRFetchArrayElemB(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRFetchArrayElem(newResult, newArg1, newArg2) {}

IRFetchArrayElemI::IRFetchArrayElemI(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRFetchArrayElem(newResult, newArg1, newArg2) {}

IRFetchArrayElemF::IRFetchArrayElemF(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRFetchArrayElem(newResult, newArg1, newArg2) {}

IRFetchArrayElemD::IRFetchArrayElemD(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRFetchArrayElem(newResult, newArg1, newArg2) {}

IRAssignArrayElem::IRAssignArrayElem(IROperand *newSource, IROperand *newArg1, IROperand *newArg2)
        : IRCode(IROperation::ASSIGN_ARRAY_ELEM, newSource, newArg1, newArg2) {}

IRAssignArrayElemB::IRAssignArrayElemB(IROperand *newSource, IROperand *newArg1, IROperand *newArg2)
        : IRAssignArrayElem(newSource, newArg1, newArg2) {}

IRAssignArrayElemI::IRAssignArrayElemI(IROperand *newSource, IROperand *newArg1, IROperand *newArg2)
        : IRAssignArrayElem(newSource, newArg1, newArg2) {}

IRAssignArrayElemF::IRAssignArrayElemF(IROperand *newSource, IROperand *newArg1, IROperand *newArg2)
        : IRAssignArrayElem(newSource, newArg1, newArg2) {}

IRAssignArrayElemD::IRAssignArrayElemD(IROperand *newSource, IROperand *newArg1, IROperand *newArg2)
        : IRAssignArrayElem(newSource, newArg1, newArg2) {}

IRAddLabel::IRAddLabel(IROperand *newArg1)
        : IRCode(IROperation::ADD_LABEL, nullptr, newArg1, nullptr) {}

IRAddParam::IRAddParam(IROperand *newArg1)
        : IRCode(IROperation::ADD_PARAM, nullptr, newArg1, nullptr) {}

IRAddParamB::IRAddParamB(IROperand *newArg1)
        : IRAddParam(newArg1) {}

IRAddParamI::IRAddParamI(IROperand *newArg1)
        : IRAddParam(newArg1) {}

IRAddParamF::IRAddParamF(IROperand *newArg1)
        : IRAddParam(newArg1) {}

IRAddParamD::IRAddParamD(IROperand *newArg1)
        : IRAddParam(newArg1) {}

IRAddParamA::IRAddParamA(IROperand *newArg1) : IRAddParam(newArg1) {}

IRGetParam::IRGetParam(IROperand *newResult, IROperand *newArg1)
        : IRCode(IROperation::GET_PARAM, newResult, newArg1, nullptr) {}

IRGetParamB::IRGetParamB(IROperand *newResult, IROperand *newArg1)
        : IRGetParam(newResult, newArg1) {}

IRGetParamI::IRGetParamI(IROperand *newResult, IROperand *newArg1)
        : IRGetParam(newResult, newArg1) {}

IRGetParamF::IRGetParamF(IROperand *newResult, IROperand *newArg1)
        : IRGetParam(newResult, newArg1) {}

IRGetParamD::IRGetParamD(IROperand *newResult, IROperand *newArg1)
        : IRGetParam(newResult, newArg1) {}

IRGetParamA::IRGetParamA(IROperand *newResult, IROperand *newArg1)
        : IRGetParam(newResult, newArg1) {}

IRCall::IRCall(IROperand *newArg1)
        : IRCode(IROperation::CALL, nullptr, newArg1, nullptr) {}

IRReturn::IRReturn(IROperand *newArg1)
        : IRCode(IROperation::RETURN, nullptr, newArg1, nullptr) {}

IRReturnV::IRReturnV()
        : IRReturn(nullptr) {}

IRReturnB::IRReturnB(IROperand *newArg1)
        : IRReturn(newArg1) {}

IRReturnI::IRReturnI(IROperand *newArg1)
        : IRReturn(newArg1) {}

IRReturnF::IRReturnF(IROperand *newArg1)
        : IRReturn(newArg1) {}

IRReturnD::IRReturnD(IROperand *newArg1)
        : IRReturn(newArg1) {}

IRGetReturn::IRGetReturn(IROperand *newResult)
        : IRCode(IROperation::GET_RETURN, newResult, nullptr, nullptr) {}

IRGetReturnB::IRGetReturnB(IROperand *newResult)
        : IRGetReturn(newResult) {}

IRGetReturnI::IRGetReturnI(IROperand *newResult)
        : IRGetReturn(newResult) {}

IRGetReturnF::IRGetReturnF(IROperand *newResult)
        : IRGetReturn(newResult) {}

IRGetReturnD::IRGetReturnD(IROperand *newResult)
        : IRGetReturn(newResult) {}

void IRAdd::print() const {
    cout << result->getSymbolName() << " = "
         << arg1->getSymbolName() << " + "
         << arg2->getSymbolName() << ";" << endl;
}

void IRSub::print() const {
    cout << result->getSymbolName() << " = "
         << arg1->getSymbolName() << " - "
         << arg2->getSymbolName() << ";" << endl;
}

void IRNeg::print() const {
    cout << result->getSymbolName() << " = "
         << " - "
         << arg1->getSymbolName() << ";" << endl;
}

void IRMul::print() const {
    cout << result->getSymbolName() << " = "
         << arg1->getSymbolName() << " * "
         << arg2->getSymbolName() << ";" << endl;
}

void IRDiv::print() const {
    cout << result->getSymbolName() << " = "
         << arg1->getSymbolName() << " / "
         << arg2->getSymbolName() << ";" << endl;
}

void IRMod::print() const {
    cout << result->getSymbolName() << " = "
         << arg1->getSymbolName() << " % "
         << arg2->getSymbolName() << ";" << endl;
}

void IRNot::print() const {
    cout << result->getSymbolName() << " = not"
         << arg1->getSymbolName() << ";" << endl;
}

void IROr::print() const {
    cout << result->getSymbolName() << " = "
         << arg1->getSymbolName() << " || " << arg2->getSymbolName() << endl;
}

void IRAnd::print() const {
    cout << result->getSymbolName() << " = "
         << arg1->getSymbolName() << " && " << arg2->getSymbolName() << endl;
}

void IRSeq::print() const {
    cout << result->getSymbolName() << " = "
         << arg1->getSymbolName() << " == " << arg2->getSymbolName() << endl;
}

void IRSne::print() const {
    cout << result->getSymbolName() << " = "
         << arg1->getSymbolName() << " != " << arg2->getSymbolName() << endl;
}

void IRSlt::print() const {
    cout << result->getSymbolName() << " = "
         << arg1->getSymbolName() << " < " << arg2->getSymbolName() << endl;
}

void IRSgt::print() const {
    cout << result->getSymbolName() << " = "
         << arg1->getSymbolName() << " > " << arg2->getSymbolName() << endl;
}

void IRSleq::print() const {
    cout << result->getSymbolName() << " = "
         << arg1->getSymbolName() << " <= " << arg2->getSymbolName() << endl;
}

void IRSgeq::print() const {
    cout << result->getSymbolName() << " = "
         << arg1->getSymbolName() << " >= " << arg2->getSymbolName() << endl;
}

void IRBeqz::print() const {
    cout << "BEQZ "
         << arg1->getSymbolName() << " "
         << arg2->getSymbolName()<< endl;
}

void IRGoto::print() const {
    cout << "GOTO " << arg1->getSymbolName();
}

void IRPhi::print() const {
    cout << result->getSymbolName() << " = phi("
         << arg1->getSymbolName() << ","
         << arg2->getSymbolName() << ")";
}

void IRAssign::print() const {
    cout << result->getSymbolName() << " = "
         << arg1->getSymbolName() << ";" << endl;
}

void IRFetchArrayElem::print() const {
    cout << result->getSymbolName() << " = "
         << arg1->getSymbolName() << "["
         << arg2->getSymbolName() << "];" << endl;
}

void IRAssignArrayElem::print() const {
    cout << arg1->getSymbolName() << "["
         << arg2->getSymbolName() << "] = "
         << result->getSymbolName() << ";" << endl;
}

void IRAddLabel::print() const {
    cout << arg1->getSymbolName() << ":" << endl;
}

void IRAddParam::print() const {
    cout << "addparam " << arg1->getSymbolName() << ";" << endl;
}

void IRGetParam::print() const {
    cout << result->getSymbolName() << " = " << " param " << arg1->getSymbolName()
         << ";" << endl;
}

void IRCall::print() const {
    cout << "call "
         << arg1->getSymbolName() << "; " << endl;

}

void IRReturn::print() const {
    cout << "return ";
    if (arg1) {
        cout << arg1->getSymbolName();
    }
    cout << ";" << endl;
}

void IRGetReturn::print() const {
    cout << result->getSymbolName() << " = " << " return "
         << ";" << endl;
}

void IRAddI::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t);
    Register *arg2Reg = arg2->load(t);
    Register *resultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    t->addCodeAdd(resultReg, arg1Reg, arg2Reg, FloatPointType::NONE);
    result->storeFrom(t, resultReg);
    arg1Reg->setFree();
    arg2Reg->setFree();
    resultReg->setFree();
}

void IRAddF::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t);
    Register *arg2Reg = arg2->load(t);
    Register *resultReg = t->getNextFreeRegister(false, false, FloatPointType::NONE, hasFreeRegister);
    t->addCodeAdd(resultReg, arg1Reg, arg2Reg, FloatPointType::SINGLE);
    result->storeFrom(t, resultReg);
    arg1Reg->setFree();
    arg2Reg->setFree();
    resultReg->setFree();
}

void IRAddD::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t);
    Register *arg2Reg = arg2->load(t);
    Register *resultReg = t->getNextFreeRegister(false, false, FloatPointType::NONE, hasFreeRegister);
    t->addCodeAdd(resultReg, arg1Reg, arg2Reg, FloatPointType::DOUBLE);
    result->storeFrom(t, resultReg);
    arg1Reg->setFree();
    arg2Reg->setFree();
    resultReg->setFree();
}

void IRSubI::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t);
    Register *arg2Reg = arg2->load(t);
    Register *resultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    t->addCodeSub(resultReg, arg1Reg, arg2Reg, FloatPointType::NONE);
    result->storeFrom(t, resultReg);
    arg1Reg->setFree();
    arg2Reg->setFree();
    resultReg->setFree();
}

void IRSubF::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t);
    Register *arg2Reg = arg2->load(t);
    Register *resultReg = t->getNextFreeRegister(false, false, FloatPointType::NONE, hasFreeRegister);
    t->addCodeSub(resultReg, arg1Reg, arg2Reg, FloatPointType::SINGLE);
    result->storeFrom(t, resultReg);
    arg1Reg->setFree();
    arg2Reg->setFree();
    resultReg->setFree();
}

void IRSubD::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t);
    Register *arg2Reg = arg2->load(t);
    Register *resultReg = t->getNextFreeRegister(false, false, FloatPointType::NONE, hasFreeRegister);
    t->addCodeAdd(resultReg, arg1Reg, arg2Reg, FloatPointType::DOUBLE);
    result->storeFrom(t, resultReg);
    arg1Reg->setFree();
    arg2Reg->setFree();
    resultReg->setFree();
}

void IRNegI::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t);
    Register *resultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    t->addCodeNeg(resultReg, arg1Reg, FloatPointType::NONE);
    result->storeFrom(t, resultReg);
    arg1Reg->setFree();
    resultReg->setFree();
}

void IRNegF::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t);
    Register *resultReg = t->getNextFreeRegister(false, false, FloatPointType::NONE, hasFreeRegister);
    t->addCodeNeg(resultReg, arg1Reg, FloatPointType::SINGLE);
    result->storeFrom(t, resultReg);
    arg1Reg->setFree();
    resultReg->setFree();
}

void IRNegD::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t);
    Register *resultReg = t->getNextFreeRegister(false, false, FloatPointType::NONE, hasFreeRegister);
    t->addCodeNeg(resultReg, arg1Reg, FloatPointType::DOUBLE);
    result->storeFrom(t, resultReg);
    arg1Reg->setFree();
    resultReg->setFree();
}

void IRMulI::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t);
    Register *arg2Reg = arg2->load(t);
    Register *resultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    t->addCodeMul(resultReg, arg1Reg, arg2Reg, FloatPointType::NONE);
    result->storeFrom(t, resultReg);
    arg1Reg->setFree();
    arg2Reg->setFree();
    resultReg->setFree();
}

void IRMulF::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t);
    Register *arg2Reg = arg2->load(t);
    Register *resultReg = t->getNextFreeRegister(false, false, FloatPointType::NONE, hasFreeRegister);
    t->addCodeMul(resultReg, arg1Reg, arg2Reg, FloatPointType::SINGLE);
    result->storeFrom(t, resultReg);
    arg1Reg->setFree();
    arg2Reg->setFree();
    resultReg->setFree();
}

void IRMulD::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t);
    Register *arg2Reg = arg2->load(t);
    Register *resultReg = t->getNextFreeRegister(false, false, FloatPointType::NONE, hasFreeRegister);
    t->addCodeMul(resultReg, arg1Reg, arg2Reg, FloatPointType::DOUBLE);
    result->storeFrom(t, resultReg);
    arg1Reg->setFree();
    arg2Reg->setFree();
    resultReg->setFree();
}

void IRDivI::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t);
    Register *arg2Reg = arg2->load(t);
    Register *resultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    t->addCodeDiv(resultReg, arg1Reg, arg2Reg, FloatPointType::NONE);
    result->storeFrom(t, resultReg);
    arg1Reg->setFree();
    arg2Reg->setFree();
    resultReg->setFree();
}

void IRDivF::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t);
    Register *arg2Reg = arg2->load(t);
    Register *resultReg = t->getNextFreeRegister(false, false, FloatPointType::NONE, hasFreeRegister);
    t->addCodeDiv(resultReg, arg1Reg, arg2Reg, FloatPointType::SINGLE);
    result->storeFrom(t, resultReg);
    arg1Reg->setFree();
    arg2Reg->setFree();
    resultReg->setFree();
}

void IRDivD::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t);
    Register *arg2Reg = arg2->load(t);
    Register *resultReg = t->getNextFreeRegister(false, false, FloatPointType::NONE, hasFreeRegister);
    t->addCodeDiv(resultReg, arg1Reg, arg2Reg, FloatPointType::DOUBLE);
    result->storeFrom(t, resultReg);
    arg1Reg->setFree();
    arg2Reg->setFree();
    resultReg->setFree();
}

void IRMod::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t);
    Register *arg2Reg = arg2->load(t);
    Register *resultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    t->addCodeRem(resultReg, arg1Reg, arg2Reg);
    result->storeFrom(t, resultReg);
    arg1Reg->setFree();
    arg2Reg->setFree();
    resultReg->setFree();
}

void IRNot::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t);
    Register *resultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    t->addCodeNot(resultReg, arg1Reg);
    result->storeFrom(t, resultReg);
    arg1Reg->setFree();
    resultReg->setFree();
}

void IROr::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t);
    Register *arg2Reg = arg2->load(t);
    Register *resultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    t->addCodeOr(resultReg, arg1Reg, arg2Reg);
    result->storeFrom(t, resultReg);
    arg1Reg->setFree();
    arg2Reg->setFree();
    resultReg->setFree();
}

void IRAnd::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t);
    Register *arg2Reg = arg2->load(t);
    Register *resultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    t->addCodeAnd(resultReg, arg1Reg, arg2Reg);
    result->storeFrom(t, resultReg);
    arg1Reg->setFree();
    arg2Reg->setFree();
    resultReg->setFree();
}

void IRSeqB::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t);
    Register *arg2Reg = arg2->load(t);
    Register *tmpResultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    Register *resultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    t->addCodeXor(tmpResultReg, arg1Reg, arg2Reg);
    t->addCodeSeqz(resultReg, tmpResultReg);
    result->storeFrom(t, resultReg);
    arg1Reg->setFree();
    arg2Reg->setFree();
    tmpResultReg->setFree();
    resultReg->setFree();
}


void IRSeqI::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t);
    Register *arg2Reg = arg2->load(t);
    Register *tmpResultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    Register *resultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    t->addCodeXor(tmpResultReg, arg1Reg, arg2Reg);
    t->addCodeSeqz(resultReg, tmpResultReg);
    result->storeFrom(t, resultReg);
    arg1Reg->setFree();
    arg2Reg->setFree();
    tmpResultReg->setFree();
    resultReg->setFree();
}

void IRSeqF::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t);
    Register *arg2Reg = arg2->load(t);
    Register *resultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    t->addCodeFeq(resultReg, arg1Reg, arg2Reg, FloatPointType::SINGLE);
    result->storeFrom(t, resultReg);
    arg1Reg->setFree();
    arg2Reg->setFree();
    resultReg->setFree();
}

void IRSeqD::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t);
    Register *arg2Reg = arg2->load(t);
    Register *resultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    t->addCodeFeq(resultReg, arg1Reg, arg2Reg, FloatPointType::DOUBLE);
    result->storeFrom(t, resultReg);
    arg1Reg->setFree();
    arg2Reg->setFree();
    resultReg->setFree();
}

void IRSneB::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t);
    Register *arg2Reg = arg2->load(t);
    Register *tmpResultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    Register *resultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    t->addCodeXor(tmpResultReg, arg1Reg, arg2Reg);
    t->addCodeSnez(resultReg, tmpResultReg);
    result->storeFrom(t, resultReg);
    arg1Reg->setFree();
    arg2Reg->setFree();
    tmpResultReg->setFree();
    resultReg->setFree();
}

void IRSneI::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t);
    Register *arg2Reg = arg2->load(t);
    Register *tmpResultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    Register *resultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    t->addCodeXor(tmpResultReg, arg1Reg, arg2Reg);
    t->addCodeSnez(resultReg, tmpResultReg);
    result->storeFrom(t, resultReg);
    arg1Reg->setFree();
    arg2Reg->setFree();
    tmpResultReg->setFree();
    resultReg->setFree();
}

void IRSneF::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t);
    Register *arg2Reg = arg2->load(t);
    Register *resultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    t->addCodeFeq(resultReg, arg1Reg, arg2Reg, FloatPointType::SINGLE);
    t->addCodeNot(resultReg, resultReg);
    result->storeFrom(t, resultReg);
    arg1Reg->setFree();
    arg2Reg->setFree();
    resultReg->setFree();
}

void IRSneD::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t);
    Register *arg2Reg = arg2->load(t);
    Register *resultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    t->addCodeFeq(resultReg, arg1Reg, arg2Reg, FloatPointType::DOUBLE);
    t->addCodeNot(resultReg, resultReg);
    result->storeFrom(t, resultReg);
    arg1Reg->setFree();
    arg2Reg->setFree();
    resultReg->setFree();
}

void IRSltI::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t);
    Register *arg2Reg = arg2->load(t);
    Register *resultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    t->addCodeSlt(resultReg, arg1Reg, arg2Reg);
    result->storeFrom(t, resultReg);
    arg1Reg->setFree();
    arg2Reg->setFree();
    resultReg->setFree();
}

void IRSltF::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t);
    Register *arg2Reg = arg2->load(t);
    Register *resultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    t->addCodeFlt(resultReg, arg1Reg, arg2Reg, FloatPointType::SINGLE);
    result->storeFrom(t, resultReg);
    arg1Reg->setFree();
    arg2Reg->setFree();
    resultReg->setFree();
}

void IRSltD::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t);
    Register *arg2Reg = arg2->load(t);
    Register *resultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    t->addCodeFlt(resultReg, arg1Reg, arg2Reg, FloatPointType::DOUBLE);
    result->storeFrom(t, resultReg);
    arg1Reg->setFree();
    arg2Reg->setFree();
    resultReg->setFree();
}

void IRSgtI::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t);
    Register *arg2Reg = arg2->load(t);
    Register *resultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    // reverse
    t->addCodeSlt(resultReg, arg2Reg, arg1Reg);
    result->storeFrom(t, resultReg);
    arg1Reg->setFree();
    arg2Reg->setFree();
    resultReg->setFree();
}

void IRSgtF::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t);
    Register *arg2Reg = arg2->load(t);
    Register *resultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    // reverse
    t->addCodeFlt(resultReg, arg2Reg, arg1Reg, FloatPointType::SINGLE);
    result->storeFrom(t, resultReg);
    arg1Reg->setFree();
    arg2Reg->setFree();
    resultReg->setFree();
}

void IRSgtD::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t);
    Register *arg2Reg = arg2->load(t);
    Register *resultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    // reverse
    t->addCodeFlt(resultReg, arg2Reg, arg1Reg, FloatPointType::DOUBLE);
    result->storeFrom(t, resultReg);
    arg1Reg->setFree();
    arg2Reg->setFree();
    resultReg->setFree();
}

void IRSleqI::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t);
    Register *arg2Reg = arg2->load(t);
    Register *resultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    // reverse
    t->addCodeSlt(resultReg, arg2Reg, arg1Reg);
    // neg
    t->addCodeNot(resultReg, resultReg);
    result->storeFrom(t, resultReg);
    arg1Reg->setFree();
    arg2Reg->setFree();
    resultReg->setFree();
}

void IRSleqF::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t);
    Register *arg2Reg = arg2->load(t);
    Register *resultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    // reverse
    t->addCodeFlt(resultReg, arg1Reg, arg2Reg, FloatPointType::SINGLE);
    result->storeFrom(t, resultReg);
    arg1Reg->setFree();
    arg2Reg->setFree();
    resultReg->setFree();
}

void IRSleqD::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t);
    Register *arg2Reg = arg2->load(t);
    Register *resultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    // reverse
    t->addCodeFlt(resultReg, arg1Reg, arg2Reg, FloatPointType::DOUBLE);
    result->storeFrom(t, resultReg);
    arg1Reg->setFree();
    arg2Reg->setFree();
    resultReg->setFree();
}

void IRSgeqI::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t);
    Register *arg2Reg = arg2->load(t);
    Register *resultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    t->addCodeSlt(resultReg, arg1Reg, arg2Reg);
    // neg
    t->addCodeNot(resultReg, resultReg);
    result->storeFrom(t, resultReg);
    arg1Reg->setFree();
    arg2Reg->setFree();
    resultReg->setFree();
}

void IRSgeqF::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t);
    Register *arg2Reg = arg2->load(t);
    Register *resultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    t->addCodeFlt(resultReg, arg2Reg, arg1Reg, FloatPointType::SINGLE);
    result->storeFrom(t, resultReg);
    arg1Reg->setFree();
    arg2Reg->setFree();
    resultReg->setFree();
}

void IRSgeqD::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t);
    Register *arg2Reg = arg2->load(t);
    Register *resultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    t->addCodeFlt(resultReg, arg1Reg, arg2Reg, FloatPointType::SINGLE);
    result->storeFrom(t, resultReg);
    arg1Reg->setFree();
    arg2Reg->setFree();
    resultReg->setFree();
}

void IRBeqz::genTargetCode(TargetCodes *t) {
    Register *arg1Reg = arg1->load(t);
    std::string label = arg2->getSymbolName();
    t->addCodeBeqz(arg1Reg, label);
    arg1Reg->setFree();
}

void IRGoto::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    std::string label = arg1->getSymbolName();
    Register *labelReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    t->addCodeLla(labelReg, label);
    t->addCodeJr(labelReg);
    labelReg->setFree();
}

void IRAssignB::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *resultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    Register *sp = t->tryGetCertainRegister(true, "sp", hasFreeRegister);
    resultReg->setFree();
    sp->setFree();
}

void IRAssignI::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t);
    result->storeFrom(t, arg1Reg);
    arg1Reg->setFree();
}

void IRAssignF::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t);
    result->storeFrom(t, arg1Reg);
    arg1Reg->setFree();
}

void IRAssignD::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t);
    result->storeFrom(t, arg1Reg);
    arg1Reg->setFree();
}

void IRFetchArrayElemB::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    Register *arg2Reg = arg2->load(t);
    t->addCodeLla(arg1Reg, arg1->getSymbolName());
    t->addCodeSlli(arg2Reg, arg2Reg, 2);
    t->addCodeAdd(arg1Reg, arg1Reg, arg2Reg, FloatPointType::NONE);
    t->addCodeLoad(arg1Reg, arg1Reg, 0, FloatPointType::NONE);
    result->storeFrom(t, arg1Reg);
    arg1Reg->setFree();
    arg2Reg->setFree();
}

void IRFetchArrayElemI::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    Register *arg2Reg = arg2->load(t);
    t->addCodeLla(arg1Reg, arg1->getSymbolName());
    t->addCodeSlli(arg2Reg, arg2Reg, 2);
    t->addCodeAdd(arg1Reg, arg1Reg, arg2Reg, FloatPointType::NONE);
    t->addCodeLoad(arg1Reg, arg1Reg, 0, FloatPointType::NONE);
    result->storeFrom(t, arg1Reg);
    arg1Reg->setFree();
    arg2Reg->setFree();
}

void IRFetchArrayElemF::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    Register *arg2Reg = arg2->load(t);
    t->addCodeLla(arg1Reg, arg1->getSymbolName());
    t->addCodeSlli(arg2Reg, arg2Reg, 2);
    t->addCodeAdd(arg1Reg, arg1Reg, arg2Reg, FloatPointType::NONE);
    t->addCodeLoad(arg1Reg, arg1Reg, 0, FloatPointType::NONE);
    result->storeFrom(t, arg1Reg);
    arg1Reg->setFree();
    arg2Reg->setFree();
}

void IRFetchArrayElemD::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    Register *arg2Reg = arg2->load(t);
    t->addCodeLla(arg1Reg, arg1->getSymbolName());
    t->addCodeSlli(arg2Reg, arg2Reg, 3);
    t->addCodeAdd(arg1Reg, arg1Reg, arg2Reg, FloatPointType::NONE);
    t->addCodeLoad(arg1Reg, arg1Reg, 0, FloatPointType::NONE);
    result->storeFrom(t, arg1Reg);
    arg1Reg->setFree();
    arg2Reg->setFree();
}

void IRAssignArrayElemB::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    Register *arg2Reg = arg2->load(t);
    Register *srcReg = result->load(t);
    t->addCodeLla(arg1Reg, arg1->getSymbolName());
    t->addCodeSlli(arg2Reg, arg2Reg, 2);
    t->addCodeAdd(arg1Reg, arg1Reg, arg2Reg, FloatPointType::NONE);
    t->addCodeStore(arg1Reg, srcReg, 0, FloatPointType::NONE);
    arg1Reg->setFree();
    arg2Reg->setFree();
}

void IRAssignArrayElemI::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    Register *arg2Reg = arg2->load(t);
    Register *srcReg = result->load(t);
    t->addCodeLla(arg1Reg, arg1->getSymbolName());
    t->addCodeSlli(arg2Reg, arg2Reg, 2);
    t->addCodeAdd(arg1Reg, arg1Reg, arg2Reg, FloatPointType::NONE);
    t->addCodeStore(arg1Reg, srcReg, 0, FloatPointType::NONE);
    arg1Reg->setFree();
    arg2Reg->setFree();
}

void IRAssignArrayElemF::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    Register *arg2Reg = arg2->load(t);
    Register *srcReg = result->load(t);
    t->addCodeLla(arg1Reg, arg1->getSymbolName());
    t->addCodeSlli(arg2Reg, arg2Reg, 2);
    t->addCodeAdd(arg1Reg, arg1Reg, arg2Reg, FloatPointType::NONE);
    t->addCodeStore(arg1Reg, srcReg, 0, FloatPointType::NONE);
    arg1Reg->setFree();
    arg2Reg->setFree();
}

void IRAssignArrayElemD::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    Register *arg2Reg = arg2->load(t);
    Register *srcReg = result->load(t);
    t->addCodeLla(arg1Reg, arg1->getSymbolName());
    t->addCodeSlli(arg2Reg, arg2Reg, 3);
    t->addCodeAdd(arg1Reg, arg1Reg, arg2Reg, FloatPointType::NONE);
    t->addCodeStore(arg1Reg, srcReg, 0, FloatPointType::NONE);
    arg1Reg->setFree();
    arg2Reg->setFree();
}

void IRAddLabel::genTargetCode(TargetCodes *t) {
    t->addCodeLabel(arg1->getSymbolName());
}

void IRAddParamB::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = t->getNextFreeRegister(true, true, FloatPointType::NONE, hasFreeRegister);
    arg1->loadTo(t, arg1Reg);
}

void IRAddParamI::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = t->getNextFreeRegister(true, true, FloatPointType::NONE, hasFreeRegister);
    arg1->loadTo(t, arg1Reg);
}

void IRAddParamF::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = t->getNextFreeRegister(false, true, FloatPointType::SINGLE, hasFreeRegister);
    arg1->loadTo(t, arg1Reg);
}

void IRAddParamD::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = t->getNextFreeRegister(false, true, FloatPointType::DOUBLE, hasFreeRegister);
    arg1->loadTo(t, arg1Reg);
}

void IRAddParamA::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = t->getNextFreeRegister(true, true, FloatPointType::NONE, hasFreeRegister);
    t->addCodeLla(arg1Reg, arg1->getSymbolName());
}

void IRGetParamB::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *resultArg = t->tryGetCertainRegister(true, "a" + arg1->getValue(), hasFreeRegister);
    result->storeFrom(t, resultArg);
    resultArg->setFree();
}

void IRGetParamI::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *resultArg = t->tryGetCertainRegister(true, "a" + arg1->getValue(), hasFreeRegister);
    result->storeFrom(t, resultArg);
    resultArg->setFree();
}

void IRGetParamF::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *resultArg = t->tryGetCertainRegister(true, "fa" + arg1->getValue(), hasFreeRegister);
    result->storeFrom(t, resultArg);
    resultArg->setFree();
}

void IRGetParamD::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *resultArg = t->tryGetCertainRegister(true, "fa" + arg1->getValue(), hasFreeRegister);
    result->storeFrom(t, resultArg);
    resultArg->setFree();
}

void IRGetParamA::genTargetCode(TargetCodes *t) {
    bool hasOccupiedRegister;
    Register *resultArg = t->getNextOccupiedRegister(true, FloatPointType::NONE, hasOccupiedRegister);
    arg1->storeFrom(t, resultArg);
    resultArg->setFree();
}

void IRCall::genTargetCode(TargetCodes *t) {
    t->addCodeCall(arg1->getSymbolName());
}

void IRReturn::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *sp = t->tryGetCertainRegister(true, "sp", hasFreeRegister);
    Register *ra = t->tryGetCertainRegister(true, "ra", hasFreeRegister);
    t->addCodeLoad(ra, sp, -8, FloatPointType::NONE);
    t->addCodeRet();
    sp->setFree();
}

void IRReturnB::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *retReg = t->tryGetCertainRegister(true, "a0", hasFreeRegister);
    arg1->loadTo(t, retReg);
    IRReturn::genTargetCode(t);
}

void IRReturnI::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *retReg = t->tryGetCertainRegister(true, "a0", hasFreeRegister);
    arg1->loadTo(t, retReg);
    IRReturn::genTargetCode(t);
}

void IRReturnF::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *retReg = t->tryGetCertainRegister(false, "fa0", hasFreeRegister);
    arg1->loadTo(t, retReg);
    IRReturn::genTargetCode(t);
}

void IRReturnD::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *retReg = t->tryGetCertainRegister(false, "fa0", hasFreeRegister);
    arg1->loadTo(t, retReg);
    IRReturn::genTargetCode(t);
}

void IRGetReturnI::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *retReg = t->tryGetCertainRegister(true, "a0", hasFreeRegister);
    arg1->storeFrom(t, retReg);
}

void IRGetReturnF::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *retReg = t->tryGetCertainRegister(false, "fa0", hasFreeRegister);
    arg1->storeFrom(t, retReg);
}

void IRGetReturnD::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *retReg = t->tryGetCertainRegister(false, "fa0", hasFreeRegister);
    arg1->storeFrom(t, retReg);
}
