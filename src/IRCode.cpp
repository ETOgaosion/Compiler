#include <iostream>

#include "IRCode.h"

using namespace std;

IRCode::IRCode(IROperation newOp, IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : operation(newOp), result(newResult), arg1(newArg1), arg2(newArg2) {}

IRAddLabel::IRAddLabel(IROperand *newArg1)
        : IRCode(IROperation::ADD_LABEL, nullptr, newArg1, nullptr) {}

IRAddParam::IRAddParam(IROperand *newArg1)
        : IRCode(IROperation::ADD_PARAM, nullptr, newArg1, nullptr) 
{
        
}

IRAddParamB::IRAddParamB(IROperand *newArg1)
        : IRAddParam(newArg1) {}

IRAddParamI::IRAddParamI(IROperand *newArg1)
        : IRAddParam(newArg1) {}

IRAddParamF::IRAddParamF(IROperand *newArg1)
        : IRAddParam(newArg1) {}

IRAddParamD::IRAddParamD(IROperand *newArg1)
        : IRAddParam(newArg1) {}

IRGetParam::IRGetParam(IROperand *newResult)
        : IRCode(IROperation::GET_PARAM, newResult, nullptr, nullptr) {}

IRGetParamB::IRGetParamB(IROperand *newResult)
        : IRGetParam(newResult) {}

IRGetParamI::IRGetParamI(IROperand *newResult)
        : IRGetParam(newResult) {}

IRGetParamF::IRGetParamF(IROperand *newResult)
        : IRGetParam(newResult) {}

IRGetParamD::IRGetParamD(IROperand *newResult)
        : IRGetParam(newResult) {}

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

IRIfEqualGoto::IRIfEqualGoto(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRCode(IROperation::IF_EQUAL_GOTO, newResult, newArg1, newArg2) {}

IRIfEqualGotoB::IRIfEqualGotoB(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRIfEqualGoto(newResult, newArg1, newArg2) {}

IRIfEqualGotoI::IRIfEqualGotoI(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRIfEqualGoto(newResult, newArg1, newArg2) {}

IRIfEqualGotoF::IRIfEqualGotoF(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRIfEqualGoto(newResult, newArg1, newArg2) {}

IRIfEqualGotoD::IRIfEqualGotoD(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRIfEqualGoto(newResult, newArg1, newArg2) {}

IRIfNotEqualGoto::IRIfNotEqualGoto(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRCode(IROperation::IF_EQUAL_GOTO, newResult, newArg1, newArg2) {}

IRIfNotEqualGotoB::IRIfNotEqualGotoB(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRIfNotEqualGoto(newResult, newArg1, newArg2) {}

IRIfNotEqualGotoI::IRIfNotEqualGotoI(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRIfNotEqualGoto(newResult, newArg1, newArg2) {}

IRIfNotEqualGotoF::IRIfNotEqualGotoF(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRIfNotEqualGoto(newResult, newArg1, newArg2) {}

IRIfNotEqualGotoD::IRIfNotEqualGotoD(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRIfNotEqualGoto(newResult, newArg1, newArg2) {}

IRIfGreaterThanGoto::IRIfGreaterThanGoto(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRCode(IROperation::IF_GREATER_THAN_GOTO, newResult, newArg1, newArg2) {}

IRIfGreaterThanGotoI::IRIfGreaterThanGotoI(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRIfGreaterThanGoto(newResult, newArg1, newArg2) {}

IRIfGreaterThanGotoF::IRIfGreaterThanGotoF(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRIfGreaterThanGoto(newResult, newArg1, newArg2) {}

IRIfGreaterThanGotoD::IRIfGreaterThanGotoD(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRIfGreaterThanGoto(newResult, newArg1, newArg2) {}

IRIfGreaterEqualThanGoto::IRIfGreaterEqualThanGoto(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRCode(IROperation::IF_GREATER_EQUAL_THAN_GOTO, newResult, newArg1, newArg2) {}

IRIfGreaterEqualThanGotoI::IRIfGreaterEqualThanGotoI(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRIfGreaterEqualThanGoto(newResult, newArg1, newArg2) {}

IRIfGreaterEqualThanGotoF::IRIfGreaterEqualThanGotoF(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRIfGreaterEqualThanGoto(newResult, newArg1, newArg2) {}

IRIfGreaterEqualThanGotoD::IRIfGreaterEqualThanGotoD(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRIfGreaterEqualThanGoto(newResult, newArg1, newArg2) {}

IRIfLessThanGoto::IRIfLessThanGoto(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRCode(IROperation::IF_LESS_THAN_GOTO, newResult, newArg1, newArg2) {}

IRIfLessThanGotoI::IRIfLessThanGotoI(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRIfLessThanGoto(newResult, newArg1, newArg2) {}

IRIfLessThanGotoF::IRIfLessThanGotoF(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRIfLessThanGoto(newResult, newArg1, newArg2) {}

IRIfLessThanGotoD::IRIfLessThanGotoD(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRIfLessThanGoto(newResult, newArg1, newArg2) {}

IRIfLessEqualThanGoto::IRIfLessEqualThanGoto(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRCode(IROperation::IF_LESS_EQUAL_THAN_GOTO, newResult, newArg1, newArg2) {}

IRIfLessEqualThanGotoI::IRIfLessEqualThanGotoI(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRIfLessEqualThanGoto(newResult, newArg1, newArg2) {}

IRIfLessEqualThanGotoF::IRIfLessEqualThanGotoF(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRIfLessEqualThanGoto(newResult, newArg1, newArg2) {}

IRIfLessEqualThanGotoD::IRIfLessEqualThanGotoD(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRIfLessEqualThanGoto(newResult, newArg1, newArg2) {}

IRGoto::IRGoto(IROperand *newLabel)
        : IRCode(IROperation::GOTO, newLabel, nullptr, nullptr) {}

IRPhi::IRPhi(IROperand *newResult, IROperand *newArg1, IROperand *newArg2)
        : IRCode(IROperation::PHI, newResult, newArg1, newArg2) {}

void IRAddLabel::print() const {
    cout << getArg1()->getSymbolName() << ":" << endl;
}

void IRAddParam::print() const {
    cout << "addparam " << getArg1()->getSymbolName() << ";" << endl;
}

void IRGetParam::print() const {
    cout << getResult()->getSymbolName() << " = " << " param "
         << ";" << endl;
}

void IRCall::print() const {
    cout << "call "
         << getArg1()->getSymbolName() << "; " << endl;

}

void IRReturn::print() const {
    cout << "return ";
    if (getArg1()) {
        cout << getArg1()->getSymbolName();
    }
    cout << ";" << endl;
}

void IRGetReturn::print() const {
    cout << getResult()->getSymbolName() << " = " << " return "
         << ";" << endl;
}

void IRAssign::print() const {
    cout << getResult()->getSymbolName() << " = "
         << getArg1()->getSymbolName() << ";" << endl;
}

void IRFetchArrayElem::print() const {
    cout << getResult()->getSymbolName() << " = "
         << getArg1()->getSymbolName() << "["
         << getArg2()->getSymbolName() << "];" <<endl;
}

void IRAssignArrayElem::print() const {
    cout << getArg1()->getSymbolName() << "["
         << getArg2()->getSymbolName() << "] = "
         << getResult()->getSymbolName() << ";"<<endl;
}

void IRAdd::print() const {
    cout << getResult()->getSymbolName() << " = "
         << getArg1()->getSymbolName() << " + "
         << getArg2()->getSymbolName() << ";" << endl;
}

void IRSub::print() const {
    cout << getResult()->getSymbolName() << " = "
         << getArg1()->getSymbolName() << " - "
         << getArg2()->getSymbolName() << ";" << endl;
}

void IRNeg::print() const {
    cout << getResult()->getSymbolName() << " = "
         << " - "
         << getArg1()->getSymbolName() << ";" << endl;
}

void IRMul::print() const {
    cout << getResult()->getSymbolName() << " = "
         << getArg1()->getSymbolName() << " * "
         << getArg2()->getSymbolName() << ";" << endl;
}

void IRDiv::print() const {
    cout << getResult()->getSymbolName() << " = "
         << getArg1()->getSymbolName() << " / "
         << getArg2()->getSymbolName() << ";" << endl;
}

void IRMod::print() const {
    cout << getResult()->getSymbolName() << " = "
         << getArg1()->getSymbolName() << " % "
         << getArg2()->getSymbolName() << ";" << endl;
}

void IRNot::print() const {
    cout << getResult()->getSymbolName() << " = not"
         << getArg1()->getSymbolName() << ";" << endl;
}

void IRIfEqualGoto::print() const {
    cout << "If "
         << getArg1()->getSymbolName() << " == "
         << getArg2()->getSymbolName()
         << " Goto " << getResult()->getSymbolName() << ";" << endl;
}

void IRIfNotEqualGoto::print() const {
    cout << "If "
         << getArg1()->getSymbolName() << " != "
         << getArg2()->getSymbolName()
         << " Goto " << getResult()->getSymbolName() << ";" << endl;
}

void IRIfGreaterThanGoto::print() const {
    cout << "if "
         << getArg1()->getSymbolName() << " > "
         << getArg2()->getSymbolName()
         << " Goto " << getResult()->getSymbolName() << ";" << endl;
}

void IRIfGreaterEqualThanGoto::print() const {
    cout << "if "
         << getArg1()->getSymbolName() << " >= "
         << getArg2()->getSymbolName()
         << " Goto " << getResult()->getSymbolName() << ";" << endl;
}

void IRIfLessThanGoto::print() const {
    cout << "if "
         << getArg1()->getSymbolName() << " < "
         << getArg2()->getSymbolName()
         << " Goto " << getResult()->getSymbolName() << ";" << endl;
}

void IRIfLessEqualThanGoto::print() const {
    cout << "if "
         << getArg1()->getSymbolName() << " <= "
         << getArg2()->getSymbolName()
         << " Goto " << getResult()->getSymbolName() << ";" << endl;
}

void IRPhi::print() const {
    cout << getResult()->getSymbolName() << " = phi("
         << getArg1()->getSymbolName() << ","
         << getArg2()->getSymbolName() << ")";
}
//
//void IRAddLabel::genTargetCode(TargetCodeList *t) {
//    t->add(getArg1()->getImme() + string(":"));
//}
//
//void IRAddParamI::genTargetCode(TargetCodeList *t) {
//    getArg1()->loadTo(t, t->getRegParamX());
//}
//
//void IRAddParamF::genTargetCode(TargetCodeList *t) {
//    getArg1()->loadTo(t, t->getRegParamF());
//}
//
//void IRAddParamD::genTargetCode(TargetCodeList *t) {
//    getArg1()->loadTo(t, t->getRegParamF());
//}
//
//void IRGetParamI::genTargetCode(TargetCodeList *t) {
//    getResult()->storeFrom(t, t->getRegGetParamX());
//}
//
//void IRGetParamF::genTargetCode(TargetCodeList *t) {
//    getResult()->storeFrom(t, t->getRegGetParamF());
//}
//
//void IRGetParamD::genTargetCode(TargetCodeList *t) {
//    getResult()->storeFrom(t, t->getRegGetParamF());
//}
//
//void IRCall::genTargetCode(TargetCodeList *t) {
//    t->resetRegParam();
//    t->add(string("\tcall\t") + getArg1()->getImme());
//}
//
//void IRReturnI::genTargetCode(TargetCodeList *t) {
//    getArg1()->loadTo(t, "a0");
//}
//
//void IRReturnF::genTargetCode(TargetCodeList *t) {
//    getArg1()->loadTo(t, "fa0");
//}
//
//void IRReturnD::genTargetCode(TargetCodeList *t) {
//    getArg1()->loadTo(t, "fa0");
//}
//
//void IRGetReturnI::genTargetCode(TargetCodeList *t) {
//    getResult()->storeFrom(t, "a0");
//}
//
//void IRGetReturnF::genTargetCode(TargetCodeList *t) {
//    getResult()->storeFrom(t, "fa0");
//}
//
//void IRGetReturnD::genTargetCode(TargetCodeList *t) {
//    getResult()->storeFrom(t, "fa0");
//}
//
//void IRAssignI::genTargetCode(TargetCodeList *t) {
//    getArg1()->loadTo(t, "t4");
//    getResult()->storeFrom(t, "t4");
//}
//
//void IRAssignF::genTargetCode(TargetCodeList *t) {
//    getArg1()->loadTo(t, "ft4");
//    getResult()->storeFrom(t, "ft4");
//}
//
//void IRAssignD::genTargetCode(TargetCodeList *t) {
//    getArg1()->loadTo(t, "ft4");
//    getResult()->storeFrom(t, "ft4");
//}
//
//void IRAddI::genTargetCode(TargetCodeList *t) {
//    getArg1()->loadTo(t, "t5");
//    getArg2()->loadTo(t, "t6");
//    t->add(string("\tadd\tt4, t5, t6"));
//    getResult()->storeFrom(t, "t4");
//}
//
//void IRAddF::genTargetCode(TargetCodeList *t) {
//    getArg1()->loadTo(t, "ft5");
//    getArg2()->loadTo(t, "ft6");
//    t->add(string("\tfadd.s\tft4, ft5, ft6"));
//    getResult()->storeFrom(t, "ft4");
//}
//
//void IRAddD::genTargetCode(TargetCodeList *t) {
//    getArg1()->loadTo(t, "ft5");
//    getArg2()->loadTo(t, "ft6");
//    t->add(string("\tfadd.d\tft4, ft5, ft6"));
//    getResult()->storeFrom(t, "ft4");
//}
//
//void IRSubI::genTargetCode(TargetCodeList *t) {
//    getArg1()->loadTo(t, "t5");
//    getArg2()->loadTo(t, "t6");
//    t->add(string("\tsub\tt4, t5, t6"));
//    getResult()->storeFrom(t, "t4");
//}
//
//void IRSubF::genTargetCode(TargetCodeList *t) {
//    getArg1()->loadTo(t, "ft5");
//    getArg2()->loadTo(t, "ft6");
//    t->add(string("\tfsub.s\tft4, ft5, ft6"));
//    getResult()->storeFrom(t, "ft4");
//}
//
//void IRSubD::genTargetCode(TargetCodeList *t) {
//    getArg1()->loadTo(t, "ft5");
//    getArg2()->loadTo(t, "ft6");
//    t->add(string("\tfsub.d\tft4, ft5, ft6"));
//    getResult()->storeFrom(t, "ft4");
//}
//
//void IRNegI::genTargetCode(TargetCodeList *t) {
//    getArg1()->loadTo(t, "t5");
//    t->add(string("\tneg\tt4, t5"));
//    getResult()->storeFrom(t, "t4");
//}
//
//void IRNegF::genTargetCode(TargetCodeList *t) {
//    getArg1()->loadTo(t, "ft5");
//    t->add(string("\tfneg.s\tft4, ft5"));
//    getResult()->storeFrom(t, "ft4");
//}
//
//void IRNegD::genTargetCode(TargetCodeList *t) {
//    getArg1()->loadTo(t, "ft5");
//    t->add(string("\tfneg.d\tft4, ft5"));
//    getResult()->storeFrom(t, "ft4");
//}
//
//void IRMulI::genTargetCode(TargetCodeList *t) {
//    getArg1()->loadTo(t, "t5");
//    getArg2()->loadTo(t, "t6");
//    t->add(string("\tmul\tt4, t5, t6"));
//    getResult()->storeFrom(t, "t4");
//}
//
//void IRMulF::genTargetCode(TargetCodeList *t) {
//    getArg1()->loadTo(t, "ft5");
//    getArg2()->loadTo(t, "ft6");
//    t->add(string("\tfmul.s\tft4, ft5, ft6"));
//    getResult()->storeFrom(t, "ft4");
//}
//
//void IRMulD::genTargetCode(TargetCodeList *t) {
//    getArg1()->loadTo(t, "ft5");
//    getArg2()->loadTo(t, "ft6");
//    t->add(string("\tfmul.d\tft4, ft5, ft6"));
//    getResult()->storeFrom(t, "ft4");
//}
//
//void IRDivI::genTargetCode(TargetCodeList *t) {
//    getArg1()->loadTo(t, "t5");
//    getArg2()->loadTo(t, "t6");
//    t->add(string("\tdiv\tt4, t5, t6"));
//    getResult()->storeFrom(t, "t4");
//}
//
//void IRDivF::genTargetCode(TargetCodeList *t) {
//    getArg1()->loadTo(t, "ft5");
//    getArg2()->loadTo(t, "ft6");
//    t->add(string("\tfdiv.s\tft4, ft5, ft6"));
//    getResult()->storeFrom(t, "ft4");
//}
//
//void IRDivD::genTargetCode(TargetCodeList *t) {
//    getArg1()->loadTo(t, "ft5");
//    getArg2()->loadTo(t, "ft6");
//    t->add(string("\tfdiv.d\tft4, ft5, ft6"));
//    getResult()->storeFrom(t, "ft4");
//}
//
//void IRMod::genTargetCode(TargetCodeList *t) {
//    getArg1()->loadTo(t, "t5");
//    getArg2()->loadTo(t, "t6");
//    t->add(string("\trem\tt4, t5, t6"));
//    getResult()->storeFrom(t, "t4");
//}
//
//void IRNot::genTargetCode(TargetCodeList *t) {
//    getArg1()->loadTo(t, "t5");
//    t->add(string("\tnot\tt4, t5"));
//    getResult()->storeFrom(t, "t4");
//}
//
//void IRIfEqualGotoI::genTargetCode(TargetCodeList *t) {
//    getArg1()->loadTo(t, "t5");
//    getArg2()->loadTo(t, "t6");
//    t->add(string("\tbeq\tt5, t6, ") + getResult()->getImme());
//}
//
//void IRIfEqualGotoF::genTargetCode(TargetCodeList *t) {
//    getArg1()->loadTo(t, "ft5");
//    getArg2()->loadTo(t, "ft6");
//    t->add(string("\tfeq.s\tt4, ft5, ft6") + getResult()->getImme());
//    t->add(string("\tbnez\tt4, ") + getResult()->getImme());
//}
//
//void IRIfEqualGotoD::genTargetCode(TargetCodeList *t) {
//    getArg1()->loadTo(t, "ft5");
//    getArg2()->loadTo(t, "ft6");
//    t->add(string("\tfeq.d\tt4, ft5, ft6") + getResult()->getImme());
//    t->add(string("\tbnez\tt4, ") + getResult()->getImme());
//}
//
//void IRIfGreaterThanGotoI::genTargetCode(TargetCodeList *t) {
//    getArg1()->loadTo(t, "t5");
//    getArg2()->loadTo(t, "t6");
//    t->add(string("\tbgt\tt5, t6, ") + getResult()->getImme());
//}
//
//void IRIfGreaterThanGotoF::genTargetCode(TargetCodeList *t) {
//    getArg1()->loadTo(t, "ft5");
//    getArg2()->loadTo(t, "ft6");
//    t->add(string("\tfgt.s\tt4, ft5, ft6") + getResult()->getImme());
//    t->add(string("\tbnez\tt4, ") + getResult()->getImme());
//}
//
//void IRIfGreaterThanGotoD::genTargetCode(TargetCodeList *t) {
//    getArg1()->loadTo(t, "ft5");
//    getArg2()->loadTo(t, "ft6");
//    t->add(string("\tfgt.d\tt4, ft5, ft6") + getResult()->getImme());
//    t->add(string("\tbnez\tt4, ") + getResult()->getImme());
//}
//
//void IRIfGreaterEqualThanGotoI::genTargetCode(TargetCodeList *t) {
//    getArg1()->loadTo(t, "t5");
//    getArg2()->loadTo(t, "t6");
//    t->add(string("\tbge\tt5, t6, ") + getResult()->getImme());
//}
//
//void IRIfGreaterEqualThanGotoF::genTargetCode(TargetCodeList *t) {
//    getArg1()->loadTo(t, "ft5");
//    getArg2()->loadTo(t, "ft6");
//    t->add(string("\tfge.s\tt4, ft5, ft6") + getResult()->getImme());
//    t->add(string("\tbnez\tt4, ") + getResult()->getImme());
//}
//
//void IRIfGreaterEqualThanGotoD::genTargetCode(TargetCodeList *t) {
//    getArg1()->loadTo(t, "ft5");
//    getArg2()->loadTo(t, "ft6");
//    t->add(string("\tfge.d\tt4, ft5, ft6") + getResult()->getImme());
//    t->add(string("\tbnez\tt4, ") + getResult()->getImme());
//}
//
//void IRIfLessThanGotoI::genTargetCode(TargetCodeList *t) {
//    getArg1()->loadTo(t, "t5");
//    getArg2()->loadTo(t, "t6");
//    t->add(string("\tblt\tt5, t6, ") + getResult()->getImme());
//}
//
//void IRIfLessThanGotoF::genTargetCode(TargetCodeList *t) {
//    getArg1()->loadTo(t, "ft5");
//    getArg2()->loadTo(t, "ft6");
//    t->add(string("\tflt.s\tt4, ft5, ft6") + getResult()->getImme());
//    t->add(string("\tbnez\tt4, ") + getResult()->getImme());
//}
//
//void IRIfLessThanGotoD::genTargetCode(TargetCodeList *t) {
//    getArg1()->loadTo(t, "ft5");
//    getArg2()->loadTo(t, "ft6");
//    t->add(string("\tflt.d\tt4, ft5, ft6") + getResult()->getImme());
//    t->add(string("\tbnez\tt4, ") + getResult()->getImme());
//}
//
//void IRIfLessEqualThanGotoI::genTargetCode(TargetCodeList *t) {
//    getArg1()->loadTo(t, "t5");
//    getArg2()->loadTo(t, "t6");
//    t->add(string("\tble\tt5, t6, ") + getResult()->getImme());
//}
//
//void IRIfLessEqualThanGotoF::genTargetCode(TargetCodeList *t) {
//    getArg1()->loadTo(t, "ft5");
//    getArg2()->loadTo(t, "ft6");
//    t->add(string("\tfle.s\tt4, ft5, ft6") + getResult()->getImme());
//    t->add(string("\tbnez\tt4, ") + getResult()->getImme());
//}
//
//void IRIfLessEqualThanGotoD::genTargetCode(TargetCodeList *t) {
//    getArg1()->loadTo(t, "ft5");
//    getArg2()->loadTo(t, "ft6");
//    t->add(string("\tfle.d\tt4, ft5, ft6") + getResult()->getImme());
//    t->add(string("\tbnez\tt4, ") + getResult()->getImme());
//}