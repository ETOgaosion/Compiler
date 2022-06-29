#include "IRContainers.h"
#include "IROperands.h"
#include "TargetCodes.h"

#pragma once

class IRGenerator {
private:
    IRGenerator();

public:
    IRProgram * ir;
    IRFunction * currentIRFunc;
    TargetCodes *targetCodes;

    static IRGenerator *getIRGenerator(IRProgram *newIR);

    IRSymbolVariable *addGlobalVariable(AbstractSymbol *Symbol, IRValue* newValue);
    IRValue *addImmValue(MetaDataType inMetaDataType, const std::string &inValue);
    IRValue *addImmValue(const std::string &inLabel, MetaDataType inMetaDataType, const std::string &inValue);

    bool addCode(IRCode *newCode);
    bool addCodes(std::vector<IRCode *> newCodes);

    // add Operand
    IRTempVariable *addTempVariable(MetaDataType newMetaDataType);
    IRLabel *addLabel();
    IRSymbolVariable* addSymbolVariable(int block, AbstractSymbol *Symbol, IRValue* newValue);
    IRSymbolFunction* getSymbolFunction(std::string funcName);

    bool enterFunction(SymbolTable *function);
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


