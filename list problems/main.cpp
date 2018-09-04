#include "mylist.h"
#include <iostream>

using namespace std;

int main() {
	ListNode* p_head = nullptr;
	append_node(&p_head, 10);
	append_node(&p_head, 20);
	append_node(&p_head, 30);
	ListNode* p_node = p_head;
	while (p_node != nullptr) {
		cout << p_node->data << endl;
		p_node = p_node->p_next;
	}

	cout << endl;

	remove_node(&p_head, 20);

	p_node = p_head;
	while (p_node != nullptr) {
		cout << p_node->data << endl;
		p_node = p_node->p_next;
	}

	cout << endl;

	remove_node(&p_head, 10);

	p_node = p_head;
	while (p_node != nullptr) {
		cout << p_node->data << endl;
		p_node = p_node->p_next;
	}

	return 0;
}