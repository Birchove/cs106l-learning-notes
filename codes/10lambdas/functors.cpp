#include <iostream>
struct my_functor {
    int operator () (int a) const {
        return a * value;
    }
    int value;
};

int main() {
    my_functor f;
    f.value = 5;
    std::cout << f(10) << '\n';
}

// ouput : 50 