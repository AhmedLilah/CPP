Document Number: PxxxxR0
Date: 2023-08-dd
Reply-to: [sabrylilah@gmail.com]
Audience: Library Evolution Working Group
Title: Extending the usability of std::print Function

Abstract
This paper proposes an enhancement to the existing std::print function in the C++ standard library. The proposed enhancement aims to provide a more concise and readable syntax for using std::print to print multiple values.

Motivation
The current std::print function in the C++23 standard library requires using format string literals (such as "{} {}") to specify the output format and the values to be printed. While this approach offers flexibility, it can become tedious when printing multiple values or when the values have complex types.

The proposed enhancement aims to provide a simpler way to print multiple values using std::print without the need for format string literals.

# Proposal: Enhancing std::print
## std::print
The enhanced std::print function would have the following signature:

```cpp
void print(const char * separator, const auto &... args); 
```

This function would take a variable number of arguments of any type and an optional separator character argument (defaulting to space). The function would print the arguments to the standard output stream (std::cout) separated by the specified separator character. The arguments would be formatted using their respective operator<< overloads.

# Example Usage
Here is an example that demonstrates how the enhanced std::print function could be used:

```cpp
int x = 1;
double y = 2.0;
std::string z = "this is a string";

std::print(x, y, z); // prints "1 2.0 this is a string"
```

Acknowledgments
[Optional: Acknowledge any individuals or organizations that provided assistance or feedback on this proposal.]

References
[Optional: List any references cited in this proposal.]
