#include "IROperands.h"

#include <utility>
#include <sstream>
#include "tools.h"

using namespace std;

IRLabel::IRLabel(string newName) : IROperand(OperandType::LABEL) {
    labelName = std::move(newName);
}

void IRLabel::print() const {
    cout << "label: " << labelName <<endl;
}

string IRLabel::getVal() const {
    return labelName;
}

IRValue::IRValue(MetaDataType newMetaDataType, const string &newLabel, bool newIsArray) : IROperand(OperandType::VALUE) {
    metaDataType = newMetaDataType;
    values.clear();
    valueLabel = newLabel;
    isArray = newIsArray;
}

IRValue::IRValue(MetaDataType newMetaDataType, const std::string& newValue, const std::string &newLabel, bool newIsArray) : IROperand(OperandType::VALUE) {
    metaDataType = newMetaDataType;
    values.clear();
    values.push_back(newValue);
    valueLabel = newLabel;
    isArray = newIsArray;
}

IRValue::IRValue(MetaDataType newMetaDataType, const std::vector<std::string>& newValues, const string &newLabel, bool newIsArray) : IROperand(OperandType::VALUE) {
    metaDataType = newMetaDataType;
    values.clear();
    for(const auto& newValue : newValues) {
        values.push_back(newValue);
    }
    valueLabel = newLabel;
    isArray = newIsArray;
}

void IRValue::addValue(const string& newValue) {
    values.push_back(newValue);
}

void IRValue::addValues(const std::vector<std::string>& newValues) {
    for(const auto& newValue : newValues) {
        values.push_back(newValue);
    }
    isArray = true;
}

Register *IRValue::load(TargetCodes *t) {
    MetaDataType dataType = metaDataType;
    bool hasFreeRegister;
    Register *freeRegister = nullptr;
    Register *retRegister = nullptr;
    switch(dataType) {
        case MetaDataType::BOOL:
        case MetaDataType::INT:
            freeRegister = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
            t->addCodeLi(freeRegister, valueLabel);
            return freeRegister;
        case MetaDataType::FLOAT:
            freeRegister = t->getNextFreeRegister(false, false, FloatPointType::NONE, hasFreeRegister);
            t->addCodeLi(freeRegister, valueLabel);
            retRegister = t->getNextFreeRegister(false, false, FloatPointType::SINGLE, hasFreeRegister);
            t->addCodeMv(retRegister, freeRegister, FloatPointType::SINGLE, FloatPointType::NONE);
            freeRegister->setFree();
            return retRegister;
        case MetaDataType::DOUBLE:
            freeRegister = t->getNextFreeRegister(false, false, FloatPointType::NONE, hasFreeRegister);
            t->addCodeLi(freeRegister, valueLabel);
            retRegister = t->getNextFreeRegister(false, false, FloatPointType::DOUBLE, hasFreeRegister);
            t->addCodeMv(retRegister, freeRegister, FloatPointType::DOUBLE, FloatPointType::NONE);
            freeRegister->setFree();
            return retRegister;
    }
}

Register *IRValue::loadTo(TargetCodes *t, const std::string &regName) {
    MetaDataType dataType = metaDataType;
    bool hasFreeRegister;
    Register *freeRegister = nullptr;
    Register *targetRegister = nullptr;
    switch(dataType) {
        case MetaDataType::BOOL:
        case MetaDataType::INT:;
            targetRegister = t->tryGetCertainRegister(true, regName, hasFreeRegister);
            t->addCodeLi(targetRegister, valueLabel);
            return targetRegister;
        case MetaDataType::FLOAT:
            freeRegister = t->getNextFreeRegister(false, false, FloatPointType::NONE, hasFreeRegister);
            t->addCodeLi(freeRegister, valueLabel);
            targetRegister = t->tryGetCertainRegister(true, regName, hasFreeRegister);
            t->addCodeMv(targetRegister, freeRegister, FloatPointType::SINGLE, FloatPointType::NONE);
            freeRegister->setFree();
            return targetRegister;
        case MetaDataType::DOUBLE:
            freeRegister = t->getNextFreeRegister(false, false, FloatPointType::NONE, hasFreeRegister);
            t->addCodeLi(freeRegister, valueLabel);
            targetRegister = t->tryGetCertainRegister(true, regName, hasFreeRegister);
            t->addCodeMv(targetRegister, freeRegister, FloatPointType::DOUBLE, FloatPointType::NONE);
            freeRegister->setFree();
            return targetRegister;
    }
}

Register *IRValue::loadTo(TargetCodes *t, Register *inReg) {
    MetaDataType dataType = metaDataType;
    bool hasFreeRegister;
    Register *freeRegister = nullptr;
    switch(dataType) {
        case MetaDataType::BOOL:
        case MetaDataType::INT:;
            t->addCodeLi(inReg, valueLabel);
            return inReg;
        case MetaDataType::FLOAT:
            freeRegister = t->getNextFreeRegister(false, false, FloatPointType::NONE, hasFreeRegister);
            t->addCodeLi(freeRegister, valueLabel);
            t->addCodeMv(inReg, freeRegister, FloatPointType::SINGLE, FloatPointType::NONE);
            freeRegister->setFree();
            return inReg;
        case MetaDataType::DOUBLE:
            freeRegister = t->getNextFreeRegister(false, false, FloatPointType::NONE, hasFreeRegister);
            t->addCodeLi(freeRegister, valueLabel);
            t->addCodeMv(inReg, freeRegister, FloatPointType::DOUBLE, FloatPointType::NONE);
            freeRegister->setFree();
            return inReg;
    }
}

void IRValue::print() const {
    if (!valueLabel.empty()) {
        cout << valueLabel << ": ";
    }
    if (isArray) {
        cout << "{";
        for (auto value : std::vector<string>(values.begin(), values.end() - 1)) {
            cout << value << ", ";
        }
        cout << values.back();
        cout << "}";
    }
    else {
        cout << values.front();
    }
    cout << endl;
}

string IRValue::getVal() const {
    string retVal = {};
    if (!valueLabel.empty()) {
        retVal += (valueLabel + ": ");
    }
    if (isArray) {
        retVal += "{";
        for (auto value : std::vector<string>(values.begin(), values.end() - 1)) {
            retVal += (value + ", ");
        }
        retVal += values.back();
        retVal += "}";
    }
    else {
        retVal += values.front();
    }
    return retVal;
}

void IRValue::genTargetValue(TargetCodes *t) const {
    stringstream stream;
    if (values.size() == 1) {
        stream << "\t.equ\t" << valueLabel << ", ";
        switch (metaDataType) {
            case MetaDataType::INT:
                stream << "0x" << std::hex << stoi(values.front());
            case MetaDataType::FLOAT:
                stream << Tools::ftoIEEE754s(stof(values.front()));
            case MetaDataType::DOUBLE:
                stream << Tools::dtoIEEE754s(stod(values.front()));
        }
        stream << endl;
    }
    else {
        t->addCodeLabel(valueLabel);
        for (const auto& value : values) {
            stream << ".word\t";
            switch (metaDataType) {
                case MetaDataType::INT:
                    stream << "0x" << std::hex << stoi(value);
                case MetaDataType::FLOAT:
                    stream << Tools::ftoIEEE754s(stof(value));
                case MetaDataType::DOUBLE:
                    stream << Tools::dtoIEEE754s(stod(value));
            }
            stream << endl;
        }
    }
    t->addCodeDirectives(stream.str());
}

IRSymbolVariable::IRSymbolVariable(AbstractSymbol *newSymbol, IRValue *newValue) : IROperand(OperandType::SYMBOLVAR) {
    symbol = newSymbol;
    assigned = false;
    historySymbols.clear();
    initialValue = newValue;
}

Register *IRSymbolVariable::load(TargetCodes *t) {
    MetaDataType dataType = symbol->getMetaDataType();
    bool hasFreeRegister;
    Register *sp = t->tryGetCertainRegister(true, "sp", hasFreeRegister);
    Register *freeRegister = nullptr;
    switch(dataType) {
        case MetaDataType::BOOL:
        case MetaDataType::INT:;
            freeRegister = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
            t->addCodeLoad(freeRegister, sp, -symbol->getOffset(), FloatPointType::NONE);
            break;
        case MetaDataType::FLOAT:
            freeRegister = t->getNextFreeRegister(false, false, FloatPointType::SINGLE, hasFreeRegister);
            t->addCodeLoad(freeRegister, sp, -symbol->getOffset(), FloatPointType::SINGLE);
            break;
        case MetaDataType::DOUBLE:
            freeRegister = t->getNextFreeRegister(false, false, FloatPointType::DOUBLE, hasFreeRegister);
            t->addCodeLoad(freeRegister, sp, -symbol->getOffset(), FloatPointType::DOUBLE);
            break;
    }
    sp->setFree();
}

Register *IRSymbolVariable::loadTo(TargetCodes *t, const std::string &regName) {
    MetaDataType dataType = symbol->getMetaDataType();
    bool hasFreeRegister;
    Register *sp = t->tryGetCertainRegister(true, "sp", hasFreeRegister);
    Register *targetRegister = nullptr;
    switch(dataType) {
        case MetaDataType::BOOL:
        case MetaDataType::INT:;
            targetRegister = t->tryGetCertainRegister(true, regName, hasFreeRegister);
            t->addCodeLoad(targetRegister, sp, -symbol->getOffset(), FloatPointType::NONE);
            break;
        case MetaDataType::FLOAT:
            targetRegister = t->tryGetCertainRegister(false, regName, hasFreeRegister);
            t->addCodeLoad(targetRegister, sp, -symbol->getOffset(), FloatPointType::SINGLE);
            break;
        case MetaDataType::DOUBLE:
            targetRegister = t->tryGetCertainRegister(false, regName, hasFreeRegister);
            t->addCodeLoad(targetRegister, sp, -symbol->getOffset(), FloatPointType::DOUBLE);
            break;
    }
    sp->setFree();
}

Register *IRSymbolVariable::loadTo(TargetCodes *t, Register *inReg) {
    bool hasFreeRegister;
    Register *sp = t->tryGetCertainRegister(true, "sp", hasFreeRegister);
    t->addCodeLoad(inReg, sp, -symbol->getOffset(), inReg->getFloatPointType());
    sp->setFree();
}

void IRSymbolVariable::storeFrom(TargetCodes *t, Register *reg) {
    MetaDataType dataType = symbol->getMetaDataType();
    bool hasFreeRegister;
    Register *sp = t->tryGetCertainRegister(true, "sp", hasFreeRegister);
    switch(dataType) {
        case MetaDataType::BOOL:
        case MetaDataType::INT:
            t->addCodeStore(sp, reg, -symbol->getOffset(), FloatPointType::NONE);
            break;
        case MetaDataType::FLOAT:
            t->addCodeStore(sp, reg, -symbol->getOffset(), FloatPointType::SINGLE);
            break;
        case MetaDataType::DOUBLE:
            t->addCodeStore(sp, reg, -symbol->getOffset(), FloatPointType::DOUBLE);
            break;
    }
    reg->setFree();
    sp->setFree();
}

void IRSymbolVariable::print() const {
    cout << symbol->getSymbolName() << " := symbol type: " << static_cast<int>(symbol->getSymbolType()) << "; data type: " << static_cast<int>(symbol->getMetaDataType()) << "; initValue: ";
    initialValue->print();
}

string IRSymbolVariable::getVal() const {
    return symbol->getSymbolName();
}

void IRSymbolVariable::genTargetValue(TargetCodes *t) const {
    stringstream stream;
    vector<string> values = initialValue->getValues();
    if (values.size() == 1) {
        stream << "\t.equ\t" << initialValue->getValueLabel() << ", ";
        switch (initialValue->getMetaDataType()) {
            case MetaDataType::INT:
                stream << "0x" << std::hex << stoi(values.front());
            case MetaDataType::FLOAT:
                stream << Tools::ftoIEEE754s(stof(values.front()));
            case MetaDataType::DOUBLE:
                stream << Tools::dtoIEEE754s(stod(values.front()));
        }
        stream << endl;
    }
    else {
        t->addCodeLabel(initialValue->getValueLabel());
        for (const auto& value : values) {
            stream << ".word\t";
            switch (initialValue->getMetaDataType()) {
                case MetaDataType::INT:
                    stream << "0x" << std::hex << stoi(value);
                case MetaDataType::FLOAT:
                    stream << Tools::ftoIEEE754s(stof(value));
                case MetaDataType::DOUBLE:
                    stream << Tools::dtoIEEE754s(stod(value));
            }
            stream << endl;
        }
    }
    t->addCodeDirectives(stream.str());
}

IRSymbolFunction::IRSymbolFunction(SymbolTable *function) : IROperand(OperandType::SYMBOLFUNC) {
    functionTable = function;
}

void IRSymbolFunction::print() const {
    cout << functionTable->getFuncName() << "(";
    auto paramTypeList = functionTable->getParamDataTypeList();
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
    cout << ") => " << static_cast<int>(functionTable->getReturnType()) << "\n";
}

string IRSymbolFunction::getVal() const {
    return functionTable->getFuncName();
}


IRTempVariable::IRTempVariable(string newName, MetaDataType newMetaDataType) : IROperand(OperandType::TEMPVAR) {
    symbolName = std::move(newName);
    metaDataType = newMetaDataType;
    assigned = false;
    aliasToSymbol = false;
    symbolVariable = nullptr;
    offset = 0;
    initialValue = nullptr;
}

IRTempVariable::IRTempVariable(std::string newName, MetaDataType newMetaDataType, IRSymbolVariable *parentVariable) : IROperand(OperandType::TEMPVAR) {
    symbolName = std::move(newName);
    metaDataType = newMetaDataType;
    assigned = false;
    aliasToSymbol = true;
    symbolVariable = parentVariable;
    offset = 0;
    initialValue = nullptr;
}

IRTempVariable::IRTempVariable(std::string newName, MetaDataType newMetaDataType, IRValue *newValue) : IROperand(OperandType::TEMPVAR) {
    symbolName = std::move(newName);
    metaDataType = newMetaDataType;
    assigned = false;
    aliasToSymbol = false;
    symbolVariable = nullptr;
    offset = 0;
    initialValue = newValue;
}


Register *IRTempVariable::load(TargetCodes *t) {
    bool hasFreeRegister;
    Register *sp = t->tryGetCertainRegister(true, "sp", hasFreeRegister);
    Register *freeRegister = nullptr;
    switch(metaDataType) {
        case MetaDataType::BOOL:
        case MetaDataType::INT:;
            freeRegister = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
            t->addCodeLoad(freeRegister, sp, -offset, FloatPointType::NONE);
            break;
        case MetaDataType::FLOAT:
            freeRegister = t->getNextFreeRegister(false, false, FloatPointType::SINGLE, hasFreeRegister);
            t->addCodeLoad(freeRegister, sp, -offset, FloatPointType::SINGLE);
            break;
        case MetaDataType::DOUBLE:
            freeRegister = t->getNextFreeRegister(false, false, FloatPointType::DOUBLE, hasFreeRegister);
            t->addCodeLoad(freeRegister, sp, -offset, FloatPointType::DOUBLE);
            break;
    }
    sp->setFree();
}

Register *IRTempVariable::loadTo(TargetCodes *t, const std::string &regName) {
    bool hasFreeRegister;
    Register *sp = t->tryGetCertainRegister(true, "sp", hasFreeRegister);
    Register *targetRegister = nullptr;
    switch(metaDataType) {
        case MetaDataType::BOOL:
        case MetaDataType::INT:;
            targetRegister = t->tryGetCertainRegister(true, regName, hasFreeRegister);
            t->addCodeLoad(targetRegister, sp, -offset, FloatPointType::NONE);
            break;
        case MetaDataType::FLOAT:
            targetRegister = t->tryGetCertainRegister(false, regName, hasFreeRegister);
            t->addCodeLoad(targetRegister, sp, -offset, FloatPointType::SINGLE);
            break;
        case MetaDataType::DOUBLE:
            targetRegister = t->tryGetCertainRegister(false, regName, hasFreeRegister);
            t->addCodeLoad(targetRegister, sp, -offset, FloatPointType::DOUBLE);
            break;
    }
    sp->setFree();
}

Register *IRTempVariable::loadTo(TargetCodes *t, Register *inReg) {
    bool hasFreeRegister;
    Register *sp = t->tryGetCertainRegister(true, "sp", hasFreeRegister);
    t->addCodeLoad(inReg, sp, -offset, inReg->getFloatPointType());
    sp->setFree();
}

void IRTempVariable::storeFrom(TargetCodes *t, Register *reg) {
    bool hasFreeRegister;
    Register *sp = t->tryGetCertainRegister(true, "sp", hasFreeRegister);
    switch(metaDataType) {
        case MetaDataType::BOOL:
        case MetaDataType::INT:
            t->addCodeStore(sp, reg, -offset, FloatPointType::NONE);
            break;
        case MetaDataType::FLOAT:
            t->addCodeStore(sp, reg, -offset, FloatPointType::SINGLE);
            break;
        case MetaDataType::DOUBLE:
            t->addCodeStore(sp, reg, -offset, FloatPointType::DOUBLE);
            break;
    }
    sp->setFree();
}

void IRTempVariable::print() const {
    if (!aliasToSymbol) {
        cout << symbolName << ":= symbol type: TEMP VAR; data type: " << static_cast<int>(metaDataType);
        if (initialValue) {
            cout << "; initValue: ";
            initialValue->print();
        }
        cout << endl;
    }
}

string IRTempVariable::getVal() const {
    return symbolName;
}