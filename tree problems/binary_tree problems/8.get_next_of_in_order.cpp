#include "binary_tree2.h"
#include <iostream>

BinaryTreeNode* GetNextOfInOrder(BinaryTreeNode* pNode) {
	if (pNode == nullptr) return pNode;

	BinaryTreeNode* pRes = nullptr;
	
	// if pNode has right child
	if (pNode->pRight != nullptr) {
		// get the left-most leave node
		pRes = pNode->pRight;
		while (pRes->pLeft != nullptr) {
			pRes = pRes->pLeft;
		}
	// if pNode has no right child and pNode has parent
	} else if (pNode->pParent != nullptr) {
		// Note: it's easy to make mistakes here!!!!!!!!!!!!!!!
		BinaryTreeNode* pCurrent = pNode;
		BinaryTreeNode* pParent = pNode->pParent;

		while (pParent != nullptr && pCurrent == pParent->pRight) {
			pCurrent = pParent;
			pParent = pParent->pParent;
		}

		pRes = pCurrent->pParent;
	}

	return pRes;
}

int main() {
	// construct a tree
	//             1
	//       2           3
	//     4   5       6   7
	BinaryTreeNode* pNode7 = new BinaryTreeNode{7, nullptr, nullptr, nullptr};
	BinaryTreeNode* pNode6 = new BinaryTreeNode{6, nullptr, nullptr, nullptr};
	BinaryTreeNode* pNode5 = new BinaryTreeNode{5, nullptr, nullptr, nullptr};
	BinaryTreeNode* pNode4 = new BinaryTreeNode{4, nullptr, nullptr, nullptr};
	BinaryTreeNode* pNode3 = new BinaryTreeNode{3, pNode6, pNode7, nullptr};
	BinaryTreeNode* pNode2 = new BinaryTreeNode{2, pNode4, pNode5, nullptr};
	BinaryTreeNode* pNode1 = new BinaryTreeNode{1, pNode2, pNode3, nullptr};
	pNode7->pParent = pNode3;
	pNode6->pParent = pNode3;
	pNode5->pParent = pNode2;
	pNode4->pParent = pNode2;
	pNode3->pParent = pNode1;
	pNode2->pParent = pNode1;

	BinaryTreeNode* pRoot = new BinaryTreeNode{0, pNode1, nullptr, nullptr};
	pNode1->pParent = pRoot;

	std::cout << GetNextOfInOrder(pNode7)->data << std::endl;
	std::cout << GetNextOfInOrder(pNode4)->data << std::endl;
	std::cout << GetNextOfInOrder(pNode5)->data << std::endl;
	std::cout << GetNextOfInOrder(pNode2)->data << std::endl;

	return 0;
}