#include <vector>
#include <iostream>
#include <format>

auto main() -> int {
        std::vector<int> intVect {0, 1, 2, 3, 4};
        std::cout << std::format("{}", intVect);
        return 0;
}
