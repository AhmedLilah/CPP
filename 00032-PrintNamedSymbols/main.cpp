#include <print>

auto main() -> int {
        std::println("\N{GREEK SMALL LETTER OMEGA}");
        std::println("\N{LATIN SMALL LETTER BETA}");
        std::println("\N{LATIN SMALL LETTER TURNED DELTA}");
        std::println("\N{GREEK THETA SYMBOL}");
        std::println("\N{GEORGIAN PARAGRAPH SEPARATOR}");
        std::println("\N{LATIN CAPITAL LETTER GAMMA}");
        std::println("\N{LATIN SMALL LETTER GAMMA}");
        std::println("->");
        std::println("\N{BLACK MEDIUM SMALL SQUARE}");
        std::println("\N{BOX DRAWINGS LIGHT LEFT AND HEAVY RIGHT}");
        std::println("\N{GREEK SMALL LETTER ETA}");
        std::println("\N{GREEK CAPITAL LETTER OMEGA WITH TONOS}");
        std::println("\N{ARABIC LETTER ALEF WITH HAMZA ABOVE}");
        std::println("\N{ARABIC LETTER BEH}");
        constexpr auto namedUnicode {"\N{GREEK SMALL LETTER BETA}"};
        constexpr auto unicode {"\316\262"};
        std::println("{} : {}", namedUnicode, unicode);
        return 0;
}
