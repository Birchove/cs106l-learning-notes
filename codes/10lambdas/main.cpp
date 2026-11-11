# include "predicate.h"
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

bool isVowel(char c) {
    c = std::toupper(c);
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}


int main() {
    std::string flower = "rose";

    auto it = my_find_if(flower.begin(), flower.end(), isVowel);

    if (it != flower.end()) {
        std::cout << "Found vowel: " << *it << "\n";
    } else {
        std::cout << "No vowel found.\n";
    }


    std::vector<int> nums {1,2,3,4,5, 6};
    int n;
    std::cin >> n;
    auto lessThanN = [n] (int x) {return x < n;};
    auto it2 = my_find_if(nums.begin(), nums.end(), lessThanN);
    std::cout << *it2 << '\n';


    return 0;
}