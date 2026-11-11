#include<map>
#include<iostream>

int main(){
    std::map<int, char> preston{
        {16, 'p'}, {18, 'r'}, {5, 'e'},
        {19, 's'}, {20, 't'}, {15, 'o'}, {14, 'n'}
    };

    // 可以看到输出的结果已经被排序过了, 即 map 存储的是有序的键值对
    // 也是其快速访问的原因
    for (const auto& [key, value] : preston){
        std::cout << key << ' ' << value << std::endl;
    }

    // 这里不会报错, 访问一个key不存在时, 会自动插入, 此时插入的就是空char
    std::cout << "The map auto insert default value: " << preston[11] << std::endl;
}
// output
/*
5 e
14 n
15 o
16 p
18 r
19 s
20 t
*/