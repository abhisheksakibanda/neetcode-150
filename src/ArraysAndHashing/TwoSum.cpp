//
// Created by abhis on 31-08-2025.
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>

using namespace std;

class Solution {
public:
    static vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;

        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (seen.count(complement))
                return {i, seen[complement]};
            seen[nums[i]] = i;
        }

        return {};
    }
};

int main() {
    vector testCases = {
        make_pair<vector<int>, int>({2, 7, 11, 15}, 9),
        make_pair<vector<int>, int>({3, 2, 4}, 6),
        make_pair<vector<int>, int>({3, 3}, 6)
    };

    for (int i = 0; i < testCases.size(); ++i) {
        auto& testCase = testCases[i];
        vector<int> result = Solution::twoSum(testCase.first, testCase.second);
        cout << i + 1 << ": " << "[ ";
        for (auto& num : result)
            cout << num << " ";
        cout << "]" << endl;
    }
    return 0;
}
