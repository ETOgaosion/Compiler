#include "SymbolTable.h"
#include "errorMsg.h"
#include <utility>

using namespace std;

template <class T> bool findDuplicateName(unordered_map<string,T*> list, const string& className, string name) {
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
    shape.clear();
    offset = 0;
}

AbstractSymbol::AbstractSymbol(string inSymbolName, SymbolType inSymbolType, MetaDataType inMetaDataType, bool inIsArray, vector<size_t> inShape){
    symbolName = move(inSymbolName);
    symbolType = inSymbolType;
    metaDataType = inMetaDataType;
    isArray = inIsArray;
    shape = move(inShape);
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

vector<size_t> AbstractSymbol::getShape() const {
    return shape;
}

int AbstractSymbol::getOffset() const {
    return offset;
}

uint64_t AbstractSymbol::getMemPosition() const {
    return memPosition;
}

bool AbstractSymbol::setAttributes(string inSymbolName, SymbolType inSymbolType, MetaDataType inMetaDataType, bool inIsArray, vector<size_t> inShape) {
    symbolName = move(inSymbolName);
    symbolType = inSymbolType;
    metaDataType = inMetaDataType;
    isArray = inIsArray;
    shape = move(inShape);
    return true;
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
    return 4;
}

// --------

ParamSymbol::ParamSymbol(const string& inSymbolName, MetaDataType inMetaDataType) {
    AbstractSymbol::setAttributes(inSymbolName, SymbolType::PARAM, inMetaDataType, false, {});
}

// --------

VarSymbol::VarSymbol(const string& inSymbolName, MetaDataType inMetaDataType) {
    AbstractSymbol::setAttributes(inSymbolName, SymbolType::VAR, inMetaDataType, false, {});
}

// --------

ConstSymbol::ConstSymbol(const string& inSymbolName, MetaDataType inMetaDataType) {
    AbstractSymbol::setAttributes(inSymbolName, SymbolType::CONST, inMetaDataType, false, {});
}

// --------

ParamArraySymbol::ParamArraySymbol(const string& inSymbolName, MetaDataType inMetaDataType, vector<size_t> inShape) {
    AbstractSymbol::setAttributes(inSymbolName, SymbolType::PARAM, inMetaDataType, true, move(inShape));
}

// --------

VarArraySymbol::VarArraySymbol(const string& inSymbolName, MetaDataType inMetaDataType, vector<size_t> inShape) {
    AbstractSymbol::setAttributes(inSymbolName, SymbolType::VAR, inMetaDataType, true, move(inShape));
}

// --------

ConstArraySymbol::ConstArraySymbol(const string& inSymbolName, MetaDataType inMetaDataType, vector<size_t> inShape) {
    AbstractSymbol::setAttributes(inSymbolName, SymbolType::CONST, inMetaDataType, true, move(inShape));
}

AbstractSymbol *SymbolFactory::createSymbol(const string& inSymbolName, SymbolType inSymbolType, MetaDataType inMetaDataType, bool inIsArray, vector<size_t> inShape){
    switch(inSymbolType){
        case SymbolType::PARAM:
            if (inIsArray){
                return new ParamArraySymbol(inSymbolName, inMetaDataType, move(inShape));
            }
            return new ParamSymbol(inSymbolName, inMetaDataType);
        case SymbolType::VAR:
            if (inIsArray) {
                return new VarArraySymbol(inSymbolName, inMetaDataType, move(inShape));
            }
            return new VarSymbol(inSymbolName, inMetaDataType);
        case SymbolType::CONST:
            if (inIsArray) {
                return new ConstArraySymbol(inSymbolName, inMetaDataType, move(inShape));
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

SymbolTable *FuncSymbolTableList::lookUpFuncSymbolTable(string inFuncName) const {
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

AbstractSymbol *SymbolTable::insertAbstractSymbolSafely(string inSymbolName, SymbolType inSymbolType, MetaDataType inMetaDataType, bool inIsArray, vector<size_t> inShape) {
    if (lookUpAbstractSymbol(inSymbolName)){
        return nullptr;
    }
    SymbolFactory symbolFactory;
    AbstractSymbol *insertAbstractSymbol = symbolFactory.createSymbol(inSymbolName, inSymbolType, inMetaDataType, inIsArray, move(inShape));
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

SymbolTable *SymbolTable::lookUpFuncSymbolTable(string inFuncName) const {
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

bool SymbolTable::compareAbstractSymbolDataType(string inSymbolName, SymbolType inSymbolType, MetaDataType inMetaDataType, bool inIsArray, vector<size_t> inShape) const {
    AbstractSymbol *curSymbol = lookUpAbstractSymbol(inSymbolName);
    if (!curSymbol) {
        ERROR_COMPARE_NO_SYMBOL("SymbolTable", inSymbolName);
        return false;
    }
    return  curSymbol->getSymbolType() == inSymbolType &&
            curSymbol->getMetaDataType() == inMetaDataType &&
            curSymbol->getIsArray() == inIsArray &&
            (!inIsArray || curSymbol->getShape() == inShape);

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
    funcName = move(inFuncName);
    returnType = inReturnType;
    SymbolTable::setSymbolTableType(TableType::FUNC);
}

FuncSymbolTable::FuncSymbolTable(string inFuncName, MetaDataType inReturnType, SymbolTable *inParentSymbolTable) {
    funcName = move(inFuncName);
    returnType = inReturnType;
    SymbolTable::setSymbolTableType(TableType::FUNC);
    SymbolTable::setParentSymbolTable(inParentSymbolTable);
}

AbstractSymbol *FuncSymbolTable::insertAbstractSymbolSafely(string inSymbolName, SymbolType inSymbolType, MetaDataType inMetaDataType, bool inIsArray, vector<size_t> inShape) {
    if (lookUpParamSymbol(inSymbolName)) {
        return nullptr;
    }
    else {
        return SymbolTable::insertAbstractSymbolSafely(inSymbolName, inSymbolType, inMetaDataType, inIsArray, move(inShape));
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

AbstractSymbol *FuncSymbolTable::insertParamSymbolSafely(const string &inSymbolName, MetaDataType inMetaDataType, bool inIsArray, vector<size_t> inShape) {
    if (findDuplicateName<AbstractSymbol>(paramSymbolList, "FuncSymbolTable", inSymbolName) || lookUpFuncSymbolTable(inSymbolName)) {
        return nullptr;
    }
    SymbolFactory symbolFactory;
    AbstractSymbol *insertParamSymbol = symbolFactory.createSymbol(inSymbolName, SymbolType::PARAM, inMetaDataType, inIsArray, move(inShape));
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

bool FuncSymbolTable::insertParamType(MetaDataType inMetaDataType, bool inIsArray, vector<size_t> inShape) {
    paramDataTypeList.emplace_back(inMetaDataType, inIsArray, move(inShape));
    return true;
}

bool FuncSymbolTable::insertParamType(AbstractSymbol *inParamSymbol) {
    return insertParamType(inParamSymbol->getMetaDataType(), inParamSymbol->getIsArray(), inParamSymbol->getShape());
}

AbstractSymbol *FuncSymbolTable::lookUpParamSymbol(const string &inSymbolName) const {
    auto it = paramSymbolList.find(inSymbolName);
    if (it != paramSymbolList.end()) {
        return it->second;
    }
    else {
        return nullptr;
    }
}

tuple <MetaDataType, bool, vector<size_t>> FuncSymbolTable::lookUpParamDataType(const string &inSymbolName) const {
    AbstractSymbol *searchSymbol = lookUpParamSymbol(inSymbolName);
    if (searchSymbol) {
        return make_tuple(searchSymbol->getMetaDataType(), searchSymbol->getIsArray(), searchSymbol->getShape());
    }
    else {
        return {};
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

vector<tuple<MetaDataType, bool, vector<size_t>> > FuncSymbolTable::getParamDataTypeList() const {
    return paramDataTypeList;
}

int FuncSymbolTable::getFrameSize() const {
    return frameSize;
}

bool FuncSymbolTable::setFuncName(const string &inFuncName) {
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
        paramDataTypeList.emplace_back(i->second->getMetaDataType(), i->second->getIsArray(), i->second->getShape());
    }
    return true;
}

bool FuncSymbolTable::setFrameSize(int inSize) {
    frameSize = inSize;
}

bool FuncSymbolTable::compareParamSymbolDataType(int index, MetaDataType inMetaDataType, bool inIsArray, vector<size_t> inShape) const {
    if (index < 0 || index >= paramNum) {
        ERROR_COMPARE_SIZE_UNMATCH("FuncSymbolTable", index, paramNum);
        return false;
    }
    if (inIsArray) {
        inShape.erase(inShape.begin());
    }
    return  get<0>(paramDataTypeList[index]) == inMetaDataType &&
            get<1>(paramDataTypeList[index]) == inIsArray &&
            (!inIsArray || get<2>(paramDataTypeList[index]) == move(inShape));
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
