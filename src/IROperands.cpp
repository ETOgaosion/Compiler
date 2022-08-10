#include "IROperands.h"

#include <utility>
#include <sstream>
#include "tools.h"

using namespace std;

IRLabel::IRLabel(string newName) : IROperand(OperandType::LABEL) {
    labelName = move(newName);
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
    allZero = false;
}

IRValue::IRValue(MetaDataType newMetaDataType, const string& newValue, const string &newLabel, bool newIsArray) : IROperand(OperandType::VALUE) {
    metaDataType = newMetaDataType;
    values.clear();
    values.push_back(newValue);
    valueLabel = newLabel;
    isArray = newIsArray;
    allZero = false;
}

IRValue::IRValue(MetaDataType newMetaDataType, const vector<string>& newValues, const string &newLabel, bool newIsArray) : IROperand(OperandType::VALUE) {
    metaDataType = newMetaDataType;
    values.clear();
    values = newValues;
    valueLabel = newLabel;
    isArray = newIsArray;
    allZero = false;
}

IRValue::IRValue(MetaDataType newMetaDataType, const std::vector<std::string>& newValues, std::vector<std::size_t> newShape, const std::string &newLabel) : IROperand(OperandType::VALUE) {
    metaDataType = newMetaDataType;
    values = newValues;
    valueLabel = newLabel;
    arrayShape = std::move(newShape);
    isArray = true;
    allZero = false;
}

IRValue::IRValue(MetaDataType newMetaDataType, bool newIsAllZero, bool newIsArray, std::vector<std::size_t> newArrayShape, std::string newValueLabel) : IROperand(OperandType::VALUE) {
    metaDataType = newMetaDataType;
    values.clear();
    valueLabel = std::move(newValueLabel);
    arrayShape = std::move(newArrayShape);
    isArray = newIsArray;
    allZero = newIsAllZero;
}

void IRValue::addValue(const string& newValue) {
    values.push_back(newValue);
}

void IRValue::addValues(const vector<string>& newValues) {
    for(const auto& newValue : newValues) {
        values.push_back(newValue);
    }
    isArray = true;
}

Register *IRValue::load(TargetCodes *t, bool isGeneralPurposeRegister) {
    MetaDataType dataType = metaDataType;
    bool hasFreeRegister;
    Register *freeRegister = nullptr;
    Register *retRegister = nullptr;
    if (valueLabel.empty()) {
        Register *zero = t->getNextFreeRegister(true, false, hasFreeRegister);
        if (dataType == MetaDataType::INT) {
            freeRegister =
                    t->getNextFreeRegister(true, false, hasFreeRegister);
            if (values.front() == "0") {
                t->addCodeEor(zero, zero, zero);
                t->addCodeMv(freeRegister, nullptr, zero, 0);
            }
            else {
                t->addCodeLdr(freeRegister, stoi(values.front()));
            }
        }
        else {
            freeRegister =
                    t->getNextFreeRegister(false, false, hasFreeRegister);
            if (values.front() == "0") {
                if (dataType == MetaDataType::FLOAT) {
                    t->addCodeEor(zero, zero, zero);
                    t->addCodeMv(freeRegister, zero, nullptr, 0);
                }
            }
        }
        t->setRegisterFree(zero);
        return freeRegister;
    }
    else {
        switch(dataType) {
            case MetaDataType::INT:
                freeRegister = t->getNextFreeRegister(true, false, hasFreeRegister);
                t->addCodeLdr(freeRegister, valueLabel, true);
                return freeRegister;
            case MetaDataType::FLOAT:
                freeRegister = t->getNextFreeRegister(true, false, hasFreeRegister);
                t->addCodeLdr(freeRegister, valueLabel, true);
                if (!isGeneralPurposeRegister) {
                    retRegister = t->getNextFreeRegister(false, false, hasFreeRegister);
                    t->addCodeMv(retRegister, freeRegister, nullptr, 0);
                    t->setRegisterFree(freeRegister);
                    return retRegister;
                }
                else {
                    return freeRegister;
                }
            default:
                return nullptr;
        }
    }
}

Register *IRValue::loadTo(TargetCodes *t, const string &regName, bool isGeneralPurposeRegister) {
    MetaDataType dataType = metaDataType;
    bool hasFreeRegister;
    Register *freeRegister = nullptr;
    Register *targetRegister = nullptr;
    if (valueLabel.empty()) {
        targetRegister =
                t->tryGetCertainRegister(true, regName, hasFreeRegister);
        Register *zero = t->getNextFreeRegister(true, false, hasFreeRegister);
        if (values.front() == "0") {
            t->addCodeEor(zero, zero, zero);
            t->addCodeMv(targetRegister, nullptr, zero, 0);
        }
        else {
            t->addCodeLdr(targetRegister, stoi(values.front()));
        }
        t->setRegisterFree(zero);
        return targetRegister;
    }
    else {
        switch(dataType) {
            case MetaDataType::INT:
                targetRegister = t->tryGetCertainRegister(true, regName, hasFreeRegister);
                t->addCodeLdr(targetRegister, valueLabel, true);
                return targetRegister;
            case MetaDataType::FLOAT:
                freeRegister = t->getNextFreeRegister(true, false, hasFreeRegister);
                t->addCodeLdr(freeRegister, valueLabel, true);
                if (!isGeneralPurposeRegister) {
                    targetRegister = t->tryGetCertainRegister(false, regName, hasFreeRegister);
                    t->addCodeMv(targetRegister, freeRegister, nullptr, 0);
                    t->setRegisterFree(freeRegister);
                    return targetRegister;
                }
                else {
                    return freeRegister;
                }
            default:
                return nullptr;
        }
    }
}

Register *IRValue::loadTo(TargetCodes *t, Register *inReg) {
    MetaDataType dataType = metaDataType;
    bool hasFreeRegister;
    Register *freeRegister = nullptr;
    if (valueLabel.empty()) {
        Register *zero = t->getNextFreeRegister(true, false, hasFreeRegister);
        if (values.front() == "0") {
            t->addCodeEor(zero, zero, zero);
            t->addCodeMv(inReg, nullptr, zero, 0);
        }
        else {
            if (stoi(values.front()) > -2048 && stoi(values.front()) < 2048) {
                t->addCodeEor(zero, zero, zero);
                t->addCodeAdd(inReg, zero, stoi(values.front()));
            }
            else {
                t->addCodeLdr(inReg, stoi(values.front()));
            }
        }
        t->setRegisterFree(zero);
        return inReg;
    }
    else {
        switch(dataType) {
            case MetaDataType::INT:
                t->addCodeLdr(inReg, valueLabel, true);
                return inReg;
            case MetaDataType::FLOAT:
                freeRegister = t->getNextFreeRegister(true, false, hasFreeRegister);
                t->addCodeLdr(freeRegister, valueLabel, true);
                t->addCodeMv(inReg, freeRegister, nullptr, 0);
                return inReg;
            default:
                return nullptr;
        }
    }
}

void IRValue::print() const {
    if (!valueLabel.empty()) {
        cout << valueLabel << ": ";
    }
    if (isArray) {
        cout << "{";
        for (const auto& value : vector<string>(values.begin(), values.end() - 1)) {
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
        for (const auto& value : vector<string>(values.begin(), values.end() - 1)) {
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
                stream << "0x" << hex << stoi(values.front());
                break;
            case MetaDataType::FLOAT:
                stream << Tools::ftoIEEE754s(stof(values.front()));
                break;
            default:
                break;
        }
        stream << endl;
    }
    else {
        t->addCodeLabel(valueLabel);
        for (const auto& value : values) {
            switch (metaDataType) {
                case MetaDataType::INT:
                    stream << "\t.word\t0x" << hex << stoi(value);
                    break;
                case MetaDataType::FLOAT:
                    stream << "\t.word\t" << Tools::ftoIEEE754s(stof(value));
                    break;
                default:
                    break;
            }
            stream << endl;
        }
    }
    t->addCodeDirectives(stream.str());
}

IRSymbolVariable::IRSymbolVariable(AbstractSymbol *newSymbol, IROperand *newValue, bool newIsGlobalSymbolVar) : IROperand(OperandType::SYMBOLVAR) {
    symbol = newSymbol;
    assigned = false;
    alive = false;
    historySymbols.clear();
    historySymbols.push_back(this);
    initialValue = newValue;
    isGlobalSymbolVar = newIsGlobalSymbolVar;
    bindRegister = false;
    targetBindRegister = nullptr;
}

Register *IRSymbolVariable::load(TargetCodes *t, bool isGeneralPurposeRegister) {
    MetaDataType dataType = symbol->getMetaDataType();
    bool hasFreeRegister;
    Register *freeRegister = nullptr;
    if (bindRegister) {
        switch (dataType) {
            case MetaDataType::INT:
                return targetBindRegister;
            case MetaDataType::FLOAT:
                if (!isGeneralPurposeRegister) {
                    return targetBindRegister;
                }
                else {
                    freeRegister = t->getNextFreeRegister(true, false, hasFreeRegister);
                    t->addCodeMv(freeRegister, targetBindRegister, nullptr, 0);
                    return freeRegister;
                }
                break;
            default:
                return nullptr;
        }
    }
    if (!isGlobalSymbolVar) {
        Register *sp = t->tryGetCertainRegister(true, "sp", hasFreeRegister);
        if (!getIsArray()) {
            switch(dataType) {
                case MetaDataType::INT:
                    freeRegister = t->getNextFreeRegister(true, false, hasFreeRegister);
                    t->addCodeLdr(freeRegister, sp, -symbol->getOffset());
                    break;
                case MetaDataType::FLOAT:
                    if (!isGeneralPurposeRegister) {
                        freeRegister = t->getNextFreeRegister(false, false, hasFreeRegister);
                        t->addCodeVldr(freeRegister, sp, -symbol->getOffset(), false);
                    }
                    else {
                        freeRegister = t->getNextFreeRegister(true, false, hasFreeRegister);
                        t->addCodeLdr(freeRegister, sp, -symbol->getOffset());
                    }
                    break;
                default:
                    break;
            }
        }
        else {
            freeRegister = t->getNextFreeRegister(true, false, hasFreeRegister);
            t->addCodeLdr(freeRegister, sp, -symbol->getOffset());
        }
        t->setRegisterFree(sp);
    }
    else {
        Register *tmpRegister = nullptr;
        if (!getIsArray()) {
            switch(dataType) {
                case MetaDataType::INT:
                    freeRegister = t->getNextFreeRegister(true, false, hasFreeRegister);
                    tmpRegister = t->getNextFreeRegister(true, false, hasFreeRegister);
                    t->addCodeLdr(tmpRegister, symbol->getSymbolName(), true);
                    t->addCodeLdr(freeRegister, tmpRegister, 0);
                    t->setRegisterFree(tmpRegister);
                    break;
                case MetaDataType::FLOAT:
                    tmpRegister = t->getNextFreeRegister(true, false, hasFreeRegister);
                    t->addCodeLdr(tmpRegister, symbol->getSymbolName(), true);
                    if (isGeneralPurposeRegister) {
                        freeRegister = t->getNextFreeRegister(true, false, hasFreeRegister);
                        t->addCodeLdr(freeRegister, tmpRegister, 0);
                    }
                    else {
                        freeRegister = t->getNextFreeRegister(false, false, hasFreeRegister);
                        t->addCodeVldr(freeRegister,  tmpRegister,  0, false);
                    }
                    t->setRegisterFree(tmpRegister);
                    break;
                default:
                    break;
            }
        }
        else {
            freeRegister = t->getNextFreeRegister(true, false, hasFreeRegister);
            t->addCodeLdr(freeRegister, symbol->getSymbolName(), true);
        }
    }
    return freeRegister;
}

Register *IRSymbolVariable::loadTo(TargetCodes *t, const string &regName, bool isGeneralPurposeRegister) {
    MetaDataType dataType = symbol->getMetaDataType();
    bool hasFreeRegister;
    Register *targetRegister = nullptr;
    if (bindRegister) {
        switch (dataType) {
            case MetaDataType::INT:
                targetRegister = targetBindRegister;
                if (targetBindRegister->getAliasName() != regName) {
                    targetRegister = t->tryGetCertainRegister(true, regName, hasFreeRegister);
                    t->addCodeMv(targetRegister, nullptr, targetBindRegister, 0);
                }
                return targetRegister;
            case MetaDataType::FLOAT:
                if (!isGeneralPurposeRegister) {
                    targetRegister = targetBindRegister;
                    if (targetBindRegister->getAliasName() != regName) {
                        targetRegister = t->tryGetCertainRegister(true, regName, hasFreeRegister);
                        t->addCodeMv(targetRegister, targetBindRegister, nullptr, 0);
                    }
                    return targetRegister;
                } else {
                    targetRegister = t->tryGetCertainRegister(true, regName, hasFreeRegister);
                    t->addCodeMv(targetRegister, targetBindRegister, nullptr, 0);
                    return targetRegister;
                }
                break;
            default:
                return nullptr;
        }
    }
    if (!isGlobalSymbolVar) {
        Register *sp = t->tryGetCertainRegister(true, "sp", hasFreeRegister);
        if (!getIsArray()) {
            switch(dataType) {
                case MetaDataType::INT:
                    targetRegister = t->tryGetCertainRegister(true, regName, hasFreeRegister);
                    t->addCodeLdr(targetRegister, sp, -symbol->getOffset());
                    break;
                case MetaDataType::FLOAT:
                    if (!isGeneralPurposeRegister) {
                        targetRegister = t->tryGetCertainRegister(false, regName, hasFreeRegister);
                        t->addCodeVldr(targetRegister, sp, -symbol->getOffset(), false);
                    }
                    else {
                        targetRegister = t->tryGetCertainRegister(true, regName, hasFreeRegister);
                        t->addCodeLdr(targetRegister, sp, -symbol->getOffset());
                    }
                    break;
                default:
                    break;
            }
        }
        else {
            targetRegister = t->tryGetCertainRegister(true, regName, hasFreeRegister);
            t->addCodeLdr(targetRegister, sp, -symbol->getOffset());
        }
        t->setRegisterFree(sp);
    }
    else {
        Register *tmpRegister = nullptr;
        if (!getIsArray()) {
            switch(dataType) {
                case MetaDataType::INT:
                    targetRegister = t->tryGetCertainRegister(true, regName, hasFreeRegister);
                    tmpRegister = t->getNextFreeRegister(true, false, hasFreeRegister);
                    t->addCodeLdr(tmpRegister, symbol->getSymbolName(), true);
                    t->addCodeLdr(tmpRegister, tmpRegister);
                    t->addCodeLdr(targetRegister, tmpRegister, 0);
                    t->setRegisterFree(tmpRegister);
                    break;
                case MetaDataType::FLOAT:
                    tmpRegister = t->getNextFreeRegister(true, false, hasFreeRegister);
                    t->addCodeLdr(tmpRegister, symbol->getSymbolName(), true);
                    t->addCodeLdr(tmpRegister, tmpRegister);
                    if (isGeneralPurposeRegister) {
                        targetRegister = t->tryGetCertainRegister(true, regName, hasFreeRegister);
                        t->addCodeLdr(targetRegister, tmpRegister, 0);
                    }
                    else {
                        targetRegister = t->tryGetCertainRegister(false, regName, hasFreeRegister);
                        t->addCodeVldr(targetRegister,  tmpRegister,  0, false);
                    }
                    t->setRegisterFree(tmpRegister);
                    break;
                default:
                    break;
            }
        }
        else {
            targetRegister = t->tryGetCertainRegister(true, regName, hasFreeRegister);
            t->addCodeLdr(targetRegister, symbol->getSymbolName(), true);
        }
    }
    return targetRegister;
}

Register *IRSymbolVariable::loadTo(TargetCodes *t, Register *inReg) {
    MetaDataType dataType = symbol->getMetaDataType();
    bool hasFreeRegister;
    if (bindRegister) {
        switch (dataType) {
            case MetaDataType::INT:
                if (targetBindRegister->getAliasName() != inReg->getAliasName()) {
                    t->addCodeMv(inReg, nullptr, targetBindRegister, 0);
                }
                return inReg;
            case MetaDataType::FLOAT:
                if (inReg->getRegisterType() == RegisterType::FLOAT_POINT) {
                    if (targetBindRegister->getAliasName() != inReg->getAliasName()) {
                        t->addCodeMv(inReg, targetBindRegister, nullptr, 0);
                    }
                    return inReg;
                } else {
                    t->addCodeMv(inReg, targetBindRegister, nullptr, 0);
                    return inReg;
                }
                break;
            default:
                return nullptr;
        }
    }
    if (!isGlobalSymbolVar) {
        Register *sp = t->tryGetCertainRegister(true, "sp", hasFreeRegister);
        switch(dataType) {
            case MetaDataType::INT:
                t->addCodeLdr(inReg, sp, -symbol->getOffset());
                break;
            case MetaDataType::FLOAT:
                t->addCodeVldr(inReg, sp, -symbol->getOffset(), false);
                break;
            default:
                break;
        }
        t->setRegisterFree(sp);
    }
    else {
        switch (inReg->getRegisterType()) {
            case RegisterType::GENERAL_PURPOSE:
                t->addCodeLdr(inReg, symbol->getSymbolName(), true);
                t->addCodeLdr(inReg, inReg);
                break;
            case RegisterType::FLOAT_POINT:
                Register *tmpRegister = t->getNextFreeRegister(true, false, hasFreeRegister);
                t->addCodeLdr(tmpRegister, symbol->getSymbolName(), true);
                t->addCodeLdr(tmpRegister, tmpRegister);
                t->addCodeMv(inReg, tmpRegister, nullptr, 0);
                t->setRegisterFree(tmpRegister);
                break;
        }
    }
    return inReg;
}

void IRSymbolVariable::storeFrom(TargetCodes *t, Register *reg) {
    MetaDataType dataType = symbol->getMetaDataType();
    bool hasFreeRegister;
    if (bindRegister) {
        switch (dataType) {
            case MetaDataType::INT:
                if (targetBindRegister->getAliasName() != reg->getAliasName()) {
                    t->addCodeMv(targetBindRegister, nullptr, reg, 0);
                }
                return;
            case MetaDataType::FLOAT:
                if (reg->getRegisterType() == RegisterType::FLOAT_POINT) {
                    if (targetBindRegister->getAliasName() != reg->getAliasName()) {
                        t->addCodeMv(targetBindRegister, reg, nullptr, 0);
                    }
                    return;
                } else {
                    t->addCodeMv(targetBindRegister, reg, nullptr, 0);
                    return;
                }
                break;
            default:
                break;
        }
    }
    if (!isGlobalSymbolVar) {
        Register *sp = t->tryGetCertainRegister(true, "sp", hasFreeRegister);
        switch(dataType) {
            case MetaDataType::INT:
                t->addCodeStr(sp, reg, -symbol->getOffset(), false);
                break;
            case MetaDataType::FLOAT:
                if (reg->getRegisterType() == RegisterType::GENERAL_PURPOSE) {
                    t->addCodeStr(sp, reg, -symbol->getOffset(), false);
                }
                else {
                    t->addCodeVstr(sp, reg, -symbol->getOffset(), false);
                }
                break;
            default:
                break;
        }
        t->setRegisterFree(sp);
    }
    else {
        Register *freeReg = t->getNextFreeRegister(true, false, hasFreeRegister);
        switch (reg->getRegisterType()) {
            case RegisterType::GENERAL_PURPOSE:
                t->addCodeLdr(freeReg, symbol->getSymbolName(), true);
                t->addCodeStr(freeReg, reg, 0, false);
                break;
            case RegisterType::FLOAT_POINT:
                t->addCodeLdr(freeReg, symbol->getSymbolName(), true);
                if (reg->getRegisterType() == RegisterType::GENERAL_PURPOSE) {
                    t->addCodeStr(freeReg, reg, 0, false);
                }
                else {
                    t->addCodeVstr(freeReg, reg, 0, false);
                }
                break;
            default:
                break;
        }
        t->setRegisterFree(freeReg);
    }
}

void IRSymbolVariable::print() const {
    cout << symbol->getSymbolName() << " := symbol type: " << static_cast<int>(symbol->getSymbolType()) << "; data type: " << static_cast<int>(symbol->getMetaDataType());
    if (initialValue) {
        cout << "; initValue: ";
        initialValue->print();
    }
    cout << endl;
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
                stream << "0x" << hex << stoi(values.front());
                break;
            case MetaDataType::FLOAT:
                stream << Tools::ftoIEEE754s(stof(values.front()));
                break;
            default:
                break;
        }
        stream << endl;
    }
    else {
        t->addCodeLabel(initialValue->getValueLabel());
        for (const auto& value : values) {
            switch (initialValue->getMetaDataType()) {
                case MetaDataType::INT:
                    stream << "\t.word\t0x" << hex << stoi(value);
                    break;
                case MetaDataType::FLOAT:
                    stream << "\t.word\t" << Tools::ftoIEEE754s(stof(value));
                    break;
                default:
                    break;
            }
            stream << endl;
        }
    }
    t->addCodeDirectives(stream.str());
}

void IRSymbolVariable::genTargetGlobalValue(TargetCodes *t) const {
    stringstream stream;
    vector<string> values = initialValue->getValues();
    if (values.size() == 1) {
        t->addCodeLabel(initialValue->getValueLabel());
        stream << "\t.word\t";
        switch (initialValue->getMetaDataType()) {
            case MetaDataType::INT:
                stream << "0x" << hex << stoi(values.front());
                break;
            case MetaDataType::FLOAT:
                stream << Tools::ftoIEEE754s(stof(values.front()));
                break;
            default:
                break;
        }
        stream << endl;
    }
    else {
        t->addCodeLabel(initialValue->getValueLabel());
        for (const auto& value : values) {
            switch (initialValue->getMetaDataType()) {
                case MetaDataType::INT:
                    stream << "\t.word\t0x" << hex << stoi(value);
                    break;
                case MetaDataType::FLOAT:
                    stream << "\t.word\t" << Tools::ftoIEEE754s(stof(value));
                    break;
                default:
                    break;
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
    for (auto param : vector<tuple<MetaDataType, bool, vector<size_t>>>(paramTypeList.begin(), paramTypeList.end() - 1)) {
        cout << static_cast<int>(get<0>(param));
        if (get<1>(param)) {
            for (auto it : get<2>(param)) {
                cout << "[" << it << "]";
            }
        }
        cout << ",";
    }
    auto param = paramTypeList.back();
    cout << static_cast<int>(get<0>(param));
    if (get<1>(param)) {
        for (auto it : get<2>(param)) {
            cout << "[" << it << "]";
        }
    }
    cout << ") => " << static_cast<int>(functionTable->getReturnType()) << "\n";
}

string IRSymbolFunction::getVal() const {
    return functionTable->getFuncName();
}



IRTempVariable::IRTempVariable(string newName, MetaDataType newMetaDataType) : IROperand(OperandType::TEMPVAR) {
    symbolName = move(newName);
    metaDataType = newMetaDataType;
    assigned = false;
    historySymbols.clear();
    historySymbols.push_back(this);
    alive = false;
    aliasToVar = false;
    parentVariable = nullptr;
    offset = 0;
    initialValue = nullptr;
    bindRegister = false;
    targetBindRegister = nullptr;
    isArray = false;
}

IRTempVariable::IRTempVariable(std::string newName, MetaDataType newMetaDataType, std::vector<std::size_t> newShape, bool newIsArray) : IROperand(OperandType::TEMPVAR) {
    symbolName = move(newName);
    metaDataType = newMetaDataType;
    arrayShape = std::move(newShape);
    isArray = newIsArray;
    assigned = false;
    historySymbols.clear();
    historySymbols.push_back(this);
    alive = false;
    aliasToVar = false;
    parentVariable = nullptr;
    offset = 0;
    initialValue = nullptr;
    bindRegister = false;
    targetBindRegister = nullptr;
}

IRTempVariable::IRTempVariable(string newName, MetaDataType newMetaDataType, IROperand *newParentVariable) : IROperand(OperandType::TEMPVAR) {
    symbolName = move(newName);
    metaDataType = newMetaDataType;
    assigned = false;
    historySymbols.clear();
    historySymbols.push_back(this);
    aliasToVar = true;
    parentVariable = newParentVariable;
    offset = 0;
    initialValue = nullptr;
    isArray = false;
    arrayShape = {};
    bindRegister = false;
    targetBindRegister = nullptr;
    alive = false;
}

IRTempVariable::IRTempVariable(string newName, MetaDataType newMetaDataType, IRValue *newValue) : IROperand(OperandType::TEMPVAR) {
    symbolName = move(newName);
    metaDataType = newMetaDataType;
    assigned = false;
    historySymbols.clear();
    historySymbols.push_back(this);
    aliasToVar = false;
    parentVariable = nullptr;
    offset = 0;
    initialValue = newValue;
    isArray = false;
    arrayShape = {};
    bindRegister = false;
    targetBindRegister = nullptr;
    alive = false;
}

Register *IRTempVariable::load(TargetCodes *t, bool isGeneralPurposeRegister) {
    if (!aliasToVar) {
        bool hasFreeRegister;
        Register *freeRegister = nullptr;
        if (bindRegister) {
            switch (metaDataType) {
                case MetaDataType::INT:
                    return targetBindRegister;
                case MetaDataType::FLOAT:
                    if (!isGeneralPurposeRegister) {
                        return targetBindRegister;
                    }
                    else {
                        freeRegister = t->getNextFreeRegister(true, false, hasFreeRegister);
                        t->addCodeMv(freeRegister, targetBindRegister, nullptr, 0);
                        return freeRegister;
                    }
                    break;
                default:
                    break;
            }
        }
        Register *sp = t->tryGetCertainRegister(true, "sp", hasFreeRegister);
        switch(metaDataType) {
            case MetaDataType::INT:
                freeRegister = t->getNextFreeRegister(true, false, hasFreeRegister);
                t->addCodeLdr(freeRegister, sp, -offset);
                break;
            case MetaDataType::FLOAT:
                if (!isGeneralPurposeRegister) {
                    freeRegister = t->getNextFreeRegister(false, false, hasFreeRegister);
                    t->addCodeVldr(freeRegister, sp, -offset, false);
                }
                else {
                    freeRegister = t->getNextFreeRegister(true, false, hasFreeRegister);
                    t->addCodeLdr(freeRegister, sp, -offset);
                }
                break;
            default:
                break;
        }
        t->setRegisterFree(sp);
        return freeRegister;
    }
    else {
        return parentVariable->load(t, isGeneralPurposeRegister);
    }
}

Register *IRTempVariable::loadTo(TargetCodes *t, const string &regName, bool isGeneralPurposeRegister) {
    if (!aliasToVar) {
        bool hasFreeRegister;
        Register *sp = t->tryGetCertainRegister(true, "sp", hasFreeRegister);
        Register *targetRegister = nullptr;
        if (bindRegister) {
            switch (metaDataType) {
                case MetaDataType::INT:
                    targetRegister = targetBindRegister;
                    if (targetBindRegister->getAliasName() != regName) {
                        targetRegister = t->tryGetCertainRegister(true, regName, hasFreeRegister);
                        t->addCodeMv(targetRegister, nullptr, targetBindRegister, 0);
                    }
                    return targetRegister;
                case MetaDataType::FLOAT:
                    if (!isGeneralPurposeRegister) {
                        targetRegister = targetBindRegister;
                        if (targetBindRegister->getAliasName() != regName) {
                            targetRegister = t->tryGetCertainRegister(true, regName, hasFreeRegister);
                            t->addCodeMv(targetRegister, targetBindRegister, nullptr, 0);
                        }
                        return targetRegister;
                    } else {
                        targetRegister = t->tryGetCertainRegister(true, regName, hasFreeRegister);
                        t->addCodeMv(targetRegister, targetBindRegister, nullptr, 0);
                        return targetRegister;
                    }
                    break;
                default:
                    break;
            }
        }
        switch(metaDataType) {
            case MetaDataType::INT:
                targetRegister = t->tryGetCertainRegister(true, regName, hasFreeRegister);
                t->addCodeLdr(targetRegister, sp, -offset);
                break;
            case MetaDataType::FLOAT:
                if (isGeneralPurposeRegister) {
                    targetRegister = t->tryGetCertainRegister(false, regName, hasFreeRegister);
                    t->addCodeVldr(targetRegister, sp, -offset, false);
                }
                else {
                    targetRegister = t->tryGetCertainRegister(true, regName, hasFreeRegister);
                    t->addCodeLdr(targetRegister, sp, -offset);
                }
                break;
            default:
                break;
        }
        t->setRegisterFree(sp);
        return targetRegister;
    }
    else {
        return parentVariable->loadTo(t, regName, isGeneralPurposeRegister);
    }
}

Register *IRTempVariable::loadTo(TargetCodes *t, Register *inReg) {
    if (!aliasToVar) {
        bool hasFreeRegister;
        if (bindRegister) {
            switch (metaDataType) {
                case MetaDataType::INT:
                    if (targetBindRegister->getAliasName() != inReg->getAliasName()) {
                        t->addCodeMv(inReg, nullptr, targetBindRegister, 0);
                    }
                    return inReg;
                case MetaDataType::FLOAT:
                    if (inReg->getRegisterType() == RegisterType::FLOAT_POINT) {
                        if (targetBindRegister->getAliasName() != inReg->getAliasName()) {
                            t->addCodeMv(inReg, targetBindRegister, nullptr, 0);
                        }
                        return inReg;
                    } else {
                        t->addCodeMv(inReg, targetBindRegister, nullptr, 0);
                        return inReg;
                    }
                    break;
                default:
                    break;
            }
        }
        Register *sp = t->tryGetCertainRegister(true, "sp", hasFreeRegister);
        switch (metaDataType) {
            case MetaDataType::INT:
                t->addCodeLdr(inReg, sp, -offset);
                break;
            case MetaDataType::FLOAT:
                t->addCodeVldr(inReg, sp, -offset, false);
                break;
            default:
                break;
        }
        t->setRegisterFree(sp);
        return inReg;
    }
    else {
        return parentVariable->loadTo(t, inReg);
    }
}

void IRTempVariable::storeFrom(TargetCodes *t, Register *reg) {
    if (!aliasToVar) {
        bool hasFreeRegister;
        if (bindRegister) {
            switch (metaDataType) {
                case MetaDataType::INT:
                    if (targetBindRegister->getAliasName() != reg->getAliasName()) {
                        t->addCodeMv(targetBindRegister, nullptr, reg, 0);
                    }
                    return;
                case MetaDataType::FLOAT:
                    if (reg->getRegisterType() == RegisterType::FLOAT_POINT) {
                        if (targetBindRegister->getAliasName() != reg->getAliasName()) {
                            t->addCodeMv(targetBindRegister, reg, nullptr, 0);
                        }
                        return;
                    } else {
                        t->addCodeMv(targetBindRegister, reg, nullptr, 0);
                        return;
                    }
                    break;
                default:
                    break;
            }
        }
        Register *sp = t->tryGetCertainRegister(true, "sp", hasFreeRegister);
        switch(metaDataType) {
            case MetaDataType::INT:
                t->addCodeStr(sp, reg, -offset, false);
                break;
            case MetaDataType::FLOAT:
                if (reg->getRegisterType() == RegisterType::GENERAL_PURPOSE) {
                    t->addCodeStr(sp, reg, -offset, false);
                }
                else {
                    t->addCodeVstr(sp, reg, -offset, false);
                }
                break;
            default:
                break;
        }
        t->setRegisterFree(sp);
    }
    else {
        return parentVariable->storeFrom(t, reg);
    }
}

void IRTempVariable::print() const {
    if (!aliasToVar) {
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