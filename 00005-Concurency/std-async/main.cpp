#include <algorithm>
#include <array>
#include <rapidcsv.h>
#include <print>
#include <tuple>
#include <variant>
#include <iostream>
#include <vector>
#include <ranges>


void printCSVDoc(rapidcsv::Document doc) {
        auto columnNames { doc.GetColumnNames() };
        std::vector<std::vector<std::string>> columnsVect;
        for (auto & name : columnNames) {
                columnsVect.push_back(doc.GetColumn<std::string>(name));
                std::print("{:15}", name);
        }
        std::println("");
        for (size_t i{}; i<columnsVect[0].size(); ++i) {
                for (auto &column : columnsVect) {
                        std::print("{:15}", column[i]);
                }
                std::println("");
        }
}

void printCSVHeader(rapidcsv::Document doc) {
        auto columnNames { doc.GetColumnNames() };
        std::vector<std::vector<std::string>> columnsVect;
        for (auto & name : columnNames) {
                columnsVect.push_back(doc.GetColumn<std::string>(name));
                std::print("{:15}", name);
        }
        std::println("");
        for (size_t i{}; i< (columnsVect[0].size() > 5 ? 5 : columnsVect[0].size()); ++i) {
                for (auto &column : columnsVect) {
                        std::print("{:15}", column[i]);
                }
                std::println("");
        }
}

auto main() -> int {
        // rapidcsv::Document doc("CSV.csv");
        // printCSVHeader(doc);
        // std::tuple tuple {1, 1, 1l, 1ll, 3.0f, 3.0};
        // std::array<std::variant<int, short, long, long long, float, double>, 6> variantVector {1, 1, 1l, 1ll, 3.0f, 3.0};

        // std::println("");
        std::vector vec {1, 2, 3, 4, 5, 6};
        auto v = vec | std::views::reverse | std::views::drop(3);
        std::cout << *v.begin() << '\n';
}
