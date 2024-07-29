#include <print>
#include <array>
 
auto main() -> int {
        int cArray[5] {1, 2, 3, 4, 5};
        std::array<int, 5> stdArray{1, 2, 3, 4, 5};
        std::println("{} : {}", sizeof cArray / sizeof (int), sizeof stdArray / sizeof (int));

        using X = std::array<int, 3>; 
        using Y = std::array<X, 3>; 
        std::array<Y, 3> mDArray  {Y{X{1, 2, 3}, X{1, 2, 3}, X{1, 2, 3}}, Y{X{1, 2, 3}, X{1, 2, 3}, X{1, 2, 3}}, Y{X{1, 2, 3}, X{1, 2, 3}, X{1, 2, 3}}};
        std::array<Y, 3> iDArray  {{{1, 2, 3}, {1, 2, 3}, {1, 2, 3}}};

        for (auto top: mDArray) {
                for (auto middle: top) {
                        std::print("\t");
                        for (auto i : middle) {
                                std::print("{}\t", i);
                        }
                        std::println("");
                }
                std::println("");
        }
}
