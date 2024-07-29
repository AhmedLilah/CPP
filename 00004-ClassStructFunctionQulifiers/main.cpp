#include <print>
#include <utility>
#include "include.hpp"

struct Name{
        Name() {
                a = 5;
        }

        void method() & {
                std::println("this executed because the class instance is an lvalue");
        }

        void method() && {
                std::println("this executed because the class instance is an rvalue");
        }
        
        void method() const & {
                std::println("this executed because the class instance is an lvalue const");
        }

        void method() const && {
                std::println("this executed because the class instance is an rvalue const");

        }

        int a;
};

auto main() -> int {
        Name a;
        const Name b;
        a.method();
        b.method();
        std::move(a).method();
        std::move(b).method();
        fn(5);
}
