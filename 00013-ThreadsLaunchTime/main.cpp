#include <stdint.h>
#include <array>
#include <chrono>
#include <future>
#include <print>

const uint64_t fibonacci(uint64_t n) {
        return n < 1 ? 0
                : n <=2 ? 1
                : fibonacci(n-1) + fibonacci(n -2);
}
auto main() -> int {
        std::array<std::future<uint64_t>, 4> resultsFutures;
        std::array<uint64_t, 4> results;

        auto start { std::chrono::high_resolution_clock::now() };

        for (auto & resultFuture : resultsFutures) {
                resultFuture= std::async(fibonacci, 40);
        }

        for (int i{}; i<4; ++i) {
                results[i] = resultsFutures[i].get();
        }
        auto end { std::chrono::high_resolution_clock::now() };

        std::println("time taken for all the threads: {}ms\n[{}, {}, {}, {}]", (end - start).count() * 1e-6, results[0], results[1], results[2], results[3]);

        return 0;
}
