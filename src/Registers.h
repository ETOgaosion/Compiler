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

public:
    Register(RegisterType inRegisterType, FloatPointType inFloatPointType, int inNumber, const std::string &inAliasName);
    
    RegisterType getRegisterType() const { return registerType; };
    FloatPointType getFloatPointType() const { return floatPointType; };
    int getNumber() const { return number; };
    std::string getAliasName() const { return abiAliasName; }
    long long getValue() const { return value; };
    bool getAllocated() const { return allocated; };

    void setFloatPointType(FloatPointType inFloatPointType) { floatPointType = inFloatPointType; };
    void setValue(long long newValue) { value = newValue; }
    void setAllocated() { allocated = true; }
    void setFree() { allocated = false; }
};

class Registers {
private:
    RegisterType registerType;

public:
    explicit Registers(bool isGeneralRegisterSet);

    virtual Register *getNextFreeRegister(bool isParam, FloatPointType inFloatPointType, bool &hasFreeRegister) { hasFreeRegister = false; return nullptr; };
    virtual Register *getNextOccupiedRegister(FloatPointType inFloatPointType, bool &hasOccupiedRegister) { hasOccupiedRegister = false; return nullptr; };

    virtual Register *tryGetCertainRegister(const std::string &regName, bool &isFreeRegister) { isFreeRegister = false; return nullptr; };

    virtual bool setRegisterFree(const std::string &) { return false; };

    virtual bool setRegistersFree(const std::vector<std::string> &) { return false; };
};

class GeneralPurposeRegisters : public Registers {
private:
    std::vector<std::string> registerClass;
    std::unordered_map<std::string, int> registerClassNum;
    std::unordered_map<std::string, int> registerAllocBitmap;
    std::unordered_map<std::string, Register *> generalPurposeRegisterList;

public:
    GeneralPurposeRegisters();

    Register *getNextFreeRegister(bool isParam, FloatPointType inFloatPointType, bool &hasFreeRegister) override;
    Register *getNextOccupiedRegister(FloatPointType inFloatPointType, bool &hasOccupiedRegister) override;

    Register *tryGetCertainRegister(const std::string &regName, bool &isFreeRegister) override;

    bool setRegisterFree(const std::string &) override;

    bool setRegistersFree(const std::vector<std::string> &) override;
};

class FloatPointRegisters : public Registers {
private:
    std::vector<std::string> registerClass;
    std::unordered_map<std::string, int> registerClassNum;
    std::unordered_map<std::string, int> registerAllocBitmap;
    std::unordered_map<std::string, Register *> floatPointRegisterList;

public:
    FloatPointRegisters();

    Register *getNextFreeRegister(bool isParam, FloatPointType inFloatPointType, bool &hasFreeRegister) override;
    Register *getNextOccupiedRegister(FloatPointType inFloatPointType, bool &hasOccupiedRegister) override;

    Register *tryGetCertainRegister(const std::string &regName, bool &isFreeRegister) override;

    bool setRegisterFree(const std::string &) override;

    bool setRegistersFree(const std::vector<std::string> &) override;
};


#endif //COMPILER_REGISTERS_H
