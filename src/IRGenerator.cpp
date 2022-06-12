#include "IRGenerator.h"

using namespace std;

IRGenerator::IRGenerator(IRProgram *newIR) {
    ir = newIR;
    currentIRFunc = nullptr;
    targetCodes->clear();
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

bool IRGenerator::addCodes(std::vector<IRCode *> newCodes)
{
    return currentIRFunc->addCodes(newCodes);
}

IRLabel* IRGenerator::addLabel()
{
    return currentIRFunc->addLabel();
}

IRLabel* IRGenerator::enterWhile()
{
    IRLabel* beginLabel = addLabel();
    IRCode* beginCode = new IRAddLabel(beginLabel);
    addCode(beginCode);
    return beginLabel;
}

// Function
bool IRGenerator::enterFunction(FuncSymbolTable *function)
{
    IRFunction *func = new IRFunction(function->getFuncName());
    currentIRFunc = func;
    ir->addFunction(func);
    IRSymbolFunction* funcSymbol = new IRSymbolFunction(function);
    ir->addSymbolFunction(funcSymbol);
    return true;
}

bool IRGenerator::exitFunction()
{
    IRCode* retCode = new IRReturnV();
    return currentIRFunc->addCode(retCode);
}


IRSymbolFunction* IRGenerator::getSymbolFunction(std::string funcName){
    return ir->getSymbolFunction(funcName);
}
