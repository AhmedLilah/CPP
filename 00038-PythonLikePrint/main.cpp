#include <iostream>
#include <vector>
#include <format> // Ensure using C++20 or later for std::format
#include <string>
#include <type_traits>
#include <variant>

// Namespace to hold the custom println functions
namespace asl {
// Helper to detect if a string contains formatting placeholders
consteval bool hasFormatPlaceholders(const std::string str) {
        return str.find("{}") != std::string::npos;
}

// Primary template for println
template<typename T, typename... Args>
void println(T first, Args&&... args) {
        if constexpr (hasFormatPlaceholders(first)) {
                if constexpr (sizeof...(args) > 0) {
                        try {
                                std::cout << std::format(std::forward<T>(first), std::forward<Args>(args)...) << std::endl;
                        } catch (const std::format_error& e) {
                                std::cerr << "Format error: " << e.what() << std::endl;
                        }
                } else {
                        std::cout << std::forward<T>(first) << std::endl; // Print format string directly if no args are provided
                }
        } else {
                if constexpr (sizeof...(args) == 0) {
                        std::cout << std::forward<T>(first) << std::endl;
                } else {
                        std::cout << std::forward<T>(first);
                        ((std::cout << ' ' << std::forward<Args>(args)), ...) << std::endl;
                }
        }
}

// Print with arguments separated by spaces
template<typename ... Args>
void println(Args ... args) {
        if constexpr (sizeof...(args) >= 1) {
                ((std::cout << args << ' '), ...) << std::endl;
        } else {
                std::cout << std::endl; // Handle the case of no arguments separately
        }
}

// Print std::vector
template<typename T>
void println(const std::vector<T>& vec) {
        for (const auto& elem : vec) {
                std::cout << elem << ' ';
        }
        std::cout << std::endl;
}

// Print with default format string handling
void println() {
        std::cout << std::endl; // Handle the case of no arguments separately
}
}

int main() {
        // Test cases

        // 1. Basic Format String Test
        asl::println("Number: {}, String: {}", 42, "Test");

        // 2. Format String with Different Data Types
        asl::println("Int: {}, Float: {:.2f}, Char: {}", 123, 456.789, 'A');

        // 3. Format String with Special Characters
        asl::println("Special characters: {}, {}, {}", '@', '#', '$');

        // 4. No Arguments with Format String
        asl::println(""); // Expected output: a newline (empty format string)

        // 5. Only Format String without Arguments
        asl::println("Hello, {}!");

        // 6. Print Multiple Arguments (no format string)
        asl::println("This", "is", "a", "test", "with", "multiple", "arguments");

        // 7. Print Empty Arguments (no format string)
        asl::println(); // Expected output: a newline (no arguments)

        // 8. Print Mixed Arguments with Format String
        asl::println("String: {}, Number: {}, Float: {:.1f}", "test", 42, 3.14);

        // 9. Print std::vector of Integers
        std::vector<int> vecInt = {10, 20, 30};
        asl::println(vecInt);

        // 10. Print std::vector of Strings
        std::vector<std::string> vecStr = {"Hello", "world", "from", "vector"};
        asl::println(vecStr);

        // 11. Print std::vector with Mixed Data Types
        std::vector<std::variant<int, std::string>> mixedVec = {1, "text", 2};
        for (const auto& item : mixedVec) {
                if (std::holds_alternative<int>(item)) {
                        asl::println(std::get<int>(item));
                } else if (std::holds_alternative<std::string>(item)) {
                        asl::println(std::get<std::string>(item));
                }
        }

        // 12. Print with Extra Spaces (no format string)
        asl::println("   ", "Extra", "Spaces   ");

        // 13. Print Floating Point with Different Precision
        asl::println("Float: {:.5f}", 3.141592653589793);

        return 0;
}
