#include "IRGenerator.h"

#include <stdio.h>

using namespace std;

IRGenerator::IRGenerator() {}

IRGenerator *IRGenerator::getIRGenerator(IRProgram *newIR) {
    // singleton
    static IRGenerator instance;
    static bool initialized = false;
    if (!initialized) {
        instance.ir = newIR;
        instance.currentIRFunc = nullptr;
        instance.targetCodes = TargetCodes::getTargetCodes();
        instance.targetCodes->clear();
        initialized = true;
    }
    return &instance;
}

IRSymbolVariable* IRGenerator::addGlobalVariable(AbstractSymbol *Symbol, IRValue* newValue){
    return ir->addGlobalVariable(Symbol, newValue);
}

IRSymbolVariable* IRGenerator::addSymbolVariable(int block, AbstractSymbol* symbol, IRValue* newValue) {
    return currentIRFunc->addSymbolVariable(block, symbol, newValue);
}

IRTempVariable* IRGenerator::addTempVariable(MetaDataType newMetaDataType) {
    return currentIRFunc->addTempVariable(newMetaDataType);
}

bool IRGenerator::addCode(IRCode *newCode)
{
    return currentIRFunc->addCode(newCode);
}

bool IRGenerator::addCodes(vector<IRCode *> newCodes)
{
    return currentIRFunc->addCodes(newCodes);
}

IRLabel* IRGenerator::addLabel()
{
    return currentIRFunc->addLabel();
}

IRValue *IRGenerator::addImmValue(MetaDataType inMetaDataType, const string &inValue) {
    return ir->addImmValue(inMetaDataType, inValue);
}

IRValue *IRGenerator::addImmValue(const string &inLabel, MetaDataType inMetaDataType, const string &inValue) {
    return ir->addImmValue(inLabel, inMetaDataType, inValue);
}

IRLabel* IRGenerator::enterWhile()
{
    IRLabel* beginLabel = addLabel();
    IRCode* beginCode = new IRAddLabel(beginLabel);
    addCode(beginCode);
    return beginLabel;
}

// Function
bool IRGenerator::enterFunction(SymbolTable *function)
{
    IRFunction *func = new IRFunction(function->getFuncName(), function);
    currentIRFunc = func;
    ir->addFunction(func);
    IRSymbolFunction* funcSymbol = new IRSymbolFunction(function);
    ir->addSymbolFunction(funcSymbol);
    return true;
}

bool IRGenerator::exitFunction()
{
    IRCode* retCode = new IRReturnV(new IRSymbolFunction(currentIRFunc->getFuncSymbolTable()));
    return currentIRFunc->addCode(retCode);
}


IRSymbolFunction* IRGenerator::getSymbolFunction(string funcName){
    return ir->getSymbolFunction(funcName);
}
