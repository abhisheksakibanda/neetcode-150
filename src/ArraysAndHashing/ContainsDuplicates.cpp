// 217. Contains Duplicate (https://leetcode.com/problems/contains-duplicate)

#include <bits/stdc++.h>
#include "../utils/PrettyPrinter.h"

using namespace std;

class Solution {
public:
    static bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for (int& num : nums) {
            if (seen.count(num))
                return true;
            seen.emplace(num);
        }
        return false;
    }
};

int main() {
    vector<vector<int>> testCases = {
        {1, 2, 3, 1},
        {1, 2, 3, 4},
        {1, 1, 1, 3, 3, 4, 3, 2, 4, 2}
    };

    for (int i = 0; i < testCases.size(); ++i) {
        cout << i + 1 << ": " << PrintContainer(testCases[i]) << " -> " << (Solution::containsDuplicate(testCases[i])
                                                                                     ? "true"
                                                                                     : "false") << endl;
    }
    return 0;
}
