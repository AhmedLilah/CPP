import std.core;

auto main() -> int { 
        std::println("Hellow, World");

        std::set<std::string> cards {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, "guard", "queen", "king"};
        for ( auto const & card : cards) {
                std::print("{}", card);
        }
}
