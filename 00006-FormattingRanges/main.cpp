#include <format>
#include <vector>
#include <string>
#include <iostream>

auto main() -> int {
        std::vector<std::string> ahmed{"a", "h", "m", "e", "d"};
        std::vector<std::string> sabry{"s", "a", "b", "r", "y"};
        std::vector vectorOfVectors {ahmed, sabry};
        std::cout << std::format("{}", vectorOfVectors);
        return 0;
}
