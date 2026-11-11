#include <iostream>
#include <string>

int main() {
    auto str = std::make_unique<std::string>("Hello World!");
    std::cout << *str << std::endl;
    return 0;
}