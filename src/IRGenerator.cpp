#include "IRGenerator.h"

using namespace std;

IROperand* IRGenerator::addTempVariable(MetaDataType newMetaDataType) {
    IROperand* op = new currentIRFunc->addTempVariable(newMetaDataType);
    return op;
}

IRGenerator(IRProgram *newIR) {
    ir = newIR;
    currentIRFunc = nullptr;
    targetCodes->clear();
}

bool IRGenrator::enterFunction(std::string funtionName)
{
    IRFunction *func = new IRFunction(functionName);
    currentIRFunc = func;
    ir->addFunction(func);
    IRLabel *funcLabel = new IRLabel(string("func_") + functionName);
    func->addLabel(funcLabel);
    IRCode* funcCode = new IRAddLabel(funcLabel);
    func->addCode(funcCode);
}

bool IRGenrator::exitFunction()
{
    IRCode::IRCode* retCode = new IRReturn::IRReturnV();
    return currentIRFunc->addCode(retCode);
}

bool IRGenrator::addCode(IRCode *newCode)
{
    return currentIRFunc->addCode(newCode);
}

IRLabel* IRGenrator::addLabel()
{
    return currentIRFunc->addLabel();
}

IRLabel* IRGenrator::enterWhile()
{
    IRLabel* beginLabel = addLabel();
    IRCode* beginCode = new IRAddLabel::IRAddLabel(beginLabel);
    addCode(beginCode);
    return beginLabel;
}