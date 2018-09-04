#include <iostream>
#include <cmath>

using namespace std;

double get_power_unsigned(double base, unsigned int exp) {
	if (exp == 0) return 1;
	if (exp == 1) return base;

	double res = get_power_unsigned(base, exp >> 1);
	res *= res;
	if (exp & 1)
		res *= base;

	return res;
}

int g_valid_input = true;
double get_power(double base, int exp) {
	if (fabs(base - 0.0) < 1e-15 && exp < 0) {
		g_valid_input = false;
		return 0.0;
	}

	unsigned int unsigned_exp = abs(exp);

	double res = get_power_unsigned(base, unsigned_exp);
	if (exp < 0)
		res = 1 / res;

	return res;
}

int main(int argc, char const *argv[])
{
	cout << get_power(0, -1) << endl;
	cout << get_power(2.5, 2) << endl;
	return 0;
}