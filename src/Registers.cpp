//
// Created by 蓝色空间 on 2022/6/2.
//

#include "Registers.h"

using namespace std;

Register::Register(RegisterType inRegisterType, int inNumber, const std::string &inAliasName) {
    registerType = inRegisterType;
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
    registerClass = {"v", "a", "ip", "sp", "lr", "pc"};
    registerClassNum = {{"v", 8}, {"a", 4}, {"ip", 1}, {"sp", 1}, {"lr", 1}, {"pc", 1}};
    registerAllocBitmap = {{"v", 0}, {"a", 0}, {"ip", 0}, {"sp", 0}, {"lr", 0}, {"pc", 0}};
    registerOccupiedBitmap = {{"v", 0}, {"a", 0}, {"ip", 0}, {"sp", 0}, {"lr", 0}, {"pc", 0}};
    generalPurposeRegisterList = {
            {"a1", new Register(RegisterType::GENERAL_PURPOSE, 1, "a1")},
            {"a2", new Register(RegisterType::GENERAL_PURPOSE, 2, "a2")},
            {"a3", new Register(RegisterType::GENERAL_PURPOSE, 3, "a3")},
            {"a4", new Register(RegisterType::GENERAL_PURPOSE, 4, "a4")},
            {"v1", new Register(RegisterType::GENERAL_PURPOSE, 5, "v1")},
            {"v2", new Register(RegisterType::GENERAL_PURPOSE, 6, "v2")},
            {"v3", new Register(RegisterType::GENERAL_PURPOSE, 7, "v3")},
            {"v4", new Register(RegisterType::GENERAL_PURPOSE, 8, "v4")},
            {"v5", new Register(RegisterType::GENERAL_PURPOSE, 9, "v5")},
            {"v6", new Register(RegisterType::GENERAL_PURPOSE, 10, "v6")},
            {"v7", new Register(RegisterType::GENERAL_PURPOSE, 11, "v7")},
            {"v8", new Register(RegisterType::GENERAL_PURPOSE, 12, "v8")},
            {"ip", new Register(RegisterType::GENERAL_PURPOSE, 13, "ip")},
            {"sp", new Register(RegisterType::GENERAL_PURPOSE, 14, "sp")},
            {"lr", new Register(RegisterType::GENERAL_PURPOSE, 15, "lr")},
            {"pc", new Register(RegisterType::GENERAL_PURPOSE, 16, "pc")}
    };
}

Register *GeneralPurposeRegisters::getNextFreeRegister(bool isParam, bool &hasFreeRegister) {
    int scanner = 0x1, scanTimes = 0;
    if (isParam) {
        while (scanTimes < registerClassNum["a"]) {
            if (registerAllocBitmap["a"] & scanner) {
                hasFreeRegister = false;
            }
            else {
                hasFreeRegister = true;
                registerAllocBitmap["a"] |= scanner;
                generalPurposeRegisterList["a" + to_string(scanTimes + 1)]->setAllocated();
                return generalPurposeRegisterList["a" + to_string(scanTimes + 1)];
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
                    generalPurposeRegisterList[reg + to_string(scanTimes + 1)]->setAllocated();
                    return generalPurposeRegisterList[reg + to_string(scanTimes + 1)];
                }
                scanTimes++;
                scanner = scanner << 1;
            }
            scanTimes = 0;
            scanner = 0x1;
        }
        return {};
    }
}

Register *GeneralPurposeRegisters::getNextAvailableRegister(bool isParam, bool &hasFreeRegister) {
    int scanner = 0x1, scanTimes = 0;
    if (isParam) {
        while (scanTimes < registerClassNum["a"]) {
            if (registerOccupiedBitmap["a"] & scanner) {
                hasFreeRegister = false;
            }
            else {
                hasFreeRegister = true;
                registerOccupiedBitmap["a"] |= scanner;
                generalPurposeRegisterList["a" + to_string(scanTimes + 1)]->setOccupied();
                return generalPurposeRegisterList["a" + to_string(scanTimes + 1)];
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
                    generalPurposeRegisterList[reg + to_string(scanTimes + 1)]->setOccupied();
                    return generalPurposeRegisterList[reg + to_string(scanTimes + 1)];
                }
                scanTimes++;
                scanner = scanner << 1;
            }
            scanTimes = 0;
            scanner = 0x1;
        }
        return {};
    }
}

Register *GeneralPurposeRegisters::tryGetCertainRegister(const string &regName, bool &isFreeRegister) {
    if (generalPurposeRegisterList[regName]->getAllocated()) {
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
    registerClass = {"s"};
    registerClassNum = {{"s", 32}};
    registerAllocBitmap = {{"s", 32}};
    registerOccupiedBitmap = {{"s", 32}};
    floatPointRegisterList = {
            {"s0", new Register(RegisterType::FLOAT_POINT, 0, "s0")},
            {"s1", new Register(RegisterType::FLOAT_POINT, 1, "s1")},
            {"s2", new Register(RegisterType::FLOAT_POINT, 2, "s2")},
            {"s3", new Register(RegisterType::FLOAT_POINT, 3, "s3")},
            {"s4", new Register(RegisterType::FLOAT_POINT, 4, "s4")},
            {"s5", new Register(RegisterType::FLOAT_POINT, 5, "s5")},
            {"s6", new Register(RegisterType::FLOAT_POINT, 6, "s6")},
            {"s7", new Register(RegisterType::FLOAT_POINT, 7, "s7")},
            {"s8", new Register(RegisterType::FLOAT_POINT, 8, "s8")},
            {"s9", new Register(RegisterType::FLOAT_POINT, 9, "s9")},
            {"s10", new Register(RegisterType::FLOAT_POINT, 10, "s10")},
            {"s11", new Register(RegisterType::FLOAT_POINT, 11, "s11")},
            {"s12", new Register(RegisterType::FLOAT_POINT, 12, "s12")},
            {"s13", new Register(RegisterType::FLOAT_POINT, 13, "s13")},
            {"s14", new Register(RegisterType::FLOAT_POINT, 14, "s14")},
            {"s15", new Register(RegisterType::FLOAT_POINT, 15, "s15")},
            {"s16", new Register(RegisterType::FLOAT_POINT, 16, "s16")},
            {"s17", new Register(RegisterType::FLOAT_POINT, 17, "s17")},
            {"s18", new Register(RegisterType::FLOAT_POINT, 18, "s18")},
            {"s19", new Register(RegisterType::FLOAT_POINT, 19, "s19")},
            {"s20", new Register(RegisterType::FLOAT_POINT, 20, "s20")},
            {"s21", new Register(RegisterType::FLOAT_POINT, 21, "s21")},
            {"s22", new Register(RegisterType::FLOAT_POINT, 22, "s22")},
            {"s23", new Register(RegisterType::FLOAT_POINT, 23, "s23")},
            {"s24", new Register(RegisterType::FLOAT_POINT, 24, "s24")},
            {"s25", new Register(RegisterType::FLOAT_POINT, 25, "s25")},
            {"s26", new Register(RegisterType::FLOAT_POINT, 26, "s26")},
            {"s27", new Register(RegisterType::FLOAT_POINT, 27, "s27")},
            {"s28", new Register(RegisterType::FLOAT_POINT, 28, "s28")},
            {"s29", new Register(RegisterType::FLOAT_POINT, 29, "s29")},
            {"s30", new Register(RegisterType::FLOAT_POINT, 30, "s30")},
            {"s31", new Register(RegisterType::FLOAT_POINT, 31, "s31")},
    };
}

Register *FloatPointRegisters::getNextFreeRegister(bool isParam, bool &hasFreeRegister) {
    int scanner = 0x1, scanTimes = 0;
    if (isParam) {
        while (scanTimes < registerClassNum["fa"]) {
            if (registerAllocBitmap["fa"] & scanner) {
                hasFreeRegister = false;
            }
            else {
                hasFreeRegister = true;
                registerAllocBitmap["fa"] |= scanner;
                floatPointRegisterList["fa" + to_string(scanTimes)]->setAllocated();
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
                    return floatPointRegisterList[reg + to_string(scanTimes)];
                }
                scanTimes++;
                scanner = scanner << 1;
            }
            scanTimes = 0;
            scanner = 0x1;
        }
        return {};
    }
}

Register *FloatPointRegisters::getNextAvailableRegister(bool isParam, bool &hasFreeRegister) {
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
                    return floatPointRegisterList[reg + to_string(scanTimes)];
                }
                scanTimes++;
                scanner = scanner << 1;
            }
            scanTimes = 0;
            scanner = 0x1;
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
