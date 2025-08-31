//
// Created by abhis on 31-08-2025.
//
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    static int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
            return 0;
        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 1;

        for (int num : s) {
            if (s.find(num - 1) == s.end()) {
                int currentNum = num;
                int currentStreak = 1;

                while (s.find(currentNum + 1) != s.end()) {
                    currentNum++;
                    currentStreak++;
                }
                longest = max(longest, currentStreak);
            }
        }
        return longest;
    }
};

int main() {
    vector<vector<int>> testCases = {
        {100, 4, 200, 1, 3, 2},
        {0, 3, 7, 2, 5, 8, 4, 6, 0, 1},
        {1, 0, 1, 2}
    };

    for (int i = 0; i < testCases.size(); ++i) {
        cout << i + 1 << ": " << Solution::longestConsecutive(testCases[i]) << endl;
    }
    return 0;
}