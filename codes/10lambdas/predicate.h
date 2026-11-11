
// generalize the function: find + condition

template <typename It, typename Pred>
It my_find_if (It first, It last, Pred pred) { // ATTENTION: 这里不能直接写成bool类型, bool是pred函数的返回值, 而非pred的类型
    for (auto it = first; it != last; ++it) {
        if (pred(*it)) return it;
    }
    return last;  // corner case
}

