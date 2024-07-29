#include "include.hpp"

template <typename T>
void fn(T t) {
        std::println("{}", t);
}

template void fn(int);
