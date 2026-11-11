#include "my_min.h"
#include<iostream>
#include<string>

int main() {
    // 显式规定类型, 和隐式让编译器自己确定类型, 在这两个例子中是一致的
    std::cout << my_min(1, 2) << std::endl;
    std::cout << my_min<int>(3, 4) << std::endl;

    // 因为cpp默认类型没有string, 所以这里会按照char比较, 最终比较的是内存地址
    // 得到的比较结果是不确定的, 即不可靠的, 后面两种修改方式是正确的
    std::cout << my_min("Preston", "Emily") << std::endl;
    // 1. 规定模版中的T, U
    std::cout << my_min<std::string, std::string>("Preston", "Emily") << std::endl;
    // 2. 根据实参推导类型, 传入临时变量, 临时变量带有type信息
    std::cout << my_min(std::string {"Preston"}, std::string {"Emily"}) << std::endl;


    // cpp默认类型有long, 所以能够正确比较
    std::cout << my_min(106L, 107) << std::endl;

    std::cout << my_average(10, 11) << std::endl;
}