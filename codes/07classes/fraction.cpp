#include "fraction.h"
#include <ostream>


// 我们需要告知编译器, 此函数术语哪个class, 所以用到了作用域解析符 :: ; 
// 不过此处构造函数和类同名而已, 所以显得有些奇怪;
Fraction::Fraction() {
    // 没有同名局部变量, 所以隐式转换为了class中的 num , 也即 this->num 
    num = 1;
    denom = 1;
}

// normal construction
Fraction::Fraction(int num, int denom) {

    // this -> num {num}; 是错误的写法, 原因在于, 此处进入构造函数前, num, denom 已经完成了初始化, 这里只是普通的赋值操作
    this -> num = num;
    this -> denom = denom;
    reduce();

}

/*

// 更推荐的现代化写法: 构造函数初始化列表, 此处就可以用统一初始化
Fraction::Fraction() : num{1}, denom{1}{}

// 这里不需要this, 因为两个同名变量可以区分, 或者说, instance此时还未初始化num, denom, 所以就是直接将外部的这两个变量传入进行初始化了
Fraction::Fraction(int num, int denom) : num{num}, denom{denom}{
    reduce();
}

*/

int Fraction::getDenom() {
    return denom;
}

int Fraction::getNum() {
    return num;
}

void Fraction::add(Fraction& other) {
    int denom_gcd = gcd(denom, other.denom);
    int k1 {denom / denom_gcd};
    int k2 {other.denom / denom_gcd};
    denom = denom * k2;
    num = num * k2 + other.num * k1;
    reduce();
}

void Fraction::multiply(Fraction& other) {
    num *= other.num;
    denom *= other.denom;
    reduce();
}

void Fraction::reduce() {
    // 作用于同一个instance的函数可以直接调用
    int frac_gcd {gcd(num, denom)};
    num = num / frac_gcd;
    denom = denom / frac_gcd;
}

int Fraction::gcd(int u, int v) {
    if (v != 0){
        return gcd(v, u % v);
    } else {
        return u;
    }
}

double Fraction::decimal() {
    return static_cast<double>(num) / denom;   // must cast at least one value
}

// 重载流输出运算符, 使得分数可以正常展示
std::ostream& operator<<(std::ostream& out, Fraction& frac) {
    out << frac.num << "/" << frac.denom;
    return out;
}