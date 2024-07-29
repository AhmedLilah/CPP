#include <print>
#include <vector>
#include <variant>

auto main() -> int {
        std::vector<std::variant<int, float, double>> vv {.04f, 3, .0f, 234, .0};
        std::print("{}", std::get<1>(vv[0]));
        return 0 ;
}
