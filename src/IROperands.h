#include "SymbolTable.h"
#include "TargetCodes.h"

#pragma once

enum class OperandType {
    LABEL,
    VALUE,
    SYMBOLVAR,
    SYMBOLFUNC,
    TEMPVAR
};

class IROperand;
class IRLabel;
class IRValue;
class IRSymbolVariable;
class IRTempVariable;

class IROperand {
private:
    OperandType operandType;

public:
    explicit IROperand(OperandType newOperandType) { operandType = newOperandType; }

    bool setOperandType(OperandType inOperandType) { operandType = inOperandType; return true; };
    OperandType getOperandType() const { return operandType; };

    virtual std::string getSymbolName() const { return {}; };
    virtual MetaDataType getMetaDataType() const { return MetaDataType::VOID; };
    virtual std::string getValue() const { return {}; };
    virtual std::vector<std::string> getValues() const { return {}; };
    virtual std::string getValueLabel() const { return {}; };
    virtual bool getAssigned() const { return false; };
    virtual IROperand *getLatestVersionSymbol() const { return nullptr; };
    virtual bool getAliasToSymbol() const { return false; };
    virtual IROperand *getSymbolVariable() const { return nullptr; }
    virtual std::string getFunctionName() const { return {}; };
    virtual SymbolTable *getFunctionSymbolTable() const { return nullptr; };
    virtual int getMemOffset() const { return 0; };
    virtual IRValue *getInitialValue() const { return nullptr; };
    virtual bool getIsArray() const { return false; };
    virtual int getArraySize() const { return 0; };
    virtual uint64_t getMemPosition() const { return 0; };

    virtual bool setAssigned() { return false; }
    virtual bool addHistorySymbol(IROperand *inSymbol) { return false; };
    virtual bool setAliasToSymbol() { return false; };
    virtual bool setSymbolVariable(IROperand *inSymbolVariable) { return false; };
    virtual bool setFunctionSymbolTable(SymbolTable *inFunctionTable) { return false; };
    virtual void setMemOffset(int offset) {};
    virtual bool setMemPosition(uint64_t inMemPosition) { return false; };

    virtual Register *load(TargetCodes * t) { return nullptr; };
    virtual Register *loadTo(TargetCodes * t, const std::string &regName) { return nullptr; };
    virtual Register *loadTo(TargetCodes * t, Register *inReg) { return nullptr; };
    virtual void storeFrom(TargetCodes * t, Register *reg) {};

    virtual void print() const = 0;
    virtual void genTargetValue(TargetCodes *t) const {};

};

class IRLabel : public IROperand {
private:
    std::string labelName;

public:
    explicit IRLabel(std::string newName);

    std::string getSymbolName() const override { return labelName; };

    void print() const override;
};

class IRValue : public IROperand {
private:
    MetaDataType metaDataType;
    std::vector<std::string> values;
    std::string valueLabel;
    bool isArray;

public:
    IRValue(MetaDataType newMetaDataType, const std::string &newLabel, bool newIsArray);
    IRValue(MetaDataType newMetaDataType, const std::string &newValue, const std::string &newLabel, bool newIsArray);
    IRValue(MetaDataType newMetaDataType, const std::vector<std::string>& newValues, const std::string &newLabel, bool newIsArray);

    MetaDataType getMetaDataType() const override { return metaDataType; };
    std::string getValue() const override { return values.front(); };
    std::vector<std::string> getValues() const override { return values; };
    std::string getValueLabel() const override { return valueLabel; };
    bool getIsArray() const override { return  isArray; };

    void addValue(const std::string& newValue);
    void addValues(const std::vector<std::string>& newValues);

    Register *load(TargetCodes * t) override;
    Register *loadTo(TargetCodes * t, const std::string &regName) override;
    Register *loadTo(TargetCodes * t, Register *inReg) override;

    void print() const override;
    void genTargetValue(TargetCodes *t) const override;
};

class IRSymbolVariable : public IROperand {
private:
    AbstractSymbol *symbol;
    bool assigned;
    std::vector<IROperand *> historySymbols;
    IRValue *initialValue;

public:
    explicit IRSymbolVariable(AbstractSymbol *newSymbol, IRValue *newValue);

    std::string getSymbolName() const override { return symbol->getSymbolName(); };
    MetaDataType getMetaDataType() const override { return symbol->getMetaDataType(); };
    bool getAssigned() const override { return assigned; };
    IROperand *getLatestVersionSymbol() const override { return historySymbols.back(); };
    int getMemOffset() const override { return symbol->getOffset(); };
    IRValue *getInitialValue() const override { return initialValue; };
    bool getIsArray() const override { return symbol->getIsArray(); };
    int getArraySize() const override { return symbol->getSize(); };
    uint64_t getMemPosition() const override { return symbol->getMemPosition(); };

    bool setAssigned() override { assigned = true; return true; };
    bool addHistorySymbol(IROperand *inSymbol) override { historySymbols.push_back(inSymbol); return true; };

    void setMemOffset(int inOffset) override { symbol->setOffset(inOffset); };
    bool setMemPosition(uint64_t inMemPosition) override { symbol->setOffset(inMemPosition); };

    Register *load(TargetCodes * t) override;
    Register *loadTo(TargetCodes * t, const std::string &regName) override;
    Register *loadTo(TargetCodes * t, Register *inReg) override;
    void storeFrom(TargetCodes * t, Register *reg) override;

    void print() const override;
    void genTargetValue(TargetCodes *t) const override;
};

class IRSymbolFunction : public IROperand {
private:
    SymbolTable *functionTable;

public:
    explicit IRSymbolFunction(SymbolTable *function);
    std::string getFunctionName() const override { return functionTable->getFuncName(); };
    SymbolTable *getFunctionSymbolTable() const override { return functionTable; };

    bool setFunctionSymbolTable(SymbolTable *inFunctionTable) override { functionTable = inFunctionTable; return true; };

    void print() const override;
};

class IRTempVariable : public IROperand {
private:
    std::string symbolName;
    MetaDataType metaDataType;
    bool assigned;
    bool aliasToSymbol;
    IROperand *symbolVariable;
    int offset;
    IRValue *initialValue;

public:
    IRTempVariable(std::string newName, MetaDataType newMetaDataType);
    IRTempVariable(std::string newName, MetaDataType newMetaDataType, IRSymbolVariable *parentVariable);
    IRTempVariable(std::string newName, MetaDataType newMetaDataType, IRValue *newValue);

    std::string getSymbolName() const override { return symbolName; };
    MetaDataType getMetaDataType() const override { return metaDataType; };
    bool getAssigned() const override { return assigned; };
    bool getAliasToSymbol() const override { return aliasToSymbol; };
    IROperand *getSymbolVariable() const override { return symbolVariable; };
    IRValue *getInitialValue() const override { return initialValue; };

    bool setAssigned() override { assigned = true; return true; };
    bool setAliasToSymbol() override { aliasToSymbol = true; return true; };
    bool setSymbolVariable(IROperand *inSymbolVariable) override { aliasToSymbol = true; symbolVariable = inSymbolVariable; return true; };

    void setMemOffset(int inOffset) override { offset = inOffset; };
    int getMemOffset() const override { return offset; };

    Register *load(TargetCodes * t) override;
    Register *loadTo(TargetCodes * t, const std::string &regName) override;
    Register *loadTo(TargetCodes * t, Register *inReg) override;
    void storeFrom(TargetCodes * t, Register *reg) override;

    void print() const override;
};