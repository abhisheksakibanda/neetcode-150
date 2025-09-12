// 167. Two Sum II - Input Array Is Sorted (https://leetcode.com/problems/two-sum-ii-input-array-is-sorted)

#include <bits/stdc++.h>
#include "PrettyPrinter.h"

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;

        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target)
                return {left + 1, right + 1};
            if (sum < target)
                left++;
            else if (sum > target)
                right--;
        }
        return {};
    }
};

int main() {
    vector testCases = {
        make_pair<vector<int>, int>({1, 3, 4, 6, 8, 10, 13}, 13),
        make_pair<vector<int>, int>({0, 0, 3, 4}, 0),
        make_pair<vector<int>, int>({2, 7, 11, 15}, 9),
        make_pair<vector<int>, int>({2, 3, 4}, 6),
        make_pair<vector<int>, int>({-1, 0}, -1),
    };

    for (int i = 0; i < testCases.size(); ++i) {
        auto& testCase = testCases[i];
        vector<int> result = Solution().twoSum(testCase.first, testCase.second);
        cout << i + 1 << ": " << PrintElement(testCase) << " -> " << PrintContainer(result) << endl;
    }
    return 0;
}
