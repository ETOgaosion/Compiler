#include "IROperands.h"

#include <utility>

using namespace std;

IRLabel::IRLabel(string newName) : IROperand(OperandType::LABEL) {
    labelName = std::move(newName);
}

IRValue::IRValue(MetaDataType newMetaDataType, bool newIsArray, std::size_t newSize) : IROperand(OperandType::VALUE) {
    metaDataType = newMetaDataType;
    isArray = newIsArray;
    size = newSize;
    values.clear();
}

void IRValue::addValue(const string& newValue) {
    values.push_back(newValue);
}

void IRValue::setValues(int len, const string& singleValue) {
    if (values.size() < len) {
        values.resize(len);
    }
    for (int i = 0; i < len; i++) {
        values[i] = singleValue;
    }
}

void IRValue::setValues(vector<string> inValues) {
    if(values.size() < inValues.size()) {
        values.resize(inValues.size());
    }
    for(int i = 0; i < inValues.size(); i++) {
        values[i] = inValues[i];
    }
}

string IRValue::getValue(int cnt) const {
    return values[cnt];
}

vector<string> IRValue::getValues() const {
    return values;
}

IRSymbolVariable::IRSymbolVariable(AbstractSymbol *newSymbol) : IROperand(OperandType::SYMBOLVAR) {
    symbol = newSymbol;
    curValue = nullptr;
}

void IRSymbolVariable::setMemOffset(int offset) {}

int IRSymbolVariable::getMemOffset() const {}

IRTempVariable::IRTempVariable(string newName, SymbolType newSymbolType, MetaDataType newMetaDataType, bool newIsArray, size_t newSize) : IROperand(OperandType::TEMPVAR) {
    symbolName = std::move(newName);
    metaDataType = newMetaDataType;
    isArray = newIsArray;
    size = newSize;
    curValue = nullptr;
}

void IRTempVariable::setMemOffset(int offset) {}

int IRTempVariable::getMemOffset() const {}