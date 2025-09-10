// 75. Sort Colors (http://leetcode.com/problems/sort-colors)

#include<bits/stdc++.h>
#include "../../utils/PrettyPrinter.h"

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, i = 0;

        while (i <= right) {
            if (nums[i] == 0) {
                swap(nums[i], nums[left]);
                left++;
                i++;
            } else if (nums[i] == 2) {
                swap(nums[right], nums[i]);
                right--;
            } else {
                i++;
            }
        }
    }
};

int main() {
    vector<vector<int>> testCases = {{2, 0, 2, 1, 1, 0}, {2, 0, 1}};

    for (int i = 0; i < testCases.size() - 1; ++i) {
        vector<int>& testCase = testCases[i];
        cout << i + 1 << ": " << PrintElement(testCase) << " -> ";
        Solution().sortColors(testCase);
        cout << PrintElement(testCase) << endl;
    }
}
