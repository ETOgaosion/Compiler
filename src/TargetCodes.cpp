//
// Created by 蓝色空间 on 2022/5/22.
//

#include "TargetCodes.h"

#include <utility>
#include <fstream>
#include <algorithm>

using namespace std;

Code::Code(ASMOperation newOp, Cond newCond, std::vector<Register *> newRegList) {
    op = newOp;
    cond = newCond;
    regList = move(newRegList);
}

Code::Code(ASMOperation newOp, Cond newCond, Register *newRd, Register *newRn, Register *newRm, ShiftWay newShiftWay, Register *newRs, int newOffset, std::string newLabel, vector<Options> newOptions) {
    op = newOp;
    cond = newCond;
    rd = newRd;
    rn = newRn;
    rm = newRm;
    shiftWay = newShiftWay;
    rs = newRs;
    regList.clear();
    offset = newOffset;
    label = move(newLabel);
    directives = {};
    extraOptions = move(newOptions);
}

Code::Code(ASMOperation newOp, Register *newRd, Register *newRn, Register *newRm) {
    op = newOp;
    cond = Cond::NONE;
    rd = newRd;
    rn = newRn;
    rm = newRm;
    shiftWay = ShiftWay::NONE;
    rs = nullptr;
    regList.clear();
    offset = 0;
    label = {};
    directives = {};
    extraOptions.clear();
}

Code::Code(ASMOperation newOp, Register *newRd, Register *newRn, int newOffset) {
    op = newOp;
    cond = Cond::NONE;
    rd = newRd;
    rn = newRn;
    rm = nullptr;
    shiftWay = ShiftWay::NONE;
    rs = nullptr;
    regList.clear();
    offset = newOffset;
    label = {};
    directives = {};
    extraOptions.clear();
}

Code::Code(ASMOperation newOp, std::string newLabel, string newDirectives) {
    op = newOp;
    cond = Cond::NONE;
    rd = nullptr;
    rn = nullptr;
    rm = nullptr;
    shiftWay = ShiftWay::NONE;
    rs = nullptr;
    regList.clear();
    offset = 0;
    label = move(newLabel);
    directives = move(newDirectives);
    extraOptions.clear();
}

string Code::condToString(Cond inCond) {
    switch (inCond) {
        case Cond::EQ:
            return "eq";
        case Cond::NE:
            return "ne";
        case Cond::GE:
            return "ge";
        case Cond::LE:
            return "le";
        case Cond::GT:
            return "gt";
        case Cond::LT:
            return "lt";
        default:
            return "";
    }
}

bool Code::isImm8(int offset) {
    if (offset < 0) {
        offset = -offset;
    }
    int scanner = 0x1, highestBit = 0, lowestBit = 0;
    for (int i = 31; i >= 0; i--) {
        if (offset & (scanner << i)) {
            highestBit = i;
            break;
        }
    }
    for (int i = 0; i < 32; i++) {
        if (offset & (scanner << i)) {
            lowestBit = i;
            break;
        }
    }
    bool midAllZeror = true;
    for (int i = lowestBit + 1; i < highestBit; i++) {
        if (offset & (scanner << i)) {
            midAllZeror = false;
            break;
        }
    }
    if (lowestBit == highestBit) {
        midAllZeror = false;
    }
    if (midAllZeror) {
        return 33 - highestBit + lowestBit <= 8;
    }
    else {
        return highestBit - lowestBit + 1 <= 8;
    }
}

void Code::print() const {
    switch (op) {
        case ASMOperation::ADD:
            if (!rm && !Code::isImm8(offset)) {
                cout << "\tldr\t" << rd->getAliasName() << ", =" << offset << endl;
                cout << "\tadd\t" << rd->getAliasName() << ", " << rn->getAliasName() << ", " << rd->getAliasName() << endl;
            }
            else {
                switch (rd->getRegisterType()) {
                    case RegisterType::GENERAL_PURPOSE:
                        cout << "\tadd";
                        break;
                    case RegisterType::FLOAT_POINT:
                        cout << "\tvadd";
                        break;
                    default:
                        break;
                }
                cout << Code::condToString(cond) << "\t";
                cout << rd->getAliasName() << ", " << rn->getAliasName() << ", ";
                if (rm) {
                    cout << rm->getAliasName() << endl;
                }
                else {
                    cout << "#" << offset << endl;  // 0~4095
                }
            }
            break;
        case ASMOperation::SUB:
            if (find(extraOptions.begin(), extraOptions.end(), Options::REVERSE_OP) == extraOptions.end()) {
                if (!rm && !Code::isImm8(offset)) {
                    cout << "\tldr\t" << rd->getAliasName() << ", =" << offset << endl;
                    cout << "\tsub\t" << rd->getAliasName() << ", " << rn->getAliasName() << ", " << rd->getAliasName() << endl;
                }
                else {
                    switch (rd->getRegisterType()) {
                        case RegisterType::GENERAL_PURPOSE:
                            cout << "\tsub";
                            break;
                        case RegisterType::FLOAT_POINT:
                            cout << "\tvsub";
                            break;
                    }
                    cout << Code::condToString(cond) << "\t";
                    cout << rd->getAliasName() << ", " << rn->getAliasName() << ", ";
                    if (rm) {
                        cout << rm->getAliasName() << endl;
                    } else {
                        cout << "#" << offset << endl;  // 0~4095
                    }
                }
            }
            else {
                if (!Code::isImm8(offset)) {
                    cout << "\tldr\t" << rd->getAliasName() << ", =" << offset << endl;
                    cout << "\trsb\t" << rd->getAliasName() << ", " << rn->getAliasName() << ", " << rd->getAliasName() << endl;
                }
                else {
                    cout << "\trsb\t" << rd->getAliasName() << ", " << rn->getAliasName() << ", #" << offset << endl;
                }
            }
            break;
        case ASMOperation::MUL:
            switch (rd->getRegisterType()) {
                case RegisterType::GENERAL_PURPOSE:
                    cout << "\tmul\t";
                    break;
                case RegisterType::FLOAT_POINT:
                    cout << "\tvmul\t";
                    break;
            }
            cout << rd->getAliasName() << ", " << rn->getAliasName() << ", " << rm->getAliasName() << endl;
            break;
        case ASMOperation::DIV:
            switch (rd->getRegisterType()) {
                case RegisterType::GENERAL_PURPOSE:
                    cout << "\tsdiv\t";
                    break;
                case RegisterType::FLOAT_POINT:
                    cout << "\tvdiv.f32\t";
                    break;
            }
            cout << rd->getAliasName() << ", " << rn->getAliasName() << ", " << rm->getAliasName() << endl;
            break;
        case ASMOperation::LSL:
            if (!rm && !Code::isImm8(offset)) {
                cout << "\tldr\t" << rd->getAliasName() << ", =" << offset << endl;
                cout << "\tlsl\t" << rd->getAliasName() << ", " << rn->getAliasName() << ", " << rd->getAliasName() << endl;
            }
            else {
                cout << "\tlsl\t" << rd->getAliasName() << ", " << rn->getAliasName() << ", ";
                if (rm) {
                    cout << rm->getAliasName() << endl;
                }
                else {
                    cout << "#" << offset << endl;  // 0~31
                }
            }
            break;
        case ASMOperation::ASR:
            if (!rm && !Code::isImm8(offset)) {
                cout << "\tldr\t" << rd->getAliasName() << ", =" << offset << endl;
                cout << "\tasr\t" << rd->getAliasName() << ", " << rn->getAliasName() << ", " << rd->getAliasName() << endl;
            }
            else {
                cout << "\tasr\t" << rd->getAliasName() << ", " << rn->getAliasName() << ", ";
                if (rm) {
                    cout << rm->getAliasName() << endl;
                }
                else {
                    cout << "#" << offset << endl;  // 0~31
                }
            }
            break;
        case ASMOperation::ORR:
            if (!rm && !Code::isImm8(offset)) {
                cout << "\tldr\t" << rd->getAliasName() << ", =" << offset << endl;
                cout << "\torr\t" << rd->getAliasName() << ", " << rn->getAliasName() << ", " << rd->getAliasName() << endl;
            }
            else {
                cout << "\torr\t" << rd->getAliasName() << ", " << rn->getAliasName() << ", ";
                if (rm) {
                    cout << rm->getAliasName() << endl;
                }
                else {
                    cout << "#" << offset << endl;  // 0~4095
                }
            }
            break;
        case ASMOperation::AND:
            if (!rm && !Code::isImm8(offset)) {
                cout << "\tldr\t" << rd->getAliasName() << ", =" << offset << endl;
                cout << "\tand\t" << rd->getAliasName() << ", " << rn->getAliasName() << ", " << rd->getAliasName() << endl;
            }
            else {
                cout << "\tand\t" << rd->getAliasName() << ", " << rn->getAliasName() << ", ";
                if (rm) {
                    cout << rm->getAliasName() << endl;
                }
                else {
                    cout << "#" << offset << endl;  // 0~4095
                }
            }
            break;
        case ASMOperation::EOR:
            if (!rm && !Code::isImm8(offset)) {
                cout << "\tldr\t" << rd->getAliasName() << ", =" << offset << endl;
                cout << "\teor\t" << rd->getAliasName() << ", " << rn->getAliasName() << ", " << rd->getAliasName() << endl;
            }
            else {
                cout << "\teor\t" << rd->getAliasName() << ", " << rn->getAliasName() << ", ";
                if (rm) {
                    cout << rm->getAliasName() << endl;
                }
                else {
                    cout << "#" << offset << endl;  // 0~4095
                }
            }
            break;
        case ASMOperation::TST:
            cout << "\ttst\t" << rn->getAliasName() << ", ";
            if (rm) {
                cout << rm->getAliasName() << endl;     // do not use sp or pc
            }
            else {
                cout << "#" << offset << endl;  // 0~4095
            }
            break;
        case ASMOperation::TEQ:
            cout << "\tteq\t" << rn->getAliasName() << ", ";
            if (rm) {
                cout << rm->getAliasName() << endl;     // do not use sp or pc
            }
            else {
                cout << "#" << offset << endl;  // 0~4095
            }
            break;
        case ASMOperation::CMP:
            cout << "\tcmp\t" << rn->getAliasName() << ", ";
            if (rm) {
                cout << rm->getAliasName() << endl;     // do not use sp or pc
            }
            else {
                cout << "#" << offset << endl;  // 0~4095
            }
            break;
        case ASMOperation::CMN:
            cout << "\tcmn\t" << rn->getAliasName() << ", ";
            if (rm) {
                cout << rm->getAliasName() << endl;     // do not use sp or pc
            }
            else {
                cout << "#" << offset << endl;  // 0~4095
            }
            break;
        case ASMOperation::VCMP:
            cout << "\tvcmp\t" << rd->getAliasName() << "," << rm->getAliasName() << endl;
            break;
        case ASMOperation::CBZ:
            cout << "\tcbz\t" << rn->getAliasName() << "," << label << endl;
            break;
        case ASMOperation::CBNZ:
            cout << "\tcbz\t" << rn->getAliasName() << "," << label << endl;
            break;
        case ASMOperation::B:
            cout << "\tb\t" << label << endl;
            break;
        case ASMOperation::BEQ:
            cout << "\tbeq\t" << label << endl;
            break;
        case ASMOperation::BNE:
            cout << "\tbne\t" << label << endl;
            break;
        case ASMOperation::BGE:
            cout << "\tbge\t" << label << endl;
            break;
        case ASMOperation::BLE:
            cout << "\tble\t" << label << endl;
            break;
        case ASMOperation::BGT:
            cout << "\tbgt\t" << label << endl;
            break;
        case ASMOperation::BLT:
            cout << "\tblt\t" << label << endl;
            break;
        case ASMOperation::ADR:
            cout << "\tadr" << Code::condToString(cond) << "\t" << rd->getAliasName() << ", " << label << endl;
            break;
        case ASMOperation::LDR:
            cout << "\tldr" << Code::condToString(cond) << "\t" << rd->getAliasName() << ", ";
            if (rn) {
                if (!rm) {
                    if (offset) {
                        if (find(extraOptions.begin(), extraOptions.end(), Options::POST_INDEX_OFFSET) == extraOptions.end()) {
                            cout << "[" << rn->getAliasName() << ", #" << offset << "]" << endl;
                        } else {
                            cout << "[" << rn->getAliasName() << "], #" << offset << endl;
                        }
                    }
                    else {
                        cout << "[" << rn->getAliasName() << "]" <<endl;
                    }
                }
                else {
                    cout << "[" << rn->getAliasName() << ", ";
                    if (find(extraOptions.begin(), extraOptions.end(), Options::RM_NEGATIVE) == extraOptions.end()) {
                        cout << "-";
                    }
                    else {
                        cout << "+";
                    }
                    cout << rm->getAliasName();
                    if (offset) {
                        cout << ", #" << offset;
                    }
                    cout << "]" << endl;
                }
            }
            else if (!label.empty()) {
                if (find(extraOptions.begin(), extraOptions.end(), Options::LABEL_AS_VAL) != extraOptions.end()) {
                    cout << "=";
                }
                cout << label << endl;
            }
            else {
                cout << "=" << offset << endl;
            }
            break;
        case ASMOperation::VLDR:
            cout << "\tldr\t" << rd->getAliasName() << ", ";
            if (rn) {
                if (offset) {
                    if (find(extraOptions.begin(), extraOptions.end(), Options::POST_INDEX_OFFSET) == extraOptions.end()) {
                        cout << "[" << rn->getAliasName() << ", #" << offset << "]" << endl;
                    } else {
                        cout << "[" << rn->getAliasName() << "], #" << offset << endl;
                    }
                }
                else {
                    cout << "[" << rn->getAliasName() << "]" <<endl;
                }
            }
            else if (!label.empty()) {
                cout << label << endl;
            }
            break;
        case ASMOperation::STR:
            cout << "\tstr\t" << rn->getAliasName() << ", ";
            if (rd) {
                if (offset) {
                    if (find(extraOptions.begin(), extraOptions.end(), Options::POST_INDEX_OFFSET) == extraOptions.end()) {
                        cout << "[" << rd->getAliasName() << ", #" << offset << "]" << endl;
                    } else {
                        cout << "[" << rd->getAliasName() << "], #" << offset << endl;
                    }
                }
                else {
                    cout << "[" << rd->getAliasName() << "]" <<endl;
                }
            }
            else if (!label.empty()) {
                cout << label << endl;
            }
            break;
        case ASMOperation::VSTR:
            cout << "\tvstr\t" << rd->getAliasName() << ", ";
            if (rn) {
                if (offset) {
                    if (find(extraOptions.begin(), extraOptions.end(), Options::POST_INDEX_OFFSET) == extraOptions.end()) {
                        cout << "[" << rn->getAliasName() << ", #" << offset << "]" << endl;
                    } else {
                        cout << "[" << rn->getAliasName() << "], #" << offset << endl;
                    }
                }
                else {
                    cout << "[" << rn->getAliasName() << "]" <<endl;
                }
            }
            else if (!label.empty()) {
                cout << label << endl;
            }
            break;
        case ASMOperation::MV:
            if (rd->getRegisterType() == RegisterType::GENERAL_PURPOSE) {
                if (rm) {
                    if (rm->getRegisterType() == RegisterType::GENERAL_PURPOSE) {
                        cout << "\tmov\t" << rd->getAliasName() << ", " << rm->getAliasName() << endl;
                    }
                }
                else {
                    if (rn) {
                        cout << "\tvmov\t" << rd->getAliasName() << ", " << rn->getAliasName() << endl;
                        cout << "\tvcvt.f32.s32\t" << rd->getAliasName() << ", " << rd->getAliasName() << endl;
                    }
                    else {
                        if (!Code::isImm8(offset)) {
                            cout << "\tldr\t" << rd->getAliasName() << ", =" << offset << endl;
                        }
                        else {
                            cout << "\tmov\t" << rd->getAliasName() << ", #" << offset << endl;
                        }
                    }
                }
            }
            else {
                if (rm) {
                    if (rm->getRegisterType() == RegisterType::FLOAT_POINT) {
                        cout << "\tvmov.f32\t" << rd->getAliasName() << ", " << rm->getAliasName() << endl;
                    }
                }
                else {
                    if (rn) {
                        cout << "\tvcvt.s32.f32\t" << rn->getAliasName() << ", " << rn->getAliasName() << endl;
                        cout << "\tvmov\t" << rd->getAliasName() << ", " << rn->getAliasName() << endl;
                    }
                    else {
                        cout << "\tvmov\t" << rd->getAliasName() << ", #" << offset << endl;
                    }
                }
            }
            break;
        case ASMOperation::LABEL:
            cout << label << ":" << endl;
            break;
        case ASMOperation::BL:
            cout << "\tbl\t" << label << endl;
            break;
        case ASMOperation::PUSH:
            cout << "\tpush\t{";
            for (int i = 0; i < regList.size() - 1; i++) {
                cout << regList[i]->getAliasName() << ",";
            }
            cout << regList.back()->getAliasName() << "}" << endl;
            break;
        case ASMOperation::POP:
            cout << "\tpop\t{";
            for (int i = 0; i < regList.size() - 1; i++) {
                cout << regList[i]->getAliasName() << ",";
            }
            cout << regList.back()->getAliasName() << "}" << endl;
            break;
        case ASMOperation::DIRECTIVE:
            cout << directives << endl;
            break;
        default:
            break;
    }
}

TargetCodes::TargetCodes() {}

TargetCodes *TargetCodes::getTargetCodes() {
    static TargetCodes instance;
    static bool initialized = false;
    if (!initialized) {
        instance.codeList.clear();
        instance.generalPurposeRegisters = new GeneralPurposeRegisters();
        instance.floatPointRegisters = new FloatPointRegisters();
        initialized = true;
    }
    return &instance;
}

bool TargetCodes::addCode(Code *newCode) {
    codeList.emplace_back(newCode);
    return true;
}

bool TargetCodes::addCodes(const vector<Code *>& newCodes) {
    for (auto &code : newCodes) {
        codeList.emplace_back(code);
    }
    return true;
}

void TargetCodes::printCode() const {
    for (auto &code : codeList) {
        code->print();
    }
}

void TargetCodes::codeWrite(string path) const {
    ofstream out;
    out.open(path, ios_base::out);
    streambuf *coutbuf = cout.rdbuf();
    cout.rdbuf(out.rdbuf());
    for (auto &code : codeList) {
        code->print();
    }
    cout.rdbuf(coutbuf);
}

Register *TargetCodes::getNextFreeRegister(bool isGeneralPurposeRegister, bool isParam, bool &hasFreeRegister) {
    if (isGeneralPurposeRegister) {
        return generalPurposeRegisters->getNextFreeRegister(isParam, hasFreeRegister);
    }
    else {
        return floatPointRegisters->getNextFreeRegister(isParam, hasFreeRegister);
    }
}

Register *TargetCodes::getNextAvailableRegister(bool isGeneralPurposeRegister, bool isParam, bool &hasFreeRegister) {
    if (isGeneralPurposeRegister) {
        return generalPurposeRegisters->getNextAvailableRegister(isParam, hasFreeRegister);
    }
    else {
        return floatPointRegisters->getNextAvailableRegister(isParam, hasFreeRegister);
    }
}

Register *TargetCodes::tryGetCertainRegister(bool isGeneralPurposeRegister, const string &regName, bool &isFreeRegister) {
    if (isGeneralPurposeRegister) {
        return generalPurposeRegisters->tryGetCertainRegister(regName, isFreeRegister);
    }
    else {
        return floatPointRegisters->tryGetCertainRegister(regName, isFreeRegister);
    }
}

bool TargetCodes::setRegisterFree(bool isGeneralPurposeRegister, const string &reg) {
    if (isGeneralPurposeRegister) {
        return generalPurposeRegisters->setRegisterFree(reg);
    }
    else {
        return floatPointRegisters->setRegisterFree(reg);
    }
}

bool TargetCodes::setRegisterAvailable(bool isGeneralPurposeRegister, const string &reg) {
    if (isGeneralPurposeRegister) {
        return generalPurposeRegisters->setRegisterAvailable(reg);
    }
    else {
        return floatPointRegisters->setRegisterAvailable(reg);
    }
}

bool TargetCodes::setRegisterFree(Register *reg) {
    if (reg->getRegisterType() == RegisterType::GENERAL_PURPOSE) {
        return generalPurposeRegisters->setRegisterFree(reg->getAliasName());
    }
    else {
        return floatPointRegisters->setRegisterFree(reg->getAliasName());
    }
}

bool TargetCodes::setRegisterAvailable(Register *reg) {
    if (reg->getRegisterType() == RegisterType::GENERAL_PURPOSE) {
        return generalPurposeRegisters->setRegisterAvailable(reg->getAliasName());
    }
    else {
        return floatPointRegisters->setRegisterAvailable(reg->getAliasName());
    }
}

bool TargetCodes::setRegistersFree(bool isGeneralPurposeRegister, const vector<string> &registers) {
    if (isGeneralPurposeRegister) {
        return generalPurposeRegisters->setRegistersFree(registers);
    }
    else {
        return floatPointRegisters->setRegistersFree(registers);
    }
}

bool TargetCodes::setRegistersAvailable(bool isGeneralPurposeRegister, const vector<string> &registers) {
    if (isGeneralPurposeRegister) {
        return generalPurposeRegisters->setRegistersAvailable(registers);
    }
    else {
        return floatPointRegisters->setRegistersAvailable(registers);
    }
}

bool TargetCodes::setRegistersFree(bool isGeneralPurposeRegister, const vector<Register *> &registers) {
    if (isGeneralPurposeRegister) {
        return generalPurposeRegisters->setRegistersFree(registers);
    }
    else {
        return floatPointRegisters->setRegistersFree(registers);
    }
}

bool TargetCodes::setRegistersAvailable(bool isGeneralPurposeRegister, const vector<Register *> &registers) {
    if (isGeneralPurposeRegister) {
        return generalPurposeRegisters->setRegistersAvailable(registers);
    }
    else {
        return floatPointRegisters->setRegistersAvailable(registers);
    }
}

bool TargetCodes::setAllRegistersFree(bool isGeneralPurposeRegister) {
    if (isGeneralPurposeRegister) {
        return generalPurposeRegisters->setAllRegistersFree();
    }
    else {
        return floatPointRegisters->setAllRegistersFree();
    }
}

bool TargetCodes::setAllRegistersAvailable(bool isGeneralPurposeRegister) {
    if (isGeneralPurposeRegister) {
        return generalPurposeRegisters->setAllRegistersAvailable();
    }
    else {
        return floatPointRegisters->setAllRegistersAvailable();
    }
}

bool TargetCodes::setAllRegistersFree() {
    generalPurposeRegisters->setAllRegistersFree();
    return floatPointRegisters->setAllRegistersFree();
}

bool TargetCodes::setAllRegistersAvailable() {
    generalPurposeRegisters->setAllRegistersAvailable();
    return floatPointRegisters->setAllRegistersAvailable();
}

bool TargetCodes::addCodeAdd(Register *rd, Register *rn, Register *rm) {
    Code *newCode = new Code(ASMOperation::ADD, rd, rn, rm);
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeAdd(Register *rd, Register *rn, int imm) {
    Code *newCode = new Code(ASMOperation::ADD, rd, rn, imm);
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeSub(Register *rd, Register *rn, Register *rm) {
    Code *newCode = new Code(ASMOperation::SUB, rd, rn, rm);
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeSub(Register *rd, Register *rn, int imm) {
    Code *newCode = new Code(ASMOperation::SUB, rd, rn, imm);
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeSub(Register *rd, Register *rn, int imm, bool reverse) {
    Code *newCode;
    if (reverse) {
        newCode = new Code(ASMOperation::SUB, Cond::NONE, rd, rn, nullptr, {}, nullptr, imm, {}, vector<Options>(1, Options::REVERSE_OP));
    }
    else {
        newCode = new Code(ASMOperation::SUB, rd, rn, imm);
    }
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeMul(Register *rd, Register *rn, Register *rm) {
    Code *newCode = new Code(ASMOperation::MUL, rd, rn, rm);
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeDiv(Register *rd, Register *rn, Register *rm) {
    Code *newCode = new Code(ASMOperation::DIV, rd, rn, rm);
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeLsl(Register *rd, Register *rn, Register *rm) {
    Code *newCode = new Code(ASMOperation::LSL, rd, rn, rm);
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeLsl(Register *rd, Register *rn, int imm) {
    Code *newCode = new Code(ASMOperation::LSL, rd, rn, imm);
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeAsr(Register *rd, Register *rn, Register *rm) {
    Code *newCode = new Code(ASMOperation::ASR, rd, rn, rm);
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeAsr(Register *rd, Register *rn, int imm) {
    Code *newCode = new Code(ASMOperation::ASR, rd, rn, imm);
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeEor(Register *rd, Register *rn, Register *rm) {
    Code *newCode = new Code(ASMOperation::EOR, rd, rn, rm);
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeEor(Register *rd, Register *rn, int imm) {
    Code *newCode = new Code(ASMOperation::EOR, rd, rn, imm);
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeOrr(Register *rd, Register *rn, Register *rm) {
    Code *newCode = new Code(ASMOperation::ORR, rd, rn, rm);
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeOrr(Register *rd, Register *rn, int imm) {
    Code *newCode = new Code(ASMOperation::ORR, rd, rn, imm);
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeAnd(Register *rd, Register *rn, Register *rm) {
    Code *newCode = new Code(ASMOperation::AND, rd, rn, rm);
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeAnd(Register *rd, Register *rn, int imm) {
    Code *newCode = new Code(ASMOperation::AND, rd, rn, imm);
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeTst(Register *rn, Register *rm) {
    Code *newCode = new Code(ASMOperation::TST, nullptr, rn, rm);
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeTst(Register *rn, int imm) {
    Code *newCode = new Code(ASMOperation::TST, nullptr, rn, imm);
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeTeq(Register *rn, Register *rm) {
    Code *newCode = new Code(ASMOperation::TEQ, nullptr, rn, rm);
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeTeq(Register *rn, int imm) {
    Code *newCode = new Code(ASMOperation::TEQ, nullptr, rn, imm);
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeCmp(Register *rn, Register *rm) {
    Code *newCode = new Code(ASMOperation::CMP, nullptr, rn, rm);
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeCmp(Register *rn, int imm) {
    Code *newCode = new Code(ASMOperation::CMP, nullptr, rn, imm);
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeCmn(Register *rn, Register *rm) {
    Code *newCode = new Code(ASMOperation::CMN, nullptr, rn, rm);
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeCmn(Register *rn, int imm) {
    Code *newCode = new Code(ASMOperation::CMN, nullptr, rn, imm);
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeVcmp(Register *rd, Register *rm) {
    Code *newCode = new Code(ASMOperation::VCMP, rd, nullptr, rm);
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeCbz(Register *rn, std::string label) {
    Code *newCode = new Code(ASMOperation::CBZ, Cond::NONE, nullptr, nullptr, nullptr, {}, nullptr, 0, std::move(label), {});
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeCbnz(Register *rn, std::string label) {
    Code *newCode = new Code(ASMOperation::CBNZ, Cond::NONE, nullptr, nullptr, nullptr, {}, nullptr, 0, std::move(label), {});
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeB(std::string label) {
    Code *newCode = new Code(ASMOperation::B, std::move(label), {});
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeBeq(std::string label) {
    Code *newCode = new Code(ASMOperation::BEQ, std::move(label), {});
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeBne(std::string label) {
    Code *newCode = new Code(ASMOperation::BNE, std::move(label), {});
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeBge(std::string label) {
    Code *newCode = new Code(ASMOperation::BGE, std::move(label), {});
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeBle(std::string label) {
    Code *newCode = new Code(ASMOperation::BLE, std::move(label), {});
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeBgt(std::string label) {
    Code *newCode = new Code(ASMOperation::BGT, std::move(label), {});
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeBlt(std::string label) {
    Code *newCode = new Code(ASMOperation::BLT, std::move(label), {});
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeAdr(Register *rd, std::string label) {
    Code *newCode = new Code(ASMOperation::ADR, {}, rd, nullptr, nullptr, {}, nullptr, 0, std::move(label), {});
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeLdr(Register *rd, std::string label) {
    Code *newCode = new Code(ASMOperation::LDR, {}, rd, nullptr, nullptr, {}, nullptr, 0, std::move(label), {});
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeLdr(Register *rd, std::string label, bool labelAsVal) {
    Code *newCode = nullptr;
    if (labelAsVal) {
        newCode = new Code(ASMOperation::LDR, {}, rd, nullptr, nullptr, {}, nullptr, 0, std::move(label), vector<Options>(1, Options::LABEL_AS_VAL));
    }
    else {
        newCode = new Code(ASMOperation::LDR, {}, rd, nullptr, nullptr, {}, nullptr, 0, std::move(label), {});
    }
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeLdr(Register *rd, int offset) {
    Code *newCode = new Code(ASMOperation::LDR, rd, nullptr, offset);
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeLdr(Register *rd, int offset, Cond inCond) {
    Code *newCode = new Code(ASMOperation::LDR, inCond, rd, nullptr, nullptr, {}, nullptr, offset, {}, {});
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeLdr(Register *rd, Register *rn) {
    Code *newCode = new Code(ASMOperation::LDR, rd, rn, nullptr);
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeLdr(Register *rd, Register *rn, Register *rm) {
    Code *newCode = new Code(ASMOperation::LDR, rd, rn, rm);
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeLdr(Register *rd, Register *rn, Register *rm, bool rmNegative) {
    Code *newCode = nullptr;
    if (rmNegative) {
        newCode = new Code(ASMOperation::LDR, Cond::NONE, rd, rn, rm, {}, nullptr, 0, {}, vector<Options>(1, Options::RM_NEGATIVE));
    }
    else {
        newCode = new Code(ASMOperation::LDR, rd, rn, rm);
    }
    addCode(newCode);
    return true;
}
bool TargetCodes::addCodeLdr(Register *rd, Register *rn, int offset) {
    Code *newCode = new Code(ASMOperation::LDR, rd, rn, offset);
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeLdr(Register *rd, Register *rn, int offset, bool postIndexed) {
    Code *newCode = nullptr;
    if (postIndexed) {
        newCode = new Code(ASMOperation::LDR, Cond::NONE, rd, rn, nullptr, {}, nullptr, offset, {}, vector<Options>(1, Options::POST_INDEX_OFFSET));
    }
    else {
        newCode = new Code(ASMOperation::LDR, rd, rn, offset);
    }
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeVldr(Register *rd, Register *rn, int offset, bool postIndexed) {
    Code *newCode = nullptr;
    if (postIndexed) {
        newCode = new Code(ASMOperation::VLDR, Cond::NONE, rd, rn, nullptr, {}, nullptr, offset, {}, vector<Options>(1, Options::POST_INDEX_OFFSET));
    }
    else {
        newCode = new Code(ASMOperation::VLDR, rd, rn, offset);
    }
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeStr(Register *rd, Register *rn, int offset, bool postIndexed) {
    Code *newCode = nullptr;
    if (postIndexed) {
        newCode = new Code(ASMOperation::STR, Cond::NONE, rd, rn, nullptr, {}, nullptr, offset, {}, vector<Options>(1, Options::POST_INDEX_OFFSET));
    }
    else {
        newCode = new Code(ASMOperation::STR, rd, rn, offset);
    }
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeVstr(Register *rd, Register *rn, int offset, bool postIndexed) {
    Code *newCode = nullptr;
    if (postIndexed) {
        newCode = new Code(ASMOperation::VSTR, Cond::NONE, rd, rn, nullptr, {}, nullptr, offset, {}, vector<Options>(1, Options::POST_INDEX_OFFSET));
    }
    else {
        newCode = new Code(ASMOperation::VSTR, rd, rn, offset);
    }
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeMv(Register *rd, Register *rn, Register *rm, int offset) {
    Code *newCode = new Code(ASMOperation::MV, {}, rd, rn, rm, {}, nullptr, offset, {}, {});
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeLabel(const string &inLabel) {
    Code *newCode = new Code(ASMOperation::LABEL, inLabel, {});
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeBl(string targetLabel) {
    Code *newCode = new Code(ASMOperation::BL, targetLabel, {});
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodePush(Cond inCond, std::vector<Register *> inRegList) {
    Code *newCode = new Code(ASMOperation::PUSH, inCond, inRegList);
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodePop(Cond inCond, std::vector<Register *> inRegList){
    Code *newCode = new Code(ASMOperation::POP, inCond, inRegList);
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeDirectives(const string &directives) {
    Code *newCode = new Code(ASMOperation::DIRECTIVE, {}, directives);
    addCode(newCode);
    return true;
}
