#include <print>
#include <ranges>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>

auto main() -> int {
        namespace v = std::views;
        namespace r = std::ranges;
        using std::print;

        std::unordered_map<std::string, std::vector<int>> map {{"ID", {1, 2, 0, 4, 5, 6}}, {"IB", {1, 2, 1, 4, 5, 6}}, {"IS", {1, 2, 2, 4, 5, 6}}};
        auto keys = map | v::keys | v::reverse; 
        r::for_each(keys, [&](auto const & key){
                print("{}", (map[key] | v::drop(2))[0]);
        });
}
