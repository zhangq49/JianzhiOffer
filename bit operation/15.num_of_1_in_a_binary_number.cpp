#include <iostream>

using namespace std;

int get_num_of_1(int number) {
	int count = 0;
	while (number) {
		++count;
		number = (number - 1) & number;
	}

	return count;
}

int main() {
	int number;
	cin >> hex >> number;
	cout << get_num_of_1(number) << endl;

	return 0;
}