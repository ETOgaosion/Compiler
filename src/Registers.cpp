//
// Created by 蓝色空间 on 2022/6/2.
//

#include "Registers.h"

using namespace std;

Register::Register(RegisterType inRegisterType, FloatPointType inFloatPointType, int inNumber, const std::string &inAliasName) {
    registerType = inRegisterType;
    floatPointType = inFloatPointType;
    number = inNumber;
    abiAliasName = inAliasName;
    value = 0;
    allocated = false;
    occupied = false;
    tmpStoreOffset = 0;
}

Registers::Registers(bool isGeneralRegisterSet) {
    if (isGeneralRegisterSet) {
        registerType = RegisterType::GENERAL_PURPOSE;
    }
    else {
        registerType = RegisterType::FLOAT_POINT;
    }
}

GeneralPurposeRegisters::GeneralPurposeRegisters() : Registers(true) {
    registerClass = {"t", "a", "s", "tp", "sp", "gp", "ra", "zero"};
    registerClassNum = {{"t", 7}, {"a", 8}, {"s", 12}, {"tp", 1}, {"gp", 1}, {"sp", 1}, {"ra", 1}, {"zero", 1}};
    registerAllocBitmap = {{"t", 0}, {"a", 0}, {"s", 0}, {"tp", 0}, {"gp", 0}, {"sp", 0}, {"ra", 0}, {"zero", 0}};
    registerOccupiedBitmap = {{"t", 0}, {"a", 0}, {"s", 0}, {"tp", 0}, {"gp", 0}, {"sp", 0}, {"ra", 0}, {"zero", 0}};
    generalPurposeRegisterList = {
            {"zero", new Register(RegisterType::GENERAL_PURPOSE, FloatPointType::NONE, 0, "zero")},
            {"ra", new Register(RegisterType::GENERAL_PURPOSE, FloatPointType::NONE, 1, "ra")},
            {"sp", new Register(RegisterType::GENERAL_PURPOSE, FloatPointType::NONE, 2, "sp")},
            {"gp", new Register(RegisterType::GENERAL_PURPOSE, FloatPointType::NONE, 3, "gp")},
            {"tp", new Register(RegisterType::GENERAL_PURPOSE, FloatPointType::NONE, 4, "tp")},
            {"t0", new Register(RegisterType::GENERAL_PURPOSE, FloatPointType::NONE, 5, "t0")},
            {"t1", new Register(RegisterType::GENERAL_PURPOSE, FloatPointType::NONE, 6, "t1")},
            {"t2", new Register(RegisterType::GENERAL_PURPOSE, FloatPointType::NONE, 7, "t2")},
            {"s0", new Register(RegisterType::GENERAL_PURPOSE, FloatPointType::NONE, 8, "s0")},
            {"s1", new Register(RegisterType::GENERAL_PURPOSE, FloatPointType::NONE, 9, "s1")},
            {"a0", new Register(RegisterType::GENERAL_PURPOSE, FloatPointType::NONE, 10, "a0")},
            {"a1", new Register(RegisterType::GENERAL_PURPOSE, FloatPointType::NONE, 11, "a1")},
            {"a2", new Register(RegisterType::GENERAL_PURPOSE, FloatPointType::NONE, 12, "a2")},
            {"a3", new Register(RegisterType::GENERAL_PURPOSE, FloatPointType::NONE, 13, "a3")},
            {"a4", new Register(RegisterType::GENERAL_PURPOSE, FloatPointType::NONE, 14, "a4")},
            {"a5", new Register(RegisterType::GENERAL_PURPOSE, FloatPointType::NONE, 15, "a5")},
            {"a6", new Register(RegisterType::GENERAL_PURPOSE, FloatPointType::NONE, 16, "a6")},
            {"a7", new Register(RegisterType::GENERAL_PURPOSE, FloatPointType::NONE, 17, "a7")},
            {"s2", new Register(RegisterType::GENERAL_PURPOSE, FloatPointType::NONE, 18, "s2")},
            {"s3", new Register(RegisterType::GENERAL_PURPOSE, FloatPointType::NONE, 19, "s3")},
            {"s4", new Register(RegisterType::GENERAL_PURPOSE, FloatPointType::NONE, 20, "s4")},
            {"s5", new Register(RegisterType::GENERAL_PURPOSE, FloatPointType::NONE, 21, "s5")},
            {"s6", new Register(RegisterType::GENERAL_PURPOSE, FloatPointType::NONE, 22, "s6")},
            {"s7", new Register(RegisterType::GENERAL_PURPOSE, FloatPointType::NONE, 23, "s7")},
            {"s8", new Register(RegisterType::GENERAL_PURPOSE, FloatPointType::NONE, 24, "s8")},
            {"s9", new Register(RegisterType::GENERAL_PURPOSE, FloatPointType::NONE, 25, "s9")},
            {"s10", new Register(RegisterType::GENERAL_PURPOSE, FloatPointType::NONE, 26, "s10")},
            {"s11", new Register(RegisterType::GENERAL_PURPOSE, FloatPointType::NONE, 27, "s11")},
            {"t3", new Register(RegisterType::GENERAL_PURPOSE, FloatPointType::NONE, 28, "t3")},
            {"t4", new Register(RegisterType::GENERAL_PURPOSE, FloatPointType::NONE, 29, "t4")},
            {"t5", new Register(RegisterType::GENERAL_PURPOSE, FloatPointType::NONE, 30, "t5")},
            {"t6", new Register(RegisterType::GENERAL_PURPOSE, FloatPointType::NONE, 31, "t6")},
    };
}

Register *GeneralPurposeRegisters::getNextFreeRegister(bool isParam, FloatPointType inFloatPointType, bool &hasFreeRegister) {
    int scanner = 0x1, scanTimes = 0;
    if (isParam) {
        while (scanTimes < registerClassNum["a"]) {
            if (registerAllocBitmap["a"] & scanner || registerOccupiedBitmap["a"] & scanner) {
                hasFreeRegister = false;
            }
            else {
                hasFreeRegister = true;
                registerAllocBitmap["a"] |= scanner;
                generalPurposeRegisterList["a" + to_string(scanTimes)]->setAllocated();
                return generalPurposeRegisterList["a" + to_string(scanTimes)];
            }
            scanTimes++;
            scanner = scanner << 1;
        }
        return {};
    }
    else {
        for (const auto& reg : registerClass) {
            while (scanTimes < registerClassNum[reg]) {
                if (registerAllocBitmap[reg] & scanner || registerAllocBitmap[reg] & scanner) {
                    hasFreeRegister = false;
                }
                else {
                    hasFreeRegister = true;
                    registerAllocBitmap[reg] |= scanner;
                    generalPurposeRegisterList[reg + to_string(scanTimes)]->setAllocated();
                    return generalPurposeRegisterList[reg + to_string(scanTimes)];
                }
                scanTimes++;
                scanner = scanner << 1;
            }
        }
        return {};
    }
}

Register *GeneralPurposeRegisters::getNextAvailableRegister(bool isParam, FloatPointType inFloatPointType, bool &hasFreeRegister) {
    int scanner = 0x1, scanTimes = 0;
    if (isParam) {
        while (scanTimes < registerClassNum["a"]) {
            if (registerOccupiedBitmap["a"] & scanner) {
                hasFreeRegister = false;
            }
            else {
                hasFreeRegister = true;
                registerOccupiedBitmap["a"] |= scanner;
                generalPurposeRegisterList["a" + to_string(scanTimes)]->setOccupied();
                return generalPurposeRegisterList["a" + to_string(scanTimes)];
            }
            scanTimes++;
            scanner = scanner << 1;
        }
        return {};
    }
    else {
        for (const auto& reg : registerClass) {
            while (scanTimes < registerClassNum[reg]) {
                if (registerOccupiedBitmap[reg] & scanner) {
                    hasFreeRegister = false;
                }
                else {
                    hasFreeRegister = true;
                    registerOccupiedBitmap[reg] |= scanner;
                    generalPurposeRegisterList[reg + to_string(scanTimes)]->setOccupied();
                    return generalPurposeRegisterList[reg + to_string(scanTimes)];
                }
                scanTimes++;
                scanner = scanner << 1;
            }
        }
        return {};
    }
}

Register *GeneralPurposeRegisters::tryGetCertainRegister(const string &regName, bool &isFreeRegister) {
    if (generalPurposeRegisterList[regName]->getAllocated() || generalPurposeRegisterList[regName]->getOccupied()) {
        isFreeRegister = false;
        return nullptr;
    }
    isFreeRegister = true;
    setRegisterAllocated(regName);
    return generalPurposeRegisterList[regName];
}

bool GeneralPurposeRegisters::setRegisterFree(const std::string &reg) {
    int charLen = 0;
    for(const auto ch : reg) {
        if (isalpha(ch)) {
            charLen++;
        }
        else {
            break;
        }
    }
    string regPrefix = reg.substr(0, charLen);
    if (charLen < reg.size()) {
        int regNum = stoi(reg.substr(charLen));
        registerAllocBitmap[regPrefix] &= ~(0x1 << regNum);
        generalPurposeRegisterList[regPrefix + to_string(regNum)]->setFree();
    }
    else {
        registerAllocBitmap[regPrefix] &= ~0x1;
        generalPurposeRegisterList[regPrefix]->setFree();
    }
    return true;
}

bool GeneralPurposeRegisters::setRegisterAvailable(const std::string &reg) {
    int charLen = 0;
    for(const auto ch : reg) {
        if (isalpha(ch)) {
            charLen++;
        }
        else {
            break;
        }
    }
    string regPrefix = reg.substr(0, charLen);
    if (charLen < reg.size()) {
        int regNum = stoi(reg.substr(charLen));
        registerOccupiedBitmap[regPrefix] &= ~(0x1 << regNum);
        generalPurposeRegisterList[regPrefix + to_string(regNum)]->setAvailable();
    }
    else {
        registerOccupiedBitmap[regPrefix] &= ~0x1;
        generalPurposeRegisterList[regPrefix]->setAvailable();
    }
    return true;
}

bool GeneralPurposeRegisters::setRegisterAllocated(const std::string &reg) {
    int charLen = 0;
    for(const auto ch : reg) {
        if (isalpha(ch)) {
            charLen++;
        }
        else {
            break;
        }
    }
    string regPrefix = reg.substr(0, charLen);
    if (charLen < reg.size()) {
        int regNum = stoi(reg.substr(charLen));
        registerAllocBitmap[regPrefix] |= (0x1 << regNum);
        generalPurposeRegisterList[regPrefix + to_string(regNum)]->setAllocated();
    }
    else {
        registerAllocBitmap[regPrefix] |= 0x1;
        generalPurposeRegisterList[regPrefix]->setAllocated();
    }
    return true;
}

bool GeneralPurposeRegisters::setRegisterOccupied(const std::string &reg) {
    int charLen = 0;
    for(const auto ch : reg) {
        if (isalpha(ch)) {
            charLen++;
        }
        else {
            break;
        }
    }
    string regPrefix = reg.substr(0, charLen);
    if (charLen < reg.size()) {
        int regNum = stoi(reg.substr(charLen));
        registerOccupiedBitmap[regPrefix] |= (0x1 << regNum);
        generalPurposeRegisterList[regPrefix + to_string(regNum)]->setOccupied();
    }
    else {
        registerOccupiedBitmap[regPrefix] |= 0x1;
        generalPurposeRegisterList[regPrefix]->setOccupied();
    }
    return true;
}

bool GeneralPurposeRegisters::setRegistersFree(const std::vector<std::string> &registers) {
    for (const auto &reg : registers) {
        setRegisterFree(reg);
    }
    return true;
}

bool GeneralPurposeRegisters::setRegistersAvailable(const std::vector<std::string> &registers) {
    for (const auto &reg : registers) {
        setRegisterAvailable(reg);
    }
    return true;
}

bool GeneralPurposeRegisters::setRegistersFree(const vector<Register *> &registers) {
    for (const auto &reg : registers) {
        setRegisterFree(reg->getAliasName());
    }
    return true;
}

bool GeneralPurposeRegisters::setRegistersAvailable(const vector<Register *> &registers) {
    for (const auto &reg : registers) {
        setRegisterAvailable(reg->getAliasName());
    }
    return true;
}

bool GeneralPurposeRegisters::setAllRegistersFree() {
    for (const auto& it : generalPurposeRegisterList) {
        setRegisterFree(it.first);
    }
    return true;
}

bool GeneralPurposeRegisters::setAllRegistersAvailable() {
    for (const auto& it : generalPurposeRegisterList) {
        setRegisterAvailable(it.first);
    }
    return true;
}

FloatPointRegisters::FloatPointRegisters() : Registers(false) {
    registerClass = {"ft", "fa", "fs"};
    registerClassNum = {{"ft", 12}, {"fa", 8}, {"fs", 12}};
    registerAllocBitmap = {{"ft", 0}, {"fa", 0}, {"fs", 0}};
    registerOccupiedBitmap = {{"ft", 0}, {"fa", 0}, {"fs", 0}};
    floatPointRegisterList = {
            {"ft0", new Register(RegisterType::FLOAT_POINT, FloatPointType::SINGLE, 0, "ft0")},
            {"ft1", new Register(RegisterType::FLOAT_POINT, FloatPointType::SINGLE, 1, "ft1")},
            {"ft2", new Register(RegisterType::FLOAT_POINT, FloatPointType::SINGLE, 2, "ft2")},
            {"ft3", new Register(RegisterType::FLOAT_POINT, FloatPointType::SINGLE, 3, "ft3")},
            {"ft4", new Register(RegisterType::FLOAT_POINT, FloatPointType::SINGLE, 4, "ft4")},
            {"ft5", new Register(RegisterType::FLOAT_POINT, FloatPointType::SINGLE, 5, "ft5")},
            {"ft6", new Register(RegisterType::FLOAT_POINT, FloatPointType::SINGLE, 6, "ft6")},
            {"ft7", new Register(RegisterType::FLOAT_POINT, FloatPointType::SINGLE, 7, "ft7")},
            {"fs0", new Register(RegisterType::FLOAT_POINT, FloatPointType::SINGLE, 8, "fs0")},
            {"fs1", new Register(RegisterType::FLOAT_POINT, FloatPointType::SINGLE, 9, "fs1")},
            {"fa0", new Register(RegisterType::FLOAT_POINT, FloatPointType::SINGLE, 10, "fa0")},
            {"fa1", new Register(RegisterType::FLOAT_POINT, FloatPointType::SINGLE, 11, "fa1")},
            {"fa2", new Register(RegisterType::FLOAT_POINT, FloatPointType::SINGLE, 12, "fa2")},
            {"fa3", new Register(RegisterType::FLOAT_POINT, FloatPointType::SINGLE, 13, "fa3")},
            {"fa4", new Register(RegisterType::FLOAT_POINT, FloatPointType::SINGLE, 14, "fa4")},
            {"fa5", new Register(RegisterType::FLOAT_POINT, FloatPointType::SINGLE, 15, "fa5")},
            {"fa6", new Register(RegisterType::FLOAT_POINT, FloatPointType::SINGLE, 16, "fa6")},
            {"fa7", new Register(RegisterType::FLOAT_POINT, FloatPointType::SINGLE, 17, "fa7")},
            {"fs2", new Register(RegisterType::FLOAT_POINT, FloatPointType::SINGLE, 18, "fs2")},
            {"fs3", new Register(RegisterType::FLOAT_POINT, FloatPointType::SINGLE, 19, "fs3")},
            {"fs4", new Register(RegisterType::FLOAT_POINT, FloatPointType::SINGLE, 20, "fs4")},
            {"fs5", new Register(RegisterType::FLOAT_POINT, FloatPointType::SINGLE, 21, "fs5")},
            {"fs6", new Register(RegisterType::FLOAT_POINT, FloatPointType::SINGLE, 22, "fs6")},
            {"fs7", new Register(RegisterType::FLOAT_POINT, FloatPointType::SINGLE, 23, "fs7")},
            {"fs8", new Register(RegisterType::FLOAT_POINT, FloatPointType::SINGLE, 24, "fs8")},
            {"fs9", new Register(RegisterType::FLOAT_POINT, FloatPointType::SINGLE, 25, "fs9")},
            {"fs10", new Register(RegisterType::FLOAT_POINT, FloatPointType::SINGLE, 26, "fs10")},
            {"fs11", new Register(RegisterType::FLOAT_POINT, FloatPointType::SINGLE, 27, "fs11")},
            {"ft8", new Register(RegisterType::FLOAT_POINT, FloatPointType::SINGLE, 28, "ft8")},
            {"ft9", new Register(RegisterType::FLOAT_POINT, FloatPointType::SINGLE, 29, "ft9")},
            {"ft10", new Register(RegisterType::FLOAT_POINT, FloatPointType::SINGLE, 30, "ft10")},
            {"ft11", new Register(RegisterType::FLOAT_POINT, FloatPointType::SINGLE, 31, "ft11")},
    };
}

Register *FloatPointRegisters::getNextFreeRegister(bool isParam, FloatPointType inFloatPointType, bool &hasFreeRegister) {
    int scanner = 0x1, scanTimes = 0;
    if (isParam) {
        while (scanTimes < registerClassNum["fa"]) {
            if (registerAllocBitmap["fa"] & scanner || registerOccupiedBitmap["fa"] & scanner) {
                hasFreeRegister = false;
            }
            else {
                hasFreeRegister = true;
                registerAllocBitmap["fa"] |= scanner;
                floatPointRegisterList["fa" + to_string(scanTimes)]->setAllocated();
                if (inFloatPointType == FloatPointType::DOUBLE) {
                    floatPointRegisterList["fa" + to_string(scanTimes)]->setFloatPointType(FloatPointType::DOUBLE);
                }
                return floatPointRegisterList["fa" + to_string(scanTimes)];
            }
            scanTimes++;
            scanner = scanner << 1;
        }
        return {};
    }
    else {
        for (const auto& reg : registerClass) {
            while (scanTimes < registerClassNum[reg]) {
                if (registerAllocBitmap[reg] & scanner || registerOccupiedBitmap[reg] & scanner) {
                    hasFreeRegister = false;
                }
                else {
                    hasFreeRegister = true;
                    registerAllocBitmap[reg] |= scanner;
                    floatPointRegisterList[reg + to_string(scanTimes)]->setAllocated();
                    if (inFloatPointType == FloatPointType::DOUBLE) {
                        floatPointRegisterList["fa" + to_string(scanTimes)]->setFloatPointType(FloatPointType::DOUBLE);
                    }
                    return floatPointRegisterList[reg + to_string(scanTimes)];
                }
                scanTimes++;
                scanner = scanner << 1;
            }
        }
        return {};
    }
}

Register *FloatPointRegisters::getNextAvailableRegister(bool isParam, FloatPointType inFloatPointType, bool &hasFreeRegister) {
    int scanner = 0x1, scanTimes = 0;
    if (isParam) {
        while (scanTimes < registerClassNum["fa"]) {
            if (registerOccupiedBitmap["fa"] & scanner) {
                hasFreeRegister = false;
            }
            else {
                hasFreeRegister = true;
                registerOccupiedBitmap["fa"] |= scanner;
                floatPointRegisterList["fa" + to_string(scanTimes)]->setOccupied();
                if (inFloatPointType == FloatPointType::DOUBLE) {
                    floatPointRegisterList["fa" + to_string(scanTimes)]->setFloatPointType(FloatPointType::DOUBLE);
                }
                return floatPointRegisterList["fa" + to_string(scanTimes)];
            }
            scanTimes++;
            scanner = scanner << 1;
        }
        return {};
    }
    else {
        for (const auto& reg : registerClass) {
            while (scanTimes < registerClassNum[reg]) {
                if (registerOccupiedBitmap[reg] & scanner) {
                    hasFreeRegister = false;
                }
                else {
                    hasFreeRegister = true;
                    registerAllocBitmap[reg] |= scanner;
                    floatPointRegisterList[reg + to_string(scanTimes)]->setOccupied();
                    if (inFloatPointType == FloatPointType::DOUBLE) {
                        floatPointRegisterList["fa" + to_string(scanTimes)]->setFloatPointType(FloatPointType::DOUBLE);
                    }
                    return floatPointRegisterList[reg + to_string(scanTimes)];
                }
                scanTimes++;
                scanner = scanner << 1;
            }
        }
        return {};
    }
}

bool FloatPointRegisters::setRegisterFree(const std::string &reg) {
    int charLen = 0;
    for(const auto ch : reg) {
        if (isalpha(ch)) {
            charLen++;
        }
        else {
            break;
        }
    }
    string regPrefix = reg.substr(0, charLen);
    int regNum = stoi(reg.substr(charLen));
    registerAllocBitmap[regPrefix] &= ~(0x1 << regNum);
    floatPointRegisterList[reg]->setFree();
    floatPointRegisterList[reg]->setFloatPointType(FloatPointType::SINGLE);
    return true;
}

bool FloatPointRegisters::setRegisterAvailable(const std::string &reg) {
    int charLen = 0;
    for(const auto ch : reg) {
        if (isalpha(ch)) {
            charLen++;
        }
        else {
            break;
        }
    }
    string regPrefix = reg.substr(0, charLen);
    int regNum = stoi(reg.substr(charLen));
    registerOccupiedBitmap[regPrefix] &= ~(0x1 << regNum);
    floatPointRegisterList[reg]->setAvailable();
    floatPointRegisterList[reg]->setFloatPointType(FloatPointType::SINGLE);
    return true;
}

bool FloatPointRegisters::setRegisterAllocated(const std::string &reg) {
    int charLen = 0;
    for(const auto ch : reg) {
        if (isalpha(ch)) {
            charLen++;
        }
        else {
            break;
        }
    }
    string regPrefix = reg.substr(0, charLen);
    int regNum = stoi(reg.substr(charLen));
    registerAllocBitmap[regPrefix] |= (0x1 << regNum);
    floatPointRegisterList[reg]->setAllocated();
    return true;
}

bool FloatPointRegisters::setRegisterOccupied(const std::string &reg) {
    int charLen = 0;
    for(const auto ch : reg) {
        if (isalpha(ch)) {
            charLen++;
        }
        else {
            break;
        }
    }
    string regPrefix = reg.substr(0, charLen);
    int regNum = stoi(reg.substr(charLen));
    registerOccupiedBitmap[regPrefix] |= (0x1 << regNum);
    floatPointRegisterList[reg]->setOccupied();
    return true;
}

bool FloatPointRegisters::setRegistersFree(const std::vector<std::string> &registers) {
    for (const auto &reg : registers) {
        setRegisterFree(reg);
    }
    return true;
}

bool FloatPointRegisters::setRegistersAvailable(const std::vector<std::string> &registers) {
    for (const auto &reg : registers) {
        setRegisterAvailable(reg);
    }
    return true;
}

Register *FloatPointRegisters::tryGetCertainRegister(const string &regName, bool &isFreeRegister) {
    if (floatPointRegisterList[regName]->getAllocated()) {
        isFreeRegister = false;
        return nullptr;
    }
    isFreeRegister = true;
    floatPointRegisterList[regName]->setAllocated();
    return floatPointRegisterList[regName];
}

bool FloatPointRegisters::setRegistersFree(const vector<Register *> &registers) {
    for (const auto &reg : registers) {
        setRegisterFree(reg->getAliasName());
    }
    return true;
}

bool FloatPointRegisters::setRegistersAvailable(const vector<Register *> &registers) {
    for (const auto &reg : registers) {
        setRegisterAvailable(reg->getAliasName());
    }
    return true;
}

bool FloatPointRegisters::setAllRegistersFree() {
    for (const auto& it : floatPointRegisterList) {
        setRegisterFree(it.first);
    }
    return true;
}

bool FloatPointRegisters::setAllRegistersAvailable() {
    for (const auto& it : floatPointRegisterList) {
        setRegisterAvailable(it.first);
    }
    return true;
}
