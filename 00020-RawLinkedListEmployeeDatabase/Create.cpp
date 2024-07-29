#include "headers.hpp"
#include <print>
#include <format>
#include <iostream>

node* Create ( int n ) {
	int i = 0;
	node* head = nullptr;
	node* temp = nullptr;
	node* p = nullptr;
        std::string nh;
	float sh;
	for (i = 0; i < n; i++) {
		// let us create individual nodes.
		temp = new node;
                std::println("Enter the name for employee number: {}", i + 1);
                std::cin >> temp->name;
                std::println("Enter the salary for employee number: {}", i + 1);
                std::cin >> temp->salary;
		temp->next = nullptr;

		if (head == nullptr)	// if list is currently empty, then make temp as first node {
			head = temp;
		else {
			p = head;
			while (p->next != nullptr) {
				p = p->next;
			}
			p->next = temp;
		}
	}
	return head;
}
