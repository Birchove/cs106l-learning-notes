#pragma once

#include <cstddef>

template <class T>
class MyVector {
public:
    std::size_t size() const;
    const T& at(size_t index) const;
    T& at(size_t index);

private:
    std::size_t local_size{0};
    T* elems{nullptr};
};

#include "template.tpp"