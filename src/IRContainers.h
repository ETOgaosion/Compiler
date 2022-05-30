#include "IRCode.h"
#include "IROperands.h"

#pragma once

class IRFunction {
private:
    std::string functionName;
    std::unordered_map<std::string, IRSymbolVariable *> localVariables;
    std::unordered_map<std::string, IRTempVariable *> tempVariables;
    std::vector<IRCode *> codes;
    std::unordered_map<std::string, IRLabel *> labels;

    int tempCount;
    int labelCount;
    int frameSize;

public:
    IRFunction(std::string newFunctionName);

    bool addLocalVariable(IRSymbolVariable *newVariable);
    IRTempVariable* addTempVariable(MetaDataType newMetaDataType);
    IRSymbolVariable* addSymbolVariable(AbstractSymbol *newSymbol);
    IRLabel* addLabel();
    bool addLabel(IRLabel *newLabel);
    bool addCode(IRCode *newCode);
    bool addCodes(std::vector<IRCode *> newCodes);
    int calFrameSize();

    std::string getFunctionName() const;
    IRSymbolVariable *getLocalVariable(const std::string& varName);
    IRTempVariable *getTempVariable(const std::string& varName);
    IRCode *getCode(int cnt);
    std::vector<IRCode *> &getCodes();
    IRLabel *getLabel(const std::string& labelName);
    int getFrameSize() const;

    void print() const;
    // void targetCodeGen(TargetCodeList * t);
};

class IRProgram {
private:
    std::string programName;
    std::unordered_map<std::string, IRSymbolVariable *> globalVariables;
    std::unordered_map<std::string, IRFunction *> functions;
    
public:
    IRProgram(std::string newProgramName);

    IRSymbolVariable *addGlobalVariable(AbstractSymbol *symbol);
    bool addFunction(IRFunction *newFunction);

    IRSymbolVariable *getGlobalVariable(const std::string& varName);
    IRFunction *getFunction(const std::string& functionName);

    void print() const;
    // void targetGen(TargetCodeList * t);
};