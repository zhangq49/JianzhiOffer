#include <iostream>

using namespace std;

#define LEN 1001
int seq[LEN];
int max_len[LEN];
int n;

int get_max_len_of_subseq() {
	int res = 0;
	max_len[1] = 1;
	for (int i = 2; i <= n; i++) {
		max_len[i] = 0;
		for (int j = 1; j < i; j++) {
			if (seq[i] > seq[j] && max_len[i] < max_len[j])
				max_len[i] = max_len[j];
		}
		max_len[i]++;
	}
	for (int i = 1; i <= n; i++) {
		if (res < max_len[i])
			res = max_len[i];
	}

	return res;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> seq[i];
	}

	cout << get_max_len_of_subseq() << endl;
	
	return 0;
}