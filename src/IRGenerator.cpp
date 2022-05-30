#include "IRGenerator.h"

using namespace std;

IRGenerator::IRGenerator(IRProgram *newIR) {
    ir = newIR;
    currentIRFunc = nullptr;
    targetCodes->clear();
}

IRSymbolVariable* IRGenerator::addGlobalVariable(AbstractSymbol *Symbol){
    return ir->addGlobalVariable(Symbol);
}

IRSymbolVariable* IRGenerator::addSymbolVariable(AbstractSymbol* symbol) {
    return currentIRFunc->addSymbolVariable(symbol);
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
bool IRGenerator::enterFunction(std::string functionName)
{
    IRFunction *func = new IRFunction(functionName);
    currentIRFunc = func;
    ir->addFunction(func);
}

bool IRGenerator::exitFunction()
{
    IRCode* retCode = new IRReturnV();
    return currentIRFunc->addCode(retCode);
}