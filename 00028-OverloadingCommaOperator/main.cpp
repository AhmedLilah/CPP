#include <print>
#include <format>
#include <fstream>
#include <ranges>
#include <chrono>

auto main() -> int {
        std::ofstream of{"output_file.txt"};

        auto tic {std::chrono::high_resolution_clock::now()};
        auto string = std::views::repeat(std::string("Hello, world!"))
                | std::views::take(100'000'000)
                | std::views::join
                | std::ranges::to<std::string>();
        auto toc {std::chrono::high_resolution_clock::now()};
        std::println("Generation time: {}", std::chrono::duration_cast<std::chrono::milliseconds>(toc-tic));

        tic = std::chrono::high_resolution_clock::now();
        std::println(of, "{}", string);
        toc = std::chrono::high_resolution_clock::now();
        std::println("Writing time: {}", std::chrono::duration_cast<std::chrono::milliseconds>(toc-tic));

        // auto vect = std::views::iota(0)
        //         | std::views::take(10)
        //         | std::ranges::to<std::vector>();

        // std::println("{}", vect);

        return 0;
}
