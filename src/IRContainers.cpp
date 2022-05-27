#include "IRContainers.h"

#include <utility>

using namespace std;

IRFunction::IRFunction(string newFunctionName) {
    functionName = std::move(newFunctionName);
    localVariables.clear();
    tempVariables.clear();
    codes.clear();
    labels.clear();
    tempCount = 0;
    labelCount = 0;
    frameSize = 0;
}

bool IRFunction::addLocalVariable(IRSymbolVariable *newVariable) {
    localVariables.emplace(newVariable->getSymbolName(), newVariable);
    return true;
}

IRTempVariable* IRFunction::addTempVariable(MetaDataType newMetaDataType) {
    string newTempVariableName = functionName + string("_t") + to_string(tempCount++);
    IRTempVariable *newIRTempVar = new IRTempVariable(newTempVariableName, newMetaDataType);
    tempVariables.emplace(newTempVariableName, newIRTempVar);
    return newIRTempVar;
}

bool IRFunction::addCode(IRCode *newCode) {
    codes.emplace_back(newCode);
}

bool IRFunction::addCodes(std::vector<IRCode *> newCodes){
    for (auto code : newCodes){
        codes.emplace_back(code);
    }
}


bool IRFunction::addLabel(IRLabel *newLabel) {
    labels.emplace(newLabel->getSymbolName(), newLabel);
}

int IRFunction::calFrameSize() {}

string IRFunction::getFunctionName() const {
    return functionName;
}

IRSymbolVariable *IRFunction::getLocalVariable(const string& varName){
    return localVariables.at(varName);
}

IRTempVariable *IRFunction::getTempVariable(const string& varName){
    return tempVariables.at(varName);
}

IRCode *IRFunction::getCode(int cnt){
    return codes[cnt];
}

vector<IRCode *> &IRFunction::getCodes(){
    return codes;
}

IRLabel *IRFunction::getLabel(const string& labelName){
    return labels.at(labelName);
}

int IRFunction::getFrameSize() const {
    return frameSize;
}

void IRFunction::print() const {}

IRProgram::IRProgram(std::string newProgramName) {
    programName = std::move(newProgramName);
}

bool IRProgram::addGlobalVariable(IRSymbolVariable *newGlobalVariable) {
    globalVariables.emplace(newGlobalVariable->getSymbolName(), newGlobalVariable);
    return true;
}

bool IRProgram::addFunction(IRFunction *newFunction) {
    functions.emplace(newFunction->getFunctionName(), newFunction);
}

IRSymbolVariable *IRProgram::getGlobalVariable(const string& varName){
    return globalVariables.at(varName);
}

IRFunction *IRProgram::getFunction(const std::string& functionName){
    return functions.at(functionName);
}

void IRProgram::print() const {}