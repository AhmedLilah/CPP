#include <print>

auto main() -> int {
        int a{69}, &aRef=a, *aPtr=&a;
        int b{100};
        int &bRef=b;
        int *bPtr=&b;
        std::println("original value {:>6}, reference {:>6}, derefrenced pointer to varilabe {:>6}", a, aRef, *aPtr);
        std::println("original value {:>6}, reference {:>6}, derefrenced pointer to varilabe {:>6}", b, bRef, *bPtr);
        return 0;
}
