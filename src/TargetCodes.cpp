//
// Created by 蓝色空间 on 2022/5/22.
//

#include "TargetCodes.h"

#include <utility>
#include <fstream>

using namespace std;

Code::Code(ASMOperation newOp, FloatPointType newRdFloatPointType, FloatPointType newSrcFloatPointType, Register *newRd, Register *newRs1, Register *newRs2, int newOffset, string newLabel) {
    op = newOp;
    rdFloatPointType = newRdFloatPointType;
    srcFloatPointType = newSrcFloatPointType;
    rd = newRd;
    rs1 = newRs1;
    rs2 = newRs2;
    offset = newOffset;
    label = move(newLabel);
    directives = {};
}

Code::Code(ASMOperation newOp, string newDirectives) {
    op = newOp;
    rdFloatPointType = {};
    srcFloatPointType = {};
    rd = nullptr;
    rs1 = nullptr;
    rs2 = nullptr;
    offset = 0;
    label = {};
    directives = move(newDirectives);
}

void Code::print() const {
    switch (op) {
        case ASMOperation::ADD:
            switch (rdFloatPointType) {
                case FloatPointType::NONE:
                    cout << "\taddw\t";
                    break;
                case FloatPointType::SINGLE:
                    cout << "\tfadd.s\t";
                    break;
                case FloatPointType::DOUBLE:
                    cout << "\tfadd.d\t";
                    break;
            }
            cout << rd->getAliasName() << ", " << rs1->getAliasName() << ", " << rs2->getAliasName() << endl;
            break;
        case ASMOperation::SUB:
            switch (rdFloatPointType) {
                case FloatPointType::NONE:
                    cout << "\tsubw\t";
                    break;
                case FloatPointType::SINGLE:
                    cout << "\tfsub.s\t";
                    break;
                case FloatPointType::DOUBLE:
                    cout << "\tfsub.d\t";
                    break;
            }
            cout << rd->getAliasName() << ", " << rs1->getAliasName() << ", " << rs2->getAliasName() << endl;
            break;
        case ASMOperation::ADDI:
            if (rdFloatPointType != FloatPointType::NONE) {
                cout << "ERROR: only general purpose registers have REM instruction";
                exit(-1);
            }
            cout << "\taddi\t" << rd->getAliasName() << ", " << rs1->getAliasName() << ", " << offset << endl;
            break;
        case ASMOperation::NEG:
            switch (rdFloatPointType) {
                case FloatPointType::NONE:
                    cout << "\tnegw\t";
                    break;
                case FloatPointType::SINGLE:
                    cout << "\tfneg.s\t";
                    break;
                case FloatPointType::DOUBLE:
                    cout << "\tfneg.d\t";
                    break;
            }
            cout << rd->getAliasName() << ", " << rs1->getAliasName() << endl;
            break;
        case ASMOperation::MUL:
            switch (rdFloatPointType) {
                case FloatPointType::NONE:
                    cout << "\tmulw\t";
                    break;
                case FloatPointType::SINGLE:
                    cout << "\tfmul.s\t";
                    break;
                case FloatPointType::DOUBLE:
                    cout << "\tfmul.d\t";
                    break;
            }
            cout << rd->getAliasName() << ", " << rs1->getAliasName() << ", " << rs2->getAliasName() << endl;
            break;
        case ASMOperation::DIV:
            switch (rdFloatPointType) {
                case FloatPointType::NONE:
                    cout << "\tdivw\t";
                    break;
                case FloatPointType::SINGLE:
                    cout << "\tfdiv.s\t";
                    break;
                case FloatPointType::DOUBLE:
                    cout << "\tfdiv.d\t";
                    break;
            }
            cout << rd->getAliasName() << ", " << rs1->getAliasName() << ", " << rs2->getAliasName() << endl;
            break;
        case ASMOperation::SLL:
            if (rdFloatPointType != FloatPointType::NONE) {
                cout << "ERROR: only general purpose registers have REM instruction";
                exit(-1);
            }
            cout << "\tsll\t" << rd->getAliasName() << ", " << rs1->getAliasName() << ", " << rs2->getAliasName() << endl;
            break;
        case ASMOperation::SLR:
            if (rdFloatPointType != FloatPointType::NONE) {
                cout << "ERROR: only general purpose registers have REM instruction";
                exit(-1);
            }
            cout << "\tslr\t" << rd->getAliasName() << ", " << rs1->getAliasName() << ", " << rs2->getAliasName() << endl;
            break;
        case ASMOperation::SLLI:
            if (rdFloatPointType != FloatPointType::NONE) {
                cout << "ERROR: only general purpose registers have REM instruction";
                exit(-1);
            }
            cout << "\tslli\t" << rd->getAliasName() << ", " << rs1->getAliasName() << ", " << offset << endl;
            break;
        case ASMOperation::SLRI:
            if (rdFloatPointType != FloatPointType::NONE) {
                cout << "ERROR: only general purpose registers have REM instruction";
                exit(-1);
            }
            cout << "\tslri\t" << rd->getAliasName() << ", " << rs1->getAliasName() << ", " << offset << endl;
            break;
        case ASMOperation::REM:
            if (rdFloatPointType != FloatPointType::NONE) {
                cout << "ERROR: only general purpose registers have REM instruction";
                exit(-1);
            }
            cout << "\tremw\t" << rd->getAliasName() << ", " << rs1->getAliasName() << ", " << rs2->getAliasName() << endl;
            break;
        case ASMOperation::NOT:
            if (rdFloatPointType != FloatPointType::NONE) {
                cout << "ERROR: only general purpose registers have NOT instruction";
                exit(-1);
            }
            cout << "\tnot\t" << rd->getAliasName() << ", " << rs1->getAliasName() << endl;
            break;
        case ASMOperation::OR:
            if (rdFloatPointType != FloatPointType::NONE) {
                cout << "ERROR: only general purpose registers have OR instruction";
                exit(-1);
            }
            cout << "\tor\t" << rd->getAliasName() << ", " << rs1->getAliasName() << ", " << rs2->getAliasName() << endl;
            break;
        case ASMOperation::AND:
            if (rdFloatPointType != FloatPointType::NONE) {
                cout << "ERROR: only general purpose registers have AND instruction";
                exit(-1);
            }
            cout << "\tand\t" << rd->getAliasName() << ", " << rs1->getAliasName() << ", " << rs2->getAliasName() << endl;
            break;
        case ASMOperation::XOR:
            if (rdFloatPointType != FloatPointType::NONE) {
                cout << "ERROR: only general purpose registers have XOR instruction";
                exit(-1);
            }
            cout << "\txor\t" << rd->getAliasName() << ", " << rs1->getAliasName() << ", " << rs2->getAliasName() << endl;
            break;
        case ASMOperation::SEQZ:
            if (rdFloatPointType != FloatPointType::NONE) {
                cout << "ERROR: only general purpose registers have SEQZ instruction";
                exit(-1);
            }
            cout << "\tseqz\t" << rd->getAliasName() << ", " << rs1->getAliasName() << endl;
            break;
        case ASMOperation::SNEZ:
            if (rdFloatPointType != FloatPointType::NONE) {
                cout << "ERROR: only general purpose registers have SLT instruction";
                exit(-1);
            }
            cout << "\tsnez\t" << rd->getAliasName() << ", " << rs1->getAliasName() << endl;
            break;
        case ASMOperation::SLTZ:
            if (rdFloatPointType != FloatPointType::NONE) {
                cout << "ERROR: only general purpose registers have SLTZ instruction";
                exit(-1);
            }
            cout << "\tsltz\t" << rd->getAliasName() << ", " << rs1->getAliasName() << endl;
            break;
        case ASMOperation::SGTZ:
            if (rdFloatPointType != FloatPointType::NONE) {
                cout << "ERROR: only general purpose registers have SGTZ instruction";
                exit(-1);
            }
            cout << "\tsgtz\t" << rd->getAliasName() << ", " << rs1->getAliasName() << endl;
            break;
        case ASMOperation::SLT:
            if (rdFloatPointType != FloatPointType::NONE) {
                cout << "ERROR: only general purpose registers have SLT instruction";
                exit(-1);
            }
            cout << "\tslt\t" << rd->getAliasName() << ", " << rs1->getAliasName() << ", " << rs2->getAliasName() << endl;
            break;
        case ASMOperation::FEQ:
            switch (rdFloatPointType) {
                case FloatPointType::NONE:
                    cout << "ERROR: general purpose registers do not have FEQ instruction";
                    break;
                case FloatPointType::SINGLE:
                    cout << "\tfeq.s\t";
                    break;
                case FloatPointType::DOUBLE:
                    cout << "\tfeq.d\t";
                    break;
            }
            cout << rd->getAliasName() << ", " << rs1->getAliasName() << ", " << rs2->getAliasName() << endl;
            break;
        case ASMOperation::FLT:
            switch (rdFloatPointType) {
                case FloatPointType::NONE:
                    cout << "ERROR: general purpose registers do not have FLT instruction";
                    break;
                case FloatPointType::SINGLE:
                    cout << "\tflt.s\t";
                    break;
                case FloatPointType::DOUBLE:
                    cout << "\tflt.d\t";
                    break;
            }
            cout << rd->getAliasName() << ", " << rs1->getAliasName() << ", " << rs2->getAliasName() << endl;
            break;
        case ASMOperation::FLE:
            switch (rdFloatPointType) {
                case FloatPointType::NONE:
                    cout << "ERROR: general purpose registers do not have FLE instruction";
                    break;
                case FloatPointType::SINGLE:
                    cout << "\tfle.s\t";
                    break;
                case FloatPointType::DOUBLE:
                    cout << "\tfle.d\t";
                    break;
            }
            cout << rd->getAliasName() << ", " << rs1->getAliasName() << ", " << rs2->getAliasName() << endl;
            break;
        case ASMOperation::BEQZ:
            if (offset != 0 && label.empty()) {
                cout << "\tbeqz\t" << rs1->getAliasName() << ", " << to_string(offset) << endl;
            }
            else {
                cout << "\tbeqz\t" << rs1->getAliasName() << ", " << label << endl;
            }
            break;
        case ASMOperation::JR:
            if (rdFloatPointType != FloatPointType::NONE) {
                cout << "ERROR: only general purpose registers have JR instruction";
                exit(-1);
            }
            cout << "\tjr\t" << rs1->getAliasName() << endl;
            break;
        case ASMOperation::LLA:
            cout << "\tlla\t" << rd->getAliasName() << ", " << label << endl;
            break;
        case ASMOperation::LI:
            cout <<"\tli\t" << rd->getAliasName() << ", ";
            if (label.empty()) {
                cout << offset;
            }
            else {
                cout << label;
            }
            cout << endl;
            break;
        case ASMOperation::LB:
            cout << "\tlb\t" << rd->getAliasName() << ", " << to_string(offset) << "(" << rs1->getAliasName() << ")" << endl;
            break;
        case ASMOperation::LW:
            cout << "\tlw\t" << rd->getAliasName() << ", " << to_string(offset) << "(" << rs1->getAliasName() << ")" << endl;
            break;
        case ASMOperation::LD:
            cout << "\tld\t" << rd->getAliasName() << ", " << to_string(offset) << "(" << rs1->getAliasName() << ")" << endl;
            break;
        case ASMOperation::FLW:
            cout << "\tflw\t" << rd->getAliasName() << ", " << to_string(offset) << "(" << rs1->getAliasName() << ")" << endl;
            break;
        case ASMOperation::FLD:
            cout << "\tfld\t" << rd->getAliasName() << ", " << to_string(offset) << "(" << rs1->getAliasName() << ")" << endl;
            break;
        case ASMOperation::SB:
            cout << "\tsb\t" << rs2->getAliasName() << ", " << to_string(offset) << "(" << rs1->getAliasName() << ")" << endl;
            break;
        case ASMOperation::SW:
            cout << "\tsw\t" << rs2->getAliasName() << ", " << to_string(offset) << "(" << rs1->getAliasName() << ")" << endl;
            break;
        case ASMOperation::SD:
            cout << "\tsd\t" << rs2->getAliasName() << ", " << to_string(offset) << "(" << rs1->getAliasName() << ")" << endl;
            break;
        case ASMOperation::FSW:
            cout << "\tfsw\t" << rs2->getAliasName() << ", " << to_string(offset) << "(" << rs1->getAliasName() << ")" << endl;
            break;
        case ASMOperation::FSD:
            cout << "\tfsd\t" << rs2->getAliasName() << ", " << to_string(offset) << "(" << rs1->getAliasName() << ")" << endl;
            break;
        case ASMOperation::MV:
            switch (rdFloatPointType) {
                case FloatPointType::NONE:
                    switch (srcFloatPointType) {
                        case FloatPointType::NONE:
                            cout << "\tmv\t";
                            break;
                        case FloatPointType::SINGLE:
                            cout << "\tfmv.x.w\t";
                            break;
                        case FloatPointType::DOUBLE:
                            cout << "\tfmv.x.d\t";
                            break;
                    }
                    break;
                case FloatPointType::SINGLE:
                    switch (srcFloatPointType) {
                        case FloatPointType::NONE:
                            cout << "\tfmv.w.x\t";
                            break;
                        case FloatPointType::SINGLE:
                            cout << "\tfmv.s\t";
                            break;
                        case FloatPointType::DOUBLE:
                            cout << "\tfmv.s.d\t";
                            break;
                    }
                    break;
                case FloatPointType::DOUBLE:
                    switch (srcFloatPointType) {
                        case FloatPointType::NONE:
                            cout << "\tfmv.d.x\t";
                            break;
                        case FloatPointType::SINGLE:
                            cout << "\tfmv.d.s\t";
                            break;
                        case FloatPointType::DOUBLE:
                            cout << "\tfmv.d\t";
                            break;
                    }
                    break;
            }
            cout << rd->getAliasName() << ", " << rs1->getAliasName() << endl;
            break;
        case ASMOperation::LABEL:
            cout << label << ":\n";
            break;
        case ASMOperation::CALL:
            cout << "\tcall\t" << label << endl;
            break;
        case ASMOperation::RET:
            cout << "\tret\n";
            break;
        case ASMOperation::DIRECTIVE:
            cout << directives << endl;
            break;
        case ASMOperation::ECALL:
            cout << "\tecall" << endl;
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

Register *TargetCodes::getNextFreeRegister(bool isGeneralPurposeRegister, bool isParam, FloatPointType inFloatPointType, bool &hasFreeRegister) {
    if (isGeneralPurposeRegister) {
        return generalPurposeRegisters->getNextFreeRegister(isParam, inFloatPointType, hasFreeRegister);
    }
    else {
        return floatPointRegisters->getNextFreeRegister(isParam, inFloatPointType, hasFreeRegister);
    }
}

Register *TargetCodes::getNextAvailableRegister(bool isGeneralPurposeRegister, bool isParam, FloatPointType inFloatPointType, bool &hasFreeRegister) {
    if (isGeneralPurposeRegister) {
        return generalPurposeRegisters->getNextAvailableRegister(isParam, inFloatPointType, hasFreeRegister);
    }
    else {
        return floatPointRegisters->getNextAvailableRegister(isParam, inFloatPointType, hasFreeRegister);
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

bool TargetCodes::addCodeAdd(Register *rd, Register *rs1, Register *rs2, FloatPointType inFloatPointType) {
    Code *newCode = new Code(ASMOperation::ADD, inFloatPointType, FloatPointType::NONE, rd, rs1, rs2, 0, {});
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeSub(Register *rd, Register *rs1, Register *rs2, FloatPointType inFloatPointType) {
    Code *newCode = new Code(ASMOperation::SUB, inFloatPointType, FloatPointType::NONE, rd, rs1, rs2, 0, {});
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeAddi(Register *rd, Register *rs1, int offset) {
    Code *newCode = new Code(ASMOperation::ADDI, FloatPointType::NONE, FloatPointType::NONE, rd, rs1, nullptr, offset, {});
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeNeg(Register *rd, Register *rs1, FloatPointType inFloatPointType) {
    Code *newCode = new Code(ASMOperation::NEG, inFloatPointType, FloatPointType::NONE, rd, rs1, nullptr, 0, {});
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeMul(Register *rd, Register *rs1, Register *rs2, FloatPointType inFloatPointType) {
    Code *newCode = new Code(ASMOperation::MUL, inFloatPointType, FloatPointType::NONE, rd, rs1, rs2, 0, {});
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeDiv(Register *rd, Register *rs1, Register *rs2, FloatPointType inFloatPointType) {
    Code *newCode = new Code(ASMOperation::DIV, inFloatPointType, FloatPointType::NONE, rd, rs1, rs2, 0, {});
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeSll(Register *rd, Register *rs1, Register *rs2, FloatPointType inFloatPointType) {
    Code *newCode = new Code(ASMOperation::SLL, inFloatPointType, FloatPointType::NONE, rd, rs1, rs2, 0, {});
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeSlr(Register *rd, Register *rs1, Register *rs2, FloatPointType inFloatPointType) {
    Code *newCode = new Code(ASMOperation::SLR, inFloatPointType, FloatPointType::NONE, rd, rs1, rs2, 0, {});
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeSlli(Register *rd, Register *rs1, int shamt) {
    Code *newCode = new Code(ASMOperation::SLLI, FloatPointType::NONE, FloatPointType::NONE, rd, rs1, nullptr, shamt, {});
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeSlri(Register *rd, Register *rs1, int shamt) {
    Code *newCode = new Code(ASMOperation::SLRI, FloatPointType::NONE, FloatPointType::NONE, rd, rs1, nullptr, shamt, {});
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeRem(Register *rd, Register *rs1, Register *rs2) {
    Code *newCode = new Code(ASMOperation::REM, FloatPointType::NONE, FloatPointType::NONE, rd, rs1, rs2, 0, {});
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeNot(Register *rd, Register *rs1) {
    Code *newCode = new Code(ASMOperation::NOT, FloatPointType::NONE, FloatPointType::NONE, rd, rs1, nullptr, 0, {});
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeXor(Register *rd, Register *rs1, Register *rs2) {
    Code *newCode = new Code(ASMOperation::XOR, FloatPointType::NONE, FloatPointType::NONE, rd, rs1, rs2, 0, {});
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeOr(Register *rd, Register *rs1, Register *rs2) {
    Code *newCode = new Code(ASMOperation::OR, FloatPointType::NONE, FloatPointType::NONE, rd, rs1, rs2, 0, {});
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeAnd(Register *rd, Register *rs1, Register *rs2) {
    Code *newCode = new Code(ASMOperation::AND, FloatPointType::NONE, FloatPointType::NONE, rd, rs1, rs2, 0, {});
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeSeqz(Register *rd, Register *rs1) {
    Code *newCode = new Code(ASMOperation::SEQZ, FloatPointType::NONE, FloatPointType::NONE, rd, rs1, nullptr, 0, {});
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeSnez(Register *rd, Register *rs1) {
    Code *newCode = new Code(ASMOperation::SNEZ, FloatPointType::NONE, FloatPointType::NONE, rd, rs1, nullptr, 0, {});
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeSltz(Register *rd, Register *rs1) {
    Code *newCode = new Code(ASMOperation::SLTZ, FloatPointType::NONE, FloatPointType::NONE, rd, rs1, nullptr, 0, {});
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeSgtz(Register *rd, Register *rs1) {
    Code *newCode = new Code(ASMOperation::SGTZ, FloatPointType::NONE, FloatPointType::NONE, rd, rs1, nullptr, 0, {});
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeSlt(Register *rd, Register *rs1, Register *rs2) {
    Code *newCode = new Code(ASMOperation::SLT, FloatPointType::NONE, FloatPointType::NONE, rd, rs1, rs2, 0, {});
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeFeq(Register *rd, Register *rs1, Register *rs2, FloatPointType inFloatPointType) {
    if (inFloatPointType == FloatPointType::NONE) {
        cout << "ERROR: general purpose registers do not have FEQ instruction";
        exit(-1);
    }
    Code *newCode = new Code(ASMOperation::FEQ, inFloatPointType, FloatPointType::NONE, rd, rs1, rs2, 0, {});
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeFlt(Register *rd, Register *rs1, Register *rs2, FloatPointType inFloatPointType) {
    if (inFloatPointType == FloatPointType::SINGLE) {
        cout << "ERROR: general purpose registers do not have FEQ instruction";
        exit(-1);
    }
    Code *newCode = new Code(ASMOperation::FLT, inFloatPointType, FloatPointType::NONE, rd, rs1, rs2, 0, {});
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeFle(Register *rd, Register *rs1, Register *rs2, FloatPointType inFloatPointType) {
    if (inFloatPointType == FloatPointType::DOUBLE) {
        cout << "ERROR: general purpose registers do not have FEQ instruction";
        exit(-1);
    }
    Code *newCode = new Code(ASMOperation::FLE, inFloatPointType, FloatPointType::NONE, rd, rs1, rs2, 0, {});
    addCode(newCode);
    return true;
}


bool TargetCodes::addCodeBeqz(Register *rs1, const string &targetLabel) {
    Code *newCode = new Code(ASMOperation::BEQZ, FloatPointType::NONE, FloatPointType::NONE, nullptr, rs1, nullptr, 0, targetLabel);
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeJr(Register *rs1) {
    Code *newCode = new Code(ASMOperation::JR, FloatPointType::NONE, FloatPointType::NONE, nullptr, rs1, nullptr, 0, {});
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeLla(Register *rd, const string &targetLabel) {
    Code *newCode = new Code(ASMOperation::LLA, FloatPointType::NONE, FloatPointType::NONE, rd, nullptr, nullptr, 0, targetLabel);
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeLi(Register *rd, const string &targetLabel) {
    Code *newCode = new Code(ASMOperation::LI, FloatPointType::NONE, FloatPointType::NONE, rd, nullptr, nullptr, 0, targetLabel);
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeLi(Register *rd, int imm) {
    Code *newCode = new Code(ASMOperation::LI, FloatPointType::NONE, FloatPointType::NONE, rd, nullptr, nullptr, imm, {});
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeLb(Register *rd, Register *rs1, int offset) {
    Code *newCode = new Code(ASMOperation::LB, FloatPointType::NONE, FloatPointType::NONE, rd, rs1, nullptr, offset, {});
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeLw(Register *rd, Register *rs1, int offset) {
    Code *newCode = new Code(ASMOperation::LW, FloatPointType::NONE, FloatPointType::NONE, rd, rs1, nullptr, offset, {});
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeLd(Register *rd, Register *rs1, int offset) {
    Code *newCode = new Code(ASMOperation::LD, FloatPointType::NONE, FloatPointType::NONE, rd, rs1, nullptr, offset, {});
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeFlw(Register *rd, Register *rs1, int offset) {
    Code *newCode = new Code(ASMOperation::FLW, FloatPointType::SINGLE, FloatPointType::NONE, rd, rs1, nullptr, offset, {});
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeFld(Register *rd, Register *rs1, int offset) {
    Code *newCode = new Code(ASMOperation::FLD, FloatPointType::DOUBLE, FloatPointType::NONE, rd, rs1, nullptr, offset, {});
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeSb(Register *rs1, Register *rs2, int offset) {
    Code *newCode = new Code(ASMOperation::SB, FloatPointType::NONE, FloatPointType::NONE, nullptr, rs1, rs2, offset, {});
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeSw(Register *rs1, Register *rs2, int offset) {
    Code *newCode = new Code(ASMOperation::SW, FloatPointType::NONE, FloatPointType::NONE, nullptr, rs1, rs2, offset, {});
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeSd(Register *rs1, Register *rs2, int offset) {
    Code *newCode = new Code(ASMOperation::SD, FloatPointType::NONE, FloatPointType::NONE, nullptr, rs1, rs2, offset, {});
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeFsw(Register *rs1, Register *rs2, int offset) {
    Code *newCode = new Code(ASMOperation::FSW, FloatPointType::SINGLE, FloatPointType::NONE, nullptr, rs1, rs2, offset, {});
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeFsd(Register *rs1, Register *rs2, int offset) {
    Code *newCode = new Code(ASMOperation::FSD, FloatPointType::DOUBLE, FloatPointType::NONE, nullptr, rs1, rs2, offset, {});
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeMv(Register *rd, Register *rs1, FloatPointType rdFloatPointType, FloatPointType rs1FloatPointType) {
    Code *newCode = new Code(ASMOperation::MV, rdFloatPointType, rs1FloatPointType, rd, rs1, nullptr, 0, {});
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeLabel(const string &inLabel) {
    Code *newCode = new Code(ASMOperation::LABEL, FloatPointType::NONE, FloatPointType::NONE, nullptr, nullptr, nullptr, 0, inLabel);
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeCall(const string &targetLabel) {
    Code *newCode = new Code(ASMOperation::CALL, FloatPointType::NONE, FloatPointType::NONE, nullptr, nullptr, nullptr, 0, targetLabel);
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeRet() {
    Code *newCode = new Code(ASMOperation::RET, FloatPointType::NONE, FloatPointType::NONE, nullptr, nullptr, nullptr, 0, {});
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeDirectives(const string &directives) {
    Code *newCode = new Code(ASMOperation::DIRECTIVE, directives);
    addCode(newCode);
    return true;
}

bool TargetCodes::addCodeEcall() {
    Code *newCode = new Code(ASMOperation::ECALL, FloatPointType::NONE, FloatPointType::NONE, nullptr, nullptr, nullptr, 0, {});
    addCode(newCode);
    return true;
}
