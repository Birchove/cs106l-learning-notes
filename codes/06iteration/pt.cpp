#include <iostream>
#include <vector>

int main(){
    std::vector<int> v = {1, 2, 3, 4, 5};

    // pointer 和 iterator 拥有相同的 interface

    // 使用pointer
    int* arr = &v[0];
    arr += 1;
    ++arr;
    if (arr == &v[4]){

    }

    // 使用iterator
    auto it {v.begin()};
    it += 1;
    ++it;
    if (it == --v.end()){

    }
}