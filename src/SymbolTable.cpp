#include "SymbolTable.h"
#include "errorMsg.h"
#include <fstream>
#include <utility>

using namespace std;

template <class T> bool findDuplicateName(unordered_map<string,T*> list, string className, string name) {
    auto searchSymbol = list.find(name);
    if (searchSymbol != list.end()) {
        ERROR_INSERT_DUPLICATED(className, name);
        return true;
    }
    return false;
}

// -------- Symbols ---------

AbstractSymbol::AbstractSymbol() {
    symbolName = {};
    symbolType = SymbolType::PARAM;
    metaDataType = MetaDataType::VOID;
    isArray = false;
    size = 0;
    offset = 0;
}

AbstractSymbol::AbstractSymbol(string inSymbolName, SymbolType inSymbolType, MetaDataType inMetaDataType, bool inIsArray, size_t inSize){
    symbolName = std::move(inSymbolName);
    symbolType = inSymbolType;
    metaDataType = inMetaDataType;
    isArray = inIsArray;
    size = inSize;
    offset = 0;
}

string AbstractSymbol::getSymbolName() const {
    return symbolName;
}

SymbolType AbstractSymbol::getSymbolType() const {
    return symbolType;
}

MetaDataType AbstractSymbol::getMetaDataType() const {
    return metaDataType;
}

bool AbstractSymbol::getIsArray() const {
    return isArray;
}

size_t AbstractSymbol::getSize() const {
    return size;
}

int AbstractSymbol::getOffset() const {
    return offset;
}

uint64_t AbstractSymbol::getMemPosition() const {
    return memPosition;
}

bool AbstractSymbol::setAttributes(std::string inSymbolName, SymbolType inSymbolType, MetaDataType inMetaDataType, bool inIsArray, std::size_t inSize) {
    symbolName = std::move(inSymbolName);
    symbolType = inSymbolType;
    metaDataType = inMetaDataType;
    isArray = inIsArray;
    size = inSize;
}

bool AbstractSymbol::setOffset(int inOffset) {
    offset = inOffset;
    return true;
}

bool AbstractSymbol::setMemPosition(uint64_t inMemPosition) {
    memPosition = inMemPosition;
    return true;
}

int AbstractSymbol::getOffsetFromDataType(MetaDataType inDataType) {
    switch(inDataType){
        case MetaDataType::INT:
        case MetaDataType::BOOL:
        case MetaDataType::FLOAT:
            return 4;
        case MetaDataType::DOUBLE:
            return 8;
        default:
            return 0;
    }
}

// --------

ParamSymbol::ParamSymbol(const string& inSymbolName, MetaDataType inMetaDataType) {
    AbstractSymbol::setAttributes(inSymbolName, SymbolType::PARAM, inMetaDataType, false, 0);
}

// --------

VarSymbol::VarSymbol(const string& inSymbolName, MetaDataType inMetaDataType) {
    AbstractSymbol::setAttributes(inSymbolName, SymbolType::VAR, inMetaDataType, false, 0);
}

// --------

ConstSymbol::ConstSymbol(const string& inSymbolName, MetaDataType inMetaDataType) {
    AbstractSymbol::setAttributes(inSymbolName, SymbolType::CONST, inMetaDataType, false, 0);
}

// --------

ParamArraySymbol::ParamArraySymbol(const string& inSymbolName, MetaDataType inMetaDataType, size_t inSize) {
    AbstractSymbol::setAttributes(inSymbolName, SymbolType::PARAM, inMetaDataType, true, inSize);
}

// --------

VarArraySymbol::VarArraySymbol(const string& inSymbolName, MetaDataType inMetaDataType, size_t inSize) {
    AbstractSymbol::setAttributes(inSymbolName, SymbolType::VAR, inMetaDataType, true, inSize);
}

// --------

ConstArraySymbol::ConstArraySymbol(const string& inSymbolName, MetaDataType inMetaDataType, size_t inSize) {
    AbstractSymbol::setAttributes(inSymbolName, SymbolType::CONST, inMetaDataType, true, inSize);
}

AbstractSymbol *SymbolFactory::createSymbol(const string& inSymbolName, SymbolType inSymbolType, MetaDataType inMetaDataType, bool inIsArray, size_t inSize){
    switch(inSymbolType){
        case SymbolType::PARAM:
            if (inIsArray){
                return new ParamArraySymbol(inSymbolName, inMetaDataType, inSize);
            }
            return new ParamSymbol(inSymbolName, inMetaDataType);
        case SymbolType::VAR:
            if (inIsArray) {
                return new VarArraySymbol(inSymbolName, inMetaDataType, inSize);
            }
            return new VarSymbol(inSymbolName, inMetaDataType);
        case SymbolType::CONST:
            if (inIsArray) {
                return new ConstArraySymbol(inSymbolName, inMetaDataType, inSize);
            }
            return new ConstSymbol(inSymbolName, inMetaDataType);
        default:
            return nullptr;
    }
}

// --------- SymbolTables ----------

FuncSymbolTableList::FuncSymbolTableList() {
    funcSymbolTableList.clear();
}

SymbolTable *FuncSymbolTableList::insertFuncSymbolTableSafely(string inFuncName, MetaDataType inReturnType) {
    if (findDuplicateName<SymbolTable>(funcSymbolTableList, "FuncSymbolTableList", inFuncName)){
        return nullptr;
    }
    SymbolTable *insertSymbolTable = new FuncSymbolTable(inFuncName, inReturnType);
    funcSymbolTableList.emplace(inFuncName, insertSymbolTable);
    return insertSymbolTable;
}

SymbolTable *FuncSymbolTableList::insertFuncSymbolTableSafely(string inFuncName, MetaDataType inReturnType, SymbolTable *inParentSymbolTable) {
    if (findDuplicateName<SymbolTable>(funcSymbolTableList, "FuncSymbolTableList", inFuncName)){
        return nullptr;
    }
    SymbolTable *insertSymbolTable = new FuncSymbolTable(inFuncName, inReturnType, inParentSymbolTable);
    funcSymbolTableList.emplace(inFuncName, insertSymbolTable);
    return insertSymbolTable;
}

SymbolTable *FuncSymbolTableList::insertFuncSymbolTableSafely(SymbolTable *inFuncSymbolTable) {
    if (findDuplicateName<SymbolTable>(funcSymbolTableList, "FuncSymbolTableList", inFuncSymbolTable->getFuncName())) {
        return nullptr;
    }
    funcSymbolTableList.emplace(inFuncSymbolTable->getFuncName(),inFuncSymbolTable);
    return inFuncSymbolTable;
}

SymbolTable *FuncSymbolTableList::lookUpFuncSymbolTable(std::string inFuncName) const {
    auto searchFuncSymbolTable = funcSymbolTableList.find(inFuncName);
    if (searchFuncSymbolTable == funcSymbolTableList.end()) {
        return nullptr;
    }
    else{
        return searchFuncSymbolTable->second;
    }
}

// --------

BlockSymbolTableList::BlockSymbolTableList() {
    blockSymbolTableList.clear();
}

SymbolTable *BlockSymbolTableList::insertBlockSymbolTable() {
    SymbolTable *insertSymbolTable = new BlockSymbolTable();
    blockSymbolTableList.emplace_back(insertSymbolTable);
    return insertSymbolTable;
}

// SymbolTable *BlockSymbolTableList::insertBlockSymbolTable(SymbolTable *inParentSymbolTable) {
//     SymbolTable *insertSymbolTable = new BlockSymbolTable(inParentSymbolTable);
//     blockSymbolTableList.emplace_back(insertSymbolTable);
//     return insertSymbolTable;
// }

SymbolTable *BlockSymbolTableList::insertBlockSymbolTable(SymbolTable *inBlockSymbolTable) {
    blockSymbolTableList.emplace_back(inBlockSymbolTable);
    return inBlockSymbolTable;
}

SymbolTable *BlockSymbolTableList::getBlockSymbolTable(int index) const {
    if (index >= blockSymbolTableList.size()){
        ERROR_GET("BlockSymbolTableList", index);
        return nullptr;
    }
    return blockSymbolTableList[index];
}

// --------

SymbolTable::SymbolTable() {
    parentSymbolTable = nullptr;
    symbolTableType = TableType::GLOBAL;
}

SymbolTable::SymbolTable(TableType inTableType) {
    parentSymbolTable = nullptr;
    symbolTableType = inTableType;
    if (symbolTableType ==  TableType::GLOBAL) {
        getGlobalSymbolTable();
    }
}

SymbolTable::SymbolTable(SymbolTable *inParentSymbolTable) {
    parentSymbolTable = inParentSymbolTable;
    symbolTableType = TableType::GLOBAL;
}

SymbolTable::SymbolTable(TableType inTableType, SymbolTable *inParentSymbolTable) {
    symbolTableType = inTableType;
    parentSymbolTable = inParentSymbolTable;
    if (symbolTableType ==  TableType::GLOBAL) {
        getGlobalSymbolTable();
    }
}

AbstractSymbol *SymbolTable::insertAbstractSymbolSafely(string inSymbolName, SymbolType inSymbolType, MetaDataType inMetaDataType, bool inIsArray, size_t inSize) {
    if (lookUpAbstractSymbol(inSymbolName)){
        return nullptr;
    }
    SymbolFactory symbolFactory;
    AbstractSymbol *insertAbstractSymbol = symbolFactory.createSymbol(inSymbolName, inSymbolType, inMetaDataType, inIsArray, inSize);
    abstractSymbolList.emplace(inSymbolName, insertAbstractSymbol);
    return insertAbstractSymbol;
}

AbstractSymbol *SymbolTable::insertAbstractSymbolSafely(AbstractSymbol *inAbstractSymbol) {
    if (lookUpAbstractSymbol(inAbstractSymbol->getSymbolName())){
        return nullptr;
    }
    abstractSymbolList.emplace(inAbstractSymbol->getSymbolName(), inAbstractSymbol);
    return inAbstractSymbol;
}

AbstractSymbol *SymbolTable::lookUpAbstractSymbol(string inSymbolName) const {
    auto searchSymbol = abstractSymbolList.find(inSymbolName);
    if (searchSymbol != abstractSymbolList.end()) {
        return searchSymbol->second;
    }
    return nullptr;
}

AbstractSymbol *SymbolTable::lookUpAbstractSymbolGlobal(string inSymbolName) const {
    auto searchSymbol = abstractSymbolList.find(inSymbolName);
    if (searchSymbol != abstractSymbolList.end()) {
        return searchSymbol->second;
    }
    if (symbolTableType == TableType::FUNC) {
        AbstractSymbol *paramSymbolRes = lookUpParamSymbol(inSymbolName);
        if (paramSymbolRes) {
            return paramSymbolRes;
        }
        return parentSymbolTable->lookUpAbstractSymbolGlobal(inSymbolName);
    }
    else if (symbolTableType == TableType::BLOCK) {
        return parentSymbolTable->lookUpAbstractSymbolGlobal(inSymbolName);
    }
    return nullptr;
}

SymbolTable *SymbolTable::lookUpFuncSymbolTable(std::string inFuncName) const {
    if (symbolTableType == TableType::GLOBAL) {
        return FuncSymbolTableList::lookUpFuncSymbolTable(inFuncName);
    }
    else {
        return parentSymbolTable->lookUpFuncSymbolTable(inFuncName);
    }
}

TableType SymbolTable::getSymbolTableType() const {
    return symbolTableType;
}

SymbolTable *SymbolTable::getParentSymbolTable() const {
    return parentSymbolTable;
}

SymbolTable *SymbolTable::getGlobalSymbolTable() {
    static SymbolTable *globalSymbolTable = new GlobalSymbolTable();
    return globalSymbolTable;
}

bool SymbolTable::setSymbolTableType(TableType inSymbolTableType) {
    symbolTableType = inSymbolTableType;
    return true;
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
            (!inIsArray || curSymbol->getSize() == inSize);

}

// --------

GlobalSymbolTable::GlobalSymbolTable() {
    SymbolTable::setSymbolTableType(TableType::GLOBAL);
}

// --------

FuncSymbolTable::FuncSymbolTable() {
    SymbolTable::setSymbolTableType(TableType::FUNC);
}

FuncSymbolTable::FuncSymbolTable(string inFuncName, MetaDataType inReturnType) {
    funcName = std::move(inFuncName);
    returnType = inReturnType;
    SymbolTable::setSymbolTableType(TableType::FUNC);
}

FuncSymbolTable::FuncSymbolTable(string inFuncName, MetaDataType inReturnType, SymbolTable *inParentSymbolTable) {
    funcName = std::move(inFuncName);
    returnType = inReturnType;
    SymbolTable::setSymbolTableType(TableType::FUNC);
    SymbolTable::setParentSymbolTable(inParentSymbolTable);
}

AbstractSymbol *FuncSymbolTable::insertAbstractSymbolSafely(std::string inSymbolName, SymbolType inSymbolType, MetaDataType inMetaDataType, bool inIsArray, std::size_t inSize) {
    if (lookUpParamSymbol(inSymbolName)) {
        return nullptr;
    }
    else {
        return SymbolTable::insertAbstractSymbolSafely(inSymbolName, inSymbolType, inMetaDataType, inIsArray, inSize);
    }
}

AbstractSymbol *FuncSymbolTable::insertAbstractSymbolSafely(AbstractSymbol *inAbstractSymbol) {
    if (lookUpParamSymbol(inAbstractSymbol->getSymbolName())) {
        return nullptr;
    }
    else {
        return SymbolTable::insertAbstractSymbolSafely(inAbstractSymbol);
    }
}

AbstractSymbol *FuncSymbolTable::insertParamSymbolSafely(const std::string &inSymbolName, MetaDataType inMetaDataType, bool inIsArray, size_t inSize) {
    if (findDuplicateName<AbstractSymbol>(paramSymbolList, "FuncSymbolTable", inSymbolName) || lookUpFuncSymbolTable(inSymbolName)) {
        return nullptr;
    }
    SymbolFactory symbolFactory;
    AbstractSymbol *insertParamSymbol = symbolFactory.createSymbol(inSymbolName, SymbolType::PARAM, inMetaDataType, inIsArray, inSize);
    paramSymbolList.emplace(inSymbolName, insertParamSymbol);
    return insertParamSymbol;
}

AbstractSymbol *FuncSymbolTable::insertParamSymbolSafely(AbstractSymbol *inParamSymbol) {
    if (findDuplicateName<AbstractSymbol>(paramSymbolList, "FuncSymbolTable", inParamSymbol->getSymbolName()) || lookUpFuncSymbolTable(inParamSymbol->getSymbolName())) {
        return nullptr;
    }
    paramSymbolList.emplace(inParamSymbol->getSymbolName(), inParamSymbol);
    return inParamSymbol;
}

bool FuncSymbolTable::insertParamType(MetaDataType inMetaDataType, bool inIsArray, size_t inSize) {
    paramDataTypeList.emplace_back(inMetaDataType, inIsArray, inSize);
    return true;
}

bool FuncSymbolTable::insertParamType(AbstractSymbol *inParamSymbol) {
    return insertParamType(inParamSymbol->getMetaDataType(), inParamSymbol->getIsArray(), inParamSymbol->getSize());
}

AbstractSymbol *FuncSymbolTable::lookUpParamSymbol(const std::string &inSymbolName) const {
    auto it = paramSymbolList.find(inSymbolName);
    if (it != paramSymbolList.end()) {
        return it->second;
    }
    else {
        return nullptr;
    }
}

tuple <MetaDataType, bool, size_t> FuncSymbolTable::lookUpParamDataType(const std::string &inSymbolName) const {
    AbstractSymbol *searchSymbol = lookUpParamSymbol(inSymbolName);
    if (searchSymbol) {
        return make_tuple(searchSymbol->getMetaDataType(), searchSymbol->getIsArray(), searchSymbol->getSize());
    }
    else {
        return tuple <MetaDataType, bool, size_t> ();
    }
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

std::vector<std::tuple<MetaDataType, bool, std::size_t> > FuncSymbolTable::getParamDataTypeList() const {
    return paramDataTypeList;
}


bool FuncSymbolTable::setFuncName(const std::string &inFuncName) {
    funcName = inFuncName;
    return true;
}

bool FuncSymbolTable::setReturnType(MetaDataType inReturnType) {
    returnType = inReturnType;
    return true;
}

int FuncSymbolTable::setParamNum() {
    paramNum = paramSymbolList.size();
    return paramNum;
}

bool FuncSymbolTable::setParamDataTypeList() {
    for (auto i = paramSymbolList.begin(); i != paramSymbolList.end(); ++i) {
        paramDataTypeList.emplace_back(i->second->getMetaDataType(), i->second->getIsArray(), i->second->getSize());
    }
    return true;
}

bool FuncSymbolTable::compareParamSymbolDataType(int index, MetaDataType inMetaDataType, bool inIsArray, size_t inSize) const {
    if (index < 0 || index >= paramNum) {
        ERROR_COMPARE_SIZE_UNMATCH("FuncSymbolTable", index, paramNum);
        return false;
    }
    return  get<0>(paramDataTypeList[index]) == inMetaDataType &&
            get<1>(paramDataTypeList[index]) == inIsArray &&
            (!inIsArray || get<2>(paramDataTypeList[index]) == inSize);
}
BlockSymbolTable::BlockSymbolTable() {
    SymbolTable::setSymbolTableType(TableType::BLOCK);
}

BlockSymbolTable::BlockSymbolTable(SymbolTable *inParentSymbolTable) {
    SymbolTable::setSymbolTableType(TableType::BLOCK);
    SymbolTable::setParentSymbolTable(inParentSymbolTable);
}

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
