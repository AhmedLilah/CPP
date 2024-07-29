#include <print>
#include <format>
#include <string>
#include <ranges>
#include <vector>

auto main()-> int {
        std::string s {"this is a test case for white spaces"}; 
        auto result = s | std::views::split('\\s');
        for (auto word : result) {
                std::print("{}", word);
        }
}
