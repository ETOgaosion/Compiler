#include <iostream>
#include <string>

#pragma once

#define ERROR_COUT(err) cout << "[ERROR] > "; \
    err

#define ERROR_WHEN(err_time) cout << "when " << err_time << " "

#define ERROR_WHEN_INSTANCE(class) ERROR_WHEN("instance class " << class)

#define ERROR_WHEN_INSERT(class) ERROR_WHEN("insert class " << class)

#define ERROR_WHEN_GET(class) ERROR_WHEN("get class " << class)

#define ERROR_WITH(val) cout << ", val is " << val << endl

#define ERROR_INSTANCE(class, symbolType) ERROR_COUT(cout << "When initializing " << class << ", " << static_cast<int>(symbolType) << " not match"<<endl)

#define ERROR_INSERT_DUPLICATED(class, name) ERROR_COUT(cout << "When inserting " << class << ", " << name << "has exist" << endl)

#define ERROR_INSERT_TYPE(class, symbolType) ERROR_COUT(cout << "When inserting " << class << ", " << static_cast<int>(symbolType) << " not match" << endl)

#define ERROR_GET(class, index) ERROR_COUT(cout << "When getting " << class << ", index error " << index << endl) 

#define ERROR_COMPARE_NO_SYMBOL(class, symbolName) ERROR_COUT(cout << "When comparing symbol in" << class << ", There is no Symbol " << symbolName << endl)

#define ERROR_COMPARE_UNINIIALIZED(class, symbolName) ERROR_COUT(cout << "When comparing symbol in" << class << ", Symbol uninitialized " << symbolName << endl)

#define ERROR_COMPARE_SIZE_UNMATCH(class, inSize, rawSize) ERROR_COUT(cout << "When comparing size in" << class << ", size unmatch: " << inSize << " compare with raw size: " << rawSize << endl)