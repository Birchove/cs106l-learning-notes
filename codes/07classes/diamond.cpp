#include<string>
#include<iostream>


// multiple inheritance, we usually use compose to replace it

// struct Person {
//     std::string name;
// };

// struct Student : Person {};

// struct Employee : Person {};

// struct TA : Student, Employee {};

// main 函数中, 需要这样写:
//     TA me;
    
//     me.Student::name = "Peak";
//     me.Employee::name = "Ak";

struct Person {
    std::string name;
};

struct Student : virtual Person{};
struct Employee : virtual Person {};

struct TA : Student, Employee {};



int main() {
    // 实例化和赋值操作必须在函数内部
    TA me;
    
    me.name = "Preston";
    
    std::cout << "my name is " << me.name << '\n';

    return 0;
}