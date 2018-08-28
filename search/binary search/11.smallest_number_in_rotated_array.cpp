#include <iostream>
#include <vector>

using namespace std;

int get_smallest_number(vector<int>& arr) {
	if (arr.size() == 0) return 0;

	int begin = 0, end = static_cast<int>(arr.size()) - 1;
	int middle = begin; // if original sorted array, e.g [1 2 3 4 5], then return first element

	while (arr.at(begin) >= arr.at(end)) {
		if (end - begin == 1) {
			middle = end;
			break;
		}

		middle = (end + begin) / 2;

		// if arr[begin] == arr[end] == arr[middle], e.g [1 0 1 1 1] or [1 1 1 0 1] or [1],
		// we must conduct sequential searching.
		if (arr.at(begin) == arr.at(end) && arr.at(begin) == arr.at(middle)) {
			int smallest_number = arr.at(0);
			for (int i = 1; i < arr.size(); i++) {
				if (arr.at(i) < smallest_number)
					smallest_number = arr.at(i);
			}
			return smallest_number;
		}

		if (arr.at(middle) >= arr.at(begin))
			begin = middle;
		else if (arr.at(middle) <= arr.at(end))
			end = middle;
	}

	return arr.at(middle);
}

int main() {
	int n, input_number, smallest_number;
	vector<int> arr;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input_number;
		arr.push_back(input_number);
	}

	smallest_number = get_smallest_number(arr);

	cout << smallest_number << endl;

	return 0;
}