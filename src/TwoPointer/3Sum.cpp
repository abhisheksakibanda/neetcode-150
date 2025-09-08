// 15. 3Sum (https://leetcode.com/problems/3sum)

#include <bits/stdc++.h>
#include "../utils/PrettyPrinter.h"

using namespace std;

class Solution {
public:
    static vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end()); // O(n log n)

        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // skip duplicate pivot

            int left = i + 1, right = nums.size() - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});

                    // Skip duplicates for left and right
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    left++;
                    right--;
                }
                else if (sum < 0) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }
        return result;
    }
};

int main() {
    vector<vector<int>> testCases = {
        {-1, 0, 1, 2, -1, -4},
        {0, 1, 1},
        {0, 0, 0},
        {0, 0, 0, 0},
        {-100, -70, -60, 110, 120, 130, 160}
    };

    for (int i = 0; i < testCases.size(); ++i) {
        vector<int>& testCase = testCases[i];
        vector<vector<int>> result = Solution::threeSum(testCase);
        cout << i + 1 << ": " << PrintContainer(testCase) << " -> " << PrintContainer(result) << endl;
    }

    return 0;
}
