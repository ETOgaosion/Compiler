#include <unordered_map>
#include <vector>
#include <utility>
#include <string>
#include <iostream>

#pragma once

using namespace std;

enum class SymbolType {
    PARAM,
    VAR,
    CONST
};

enum class TableType {
    GLOBAL,
    FUNC,
    BLOCK
};

enum class MetaDataType {
    VOID,
    BOOL,
    INT,
    FLOAT,
    DOUBLE
};

class AbstractSymbol {
private:
    string symbolName;
    SymbolType symbolType;
    MetaDataType metaDataType;
    bool isArray;
    size_t size;
    bool initialized;

protected:

public:
    AbstractSymbol();
    AbstractSymbol(string inSymbolName, SymbolType inSymbolType, MetaDataType inMetaDataType, bool inIsArray, size_t inSize, bool inInitialized);
    ~AbstractSymbol();
    virtual string getSymbolName() const;
    virtual SymbolType getSymbolType() const;
    virtual MetaDataType getMetaDataType() const;
    virtual bool getIsArray() const;
    virtual size_t getSize() const;
    virtual bool getInitialized() const;

};

class ParamSymbol : public AbstractSymbol {
private:

protected:

public:
    ParamSymbol(string inSymbolName, SymbolType inSymbolType, MetaDataType inMetaDataType, bool inIsArray, size_t inSize, bool inInitialized);
    ~ParamSymbol();

};

class VarSymbol : public AbstractSymbol {
private:

protected:

public:
    VarSymbol(string inSymbolName, SymbolType inSymbolType, MetaDataType inMetaDataType, bool inIsArray, size_t inSize, bool inInitialized);
    ~VarSymbol();

};

class ConstSymbol : public AbstractSymbol {
private:

protected:

public:
    ConstSymbol(string inSymbolName, SymbolType inSymbolType, MetaDataType inMetaDataType, bool inIsArray, size_t inSize, bool inInitialized);
    ~ConstSymbol();
};


class ParamArraySymbol : public AbstractSymbol {
private:

protected:

public:
    ParamArraySymbol(string inSymbolName, SymbolType inSymbolType, MetaDataType inMetaDataType, bool inIsArray, size_t inSize, bool inInitialized);
    ~ParamArraySymbol();

};

class VarArraySymbol : public AbstractSymbol {
private:

protected:

public:
    VarArraySymbol(string inSymbolName, SymbolType inSymbolType, MetaDataType inMetaDataType, bool inIsArray, size_t inSize, bool inInitialized);
    ~VarArraySymbol();

};

class ConstArraySymbol : public AbstractSymbol {
private:

protected:

public:
    ConstArraySymbol(string inSymbolName, SymbolType inSymbolType, MetaDataType inMetaDataType, bool inIsArray, size_t inSize, bool inInitialized);
    ~ConstArraySymbol();
};

class SymbolFactory {
private:

protected:

public:
    static AbstractSymbol *createSymbol(string inSymbolName, SymbolType inSymbolType, MetaDataType inMetaDataType, bool inIsArray, size_t inSize, bool inInitialized);

};

// --------- SymbolTables ----------

class FuncSymbolTableList;
class BlockSymbolTableList;
class SymbolTable;
class GlobalSymbolTable;
class FuncSymbolTable;
class BlockSymbolTable;

class FuncSymbolTableList {
private:

protected:
    unordered_map<string, SymbolTable *> funcSymbolTableList;

public:
    FuncSymbolTableList();
    ~FuncSymbolTableList();
    virtual SymbolTable *insertFuncSymbolTableSafely(string inFuncName, MetaDataType inReturnType);
    virtual SymbolTable *insertFuncSymbolTableSafely(string inFuncName, MetaDataType inReturnType, SymbolTable *inParentSymbolTable);

    virtual SymbolTable *lookUpFuncSymbolTable(string inFuncName) const;

};

class BlockSymbolTableList {
private:

protected:
    vector<SymbolTable *> blockSymbolTableList;

public:
    BlockSymbolTableList();
    ~BlockSymbolTableList();
    virtual SymbolTable *insertBlockSymbolTable();
    virtual SymbolTable *insertBlockSymbolTable(SymbolTable *inParentSymbolTable);
    
    virtual SymbolTable *getBlockSymbolTable(int index) const;

};

class SymbolTable : public FuncSymbolTableList, public BlockSymbolTableList {
private:
    SymbolTable *parentSymbolTable;
    TableType symbolTableType;

protected:
    unordered_map<string, AbstractSymbol *> abstractSymbolList;
    unordered_map<string, AbstractSymbol *> paramSymbolList;

public:
    SymbolTable();  // note: should promiss GlobalSymbolTable construct for once
    SymbolTable(TableType inTableType);
    SymbolTable(SymbolTable *inParentSymbolTable);
    SymbolTable(TableType inTableType, SymbolTable *inParentSymbolTable);
    ~SymbolTable();

    virtual AbstractSymbol *insertAbstractSymbolSafely(string inSymbolName, SymbolType inSymbolType, MetaDataType inMetaDataType, bool inIsArray, size_t inSize, bool inInitialized);
    virtual AbstractSymbol *insertParamSymbolSafely(string inSymbolName, SymbolType inSymbolType, MetaDataType inMetaDataType, bool inIsArray, size_t inSize) { return nullptr;};
    virtual bool insertParamType(SymbolType inSymbolType, MetaDataType inMetaDataType, bool inIsArray, size_t inSize) { return false; };

    virtual AbstractSymbol *lookUpAbstractSymbol(string inSymbolName) const;
    virtual AbstractSymbol *lookUpParamSymbol(string inSymbolNmae) const { return nullptr; };
    virtual tuple <SymbolType, MetaDataType, bool, size_t> lookUpParamDataType(string inSymbolName) const { return tuple <SymbolType, MetaDataType, bool, size_t>(SymbolType::CONST, MetaDataType::VOID, false, 0); };

    virtual SymbolTable *getParentSymbolTable() const;
    static SymbolTable *getGlobalSymbolTable();
    virtual string getFuncName() const { return string(); };
    virtual MetaDataType getReturnType() const { return MetaDataType::VOID; };
    virtual int getParamNum() const { return 0; };
    
    virtual bool setFuncName(string inFuncname) { return false;};
    virtual bool setReturnType(MetaDataType inReturnType) { return false;};
    virtual int setParamNum() { return false; };
    virtual bool setParamDataTypeList() { return false; };
    virtual bool setParentSymbolTable(SymbolTable *parentSymbolTable);

    virtual bool compareAbstractSymbolDataType(string inSymbolName, SymbolType inSymbolType, MetaDataType inMetaDataType, bool inIsArray, size_t inSize) const;
    virtual bool compareParamSymbolDataType(int index, SymbolType inSymbolType, MetaDataType inMetaDataType, bool inIsArray, size_t inSize) const { return false; };

};

// parent help to implement sigleton pattern
class GlobalSymbolTable : public SymbolTable {
private:
    GlobalSymbolTable(GlobalSymbolTable &globalSymbolTable) = delete;
    GlobalSymbolTable &operator = (const GlobalSymbolTable &globalSymbolTable) = delete;
    ~GlobalSymbolTable();

protected:

public:
    GlobalSymbolTable();

};

class FuncSymbolTable : public SymbolTable {
private:
    string funcName;
    MetaDataType returnType;
    int paramNum;
    vector<tuple <SymbolType, MetaDataType, bool, size_t> > paramDataTypeList;

protected:

public:
    FuncSymbolTable();
    FuncSymbolTable(string inFuncName, MetaDataType inReturnType);
    FuncSymbolTable(string inFuncName, MetaDataType inReturnType, SymbolTable *inParentSymbolTable);
    ~FuncSymbolTable();
    AbstractSymbol *insertParamSymbolSafely(string inSymbolName, SymbolType inSymbolType, MetaDataType inMetaDataType, bool inIsArray, size_t inSize) override;
    bool insertParamType(SymbolType inSymbolType, MetaDataType inMetaDataType, bool inIsArray, size_t inSize) override;

    string getFuncName() const override;
    MetaDataType getReturnType() const override;
    int getParamNum() const override;

    bool setFuncName(string inFuncName) override;
    bool setReturnType(MetaDataType inReturnType) override;
    int setParamNum() override;
    bool setParamDataTypeList() override;

    bool compareParamSymbolDataType(int index, SymbolType inSymbolType, MetaDataType inMetaDataType, bool inIsArray, size_t inSize) const override;

};

class BlockSymbolTable : public SymbolTable {
private:

protected:

public:
    BlockSymbolTable();
    BlockSymbolTable(SymbolTable *inParentSymbolTable);
    ~BlockSymbolTable();

};

class SymbolTableFactory {
private:

protected:

public:
    static SymbolTable *createSymbolTable(TableType inTableType);

};