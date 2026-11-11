// fraction.h
// 实现一个 有理数 类, 可以使用分数表示
// 类的核心是封装:
// 写头文件就可以体会到: 什么要提供给用户, 什么用户用不到/不允许用户操作, 分别作为private, public

#pragma once

#include <ostream>
class Fraction {
    public:
        Fraction();        // the default construction, defaulted as 1/1
        Fraction(int num, int denom); // the normal construction
        void add(Fraction& f);
        void multiply(Fraction& f);
        double decimal();
        int getNum();
        int getDenom();

        // friend func: 用到了私有variables, 同时用户又需要用到这个函数(即 public 用到 private )
        friend std::ostream& operator<< (std::ostream& out, Fraction& frac); 
        // this defines an operator overload to make it possible to use the << operator with cout for our class. 

    private:
        int num;   // the numerator. 分子
        int denom; // the denominator  分母

        // private functions. They are useful, but the client does not need them, so they are private.
        void reduce();   // 让分数保持最简形式
        int gcd(int u, int v);   // 上一个函数需要此函数

};