#include <iostream>

using namespace std;

int sum_recursively(int n) {
	if (n <= 1) return n;

	return sum_recursively(n - 1) + n;
}

int sum_iteratively(int n) {
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += i;
	}

	return sum;
}

int main() {
	cout << sum_recursively(10) << endl;
	cout << sum_iteratively(10) << endl;

	return 0;
}