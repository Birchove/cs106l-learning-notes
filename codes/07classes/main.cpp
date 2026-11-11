// File: main.cpp

#include "elevator.h"
#include<iostream>
#include "fraction.h"

int main() {
    // Elevator e {1};
    // e.request(1);
    // std::cout << "run" << std::endl;

    // 1. 测试默认构造函数 (预期输出: 1/1)
    Fraction f1;
    std::cout << "1. 默认构造函数 f1: " << f1 << " (预期: 1/1)\n";

    // 2. 测试普通构造函数及自动约分 (2/4 应自动化简为 1/2)
    Fraction f2(2, 4);
    std::cout << "2. 构造函数 f2(2, 4): " << f2 << " (预期: 1/2)\n";

    Fraction f3(6, 8);
    std::cout << "   构造函数 f3(6, 8): " << f3 << " (预期: 3/4)\n\n";

    // 3. 测试 Getter 函数与小数转换
    std::cout << "3. f2 的分子: " << f2.getNum() << ", 分母: " << f2.getDenom() << "\n";
    std::cout << "   f2 转为小数: " << f2.decimal() << " (预期: 0.5)\n\n";

    // 4. 测试加法 add (1/2 + 3/4 = 5/4)
    std::cout << "4. 执行加法: " << f2 << " + " << f3 << "\n";
    f2.add(f3);
    std::cout << "   计算后 f2 变为: " << f2 << " (预期: 5/4)\n\n";

    // 5. 测试乘法 multiply (2/3 * 3/4 = 1/2)
    Fraction f4(2, 3);
    Fraction f5(3, 4);
    std::cout << "5. 执行乘法: " << f4 << " * " << f5 << "\n";
    f4.multiply(f5);
    std::cout << "   计算后 f4 变为: " << f4 << " (预期: 1/2)\n";

    return 0;
}

// 单行编译: clang++ -std=c++23 main.cpp elevator.cpp -o m
// 逐个编译: 
/*
    1. 仅编译 main.cpp（使用 -c 参数），生成 main.o
    clang++ -std=c++23 -c main.cpp

    2. 仅编译 elevator.cpp，生成 elevator.o
    clang++ -std=c++23 -c elevator.cpp

    3. 将两个对象文件链接成最终的可执行文件 m
    clang++ main.o elevator.o -o m
*/