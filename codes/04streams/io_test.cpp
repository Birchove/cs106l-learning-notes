#include <iostream>
#include <string>
#include <fstream>

int main() {
    std::string str;
    int x;
    std::string otherstr;

    std::cin >> str >> x >> otherstr;
    std::cout << str << x << otherstr << std::endl;

    // 尝试输入: blah blah blah
    // 正常情况下, 每次 >> 都会调用一次 cin 
    // std::cin 转换失败时, 就会退出, 返回0代表转换失败(str -> int), 且失败后不再接受新的输入, 直接break了
    
    // stream 可以作为condition判断
    if (std::cin) {
        std::cout << "Success!" << std::endl;
    }

    // Reading until the end of the stream
    // 不要写: while (!input.eof())
    std::ifstream input("numbers.txt");
    int value;
    while (input >> value){
        std::cout << value << std::endl;
    }

    return 0;
}