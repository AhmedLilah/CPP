#include <algorithm>
#include <ranges>
#include <string>
#include <print>
#include <vector>
#include <format>
#include <utility>

auto main() -> int {
        auto const output = 
                std::views::iota(0, 1000)
                | std::views::take(50) 
                | std::views::filter([](int const & x) { return x%2 == 0;})
                | std::views::transform( [](auto const x){ return x; })
                | std::views::reverse
                | std::views::chunk(2)
                | std::views::transform( [](auto rng) {
                        auto chunkIt = rng.begin();
                        return std::pair<int, int>(*chunkIt, *std::next(chunkIt));
                })
                | std::ranges::to<std::vector<std::pair<int, int>>>();

        std::println("Output pairs");
        std::ranges::for_each(output, [](auto x) {
                auto [a, b] {x};
                std::println("\t{:<5} : {:>5}", a, b);
        });
}
