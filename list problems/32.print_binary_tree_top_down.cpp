#include <iostream>
#include <queue>
#include <vector>

using namespace std;


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};


vector<int> PrintFromTopToBottom(TreeNode* root) {
	vector<int> res;
	if (root == nullptr)
		return res;

	queue<TreeNode*> qu;
	TreeNode* pTmp = nullptr;
	qu.push(root);
	while (!qu.empty()) {
		pTmp = qu.front();
		res.push_back(pTmp->val);
		qu.pop();
		if (pTmp->left != nullptr)
			qu.push(pTmp->left);
		if (pTmp->right != nullptr)
			qu.push(pTmp->right);
	}

	return res;
}

void PrintFromTopToBottomEachLine(TreeNode* root) {
	if (root == nullptr)
		return;

	queue<TreeNode*> nodes;
	TreeNode* pTmp = nullptr;
	int toBePrinted = 1;
	int nextLevel = 0;
	nodes.push(root);

	while (!nodes.empty()) {
		pTmp = nodes.front();
		cout << pTmp->val << ' ';

		if (pTmp->left != nullptr) {
			nodes.push(pTmp->left);
			nextLevel++;
		}
		if (pTmp->right != nullptr) {
			nodes.push(pTmp->right);
			nextLevel++;
		}

		nodes.pop();
		toBePrinted--;
		if (toBePrinted == 0) {
			cout << endl;
			toBePrinted = nextLevel;
			nextLevel = 0;
		}
	}
}

void PrintFromTopToBottomEachLine_Z_Shape(TreeNode* root) {
	if (root == nullptr)
		return;

	queue<TreeNode*> nodes;
	TreeNode* pTmp = nullptr;
	int toBePrinted = 1;
	int nextLevel = 0;
	bool nextReverse = true;
	nodes.push(root);

	while (!nodes.empty()) {
		pTmp = nodes.front();
		cout << pTmp->val << ' ';

		if (!nextReverse) {
			if (pTmp->left != nullptr) {
				nodes.push(pTmp->left);
				nextLevel++;
			}
			if (pTmp->right != nullptr) {
				nodes.push(pTmp->right);
				nextLevel++;
			}
		} else {
			if (pTmp->right != nullptr) {
				nodes.push(pTmp->right);
				nextLevel++;
			}
			if (pTmp->left != nullptr) {
				nodes.push(pTmp->left);
				nextLevel++;
			}
		}
		

		nodes.pop();
		toBePrinted--;
		if (toBePrinted == 0) {
			cout << endl;
			toBePrinted = nextLevel;
			nextLevel = 0;
			nextReverse = nextReverse == false ? true : false;
		}
	}
}

int main() {
	return 0;
}