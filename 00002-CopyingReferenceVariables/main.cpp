#include <print>

struct type {
        type() {
                std::println("A new was made");
        } 
        type( type & self) {
                std::println("A copy was made");
        }
};

void fn(type a) {
        std::println("the type was consumed.");
}
void fn(short i) {
        ++i;
}
auto main() -> int {
        type a;
        type & aRef = a;
        std::println("");
        fn(a);
        fn(aRef);
        short i {8};
        std::println("i: {}", i);
        short & iRef {i};
        std::println("iRef: {}", iRef);
        fn(iRef);
        std::println("i new after fn: {}", i);
        std::println("iRef new after fn: {}", iRef);
        ++iRef;
        std::println("i new after ++: {}", i);
        std::println("iRef new after ++: {}", iRef);
        std::println("size of i: {}", sizeof i);
        std::println("size of iRef: {}", sizeof i);
        return 0;
}
