#include "IROperands.h"

#include <utility>

using namespace std;

IRLabel::IRLabel(string newName) : IROperand(OperandType::LABEL) {
    labelName = std::move(newName);
}

IRValue::IRValue(MetaDataType newMetaDataType, bool newIsArray, std::size_t newSize) : IROperand(OperandType::VALUE) {
    metaDataType = newMetaDataType;
    value.clear();
}

void IRValue::addValue(const string& newValue) {
    value.assign(newValue);
}

string IRValue::getValue() const {
    return value;
}

IRSymbolVariable::IRSymbolVariable(AbstractSymbol *newSymbol) : IROperand(OperandType::SYMBOLVAR) {
    symbol = newSymbol;
}

void IRSymbolVariable::setMemOffset(int offset) {}

int IRSymbolVariable::getMemOffset() const {}

IRTempVariable::IRTempVariable(string newName, MetaDataType newMetaDataType, bool newIsArray, size_t newSize) : IROperand(OperandType::TEMPVAR) {
    symbolName = std::move(newName);
    metaDataType = newMetaDataType;
    isArray = newIsArray;
    size = newSize;
}

void IRTempVariable::setMemOffset(int offset) {}

int IRTempVariable::getMemOffset() const {}