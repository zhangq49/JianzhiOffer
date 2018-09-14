#include <iostream>
#include <vector>

using namespace std;

bool VerifySquenceOfBSTCore(vector<int>& sequence) {
    int len = sequence.size();
    if (len <= 1)
        return true;

    int root = sequence[len - 1];
    int i;
    vector<int> left, right;
    for (i = 0; i < len - 1; i++) {
        if (sequence[i] > root)
            break;
        left.push_back(sequence[i]);
    }
    for (int j = i; j < len - 1; j++) {
        if (sequence[j] < root)
            return false;
        right.push_back(sequence[j]);
    }

    return VerifySquenceOfBST(left) && VerifySquenceOfBST(right);
}

bool VerifySquenceOfBST(vector<int> sequence) {
    if (sequence.size() == 0)
        return false;
    return VerifySquenceOfBSTCore(sequence);
}

