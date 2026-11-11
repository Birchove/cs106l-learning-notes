#pragma once
#include <iostream>
 
template <typename T>
concept Printable = requires(T value) {
    std::cout << value;
};
 
template <Printable T, Printable... Args>
void commaSeparate(const T& first, const Args&... args) {
    std::cout << first;
    ((std::cout << ", " << args), ...);
    std::cout << std::endl;
}

// 其等价写法:
/* 
template <Printable T>
void commaSeparate(const T& one) {
    std::cout << one << std::endl;
}

template <Printable T, Printable... Args>
void commaSeparate(const T& first, const Args&... args) {
    std::cout << first << ", ";
    commaSeparate(args...);
    std::cout << std::endl;
}
    */