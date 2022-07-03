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
}

IRValue::IRValue(MetaDataType newMetaDataType, const string& newValue, const string &newLabel, bool newIsArray) : IROperand(OperandType::VALUE) {
    metaDataType = newMetaDataType;
    values.clear();
    values.push_back(newValue);
    valueLabel = newLabel;
    isArray = newIsArray;
}

IRValue::IRValue(MetaDataType newMetaDataType, const vector<string>& newValues, const string &newLabel, bool newIsArray) : IROperand(OperandType::VALUE) {
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
        Register *zero = t->tryGetCertainRegister(true, "zero", hasFreeRegister);
        if (dataType == MetaDataType::BOOL || dataType == MetaDataType::INT) {
            freeRegister = 
            t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
            if (values.front() == "0") {
                t->addCodeMv(freeRegister, zero,FloatPointType::NONE, FloatPointType::NONE);
            }
            else {
                t->addCodeAddi(freeRegister, zero, stoi(values.front()));
            }
        }
        else {
            freeRegister = 
            t->getNextFreeRegister(false, false, FloatPointType::NONE, hasFreeRegister);
            if (values.front() == "0") {
                if (dataType == MetaDataType::FLOAT) {
                    t->addCodeMv(freeRegister, zero, FloatPointType::SINGLE, FloatPointType::NONE);
                }
                else {
                    t->addCodeMv(freeRegister, zero, FloatPointType::DOUBLE, FloatPointType::NONE);
                }
            }
        }
        t->setRegisterFree(zero);
        return freeRegister;
    }
    else {
        switch(dataType) {
            case MetaDataType::BOOL:
            case MetaDataType::INT:
                freeRegister = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
                t->addCodeLi(freeRegister, valueLabel);
                return freeRegister;
            case MetaDataType::FLOAT:
                freeRegister = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
                t->addCodeLi(freeRegister, valueLabel);
                if (!isGeneralPurposeRegister) {
                    retRegister = t->getNextFreeRegister(false, false, FloatPointType::SINGLE, hasFreeRegister);
                    t->addCodeMv(retRegister, freeRegister, FloatPointType::SINGLE, FloatPointType::NONE);
                    t->setRegisterFree(freeRegister);
                    return retRegister;
                }
                else {
                    return freeRegister;
                }
            case MetaDataType::DOUBLE:
                freeRegister = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
                t->addCodeLi(freeRegister, valueLabel);
                if (!isGeneralPurposeRegister) {
                retRegister = t->getNextFreeRegister(false, false, FloatPointType::DOUBLE, hasFreeRegister);
                t->addCodeMv(retRegister, freeRegister, FloatPointType::DOUBLE, FloatPointType::NONE);
                t->setRegisterFree(freeRegister);
                return retRegister;
                }
                else{
                    return freeRegister;
                }
            default:
                break;
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
        Register *zero = t->tryGetCertainRegister(true, "zero", hasFreeRegister);
        if (values.front() == "0") {
            t->addCodeMv(targetRegister, zero,FloatPointType::NONE, FloatPointType::NONE);
        }
        else {
            t->addCodeAddi(targetRegister, zero, stoi(values.front()));
        }
        t->setRegisterFree(zero);
        return targetRegister;
    }
    else {
        switch(dataType) {
            case MetaDataType::BOOL:
            case MetaDataType::INT:
                targetRegister = t->tryGetCertainRegister(true, regName, hasFreeRegister);
                t->addCodeLi(targetRegister, valueLabel);
                return targetRegister;
            case MetaDataType::FLOAT:
                freeRegister = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
                t->addCodeLi(freeRegister, valueLabel);
                if (!isGeneralPurposeRegister) {
                    targetRegister = t->tryGetCertainRegister(false, regName, hasFreeRegister);
                    t->addCodeMv(targetRegister, freeRegister, FloatPointType::SINGLE, FloatPointType::NONE);
                    t->setRegisterFree(freeRegister);
                    return targetRegister;
                }
                else {
                    return freeRegister;
                }
            case MetaDataType::DOUBLE:
                freeRegister = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
                t->addCodeLi(freeRegister, valueLabel);
                if (!isGeneralPurposeRegister) {
                    targetRegister = t->tryGetCertainRegister(false, regName, hasFreeRegister);
                    t->addCodeMv(targetRegister, freeRegister, FloatPointType::DOUBLE, FloatPointType::NONE);
                    t->setRegisterFree(freeRegister);
                    return targetRegister;
                }
                else {
                    return freeRegister;
                }
        }
    }
}

Register *IRValue::loadTo(TargetCodes *t, Register *inReg) {
    MetaDataType dataType = metaDataType;
    bool hasFreeRegister;
    Register *freeRegister = nullptr;
    if (valueLabel.empty()) {
        Register *zero = t->tryGetCertainRegister(true, "zero", hasFreeRegister);
        if (values.front() == "0") {
            t->addCodeMv(inReg, zero, FloatPointType::NONE, FloatPointType::NONE);
        }
        else {
            t->addCodeAddi(inReg, zero, stoi(values.front()));
        }
        t->setRegisterFree(zero);
        return inReg;
    }
    else {
        switch(dataType) {
            case MetaDataType::BOOL:
            case MetaDataType::INT:
                t->addCodeLi(inReg, valueLabel);
                return inReg;
            case MetaDataType::FLOAT:
                freeRegister = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
                t->addCodeLi(freeRegister, valueLabel);
                t->addCodeMv(inReg, freeRegister, FloatPointType::SINGLE, FloatPointType::NONE);
                return inReg;
            case MetaDataType::DOUBLE:
                freeRegister = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
                t->addCodeLi(freeRegister, valueLabel);
                t->addCodeMv(inReg, freeRegister, FloatPointType::DOUBLE, FloatPointType::NONE);
                return inReg;
        }
    }
}

void IRValue::print() const {
    if (!valueLabel.empty()) {
        cout << valueLabel << ": ";
    }
    if (isArray) {
        cout << "{";
        for (auto value : vector<string>(values.begin(), values.end() - 1)) {
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
        for (auto value : vector<string>(values.begin(), values.end() - 1)) {
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
            case MetaDataType::DOUBLE:
                stream << Tools::dtoIEEE754s(stod(values.front()));
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
                case MetaDataType::DOUBLE:
                    stream << "\t.quad\t" << Tools::dtoIEEE754s(stod(value));
                    break;
            }
            stream << endl;
        }
    }
    t->addCodeDirectives(stream.str());
}

IRSymbolVariable::IRSymbolVariable(AbstractSymbol *newSymbol, IRValue *newValue, bool newIsGlobalSymbolVar) : IROperand(OperandType::SYMBOLVAR) {
    symbol = newSymbol;
    assigned = false;
    alive = false;
    historySymbols.clear();
    historySymbols.push_back(this);
    initialValue = newValue;
    isGlobalSymbolVar = newIsGlobalSymbolVar;
}

Register *IRSymbolVariable::load(TargetCodes *t, bool isGeneralPurposeRegister) {
    MetaDataType dataType = symbol->getMetaDataType();
    bool hasFreeRegister;
    Register *freeRegister = nullptr;
    if (bindRegister) {
        switch (dataType) {
            case MetaDataType::BOOL:
            case MetaDataType::INT:
                return targetBindRegister;
            case MetaDataType::FLOAT:
                if (!isGeneralPurposeRegister) {
                    return targetBindRegister;
                }
                else {
                    freeRegister = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
                    t->addCodeMv(freeRegister, targetBindRegister, FloatPointType::NONE, FloatPointType::SINGLE);
                    return freeRegister;
                }
                break;
            case MetaDataType::DOUBLE:
                if (!isGeneralPurposeRegister) {
                    return targetBindRegister;
                }
                else {
                    freeRegister = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
                    t->addCodeMv(freeRegister, targetBindRegister, FloatPointType::NONE, FloatPointType::DOUBLE);
                    return freeRegister;
                }
                break;
        }
    }
    if (!isGlobalSymbolVar) {
        Register *sp = t->tryGetCertainRegister(true, "sp", hasFreeRegister);
        if (!getIsArray()) {
            switch(dataType) {
                case MetaDataType::BOOL:
                    freeRegister = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
                    t->addCodeLb(freeRegister, sp, -symbol->getOffset());
                    break;
                case MetaDataType::INT:
                    freeRegister = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
                    t->addCodeLw(freeRegister, sp, -symbol->getOffset());
                    break;
                case MetaDataType::FLOAT:
                    if (!isGeneralPurposeRegister) {
                        freeRegister = t->getNextFreeRegister(false, false, FloatPointType::SINGLE, hasFreeRegister);
                        t->addCodeFlw(freeRegister, sp, -symbol->getOffset());
                    }
                    else {
                        freeRegister = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
                        t->addCodeLw(freeRegister, sp, -symbol->getOffset());
                    }
                    break;
                case MetaDataType::DOUBLE:
                    if (!isGeneralPurposeRegister) {
                        freeRegister = t->getNextFreeRegister(false, false, FloatPointType::DOUBLE, hasFreeRegister);
                        t->addCodeFld(freeRegister, sp, -symbol->getOffset());
                    }
                    else {
                        freeRegister = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
                        t->addCodeLd(freeRegister, sp, -symbol->getOffset());
                    }
                    break;
            }
        }
        else {
            freeRegister = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
            t->addCodeAddi(freeRegister, sp, -symbol->getOffset());
        }
        t->setRegisterFree(sp);
    }
    else {
        Register *tmpRegister = nullptr;
        if (!getIsArray()) {
            switch(dataType) {
                case MetaDataType::BOOL:
                case MetaDataType::INT:
                    freeRegister = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
                    tmpRegister = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
                    t->addCodeLla(tmpRegister, symbol->getSymbolName());
                    t->addCodeLw(freeRegister, tmpRegister, 0);
                    t->setRegisterFree(tmpRegister);
                    break;
                case MetaDataType::FLOAT:
                    tmpRegister = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
                    t->addCodeLla(tmpRegister, symbol->getSymbolName());
                    if (isGeneralPurposeRegister) {
                        freeRegister = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
                        t->addCodeLw(freeRegister, tmpRegister, 0);
                    }
                    else {
                        freeRegister = t->getNextFreeRegister(false, false, FloatPointType::SINGLE, hasFreeRegister);
                        t->addCodeFlw(freeRegister,  tmpRegister,  0);
                    }
                    t->setRegisterFree(tmpRegister);
                    break;
                case MetaDataType::DOUBLE:
                    tmpRegister = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
                    t->addCodeLla(tmpRegister, symbol->getSymbolName());
                    if (isGeneralPurposeRegister) {
                        freeRegister = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
                        t->addCodeLw(freeRegister, tmpRegister, 0);
                    }
                    else {
                        freeRegister = t->getNextFreeRegister(false, false, FloatPointType::DOUBLE, hasFreeRegister);
                        t->addCodeFlw(freeRegister,  tmpRegister,  0);
                    }
                    t->setRegisterFree(tmpRegister);
                    break;
            }
        }
        else {
            freeRegister = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
            t->addCodeLla(freeRegister, symbol->getSymbolName());
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
            case MetaDataType::BOOL:
            case MetaDataType::INT:
                targetRegister = targetBindRegister;
                if (targetBindRegister->getAliasName() != regName) {
                    targetRegister = t->tryGetCertainRegister(true, regName, hasFreeRegister);
                    t->addCodeMv(targetRegister, targetBindRegister, FloatPointType::NONE, FloatPointType::NONE);
                }
                return targetRegister;
            case MetaDataType::FLOAT:
                if (!isGeneralPurposeRegister) {
                    targetRegister = targetBindRegister;
                    if (targetBindRegister->getAliasName() != regName) {
                        targetRegister = t->tryGetCertainRegister(true, regName, hasFreeRegister);
                        t->addCodeMv(targetRegister, targetBindRegister, FloatPointType::SINGLE,
                                     FloatPointType::SINGLE);
                    }
                    return targetRegister;
                } else {
                    targetRegister = t->tryGetCertainRegister(true, regName, hasFreeRegister);
                    t->addCodeMv(targetRegister, targetBindRegister, FloatPointType::NONE, FloatPointType::SINGLE);
                    return targetRegister;
                }
                break;
            case MetaDataType::DOUBLE:
                if (!isGeneralPurposeRegister) {
                    targetRegister = targetBindRegister;
                    if (targetBindRegister->getAliasName() != regName) {
                        targetRegister = t->tryGetCertainRegister(true, regName, hasFreeRegister);
                        t->addCodeMv(targetRegister, targetBindRegister, FloatPointType::DOUBLE,
                                     FloatPointType::DOUBLE);
                    }
                    return targetRegister;
                } else {
                    targetRegister = t->tryGetCertainRegister(true, regName, hasFreeRegister);
                    t->addCodeMv(targetRegister, targetBindRegister, FloatPointType::NONE, FloatPointType::DOUBLE);
                    return targetRegister;
                }
                break;
        }
    }
    if (!isGlobalSymbolVar) {
        Register *sp = t->tryGetCertainRegister(true, "sp", hasFreeRegister);
        if (!getIsArray()) {
            switch(dataType) {
                case MetaDataType::BOOL:
                    targetRegister = t->tryGetCertainRegister(true, regName, hasFreeRegister);
                    t->addCodeLb(targetRegister, sp, -symbol->getOffset());
                    break;
                case MetaDataType::INT:
                    targetRegister = t->tryGetCertainRegister(true, regName, hasFreeRegister);
                    t->addCodeLw(targetRegister, sp, -symbol->getOffset());
                    break;
                case MetaDataType::FLOAT:
                    if (!isGeneralPurposeRegister) {
                        targetRegister = t->tryGetCertainRegister(false, regName, hasFreeRegister);
                        t->addCodeFlw(targetRegister, sp, -symbol->getOffset());
                    }
                    else {
                        targetRegister = t->tryGetCertainRegister(true, regName, hasFreeRegister);
                        t->addCodeLw(targetRegister, sp, -symbol->getOffset());
                    }
                    break;
                case MetaDataType::DOUBLE:
                    if (!isGeneralPurposeRegister) {
                        targetRegister = t->tryGetCertainRegister(false, regName, hasFreeRegister);
                        t->addCodeFld(targetRegister, sp, -symbol->getOffset());
                    }
                    else {
                        targetRegister = t->tryGetCertainRegister(true, regName, hasFreeRegister);
                        t->addCodeLd(targetRegister, sp, -symbol->getOffset());
                    }
                    break;
            }
        }
        else {
            targetRegister = t->tryGetCertainRegister(true, regName, hasFreeRegister);
            t->addCodeAddi(targetRegister, sp, -symbol->getOffset());
        }
        t->setRegisterFree(sp);
    }
    else {
        Register *tmpRegister = nullptr;
        if (!getIsArray()) {
            switch(dataType) {
                case MetaDataType::BOOL:
                case MetaDataType::INT:
                    targetRegister = t->tryGetCertainRegister(true, regName, hasFreeRegister);
                    tmpRegister = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
                    t->addCodeLla(tmpRegister, symbol->getSymbolName());
                    t->addCodeLw(targetRegister, tmpRegister, 0);
                    t->setRegisterFree(tmpRegister);
                    break;
                case MetaDataType::FLOAT:
                    tmpRegister = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
                    t->addCodeLla(tmpRegister, symbol->getSymbolName());
                    if (isGeneralPurposeRegister) {
                        targetRegister = t->tryGetCertainRegister(true, regName, hasFreeRegister);
                        t->addCodeLw(targetRegister, tmpRegister, 0);
                    }
                    else {
                        targetRegister = t->tryGetCertainRegister(false, regName, hasFreeRegister);
                        t->addCodeFlw(targetRegister,  tmpRegister,  0);
                    }
                    t->setRegisterFree(tmpRegister);
                    break;
                case MetaDataType::DOUBLE:
                    tmpRegister = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
                    t->addCodeLla(tmpRegister, symbol->getSymbolName());
                    if (isGeneralPurposeRegister) {
                        targetRegister = t->tryGetCertainRegister(true, regName, hasFreeRegister);
                        t->addCodeLd(targetRegister, tmpRegister, 0);
                    }
                    else {
                        targetRegister = t->tryGetCertainRegister(false, regName, hasFreeRegister);
                        t->addCodeFld(targetRegister,  tmpRegister,  0);
                    }
                    t->setRegisterFree(tmpRegister);
                    break;
            }
        }
        else {
            targetRegister = t->tryGetCertainRegister(true, regName, hasFreeRegister);
            t->addCodeLla(targetRegister, symbol->getSymbolName());
        }
    }
    return targetRegister;
}

Register *IRSymbolVariable::loadTo(TargetCodes *t, Register *inReg) {
    MetaDataType dataType = symbol->getMetaDataType();
    bool hasFreeRegister;
    if (bindRegister) {
        switch (dataType) {
            case MetaDataType::BOOL:
            case MetaDataType::INT:
                if (targetBindRegister->getAliasName() != inReg->getAliasName()) {
                    t->addCodeMv(inReg, targetBindRegister, FloatPointType::NONE, FloatPointType::NONE);
                }
                return inReg;
            case MetaDataType::FLOAT:
                if (inReg->getRegisterType() == RegisterType::FLOAT_POINT) {
                    if (targetBindRegister->getAliasName() != inReg->getAliasName()) {
                        t->addCodeMv(inReg, targetBindRegister, FloatPointType::SINGLE,
                                     FloatPointType::SINGLE);
                    }
                    return inReg;
                } else {
                    t->addCodeMv(inReg, targetBindRegister, FloatPointType::NONE, FloatPointType::SINGLE);
                    return inReg;
                }
                break;
            case MetaDataType::DOUBLE:
                if (inReg->getRegisterType() == RegisterType::FLOAT_POINT) {
                    if (targetBindRegister->getAliasName() != inReg->getAliasName()) {
                        t->addCodeMv(inReg, targetBindRegister, FloatPointType::DOUBLE,
                                     FloatPointType::DOUBLE);
                    }
                    return inReg;
                } else {
                    t->addCodeMv(inReg, targetBindRegister, FloatPointType::NONE, FloatPointType::DOUBLE);
                    return inReg;
                }
                break;
        }
    }
    if (!isGlobalSymbolVar) {
        Register *sp = t->tryGetCertainRegister(true, "sp", hasFreeRegister);
        switch(dataType) {
            case MetaDataType::BOOL:
                t->addCodeLb(inReg, sp, -symbol->getOffset());
                break;
            case MetaDataType::INT:
                t->addCodeLw(inReg, sp, -symbol->getOffset());
                break;
            case MetaDataType::FLOAT:
                t->addCodeFlw(inReg, sp, -symbol->getOffset());
                break;
            case MetaDataType::DOUBLE:
                t->addCodeFld(inReg, sp, -symbol->getOffset());
                break;
        }
        t->setRegisterFree(sp);
    }
    else {
        switch (inReg->getFloatPointType()) {
            case FloatPointType::NONE:
                t->addCodeLla(inReg, symbol->getSymbolName());
                break;
            case FloatPointType::SINGLE:
            case FloatPointType::DOUBLE:
                Register *tmpRegister = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
                t->addCodeLla(tmpRegister, symbol->getSymbolName());
                t->addCodeMv(inReg, tmpRegister, inReg->getFloatPointType(), FloatPointType::NONE);
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
            case MetaDataType::BOOL:
            case MetaDataType::INT:
                if (targetBindRegister->getAliasName() != reg->getAliasName()) {
                    t->addCodeMv(targetBindRegister, reg, FloatPointType::NONE, FloatPointType::NONE);
                }
                return;
            case MetaDataType::FLOAT:
                if (reg->getRegisterType() == RegisterType::FLOAT_POINT) {
                    if (targetBindRegister->getAliasName() != reg->getAliasName()) {
                        t->addCodeMv(targetBindRegister, reg, FloatPointType::SINGLE,
                                     FloatPointType::SINGLE);
                    }
                    return;
                } else {
                    t->addCodeMv(targetBindRegister, reg, FloatPointType::SINGLE, FloatPointType::NONE);
                    return;
                }
                break;
            case MetaDataType::DOUBLE:
                if (reg->getRegisterType() == RegisterType::FLOAT_POINT) {
                    if (targetBindRegister->getAliasName() != reg->getAliasName()) {
                        t->addCodeMv(targetBindRegister, reg, FloatPointType::DOUBLE,
                                     FloatPointType::DOUBLE);
                    }
                    return;
                } else {
                    t->addCodeMv(targetBindRegister, reg, FloatPointType::DOUBLE, FloatPointType::NONE);
                    return;
                }
                break;
        }
    }
    if (!isGlobalSymbolVar) {
        Register *sp = t->tryGetCertainRegister(true, "sp", hasFreeRegister);
        switch(dataType) {
            case MetaDataType::BOOL:
                t->addCodeSb(sp, reg, -symbol->getOffset());
                break;
            case MetaDataType::INT:
                t->addCodeSw(sp, reg, -symbol->getOffset());
                break;
            case MetaDataType::FLOAT:
                if (reg->getRegisterType() == RegisterType::GENERAL_PURPOSE) {
                    t->addCodeSw(sp, reg, -symbol->getOffset());
                }
                else {
                    t->addCodeFsw(sp, reg, -symbol->getOffset());
                }
                break;
            case MetaDataType::DOUBLE:
                if (reg->getRegisterType() == RegisterType::GENERAL_PURPOSE) {
                    t->addCodeSd(sp, reg, -symbol->getOffset());
                }
                else {
                    t->addCodeFsd(sp, reg, -symbol->getOffset());
                }
                break;
        }
        t->setRegisterFree(sp);
    }
    else {
        Register *freeReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
        switch (reg->getFloatPointType()) {
            case FloatPointType::NONE:
                t->addCodeLla(freeReg, symbol->getSymbolName());
                t->addCodeSw(freeReg, reg, 0);
                break;
            case FloatPointType::SINGLE:
                t->addCodeLla(freeReg, symbol->getSymbolName());
                if (reg->getRegisterType() == RegisterType::GENERAL_PURPOSE) {
                    t->addCodeSw(freeReg, reg, 0);
                }
                else {
                    t->addCodeFsw(freeReg, reg, 0);
                }
                break;
            case FloatPointType::DOUBLE:
                t->addCodeLla(freeReg, symbol->getSymbolName());
                if (reg->getRegisterType() == RegisterType::GENERAL_PURPOSE) {
                    t->addCodeSd(freeReg, reg, 0);
                }
                else {
                    t->addCodeFsd(freeReg, reg, 0);
                }
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
            case MetaDataType::DOUBLE:
                stream << Tools::dtoIEEE754s(stod(values.front()));
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
                case MetaDataType::DOUBLE:
                    stream << "\t.quad\t" << Tools::dtoIEEE754s(stod(value));
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
            case MetaDataType::DOUBLE:
                stream << Tools::dtoIEEE754s(stod(values.front()));
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
                case MetaDataType::DOUBLE:
                    stream << "\t.quad\t" << Tools::dtoIEEE754s(stod(value));
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
    symbolName = move(newName);
    metaDataType = newMetaDataType;
    assigned = false;
    alive = false;
    aliasToSymbol = false;
    symbolVariable = nullptr;
    offset = 0;
    initialValue = nullptr;
}

IRTempVariable::IRTempVariable(string newName, MetaDataType newMetaDataType, IROperand *parentVariable) : IROperand(OperandType::TEMPVAR) {
    symbolName = move(newName);
    metaDataType = newMetaDataType;
    assigned = false;
    aliasToSymbol = true;
    symbolVariable = parentVariable;
    offset = 0;
    initialValue = nullptr;
}

IRTempVariable::IRTempVariable(string newName, MetaDataType newMetaDataType, IRValue *newValue) : IROperand(OperandType::TEMPVAR) {
    symbolName = move(newName);
    metaDataType = newMetaDataType;
    assigned = false;
    aliasToSymbol = false;
    symbolVariable = nullptr;
    offset = 0;
    initialValue = newValue;
}


Register *IRTempVariable::load(TargetCodes *t, bool isGeneralPurposeRegister) {
    if (!aliasToSymbol) {
        bool hasFreeRegister;
        Register *freeRegister = nullptr;
        if (bindRegister) {
            switch (metaDataType) {
                case MetaDataType::BOOL:
                case MetaDataType::INT:
                    return targetBindRegister;
                case MetaDataType::FLOAT:
                    if (!isGeneralPurposeRegister) {
                        return targetBindRegister;
                    }
                    else {
                        freeRegister = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
                        t->addCodeMv(freeRegister, targetBindRegister, FloatPointType::NONE, FloatPointType::SINGLE);
                        return freeRegister;
                    }
                    break;
                case MetaDataType::DOUBLE:
                    if (!isGeneralPurposeRegister) {
                        return targetBindRegister;
                    }
                    else {
                        freeRegister = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
                        t->addCodeMv(freeRegister, targetBindRegister, FloatPointType::NONE, FloatPointType::DOUBLE);
                        return freeRegister;
                    }
                    break;
            }
        }
        Register *sp = t->tryGetCertainRegister(true, "sp", hasFreeRegister);
        switch(metaDataType) {
            case MetaDataType::BOOL:
                freeRegister = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
                t->addCodeLb(freeRegister, sp, -offset);
                break;
            case MetaDataType::INT:
                freeRegister = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
                t->addCodeLw(freeRegister, sp, -offset);
                break;
            case MetaDataType::FLOAT:
                if (!isGeneralPurposeRegister) {
                    freeRegister = t->getNextFreeRegister(false, false, FloatPointType::SINGLE, hasFreeRegister);
                    t->addCodeFlw(freeRegister, sp, -offset);
                }
                else {
                    freeRegister = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
                    t->addCodeLw(freeRegister, sp, -offset);
                }
                break;
            case MetaDataType::DOUBLE:
                if (!isGeneralPurposeRegister) {
                    freeRegister = t->getNextFreeRegister(false, false, FloatPointType::DOUBLE, hasFreeRegister);
                    t->addCodeFld(freeRegister, sp, -offset);
                }
                else {
                    freeRegister = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
                    t->addCodeLd(freeRegister, sp, -offset);
                }
                break;
        }
        t->setRegisterFree(sp);
        return freeRegister;
    }
    else {
        return symbolVariable->load(t, isGeneralPurposeRegister);
    }
}

Register *IRTempVariable::loadTo(TargetCodes *t, const string &regName, bool isGeneralPurposeRegister) {
    if (!aliasToSymbol) {
        bool hasFreeRegister;
        Register *sp = t->tryGetCertainRegister(true, "sp", hasFreeRegister);
        Register *targetRegister = nullptr;
        if (bindRegister) {
            switch (metaDataType) {
                case MetaDataType::BOOL:
                case MetaDataType::INT:
                    targetRegister = targetBindRegister;
                    if (targetBindRegister->getAliasName() != regName) {
                        targetRegister = t->tryGetCertainRegister(true, regName, hasFreeRegister);
                        t->addCodeMv(targetRegister, targetBindRegister, FloatPointType::NONE, FloatPointType::NONE);
                    }
                    return targetRegister;
                case MetaDataType::FLOAT:
                    if (!isGeneralPurposeRegister) {
                        targetRegister = targetBindRegister;
                        if (targetBindRegister->getAliasName() != regName) {
                            targetRegister = t->tryGetCertainRegister(true, regName, hasFreeRegister);
                            t->addCodeMv(targetRegister, targetBindRegister, FloatPointType::SINGLE,
                                         FloatPointType::SINGLE);
                        }
                        return targetRegister;
                    } else {
                        targetRegister = t->tryGetCertainRegister(true, regName, hasFreeRegister);
                        t->addCodeMv(targetRegister, targetBindRegister, FloatPointType::NONE, FloatPointType::SINGLE);
                        return targetRegister;
                    }
                    break;
                case MetaDataType::DOUBLE:
                    if (!isGeneralPurposeRegister) {
                        targetRegister = targetBindRegister;
                        if (targetBindRegister->getAliasName() != regName) {
                            targetRegister = t->tryGetCertainRegister(true, regName, hasFreeRegister);
                            t->addCodeMv(targetRegister, targetBindRegister, FloatPointType::DOUBLE,
                                         FloatPointType::DOUBLE);
                        }
                        return targetRegister;
                    } else {
                        targetRegister = t->tryGetCertainRegister(true, regName, hasFreeRegister);
                        t->addCodeMv(targetRegister, targetBindRegister, FloatPointType::NONE, FloatPointType::DOUBLE);
                        return targetRegister;
                    }
                    break;
            }
        }
        switch(metaDataType) {
            case MetaDataType::BOOL:
                targetRegister = t->tryGetCertainRegister(true, regName, hasFreeRegister);
                t->addCodeLb(targetRegister, sp, -offset);
                break;
            case MetaDataType::INT:
                targetRegister = t->tryGetCertainRegister(true, regName, hasFreeRegister);
                t->addCodeLw(targetRegister, sp, -offset);
                break;
            case MetaDataType::FLOAT:
                if (isGeneralPurposeRegister) {
                    targetRegister = t->tryGetCertainRegister(false, regName, hasFreeRegister);
                    t->addCodeFlw(targetRegister, sp, -offset);
                }
                else {
                    targetRegister = t->tryGetCertainRegister(true, regName, hasFreeRegister);
                    t->addCodeLw(targetRegister, sp, -offset);
                }
                break;
            case MetaDataType::DOUBLE:
                if (isGeneralPurposeRegister) {
                    targetRegister = t->tryGetCertainRegister(false, regName, hasFreeRegister);
                    t->addCodeFld(targetRegister, sp, -offset);
                }
                else {
                    targetRegister = t->tryGetCertainRegister(true, regName, hasFreeRegister);
                    t->addCodeLd(targetRegister, sp, -offset);
                }
                break;
        }
        t->setRegisterFree(sp);
        return targetRegister;
    }
    else {
        return symbolVariable->loadTo(t, regName, isGeneralPurposeRegister);
    }
}

Register *IRTempVariable::loadTo(TargetCodes *t, Register *inReg) {
    if (!aliasToSymbol) {
        bool hasFreeRegister;
        if (bindRegister) {
            switch (metaDataType) {
                case MetaDataType::BOOL:
                case MetaDataType::INT:
                    if (targetBindRegister->getAliasName() != inReg->getAliasName()) {
                        t->addCodeMv(inReg, targetBindRegister, FloatPointType::NONE, FloatPointType::NONE);
                    }
                    return inReg;
                case MetaDataType::FLOAT:
                    if (inReg->getRegisterType() == RegisterType::FLOAT_POINT) {
                        if (targetBindRegister->getAliasName() != inReg->getAliasName()) {
                            t->addCodeMv(inReg, targetBindRegister, FloatPointType::SINGLE,
                                         FloatPointType::SINGLE);
                        }
                        return inReg;
                    } else {
                        t->addCodeMv(inReg, targetBindRegister, FloatPointType::NONE, FloatPointType::SINGLE);
                        return inReg;
                    }
                    break;
                case MetaDataType::DOUBLE:
                    if (inReg->getRegisterType() == RegisterType::FLOAT_POINT) {
                        if (targetBindRegister->getAliasName() != inReg->getAliasName()) {
                            t->addCodeMv(inReg, targetBindRegister, FloatPointType::DOUBLE,
                                         FloatPointType::DOUBLE);
                        }
                        return inReg;
                    } else {
                        t->addCodeMv(inReg, targetBindRegister, FloatPointType::NONE, FloatPointType::DOUBLE);
                        return inReg;
                    }
                    break;
            }
        }
        Register *sp = t->tryGetCertainRegister(true, "sp", hasFreeRegister);
        switch (metaDataType) {
            case MetaDataType::BOOL:
            case MetaDataType::INT:
                t->addCodeLw(inReg, sp, -offset);
                break;
            case MetaDataType::FLOAT:
                t->addCodeFlw(inReg, sp, -offset);
            case MetaDataType::DOUBLE:
                t->addCodeFld(inReg, sp, -offset);
        }
        t->setRegisterFree(sp);
        return inReg;
    }
    else {
        return symbolVariable->loadTo(t, inReg);
    }
}

void IRTempVariable::storeFrom(TargetCodes *t, Register *reg) {
    if (!aliasToSymbol) {
        bool hasFreeRegister;
        if (bindRegister) {
            switch (metaDataType) {
                case MetaDataType::BOOL:
                case MetaDataType::INT:
                    if (targetBindRegister->getAliasName() != reg->getAliasName()) {
                        t->addCodeMv(targetBindRegister, reg, FloatPointType::NONE, FloatPointType::NONE);
                    }
                    return;
                case MetaDataType::FLOAT:
                    if (reg->getRegisterType() == RegisterType::FLOAT_POINT) {
                        if (targetBindRegister->getAliasName() != reg->getAliasName()) {
                            t->addCodeMv(targetBindRegister, reg, FloatPointType::SINGLE,
                                         FloatPointType::SINGLE);
                        }
                        return;
                    } else {
                        t->addCodeMv(targetBindRegister, reg, FloatPointType::SINGLE, FloatPointType::NONE);
                        return;
                    }
                    break;
                case MetaDataType::DOUBLE:
                    if (reg->getRegisterType() == RegisterType::FLOAT_POINT) {
                        if (targetBindRegister->getAliasName() != reg->getAliasName()) {
                            t->addCodeMv(targetBindRegister, reg, FloatPointType::DOUBLE,
                                         FloatPointType::DOUBLE);
                        }
                        return;
                    } else {
                        t->addCodeMv(targetBindRegister, reg, FloatPointType::DOUBLE, FloatPointType::NONE);
                        return;
                    }
                    break;
            }
        }
        Register *sp = t->tryGetCertainRegister(true, "sp", hasFreeRegister);
        switch(metaDataType) {
            case MetaDataType::BOOL:
                t->addCodeSb(sp, reg, -offset);
                break;
            case MetaDataType::INT:
                t->addCodeSw(sp, reg, -offset);
                break;
            case MetaDataType::FLOAT:
                if (reg->getRegisterType() == RegisterType::GENERAL_PURPOSE) {
                    t->addCodeSw(sp, reg, -offset);
                }
                else {
                    t->addCodeFsw(sp, reg, -offset);
                }
                break;
            case MetaDataType::DOUBLE:
                if (reg->getRegisterType() == RegisterType::GENERAL_PURPOSE) {
                    t->addCodeSd(sp, reg, -offset);
                }
                else {
                    t->addCodeFsd(sp, reg, -offset);
                }
                break;
        }
        t->setRegisterFree(sp);
    }
    else {
        return symbolVariable->storeFrom(t, reg);
    }
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