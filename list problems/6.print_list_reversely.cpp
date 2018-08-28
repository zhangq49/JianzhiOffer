#include "mylist.h"
#include <stack>
#include <iostream>

void PrintListReversely(ListNode* pHead) {
	std::stack<ListNode*> nodes;
	ListNode* pNode = pHead;
	while (pNode != nullptr) {
		nodes.push(pNode);
		pNode = pNode->pNext;
	}

	while(!nodes.empty()) {
		pNode = nodes.top();
		std::cout << pNode->data << std::endl;
		nodes.pop();
	}
}

int main() {
	ListNode* pHead = nullptr;
	AppendNode(&pHead, 10);
	AppendNode(&pHead, 20);
	AppendNode(&pHead, 30);

	PrintListReversely(pHead);

	return 0;
}