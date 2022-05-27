#include "symbolTable.h"

#pragma once

enum class MemArea {
    STACK,
    DATA,
    RODATA
};

enum class OperandType {
    LABEL,
    VALUE,
    SYMBOLVAR,
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
    IROperand(OperandType newOperandType) { operandType = newOperandType; };

    bool setOperandType(OperandType inOperandType) { operandType = inOperandType; return true; };
    OperandType getOperandType() const { return operandType; };

    virtual std::string getSymbolName() const { return {}; };
    virtual MetaDataType getMetaDataType() const { return MetaDataType::VOID; };
    virtual bool getIsArray() const { return false; };
    virtual std::size_t getSize() const { return 0; };
    virtual bool getAssigned() const { return false; };
    virtual IROperand *getLatestVersionSymbol() const { return nullptr; };
    virtual bool getAliasToSymbol() const { return false; };
    virtual IROperand *getSymbolVariable() const { return nullptr; }
    virtual std::string getFunctionName() const { return {}; };
    virtual SymbolTable *getFunctionSymbolTable() const { return nullptr; };

    virtual bool setAssigned() { return false; }
    virtual bool setLatestVersionSymbol(IROperand *newVersionSymbol) { return false; };
    virtual bool setAliasToSymbol() { return false; };
    virtual bool setSymbolVariable(IROperand *inSymbolVariable) { return false; };
    virtual bool setFunctionSymbolTable(SymbolTable *inFunctionTable) const { return false; };

    virtual void setMemOffset(int offset) {};
    virtual int getMemOffset() const { return 0; };

};

class IRLabel : public IROperand {
private:
    std::string labelName;

public:
    IRLabel(std::string newName);

    std::string getSymbolName() const override { return labelName; };
};

class IRValue : public IROperand {
private:
    MetaDataType metaDataType;
    std::string value;

public:
    IRValue(MetaDataType newMetaDataType, bool newIsArray, std::size_t newSize);

    MetaDataType getMetaDataType() const override { return metaDataType; };

    void addValue(const std::string& newValue);
    std::string getValue() const;
};

class IRSymbolVariable : public IROperand {
private:
    AbstractSymbol *symbol;
    bool assigned;
    IROperand *latestVersionSymbol;

public:
    IRSymbolVariable(AbstractSymbol *newSymbol);

    std::string getSymbolName() const override { return symbol->getSymbolName(); };
    MetaDataType getMetaDataType() const override { return symbol->getMetaDataType(); };
    bool getIsArray() const override { return symbol->getIsArray(); };
    std::size_t getSize() const override { return symbol->getSize(); };
    bool getAssigned() const override { return assigned; };
    IROperand *getLatestVersionSymbol() const override { return latestVersionSymbol; };

    bool setAssigned() override { assigned = true; return true; };
    bool setLatestVersionSymbol(IROperand *latestSymbol) override { latestVersionSymbol = latestSymbol; return true; }

    void setMemOffset(int offset) override;
    int getMemOffset() const override;
};

class IRSymbolFunction : public IROperand {
private:
    SymbolTable *functionTable;

public:
    IRSymbolFunction(FuncSymbolTable *function);
    std::string getFunctionName() const override { return functionTable->getFuncName(); };
    SymbolTable *getFunctionSymbolTable() const override { return functionTable; };

    bool setFunctionSymbolTable(SymbolTable *inFunctionTable) const override { functionTable = inFunctionTable; return true; };
};

class IRTempVariable : public IROperand {
private:
    std::string symbolName;
    MetaDataType metaDataType;
    bool isArray;
    std::size_t size;
    bool assigned;
    bool aliasToSymbol;
    IROperand *symbolVariable;

public:
    IRTempVariable(std::string newName, MetaDataType newMetaDataType, bool newIsArray, size_t newSize);

    std::string getSymbolName() const override { return symbolName; };
    MetaDataType getMetaDataType() const override { return metaDataType; };
    bool getIsArray() const override { return isArray; };
    std::size_t getSize() const override { return size; };
    bool getAssigned() const override { return assigned; };
    bool getAliasToSymbol() const override { return aliasToSymbol; };
    IROperand *getSymbolVariable() const override { return symbolVariable; };

    bool setAssigned() override { assigned = true; return true; };
    bool setAliasToSymbol() override { aliasToSymbol = true; return true; };
    bool setSymbolVariable(IROperand *inSymbolVariable) override { aliasToSymbol = true; symbolVariable = inSymbolVariable; return true; };

    void setMemOffset(int offset) override;
    int getMemOffset() const override;

};