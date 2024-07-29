#include <compare>
#include <print>
#include <concepts>

template <typename T> 
concept comparable = requires (T a, T b) {
        a < b;
        a == b;
};

template <comparable T>
auto comp(T a, T b) -> std::strong_ordering  {
        return a<=>b;
}

int main( ) {
        auto c = comp(5 , 4);
        std::print("the sum is {}", std::is_lt(c));
}
