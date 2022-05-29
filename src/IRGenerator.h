#include "IRContainers.h"
#include "IROperands.h"
#include "TargetCodes.h"

#pragma once

class IRGenerator {
private:
    IRProgram * ir;
    IRFunction * currentIRFunc;
    TargetCodes *targetCodes;

public:
    IRGenerator(IRProgram * newIR);

    bool addGlobalVar(IRSymbolVariable *globalVariable);
    bool setGlobalVarValue(IRSymbolVariable *globalVariable, IRValue *curValue);
    bool setGlobalVarValue(std::string globalVariableName, IRValue *curValue);
    IRSymbolVariable *getGlobalVar(std::string globVariableName);

    bool addCode(IRCode *newCode);
    bool addCodes(std::vector<IRCode *> newCodes);

    // add Operand
    bool addLocalVariable(IRSymbolVariable *newLocalVariable);
    IRTempVariable *addTempVariable(MetaDataType newMetaDataType);
    IRLabel *addLabel();
    IRSymbolVariable* addSymbolVariable(MetaDataType newMetaDataType);


    bool enterFunction(std::string funtionName);
    bool exitFunction(); // enter return

    // param is IN/OUT
    IRLabel* enterWhile();
    bool exitWhile(IRLabel *loopBeginLabel, IRLabel *loopEndLabel);
    bool enterBreak(IRLabel *loopEndLabel);
    bool enterContinue(IRLabel *loopBeginLabel);

    // param is IN/OUT
    bool enterArrayAssign(IRLabel *arrayLoopBeginLabel, IRLabel *arrayLoopEndLabel);
    bool exitArrayAssign(IRLabel *arrayLoopBeginLabel);

    // IRLabel *enterIf();
    // void enterElse(IRLabel *ifEndLabel);
};

