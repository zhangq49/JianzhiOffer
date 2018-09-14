#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 101

int triangle[MAX][MAX];
int max_sum[MAX][MAX];
int n;

int get_max_path_len_recursively(int i, int j) {
	if (max_sum[i][j] != -1) return max_sum[i][j];
	if (i == n - 1) return triangle[i][j];
	
	int left_max_len = get_max_path_len_recursively(i + 1, j);
	int right_max_len = get_max_path_len_recursively(i + 1, j + 1);
	max_sum[i][j] = max(left_max_len, right_max_len) + triangle[i][j];

	return max_sum[i][j];
}

int get_max_path_len_dp() {
	for (int i = 0; i < n; i++)
		max_sum[n - 1][i] = triangle[n - 1][i];

	for (int i = n - 2; i >= 0; i--)
		for (int j = 0; j <= i; j++)
			max_sum[i][j] = max(max_sum[i + 1][j], max_sum[i + 1][j + 1]) + triangle[i][j];

	return max_sum[0][0];
}

int main() {
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			max_sum[i][j] = -1;

	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < i + 1; j++)
			cin >> triangle[i][j];

	int max_len = get_max_path_len_dp();

	cout << max_len << endl;

	return 0;
}
