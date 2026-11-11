#include<iostream>
#include<set>
#include<iterator>

int main(){
    std::set<int> s{1, 2, 3, 4};

    // 以下两种写法等价
    for (auto it = s.begin(); it != s.end(); ++it){
        const auto& elem = *it;
        std::cout << elem << std::endl;
    }

    for (auto e : s){
        std::cout << e << std::endl;
    }

    auto it {s.end()};
    --it;
    auto& elem {*it};
    std::cout << elem << std::endl;

    return 0;
}