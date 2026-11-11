#include <iostream>
#include <sstream>

using namespace std;

int main(){
    int age; double hourlyWage;
    // cout << "Please enter your age: ";
    // cin >> age;
    // cout << age << endl;
    // // 尝试输入age为2.17
    // // Reads until it finds something that isn’t an int!
    // // 且一个cin失效后, 其后所有的cin都将不再接受输入

    // cout << "Please enter your hourly wage: ";
    // cin >> hourlyWage;

    // getline
    // string line;
    // std::getline(cin, line);
    // std::cout << line << endl;


    // istream
    std::istringstream input("10 20 30");
    int value;
    while (input >> value) {
        std::cout << value << std::endl;
    }
    return 0;


}