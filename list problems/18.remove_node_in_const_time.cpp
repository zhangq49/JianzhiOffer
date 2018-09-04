#include "mylist.h"
#include <iostream>

using namespace std;

void remove_node_in_const_time(ListNode** p_p_head, ListNode* p_node) {
	if (p_p_head == nullptr || *p_p_head == nullptr || p_node == nullptr)
		return;

	ListNode* p_node_next = p_node->p_next;
	if (p_node_next != nullptr) {
		p_node->data = p_node_next->data;
		p_node->p_next = p_node_next->p_next;
		delete p_node_next;
		p_node_next = nullptr;
	} else if (p_node == *p_p_head) {
		*p_p_head = nullptr;
		delete p_node;
		p_node = nullptr;
	} else {
		ListNode* p_tmp_node = *p_p_head;
		while (p_tmp_node->p_next != p_node)
			p_tmp_node = p_tmp_node->p_next;
		p_tmp_node->p_next = nullptr;
		delete p_node;
		p_node = nullptr;
	}
}

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