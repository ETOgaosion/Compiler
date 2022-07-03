#include "IRCode.h"
#include "IROperands.h"

#pragma once

class IRProgram;

class IRFunction {
private:
    std::string functionName;
    std::unordered_map<std::string, IRSymbolVariable *> paramVariables;
    std::unordered_map<std::string, IRSymbolVariable *> localVariables;
    std::unordered_map<std::string, IRTempVariable *> tempVariables;
    std::vector<IRCode *> codes;
    std::unordered_map<std::string, IRLabel *> labels;

    std::vector<int> entrances;
    std::vector<std::vector<IRCode *>> basicBlocks;
    std::vector<std::vector<int>> controlFlow;
    std::vector<int> cycleNum;

    int tempCount;
    int labelCount;
    int frameSize;

    SymbolTable *functionTable;

public:
    IRProgram * ir;

    explicit IRFunction(std::string newFunctionName, SymbolTable *newFunctionTable);

    bool addParamVariable(IRSymbolVariable *newVariable);
    bool addLocalVariable(int block, IRSymbolVariable *newVariable);
    IRTempVariable *addTempVariable(MetaDataType newMetaDataType);
    IRTempVariable *addTempVariable(IROperand *parentSymbolVariable);
    IRSymbolVariable *addSymbolVariable(int block, AbstractSymbol *newSymbol, IRValue *initVal);
    IRLabel *addLabel();
    bool addCode(IRCode *newCode);
    bool addCodes(const std::vector<IRCode *>& newCodes);
    int calFrameSize();
    int addFrameSize(int inFrameSize) { frameSize += inFrameSize;};

    IRValue* immAddSub(IROperand* op1, IROperand* op2, IROperation op);
    IRValue* immMul(IROperand* op1, IROperand* op2);
    IRValue* immDiv(IROperand* op1, IROperand* op2);


    void liveVarAnalysis();
    void basicBlockDivision();

    void calVarActiveRegions();
    static bool vectorOverlap(const std::vector<int>& a, const std::vector<int>& b);
    std::unordered_map<IROperand *, std::vector<IROperand *>> calSymVarRelations();
    std::unordered_map<IROperand *, int> calVarCosts();
    void varBindRegisters(TargetCodes *t);

    void constFolding();

    std::string getFunctionName() const;
    SymbolTable *getFuncSymbolTable() const { return functionTable; };
    IRSymbolVariable *getLocalVariable(int block, const std::string& varName);
    IRSymbolVariable *getParamVariable(const std::string& varName);
    IRTempVariable *getTempVariable(const std::string& varName);
    IRCode *getCode(int cnt);
    std::vector<IRCode *> &getCodes();
    IRLabel *getLabel(const std::string& labelName);
    int getFrameSize() const;
    std::vector<Register *> getBindRegisters() const;

    void print(SymbolTable *globalSymbolTable) const;
    void targetCodeGen(TargetCodes * t);
};

class IRProgram {
private:
    IRProgram();
    SymbolTable *globalSymbolTable;
    std::string programName;
    std::unordered_map<std::string, IRSymbolVariable *> globalVariables;
    std::unordered_map<std::string, IRFunction *> functions;
    std::unordered_map<std::string, IRSymbolFunction *> funcSymbols;
    std::unordered_map<std::string, IRValue *> immValues;

    int valueCount;
    
public:

    static IRProgram *getIRProgram(std::string newProgramName, SymbolTable *newGlobalSymbolTable);
    void initializeFileds(std::string newProgramName, SymbolTable *newGlobalSymbolTable);

    IRSymbolVariable *addGlobalVariable(AbstractSymbol *symbol, IRValue *newValue);
    bool addFunction(IRFunction *newFunction);
    bool addSymbolFunction(IRSymbolFunction *funcSymbol);
    IRValue *addImmValue(MetaDataType inMetaDataType, const std::string &inValue);
    IRValue *addImmValue(const std::string &inLabel, MetaDataType inMetaDataType, const std::string &inValue);
    IRValue *addMulSameImmValue(MetaDataType inMetaDataType, const std::string &inValue, int num);
    IRValue *addMulImmValue(MetaDataType inMetaDataType, std::vector<std::string> &inValues);

    std::unordered_map<std::string, IRSymbolVariable *> getGlobalVariables() const {return globalVariables; };
    SymbolTable *getGlobalSymbolTable() const { return globalSymbolTable; };
    IRSymbolVariable *getGlobalVariable(const std::string& varName);
    IRFunction *getFunction(const std::string& functionName);
    IRSymbolFunction *getSymbolFunction(const std::string& functionName);
    IRValue *getImmValue(const std::string& inImmValue);
    IRValue *getImmValue(const std::vector<std::string>& inImmValues);

    void print();
    void write(const std::string &path);
    void targetGen(TargetCodes * t);
    void targetCodePrint(TargetCodes * t);
    void targetCodeWrite(TargetCodes * t, std::string path);
};



