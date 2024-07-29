#include <print>
#include <chrono>

auto main() -> int {
        auto tic {std::chrono::high_resolution_clock::now()};
        std::string buf{};
        for (size_t i =0; i<100'000; ++i) {
                buf += std::format("{}\n", i);
        }
        std::print("{}", buf);
        auto toc {std::chrono::high_resolution_clock::now()};
        std::println("{}", std::chrono::duration_cast<std::chrono::milliseconds>(toc-tic));
}
