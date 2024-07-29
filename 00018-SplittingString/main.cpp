#include <print>
#include <ranges>
#include <string>
#include <vector>
#include <regex>
#include <format>

auto main()-> int {
        std::string input{
            "#include <print>\n"
            "#include <ranges>\n"
            "#include <string>\n"
            "#include <vector>\n"
            "#include <regex>\n"
            "#include <format>\n"
            "\n"
            "auto main()-> int {\n"
            "    std::string input{\n"
            "    };\n"
            "    \n"
            "    std::regex re(\"\\\\s+\");\n"
            "    std::sregex_token_iterator it(input.begin(), input.end(), re, -1);\n"
            "    std::vector<std::string> result(it, {});\n"
            "\n"
            "    std::println(\"{}\", result);\n"
            "}"
        };
        
        std::regex re("\\n+");
        std::sregex_token_iterator it(input.begin(), input.end(), re, -1);
        std::vector<std::string> result(it, {});

        for (auto const & string : result)
                std::println("{}", string);
}
