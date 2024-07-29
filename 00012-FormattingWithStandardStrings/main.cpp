#include <print>


auto main() -> int {
        constexpr std::string message{"hello world!"}, format{"{}"};
        std::println(format, message);
}
