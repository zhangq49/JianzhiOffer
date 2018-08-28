#include <iostream>
#include <vector>

using namespace std;

int get_digit_sum(int number) {
	int sum = 0;
	while (number > 0) {
		sum += number % 10;
		number /= 10;
	}
	return sum;
}

bool is_valid_row_col(int row, int col, vector<vector<bool>>& visited, const int threshold) {
	if (row >= 0 && row < visited.size() && col >= 0 && col < visited[0].size() &&
		!visited[row][col] && get_digit_sum(row) + get_digit_sum(col) <= threshold)
		return true;
	return false;
}

int get_num_of_reachable_grids_core(int row, int col, vector<vector<bool>>& visited, const int threshold) {
	int count = 0;
	if (is_valid_row_col(row, col, visited, threshold)) {
		visited[row][col] = true;
		count = 1 + get_num_of_reachable_grids_core(row - 1, col, visited, threshold) +
				get_num_of_reachable_grids_core(row, col + 1, visited, threshold) +
				get_num_of_reachable_grids_core(row + 1, col, visited, threshold) +
				get_num_of_reachable_grids_core(row, col - 1, visited, threshold);
	}

	return count;
}


int get_num_of_reachable_grids(int rows, int cols, int threshold) {
	if (rows <= 0 || cols <= 0 || threshold < 0) return 0;

	vector<bool> visited_row(cols, false);
	vector<vector<bool>> visited(rows, visited_row);
	return get_num_of_reachable_grids_core(0, 0, visited, threshold);
}

int main() {
	int rows, cols, threshold, count;

	cin >> rows >> cols;
	cin >> threshold;

	count = get_num_of_reachable_grids(rows, cols, threshold);

	cout << count << endl;

	return 0;
}