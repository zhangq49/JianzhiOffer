#include "mylist.h"

void append_node(ListNode** p_p_head, int value) {
	if (p_p_head == nullptr) return;

	ListNode* p_new_node = new ListNode; // the same as new ListNode();
	p_new_node->data = value;
	p_new_node->p_next = nullptr;

	if (*p_p_head == nullptr) {
		*p_p_head = p_new_node;
	} else {
		ListNode* p_tmp_node = *p_p_head;
		while (p_tmp_node->p_next != nullptr)
			p_tmp_node = p_tmp_node->p_next;
		p_tmp_node->p_next = p_new_node;
	}
}

void remove_node(ListNode** p_p_head, int value) {
	if (p_p_head == nullptr || *p_p_head == nullptr) return;

	ListNode* p_node_to_be_deleted = nullptr;

	if ((*p_p_head)->data == value) { // cannot use *p_p_head->data
		p_node_to_be_deleted = *p_p_head;
		*p_p_head = (*p_p_head)->p_next;
	} else {
		ListNode* p_node = *p_p_head;
		while (p_node->p_next != nullptr && p_node->p_next->data != value) {
			p_node = p_node->p_next;
		}

		if (p_node->p_next != nullptr && p_node->p_next->data == value) {
			p_node_to_be_deleted = p_node->p_next;
			p_node->p_next = p_node->p_next->p_next;
		}
	}

	if (p_node_to_be_deleted != nullptr) {
		delete p_node_to_be_deleted;
		p_node_to_be_deleted = nullptr;
	}
}

