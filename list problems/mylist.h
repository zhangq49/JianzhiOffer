#ifndef _MY_LIST_H
#define _MY_LIST_H

struct ListNode {
	int data;
	ListNode* pNext;
};

void AppendNode(ListNode** ppHead, int value);

void RemoveNode(ListNode** ppHead, int value);

#endif