#include "IRGenerator.h"

using namespace std;

IROperand* IRGenerator::addTempVariable(MetaDataType newMetaDataType) {
    IROperand* op = new currentIRFunc->addTempVariable(newMetaDataType);
    return op;
}

IRGenerator::IRGenerator(IRProgram *newIR) {
    ir = newIR;
    currentIRFunc = nullptr;
    targetCodes->clear();
}

bool IRGenerator::enterFunction(std::string functionName)
{
    IRFunction *func = new IRFunction(functionName);
    currentIRFunc = func;
    ir->addFunction(func);
    IRLabel *funcLabel = new IRLabel(string("func_") + functionName);
    func->addLabel(funcLabel);
    IRCode* funcCode = new IRAddLabel(funcLabel);
    func->addCode(funcCode);
}

bool IRGenerator::exitFunction()
{
    IRCode* retCode = new IRReturnV::IRReturnV();
    return currentIRFunc->addCode(retCode);
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
    IRCode* beginCode = new IRAddLabel::IRAddLabel(beginLabel);
    addCode(beginCode);
    return beginLabel;
}