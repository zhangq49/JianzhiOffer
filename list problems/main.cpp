#include "mylist.h"
#include <iostream>

using namespace std;

int main() {
	ListNode* pHead = nullptr;
	AppendNode(&pHead, 10);
	AppendNode(&pHead, 20);
	AppendNode(&pHead, 30);
	ListNode* pNode = pHead;
	while (pNode != nullptr) {
		cout << pNode->data << endl;
		pNode = pNode->pNext;
	}

	cout << endl;

	RemoveNode(&pHead, 20);

	pNode = pHead;
	while (pNode != nullptr) {
		cout << pNode->data << endl;
		pNode = pNode->pNext;
	}

	cout << endl;

	RemoveNode(&pHead, 10);

	pNode = pHead;
	while (pNode != nullptr) {
		cout << pNode->data << endl;
		pNode = pNode->pNext;
	}

	return 0;
}