#include "hero.h"
#include <iostream>

bool Hero::operator<(const Hero& other) const {
    return power < other.power;
}

// .cpp 文件中, 不写 friend 关键字
std::ostream& operator << (std::ostream& out, const Hero& hero) {
    out << hero.name << " (power " << hero.power << ")";
    return out;
}

int rescueCount() {
    // this count will incredement when this func was called
    static int count = 0;
    return ++count;
}

// only can be seen in this file(hero.cpp)
static void secretLair() {
    std::cout << "this is a secret" << '\n';
}
