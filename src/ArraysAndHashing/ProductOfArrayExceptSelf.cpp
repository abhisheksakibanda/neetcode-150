//
// Created by abhis on 31-08-2025.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> result(n);
        vector prefix(n, 1);
        vector suffix(n, 1);

        // Prefix Pass
        prefix[0] = 1;
        for (int i = 1; i < n; i++)
            prefix[i] = prefix[i - 1] * nums[i - 1];

        // Suffix Pass
        suffix[n - 1] = 1;
        for (int i = n - 2; i >= 0; --i)
            suffix[i] = suffix[i + 1] * nums[i + 1];

        for (int i = 0; i < n; ++i)
            result[i] = prefix[i] * suffix[i];

        return result;
    }
};

int main() {
    vector<vector<int>> testCases = {{1, 2, 3, 4}, {-1, 1, 0, -3, 3}};
    for (int i = 0; i < testCases.size(); ++i) {
        vector<int> result = Solution::productExceptSelf(testCases[i]);
        cout << i + 1 << ": " << "[ ";
        for (auto& num : result)
            cout << num << " ";
        cout << "]" << endl;
    }
    return 0;
}
