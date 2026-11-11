#include <concepts>

template <typename T> 
concept Comparable = requires(T a, T b) {
    {a < b} -> std::convertible_to<bool>;
};

// 递归终止条件：只剩一个参数
template <Comparable T>
T recur_min(const T& v) {
    return v;
}

// 否则递归
template <Comparable T, Comparable... Args>
T recur_min(const T& v, const Args&... args) {
    auto m = recur_min(args...);
    return v < m ? v : m;
}

