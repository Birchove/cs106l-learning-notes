#include <algorithm>
#include <string>
#include <iostream>
#include <utility>
#include <vector>

// in: only read the params and dont change it; use the const T&
class NameValidator {
public:
    explicit NameValidator(const std::string& name) {
        // 只检查 name，不保存它
    }
};

void print(const std::string& name) {
    std::cout << name << '\n';
}


// sink: get the params' ownship; use auto&& and move semantic
class Data {
private:
    std::vector<int> values_;

public:
    explicit Data(std::vector<int>&& values)
        : values_(std::move(values)) {}
};


// in-out: read and change it, probably dont own it. use T&
class DataProcessor {
public:
    explicit DataProcessor(std::vector<int>& values) {
        std::ranges::sort(values);
    }
};


// out: only provide the result, even dont read it
std::vector<int> createData() {
    return {1, 2, 3, 4, 5};
}


