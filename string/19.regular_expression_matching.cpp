#include <iostream>
using namespace std;

bool is_regular_match_core(char* pattern, char* str) {
	if (*pattern == '\0' && *str == '\0')
		return true;
	if (*pattern == '\0' && *str != '\0')
		return false;

	if (*(pattern + 1) == '*') {
		if (*pattern == *str || (*pattern == '.' && *str != '\0'))
			return is_regular_match_core(pattern + 2, str + 1) ||
				   is_regular_match_core(pattern, str + 1) ||
				   is_regular_match_core(pattern + 2, str);
		else
			return is_regular_match_core(pattern + 2, str);
	}

	if (*pattern == *str || (*pattern == '.' && *str != '\0'))
		return is_regular_match_core(pattern + 1, str + 1);

	return false;
}

bool is_regular_match(char* pattern, char* str) {
	if (pattern == nullptr || str == nullptr)
		return false;

	return is_regular_match_core(pattern, str);
}

int main() {
	char pattern[] = "a.a";
	char str[] = "aa";
	cout << boolalpha << is_regular_match(pattern, str) << endl;

	return 0;
}
