#include <vector>
#include <iostream>

using namespace std;

bool is_odd(int number) {
	return (number & 1) == 1;
}

bool is_negative(int number) {
	return number < 0;
}

void adjust_array(vector<int>& arr, bool (*func)(int number)) {
	if (arr.size() == 0) return;

	int begin = 0, end = arr.size() - 1;
	while (begin < end) {
		while (!func(arr[end]) && begin < end)
			--end;
		while (func(arr[begin]) && begin < end)
			++begin;
		if (begin < end)
			swap(arr[begin], arr[end]);
	}
}

int main() {
	vector<int> arr = {1, 2, 3, 4, 5, 6};
	for (int ele : arr)
		cout << ele << ' ';
	cout << endl;

	adjust_array(arr, is_odd);
	for (int ele : arr)
		cout << ele << ' ';
	cout << endl;

	vector<int> arr1 = {-1, 2, -3, 4, 5, -6};
	for (int ele : arr1)
		cout << ele << ' ';
	cout << endl;

	adjust_array(arr1, is_negative);
	for (int ele : arr1)
		cout << ele << ' ';
	cout << endl;

	return 0;
}