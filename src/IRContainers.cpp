#include "IRContainers.h"

#include <utility>
#include <fstream>
#include <stdio.h>

using namespace std;

IRFunction::IRFunction(string newFunctionName, SymbolTable *newFunctionTable) {
    functionName = move(newFunctionName);
    localVariables.clear();
    tempVariables.clear();
    codes.clear();
    labels.clear();
    tempCount = 0;
    labelCount = 0;
    frameSize = 8;
    functionTable = newFunctionTable;
}

bool IRFunction::addParamVariable(IRSymbolVariable *newVariable) {
    paramVariables.emplace(newVariable->getSymbolName(), newVariable);
    return true;
}

bool IRFunction::addLocalVariable(int block, IRSymbolVariable *newVariable) {
    localVariables.emplace(newVariable->getSymbolName()+to_string(block), newVariable);
    return true;
}

IRTempVariable* IRFunction::addTempVariable(MetaDataType newMetaDataType) {
    string newTempVariableName = string("t_") + to_string(tempCount++);
    auto *newIRTempVar = new IRTempVariable(newTempVariableName, newMetaDataType);
    tempVariables.emplace(newTempVariableName, newIRTempVar);
    return newIRTempVar;
}

IRSymbolVariable* IRFunction::addSymbolVariable(int block, AbstractSymbol *newSymbol, IRValue *initVal) {
    auto *newSymVar = new IRSymbolVariable(newSymbol, initVal, false);
    addLocalVariable(block,newSymVar);
    return newSymVar;
}

bool IRFunction::addCode(IRCode *newCode) {
    codes.emplace_back(newCode);
}

bool IRFunction::addCodes(const vector<IRCode *>& newCodes){
    for (auto code : newCodes){
        codes.emplace_back(code);
    }
}


IRLabel* IRFunction::addLabel() {
    string newLabelName = string("L_") + to_string(labelCount++) + string("_") + functionName;
    auto *newLabel = new IRLabel(newLabelName);
    labels.emplace(newLabelName, newLabel);
    return newLabel;
}

int IRFunction::calFrameSize() {
    frameSize = 8;
    int varSize = 0;
    for (const auto& it : paramVariables) {
        varSize = AbstractSymbol::getOffsetFromDataType(it.second->getMetaDataType());
        it.second->setMemOffset(frameSize + varSize);
        frameSize += varSize;
    }
    for (const auto& it : localVariables) {
        varSize = AbstractSymbol::getOffsetFromDataType(it.second->getMetaDataType());
        it.second->setMemOffset(frameSize + varSize);
        frameSize += varSize;
    }
    for (const auto& it : tempVariables) {
        if (!it.second->getAliasToSymbol()) {
            varSize = AbstractSymbol::getOffsetFromDataType(it.second->getMetaDataType());
            it.second->setMemOffset(frameSize + varSize);
            frameSize += varSize;
        }
        else {
            it.second->setMemOffset(it.second->getInitialValue()->getMemOffset());
        }
    }
}

string IRFunction::getFunctionName() const {
    return functionName;
}

IRSymbolVariable *IRFunction::getLocalVariable(int block, const string& varName){
    for(int i = block; i >= 0; i--){
        if(localVariables.find(varName + to_string(i)) != localVariables.end())
            return localVariables[varName+ to_string(i)];
    }
    return nullptr;
}

IRSymbolVariable *IRFunction::getParamVariable(const string& varName){
    auto iter = paramVariables.find(varName);
    if(iter != paramVariables.end())
        return iter->second;
    return nullptr;
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

void IRFunction::print(SymbolTable *globalSymbolTable) const {
    auto functionTable = globalSymbolTable->lookUpFuncSymbolTable(functionName);
    cout << "----------- funcDef -----------" << endl;
    cout << functionTable->getFuncName() << "(";
    auto paramTypeList = functionTable->getParamDataTypeList();
    if (!paramTypeList.empty()) {
        for (auto param : vector<tuple<MetaDataType, bool, size_t>>(paramTypeList.begin(), paramTypeList.end() - 1)) {
            cout << static_cast<int>(get<0>(param));
            if (get<1>(param)) {
                cout << "[" << get<2>(param) << "]";
            }
            cout << ",";
        }
        auto param = paramTypeList.back();
        cout << static_cast<int>(get<0>(param));
        if (get<1>(param)) {
            cout << "[" << get<2>(param) << "]";
        }
    }
    cout << ") => " << static_cast<int>(functionTable->getReturnType()) << ":\n";
    cout << "----------- paramVars -----------" << endl;
    for (auto &symbolVar : paramVariables) {
        symbolVar.second->print();
    }
    cout << "----------- localVars -----------" << endl;
    for (auto &symbolVar : localVariables) {
        symbolVar.second->print();
    }
    cout << "----------- tempVars ------------" << endl;
    for (auto &symbolVar : tempVariables) {
        symbolVar.second->print();
    }
    cout << "----------- Codes ------------" << endl;
    cout << functionName << ":" << endl;
    for (auto &code : codes) {
        code->print();
    }
    cout << endl;
}

void IRFunction::targetCodeGen(TargetCodes *t) {
    t->addCodeDirectives(".text");
    t->addCodeDirectives(".align 1");
    t->addCodeDirectives(".globl\t" + functionName);
    t->addCodeDirectives(".type\t" + functionName + ", @function");
    t->addCodeLabel(functionName);
    bool hasFreeRegister;
    Register *ra = t->tryGetCertainRegister(true, "ra", hasFreeRegister);
    Register *sp = t->tryGetCertainRegister(true, "sp", hasFreeRegister);
    t->addCodeSd(sp, ra, -8, FloatPointType::NONE);
    t->setRegisterFree(true, ra);
    t->setRegisterFree(true, sp);
    for (auto &code : codes) {
        code->genTargetCode(t);
    }
    if (codes.back()->getOperation() != IROperation::RETURN) {
        Register *sp = t->tryGetCertainRegister(true, "sp", hasFreeRegister);
        Register *ra = t->tryGetCertainRegister(true, "ra", hasFreeRegister);
        t->addCodeLd(ra, sp, -8, FloatPointType::NONE);
        t->addCodeRet();
        t->setRegisterFree(true, sp);
    }
}

IRProgram::IRProgram() {}

IRProgram *IRProgram::getIRProgram(string newProgramName, SymbolTable *newGlobalSymbolTable) {
    // singleton
    static IRProgram instance;
    static bool initialized = false;
    if (!initialized) {
        instance.initializeFileds(newProgramName, newGlobalSymbolTable);
        initialized = true;
    }
    return &instance;
}

void IRProgram::initializeFileds(string newProgramName, SymbolTable *newGlobalSymbolTable) {
    programName = move(newProgramName);
    globalSymbolTable = newGlobalSymbolTable;
    globalVariables.clear();
    functions.clear();
    funcSymbols.clear();
    immValues.clear();
    valueCount = 0;
}

IRSymbolVariable* IRProgram::addGlobalVariable(AbstractSymbol* symbol, IRValue *newValue) {
    string valueKey = {};
    for (const auto &val : newValue->getValues()) {
        valueKey += (val + ",");
    }
    immValues.erase(valueKey);
    newValue = new IRValue(newValue->getMetaDataType(), newValue->getValues(), symbol->getSymbolName(), false);
    auto glbSymVar = new IRSymbolVariable(symbol, newValue, true);
    globalVariables.emplace(glbSymVar->getSymbolName(), glbSymVar);
    return glbSymVar;
}

bool IRProgram::addFunction(IRFunction *newFunction) {
    functions.emplace(newFunction->getFunctionName(), newFunction);
}

bool IRProgram::addSymbolFunction(IRSymbolFunction *funcSymbol) {
    funcSymbols.emplace(funcSymbol->getFunctionName(), funcSymbol);
}

IRValue *IRProgram::addImmValue(MetaDataType inMetaDataType, const string &inValue) {
    if (immValues.find(inValue) != immValues.end()) {
        return immValues[inValue];
    }
    auto *newValue = new IRValue(inMetaDataType, inValue, "ImmValue_" + to_string(valueCount++), false);
    immValues[inValue] = newValue;
    return newValue;
}

IRValue *IRProgram::addImmValue(const string &inLabel, MetaDataType inMetaDataType, const string &inValue) {
    if (immValues.find(inValue) != immValues.end()) {
        return immValues[inValue];
    }
    auto *newValue = new IRValue(inMetaDataType, inValue, inLabel, false);
    immValues[inValue] = newValue;
    return newValue;
}

IRValue *IRProgram::addMulSameImmValue(MetaDataType inMetaDataType, const string &inValue, int num) {
    string valueKey = {};
    vector<string> values;
    for (int i = 0; i < num; i++) {
        valueKey += (inValue + ",");
        values.push_back(inValue);
    }
    if (immValues.find(valueKey) != immValues.end()) {
        return immValues[valueKey];
    }
    auto *newValue = new IRValue(inMetaDataType, values, "ImmValue_" + to_string(valueCount++), true);
    immValues[valueKey] = newValue;
    return newValue;
}

IRValue *IRProgram::addMulImmValue(MetaDataType inMetaDataType, vector<string> &inValues) {
    string valueKey = {};
    for (auto &value : inValues) {
        valueKey += (value + ",");
    }
    if (immValues.find(valueKey) != immValues.end()) {
        return immValues[valueKey];
    }
    auto *newValue = new IRValue(inMetaDataType, inValues, "ImmValue_" + to_string(valueCount++), true);
    immValues[valueKey] = newValue;
    return newValue;
}

IRSymbolVariable *IRProgram::getGlobalVariable(const string& varName){
    auto iter = globalVariables.find(varName);
    if(iter != globalVariables.end())
        return iter->second;
    return nullptr;
}

IRFunction *IRProgram::getFunction(const string& functionName){
    return functions.at(functionName);
}

IRSymbolFunction *IRProgram::getSymbolFunction(const string& functionName){
    return funcSymbols.at(functionName);
}

IRValue *IRProgram::getImmValue(const string &inImmValue) {
    return immValues.at(inImmValue);
    return nullptr;
}

IRValue *IRProgram::getImmValue(const vector<string>& inImmValues) {
    string valueKey = {};
    for (auto &value : inImmValues) {
        valueKey += value;
    }
    return immValues.at(valueKey);
}

void IRProgram::print() {
    cout << "============ global var ================" << endl;
    for (auto &symbol : globalVariables) {
        symbol.second->print();
    }
    cout << "============ imm value ================" << endl;
    for (auto &imm : immValues) {
        imm.second->print();
    }
    cout << "============ functions ================" << endl;
    for (const auto& func : functions) {
        if ((func.second->getFunctionName().find_first_of("print_", 0) != 0) && (func.second->getFunctionName().find_first_of("get_", 0) != 0)) {
            func.second->print(globalSymbolTable);
        }
    }
}

void IRProgram::write(const string &path) {
    ofstream out;
    out.open(path, ios_base::out);
    streambuf *coutbuf = cout.rdbuf();
    cout.rdbuf(out.rdbuf());
    print();
    cout.rdbuf(coutbuf);
}

void IRProgram::targetGen(TargetCodes *t) {
    for (auto &globalVar : globalVariables) {
        t->addCodeDirectives(".data");
        t->addCodeDirectives(".globl\t" + globalVar.first);
        t->addCodeDirectives(".type\t" + globalVar.first + ", @object");
        globalVar.second->genTargetGlobalValue(t);
    }
    for (auto &imm : immValues) {
        imm.second->genTargetValue(t);
    }
    for (const auto& func : functions) {
        if ((func.second->getFunctionName().find_first_of("print_", 0) != 0) && (func.second->getFunctionName().find_first_of("get_", 0) != 0)) {
            func.second->targetCodeGen(t);
        }
    }
}

void IRProgram::targetCodePrint(TargetCodes *t) {
    t->printCode();
}

void IRProgram::targetCodeWrite(TargetCodes *t, string path) {
    t->codeWrite(path);
}
