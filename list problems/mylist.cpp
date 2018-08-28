#include "mylist.h"

void AppendNode(ListNode** ppHead, int value) {
	if (ppHead == nullptr) return;

	ListNode* pNewNode = new ListNode; // the same as new ListNode();
	pNewNode->data = value;
	pNewNode->pNext = nullptr;

	if (*ppHead == nullptr) {
		*ppHead = pNewNode;
	} else {
		ListNode* pTmpNode = *ppHead;
		while (pTmpNode->pNext != nullptr)
			pTmpNode = pTmpNode->pNext;
		pTmpNode->pNext = pNewNode;
	}
}

void RemoveNode(ListNode** ppHead, int value) {
	if (ppHead == nullptr || *ppHead == nullptr) return;

	ListNode* pToBeDeleted = nullptr;

	if ((*ppHead)->data == value) { // cannot use *ppHead->data
		pToBeDeleted = *ppHead;
		*ppHead = (*ppHead)->pNext;
	} else {
		ListNode* pNode = *ppHead;
		while (pNode->pNext != nullptr && pNode->pNext->data != value) {
			pNode = pNode->pNext;
		}

		if (pNode->pNext != nullptr && pNode->pNext->data == value) {
			pToBeDeleted = pNode->pNext;
			pNode->pNext = pNode->pNext->pNext;
		}
	}

	if (pToBeDeleted != nullptr) {
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
	}
}