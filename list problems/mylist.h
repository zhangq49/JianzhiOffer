#ifndef _MY_LIST_H
#define _MY_LIST_H

struct ListNode {
	int data;
	ListNode* p_next;
};

void append_node(ListNode** p_p_head, int value);

void remove_node(ListNode** p_p_head, int value);

#endif