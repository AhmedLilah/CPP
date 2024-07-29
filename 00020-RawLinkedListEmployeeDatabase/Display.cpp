#include "headers.hpp"
#include <print>
#include <format>

void Display ( node* h ) {
	node* p;
	p = h;
	while (p != NULL) {
                std::println("name: {}\t\tsalary: {}", p->name, p->salary);
		p = p->next;
	}
}
