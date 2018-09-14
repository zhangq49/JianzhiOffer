#include <vector>
#include <iostream>

using namespace std;

int FindGreatestSumOfSubArray2(vector<int> array) {
	int maxSum = 0x80000000, prevSum = 0;

	for (int i = 0; i < array.size(); i++) {
		prevSum = (prevSum > 0) ? prevSum + array[i] : array[i];
		maxSum = max(maxSum, prevSum);
	}

	return maxSum;
}

int FindGreatestSumOfSubArray(vector<int> array) {
	int maxSum = 0x80000000;
	int dp[array.size()];

	dp[0] = array[0];

	for (int i = 1; i < array.size(); i++)
		dp[i] = max(dp[i - 1] + array[i], array[i]);

	for (int i = 0; i < array.size(); i++)
		maxSum = max(maxSum, dp[i]);

	return maxSum;
}


int main() {
	vector<int> array = {1, -2, 3, 10, -4, 7, 2, -5};
	cout << FindGreatestSumOfSubArray(array) << endl;

	return 0;
}