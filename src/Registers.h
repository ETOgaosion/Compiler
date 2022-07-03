//
// Created by 蓝色空间 on 2022/6/2.
//

#ifndef COMPILER_REGISTERS_H
#define COMPILER_REGISTERS_H

#include <string>
#include <vector>
#include <unordered_map>

enum class RegisterType {
    GENERAL_PURPOSE,
    FLOAT_POINT
};

enum class FloatPointType {
    NONE,
    SINGLE,
    DOUBLE
};

class Register {
private:
    RegisterType registerType;
    FloatPointType floatPointType;
    int number;
    std::string abiAliasName;
    long long value;
    bool allocated;
    bool occupied;
    bool tmpStored;
    int tmpStoreOffset;

public:
    Register(RegisterType inRegisterType, FloatPointType inFloatPointType, int inNumber, const std::string &inAliasName);
    
    RegisterType getRegisterType() const { return registerType; };
    FloatPointType getFloatPointType() const { return floatPointType; };
    int getNumber() const { return number; };
    std::string getAliasName() const { return abiAliasName; }
    long long getValue() const { return value; };
    bool getAllocated() const { return allocated; };
    bool getOccupied() const { return occupied; };
    bool getTmpStored() const { return tmpStored; };
    int getTmpStoreOffset() const { return tmpStoreOffset; };

    void setFloatPointType(FloatPointType inFloatPointType) { floatPointType = inFloatPointType; };
    void setValue(long long newValue) { value = newValue; }
    void setAllocated() { allocated = true; }
    void setOccupied() { occupied = true; }
    void setFree() { allocated = false; }
    void setAvailable() { occupied = false; }
    void setTmpStored(bool inTmpStored) { tmpStored = inTmpStored; };
    void setTmpStoreOffset(int inTmpStoreOffset) { tmpStoreOffset = inTmpStoreOffset; };
};

class Registers {
private:
    RegisterType registerType;

public:
    explicit Registers(bool isGeneralRegisterSet);

    virtual Register *getNextFreeRegister(bool isParam, FloatPointType inFloatPointType, bool &hasFreeRegister) = 0;
    virtual Register *getNextAvailableRegister(bool isParam, FloatPointType inFloatPointType, bool &hasFreeRegister) = 0;

    virtual Register *tryGetCertainRegister(const std::string &regName, bool &isFreeRegister) = 0;

    virtual bool setRegisterFree(const std::string &) = 0;
    virtual bool setRegisterAvailable(const std::string &) = 0;
    virtual bool setRegisterAllocated (const std::string &) = 0;
    virtual bool setRegisterOccupied (const std::string &) = 0;

    virtual bool setRegistersFree(const std::vector<std::string> &) = 0;
    virtual bool setRegistersFree(const std::vector<Register *> &) = 0;
    virtual bool setRegistersAvailable(const std::vector<std::string> &) = 0;
    virtual bool setRegistersAvailable(const std::vector<Register *> &) = 0;

    virtual bool setAllRegistersFree() = 0;
    virtual bool setAllRegistersAvailable() = 0;
};

class GeneralPurposeRegisters : public Registers {
private:
    std::vector<std::string> registerClass;
    std::unordered_map<std::string, int> registerClassNum;
    std::unordered_map<std::string, int> registerAllocBitmap;
    std::unordered_map<std::string, int> registerOccupiedBitmap;
    std::unordered_map<std::string, Register *> generalPurposeRegisterList;

public:
    GeneralPurposeRegisters();

    Register *getNextFreeRegister(bool isParam, FloatPointType inFloatPointType, bool &hasFreeRegister) override;
    Register *getNextAvailableRegister(bool isParam, FloatPointType inFloatPointType, bool &hasFreeRegister) override;

    Register *tryGetCertainRegister(const std::string &regName, bool &isFreeRegister) override;

    bool setRegisterFree(const std::string &) override;
    bool setRegisterAvailable(const std::string &) override;
    bool setRegisterAllocated(const std::string &) override;
    bool setRegisterOccupied(const std::string &) override;

    bool setRegistersFree(const std::vector<std::string> &) override;
    bool setRegistersFree(const std::vector<Register *> &) override;
    bool setRegistersAvailable(const std::vector<std::string> &) override;
    bool setRegistersAvailable(const std::vector<Register *> &) override;

    bool setAllRegistersFree() override;
    bool setAllRegistersAvailable() override;
};

class FloatPointRegisters : public Registers {
private:
    std::vector<std::string> registerClass;
    std::unordered_map<std::string, int> registerClassNum;
    std::unordered_map<std::string, int> registerAllocBitmap;
    std::unordered_map<std::string, int> registerOccupiedBitmap;
    std::unordered_map<std::string, Register *> floatPointRegisterList;

public:
    FloatPointRegisters();

    Register *getNextFreeRegister(bool isParam, FloatPointType inFloatPointType, bool &hasFreeRegister) override;
    Register *getNextAvailableRegister(bool isParam, FloatPointType inFloatPointType, bool &hasFreeRegister) override;

    Register *tryGetCertainRegister(const std::string &regName, bool &isFreeRegister) override;

    bool setRegisterFree(const std::string &) override;
    bool setRegisterAvailable(const std::string &) override;
    bool setRegisterAllocated(const std::string &) override;
    bool setRegisterOccupied(const std::string &) override;

    bool setRegistersFree(const std::vector<std::string> &) override;
    bool setRegistersFree(const std::vector<Register *> &) override;
    bool setRegistersAvailable(const std::vector<std::string> &) override;
    bool setRegistersAvailable(const std::vector<Register *> &) override;

    bool setAllRegistersFree() override;
    bool setAllRegistersAvailable() override;
};


#endif //COMPILER_REGISTERS_H
