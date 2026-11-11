
// Write a C++ function to calculate the minimum value of a vector.

#include<vector>
#include<iostream>

int get_vec_min(const std::vector<int>& nums){
    int ans{nums.at(0)};
    for (int i: nums){
        if (i < ans){
            ans = i;
        }
    }
    return ans;
}

int main(){ 
    std::vector<int> vec{1, 2, 3, 4};
    vec.push_back(5);
    vec.push_back(6);
    vec.pop_back();
    std::cout << get_vec_min(vec) << std::endl;
}