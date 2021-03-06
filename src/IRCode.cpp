#include <iostream>

#include "IRCode.h"

using namespace std;

IRCode::IRCode() {
    operation = IROperation::ADD_PARAM;
    result = nullptr;
    arg1 = nullptr;
    arg2 = nullptr;
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

bool IRCode::setOperation(IROperation op) {
    operation = op;
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
        case IROperation::PRINT:
        case IROperation::READ:
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

IRPhi::IRPhi(IROperand *newResult, std::vector<IROperand *>newArg1)
        : IRCode(IROperation::PHI, newResult, nullptr, nullptr) {
    args = newArg1;
}

IRReplace::IRReplace(IROperand *newResult, IROperand *newArg1)
        : IRCode(IROperation::REPLACE, newResult, newArg1, nullptr) {}

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

IRCall::IRCall(IROperand *newArg1, IROperand *newArg2)
        : IRCode(IROperation::CALL, nullptr, newArg1, newArg2) {}

IRReturn::IRReturn(IROperand *newArg1, IROperand *newArg2)
        : IRCode(IROperation::RETURN, nullptr, newArg1, newArg2) {}

IRReturnV::IRReturnV(IROperand *newArg2)
        : IRReturn(nullptr, newArg2) {}

IRReturnB::IRReturnB(IROperand *newArg1, IROperand *newArg2)
        : IRReturn(newArg1, newArg2) {}

IRReturnI::IRReturnI(IROperand *newArg1, IROperand *newArg2)
        : IRReturn(newArg1, newArg2) {}

IRReturnF::IRReturnF(IROperand *newArg1, IROperand *newArg2)
        : IRReturn(newArg1, newArg2) {}

IRReturnD::IRReturnD(IROperand *newArg1, IROperand *newArg2)
        : IRReturn(newArg1, newArg2) {}

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

IRPrint::IRPrint(IROperand *newArg1)
        : IRCode(IROperation::PRINT, nullptr, newArg1, nullptr) {}

IRPrintB::IRPrintB(IROperand *newArg1)
        : IRPrint(newArg1) {}

IRPrintI::IRPrintI(IROperand *newArg1)
        : IRPrint(newArg1) {}

IRPrintF::IRPrintF(IROperand *newArg1)
        : IRPrint(newArg1) {}

IRPrintD::IRPrintD(IROperand *newArg1)
        : IRPrint(newArg1) {}

IRRead::IRRead(IROperand *newResult)
        : IRCode(IROperation::READ, newResult, nullptr, nullptr) {}

IRReadI::IRReadI(IROperand *newResult)
        : IRRead(newResult) {}

IRReadF::IRReadF(IROperand *newResult)
        : IRRead(newResult) {}

IRReadD::IRReadD(IROperand *newResult)
        : IRRead(newResult) {}

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

void IRPrint::print() const {
    cout << "\t" << "print(" << arg1->getVal() << ");" << endl;
}

void IRRead::print() const {
    cout << "\t" << result->getVal() << " = read();" << endl;
}

void IRAddI::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *resultReg;
    if (result->getBindRegister()) {
        resultReg = result->getTargetBindRegister();
    }
    else {
        resultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    }
    if (arg1->getOperandType() == OperandType::VALUE && arg2->getOperandType() != OperandType::VALUE) {
        Register *arg2Reg = arg2->load(t, true);
        if (stoi(arg1->getValue()) > 2048 || stoi(arg1->getValue()) < -2048) {
            t->addCodeLi(resultReg, stoi(arg1->getValue()));
        }
        else {
            t->addCodeAddi(resultReg, arg2Reg, stoi(arg1->getValue()));
        }
        t->setRegisterFree(arg2Reg);
    }
    else if (arg1->getOperandType() != OperandType::VALUE && arg2->getOperandType() == OperandType::VALUE) {
        Register *arg1Reg = arg1->load(t, true);
        int val = stoi(arg2->getValue());
        if (val > 2048 || val < -2048) {
            t->addCodeLi(resultReg, val);
        }
        else {
            t->addCodeAddi(resultReg, arg1Reg, val);
        }
        t->setRegisterFree(arg1Reg);
    }
    else if (arg1->getOperandType() == OperandType::VALUE && arg2->getOperandType() == OperandType::VALUE) {
        Register *zero = t->tryGetCertainRegister(true, "zero", hasFreeRegister);
        int val = stoi(arg2->getValue()) + stoi(arg2->getValue());
        if (val > 2048 || val < -2048) {
            t->addCodeLi(resultReg, stoi(arg1->getValue()));
        }
        else {
            t->addCodeAddi(resultReg, zero, val);
        }
        t->setRegisterFree(zero);
    }
    else {
        Register *arg1Reg = arg1->load(t, true);
        Register *arg2Reg = arg2->load(t, true);
        t->addCodeAdd(resultReg, arg1Reg, arg2Reg, FloatPointType::NONE);
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
        resultReg = t->getNextFreeRegister(false, false, FloatPointType::NONE, hasFreeRegister);
    }
    t->addCodeAdd(resultReg, arg1Reg, arg2Reg, FloatPointType::SINGLE);
    result->storeFrom(t, resultReg);
    t->setRegisterFree(arg1Reg);
    t->setRegisterFree(arg2Reg);
    t->setRegisterFree(resultReg);
}

void IRAddD::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t, false);
    Register *arg2Reg = arg2->load(t, false);
    Register *resultReg ;
    if (result->getBindRegister()) {
        resultReg = result->getTargetBindRegister();
    }
    else {
        resultReg = t->getNextFreeRegister(false, false, FloatPointType::NONE, hasFreeRegister);
    }
    t->addCodeAdd(resultReg, arg1Reg, arg2Reg, FloatPointType::DOUBLE);
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
        resultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    }
    t->addCodeSub(resultReg, arg1Reg, arg2Reg, FloatPointType::NONE);
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
        resultReg = t->getNextFreeRegister(false, false, FloatPointType::NONE, hasFreeRegister);
    }
    t->addCodeSub(resultReg, arg1Reg, arg2Reg, FloatPointType::SINGLE);
    result->storeFrom(t, resultReg);
    t->setRegisterFree(arg1Reg);
    t->setRegisterFree(arg2Reg);
    t->setRegisterFree(resultReg);
}

void IRSubD::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t, false);
    Register *arg2Reg = arg2->load(t, false);
    Register *resultReg;
    if (result->getBindRegister()) {
        resultReg = result->getTargetBindRegister();
    }
    else {
        resultReg = t->getNextFreeRegister(false, false, FloatPointType::NONE, hasFreeRegister);
    }
    t->addCodeAdd(resultReg, arg1Reg, arg2Reg, FloatPointType::DOUBLE);
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
        resultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    }
    t->addCodeNeg(resultReg, arg1Reg, FloatPointType::NONE);
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
        resultReg = t->getNextFreeRegister(false, false, FloatPointType::NONE, hasFreeRegister);
    }
    t->addCodeNeg(resultReg, arg1Reg, FloatPointType::SINGLE);
    result->storeFrom(t, resultReg);
    t->setRegisterFree(arg1Reg);
    t->setRegisterFree(resultReg);
}

void IRNegD::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t, false);
    Register *resultReg;
    if (result->getBindRegister()) {
        resultReg = result->getTargetBindRegister();
    }
    else {
        resultReg = t->getNextFreeRegister(false, false, FloatPointType::NONE, hasFreeRegister);
    }
    t->addCodeNeg(resultReg, arg1Reg, FloatPointType::DOUBLE);
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
        resultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    }
    t->addCodeMul(resultReg, arg1Reg, arg2Reg, FloatPointType::NONE);
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
        resultReg = t->getNextFreeRegister(false, false, FloatPointType::NONE, hasFreeRegister);
    }
    t->addCodeMul(resultReg, arg1Reg, arg2Reg, FloatPointType::SINGLE);
    result->storeFrom(t, resultReg);
    t->setRegisterFree(arg1Reg);
    t->setRegisterFree(arg2Reg);
    t->setRegisterFree(resultReg);
}

void IRMulD::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t, false);
    Register *arg2Reg = arg2->load(t, false);
    Register *resultReg;
    if (result->getBindRegister()) {
        resultReg = result->getTargetBindRegister();
    }
    else {
        resultReg = t->getNextFreeRegister(false, false, FloatPointType::NONE, hasFreeRegister);
    }
    t->addCodeMul(resultReg, arg1Reg, arg2Reg, FloatPointType::DOUBLE);
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
        resultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    }
    t->addCodeDiv(resultReg, arg1Reg, arg2Reg, FloatPointType::NONE);
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
        resultReg = t->getNextFreeRegister(false, false, FloatPointType::NONE, hasFreeRegister);
    }
    t->addCodeDiv(resultReg, arg1Reg, arg2Reg, FloatPointType::SINGLE);
    result->storeFrom(t, resultReg);
    t->setRegisterFree(arg1Reg);
    t->setRegisterFree(arg2Reg);
    t->setRegisterFree(resultReg);
}

void IRDivD::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t, false);
    Register *arg2Reg = arg2->load(t, false);
    Register *resultReg;
    if (result->getBindRegister()) {
        resultReg = result->getTargetBindRegister();
    }
    else {
        resultReg = t->getNextFreeRegister(false, false, FloatPointType::NONE, hasFreeRegister);
    }
    t->addCodeDiv(resultReg, arg1Reg, arg2Reg, FloatPointType::DOUBLE);
    result->storeFrom(t, resultReg);
    t->setRegisterFree(arg1Reg);
    t->setRegisterFree(arg2Reg);
    t->setRegisterFree(resultReg);
}

void IRMod::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t, true);
    Register *arg2Reg = arg2->load(t, true);
    Register *resultReg;
    if (result->getBindRegister()) {
        resultReg = result->getTargetBindRegister();
    }
    else {
        resultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    }
    t->addCodeRem(resultReg, arg1Reg, arg2Reg);
    result->storeFrom(t, resultReg);
    t->setRegisterFree(arg1Reg);
    t->setRegisterFree(arg2Reg);
    t->setRegisterFree(resultReg);
}

void IRNot::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t, true);
    Register *resultReg;
    if (result->getBindRegister()) {
        resultReg = result->getTargetBindRegister();
    }
    else {
        resultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    }
    t->addCodeSeqz(resultReg, arg1Reg);
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
        resultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    }
    t->addCodeOr(resultReg, arg1Reg, arg2Reg);
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
        resultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    }
    t->addCodeAnd(resultReg, arg1Reg, arg2Reg);
    result->storeFrom(t, resultReg);
    t->setRegisterFree(arg1Reg);
    t->setRegisterFree(arg2Reg);
    t->setRegisterFree(resultReg);
}

void IRSeqB::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t, true);
    Register *arg2Reg = arg2->load(t, true);
    Register *tmpResultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    Register *resultReg;
    if (result->getBindRegister()) {
        resultReg = result->getTargetBindRegister();
    }
    else {
        resultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    }
    t->addCodeXor(tmpResultReg, arg1Reg, arg2Reg);
    t->addCodeSeqz(resultReg, tmpResultReg);
    result->storeFrom(t, resultReg);
    t->setRegisterFree(arg1Reg);
    t->setRegisterFree(arg2Reg);
    t->setRegisterFree(tmpResultReg);
    t->setRegisterFree(resultReg);
}


void IRSeqI::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t, true);
    Register *arg2Reg = arg2->load(t, true);
    Register *tmpResultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    Register *resultReg;
    if (result->getBindRegister()) {
        resultReg = result->getTargetBindRegister();
    }
    else {
        resultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    }
    t->addCodeXor(tmpResultReg, arg1Reg, arg2Reg);
    t->addCodeSeqz(resultReg, tmpResultReg);
    result->storeFrom(t, resultReg);
    t->setRegisterFree(arg1Reg);
    t->setRegisterFree(arg2Reg);
    t->setRegisterFree(tmpResultReg);
    t->setRegisterFree(resultReg);
}

void IRSeqF::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t, false);
    Register *arg2Reg = arg2->load(t, false);
    Register *resultReg;
    if (result->getBindRegister()) {
        resultReg = result->getTargetBindRegister();
    }
    else {
        resultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    }
    t->addCodeFeq(resultReg, arg1Reg, arg2Reg, FloatPointType::SINGLE);
    result->storeFrom(t, resultReg);
    t->setRegisterFree(arg1Reg);
    t->setRegisterFree(arg2Reg);
    t->setRegisterFree(resultReg);
}

void IRSeqD::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t, false);
    Register *arg2Reg = arg2->load(t, false);
    Register *resultReg;
    if (result->getBindRegister()) {
        resultReg = result->getTargetBindRegister();
    }
    else {
        resultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    }
    t->addCodeFeq(resultReg, arg1Reg, arg2Reg, FloatPointType::DOUBLE);
    result->storeFrom(t, resultReg);
    t->setRegisterFree(arg1Reg);
    t->setRegisterFree(arg2Reg);
    t->setRegisterFree(resultReg);
}

void IRSneB::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t, true);
    Register *arg2Reg = arg2->load(t, true);
    Register *tmpResultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    Register *resultReg;
    if (result->getBindRegister()) {
        resultReg = result->getTargetBindRegister();
    }
    else {
        resultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    }
    t->addCodeXor(tmpResultReg, arg1Reg, arg2Reg);
    t->addCodeSnez(resultReg, tmpResultReg);
    result->storeFrom(t, resultReg);
    t->setRegisterFree(arg1Reg);
    t->setRegisterFree(arg2Reg);
    t->setRegisterFree(tmpResultReg);
    t->setRegisterFree(resultReg);
}

void IRSneI::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t, true);
    Register *arg2Reg = arg2->load(t, true);
    Register *tmpResultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    Register *resultReg;
    if (result->getBindRegister()) {
        resultReg = result->getTargetBindRegister();
    }
    else {
        resultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    }
    t->addCodeXor(tmpResultReg, arg1Reg, arg2Reg);
    t->addCodeSnez(resultReg, tmpResultReg);
    result->storeFrom(t, resultReg);
    t->setRegisterFree(arg1Reg);
    t->setRegisterFree(arg2Reg);
    t->setRegisterFree(tmpResultReg);
    t->setRegisterFree(resultReg);
}

void IRSneF::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t, false);
    Register *arg2Reg = arg2->load(t, false);
    Register *resultReg;
    if (result->getBindRegister()) {
        resultReg = result->getTargetBindRegister();
    }
    else {
        resultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    }
    t->addCodeFeq(resultReg, arg1Reg, arg2Reg, FloatPointType::SINGLE);
    t->addCodeNot(resultReg, resultReg);
    result->storeFrom(t, resultReg);
    t->setRegisterFree(arg1Reg);
    t->setRegisterFree(arg2Reg);
    t->setRegisterFree(resultReg);
}

void IRSneD::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t, false);
    Register *arg2Reg = arg2->load(t, false);
    Register *resultReg;
    if (result->getBindRegister()) {
        resultReg = result->getTargetBindRegister();
    }
    else {
        resultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    }
    t->addCodeFeq(resultReg, arg1Reg, arg2Reg, FloatPointType::DOUBLE);
    t->addCodeNot(resultReg, resultReg);
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
        resultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    }
    t->addCodeSlt(resultReg, arg1Reg, arg2Reg);
    result->storeFrom(t, resultReg);
    t->setRegisterFree(arg1Reg);
    t->setRegisterFree(arg2Reg);
    t->setRegisterFree(resultReg);
}

void IRSltF::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t, false);
    Register *arg2Reg = arg2->load(t, false);
    Register *resultReg;
    if (result->getBindRegister()) {
        resultReg = result->getTargetBindRegister();
    }
    else {
        resultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    }
    t->addCodeFlt(resultReg, arg1Reg, arg2Reg, FloatPointType::SINGLE);
    result->storeFrom(t, resultReg);
    t->setRegisterFree(arg1Reg);
    t->setRegisterFree(arg2Reg);
    t->setRegisterFree(resultReg);
}

void IRSltD::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t, false);
    Register *arg2Reg = arg2->load(t, false);
    Register *resultReg;
    if (result->getBindRegister()) {
        resultReg = result->getTargetBindRegister();
    }
    else {
        resultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    }
    t->addCodeFlt(resultReg, arg1Reg, arg2Reg, FloatPointType::DOUBLE);
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
        resultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    }
    // reverse
    t->addCodeSlt(resultReg, arg2Reg, arg1Reg);
    result->storeFrom(t, resultReg);
    t->setRegisterFree(arg1Reg);
    t->setRegisterFree(arg2Reg);
    t->setRegisterFree(resultReg);
}

void IRSgtF::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t, false);
    Register *arg2Reg = arg2->load(t, false);
    Register *resultReg;
    if (result->getBindRegister()) {
        resultReg = result->getTargetBindRegister();
    }
    else {
        resultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    }
    // reverse
    t->addCodeFlt(resultReg, arg2Reg, arg1Reg, FloatPointType::SINGLE);
    result->storeFrom(t, resultReg);
    t->setRegisterFree(arg1Reg);
    t->setRegisterFree(arg2Reg);
    t->setRegisterFree(resultReg);
}

void IRSgtD::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t, false);
    Register *arg2Reg = arg2->load(t, false);
    Register *resultReg;
    if (result->getBindRegister()) {
        resultReg = result->getTargetBindRegister();
    }
    else {
        resultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    }
    // reverse
    t->addCodeFlt(resultReg, arg2Reg, arg1Reg, FloatPointType::DOUBLE);
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
        resultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    }
    // reverse
    t->addCodeSlt(resultReg, arg2Reg, arg1Reg);
    // neg
    t->addCodeNot(resultReg, resultReg);
    result->storeFrom(t, resultReg);
    t->setRegisterFree(arg1Reg);
    t->setRegisterFree(arg2Reg);
    t->setRegisterFree(resultReg);
}

void IRSleqF::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t, false);
    Register *arg2Reg = arg2->load(t, false);
    Register *resultReg;
    if (result->getBindRegister()) {
        resultReg = result->getTargetBindRegister();
    }
    else {
        resultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    }
    // reverse
    t->addCodeFlt(resultReg, arg1Reg, arg2Reg, FloatPointType::SINGLE);
    result->storeFrom(t, resultReg);
    t->setRegisterFree(arg1Reg);
    t->setRegisterFree(arg2Reg);
    t->setRegisterFree(resultReg);
}

void IRSleqD::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t, false);
    Register *arg2Reg = arg2->load(t, false);
    Register *resultReg;
    if (result->getBindRegister()) {
        resultReg = result->getTargetBindRegister();
    }
    else {
        resultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    }
    // reverse
    t->addCodeFlt(resultReg, arg1Reg, arg2Reg, FloatPointType::DOUBLE);
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
        resultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    }
    t->addCodeSlt(resultReg, arg1Reg, arg2Reg);
    // neg
    t->addCodeSeqz(resultReg, resultReg);
    result->storeFrom(t, resultReg);
    t->setRegisterFree(arg1Reg);
    t->setRegisterFree(arg2Reg);
    t->setRegisterFree(resultReg);
}

void IRSgeqF::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t, false);
    Register *arg2Reg = arg2->load(t, false);
    Register *resultReg;
    if (result->getBindRegister()) {
        resultReg = result->getTargetBindRegister();
    }
    else {
        resultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    }
    t->addCodeFlt(resultReg, arg1Reg, arg2Reg, FloatPointType::SINGLE);
    t->addCodeSeqz(resultReg, resultReg);
    result->storeFrom(t, resultReg);
    t->setRegisterFree(arg1Reg);
    t->setRegisterFree(arg2Reg);
    t->setRegisterFree(resultReg);
}

void IRSgeqD::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t, false);
    Register *arg2Reg = arg2->load(t, false);
    Register *resultReg;
    if (result->getBindRegister()) {
        resultReg = result->getTargetBindRegister();
    }
    else {
        resultReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    }
    t->addCodeFlt(resultReg, arg1Reg, arg2Reg, FloatPointType::SINGLE);
    t->addCodeSeqz(resultReg, resultReg);
    result->storeFrom(t, resultReg);
    t->setRegisterFree(arg1Reg);
    t->setRegisterFree(arg2Reg);
    t->setRegisterFree(resultReg);
}

void IRBeqz::genTargetCode(TargetCodes *t) {
    Register *arg1Reg = arg1->load(t, true);
    string label = arg2->getSymbolName();
    t->addCodeBeqz(arg1Reg, label);
    t->setRegisterFree(arg1Reg);
}

void IRGoto::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    string label = arg1->getSymbolName();
    Register *labelReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
    t->addCodeLla(labelReg, label);
    t->addCodeJr(labelReg);
    t->setRegisterFree(labelReg);
}

void IRReplace::genTargetCode(TargetCodes *t) {
    // do nothing
}

void IRAssignB::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    if (result->getIsArray()) {
        Register *tmpr = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
        t->addCodeLla(tmpr, arg1->getValueLabel());
        Register *arg1Reg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
        t->addCodeLla(arg1Reg, arg1->getSymbolName());
        for (int i = 0; i < result->getArraySize(); ++i) {
            t->addCodeAddi(arg1Reg, arg1Reg, 4);
            t->addCodeSb(arg1Reg, tmpr, 0);
        }
        t->setRegisterFree(arg1Reg);
        t->setRegisterFree(tmpr);
    }
    else {
        Register *arg1Reg = arg1->load(t, true);
        result->storeFrom(t, arg1Reg);
        t->setRegisterFree(arg1Reg);
    }
}

void IRAssignI::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    if (result->getIsArray()) {
        Register *tmpr = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
        t->addCodeLla(tmpr, arg1->getValueLabel());
        Register *arg1Reg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
        Register *sp = t->tryGetCertainRegister(true, "sp", hasFreeRegister);
        t->addCodeAddi(arg1Reg, sp, -result->getMemOffset());
        for (int i = 0; i < result->getArraySize(); ++i) {
            t->addCodeSw(arg1Reg, tmpr, 0);
            t->addCodeAddi(arg1Reg, arg1Reg, 4);
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
        Register *tmpr = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
        t->addCodeLla(tmpr, arg1->getValueLabel());
        Register *arg1Reg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
        Register *sp = t->tryGetCertainRegister(true, "sp", hasFreeRegister);
        t->addCodeAddi(arg1Reg, sp, -result->getMemOffset());
        for (int i = 0; i < result->getArraySize(); ++i) {
            t->addCodeSw(arg1Reg, tmpr, 0);
            t->addCodeAddi(arg1Reg, arg1Reg, 4);
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

void IRAssignD::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    if (result->getIsArray()) {
        Register *tmpr = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
        t->addCodeLla(tmpr, arg1->getValueLabel());
        Register *arg1Reg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
        Register *sp = t->tryGetCertainRegister(true, "sp", hasFreeRegister);
        t->addCodeAddi(arg1Reg, sp, -result->getMemOffset());
        for (int i = 0; i < result->getArraySize(); ++i) {
            t->addCodeSd(arg1Reg, tmpr, 0);
            t->addCodeAddi(arg1Reg, arg1Reg, 8);
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

void IRFetchArrayElemB::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t, true);
    Register *arg2Reg = arg2->load(t, true);
    t->addCodeSlli(arg2Reg, arg2Reg, 2);
    t->addCodeAdd(arg1Reg, arg1Reg, arg2Reg, FloatPointType::NONE);
    t->addCodeLb(arg1Reg, arg1Reg, 0);
    result->storeFrom(t, arg1Reg);
    t->setRegisterFree(arg1Reg);
    t->setRegisterFree(arg2Reg);
}

void IRFetchArrayElemI::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t, true);
    Register *arg2Reg = arg2->load(t, true);
    t->addCodeSlli(arg2Reg, arg2Reg, 2);
    t->addCodeAdd(arg1Reg, arg1Reg, arg2Reg, FloatPointType::NONE);
    t->addCodeLw(arg1Reg, arg1Reg, 0);
    result->storeFrom(t, arg1Reg);
    t->setRegisterFree(arg1Reg);
    t->setRegisterFree(arg2Reg);
}

void IRFetchArrayElemF::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t, true);
    Register *arg2Reg = arg2->load(t, true);
    t->addCodeSlli(arg2Reg, arg2Reg, 2);
    t->addCodeAdd(arg1Reg, arg1Reg, arg2Reg, FloatPointType::NONE);
    t->addCodeLw(arg1Reg, arg1Reg, 0);
    result->storeFrom(t, arg1Reg);
    t->setRegisterFree(arg1Reg);
    t->setRegisterFree(arg2Reg);
}

void IRFetchArrayElemD::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t, true);
    Register *arg2Reg = arg2->load(t, true);
    t->addCodeSlli(arg2Reg, arg2Reg, 3);
    t->addCodeAdd(arg1Reg, arg1Reg, arg2Reg, FloatPointType::NONE);
    t->addCodeLd(arg1Reg, arg1Reg, 0);
    result->storeFrom(t, arg1Reg);
    t->setRegisterFree(arg1Reg);
    t->setRegisterFree(arg2Reg);
}

void IRAssignArrayElemB::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t, true);
    Register *arg2Reg = arg2->load(t, true);
    Register *srcReg = result->load(t, true);
    t->addCodeSlli(arg2Reg, arg2Reg, 2);
    t->addCodeAdd(arg1Reg, arg1Reg, arg2Reg, FloatPointType::NONE);
    t->addCodeSb(arg1Reg, srcReg, 0);
    t->setRegisterFree(arg1Reg);
    t->setRegisterFree(arg2Reg);
    t->setRegisterFree(srcReg);
}

void IRAssignArrayElemI::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t, true);
    Register *arg2Reg = arg2->load(t, true);
    Register *srcReg = result->load(t, true);
    t->addCodeSlli(arg2Reg, arg2Reg, 2);
    t->addCodeAdd(arg1Reg, arg1Reg, arg2Reg, FloatPointType::NONE);
    t->addCodeSw(arg1Reg, srcReg, 0);
    t->setRegisterFree(arg1Reg);
    t->setRegisterFree(arg2Reg);
    t->setRegisterFree(srcReg);
}

void IRAssignArrayElemF::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t, true);
    Register *arg2Reg = arg2->load(t, true);
    Register *srcReg = result->load(t, true);
    t->addCodeSlli(arg2Reg, arg2Reg, 2);
    t->addCodeAdd(arg1Reg, arg1Reg, arg2Reg, FloatPointType::NONE);
    t->addCodeSw(arg1Reg, srcReg, 0);
    t->setRegisterFree(arg1Reg);
    t->setRegisterFree(arg2Reg);
    t->setRegisterFree(srcReg);
}

void IRAssignArrayElemD::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = arg1->load(t, true);
    Register *arg2Reg = arg2->load(t, true);
    Register *srcReg = result->load(t, true);
    t->addCodeSlli(arg2Reg, arg2Reg, 3);
    t->addCodeAdd(arg1Reg, arg1Reg, arg2Reg, FloatPointType::NONE);
    t->addCodeSd(arg1Reg, srcReg, 0);
    t->setRegisterFree(arg1Reg);
    t->setRegisterFree(arg2Reg);
    t->setRegisterFree(srcReg);
}

void IRAddLabel::genTargetCode(TargetCodes *t) {
    t->addCodeLabel(arg1->getSymbolName());
}

void IRAddParamB::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = t->getNextFreeRegister(true, true, FloatPointType::NONE, hasFreeRegister);
    if (arg1Reg->getOccupied()) {
        Register *sp = t->tryGetCertainRegister(true, "sp", hasFreeRegister);
        arg1Reg->setTmpStored(true);
        t->addCodeSw(sp, arg1Reg, -arg1Reg->getTmpStoreOffset());
        t->setRegisterFree(sp);
    }
    arg1->loadTo(t, arg1Reg);
    t->setRegisterFree(arg1Reg);
}

void IRAddParamI::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = t->getNextFreeRegister(true, true, FloatPointType::NONE, hasFreeRegister);
    if (arg1Reg->getOccupied()) {
        Register *sp = t->tryGetCertainRegister(true, "sp", hasFreeRegister);
        arg1Reg->setTmpStored(true);
        t->addCodeSw(sp, arg1Reg, -arg1Reg->getTmpStoreOffset());
        t->setRegisterFree(sp);
    }
    arg1->loadTo(t, arg1Reg);
    t->setRegisterFree(arg1Reg);
}

void IRAddParamF::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = t->getNextFreeRegister(false, true, FloatPointType::SINGLE, hasFreeRegister);
    if (arg1Reg->getOccupied()) {
        Register *sp = t->tryGetCertainRegister(true, "sp", hasFreeRegister);
        arg1Reg->setTmpStored(true);
        t->addCodeFsw(sp, arg1Reg, -arg1Reg->getTmpStoreOffset());
        t->setRegisterFree(sp);
    }
    arg1->loadTo(t, arg1Reg);
    t->setRegisterFree(arg1Reg);
}

void IRAddParamD::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = t->getNextFreeRegister(false, true, FloatPointType::DOUBLE, hasFreeRegister);
    if (arg1Reg->getOccupied()) {
        Register *sp = t->tryGetCertainRegister(true, "sp", hasFreeRegister);
        arg1Reg->setTmpStored(true);
        t->addCodeFsd(sp, arg1Reg, -arg1Reg->getTmpStoreOffset());
        t->setRegisterFree(sp);
    }
    arg1->loadTo(t, arg1Reg);
    t->setRegisterFree(arg1Reg);
}

void IRAddParamA::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *arg1Reg = t->getNextFreeRegister(true, true, FloatPointType::NONE, hasFreeRegister);
    t->addCodeLla(arg1Reg, arg1->getSymbolName());
    t->setRegisterFree(arg1Reg);
}

void IRGetParamB::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *resultArg = t->tryGetCertainRegister(true, "a" + arg1->getValue(), hasFreeRegister);
    result->storeFrom(t, resultArg);
    t->setRegisterFree(resultArg);
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

void IRGetParamD::genTargetCode(TargetCodes *t) {
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
            t->addCodeSw(sp, it, -it->getTmpStoreOffset());
        }
        else if (it->getRegisterType() == RegisterType::FLOAT_POINT && it->getAliasName()[0] != 'fs') {
            if (it->getFloatPointType() == FloatPointType::SINGLE) {
                t->addCodeSw(sp, it, -it->getTmpStoreOffset());
            }
            else {
                t->addCodeSd(sp, it, -it->getTmpStoreOffset());
            }
        }
    }
    t->addCodeAddi(sp, sp, -arg2->getFrameSize());
    t->addCodeCall(arg1->getFunctionName());
    t->addCodeAddi(sp, sp, arg2->getFrameSize());
    for (auto it : arg2->getBindRegisters()) {
        if (it->getRegisterType() == RegisterType::GENERAL_PURPOSE && it->getAliasName()[0] != 's') {
            if (arg1->getReturnType() != MetaDataType::VOID && it->getAliasName() == "a0") {
                continue;
            }
            t->addCodeLw(it, sp, -it->getTmpStoreOffset());
        }
        else if (it->getRegisterType() == RegisterType::FLOAT_POINT && it->getAliasName()[0] != 'fs') {
            if (arg1->getReturnType() != MetaDataType::VOID && it->getAliasName() == "fa0") {
                continue;
            }
            if (it->getFloatPointType() == FloatPointType::SINGLE) {
                t->addCodeLw(it, sp, -it->getTmpStoreOffset());
            }
            else {
                t->addCodeLd(it, sp, -it->getTmpStoreOffset());
            }
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
            t->addCodeLw(it, sp, -it->getTmpStoreOffset());
        }
        else if (it->getRegisterType() == RegisterType::FLOAT_POINT && it->getAliasName()[0] == 'fs') {
            if (it->getFloatPointType() == FloatPointType::SINGLE) {
                t->addCodeLw(it, sp, -it->getTmpStoreOffset());
            }
            else {
                t->addCodeLd(it, sp, -it->getTmpStoreOffset());
            }
        }
    }
    // t->addCodeLd(ra, sp, -8);
    t->addCodeRet();
    t->setRegisterFree(sp);
    // t->setRegisterFree(ra);
}

void IRReturnV::genTargetCode(TargetCodes *t) {
    IRReturn::genTargetCode(t);
}

void IRReturnB::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *retReg = t->tryGetCertainRegister(true, "a0", hasFreeRegister);
    if (retReg->getOccupied()) {
        Register *sp = t->tryGetCertainRegister(true, "sp", hasFreeRegister);
        t->addCodeSw(sp, retReg, -retReg->getTmpStoreOffset());
        t->setRegisterFree(sp);
    }
    arg1->loadTo(t, retReg);
    IRReturn::genTargetCode(t);
    t->setRegisterFree(retReg);
}

void IRReturnI::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *retReg = t->tryGetCertainRegister(true, "a0", hasFreeRegister);
    if (retReg->getOccupied()) {
        Register *sp = t->tryGetCertainRegister(true, "sp", hasFreeRegister);
        t->addCodeSw(sp, retReg, -retReg->getTmpStoreOffset());
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
        t->addCodeFsw(sp, retReg, -retReg->getTmpStoreOffset());
        t->setRegisterFree(sp);
    }
    arg1->loadTo(t, retReg);
    IRReturn::genTargetCode(t);
    t->setRegisterFree(retReg);
}

void IRReturnD::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *retReg = t->tryGetCertainRegister(false, "fa0", hasFreeRegister);
    if (retReg->getOccupied()) {
        Register *sp = t->tryGetCertainRegister(true, "sp", hasFreeRegister);
        t->addCodeFsd(sp, retReg, -retReg->getTmpStoreOffset());
        t->setRegisterFree(sp);
    }
    arg1->loadTo(t, retReg);
    IRReturn::genTargetCode(t);
    t->setRegisterFree(retReg);
}

void IRGetReturnB::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *retReg = t->tryGetCertainRegister(true, "a0", hasFreeRegister);
    result->storeFrom(t, retReg);
    if (retReg->getOccupied()) {
        Register *sp = t->tryGetCertainRegister(true, "sp", hasFreeRegister);
        t->addCodeSw(sp, retReg, -retReg->getTmpStoreOffset());
        t->setRegisterFree(sp);
    }
    t->setRegisterFree(retReg);
}

void IRGetReturnI::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *retReg = t->tryGetCertainRegister(true, "a0", hasFreeRegister);
    result->storeFrom(t, retReg);
    if (retReg->getOccupied()) {
        Register *sp = t->tryGetCertainRegister(true, "sp", hasFreeRegister);
        t->addCodeSw(sp, retReg, -retReg->getTmpStoreOffset());
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
        t->addCodeFsd(sp, retReg, -retReg->getTmpStoreOffset());
        t->setRegisterFree(sp);
    }
    t->setRegisterFree(retReg);
}

void IRGetReturnD::genTargetCode(TargetCodes *t) {
    bool hasFreeRegister;
    Register *retReg = t->tryGetCertainRegister(false, "fa0", hasFreeRegister);
    result->storeFrom(t, retReg);
    if (retReg->getOccupied()) {
        Register *sp = t->tryGetCertainRegister(true, "sp", hasFreeRegister);
        t->addCodeFsd(sp, retReg, -retReg->getTmpStoreOffset());
        t->setRegisterFree(sp);
    }
    t->setRegisterFree(retReg);
}

void IRPrintB::genTargetCode(TargetCodes *t) {
}

void IRPrintI::genTargetCode(TargetCodes *t) {
}

void IRPrintF::genTargetCode(TargetCodes *t) {
}

void IRPrintD::genTargetCode(TargetCodes *t) {
}

void IRReadI::genTargetCode(TargetCodes *t) {
}

void IRReadF::genTargetCode(TargetCodes *t) {
}

void IRReadD::genTargetCode(TargetCodes *t) {
}