#include <concepts>
#include <iostream>
#include <format>
#include <type_traits>
#include <print>


template<typename T, typename ...Args>
concept NotStringLiteral = !std::disjunction_v<
	std::is_same<T, const char *>,
	std::is_same<T, char *>,
	std::is_same<T, const char []>,
	std::is_same<T, std::format_string<Args...>>,
	std::is_base_of<std::ostream, T>,
	std::is_base_of<std::string_view, T>
>;

namespace std {
// template<typename T, typename... Args> requires NotStringLiteral<T, Args...>
// void print(T&& var) {
//         std::cout << std::format(" {}", var);
// }

// template<typename T, typename... Args> requires NotStringLiteral<T, Args...>
// void println(T&& var) {
//         std::cout << std::format(" {}", var);
// }

template<typename T, typename... Args> requires NotStringLiteral<T, Args...>
void print(T first, Args&&... args) {
        std::cout << std::format("{}", std::move(first));
        (std::cout << ... << std::format(" {}", args));
        // if constexpr (sizeof...(args) > 0) {
        //         print(args...);
        // }
}

template<typename T, typename... Args> requires NotStringLiteral<T, Args...>
void println(T first, Args&&... args) {
        std::cout << std::format("{}", std::move(first));
        (std::cout << ... << std::format(" {}", args));
        std::cout << '\n';
        // if constexpr (sizeof...(args) > 0) {
        //         println(args...);
        // } else {
        //         std::cout << '\n';
        // }
}

// template<typename T, typename... Args> requires NotStringLiteral<T, Args...>
// void print(T& first, Args&&... args) {
//         std::cout << std::format("{}", std::move(first));
//         (std::cout << ... << std::format(" {}", args));
//         // if constexpr (sizeof...(args) > 0) {
//         //         print(args...);
//         // }
// }

// template<typename T, typename... Args> requires NotStringLiteral<T, Args...>
// void println(T& first, Args&&... args) {
//         std::cout << std::format("{}", std::move(first));
//         (std::cout << ... << std::format(" {}", args));
//         std::cout << '\n';
//         // if constexpr (sizeof...(args) > 0) {
//         //         println(args...);
//         // } else {
//         //         std::cout << '\n';
//         // }
// }
}

struct MyStr {
        MyStr() = default;
        MyStr(MyStr& ms) {
                std::println("i was coppied");
        }
        MyStr(MyStr&&) = default;
};

template <>
struct std::formatter<MyStr> {
    constexpr auto parse(std::format_parse_context& ctx) {
        return ctx.begin();
    }

    template <typename FormatContext>
    auto format(const MyStr& p, FormatContext& ctx) {
        return std::format_to(ctx.out(), "MyStr");
    }
};

int main() {
        // These calls will use your custom print and println functions
        constexpr const char * ts {"this is a test string {}"}; 
        std::print(ts, "error\n");
        std::print(1, 2, 3, '\n'); // prints "1 2 3 "
        std::println(1, 2, 3, "\n"); // prints "1 2 3 \n"


        // These calls will use the C++23 STL version of print and println
        std::print("Hello, World");
        std::print("{}, {}, {} {}", 1, 2, 3, '\n'); // prints "1, 2, 3"
        std::println("{}, {}, {} {}", 1, 2, 3, "\n"); // prints "1, 2, 3\n"
        
        // cheking copies in both version.
        MyStr ms;
        std::println(std::move(ms), ": Proposed version");
        std::println("{}: STL version", ms);
        return 0;
}

