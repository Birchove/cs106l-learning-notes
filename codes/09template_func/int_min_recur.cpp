#include <vector>
#include <stdexcept>
#include <iostream>

template <typename T>
T recur_min(const std::vector<T>& nums, std::size_t i = 0) {
    if (nums.empty()) {
        throw std::invalid_argument("empty vector");
    }

    if (i == nums.size() - 1) {
        return nums[i];  // 递归终止条件
    }

    T m = recur_min(nums, i + 1);
    return nums[i] < m ? nums[i] : m;
}

int main() {
    std::vector nums {1, 2, 3, 4};
    std::cout << recur_min(nums) << std::endl;
}