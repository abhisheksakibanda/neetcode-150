// 704. Binary Search (https://leetcode.com/problems/binary-search)

#include <bits/stdc++.h>
#include "../utils/PrettyPrinter.h"

using namespace std;

class Solution {
public:
    static int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;

            if (target > nums[mid])
                left = mid + 1;
            else if (target < nums[mid])
                right = mid - 1;
        }
        return -1;
    }
};

int main() {
    vector testCases = {
        make_pair<vector<int>, int>({-1, 0, 3, 5, 9, 12}, 9),
        make_pair<vector<int>, int>({-1, 0, 3, 5, 9, 12}, 2),
        make_pair<vector<int>, int>({2, 5}, 5)
    };

    for (int i = 0; i < testCases.size(); ++i) {
        auto testCase = testCases[i];
        int result = Solution::search(testCase.first, testCase.second);
        cout << i + 1 << ": " << PrintElement(testCase) << " -> " << result << endl;
    }

    return 0;
}
