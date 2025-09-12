// 74. Search a 2D Matrix (https://leetcode.com/problems/search-a-2d-matrix)

#include<bits/stdc++.h>
#include "PrettyPrinter.h"

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;

        int m = matrix.size();
        int n = matrix[0].size();

        int left = 0, right = m * n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int midValue = matrix[mid / n][mid % n]; // map 1D index to 2D

            if (midValue == target) return true;

            if (midValue < target) left = mid + 1;
            else right = mid - 1;
        }

        return false;
    }
};

int main() {
    vector testCases = {
        make_pair<vector<vector<int>>, int>(
            {
                {1, 3, 5, 7},
                {10, 11, 16, 20},
                {23, 30, 34, 60}
            }, 3
        ),
        make_pair<vector<vector<int>>, int>(
            {
                {1, 3, 5, 7},
                {10, 11, 16, 20},
                {23, 30, 34, 60}
            }, 13
        ),
    };

    for (int i = 0; i < testCases.size(); ++i) {
        pair<vector<vector<int>>, int> testCase = testCases[i];
        bool result = Solution().searchMatrix(testCase.first, testCase.second);
        cout << i + 1 << ": " << PrintElement(testCase) << " -> " << PrintElement(result) << endl;
    }
}
