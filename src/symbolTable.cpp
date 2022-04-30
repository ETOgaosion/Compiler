#include "symbolTable.h"
#include "errorMsg.h"

template <class T> bool findDuplicateName(T list, string className, string name) {
    auto searchSymbol = list.find(name);
    if (searchSymbol != list.end()) {
        ERROR_INSERT_DUPLICATED(className, name);
        return true;
    }
    return false;
}

// -------- Symbols ---------

AbstractSymbol::AbstractSymbol() {
    // never use this constructor directly
    // only called by default before children's constructor
}

AbstractSymbol::AbstractSymbol(string inSymbolName, SymbolType inSymbolType, MetaDataType inMetaDataType, bool inIsArray, size_t inSize, bool inInitialized){
    symbolName = inSymbolName;
    symbolType = inSymbolType;
    metaDataType = inMetaDataType;
    isArray = inIsArray;
    size = inSize;
    initialized = inInitialized;

}

AbstractSymbol::~AbstractSymbol() {}

string AbstractSymbol::getSymbolName() const {
    return symbolName;
}

SymbolType AbstractSymbol::getSymbolType() const {
    return symbolType;
}

MetaDataType AbstractSymbol::getMetaDataType() const {
    return metaDataType;
}

size_t AbstractSymbol::getSize() const {
    return size;
}

bool AbstractSymbol::getInitialized() const {
    return initialized;
}

// --------

ParamSymbol::ParamSymbol(string inSymbolName, SymbolType inSymbolType, MetaDataType inMetaDataType, bool inIsArray, size_t inSize, bool inInitialized) {
    if (inSymbolType == SymbolType::PARAM){
        AbstractSymbol(inSymbolName, inSymbolType, inMetaDataType, inIsArray, inSize, inInitialized);
    }
    else {
        ERROR_INSTANCE("ParamSymbol", inSymbolType);
    }
}

// --------

VarSymbol::VarSymbol(string inSymbolName, SymbolType inSymbolType, MetaDataType inMetaDataType, bool inIsArray, size_t inSize, bool inInitialized) {
    if (inSymbolType == SymbolType::VAR){
        AbstractSymbol(inSymbolName, inSymbolType, inMetaDataType, inIsArray, inSize, inInitialized);
    }
    else {
        ERROR_INSTANCE("VarSymbol", inSymbolType);
    }
}

// --------

ConstSymbol::ConstSymbol(string inSymbolName, SymbolType inSymbolType, MetaDataType inMetaDataType, bool inIsArray, size_t inSize, bool inInitialized) {
    if (inSymbolType == SymbolType::CONST){
        AbstractSymbol(inSymbolName, inSymbolType, inMetaDataType, inIsArray, inSize, inInitialized);
    }
    else {
        ERROR_INSTANCE("ConstSymbol", inSymbolType);
    }
}

// --------

ParamArraySymbol::ParamArraySymbol(string inSymbolName, SymbolType inSymbolType, MetaDataType inMetaDataType, bool inIsArray, size_t inSize, bool inInitialized) {
    if (inSymbolType == SymbolType::PARAM && inIsArray) {
        AbstractSymbol(inSymbolName, inSymbolType, inMetaDataType, inIsArray, inSize, inInitialized);
    }
    else {
        ERROR_INSTANCE("ParamArraySymbol", inSymbolType);
    }
}

// --------

VarArraySymbol::VarArraySymbol(string inSymbolName, SymbolType inSymbolType, MetaDataType inMetaDataType, bool inIsArray, size_t inSize, bool inInitialized) {
    if (inSymbolType == SymbolType::VAR && inIsArray) {
        AbstractSymbol(inSymbolName, inSymbolType, inMetaDataType, inIsArray, inSize, inInitialized);
    }
    else {
        ERROR_INSTANCE("VarArraySymbol", inSymbolType);
    }
}

// --------

ConstArraySymbol::ConstArraySymbol(string inSymbolName, SymbolType inSymbolType, MetaDataType inMetaDataType, bool inIsArray, size_t inSize, bool inInitialized) {
    if (inSymbolType == SymbolType::CONST && inIsArray) {
        AbstractSymbol(inSymbolName, inSymbolType, inMetaDataType, inIsArray, inSize, inInitialized);
    }
    else {
        ERROR_INSTANCE("ConstArraySymbol", inSymbolType);
    }
}


AbstractSymbol *SymbolFactory::createSymbol(string inSymbolName, SymbolType inSymbolType, MetaDataType inMetaDataType, bool inIsArray, size_t inSize, bool inInitialized){
    switch(inSymbolType){
        case SymbolType::PARAM:
            if (inIsArray){
                return new ParamArraySymbol(inSymbolName, inSymbolType, inMetaDataType, inIsArray, inSize, inInitialized);
            }
            return new ParamSymbol(inSymbolName, inSymbolType, inMetaDataType, inIsArray, inSize, inInitialized);
        case SymbolType::VAR:
            if (inIsArray) {
                return new VarArraySymbol(inSymbolName, inSymbolType, inMetaDataType, inIsArray, inSize, inInitialized);
            }
            return new VarSymbol(inSymbolName, inSymbolType, inMetaDataType, inIsArray, inSize, inInitialized);
        case SymbolType::CONST:
            if (inIsArray) {
                return new ConstArraySymbol(inSymbolName, inSymbolType, inMetaDataType, inIsArray, inSize, inInitialized);
            }
            return new ConstSymbol(inSymbolName, inSymbolType, inMetaDataType, inIsArray, inSize, inInitialized);
        default:
            return nullptr;
    }
}

// --------- SymbolTables ----------

FuncSymbolTableList::FuncSymbolTableList() {
    funcSymbolTableList.empty();
}

FuncSymbolTableList::~FuncSymbolTableList() {}

SymbolTable *FuncSymbolTableList::insertFuncSymbolTableSafely(string inFuncName, MetaDataType inReturnType) {
    if (findDuplicateName(funcSymbolTableList, "FuncSymbolTableList", inFuncName)){
        return nullptr;
    }
    SymbolTable *insertSymbolTable = new FuncSymbolTable(inFuncName, inReturnType);
    funcSymbolTableList.emplace(inFuncName, insertSymbolTable);
    return insertSymbolTable;
}

SymbolTable *FuncSymbolTableList::insertFuncSymbolTableSafely(string inFuncName, MetaDataType inReturnType, SymbolTable *inParentSymbolTable) {
    if (findDuplicateName(funcSymbolTableList, "FuncSymbolTableList", inFuncName)){
        return nullptr;
    }
    SymbolTable *insertSymbolTable = new FuncSymbolTable(inFuncName, inReturnType, inParentSymbolTable);
    funcSymbolTableList.emplace(inFuncName, insertSymbolTable);
    return insertSymbolTable;
}

// --------

BlockSymbolTableList::BlockSymbolTableList() {
    blockSymbolTableList.empty();
}

BlockSymbolTableList::~BlockSymbolTableList() {}

SymbolTable *BlockSymbolTableList::insertBlockSymbolTable() {
    SymbolTable *insertSymbolTable = new BlockSymbolTable();
    blockSymbolTableList.push_back(insertSymbolTable);
    return insertSymbolTable;
}

SymbolTable *BlockSymbolTableList::insertBlockSymbolTable(SymbolTable *inParentSymbolTable) {
    SymbolTable *insertSymbolTable = new BlockSymbolTable(inParentSymbolTable);
    blockSymbolTableList.push_back(insertSymbolTable);
    return insertSymbolTable;
}

SymbolTable *BlockSymbolTableList::getBlockSymbolTable(int index) const {
    if (index >= blockSymbolTableList.size()){
        ERROR_GET("BlockSymbolTableList", index);
        return nullptr;
    }
    return blockSymbolTableList[index];
}

// --------

SymbolTable::SymbolTable() {}

SymbolTable::SymbolTable(TableType inTableType) {
    symbolTableType = inTableType;
    if (symbolTableType ==  TableType::GLOBAL) {
        getGlobalSymbolTable();
    }
}

SymbolTable::SymbolTable(SymbolTable *inParentSymbolTable) {
    parentSymbolTable = inParentSymbolTable;
}

SymbolTable::SymbolTable(TableType inTableType, SymbolTable *inParentSymbolTable) {
    symbolTableType = inTableType;
    parentSymbolTable = inParentSymbolTable;
    if (symbolTableType ==  TableType::GLOBAL) {
        getGlobalSymbolTable();
    }
}

SymbolTable::~SymbolTable() {}

AbstractSymbol *SymbolTable::insertAbstractSymbolSafely(string inSymbolName, SymbolType inSymbolType, MetaDataType inMetaDataType, bool inIsArray, size_t inSize, bool inInitialized) {
    if (findDuplicateName(abstractSymbolList, "AbstractSymbolList", inSymbolName)){
        return nullptr;
    }
    AbstractSymbol *insertAbstractSymbol = SymbolFactory::createSymbol(inSymbolName, inSymbolType, inMetaDataType, inIsArray, inSize, inInitialized);
    abstractSymbolList.emplace(inSymbolName, insertAbstractSymbol);
    return insertAbstractSymbol;
}

AbstractSymbol *SymbolTable::lookUpAbstractSymbol(string inSymbolName) const {
    auto searchSymbol = abstractSymbolList.find(inSymbolName);
    if (searchSymbol != abstractSymbolList.end()) {
        return searchSymbol->second;
    }
    if (symbolTableType == TableType::FUNC) {
        searchSymbol = paramSymbolList.find(inSymbolName);
        if (searchSymbol != paramSymbolList.end()) {
            return searchSymbol->second;
        }
        return parentSymbolTable->lookUpAbstractSymbol(inSymbolName);
    }
    else if (symbolTableType == TableType::BLOCK) {
        return parentSymbolTable->lookUpAbstractSymbol(inSymbolName);
    }
    return nullptr;
}

SymbolTable *SymbolTable::getParentSymbolTable() const {
    return parentSymbolTable;
}

static SymbolTable *getGlobalSymbolTable() {
    static SymbolTable *globalSymbolTable = new GlobalSymbolTable();
    return globalSymbolTable;
}

bool SymbolTable::setParentSymbolTable(SymbolTable *inParentSymbolTable) {
    parentSymbolTable = inParentSymbolTable;
    return true;
}

bool SymbolTable::compareAbstractSymbolDataType(string inSymbolName, SymbolType inSymbolType, MetaDataType inMetaDataType, bool inIsArray, size_t inSize) const {
    AbstractSymbol *curSymbol = lookUpAbstractSymbol(inSymbolName);
    if (!curSymbol) {
        ERROR_COMPARE_NO_SYMBOL("SymbolTable", inSymbolName);
        return false;
    }
    return  curSymbol->getSymbolType() == inSymbolType &&
            curSymbol->getMetaDataType() == inMetaDataType &&
            curSymbol->getIsArray() == inIsArray &&
            (inIsArray ? curSymbol->getSize() == inSize : true);

}

// --------

GlobalSymbolTable::GlobalSymbolTable() {}

GlobalSymbolTable::~GlobalSymbolTable() {}

// --------

FuncSymbolTable::FuncSymbolTable() {}

FuncSymbolTable::FuncSymbolTable(string inFuncName, MetaDataType inReturnType) {
    funcName = inFuncName;
    returnType = inReturnType;
}

FuncSymbolTable::FuncSymbolTable(string inFuncName, MetaDataType inReturnType, SymbolTable *inParentSymbolTable) {
    funcName = inFuncName;
    returnType = inReturnType;
    SymbolTable::setParentSymbolTable(inParentSymbolTable);
}

AbstractSymbol *FuncSymbolTable::insertParamSymbolSafely(string inSymbolName, SymbolType inSymbolType, MetaDataType inMetaDataType, bool inIsArray, size_t inSize) {
    if (findDuplicateName(paramSymbolList, "FuncSymbolTable", inSymbolName)) {
        return nullptr;
    }
    AbstractSymbol *insertParamSymbol = SymbolFactory::createSymbol(inSymbolName, inSymbolType, inMetaDataType, inIsArray, inSize, true);
    paramSymbolList.emplace(inSymbolName, insertParamSymbol);
    return insertParamSymbol;
}

bool FuncSymbolTable::insertParamType(SymbolType inSymbolType, MetaDataType inMetaDataType, bool inIsArray, size_t inSize) {
    paramDataTypeList.push_back(tuple<SymbolType, MetaDataType, bool, size_t>(inSymbolType, inMetaDataType, inIsArray, inSize));
    return true;
}

string FuncSymbolTable::getFuncName() const {
    return funcName;
}

MetaDataType FuncSymbolTable::getReturnType() const {
    return returnType;
}

int FuncSymbolTable::getParamNum() const { 
    return paramNum; 
}

bool FuncSymbolTable::setFuncName(string inFuncName) {
    funcName = inFuncName;
    return true;
}

bool FuncSymbolTable::setReturnType(MetaDataType inReturnType) {
    returnType = inReturnType;
    return true;
}

int FuncSymbolTable::setParamNum() {
    paramNum = FuncSymbolTableList::funcSymbolTableList.size();
    return paramNum;
}

bool FuncSymbolTable::setParamDataTypeList() {
    for (auto i = SymbolTable::paramSymbolList.begin(); i != SymbolTable::paramSymbolList.end(); ++i) {
        paramDataTypeList.push_back(tuple<SymbolType, MetaDataType, bool, size_t>(i->second->getSymbolType(), i->second->getMetaDataType(), i->second->getIsArray(), i->second->getSize()));
    }
    return true;
}

bool FuncSymbolTable::compareParamSymbolDataType(int index, SymbolType inSymbolType, MetaDataType inMetaDataType, bool inIsArray, size_t inSize) const {
    if (index < 0 || index >= paramNum) {
        ERROR_COMPARE_SIZE_UNMATCH("FuncSymbolTable", index, paramNum);
        return false;
    }
    return  get<0>(paramDataTypeList[index]) == inSymbolType &&
            get<1>(paramDataTypeList[index]) == inMetaDataType && 
            get<2>(paramDataTypeList[index]) == inIsArray &&
            (inIsArray ? get<3>(paramDataTypeList[index]) == inSize : true);
}

BlockSymbolTable::BlockSymbolTable() {}

BlockSymbolTable::BlockSymbolTable(SymbolTable *inParentSymbolTable) {
    SymbolTable::setParentSymbolTable(inParentSymbolTable);
}

BlockSymbolTable::~BlockSymbolTable() {}

SymbolTable *SymbolTableFactory::createSymbolTable(TableType inTableType) {
    switch (inTableType) {
        case TableType::GLOBAL:
            return SymbolTable::getGlobalSymbolTable();
        case TableType::FUNC:
            return new FuncSymbolTable();
        case TableType::BLOCK:
            return new BlockSymbolTable();
        default:
            return nullptr;
    }
}