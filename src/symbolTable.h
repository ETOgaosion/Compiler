#include <unordered_map>
#include <vector>
#include <utility>
#include <string>
#include <iostream>

#pragma once

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
    std::string symbolName;
    SymbolType symbolType;
    MetaDataType metaDataType;
    bool isArray;
    size_t size;

protected:

public:
    AbstractSymbol();
    AbstractSymbol(std::string inSymbolName, SymbolType inSymbolType, MetaDataType inMetaDataType, bool inIsArray, size_t inSize);
    ~AbstractSymbol();
    virtual std::string getSymbolName() const;
    virtual SymbolType getSymbolType() const;
    virtual MetaDataType getMetaDataType() const;
    virtual bool getIsArray() const;
    virtual size_t getSize() const;

};

class ParamSymbol : public AbstractSymbol {
private:

protected:

public:
    ParamSymbol(std::string inSymbolName, SymbolType inSymbolType, MetaDataType inMetaDataType, bool inIsArray, size_t inSize);
    ~ParamSymbol();

};

class VarSymbol : public AbstractSymbol {
private:

protected:

public:
    VarSymbol(std::string inSymbolName, SymbolType inSymbolType, MetaDataType inMetaDataType, bool inIsArray, size_t inSize);
    ~VarSymbol();

};

class ConstSymbol : public AbstractSymbol {
private:

protected:

public:
    ConstSymbol(std::string inSymbolName, SymbolType inSymbolType, MetaDataType inMetaDataType, bool inIsArray, size_t inSize);
    ~ConstSymbol();
};


class ParamArraySymbol : public AbstractSymbol {
private:

protected:

public:
    ParamArraySymbol(std::string inSymbolName, SymbolType inSymbolType, MetaDataType inMetaDataType, bool inIsArray, size_t inSize);
    ~ParamArraySymbol();

};

class VarArraySymbol : public AbstractSymbol {
private:

protected:

public:
    VarArraySymbol(std::string inSymbolName, SymbolType inSymbolType, MetaDataType inMetaDataType, bool inIsArray, size_t inSize);
    ~VarArraySymbol();

};

class ConstArraySymbol : public AbstractSymbol {
private:

protected:

public:
    ConstArraySymbol(std::string inSymbolName, SymbolType inSymbolType, MetaDataType inMetaDataType, bool inIsArray, size_t inSize);
    ~ConstArraySymbol();
};

class SymbolFactory {
private:

protected:

public:
    static AbstractSymbol *createSymbol(std::string inSymbolName, SymbolType inSymbolType, MetaDataType inMetaDataType, bool inIsArray, size_t inSize);

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
    std::unordered_map<std::string, SymbolTable *> funcSymbolTableList;

public:
    FuncSymbolTableList();
    ~FuncSymbolTableList();
    virtual SymbolTable *insertFuncSymbolTableSafely(std::string inFuncName, MetaDataType inReturnType);
    virtual SymbolTable *insertFuncSymbolTableSafely(std::string inFuncName, MetaDataType inReturnType, SymbolTable *inParentSymbolTable);
    virtual SymbolTable *insertFuncSymbolTableSafely(SymbolTable *inFuncSymbolTable);

    virtual SymbolTable *lookUpFuncSymbolTable(std::string inFuncName) const;

};

class BlockSymbolTableList {
private:

protected:
    std::vector<SymbolTable *> blockSymbolTableList;

public:
    BlockSymbolTableList();
    ~BlockSymbolTableList();
    virtual SymbolTable *insertBlockSymbolTable();
    //virtual SymbolTable *insertBlockSymbolTable(SymbolTable *inParentSymbolTable);
    virtual SymbolTable *insertBlockSymbolTable(SymbolTable *inBlockSymbolTable);
    
    virtual SymbolTable *getBlockSymbolTable(int index) const;

};

class SymbolTable : public FuncSymbolTableList, public BlockSymbolTableList {
private:
    SymbolTable *parentSymbolTable;
    TableType symbolTableType;

protected:
    std::unordered_map<std::string, AbstractSymbol *> abstractSymbolList;

public:
    SymbolTable();  // note: should promiss GlobalSymbolTable construct for once
    SymbolTable(TableType inTableType);
    SymbolTable(SymbolTable *inParentSymbolTable);
    SymbolTable(TableType inTableType, SymbolTable *inParentSymbolTable);
    ~SymbolTable();

    virtual AbstractSymbol *insertAbstractSymbolSafely(std::string inSymbolName, SymbolType inSymbolType, MetaDataType inMetaDataType, bool inIsArray, size_t inSize);
    virtual AbstractSymbol *insertAbstractSymbolSafely(AbstractSymbol *inAbstractSymbol);
    virtual AbstractSymbol *insertParamSymbolSafely(std::string inSymbolName, SymbolType inSymbolType, MetaDataType inMetaDataType, bool inIsArray, size_t inSize) { return nullptr;};
    virtual AbstractSymbol *insertParamSymbolSafely(AbstractSymbol *inParamSymbol) { return nullptr;};
    virtual bool insertParamType(SymbolType inSymbolType, MetaDataType inMetaDataType, bool inIsArray, size_t inSize) { return false; };
    virtual bool insertParamType(AbstractSymbol *inParamSymbol) { return false; };

    virtual AbstractSymbol *lookUpAbstractSymbol(std::string inSymbolName) const;
    virtual AbstractSymbol *lookUpAbstractSymbolGlobal(std::string inSymbolName) const;
    virtual AbstractSymbol *lookUpParamSymbol(std::string inSymbolNmae) const { return nullptr; };
    virtual std::tuple <SymbolType, MetaDataType, bool, size_t> lookUpParamDataType(std::string inSymbolName) const { return std::tuple <SymbolType, MetaDataType, bool, size_t>(SymbolType::CONST, MetaDataType::VOID, false, 0); };

    virtual SymbolTable *getParentSymbolTable() const;
    static SymbolTable *getGlobalSymbolTable();
    virtual std::string getFuncName() const { return std::string(); };
    virtual MetaDataType getReturnType() const { return MetaDataType::VOID; };
    virtual int getParamNum() const { return 0; };
    
    virtual bool setFuncName(std::string inFuncname) { return false;};
    virtual bool setReturnType(MetaDataType inReturnType) { return false;};
    virtual int setParamNum() { return false; };
    virtual bool setParamDataTypeList() { return false; };
    virtual bool setParentSymbolTable(SymbolTable *parentSymbolTable);

    virtual bool compareAbstractSymbolDataType(std::string inSymbolName, SymbolType inSymbolType, MetaDataType inMetaDataType, bool inIsArray, size_t inSize) const;
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
    std::string funcName;
    MetaDataType returnType;
    int paramNum;
    std::unordered_map<std::string, AbstractSymbol *> paramSymbolList;
    std::vector<std::tuple <SymbolType, MetaDataType, bool, size_t> > paramDataTypeList;

protected:

public:
    FuncSymbolTable();
    FuncSymbolTable(std::string inFuncName, MetaDataType inReturnType);
    FuncSymbolTable(std::string inFuncName, MetaDataType inReturnType, SymbolTable *inParentSymbolTable);
    ~FuncSymbolTable();
    AbstractSymbol *insertParamSymbolSafely(std::string inSymbolName, SymbolType inSymbolType, MetaDataType inMetaDataType, bool inIsArray, size_t inSize) override;
    AbstractSymbol *insertParamSymbolSafely(AbstractSymbol *inParamSymbol) override;
    bool insertParamType(SymbolType inSymbolType, MetaDataType inMetaDataType, bool inIsArray, size_t inSize) override;
    bool insertParamType(AbstractSymbol *inParamSymbol) override;

    AbstractSymbol *lookUpParamSymbol(std::string inSymbolNmae) const override;
    std::tuple <SymbolType, MetaDataType, bool, size_t> lookUpParamDataType(std::string inSymbolName) const override;

    std::string getFuncName() const override;
    MetaDataType getReturnType() const override;
    int getParamNum() const override;

    bool setFuncName(std::string inFuncName) override;
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