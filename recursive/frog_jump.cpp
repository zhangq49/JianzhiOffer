#include <iostream>
#include <stack>
#include <ctime>
using namespace std;

long long fibonacci_recursive(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

long long fibonacci_iterative(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	long long num1 = 0, num2 = 1, tmp;
	for (int i = 2; i <= n; i++) {
		tmp = num2;
		num2 = num1 + num2;
		num1 = tmp;
	}
	return num2;
}

int main() {
	int num = 43;

	clock_t start_time, end_time;
	
	// fibonacci_iterative
	start_time = clock();

	cout << fibonacci_iterative(num) << endl;

	end_time = clock();
	cout << "The run time of fibonacci_iterative is " << (double)(end_time - start_time)/ CLOCKS_PER_SEC << "s" << endl;

	// fibonacci_recursive
	start_time = clock();

	cout << fibonacci_recursive(num) << endl;

	end_time = clock();
	cout << "The run time of fibonacci_recursive is " << (double)(end_time - start_time)/ CLOCKS_PER_SEC << "s" << endl;

	return 0;
}
