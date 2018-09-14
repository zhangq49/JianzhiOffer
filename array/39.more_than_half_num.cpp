#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int MoreThanHalfNum_Solution1(vector<int> numbers) {
        if (numbers.size() == 0)
            return 0;
        
        int numberNeeded = numbers[0];
        int count = 1;
        for (int i = 1; i < numbers.size(); i++) {
            if (numbers[i] != numberNeeded) {
                if (count == 0) {
                    numberNeeded = numbers[i];
                    count = 1;
                } else
                    --count;
            } else
                ++count;
        }
        
        count = 0;
        for (auto elem : numbers) {
            if (elem == numberNeeded)
                ++count;
        }
        
        if (count > numbers.size() / 2)
            return numberNeeded;
        else
            return 0;
    }

int VectorPartition(vector<int>& numbers, int begin, int end) {
    int pivot = numbers[begin];
    int originalBegin = begin;

    while (begin < end) {
        while (numbers[end] <= pivot && begin < end)
            --end;

        while (numbers[begin] >= pivot && begin < end)
            ++begin;

        if (begin < end) {
            swap(numbers[begin], numbers[end]);
        }
    }

    swap(numbers[originalBegin], numbers[begin]);

    return begin;
}

int GetKthBigNumber(vector<int>& numbers, int begin, int end, int k) {
    int vectorSize = numbers.size();
    int index = VectorPartition(numbers, begin, end);

    if (index == k - 1)
        return numbers[index];

    if (index > k - 1)
        return GetKthBigNumber(numbers, begin, index - 1, k); 
    else
        return GetKthBigNumber(numbers, index + 1, end, k);
}

int MoreThanHalfNum_Solution(vector<int> numbers) {
    int vectorSize = numbers.size();
    if (vectorSize == 0)
        return 0;

    int middleNumber = GetKthBigNumber(numbers, 0, vectorSize - 1, vectorSize >> 1);

    int count = 0;
    for (auto elem : numbers) {
        if (elem == middleNumber)
            ++count;
    }

    if (count > numbers.size() / 2)
        return middleNumber;
    else
        return 0;
}

int main() {
    vector<int> numbers = {2,2,2,2,2,3,4,2,2,2,2,2,2,2,1,2,3,2,2,2,5,2,2,2,2,2,3,4,2,2,2,2,2,2,2,1,2,3,2,2,2,5,4,2,2,7,8,9,3,7,4,8};
    cout << MoreThanHalfNum_Solution(numbers) << endl;

    return 0;
}
