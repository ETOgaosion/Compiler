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

bool IRGenerator::enterFunction(std::string funtionName)
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
    IRCode::IRCode* retCode = new IRReturn::IRReturnV();
    return currentIRFunc->addCode(retCode);
}

bool addCode(IRCode *newCode)
{
    return currentIRFunc->addCode(newCode);
}

IRLabel *addLabel()
{
    
}

bool addCode(IRCode *newCode)
{
    return currentIRFunc->addCode(newCode);
}