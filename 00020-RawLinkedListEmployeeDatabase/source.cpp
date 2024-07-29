#include "headers.hpp"
#include "Create.hpp"
#include "Display.hpp"
#include "Modify.hpp"
#include <print>
#include <format>
#include <iostream>

int main ( )
{
        int n = 0;
        std::string name;
        float salary;
        node* h = NULL;
        std::println("how many nodes: ");
        std::cin >> n;
        h = Create(n);
        Display(h);
        std::println("enter the name of the employee you want to change his salalry: ");
        std::cin >> name;
        std::println("enter the salary: ");
        std::cin >> salary;
        bool t = Modify(h, name, salary);
        std::println("{}", t);
        Display(h);
        return 0;
}
