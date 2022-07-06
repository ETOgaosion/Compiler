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
    ADDI,
    NEG,
    MUL,
    REM,
    DIV,
    SLL,
    SLR,
    SLLI,
    SLRI,
    NOT,
    OR,
    AND,
    XOR,
    SEQZ,
    SNEZ,
    SLTZ,
    SGTZ,
    SLT,
    FEQ,
    FLT,
    FLE,
    BEQZ,
    JR,
    LLA,
    LI,
    LB,
    LW,
    LD,
    FLW,
    FLD,
    SB,
    SW,
    SD,
    FSW,
    FSD,
    MV,
    LABEL,
    CALL,
    RET,
    DIRECTIVE,
    ECALL
};

class Code {
public:
    ASMOperation op;
    FloatPointType rdFloatPointType;
    FloatPointType srcFloatPointType;
    Register *rd;
    Register *rs1;
    Register *rs2;
    int offset;
    std::string label;
    std::string directives;

    Code(ASMOperation newOp, FloatPointType newRdFloatPointType, FloatPointType newSrcFloatPointType, Register *newRd, Register *newRs1, Register *newRs2, int newOffset, std::string newLabel);
    Code(ASMOperation newOp, std::string newDirectives);
    void print() const;
};

class TargetCodes {
private:
    TargetCodes();
    std::vector<Code *> codeList;
    Registers *generalPurposeRegisters;
    Registers *floatPointRegisters;

public:
    static TargetCodes *getTargetCodes();
    bool clear() { codeList.clear(); };

    bool addCode(Code *newCode);
    bool addCodes(const std::vector<Code *>& newCodes);

    bool addCodeAdd(Register *rd, Register *rs1, Register *rs2, FloatPointType inFloatPointType);
    bool addCodeSub(Register *rd, Register *rs1, Register *rs2, FloatPointType inFloatPointType);
    bool addCodeAddi(Register *rd, Register *rs1, int offset);
    bool addCodeNeg(Register *rd, Register *rs1, FloatPointType inFloatPointType);
    bool addCodeMul(Register *rd, Register *rs1, Register *rs2, FloatPointType inFloatPointType);
    bool addCodeDiv(Register *rd, Register *rs1, Register *rs2, FloatPointType inFloatPointType);
    bool addCodeSll(Register *rd, Register *rs1, Register *rs2, FloatPointType inFloatPointType);
    bool addCodeSlr(Register *rd, Register *rs1, Register *rs2, FloatPointType inFloatPointType);
    bool addCodeSlli(Register *rd, Register *rs1, int shamt);
    bool addCodeSlri(Register *rd, Register *rs1, int shamt);
    bool addCodeRem(Register *rd, Register *rs1, Register *rs2);
    bool addCodeNot(Register *rd, Register *rs1);
    bool addCodeXor(Register *rd, Register *rs1, Register *rs2);
    bool addCodeOr(Register *rd, Register *rs1, Register *rs2);
    bool addCodeAnd(Register *rd, Register *rs1, Register *rs2);
    bool addCodeSeqz(Register *rd, Register *rs1);
    bool addCodeSnez(Register *rd, Register *rs1);
    bool addCodeSltz(Register *rd, Register *rs1);
    bool addCodeSgtz(Register *rd, Register *rs1);
    bool addCodeSlt(Register *rd, Register *rs1, Register *rs2);
    bool addCodeFeq(Register *rd, Register *rs1, Register *rs2, FloatPointType inFloatPointType);
    bool addCodeFlt(Register *rd, Register *rs1, Register *rs2, FloatPointType inFloatPointType);
    bool addCodeFle(Register *rd, Register *rs1, Register *rs2, FloatPointType inFloatPointType);
    bool addCodeBeqz(Register *rs1, const std::string &targetLabel);
    bool addCodeJr(Register *rs1);
    bool addCodeLla(Register *rd, const std::string &targetLabel);
    bool addCodeLi(Register *rd, const std::string &targetLabel);
    bool addCodeLi(Register *rd, int imm);
    bool addCodeLb(Register *rd, Register *rs1, int offset);
    bool addCodeLw(Register *rd, Register *rs1, int offset);
    bool addCodeLd(Register *rd, Register *rs1, int offset);
    bool addCodeFlw(Register *rd, Register *rs1, int offset);
    bool addCodeFld(Register *rd, Register *rs1, int offset);
    bool addCodeSb(Register *rs1, Register *rs2, int offset);
    bool addCodeSw(Register *rs1, Register *rs2, int offset);
    bool addCodeSd(Register *rs1, Register *rs2, int offset);
    bool addCodeFsw(Register *rs1, Register *rs2, int offset);
    bool addCodeFsd(Register *rs1, Register *rs2, int offset);
    bool addCodeMv(Register *rd, Register *rs1, FloatPointType rdFloatPointType, FloatPointType rs1FloatPointType);
    bool addCodeLabel(const std::string &inLabel);
    bool addCodeCall(const std::string &targetLabel);
    bool addCodeRet();
    bool addCodeDirectives(const std::string &directives);
    bool addCodeEcall();

    void printCode() const;
    void codeWrite(std::string path) const;

    Register *getNextFreeRegister(bool isGeneralPurposeRegister, bool isParam, FloatPointType inFloatPointType, bool &hasFreeRegister);
    Register *getNextAvailableRegister(bool isGeneralPurposeRegister, bool isParam, FloatPointType inFloatPointType, bool &hasFreeRegister);

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
