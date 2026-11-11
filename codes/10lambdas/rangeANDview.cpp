#include <iostream>
#include <vector>
#include <algorithm> // 使用ranges时, 必须添加此头文件
#include <string>
#include <ranges>
#include <string_view>

int main() {
    std::vector<char> v {'a', 'b', 'c', 'd', 'e'};

    // use the range
    auto it = std::ranges::find(v, 'c');
    
    if (it != v.end()) { 
        std::cout << *it << '\n';
    }

    // traditional 
    auto it2 = std::find(v.begin(), v.end(), 'd');
    if (it2 != v.end()) { 
        std::cout << *it2 << '\n';
    }

    
    std::string text = "C++20,is,awesome";

    // 按逗号分割字符串
    auto words = text | std::views::split(',');

    for (const auto& word : words) {
        // word 也是一个视图，可以用 string_view 打印
        std::cout << std::string_view(word) << "\n";
    }
    return 0;

}