// rewrite some safer stl funcs

#include <cstddef>
#include <vector>
#include <optional>

std::optional<size_t> find_index(const std::vector<int>& v, int target) {
    for (size_t i {0}; i < v.size(); ++i) {
        if (v[i] == target) return i;
    }
    return std::nullopt;
}

std::optional<int> safe_back(const std::vector<int>& v) {
    if (v.empty()) return std::nullopt;
    return v.back();
}

