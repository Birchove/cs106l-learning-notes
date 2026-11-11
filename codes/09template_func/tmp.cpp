// Template MetaProgramming, so tmp

#include <cstddef>
#include <iostream>
#include <ostream>

// This style is C++98, too old to use
template <int N>
struct Factorial {
    enum {value = N * Factorial<N - 1>::value};
};

template <>
struct Factorial<0> {
    enum {value = 1};
};


// tell the compiler must run at compile time
consteval std::size_t factorial_must(size_t n){
    if (n == 0) return 1;
    return n * factorial_must(n - 1);
}


// tell the compiler try to run at compile time
constexpr std::size_t factorial_try(size_t n){
    if (n == 0) return 1;
    return n * factorial_try(n - 1);
}



int main() {
    std::cout << Factorial<6>::value << std::endl;
    std::cout << factorial_must(7) << std::endl;
    std::cout << factorial_try(8) << std::endl;
}

