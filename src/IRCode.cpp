#include <iostream>
#include <utility>

#include "IRCode.h"

using namespace std;

IRCode::IRCode() {
    operation = IROperation::ADD_PARAM;
    result = nullptr;
    arg1 = nullptr;
    arg2 = nullptr;
    use.clear();
    //loop.clear();
}

bool IRCode::setArg1(IROperand *arg){
    arg1 = arg;
    return true;
}

bool IRCode::setArg2(IROperand *arg){
    arg2 = arg;
    return true;
}

bool IRCode::setResult(IROperand *res){
    result = res;
    return true;
}

bool IRCode::isTwoArgAssignmentOperation(IROperation inOperation) {
    switch(inOperation) {
        case IROperation::ADD:
        case IROperation::SUB:
        case IROperation::MUL:
        case IROperation::DIV:
        case IROperation::MOD:
        case IROperation::OR:
        case IROperation::AND:
        case IROperation::SEQ:
        case IROperation::SNE:
        case IROperation::SLT:
        case IROperation::SGT:
        case IROperation::SLEQ:
        case IROperation::SGEQ:
            return true;
            break;
        default:
            return false;
    }
}

bool IRCode::isOrderIndependentOperation(IROperation inOperation) {
    switch(inOperation) {
        case IROperation::ADD:
        case IROperation::MUL:
        case IROperation::OR:
        case IROperation::AND:
        case IROperation::SEQ:
        case IROperation::SNE:
            return true;
            break;
        default:
            return false;
    }
}

bool IRCode::isAssignmentOperation(IROperation inOperation) {
    switch(inOperation) {
        case IROperation::BEQZ:
        case IROperation::GOTO:
        case IROperation::REPLACE:
        case IROperation::FETCH_ARRAY_ELEM:
        case IROperation::ASSIGN_ARRAY_ELEM:
        case IROperation::ADD_LABEL:
        case IROperation::ADD_PARAM:
        case IROperation::GET_PARAM:
        case IROperation::CALL:
        case IROperation::RETURN:
        case IROperation::GET_RETURN:
            return false;
            break;
        default:
            return true;
    }
}

IRCode::IRCode(IROperation newOp, IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : operation(newOp), result(newResult), arg1(newArg1), arg2(newArg2) {}

IRAdd::IRAdd(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRCode(IROperation::ADD, newResult, newArg1, newArg2) {}

IRAddI::IRAddI(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRAdd(newResult, newArg1, newArg2) {}

IRAddF::IRAddF(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRAdd(newResult, newArg1, newArg2) {}

IRSub::IRSub(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRCode(IROperation::SUB, newResult, newArg1, newArg2) {}

IRSubI::IRSubI(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRSub(newResult, newArg1, newArg2) {}

IRSubF::IRSubF(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRSub(newResult, newArg1, newArg2) {}

IRNeg::IRNeg(IROperand *newResult, IROperand *newArg1)
        : IRCode(IROperation::NEG, newResult, newArg1, nullptr) {}

IRNegI::IRNegI(IROperand *newResult, IROperand *newArg1)
        : IRNeg(newResult, newArg1) {}

IRNegF::IRNegF(IROperand *newResult, IROperand *newArg1)
        : IRNeg(newResult, newArg1) {}

IRMul::IRMul(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRCode(IROperation::MUL, newResult, newArg1, newArg2) {}

IRMulI::IRMulI(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRMul(newResult, newArg1, newArg2) {}

IRMulF::IRMulF(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRMul(newResult, newArg1, newArg2) {}

IRDiv::IRDiv(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRCode(IROperation::DIV, newResult, newArg1, newArg2) {}

IRDivI::IRDivI(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRDiv(newResult, newArg1, newArg2) {}

IRDivF::IRDivF(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRDiv(newResult, newArg1, newArg2) {}

IRMod::IRMod(IROperand *newResult, IROperand *newArg1, IROperand *newArg2, IROperand *newCurFunc)
        : IRCode(IROperation::DIV, newResult, newArg1, newArg2) {
    curFunc = newCurFunc;
}

IRNot::IRNot(IROperand *newResult, IROperand *newArg1)
        : IRCode(IROperation::DIV, newResult, newArg1, nullptr) {}

IROr::IROr(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRCode(IROperation::OR, newResult, newArg1, newArg2) {}

IRAnd::IRAnd(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRCode(IROperation::AND, newResult, newArg1, newArg2) {}

IRSeq::IRSeq(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRCode(IROperation::SEQ, newResult, newArg1, newArg2) {}

IRSeqI::IRSeqI(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRSeq(newResult, newArg1, newArg2) {}

IRSeqF::IRSeqF(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRSeq(newResult, newArg1, newArg2) {}

IRSne::IRSne(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRCode(IROperation::SNE, newResult,
                 newArg1, newArg2) {}

IRSneI::IRSneI(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRSne(newResult, newArg1, newArg2) {}

IRSneF::IRSneF(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRSne(newResult, newArg1, newArg2) {}

IRSlt::IRSlt(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRCode(IROperation::SLT, newResult, newArg1, newArg2) {}

IRSltI::IRSltI(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRSlt(newResult, newArg1, newArg2) {}

IRSltF::IRSltF(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRSlt(newResult, newArg1, newArg2) {}

IRSgt::IRSgt(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRCode(IROperation::SGT, newResult, newArg1, newArg2) {}

IRSgtI::IRSgtI(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRSgt(newResult, newArg1, newArg2) {}

IRSgtF::IRSgtF(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRSgt(newResult, newArg1, newArg2) {}

IRSleq::IRSleq(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRCode(IROperation::SLEQ, newResult, newArg1, newArg2) {}

IRSleqI::IRSleqI(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRSleq(newResult, newArg1, newArg2) {}

IRSleqF::IRSleqF(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRSleq(newResult, newArg1, newArg2) {}

IRSgeq::IRSgeq(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRCode(IROperation::SGEQ, newResult, newArg1, newArg2) {}

IRSgeqI::IRSgeqI(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRSgeq(newResult, newArg1, newArg2) {}

IRSgeqF::IRSgeqF(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRSgeq(newResult, newArg1, newArg2) {}

IRBeqz::IRBeqz(IROperand *newArg1, IROperand *newLabel)
        : IRCode(IROperation::BEQZ, nullptr, newArg1, newLabel) {}

IRGoto::IRGoto(IROperand *newLabel)
        : IRCode(IROperation::GOTO, nullptr, newLabel, nullptr) {}

IRPhi::IRPhi(IROperand *newResult, std::vector<IROperand *>newArg1)
        : IRCode(IROperation::PHI, newResult, nullptr, nullptr) {
    args = std::move(newArg1);
}

IRReplace::IRReplace(IROperand *newResult, IROperand *newArg1)
        : IRCode(IROperation::REPLACE, newResult, newArg1, nullptr) {}

IRAssign::IRAssign(IROperand *newResult, IROperand *newArg1)
        : IRCode(IROperation::ASSIGN, newResult, newArg1, nullptr) {}

IRAssignI::IRAssignI(IROperand *newResult, IROperand *newArg1)
        : IRAssign(newResult, newArg1) {}

IRAssignF::IRAssignF(IROperand *newResult, IROperand *newArg1)
        : IRAssign(newResult, newArg1) {}

IRFetchArrayElem::IRFetchArrayElem(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRCode(IROperation::FETCH_ARRAY_ELEM, newResult, newArg1, newArg2) {}

IRFetchArrayElemI::IRFetchArrayElemI(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRFetchArrayElem(newResult, newArg1, newArg2) {}

IRFetchArrayElemF::IRFetchArrayElemF(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRFetchArrayElem(newResult, newArg1, newArg2) {}

IRAssignArrayElem::IRAssignArrayElem(IROperand *newSource, IROperand *newArg1, IROperand *newArg2)
        : IRCode(IROperation::ASSIGN_ARRAY_ELEM, newSource, newArg1, newArg2) {}

IRAssignArrayElemI::IRAssignArrayElemI(IROperand *newSource, IROperand *newArg1, IROperand *newArg2)
        : IRAssignArrayElem(newSource, newArg1, newArg2) {}

IRAssignArrayElemF::IRAssignArrayElemF(IROperand *newSource, IROperand *newArg1, IROperand *newArg2)
        : IRAssignArrayElem(newSource, newArg1, newArg2) {}

IRAddLabel::IRAddLabel(IROperand *newArg1)
        : IRCode(IROperation::ADD_LABEL, nullptr, newArg1, nullptr) {}

IRAddParam::IRAddParam(IROperand *newArg1)
        : IRCode(IROperation::ADD_PARAM, nullptr, newArg1, nullptr) {}

IRAddParamI::IRAddParamI(IROperand *newArg1)
        : IRAddParam(newArg1) {}

IRAddParamF::IRAddParamF(IROperand *newArg1)
        : IRAddParam(newArg1) {}

IRAddParamA::IRAddParamA(IROperand *newArg1) : IRAddParam(newArg1) {}

IRGetParam::IRGetParam(IROperand *newResult, IROperand *newArg1)
        : IRCode(IROperation::GET_PARAM, newResult, newArg1, nullptr) {}

IRGetParamI::IRGetParamI(IROperand *newResult, IROperand *newArg1)
        : IRGetParam(newResult, newArg1) {}

IRGetParamF::IRGetParamF(IROperand *newResult, IROperand *newArg1)
        : IRGetParam(newResult, newArg1) {}

IRGetParamA::IRGetParamA(IROperand *newResult, IROperand *newArg1)
        : IRGetParam(newResult, newArg1) {}

IRCall::IRCall(IROperand *newArg1, IROperand *newArg2)
        : IRCode(IROperation::CALL, nullptr, newArg1, newArg2) {}

IRReturn::IRReturn(IROperand *newArg1, IROperand *newArg2)
        : IRCode(IROperation::RETURN, nullptr, newArg1, newArg2) {}

IRReturnV::IRReturnV(IROperand *newArg2)
        : IRReturn(nullptr, newArg2) {}

IRReturnI::IRReturnI(IROperand *newArg1, IROperand *newArg2)
        : IRReturn(newArg1, newArg2) {}

IRReturnF::IRReturnF(IROperand *newArg1, IROperand *newArg2)
        : IRReturn(newArg1, newArg2) {}

IRGetReturn::IRGetReturn(IROperand *newResult)
        : IRCode(IROperation::GET_RETURN, newResult, nullptr, nullptr) {}

IRGetReturnI::IRGetReturnI(IROperand *newResult)
        : IRGetReturn(newResult) {}

IRGetReturnF::IRGetReturnF(IROperand *newResult)
        : IRGetReturn(newResult) {}

void IRAdd::print() const {
    cout << "\t" << result->getVal() << " = "
         << arg1->getVal() << " + "
         << arg2->getVal() << ";" << endl;
}

void IRSub::print() const {
    cout << "\t" << result->getVal() << " = "
         << arg1->getVal() << " - "
         << arg2->getVal() << ";" << endl;
}

void IRNeg::print() const {
    cout << "\t" << result->getVal() << " = "
         << " - "
         << arg1->getVal() << ";" << endl;
}

void IRMul::print() const {
    cout << "\t" << result->getVal() << " = "
         << arg1->getVal() << " * "
         << arg2->getVal() << ";" << endl;
}

void IRDiv::print() const {
    cout << "\t" << result->getVal() << " = "
         << arg1->getVal() << " / "
         << arg2->getVal() << ";" << endl;
}

void IRMod::print() const {
    cout << "\t" << result->getVal() << " = "
         << arg1->getVal() << " % "
         << arg2->getVal() << ";" << endl;
}

void IRNot::print() const {
    cout << "\t" << result->getVal() << " = not"
         << arg1->getVal() << ";" << endl;
}

void IROr::print() const {
    cout << "\t" << result->getVal() << " = "
         << arg1->getVal() << " || " << arg2->getVal() << ";" << endl;
}

void IRAnd::print() const {
    cout << "\t" << result->getVal() << " = "
         << arg1->getVal() << " && " << arg2->getVal() << ";" << endl;
}

void IRSeq::print() const {
    cout << "\t" << result->getVal() << " = "
         << arg1->getVal() << " == " << arg2->getVal() << ";" << endl;
}

void IRSne::print() const {
    cout << "\t" << result->getVal() << " = "
         << arg1->getVal() << " != " << arg2->getVal() << ";" << endl;
}

void IRSlt::print() const {
    cout << "\t" << result->getVal() << " = "
         << arg1->getVal() << " < " << arg2->getVal() << ";" << endl;
}

void IRSgt::print() const {
    cout << "\t" << result->getVal() << " = "
         << arg1->getVal() << " > " << arg2->getVal() << ";" << endl;
}

void IRSleq::print() const {
    cout << "\t" << result->getVal() << " = "
         << arg1->getVal() << " <= " << arg2->getVal() << ";" << endl;
}

void IRSgeq::print() const {
    cout << "\t" << result->getVal() << " = "
         << arg1->getVal() << " >= " << arg2->getVal() << ";" << endl;
}

void IRBeqz::print() const {
    cout << "\t" << "beqz "
         << arg1->getVal() << " "
         << arg2->getVal() << ";" << endl;
}

void IRGoto::print() const {
    cout << "\t" << "goto " << arg1->getVal() << ";" << endl;
}

void IRPhi::print() const {
    cout << "\t" << result->getVal() << " = phi ";
    for (auto i : vector<IROperand *>(args.begin(), prev(args.end()))) {
        cout << i->getVal() <<  ", ";
    }
    cout << args.back()->getVal() << ";";
    cout << endl;
}

void IRReplace::print() const {
    cout << "\t" << result->getVal() << " <= "
         << arg1->getVal() << ";" << endl;
}

void IRAssign::print() const {
    cout << "\t" << result->getVal() << " = "
         << arg1->getVal() << ";" << endl;
}

void IRFetchArrayElem::print() const {
    cout << "\t" << result->getVal() << " = "
         << arg1->getVal() << "["
         << arg2->getVal() << "];" << endl;
}

void IRAssignArrayElem::print() const {
    cout << "\t" << arg1->getVal() << "["
         << arg2->getVal() << "] = "
         << result->getVal() << ";" << endl;
}

void IRAddLabel::print() const {
    cout << arg1->getVal() << ":" << endl;
}

void IRAddParam::print() const {
    cout << "\t" << "addparam " << arg1->getVal() << ";" << endl;
}

void IRGetParam::print() const {
    cout << "\t" << result->getVal() << " = " << " param " << arg1->getValue()
         << ";" << endl;
}

void IRCall::print() const {
    cout << "\t" << "call "
         << arg1->getVal() <<  "; " << endl;

}

void IRReturn::print() const {
    cout << "\t" << "return ";
    if (arg1) {
        if (arg1->getOperandType() == OperandType::VALUE) {
            cout << arg1->getValue();
        }
        else {
            cout << arg1->getSymbolName();
        }
    }
    cout << ";" << endl;
}

void IRGetReturn::print() const {
    cout << "\t" << result->getVal() << " = " << " return "
         << ";" << endl;
}

void IRAddI::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *resultReg;
    if (result->getBindRegister()) {
        resultReg = result->getTargetBindRegister();
    }
    else {
        resultReg = t->getNextFreeRegister(true, false, hasFreeRegister);
    }
    if (arg1->getOperandType() == OperandType::VALUE && arg2->getOperandType() != OperandType::VALUE) {
        Register *arg2Reg = arg2->load(t, true);
        if (stoi(arg1->getValue()) > 2048 || stoi(arg1->getValue()) < -2048) {
            t->addCodeLdr(resultReg, stoi(arg1->getValue()));
        }
        else {
            t->addCodeAdd(resultReg, arg2Reg, stoi(arg1->getValue()));
        }
        t->setRegisterFree(arg2Reg);
    }
    else if (arg1->getOperandType() != OperandType::VALUE && arg2->getOperandType() == OperandType::VALUE) {
        Register *arg1Reg = arg1->load(t, true);
        int val = stoi(arg2->getValue());
        if (val > 2048 || val < -2048) {
            t->addCodeLdr(resultReg, val);
        }
        else {
            t->addCodeAdd(resultReg, arg1Reg, val);
        }
        t->setRegisterFree(arg1Reg);
    }
    else if (arg1->getOperandType() == OperandType::VALUE && arg2->getOperandType() == OperandType::VALUE) {
        Register *zero = t->getNextFreeRegister(true, false, hasFreeRegister);
        t->addCodeEor(zero, zero, zero);
        int val = stoi(arg2->getValue()) + stoi(arg2->getValue());
        if (val > 2048 || val < -2048) {
            t->addCodeLdr(resultReg, stoi(arg1->getValue()));
        }
        else {
            t->addCodeAdd(resultReg, zero, val);
        }
        t->setRegisterFree(zero);
    }
    else {
        Register *arg1Reg = arg1->load(t, true);
        Register *arg2Reg = arg2->load(t, true);
        t->addCodeAdd(resultReg, arg1Reg, arg2Reg);
        t->setRegisterFree(arg1Reg);
        t->setRegisterFree(arg2Reg);
    }
    result->storeFrom(t, resultReg);
    t->setRegisterFree(resultReg);
}

void IRAddF::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t, false);
    Register *arg2Reg = arg2->load(t, false);
    Register *resultReg;
    if (result->getBindRegister()) {
        resultReg = result->getTargetBindRegister();
    }
    else {
        resultReg = t->getNextFreeRegister(false, false, hasFreeRegister);
    }
    t->addCodeAdd(resultReg, arg1Reg, arg2Reg);
    result->storeFrom(t, resultReg);
    t->setRegisterFree(arg1Reg);
    t->setRegisterFree(arg2Reg);
    t->setRegisterFree(resultReg);
}


void IRSubI::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t, true);
    Register *arg2Reg = arg2->load(t, true);
    Register *resultReg;
    if (result->getBindRegister()) {
        resultReg = result->getTargetBindRegister();
    }
    else {
        resultReg = t->getNextFreeRegister(true, false, hasFreeRegister);
    }
    t->addCodeSub(resultReg, arg1Reg, arg2Reg);
    result->storeFrom(t, resultReg);
    t->setRegisterFree(arg1Reg);
    t->setRegisterFree(arg2Reg);
    t->setRegisterFree(resultReg);
}

void IRSubF::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t, false);
    Register *arg2Reg = arg2->load(t, false);
    Register *resultReg;
    if (result->getBindRegister()) {
        resultReg = result->getTargetBindRegister();
    }
    else {
        resultReg = t->getNextFreeRegister(false, false, hasFreeRegister);
    }
    t->addCodeSub(resultReg, arg1Reg, arg2Reg);
    result->storeFrom(t, resultReg);
    t->setRegisterFree(arg1Reg);
    t->setRegisterFree(arg2Reg);
    t->setRegisterFree(resultReg);
}

void IRNegI::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t, true);
    Register *resultReg;
    if (result->getBindRegister()) {
        resultReg = result->getTargetBindRegister();
    }
    else {
        resultReg = t->getNextFreeRegister(true, false, hasFreeRegister);
    }
    t->addCodeSub(resultReg, arg1Reg, 0, true);
    result->storeFrom(t, resultReg);
    t->setRegisterFree(arg1Reg);
    t->setRegisterFree(resultReg);
}

void IRNegF::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t, false);
    Register *resultReg;
    if (result->getBindRegister()) {
        resultReg = result->getTargetBindRegister();
    }
    else {
        resultReg = t->getNextFreeRegister(false, false, hasFreeRegister);
    }
    t->addCodeSub(resultReg, arg1Reg, 0, true);
    result->storeFrom(t, resultReg);
    t->setRegisterFree(arg1Reg);
    t->setRegisterFree(resultReg);
}

void IRMulI::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t, true);
    Register *arg2Reg = arg2->load(t, true);
    Register *resultReg;
    if (result->getBindRegister()) {
        resultReg = result->getTargetBindRegister();
    }
    else {
        resultReg = t->getNextFreeRegister(true, false, hasFreeRegister);
    }
    t->addCodeMul(resultReg, arg1Reg, arg2Reg);
    result->storeFrom(t, resultReg);
    t->setRegisterFree(arg1Reg);
    t->setRegisterFree(arg2Reg);
    t->setRegisterFree(resultReg);
}

void IRMulF::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t, false);
    Register *arg2Reg = arg2->load(t, false);
    Register *resultReg;
    if (result->getBindRegister()) {
        resultReg = result->getTargetBindRegister();
    }
    else {
        resultReg = t->getNextFreeRegister(false, false, hasFreeRegister);
    }
    t->addCodeMul(resultReg, arg1Reg, arg2Reg);
    result->storeFrom(t, resultReg);
    t->setRegisterFree(arg1Reg);
    t->setRegisterFree(arg2Reg);
    t->setRegisterFree(resultReg);
}

void IRDivI::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t, true);
    Register *arg2Reg = arg2->load(t, true);
    Register *resultReg;
    if (result->getBindRegister()) {
        resultReg = result->getTargetBindRegister();
    }
    else {
        resultReg = t->getNextFreeRegister(true, false, hasFreeRegister);
    }
    t->addCodeDiv(resultReg, arg1Reg, arg2Reg);
    result->storeFrom(t, resultReg);
    t->setRegisterFree(arg1Reg);
    t->setRegisterFree(arg2Reg);
    t->setRegisterFree(resultReg);
}

void IRDivF::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t, false);
    Register *arg2Reg = arg2->load(t, false);
    Register *resultReg;
    if (result->getBindRegister()) {
        resultReg = result->getTargetBindRegister();
    }
    else {
        resultReg = t->getNextFreeRegister(false, false, hasFreeRegister);
    }
    t->addCodeDiv(resultReg, arg1Reg, arg2Reg);
    result->storeFrom(t, resultReg);
    t->setRegisterFree(arg1Reg);
    t->setRegisterFree(arg2Reg);
    t->setRegisterFree(resultReg);
}

void IRMod::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->loadTo(t, "a1", true);
    Register *arg2Reg = arg2->loadTo(t, "a2", true);
    Register *resultReg;
    if (result->getBindRegister()) {
        resultReg = result->getTargetBindRegister();
    }
    else {
        resultReg = t->getNextFreeRegister(true, false, hasFreeRegister);
    }
    Register *sp = t->tryGetCertainRegister(true, "sp", hasFreeRegister);
    t->addCodeSub(sp, sp, curFunc->getFrameSize());
    t->addCodeBl("__aeabi_idivmod");
    t->addCodeMv(resultReg, arg1Reg);
    result->storeFrom(t, resultReg);
    t->setRegisterFree(arg1Reg);
    t->setRegisterFree(arg2Reg);
    t->setRegisterFree(resultReg);
    t->setRegisterFree(sp);
}

void IRNot::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t, true);
    Register *resultReg;
    if (result->getBindRegister()) {
        resultReg = result->getTargetBindRegister();
    }
    else {
        resultReg = t->getNextFreeRegister(true, false, hasFreeRegister);
    }
    t->addCodeEor(resultReg, arg1Reg, 1);
    result->storeFrom(t, resultReg);
    t->setRegisterFree(arg1Reg);
    t->setRegisterFree(resultReg);
}

void IROr::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t, true);
    Register *arg2Reg = arg2->load(t, true);
    Register *resultReg;
    if (result->getBindRegister()) {
        resultReg = result->getTargetBindRegister();
    }
    else {
        resultReg = t->getNextFreeRegister(true, false, hasFreeRegister);
    }
    t->addCodeOrr(resultReg, arg1Reg, arg2Reg);
    result->storeFrom(t, resultReg);
    t->setRegisterFree(arg1Reg);
    t->setRegisterFree(arg2Reg);
    t->setRegisterFree(resultReg);
}

void IRAnd::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t, true);
    Register *arg2Reg = arg2->load(t, true);
    Register *resultReg;
    if (result->getBindRegister()) {
        resultReg = result->getTargetBindRegister();
    }
    else {
        resultReg = t->getNextFreeRegister(true, false, hasFreeRegister);
    }
    t->addCodeAnd(resultReg, arg1Reg, arg2Reg);
    result->storeFrom(t, resultReg);
    t->setRegisterFree(arg1Reg);
    t->setRegisterFree(arg2Reg);
    t->setRegisterFree(resultReg);
}

void IRSeqI::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t, true);
    Register *arg2Reg = arg2->load(t, true);
    Register *resultReg;
    if (result->getBindRegister()) {
        resultReg = result->getTargetBindRegister();
    }
    else {
        resultReg = t->getNextFreeRegister(true, false, hasFreeRegister);
    }
    t->addCodeCmp( arg1Reg, arg2Reg);
    t->addCodeLdr(resultReg, 1, Cond::EQ);
    t->addCodeLdr(resultReg, 0, Cond::NE);
    result->storeFrom(t, resultReg);
    t->setRegisterFree(arg1Reg);
    t->setRegisterFree(arg2Reg);
    t->setRegisterFree(resultReg);
}

void IRSeqF::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t, true);
    Register *arg2Reg = arg2->load(t, true);
    Register *resultReg;
    if (result->getBindRegister()) {
        resultReg = result->getTargetBindRegister();
    }
    else {
        resultReg = t->getNextFreeRegister(true, false, hasFreeRegister);
    }
    t->addCodeCmp(arg1Reg, arg2Reg);
    t->addCodeLdr(resultReg, 1, Cond::EQ);
    t->addCodeLdr(resultReg, 0, Cond::NE);
    result->storeFrom(t, resultReg);
    t->setRegisterFree(arg1Reg);
    t->setRegisterFree(arg2Reg);
    t->setRegisterFree(resultReg);
}

void IRSneI::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t, true);
    Register *arg2Reg = arg2->load(t, true);
    Register *resultReg;
    if (result->getBindRegister()) {
        resultReg = result->getTargetBindRegister();
    }
    else {
        resultReg = t->getNextFreeRegister(true, false, hasFreeRegister);
    }
    t->addCodeCmp(arg1Reg, arg2Reg);
    t->addCodeLdr(resultReg, 1, Cond::NE);
    t->addCodeLdr(resultReg, 0, Cond::EQ);
    result->storeFrom(t, resultReg);
    t->setRegisterFree(arg1Reg);
    t->setRegisterFree(arg2Reg);
    t->setRegisterFree(resultReg);
}

void IRSneF::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t, true);
    Register *arg2Reg = arg2->load(t, true);
    Register *resultReg;
    if (result->getBindRegister()) {
        resultReg = result->getTargetBindRegister();
    }
    else {
        resultReg = t->getNextFreeRegister(true, false, hasFreeRegister);
    }
    t->addCodeCmp(arg1Reg, arg2Reg);
    t->addCodeLdr(resultReg, 1, Cond::NE);
    t->addCodeLdr(resultReg, 0, Cond::EQ);
    result->storeFrom(t, resultReg);
    t->setRegisterFree(arg1Reg);
    t->setRegisterFree(arg2Reg);
    t->setRegisterFree(resultReg);
}

void IRSltI::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t, true);
    Register *arg2Reg = arg2->load(t, true);
    Register *resultReg;
    if (result->getBindRegister()) {
        resultReg = result->getTargetBindRegister();
    }
    else {
        resultReg = t->getNextFreeRegister(true, false, hasFreeRegister);
    }
    t->addCodeCmp(arg1Reg, arg2Reg);
    t->addCodeLdr(resultReg, 1, Cond::LT);
    t->addCodeLdr(resultReg, 0, Cond::GE);
    result->storeFrom(t, resultReg);
    t->setRegisterFree(arg1Reg);
    t->setRegisterFree(arg2Reg);
    t->setRegisterFree(resultReg);
}

void IRSltF::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t, true);
    Register *arg2Reg = arg2->load(t, true);
    Register *resultReg;
    if (result->getBindRegister()) {
        resultReg = result->getTargetBindRegister();
    }
    else {
        resultReg = t->getNextFreeRegister(true, false, hasFreeRegister);
    }
    t->addCodeCmp(arg1Reg, arg2Reg);
    t->addCodeLdr(resultReg, 1, Cond::LT);
    t->addCodeLdr(resultReg, 0, Cond::GE);
    result->storeFrom(t, resultReg);
    t->setRegisterFree(arg1Reg);
    t->setRegisterFree(arg2Reg);
    t->setRegisterFree(resultReg);
}

void IRSgtI::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t, true);
    Register *arg2Reg = arg2->load(t, true);
    Register *resultReg;
    if (result->getBindRegister()) {
        resultReg = result->getTargetBindRegister();
    }
    else {
        resultReg = t->getNextFreeRegister(true, false, hasFreeRegister);
    }
    // reverse
    t->addCodeCmp(arg1Reg, arg2Reg);
    t->addCodeLdr(resultReg, 1, Cond::GT);
    t->addCodeLdr(resultReg, 0, Cond::LE);
    result->storeFrom(t, resultReg);
    t->setRegisterFree(arg1Reg);
    t->setRegisterFree(arg2Reg);
    t->setRegisterFree(resultReg);
}

void IRSgtF::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t, true);
    Register *arg2Reg = arg2->load(t, true);
    Register *resultReg;
    if (result->getBindRegister()) {
        resultReg = result->getTargetBindRegister();
    }
    else {
        resultReg = t->getNextFreeRegister(true, false, hasFreeRegister);
    }
    // reverse
    t->addCodeCmp(arg1Reg, arg2Reg);
    t->addCodeLdr(resultReg, 1, Cond::GT);
    t->addCodeLdr(resultReg, 0, Cond::LE);
    result->storeFrom(t, resultReg);
    t->setRegisterFree(arg1Reg);
    t->setRegisterFree(arg2Reg);
    t->setRegisterFree(resultReg);
}

void IRSleqI::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t, true);
    Register *arg2Reg = arg2->load(t, true);
    Register *resultReg;
    if (result->getBindRegister()) {
        resultReg = result->getTargetBindRegister();
    }
    else {
        resultReg = t->getNextFreeRegister(true, false, hasFreeRegister);
    }
    t->addCodeCmp(arg1Reg, arg2Reg);
    t->addCodeLdr(resultReg, 1, Cond::LE);
    t->addCodeLdr(resultReg, 0, Cond::GT);
    result->storeFrom(t, resultReg);
    t->setRegisterFree(arg1Reg);
    t->setRegisterFree(arg2Reg);
    t->setRegisterFree(resultReg);
}

void IRSleqF::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t, true);
    Register *arg2Reg = arg2->load(t, true);
    Register *resultReg;
    if (result->getBindRegister()) {
        resultReg = result->getTargetBindRegister();
    }
    else {
        resultReg = t->getNextFreeRegister(true, false, hasFreeRegister);
    }
    t->addCodeCmp(arg1Reg, arg2Reg);
    t->addCodeLdr(resultReg, 1, Cond::LE);
    t->addCodeLdr(resultReg, 0, Cond::GT);
    result->storeFrom(t, resultReg);
    t->setRegisterFree(arg1Reg);
    t->setRegisterFree(arg2Reg);
    t->setRegisterFree(resultReg);
}

void IRSgeqI::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t, true);
    Register *arg2Reg = arg2->load(t, true);
    Register *resultReg;
    if (result->getBindRegister()) {
        resultReg = result->getTargetBindRegister();
    }
    else {
        resultReg = t->getNextFreeRegister(true, false, hasFreeRegister);
    }
    t->addCodeCmp(arg1Reg, arg2Reg);
    t->addCodeLdr(resultReg, 1, Cond::GE);
    t->addCodeLdr(resultReg, 0, Cond::LT);
    result->storeFrom(t, resultReg);
    t->setRegisterFree(arg1Reg);
    t->setRegisterFree(arg2Reg);
    t->setRegisterFree(resultReg);
}

void IRSgeqF::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t, true);
    Register *arg2Reg = arg2->load(t, true);
    Register *resultReg;
    if (result->getBindRegister()) {
        resultReg = result->getTargetBindRegister();
    }
    else {
        resultReg = t->getNextFreeRegister(true, false, hasFreeRegister);
    }
    t->addCodeCmp(arg1Reg, arg2Reg);
    t->addCodeLdr(resultReg, 1, Cond::GE);
    t->addCodeLdr(resultReg, 0, Cond::LT);
    result->storeFrom(t, resultReg);
    t->setRegisterFree(arg1Reg);
    t->setRegisterFree(arg2Reg);
    t->setRegisterFree(resultReg);
}

void IRBeqz::genTargetCode(TargetCodes *t) {
    Register *arg1Reg = arg1->load(t, true);
    string label = arg2->getSymbolName();
    t->addCodeCmp(arg1Reg, 0);
    t->addCodeBeq(label);
    t->setRegisterFree(arg1Reg);
}

void IRGoto::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    string label = arg1->getSymbolName();
    t->addCodeB(label);
}

void IRReplace::genTargetCode(TargetCodes *t) {
    // do nothing
}

void IRAssignI::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    if (result->getIsArray()) {
        Register *tmpr = t->getNextFreeRegister(true, false, hasFreeRegister);
        t->addCodeAdr(tmpr, arg1->getValueLabel());
        Register *arg1Reg = t->getNextFreeRegister(true, false, hasFreeRegister);
        Register *sp = t->tryGetCertainRegister(true, "sp", hasFreeRegister);
        t->addCodeAdd(arg1Reg, sp, -result->getMemOffset());
        for (int i = 0; i < result->getArraySize(); ++i) {
            t->addCodeStr(arg1Reg, tmpr, 0, false);
            t->addCodeAdd(arg1Reg, arg1Reg, 4);
        }
        t->setRegisterFree(arg1Reg);
        t->setRegisterFree(tmpr);
        t->setRegisterFree(sp);
    }
    else {
        Register *arg1Reg = arg1->load(t, true);
        result->storeFrom(t, arg1Reg);
        t->setRegisterFree(arg1Reg);
    }
}

void IRAssignF::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    if (result->getIsArray()) {
        Register *tmpr = t->getNextFreeRegister(true, false, hasFreeRegister);
        t->addCodeAdr(tmpr, arg1->getValueLabel());
        Register *arg1Reg = t->getNextFreeRegister(true, false, hasFreeRegister);
        Register *sp = t->tryGetCertainRegister(true, "sp", hasFreeRegister);
        t->addCodeAdd(arg1Reg, sp, -result->getMemOffset());
        for (int i = 0; i < result->getArraySize(); ++i) {
            t->addCodeStr(arg1Reg, tmpr, 0, false);
            t->addCodeAdd(arg1Reg, arg1Reg, 4);
        }
        t->setRegisterFree(arg1Reg);
        t->setRegisterFree(tmpr);
        t->setRegisterFree(sp);
    }
    else {
        Register *arg1Reg = arg1->load(t, true);
        result->storeFrom(t, arg1Reg);
        t->setRegisterFree(arg1Reg);
    }
}

void IRFetchArrayElemI::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t, true);
    Register *arg2Reg = arg2->load(t, true);
    t->addCodeLsl(arg2Reg, arg2Reg, 2);
    t->addCodeAdd(arg1Reg, arg1Reg, arg2Reg);
    t->addCodeLdr(arg1Reg, arg1Reg, 0);
    result->storeFrom(t, arg1Reg);
    t->setRegisterFree(arg1Reg);
    t->setRegisterFree(arg2Reg);
}

void IRFetchArrayElemF::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t, true);
    Register *arg2Reg = arg2->load(t, true);
    t->addCodeLsl(arg2Reg, arg2Reg, 2);
    t->addCodeAdd(arg1Reg, arg1Reg, arg2Reg);
    t->addCodeLdr(arg1Reg, arg1Reg, 0);
    result->storeFrom(t, arg1Reg);
    t->setRegisterFree(arg1Reg);
    t->setRegisterFree(arg2Reg);
}

void IRAssignArrayElemI::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t, true);
    Register *arg2Reg = arg2->load(t, true);
    Register *srcReg = result->load(t, true);
    t->addCodeLsl(arg2Reg, arg2Reg, 2);
    t->addCodeAdd(arg1Reg, arg1Reg, arg2Reg);
    t->addCodeStr(arg1Reg, srcReg, 0, false);
    t->setRegisterFree(arg1Reg);
    t->setRegisterFree(arg2Reg);
    t->setRegisterFree(srcReg);
}

void IRAssignArrayElemF::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t, true);
    Register *arg2Reg = arg2->load(t, true);
    Register *srcReg = result->load(t, true);
    t->addCodeLsl(arg2Reg, arg2Reg, 2);
    t->addCodeAdd(arg1Reg, arg1Reg, arg2Reg);
    t->addCodeStr(arg1Reg, srcReg, 0, false);
    t->setRegisterFree(arg1Reg);
    t->setRegisterFree(arg2Reg);
    t->setRegisterFree(srcReg);
}

void IRAddLabel::genTargetCode(TargetCodes *t) {
    t->addCodeLabel(arg1->getSymbolName());
}

void IRAddParamI::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = t->getNextFreeRegister(true, true, hasFreeRegister);
    if (arg1Reg->getOccupied()) {
        Register *sp = t->tryGetCertainRegister(true, "sp", hasFreeRegister);
        arg1Reg->setTmpStored(true);
        t->addCodeStr(sp, arg1Reg, -arg1Reg->getTmpStoreOffset(), false);
        t->setRegisterFree(sp);
    }
    arg1->loadTo(t, arg1Reg);
    t->setRegisterFree(arg1Reg);
}

void IRAddParamF::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = t->getNextFreeRegister(false, true, hasFreeRegister);
    if (arg1Reg->getOccupied()) {
        Register *sp = t->tryGetCertainRegister(true, "sp", hasFreeRegister);
        arg1Reg->setTmpStored(true);
        t->addCodeVstr(sp, arg1Reg, -arg1Reg->getTmpStoreOffset(), false);
        t->setRegisterFree(sp);
    }
    arg1->loadTo(t, arg1Reg);
    t->setRegisterFree(arg1Reg);
}

void IRAddParamA::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = t->getNextFreeRegister(true, true, hasFreeRegister);
    t->addCodeAdr(arg1Reg, arg1->getSymbolName());
    t->setRegisterFree(arg1Reg);
}

void IRGetParamI::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *resultArg = t->tryGetCertainRegister(true, "a" + arg1->getValue(), hasFreeRegister);
    result->storeFrom(t, resultArg);
    t->setRegisterFree(resultArg);
}

void IRGetParamF::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *resultArg = t->tryGetCertainRegister(false, "fa" + arg1->getValue(), hasFreeRegister);
    result->storeFrom(t, resultArg);
    t->setRegisterFree(resultArg);
}

void IRGetParamA::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *resultArg = t->tryGetCertainRegister(true, "a" + arg1->getValue(), hasFreeRegister);
    arg1->storeFrom(t, resultArg);
    t->setRegisterFree(resultArg);
}

void IRCall::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *sp = t->tryGetCertainRegister(true, "sp", hasFreeRegister);
    for (auto it : arg2->getBindRegisters()) {
        if (it->getRegisterType() == RegisterType::GENERAL_PURPOSE && it->getAliasName()[0] != 's') {
            t->addCodeStr(sp, it, -it->getTmpStoreOffset(), false);
        }
        else if (it->getRegisterType() == RegisterType::FLOAT_POINT && it->getAliasName()[0] != 'fs') {
            t->addCodeStr(sp, it, -it->getTmpStoreOffset(), false);
        }
    }
    t->addCodeAdd(sp, sp, -arg2->getFrameSize());
    t->addCodeBl(arg1->getFunctionName());
    t->addCodeAdd(sp, sp, arg2->getFrameSize());
    for (auto it : arg2->getBindRegisters()) {
        if (it->getRegisterType() == RegisterType::GENERAL_PURPOSE && it->getAliasName()[0] != 's') {
            if (arg1->getReturnType() != MetaDataType::VOID && it->getAliasName() == "a0") {
                continue;
            }
            t->addCodeLdr(it, sp, -it->getTmpStoreOffset());
        }
        else if (it->getRegisterType() == RegisterType::FLOAT_POINT && it->getAliasName()[0] != 'fs') {
            if (arg1->getReturnType() != MetaDataType::VOID && it->getAliasName() == "fa0") {
                continue;
            }
            t->addCodeLdr(it, sp, -it->getTmpStoreOffset());
        }
    }
    t->setRegisterFree(sp);
}

void IRReturn::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *sp = t->tryGetCertainRegister(true, "sp", hasFreeRegister);
    // Register *ra = t->tryGetCertainRegister(true, "ra", hasFreeRegister);
    for (auto it : arg2->getBindRegisters()) {
        if (it->getRegisterType() == RegisterType::GENERAL_PURPOSE && it->getAliasName()[0] == 's') {
            t->addCodeLdr(it, sp, -it->getTmpStoreOffset());
        }
        else if (it->getRegisterType() == RegisterType::FLOAT_POINT && it->getAliasName()[0] == 'fs') {
            t->addCodeLdr(it, sp, -it->getTmpStoreOffset());
        }
    }
    // t->addCodeLd(ra, sp, -8);
    Register *pc = t->tryGetCertainRegister(true, "pc", hasFreeRegister);
    Register *lr = t->tryGetCertainRegister(true, "lr", hasFreeRegister);
    t->addCodeMv(pc, lr);
    t->setRegisterFree(pc);
    t->setRegisterFree(lr);
    t->setRegisterFree(sp);
    // t->setRegisterFree(ra);
}

void IRReturnV::genTargetCode(TargetCodes *t) {
    IRReturn::genTargetCode(t);
}

void IRReturnI::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *retReg = t->tryGetCertainRegister(true, "a0", hasFreeRegister);
    if (retReg->getOccupied()) {
        Register *sp = t->tryGetCertainRegister(true, "sp", hasFreeRegister);
        t->addCodeStr(sp, retReg, -retReg->getTmpStoreOffset(), false);
        t->setRegisterFree(sp);
    }
    arg1->loadTo(t, retReg);
    IRReturn::genTargetCode(t);
    t->setRegisterFree(retReg);
}

void IRReturnF::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *retReg = t->tryGetCertainRegister(false, "fa0", hasFreeRegister);
    if (retReg->getOccupied()) {
        Register *sp = t->tryGetCertainRegister(true, "sp", hasFreeRegister);
        t->addCodeVstr(sp, retReg, -retReg->getTmpStoreOffset(), false);
        t->setRegisterFree(sp);
    }
    arg1->loadTo(t, retReg);
    IRReturn::genTargetCode(t);
    t->setRegisterFree(retReg);
}

void IRGetReturnI::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *retReg = t->tryGetCertainRegister(true, "a0", hasFreeRegister);
    result->storeFrom(t, retReg);
    if (retReg->getOccupied()) {
        Register *sp = t->tryGetCertainRegister(true, "sp", hasFreeRegister);
        t->addCodeStr(sp, retReg, -retReg->getTmpStoreOffset(), false);
        t->setRegisterFree(sp);
    }
    t->setRegisterFree(retReg);
}

void IRGetReturnF::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *retReg = t->tryGetCertainRegister(false, "fa0", hasFreeRegister);
    result->storeFrom(t, retReg);
    if (retReg->getOccupied()) {
        Register *sp = t->tryGetCertainRegister(true, "sp", hasFreeRegister);
        t->addCodeVstr(sp, retReg, -retReg->getTmpStoreOffset(), false);
        t->setRegisterFree(sp);
    }
    t->setRegisterFree(retReg);
}