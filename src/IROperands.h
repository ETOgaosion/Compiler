#include "SymbolTable.h"
#include "TargetCodes.h"

#include <utility>
#include <vector>

#pragma once

/* IR Operand Type */
/* @usage: OperandType::LABEL */
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

/* operands' parent*/
/* @NOTICE: never use directly */
/* @usage: IROperand *newOp = new IRLabel(labelName); */
class IROperand {
private:
    OperandType operandType;
    bool wasColored;        // used for graph-coloring register allocation

public:
    explicit IROperand(OperandType newOperandType) { operandType = newOperandType; wasColored = false; };

    /* access to operandType field */
    bool setOperandType(OperandType inOperandType) { operandType = inOperandType; return true; };
    OperandType getOperandType() const { return operandType; };

    virtual std::string getSymbolName() const { return {}; };
    virtual MetaDataType getMetaDataType() const { return MetaDataType::VOID; };
    virtual std::string getValue() const { return {}; };
    virtual std::string getValue(int off) const { return {}; };
    virtual std::vector<std::string> getValues() const { return {}; };
    virtual std::string getValueLabel() const { return {}; };
    virtual bool getAssigned() const { return false; };
    virtual std::vector<IRValue *> getSubValues() const { return {}; };
    virtual std::vector<IROperand *> getHistorySymbols() const { return {}; };
    virtual IROperand *getLatestVersionSymbol() const { return nullptr; };
    virtual bool getAliasToVar() const { return false; };
    virtual IROperand *getParentVariable() const { return nullptr; }
    virtual std::string getFunctionName() const { return {}; };
    virtual MetaDataType getReturnType() const { return {}; };
    virtual SymbolTable *getFunctionSymbolTable() const { return nullptr; };
    virtual int getMemOffset() const { return 0; };
    virtual IROperand *getInitialValue() const { return nullptr; };
    virtual bool getIsArray() const { return false; };
    virtual std::size_t getArraySize() const { return 0; };
    virtual std::vector<std::size_t> getArrayShape() const { return {}; };
    virtual uint64_t getMemPosition() const { return 0; };
    virtual bool getIsGlobalSymbolVar() const { return 0; };
    virtual int getFrameSize() const { return 0; };
    virtual bool getBindRegister() const { return false; };
    virtual Register *getTargetBindRegister() const { return nullptr; };
    virtual std::vector<int> getActiveRegions() const { return {}; };
    virtual bool getIsAlive() const { return true; };
    virtual std::vector<Register *> getBindRegisters() const { return {}; };
    virtual bool getWasColored() const { return wasColored; };        // used for graph-coloring register allocation

    virtual void setAlive(bool set) {};
    virtual bool setAssigned() { return false; }
    virtual bool addHistorySymbol(IROperand *inSymbol) { return false; };
    virtual bool setAliasToVar() { return false; };
    virtual bool setParentVariable(IROperand *inParentVariable) { return false; };
    virtual bool setFunctionSymbolTable(SymbolTable *inFunctionTable) { return false; };
    virtual bool setFrameSize(int inSize) { return false; };
    virtual void setMemOffset(int offset) {};
    virtual bool setArrayShape(std::vector<std::size_t> newArrayShape) { return false; };
    virtual bool setMemPosition(uint64_t inMemPosition) { return false; };
    virtual void addValue(const std::string& newValue) {};
    virtual void addValues(const std::vector<std::string>& newValues) {};
    virtual bool setValues(std::vector<std::string> inValues) { return false; };
    virtual bool setInitialValue(IROperand *inInitialValue) { return false; };
    virtual bool setLabel(const std::string& newLabel) { return false; };
    virtual bool setMetaDataType(MetaDataType newType) { return false; };
    virtual bool setActiveRegions(std::vector<int> inActiveRegion) { return false; };
    virtual bool setBindRegister(bool toBindRegister) { return false; };
    virtual bool setTargetBindRegister(Register *inTargetBindRegister) { return false; };
    virtual bool setWasColored(bool inWasColored) { wasColored = inWasColored; return true; };        // used for graph-coloring register allocation
    virtual bool setSubValues(std::vector<IRValue *>newSubValues) { return false; };

    virtual Register *load(TargetCodes * t, bool isGeneralPurposeRegister) { return nullptr; };
    virtual Register *loadTo(TargetCodes * t, const std::string &regName, bool isGeneralPurposeRegister) { return nullptr; };
    virtual Register *loadTo(TargetCodes * t, Register *inReg) { return nullptr; };
    virtual void storeFrom(TargetCodes * t, Register *reg) {};

    /* can print formally, but commonly not used, all child implement */
    virtual void print() const = 0;
    /* get formal string to describe operand, all child implement */
    virtual std::string getVal() const = 0;
    virtual void genTargetValue(TargetCodes *t) const {};
    virtual void genTargetGlobalValue(TargetCodes *t) const {};

    /*figure out which basic block is used when operand is defined*/
    int which_bb;
};

/* label operand */
class IRLabel : public IROperand {
private:
    std::string labelName;

public:
    explicit IRLabel(std::string newName);

    std::string getSymbolName() const override { return labelName; };

    void print() const override;
    std::string getVal() const override;
};

/* immediate value operand(can be array), like 0, 1, 0.99, {0.1, 2.33} */
/* immediate value index rules: */
/* 1. integer single value: use number directly */
/* 2. any other types of value are indexed by label */
/*      - float value use `.equ label, ieeeFormatFloatImm` */
/*      - array value use: */
/*          ```*/
/*          .data */
/*          label: */
/*              .word immVal */
/*              .word immVal */
/*              .word immVal */
/*          ```*/
/*        which are stored in (ro-)data sections */
class IRValue : public IROperand {
private:
    MetaDataType metaDataType;          // immediate data type
    std::vector<std::string> values;    // single value immediate only has 1 member, while multi-value array occupies more
    std::vector<std::size_t> arrayShape;
    bool allZero;
    std::string valueLabel;             // some immediate numbers are stored globally in (ro-)data section, so use label as index
    bool isArray;                       // judge whether it describes an array

public:
    /* @initialize */
    /* @commonParam: first arg: data type */
    /* @method: 1. for index rules 2, use (ro-)data section to store value, and use label as index */
    /* @param: label - globally defined, must be unique */
    /* @param: isArray - distinguish between float and array, which are translated in different ways */
    IRValue(MetaDataType newMetaDataType, const std::string &newLabel, bool newIsArray);
    /* @method: 2. for index rules 1 and 2 float case, you can directly initialize value stored here as single value */
    /*             for rule 1, no-need for label, leave null is OK */
    IRValue(MetaDataType newMetaDataType, const std::string &newValue, const std::string &newLabel, bool newIsArray);
    /* @method: 3. for index rules 2 array case, you can directly initialize array multiple value */
    IRValue(MetaDataType newMetaDataType, const std::vector<std::string>& newValues, const std::string &newLabel, bool newIsArray);
    /* @method: 4. for index rules 2 array case, you can directly initialize array multiple value */
    IRValue(MetaDataType newMetaDataType, const std::vector<std::string>& newValues, std::vector<std::size_t> newShape, const std::string &newLabel);
    /* @method: 5. if all value in vector are zero */
    IRValue(MetaDataType newMetaDataType, bool newIsAllZero, bool newIsArray, std::vector<std::size_t> newArrayShape, std::string newValueLabel);

    MetaDataType getMetaDataType() const override { return metaDataType; };
    /* only return first value, used for single value */
    std::string getValue() const override { return values.front(); };
    std::string getValue(int off) const override { return values[off]; };
    /* get all value in array */
    std::vector<std::string> getValues() const override { return values; };
    /* return label which can index the value */
    std::string getValueLabel() const override { return valueLabel; };
    /* used for array value */
    bool getIsArray() const override { return  isArray; };
    std::size_t getArraySize() const override { return values.size(); };
    std::vector<std::size_t> getArrayShape() const override { return arrayShape; };

    /* modify and access values field */
    void addValue(const std::string& newValue) override;
    void addValues(const std::vector<std::string>& newValues) override;
    bool setLabel(const std::string& newLabel) override { valueLabel = newLabel; return true; };
    bool setMetaDataType(MetaDataType newType) override { metaDataType = newType; return true; };
    bool setArrayShape(std::vector<std::size_t> newArrayShape) override { arrayShape = newArrayShape; return true; };
    bool setValues(std::vector<std::string> inValues) override { values = inValues; return true; };

    /* for target codes translation */
    Register *load(TargetCodes * t, bool isGeneralPurposeRegister) override;
    Register *loadTo(TargetCodes * t, const std::string &regName, bool isGeneralPurposeRegister) override;
    Register *loadTo(TargetCodes * t, Register *inReg) override;

    void print() const override;
    std::string getVal() const override;
    void genTargetValue(TargetCodes *t) const override;
};

/* user defined symbol as operand, including array symbol */
/* @initialize: symbol - target in symbol table; value - initialized value; whether is global symbol variable */
class IRSymbolVariable : public IROperand {
private:
    AbstractSymbol *symbol;                     // point to symbol table
    /* SSA format */
    bool assigned;                              // whether this symbol was defined in lVal
    std::vector<IROperand *> historySymbols;    // if user defined symbols are defined, we use temp vars to replace it, and those vars will be pushed into this field

    IROperand *initialValue;                      // if user initialized value for this symbol, those value will be linked here
    bool isGlobalSymbolVar;                     // determine whether this is globally defined
    /* Optimization */
    std::vector<int> activeRegions;             // used for calculation of variable active regions
    bool bindRegister;                          // used for register binding optimization, determine whether var shall be bound to register
    Register *targetBindRegister;               // if the variable is to bind register, point to that register
    bool alive;                                 // used for calculation of variable live and death

public:
    IRSymbolVariable(AbstractSymbol *newSymbol, IROperand *newValue, bool newIsGlobalSymbolVar);

    /* return fields stored in symbol table */
    std::string getSymbolName() const override { return symbol->getSymbolName(); };
    MetaDataType getMetaDataType() const override { return symbol->getMetaDataType(); };
    int getMemOffset() const override { return symbol->getOffset(); };
    bool getIsArray() const override { return symbol->getIsArray(); };
    std::vector<std::size_t> getArrayShape() const override { return symbol->getShape(); };
    uint64_t getMemPosition() const override { return symbol->getMemPosition(); };  // commonly don't use this method, use memOffset instead
    /* SSA */
    bool getAssigned() const override { return assigned; };
    std::vector<IROperand *> getHistorySymbols() const override { return historySymbols; };
    /* return latest version of replace temp var */
    IROperand *getLatestVersionSymbol() const override { return historySymbols.back(); };

    IROperand *getInitialValue() const override { return initialValue; };
    bool getIsGlobalSymbolVar() const override { return isGlobalSymbolVar; };

    /* Optimization fields */
    std::vector<int> getActiveRegions() const override { return activeRegions; };
    bool getBindRegister() const override { return bindRegister; };
    Register *getTargetBindRegister() const override { return targetBindRegister; };

    bool setAssigned() override { assigned = true; return true; };
    bool addHistorySymbol(IROperand *inSymbol) override { historySymbols.push_back(inSymbol); return true; };

    bool getIsAlive() const override { return alive; };
    void setAlive(bool set) override { alive = set; };
    void setMemOffset(int inOffset) override { symbol->setOffset(inOffset); };
    bool setMemPosition(uint64_t inMemPosition) override { symbol->setOffset(inMemPosition); return true; };
    bool setInitialValue(IROperand *inInitialValue) override { initialValue = inInitialValue; return true;  }
    bool setBindRegister(bool toBindRegister) override { bindRegister = toBindRegister; return true; };
    bool setTargetBindRegister(Register *inTargetBindRegister) override { targetBindRegister = inTargetBindRegister; return true; };
    bool setActiveRegions(std::vector<int> inActiveRegions) override { activeRegions = std::vector<int>(inActiveRegions.begin(), inActiveRegions.end()); return false; };

    Register *load(TargetCodes * t, bool isGeneralPurposeRegister) override;
    Register *loadTo(TargetCodes * t, const std::string &regName, bool isGeneralPurposeRegister) override;
    Register *loadTo(TargetCodes * t, Register *inReg) override;
    void storeFrom(TargetCodes * t, Register *reg) override;

    void print() const override;
    std::string getVal() const override;
    void genTargetValue(TargetCodes *t) const override;
    void genTargetGlobalValue(TargetCodes *t) const override;
};

/* only used in call and return operation, point to a function table */
class IRSymbolFunction : public IROperand {
private:
    SymbolTable *functionTable;     // point to function symbol table

public:
    explicit IRSymbolFunction(SymbolTable *function);
    std::string getFunctionName() const override { return functionTable->getFuncName(); };
    MetaDataType getReturnType() const override { return functionTable->getReturnType(); };
    SymbolTable *getFunctionSymbolTable() const override { return functionTable; };
    int getFrameSize() const override { return functionTable->getFrameSize(); };
    /* return all bind registers */
    std::vector<Register *> getBindRegisters()  const override { return functionTable->getBindRegisters(); };

    bool setFunctionSymbolTable(SymbolTable *inFunctionTable) override { functionTable = inFunctionTable; return true; };
    bool setFrameSize(int inSize) override { return functionTable->setFrameSize(inSize); return true; };

    void print() const override;
    std::string getVal() const override;

};

/* temp vars generated by compiler */
/* there are two types: */
/* 1. IR operation result temp storage */
/* 2. SSA, used for replace symbol var */
class IRTempVariable : public IROperand {
private:
    std::string symbolName;             // temp var name generated by compiler, must be different within function but can be same globally
    MetaDataType metaDataType;          // data type
    std::vector<std::size_t> arrayShape;
    bool isArray;
    /* SSA */
    bool assigned;                      // whether temp vars are assigned, shared expression
    std::vector<IROperand *> historySymbols;    // if user defined symbols are defined, we use temp vars to replace it, and those vars will be pushed into this field optimization may use
    bool aliasToVar;                 // whether is type-2
    IROperand *parentVariable;          // if is type-2, point to symbol var
    int offset;                         // memory offset
    IROperand *initialValue;              // not used
    /* Optimization */
    std::vector<int> activeRegions;
    bool bindRegister;
    Register *targetBindRegister;
    bool alive;

public:
    /* @initialize */
    /* @method: 1. type-1 temp var, determine name and data type */
    IRTempVariable(std::string newName, MetaDataType newMetaDataType);
    /* @method: 2. type-1 temp var, determine name and data type */
    IRTempVariable(std::string newName, MetaDataType newMetaDataType, std::vector<std::size_t> newShape, bool newIsArray);
    /* @method: 3. type-2 temp var, pass parent symbol var directly and fixed */
    IRTempVariable(std::string newName, MetaDataType newMetaDataType, IROperand *newParentVariable);
    /* @method: 4. type-1 temp var, determine name, data type and also initial value */
    IRTempVariable(std::string newName, MetaDataType newMetaDataType, IRValue *newValue);

    std::string getSymbolName() const override { return symbolName; };
    MetaDataType getMetaDataType() const override { return metaDataType; };
    bool getAssigned() const override { return assigned; };
    std::vector<IROperand *> getHistorySymbols() const override { return historySymbols; };
    /* return latest version of replace temp var */
    IROperand *getLatestVersionSymbol() const override { return historySymbols.back(); };
    std::vector<std::size_t> getArrayShape() const override { return arrayShape; };
    bool getIsArray() const override { return  isArray; };
    bool getAliasToVar() const override { return aliasToVar; };
    IROperand *getParentVariable() const override { return parentVariable; };
    IROperand *getInitialValue() const override { return initialValue; };
    std::vector<int> getActiveRegions() const override { return activeRegions; };
    bool getBindRegister() const override { return bindRegister; };
    Register *getTargetBindRegister() const override { return targetBindRegister; };
    bool getIsAlive() const override { return alive; };

    void setAlive(bool set) override { alive = set; };
    bool setAssigned() override { assigned = true; return true; };
    bool addHistorySymbol(IROperand *inSymbol) override { historySymbols.push_back(inSymbol); return true; };
    bool setArrayShape(std::vector<std::size_t> newArrayShape) override { arrayShape = newArrayShape; return true; };
    bool setIsArray(bool newIsArray) { isArray = newIsArray; return true; };
    bool setInitialValue(IROperand *inInitialValue) override { initialValue = inInitialValue; return true;  }
    bool setAliasToVar() override { aliasToVar = true; return true; };
    bool setParentVariable(IROperand *inParentVariable) override { aliasToVar = true; parentVariable = inParentVariable; return true; };
    bool setActiveRegions(std::vector<int> inActiveRegions) override { activeRegions = std::vector<int>(inActiveRegions.begin(), inActiveRegions.end()); return true; };
    bool setBindRegister(bool toBindRegister) override { bindRegister = toBindRegister; return true; };
    bool setTargetBindRegister(Register *inTargetBindRegister) override { targetBindRegister = inTargetBindRegister; return true; };

    void setMemOffset(int inOffset) override { offset = inOffset; };
    int getMemOffset() const override { return offset; };

    Register *load(TargetCodes * t, bool isGeneralPurposeRegister) override;
    Register *loadTo(TargetCodes * t, const std::string &regName, bool isGeneralPurposeRegister) override;
    Register *loadTo(TargetCodes * t, Register *inReg) override;
    void storeFrom(TargetCodes * t, Register *reg) override;

    void print() const override;
    std::string getVal() const override;
};
