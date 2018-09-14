#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
	priority_queue<int> kNumbers;
	for (auto elem : input) {
		if (kNumbers.size() < k)
			kNumbers.push(elem);
		else {
			if (kNumbers.top() > elem) {
				kNumbers.pop();
				kNumbers.push(elem);
			}
		}
	}

	vector<int> res;
	while (!kNumbers.empty()) {
		res.push_back(kNumbers.top());
		kNumbers.pop();
	}

	return res;
}

vector<int> GetLeastNumbers_Solution2(vector<int> input, int k) {
	multiset<int, greater<int>> kNumbers;
	for (auto elem : input) {
		if (kNumbers.size() < k)
			kNumbers.insert(elem);
		else {
			if (*(kNumbers.begin()) > elem) {
				kNumbers.erase(kNumbers.begin());
				kNumbers.insert(elem);
			}
		}
	}

	vector<int> res;
	for (auto elem : kNumbers)
		res.push_back(elem);

	return res;
}

vector<int> GetLeastNumbers_Solution1(vector<int> input, int k) {
	sort(input.begin(), input.end());

	vector<int> res;

	for (int i = 0; i < k; i++) {
		res.push_back(input[i]);
	}

	return res;
}

int main() {
	vector<int> input = {4, 5, 1, 6, 2, 7, 3, 8};
	vector<int> res = GetLeastNumbers_Solution(input, 4);

	for (auto elem : res)
		cout << elem << " ";

	cout << endl;

	return 0;
}