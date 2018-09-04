#include <iostream>
#include "mylist.h"

using namespace std;

ListNode* merge_two_sorted_lists(ListNode* p_list1, ListNode* p_list2) {	
	if (p_list1 == nullptr)
		return p_list2;

	if (p_list2 == nullptr)
		return p_list1;

	ListNode* p_result_list = new ListNode();
	p_result_list->p_next = nullptr;
	ListNode* p_node_result_list = p_result_list;
	ListNode* p_node_list1 = p_list1;
	ListNode* p_node_list2 = p_list2;

	while (p_node_list1 != nullptr && p_node_list2 != nullptr) {

		if (p_node_list1->data < p_node_list2->data) {
			p_node_result_list->p_next = p_node_list1;
			p_node_list1 = p_node_list1->p_next;
		} else {
			p_node_result_list->p_next = p_node_list2;
			p_node_list2 = p_node_list2->p_next;
		}

		p_node_result_list = p_node_result_list->p_next;
	}

	if (p_node_list1 != nullptr) {
		p_node_result_list->p_next = p_node_list1;
		p_node_result_list = p_node_result_list->p_next;
	}

	if (p_node_list2 != nullptr) {
		p_node_result_list->p_next = p_node_list2;
		p_node_result_list = p_node_result_list->p_next;
	}

	p_node_result_list->p_next = nullptr;
	p_node_result_list = p_result_list;
	p_result_list = p_result_list->p_next;
	delete p_node_result_list;

	return p_result_list;
}

ListNode* merge_two_sorted_lists_recursively(ListNode* p_list1, ListNode* p_list2) {
	if (p_list1 == nullptr)
		return p_list2;
	if (p_list2 == nullptr)
		return p_list1;

	ListNode* p_result_list = nullptr;
	if (p_list1->data < p_list2->data) {
		p_result_list = p_list1;
		p_result_list->p_next = merge_two_sorted_lists_recursively(p_list1->p_next, p_list2);
	} else {
		p_result_list = p_list2;
		p_result_list->p_next = merge_two_sorted_lists_recursively(p_list1, p_list2->p_next);
	}

	return p_result_list;
}

int main() {
	ListNode* p_list1 = nullptr;
	append_node(&p_list1, 10);
	
	append_node(&p_list1, 20);

	append_node(&p_list1, 30);

	ListNode* p_list2 = nullptr;
	append_node(&p_list2, 15);
	
	append_node(&p_list2, 25);

	append_node(&p_list2, 28);

	ListNode* p_result_list = merge_two_sorted_lists_recursively(p_list1, p_list2);
	ListNode* p_node_result_list = p_result_list;
	while (p_result_list != nullptr) {
		cout << p_result_list->data << ' ';
		p_result_list = p_result_list->p_next;
	}
	cout << endl;

	return 0;
}
