#include <vector>
#include <print>
#include <iostream>

auto main() -> int {
        std::vector<int> vect {1, 2, 3, 4, 5, 6};

        for (size_t i=0; i<7; ++i) {
                std::println("UNSAFE : the value at index {} is {}", i, vect[i]);
        }

        try {
                for (size_t i=0; i<7; ++i) {
                        std::println("SAFE : the value at index {} is {}", i, vect.at(i));
                }
        } catch (std::exception & e) {
                std::print(std::cerr, "[ERROR] : {}", e.what());
        }
}
