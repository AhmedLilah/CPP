#include <print>

auto function(auto ... inputArgs) {
    return typeid(inputArgs...[0]).name();
}

auto main() -> int {
    std::println("{}", function(5, 5.0, "char", 'c'));
    return 0;
}
