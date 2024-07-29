#include <print>
#include <expected>

enum class ParsingErrors {
        InvalidInput,
        Overflow,
};

auto function(int8_t a) -> std::expected<std::string, ParsingErrors> {
        using std::unexpected, std::string;

        if (0 < a)
                return unexpected(ParsingErrors::InvalidInput);
        else if (0 == a)
                return unexpected(ParsingErrors::Overflow);
        else
                return string("HellowWorld");
}

struct Foo {
public:
        Foo() = delete;
        Foo(Foo& self) = default;
        Foo(std::string && input);
        auto format() -> std::string;
public:
        std::string x;
};

Foo::Foo(std::string && input) {
        this->x = std::move(input);
}

auto Foo::format() -> std::string {
        return this->x;
}

auto main() -> int {
        using std::print, std::println;

        for (int8_t i = -1; i<2; ++i) {
                auto result {function(i)};
                if (result) 
                        println("{}.", result.value());
                else if (result.error() == ParsingErrors::InvalidInput)
                        println("[ERROR] Invalid input.");
                else
                        println("[ERROR] Overflow.");
        }

        Foo foo("Ahmed");
        println("the name is: {{{}}}", foo.format());

        return 0;
}
