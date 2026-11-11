#include <iostream>
#include <sstream>
#include <string>

int main(){
    // << 写入流
    std::stringstream ss;
    ss << 3.14f << ' ' << "hello";

    float pi;
    std::string hi;
    // >> 输出流
    ss >> hi >> pi;

    // 向 cout流 中写入数据, 这样可以更加理解 << 操作符
    std::cout << pi << "\n" << hi << std::endl;
}