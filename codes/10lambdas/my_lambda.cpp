#include <iostream>
#include <string>

int main() {
    // auto my_add(auto a, auto b) { return a + b;}    cpp不允许函数的嵌套, 所以在函数内部如果想要使用小工具函数, 必须使用lambda表达式

    auto add = [](auto a, auto b) {
        return a + b;
    };

    std::cout << add(5, 10) << "\n";                          // 输出: 15 (处理 int)
    std::cout << add(3.14, 2.0) << "\n";                      // 输出: 5.14 (处理 double)
    std::cout << add(std::string("Hello "), "World") << "\n"; // 输出: Hello World (处理 string)
    
    return 0;
}