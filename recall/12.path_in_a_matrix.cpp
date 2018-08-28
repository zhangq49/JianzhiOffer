#include <vector>
#include <iostream>

using namespace std;

bool has_path_in_matrix_core(const vector<vector<char>>& matrix, const string& path,
							 vector<vector<bool>>& visited, int& visited_path_length,
							 int row, int col) {
	if (path[visited_path_length] == '\0')
		return true;

	bool has_path = false;

	if (row >= 0 && row < matrix.size() && col >= 0 && col < matrix[0].size() &&
		matrix[row][col] == path[visited_path_length] && !visited[row][col]) {
		visited[row][col] = true;
		++visited_path_length;

		has_path = has_path_in_matrix_core(matrix, path, visited, visited_path_length, row - 1, col) ||
				   has_path_in_matrix_core(matrix, path, visited, visited_path_length, row, col + 1) ||
			       has_path_in_matrix_core(matrix, path, visited, visited_path_length, row + 1, col) ||
			       has_path_in_matrix_core(matrix, path, visited, visited_path_length, row, col - 1);
		if (!has_path) {
			--visited_path_length;
			visited[row][col] = false;
		}
	}

	return has_path;
}

bool has_path_in_matrix(const vector<vector<char>>& matrix, const string& path) {
	int rows = matrix.size();
	int cols = matrix[0].size();
	if (rows == 0 || path.length() == 0) return false;
	vector<bool> visited_row(cols, false);
	vector<vector<bool>> visited(rows, visited_row);
	int visited_path_length = 0;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (has_path_in_matrix_core(matrix, path, visited, visited_path_length, i, j))
				return true;
		}
	}

	return false;
}

int main() {
	int rows, cols;
	cin >> rows >> cols;

	cout << "Please input a matrix: " << endl;

	vector<char> matrix_row(cols, '\0');
	vector<vector<char>> matrix(rows, matrix_row);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cin >> matrix[i][j];
		}
	}

	cout << "Please input a path: " << endl;

	string path;
	cin >> path;

	bool has_path = has_path_in_matrix(matrix, path);

	cout << boolalpha << has_path << endl;

	return 0;
}