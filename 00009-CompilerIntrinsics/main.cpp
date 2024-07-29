#include <immintrin.h>
#include <stdint.h>
#include <vector>
#include <array>
#include <print>

auto function(int32_t * a, size_t size) -> std::vector<int32_t>;


auto main() -> int32_t {
        srand(time(nullptr));
        std::vector<int32_t> a;
        a.reserve(8*1000);
        for (size_t i {}; i < 8*1000; ++i) {
                a.push_back(rand());
        }
        auto vi {function(&a[0], a.size()) };
        std::print("size of reduced vector {}", vi.size());
        for (auto element : vi) {
                std::println("{}", element);
        }
        return 0;
}


auto function(int32_t * a, size_t size) -> std::vector<int32_t> {
    std::vector<int32_t> v(size/8);
    for (size_t i{}; i<size; i+=8) {
        __m256i vi = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(a + i));
        __m256i sum = _mm256_hadd_epi32(vi, vi);
        sum = _mm256_hadd_epi32(sum, sum);
        __m128i top = _mm256_extracti128_si256(sum, 1);
        __m128i total = _mm_add_epi32(_mm256_castsi256_si128(sum), top);
        v[i/8] = _mm_cvtsi128_si32(total);
    }
    return v;
}
