#include <print>
#include <format>
#include <vector>
#include <iostream>
#include <ranges>
#include <array>
#include <tuple>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <queue>
#include <deque>

auto main() -> int {
        for (int i : std::array{1, 2, 3, 4}) {
	        std::println("Number: {}", i);
        }
        
        return 0;
}
