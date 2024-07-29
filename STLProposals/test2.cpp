#include <iostream>
#include <format>
#include <print>
#include <type_traits>

namespace std {
template<typename T, typename... Args> requires (!std::is_same_v<const char *, T> && !std::is_same_v<T, char *>)
void print(T&& first, Args&&... args) {
        // use a fold expression to print each argument followed by the separator
        std::cout << std::format("{} ", first);
        (std::cout << ... << std::format("{} ", args));
}

template<typename T, typename... Args> requires (!std::is_same_v<const char *, T> && !std::is_same_v<T, char *>)
void println(T&& first, Args&&... args) {
        // use a fold expression to print each argument followed by the separator
        std::cout << std::format("{} ", first);
        (std::cout << ... << std::format("{} ", args));
        std::cout << '\n';
}

// template<typename... Args>
// void print(const std::string& sep = " ", Args&&... args) {
//         // use std::apply to unpack the tuple of arguments and print them with the separator
//         std::apply([&sep](auto&&... arg) {
//                 // use a fold expression to print each argument followed by the separator
//                 ((std::cout << std::format("{}", arg) << sep), ...);
//         }, std::forward_as_tuple(args...));
// }

// template<typename... Args>
// void println(const std::string& sep = " ", Args&&... args) { 
//         // use std::apply to unpack the tuple of arguments and print them with the separator
//         std::apply([&sep](auto&&... arg) {
//                 // use a fold expression to print each argument followed by the separator
//                 ((std::cout << std::format("{}", arg) << sep), ...);
//                 // print a newline at the end
//                 std::cout << "\n";
//         }, std::forward_as_tuple(args...));
// }
}

int main() {
        int x {};
        int y {40};
        std::string mes {"hellow from new print"};

        std::print("Hello", "world"); // prints "Hello world "
        std::print(1, 2, 3); // prints "1,2,3,"
        std::print("***", 1, 2, 3); // prints "1***2***3***"
        std::println(""); // prints nothing
        std::println("Hello", "world"); // prints "Hello world "
        std::println(1, 2, 3); // prints "1,2,3,"
        std::println("***", 1, 2, 3); // prints "1***2***3***"

        // this should use the default C++23 std::print, std::println
        std::println("STL println: {}, {}, {}", x, y, mes);
        std::print("STL println: {}, {}, {}", x, y, mes);
        return 0;
}
