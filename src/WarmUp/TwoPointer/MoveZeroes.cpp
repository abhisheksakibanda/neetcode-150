// 283. Move Zeroes (http://leetcode.com/problems/move-zeroes)

#include <bits/stdc++.h>
#include "PrettyPrinter.h"

using namespace std;

class Solution {
public:
    vector<int> moveZeroes(vector<int> nums) {
        int nextNonZero = 0;
        for (int i = 0; i < nums.size(); ++i) {
            // Tracks zeroes
            if (nums[i] != 0) {
                swap(nums[i], nums[nextNonZero]);
                nextNonZero++;
            }
        }

        return nums;
    }
};

int main() {
    vector<vector<int>> testCases = {
        {1, 0, 4, 0, 3, 0, 1},
        {0, 0, 1},
        {1, 2, 3},
        {0, 0, 0}
    };

    for (int i = 0; i < testCases.size(); ++i) {
        vector<int>& testCase = testCases[i];
        vector<int> result = Solution().moveZeroes(testCase);
        cout << i + 1 << ": " << PrintElement(testCase) << " -> " << PrintElement(result) << endl;
    }
    return 0;
}
