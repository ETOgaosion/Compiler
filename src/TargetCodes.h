//
// Created by 蓝色空间 on 2022/5/22.
//

#ifndef COMPILER_TARGETCODES_H
#define COMPILER_TARGETCODES_H

#include <iostream>
#include <string>
#include <vector>

class TargetCodes {
private:
    std::vector<std::string> codeList;

public:
    TargetCodes();
    bool clear() { codeList.clear(); };

    bool addCode(std::string newCode);
    bool addCodes(std::vector<std::string> newCodes);

    void printCode() const;
};


#endif //COMPILER_TARGETCODES_H
