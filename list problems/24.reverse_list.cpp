#include "mylist.h"
#include <iostream>

using namespace std;

void reverse_list_iteratively(ListNode** p_p_head) {
	if (p_p_head == nullptr || *p_p_head == nullptr || (*p_p_head)->p_next == nullptr)
		return;
	ListNode* p_reverse_head = *p_p_head;
	ListNode* p_node = (*p_p_head)->p_next;
	ListNode* p_node_next = nullptr;
	p_reverse_head->p_next = nullptr;
	while (p_node != nullptr) {
		cout << p_reverse_head->data << ' ';
		p_node_next = p_node->p_next;
		p_node->p_next = p_reverse_head;
		p_reverse_head = p_node;
		p_node = p_node_next;
	}
	cout << endl;
	*p_p_head = p_reverse_head;
}

ListNode* reverse_list_recursively(ListNode* p_p_head) {
	if (p_p_head == nullptr || p_p_head->p_next == nullptr)
		return p_p_head;

	ListNode* p_reverse_head = reverse_list_recursively(p_p_head->p_next);
	ListNode* p_node = p_reverse_head;
	while(p_node->p_next != nullptr)
		p_node = p_node->p_next;

	p_node->p_next = p_p_head;
	p_p_head->p_next = nullptr;

	return p_reverse_head;
}

int main() {
	ListNode* p_head = nullptr;
	append_node(&p_head, 10);
	
	append_node(&p_head, 30);

	append_node(&p_head, 20);
	
	ListNode* p_reverse_head = reverse_list_recursively(p_head);
	cout << p_reverse_head->data << endl;
	return 0;
}