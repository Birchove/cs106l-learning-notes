// this template func is so simple
// so dont split into .tpp & .h (or .cpp & .h)
#include<concepts>

#pragma once

// C++ 20 引入的新关键字, 可以规定某种规则
template <typename T, typename U>
concept Comparable = requires(const T& a, const U& b) {
    { a < b } -> std::convertible_to<bool>;
};


// 这样定义, 可以比较精度不同的type, 且自动适配高精度
template <typename T, typename U>
    requires Comparable<T, U>
auto my_min(const T& a, const U& b) {
    return a < b ? a : b;
}


template <class T, class U>
auto my_average(const T& a, const U& b) {
    // 注意这里分母必须写为: 2.0, 保证精度足够大, 这样使得两个整数的平均数也能正常取到浮点数
    return (a + b) / 2.0;
}