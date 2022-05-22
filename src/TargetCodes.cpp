//
// Created by 蓝色空间 on 2022/5/22.
//

#include "TargetCodes.h"

using namespace std;

TargetCodes::TargetCodes() {
    codeList.clear();
}

bool TargetCodes::addCode(string newCode) {
    codeList.emplace_back(newCode);
    return true;
}

bool TargetCodes::addCodes(vector<string> newCodes) {
    for (string code : newCodes) {
        codeList.emplace_back(code);
    }
    return true;
}

void TargetCodes::printCode() const {
    for (string code : codeList) {
        cout<< code;
    }
}