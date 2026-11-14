#include <optional>
#include <iostream>

int main() {
    std::optional<int> a = 42;
    std::optional<int> b = std::nullopt;

    // if (a.has_value()) std::cout << a.value() << "\n";

    // if (b.has_value()) std::cout << b.value() << "\n" << "No Value";

    if (a.has_value()) std::cout << *a << "\n";

    if (b) std::cout << *b << "\n" << "No Value";

}