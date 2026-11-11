#include "template.h"
#include <iostream>

void printVec(const MyVector<int>& v) {
    for (size_t i{0}; i < v.size(); ++i) {
        std::cout << v.at(i) <<" ";
    }
    std::cout << '\n';
}

int main() {
    MyVector<int> v;
    printVec(v);
    return static_cast<int>(v.size());
}