Document Number: PxxxxR0
Date: 2023-08-dd
Reply-to: [sabrylilah@gmail.com]
Audience: C++ Standard Committee
Title: Named Function Parameters with Aggregate Initialization-like Syntax

# Abstract
This paper proposes the introduction of named function parameters with aggregate initialization-like syntax to the C++ standard. The proposal aims to enhance the readability and expressiveness of function calls by allowing named parameters to be explicitly specified, making the code more self-documenting and reducing potential errors caused by positional parameter mismatches.

# Motivation
In C++, functions are typically called with positional arguments, which may lead to confusion and errors if the arguments' order is not well-known or if the function has a large number of parameters. Additionally, default argument values can often cause confusion when calling functions.

Named function parameters with aggregate initialization-like syntax can alleviate these issues by allowing the programmer to specify the parameter names explicitly. This approach improves code readability and reduces potential errors during function calls.

# Proposal: Named Function Parameters with Aggregate Initialization-like Syntax
The proposal introduces the use of aggregate initialization-like syntax for named function parameters. With this syntax, function arguments can be passed by explicitly specifying their names, similar to how aggregates (e.g., structs or arrays) are initialized.

## Function Declaration
The syntax for function declaration with named parameters would follow the existing function declaration syntax, with the addition of parameter names:

```cpp
void func(int x, float y, double pi = 3.14, std::string s);
```
## Function Call
To call functions with named parameters, the aggregate initialization-like syntax would be used:

```cpp
// A: Parameter name skipped, no default value => zero-initialized
func(42, 3.14f, "Hello, World!");

// B: Parameter name skipped, default value => initialized with default value
func(42, 3.14f);
```

The named parameters are preceded by a dot (.) and are followed by their corresponding values. The order of the named parameters in the function call should match the order of the parameters in the function declaration.

## Default Arguments
Default arguments can be utilized in combination with named function parameters:

```cpp
void func(int x, float y, double pi = 3.14, std::string s = "default value");
```

In this case, the function could be called with only the parameters the programmer wants to override:

```cpp
// A: Parameter name skipped, no default value => zero-initialized
func(42, 3.14f, "Overridden value");

// B: Parameter name skipped, default value => initialized with default value
func(42, 3.14f);
```

## Benefits
- Improved Readability: Named function parameters make function calls more self-documenting and easier to understand.
- Flexibility: Named parameters can be explicitly provided, leaving no ambiguity in the function call.
- Avoidance of Defaults Ambiguity: With named parameters, default arguments can be explicitly overridden, reducing confusion.

## Example Usage
Here is an example demonstrating the proposed syntax in a function call:

```cpp
void printPersonInfo(std::string name, int age, std::string city = "Unknown");

int main() {
    // B: Parameter name skipped, default value => initialized with default value
    printPersonInfo("John Doe", 30, "New York");

    // A: Parameter name skipped, no default value => zero-initialized
    printPersonInfo("Jane Smith", 25);
}
```

# Acknowledgments
[Optional: Acknowledge any individuals or organizations that provided assistance or feedback on this proposal.]

# References
[Optional: List any references cited in this proposal.]
