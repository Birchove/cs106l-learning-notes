template <class T>
std::size_t MyVector<T>::size() const {
    return local_size;
}

// const overload, apply two version of the function 'at': Read Only / Writable

template <class T>              

/* the first 'const' keeps the pointer; the second make [const MyVector] could use 'at'    */
const T& MyVector<T>::at(size_t index) const {
    return elems[index];
}

template <class T>
T& MyVector<T>::at(size_t index) {
    return elems[index];
}