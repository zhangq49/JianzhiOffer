#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define LEN 1000
char str1[LEN];
char str2[LEN];
int len1, len2;
int max_len[LEN][LEN];

int get_max_common_len() {
	len1 = strlen(str1);
	len2 = strlen(str2);

	for (int i = 0; i <= len1; i++) {
		max_len[i][0] = 0;
	}
	for (int i = 0; i <= len2; i++) {
		max_len[0][i] = 0;
	}

	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			if (str1[i - 1] == str2[j - 1])
				max_len[i][j] = max_len[i - 1][j - 1] + 1;
			else
				max_len[i][j] = max(max_len[i][j - 1], max_len[i - 1][j]);
		}
	}

	return max_len[len1][len2];
}

int main() {
	cin >> str1 >> str2;
	cout << get_max_common_len() << endl;
	return 0;
}