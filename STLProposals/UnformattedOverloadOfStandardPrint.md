Document Number: PxxxxR0
Date: 2023-08-dd
Reply-to: [sabrylilah@gmail.com]
Audience: Library Evolution Working Group
Title: Extending the usability of std::print and std::println Functions

# Abstract

This paper proposes the addition of two function overloads to, `std::print` and `std::println`, to the C++ standard library. These functions would provide a convenient way to print multiple values to an output stream without the use of foramatting string litterals.

# Motivation

Currently, printing multiple values to an output stream in C++ requires manually formatting the values into a string using string streams or other formatting facilities. This can be cumbersome and error-prone, especially when printing many values or when the values have complex types.

The proposed `std::print` and `std::println` functions would provide a simpler and more convenient way to print multiple values. These functions would take a variable number of arguments and print them to an output stream separated by a specified separator character (defaulting to space). The `std::println` function would also print a newline character after the last value.

Here is an example that shows how the proposed functions could be used:

```cpp
int x = 1;
double y = 2.0;
std::string z = "three";

std::print(x, y, z); // prints "1 2.0 three"
std::println(x, y, z); // prints "1 2.0 three\n"
```
# Design
This section describes the proposed design of the std::print and std::println functions.

# std::print
The std::print function would have the following signature:

```cpp
template<typename... Args>
void print(const Args&... args, std::ostream& os = std::cout, char separator = ' ');
```
This function would take a variable number of arguments of any type, an optional output stream argument (defaulting to std::cout), and an optional separator character argument (defaulting to space).

The function would print the arguments to the specified output stream separated by the specified separator character. The arguments would be formatted using their respective operator<< overloads.

# std::println
The std::println function would have the same signature as the std::print function:

```cpp
template<typename... Args>
void println(const Args&... args, std::ostream& os = std::cout, char separator = ' ');
```

This function would behave the same as the std::print function, except that it would also print a newline character after the last value.

Acknowledgments
[Optional: Acknowledge any individuals or organizations that provided assistance or feedback on this proposal.]

References
[Optional: List any references cited in this proposal.]
