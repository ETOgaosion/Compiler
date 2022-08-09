//
// Created by 蓝色空间 on 2022/5/22.
//

#ifndef COMPILER_TARGETCODES_H
#define COMPILER_TARGETCODES_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "Registers.h"

enum class ASMOperation {
    ADD,
    SUB,
    // ADDI,
    // NEG,
    MUL,
    // REM,
    DIV,
    LSL,
    ASR,
    // SLLI,
    // SLRI,
    // NOT,
    ORR,
    AND,
    EOR,
    TST,
    TEQ,
    CMP,
    CMN,
    VCMP,
    CBZ,
    CBNZ,
    B,
    BEQ,
    BNE,
    BGE,
    BLE,
    BGT,
    BLT,
    ADR,
    LDR,
    // LI,
    // LW,
    VLDR,
    STR,
    VSTR,
    MV,
    LABEL,
    BL,
    // RET,
    PUSH,
    POP,
    DIRECTIVE
};

enum class ShiftWay {
    NONE,
    LSL,
    LSR,
    ASR,
    ROR
};

enum class Cond {
    NONE,
    EQ,
    NE,
    GE,
    LE,
    GT,
    LT
};

enum class Options {
    NONE,
    POST_INDEX_OFFSET,
    RM_NEGATIVE,
    REVERSE_OP,
    LABEL_AS_VAL
};

class Code {
public:
    ASMOperation op;
    Cond cond;
    Register *rd;
    Register *rn;
    Register *rm;
    ShiftWay shiftWay;
    Register *rs;
    std::vector<Register *> regList;
    int offset;
    std::string label;
    std::string directives;
    std::vector<Options> extraOptions;

    Code(ASMOperation newOp, Cond newCond, std::vector<Register *> newRegList);
    Code(ASMOperation newOp, Cond newCond, Register *newRd, Register *newRn, Register *newRm, ShiftWay newShiftWay, Register *newRs, int newOffset, std::string newLabel, std::vector<Options> newOptions);
    Code(ASMOperation newOp, Register *newRd, Register *newRn, Register *newRm);
    Code(ASMOperation newOp, Register *newRd, Register *newRn, int newOffset);
    Code(ASMOperation newOp, std::string newLabel, std::string newDirectives);
    void print() const;
    static std::string condToString(Cond inCond);
    static bool isImm8(int offset);
};

class TargetCodes {
private:
    TargetCodes();
    std::vector<Code *> codeList;
    Registers *generalPurposeRegisters;
    Registers *floatPointRegisters;

public:
    static TargetCodes *getTargetCodes();
    bool clear() { codeList.clear(); return true; };

    bool addCode(Code *newCode);
    bool addCodes(const std::vector<Code *>& newCodes);

    bool addCodeAdd(Register *rd, Register *rn, Register *rm);
    bool addCodeAdd(Register *rd, Register *rn, int imm);
    bool addCodeSub(Register *rd, Register *rn, Register *rm);
    bool addCodeSub(Register *rd, Register *rn, int imm);
    bool addCodeSub(Register *rd, Register *rn, int imm, bool reverse);
    bool addCodeMul(Register *rd, Register *rn, Register *rm);
    bool addCodeDiv(Register *rd, Register *rn, Register *rm);
    bool addCodeLsl(Register *rd, Register *rn, Register *rm);
    bool addCodeLsl(Register *rd, Register *rn, int imm);
    bool addCodeAsr(Register *rd, Register *rn, Register *rm);
    bool addCodeAsr(Register *rd, Register *rn, int imm);
    bool addCodeEor(Register *rd, Register *rn, Register *rm);
    bool addCodeEor(Register *rd, Register *rn, int imm);
    bool addCodeOrr(Register *rd, Register *rn, Register *rm);
    bool addCodeOrr(Register *rd, Register *rn, int imm);
    bool addCodeAnd(Register *rd, Register *rn, Register *rm);
    bool addCodeAnd(Register *rd, Register *rn, int imm);
    bool addCodeTst(Register *rn, Register *rm);
    bool addCodeTst(Register *rn, int imm);
    bool addCodeTeq(Register *rn, Register *rm);
    bool addCodeTeq(Register *rn, int imm);
    bool addCodeCmp(Register *rn, Register *rm);
    bool addCodeCmp(Register *rn, int imm);
    bool addCodeCmn(Register *rn, Register *rm);
    bool addCodeCmn(Register *rn, int imm);
    bool addCodeVcmp(Register *rd, Register *rm);
    bool addCodeCbz(Register *rn, std::string label);
    bool addCodeCbnz(Register *rn, std::string label);
    bool addCodeB(std::string label);
    bool addCodeBeq(std::string label);
    bool addCodeBne(std::string label);
    bool addCodeBge(std::string label);
    bool addCodeBle(std::string label);
    bool addCodeBgt(std::string label);
    bool addCodeBlt(std::string label);
    bool addCodeAdr(Register *rd, std::string label);
    bool addCodeLdr(Register *rd, std::string label);
    bool addCodeLdr(Register *rd, std::string label, bool labelAsVal);
    bool addCodeLdr(Register *rd, int offset);
    bool addCodeLdr(Register *rd, int offset, Cond inCond);
    bool addCodeLdr(Register *rd, Register *rn);
    bool addCodeLdr(Register *rd, Register *rn, Register *rm);
    bool addCodeLdr(Register *rd, Register *rn, Register *rm, bool rmNegative);
    bool addCodeLdr(Register *rd, Register *rn, int offset);
    bool addCodeLdr(Register *rd, Register *rn, int offset, bool postIndexed);
    bool addCodeVldr(Register *rd, Register *rn, int offset, bool postIndexed);
    bool addCodeStr(Register *rd, Register *rn, int offset, bool postIndexed);
    bool addCodeVstr(Register *rd, Register *rn, int offset, bool postIndexed);
    bool addCodeMv(Register *rd, Register *rn, Register *rm, int offset);
    bool addCodeLabel(const std::string &inLabel);
    bool addCodeBl(std::string label);
    bool addCodePush(Cond inCond, std::vector<Register *> inRegList);
    bool addCodePop(Cond inCond, std::vector<Register *> inRegList);
    bool addCodeDirectives(const std::string &directives);

    void printCode() const;
    void codeWrite(std::string path) const;

    Register *getNextFreeRegister(bool isGeneralPurposeRegister, bool isParam, bool &hasFreeRegister);
    Register *getNextAvailableRegister(bool isGeneralPurposeRegister, bool isParam, bool &hasFreeRegister);

    Register *tryGetCertainRegister(bool isGeneralPurposeRegister, const std::string &regName, bool &isFreeRegister);

    bool setRegisterFree(bool isGeneralPurposeRegister, const std::string &reg);
    bool setRegisterAvailable(bool isGeneralPurposeRegister, const std::string &reg);
    bool setRegisterFree(Register *reg);
    bool setRegisterAvailable(Register *reg);

    bool setRegistersFree(bool isGeneralPurposeRegister, const std::vector<std::string> &registers);
    bool setRegistersFree(bool isGeneralPurposeRegister, const std::vector<Register *> &registers);
    bool setRegistersAvailable(bool isGeneralPurposeRegister, const std::vector<std::string> &registers);
    bool setRegistersAvailable(bool isGeneralPurposeRegister, const std::vector<Register *> &registers);

    bool setAllRegistersFree(bool isGeneralPurposeRegister);
    bool setAllRegistersAvailable(bool isGeneralPurposeRegister);
    bool setAllRegistersFree();
    bool setAllRegistersAvailable();
};


#endif //COMPILER_TARGETCODES_H
