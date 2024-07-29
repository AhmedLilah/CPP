#include <print>

struct MyStruct {
        int x;
        int y;
        int z;
};

auto function(MyStruct ms) {
        std::print("{{x={}, y={}, z={}}}", ms.x, ms.y, ms.z);
}

auto main() -> int {
        function({.z=5});
}
