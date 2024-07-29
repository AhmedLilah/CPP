#include <print>
#include <iostream>
#include <source_location>
#include <stacktrace>

void thirdLevel() {
        auto const sl { std::source_location().current() };
        std::println(std::cerr, "Error[{}]: in {}, line {}, column {}.", -1, sl.file_name(), sl.line(), sl.column());
        std::println("\tfunction {}", sl.function_name());
        std::cout << std::stacktrace::current() << '\n';
}

void secondLevel() {
        thirdLevel();
}

void firstLevel() {
        secondLevel();
}



auto main() -> int {
        firstLevel();
        return 0;
}
