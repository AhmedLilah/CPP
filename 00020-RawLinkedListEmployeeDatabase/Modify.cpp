#include "headers.hpp"
#include <iostream>

bool Modify ( node* h, std::string n, float s ) {
	node* p = NULL;
	p = h;
	while (p != NULL) {
		if (p->name == n) {
			p->salary = s;
			return true;
		}
		p = p->next;
	}
	return false;
}
