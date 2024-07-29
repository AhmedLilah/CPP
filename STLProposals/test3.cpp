#include <concepts>
#include <iostream>
#include <format>
#include <type_traits>
#include <print>

// template<typename T>
// concept NotFormatString = !std::is_same_v<T, std::format_string<>> && !std::is_same_v<T, const char *> && !std::is_same_v<T, char *>;

template<typename T>
concept NotFormatString = !std::disjunction_v<std::is_same<T, const char*>, std::is_same<T, const char (&)[]>, std::is_same<T, std::string>>;

namespace std {
template<NotFormatString T, typename... Args>
void print(T&& first, Args&&... args) {
        std::cout << std::format("{} ", first);
        if constexpr (sizeof...(args) > 0) {
                print(args...);
        }
}

template<NotFormatString T, typename... Args>
void println(T&& first, Args&&... args) {
        std::cout << std::format("{} ", first);
        if constexpr (sizeof...(args) > 0) {
                println(args...);
        } else {
                std::cout << '\n';
        }
}
}

int main() {
        // These calls will use your custom print and println functions
        const char * ts {"this is a test string {}"}; 
        std::print(ts, "error");
        std::print(1, 2, 3); // prints "1 2 3 "
        std::println(1, 2, 3); // prints "1 2 3 \n"

        // These calls will use the C++23 STL version of print and println
        std::print("{}, {}, {}", 1, 2, 3); // prints "1, 2, 3"
        std::println("{}, {}, {}", 1, 2, 3); // prints "1, 2, 3\n"
        return 0;
}



// #include <print>
// #include <iostream>
// #include <format>
// #include <type_traits>

// namespace std {
// template<typename T, typename... Args> requires (!std::is_same_v<const char *, T>)
// void print(T&& first, Args&&... args) {
//         // use a fold expression to print each argument followed by the separator
//         std::cout << std::format("{} ", first);
//         (std::cout << ... << std::format("{} ", args));
// }

// template<typename T, typename... Args> requires (!std::is_same_v<const char *, T>)
// void println(T&& first, Args&&... args) {
//         // use a fold expression to print each argument followed by the separator
//         std::cout << std::format("{} ", first);
//         (std::cout << ... << std::format("{} ", args));
//         std::cout << '\n';
// }
// }

// int main() {
//     // These calls will use your custom print and println functions
//     std::print(1, 2, 3); // prints "1 2 3 "
//     std::println(1, 2, 3); // prints "1 2 3 \n"

//     // These calls will use the C++23 STL version of print and println
//     std::print("{}, {}, {}", 1, 2, 3); // prints "1, 2, 3"
//     std::println("{}, {}, {}", 1, 2, 3); // prints "1, 2, 3\n"
//     return 0;
// }



// #include <iostream>
// #include <format>
// #include <type_traits>
// #include <print>

// namespace std {
// template<typename T>
// void print(T&& first) {
//     std::cout << std::format("{} ", first);
// }

// template<typename T, typename U, typename... Args>
// void print(T&& first, U&& second, Args&&... args) {
//     std::cout << std::format("{} ", first);
//     print(second, args...);
// }

// template<typename T>
// void println(T&& first) {
//     std::cout << std::format("{}\n", first);
// }

// template<typename T, typename U, typename... Args>
// void println(T&& first, U&& second, Args&&... args) {
//     std::cout << std::format("{} ", first);
//     println(second, args...);
// }
// }

// int main() {
//     // These calls will use your custom print and println functions
//     std::print(1, 2, 3); // prints "1 2 3 "
//     std::println(1, 2, 3); // prints "1 2 3 \n"

//     // These calls will use the C++23 STL version of print and println
//     std::print("{}, {}, {}", 1, 2, 3); // prints "1, 2, 3"
//     std::println("{}, {}, {}", 1, 2, 3); // prints "1, 2, 3\n"
//     return 0;
// }






// #include <iostream>
// #include <format>
// #include <type_traits>
// #include <print>

// namespace std {
// template<typename T, typename... Args>
// void print(T&& first, Args&&... args) {
//     std::cout << std::format("{} ", first);
//     if constexpr (sizeof...(args) > 0) {
//         print(args...);
//     }
// }

// template<typename T, typename... Args>
// void println(T&& first, Args&&... args) {
//     std::cout << std::format("{} ", first);
//     if constexpr (sizeof...(args) > 0) {
//         println(args...);
//     } else {
//         std::cout << '\n';
//     }
// }
// }

// int main() {
//     // These calls will use your custom print and println functions
//         std::print(1, 2, 3); // prints "1 2 3 "
//         std::print(1, 2, 3, 4); // prints "1 2 3 "
//         std::println(1, 2, 3); // prints "1 2 3 \n"
//         std::println(1, 2, 3, 4, 5); // prints "1 2 3 \n"

//     // These calls will use the C++23 STL version of print and println
//         std::print("{}, {}, {}", 1, 2, 3); // prints "1, 2, 3"
//         std::println("{}, {}, {}", 1, 2, 3); // prints "1, 2, 3\n"
//     return 0;
// }






