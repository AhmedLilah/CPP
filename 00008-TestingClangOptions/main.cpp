#include <iostream>
#include <vector>
#include <format>

template <>
struct std::formatter<std::vector<int>> {
    constexpr auto parse(std::format_parse_context& ctx) { return ctx.end(); }

    template <typename FormatContext>
    auto format(const std::vector<int>& v, FormatContext& ctx) {
        std::string s = "{";
        for (size_t i = 0; i < v.size(); ++i) {
            s += std::format("{}", v[i]);
            if (i != v.size() - 1) s += ", ";
        }
        s += "}";
        return std::format_to(ctx.out(), "{}", s);
    }
};

int main() {
    std::vector<int> v {1, 2, 3};
    std::cout << std::format("{}", v) << '\n';
    return 0;
}
