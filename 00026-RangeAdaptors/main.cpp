#include <print>
#include <ranges>
#include <vector>
#include <fstream>
#include <string>
#include <tuple>
#include <algorithm>

auto parseNetlist() {

        std::ifstream inputFile("netlist 1.sp");
        std::string inputString(std::istreambuf_iterator<char>(inputFile), {});
        
        return inputString
                | std::views::split(std::string_view("\n"))
                | std::views::transform([](auto const rng){return rng | std::ranges::to<std::string>();})
                | std::views::filter([](auto const & str){return not str.empty();})
                | std::views::filter([](auto const & str){return str.find("r") == 0;})
                | std::views::transform([](auto const & str){return str | std::views::split(std::string_view(" ")) | std::ranges::to<std::vector<std::string>>();})
                | std::views::transform([](auto const & strVect){return std::tuple(strVect[0], strVect[1], strVect[2], std::stof(strVect[3]));})
                | std::ranges::to<std::vector>();
}

auto main(int argc, char **argv) -> int { 

        auto const & resistorsElementsTuples{parseNetlist()}; 
        float minValue(1e+18), maxValue(1e-18);
        std::string minName, maxName;
        for(auto const & [indx, tuple] : resistorsElementsTuples | std::views::enumerate) {
                auto [name, terminal1, terminal2, value] {tuple};
                minValue = std::min(minValue, value);
                maxValue = std::max(maxValue, value);
        }

        std::println("min-resistor:\n"
                     "\tname  : {}\n"
                     "\tvalue     : {}\n"
                     , minName, minValue);

        std::println("max-resistor:\n"
                     "\tname  : {}\n"
                     "\tvalue     : {}\n"
                     , maxName, maxValue);

        std::string stringVar {"Hellow"};

        return 0;
}
