#include "IRContainers.h"
#include "IROperands.h"
#include "TargetCodes.h"

#pragma once

class IRGenerator {
private:

public:
    IRProgram * ir;
    IRFunction * currentIRFunc;
    TargetCodes *targetCodes;

    IRGenerator(IRProgram * newIR);

    IRSymbolVariable *addGlobalVariable(AbstractSymbol *Symbol);
    bool setGlobalVarValue(IRSymbolVariable *globalVariable, IRValue *curValue);
    bool setGlobalVarValue(std::string globalVariableName, IRValue *curValue);
    IRSymbolVariable *getGlobalVar(std::string globVariableName);

    bool addCode(IRCode *newCode);
    bool addCodes(std::vector<IRCode *> newCodes);

    // add Operand
    bool addLocalVariable(IRSymbolVariable *newLocalVariable);
    IRTempVariable *addTempVariable(MetaDataType newMetaDataType);
    IRLabel *addLabel();
    IRSymbolVariable* addSymbolVariable(AbstractSymbol *Symbol);
    IRSymbolFunction* getSymbolFunction(std::string funcName);

    bool enterFunction(FuncSymbolTable *function);
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


