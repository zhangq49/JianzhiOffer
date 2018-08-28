#include "binary_tree.h"
#include <iostream>

BinaryTreeNode* ConstructBinaryTree(int* preOrderArr, 
	int* inOrderArr, int len) {
	if (preOrderArr == nullptr || inOrderArr == nullptr || len == 0)
		return nullptr;

	int rootValue = preOrderArr[0];

	BinaryTreeNode* pRoot = new BinaryTreeNode;
	pRoot->data = rootValue;
	pRoot->pLeft = pRoot->pRight = nullptr;

	int index, numOfLeft, numOfRight;
	if (len > 1) {
		for (index = 0; index < len; index++)
			if (inOrderArr[index] == rootValue)
				break;

		numOfLeft = index;
		numOfRight = len - index - 1;

		// the left part of inOrderArr has more than 0 elements 
		if (numOfLeft > 0)
			pRoot->pLeft = ConstructBinaryTree(preOrderArr + 1, inOrderArr, numOfLeft);

		// the right part of inOrderArr has more than 0 elements
		if (numOfRight > 0)
			pRoot->pRight = ConstructBinaryTree(preOrderArr + numOfLeft + 1, inOrderArr + numOfLeft + 1, numOfRight);
	}

	return pRoot;
}

int main() {
	int preOrderArr[8] = {1, 2, 4, 7, 3, 5, 6, 8};
	int inOrderArr[8] = {4, 7, 2, 1, 5, 3, 8, 6};
	BinaryTreeNode* pRoot = ConstructBinaryTree(preOrderArr, inOrderArr, 8);

	std::cout << pRoot->data << std::endl;
	std::cout << pRoot->pLeft->data << std::endl;
	std::cout << pRoot->pRight->data << std::endl;

	return 0;
}