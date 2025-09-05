// 11. Container With Most Water (https://leetcode.com/problems/container-with-most-water)

#include <bits/stdc++.h>
#include "../utils/PrettyPrinter.h"

using namespace std;

class Solution {
public:
    static int maxArea(vector<int>& height) {
        int maxVolume = 0;
        int left = 0, right = height.size() - 1;

        while (left < right) {
            int capacity = min(height[left], height[right]);
            int volume = (right - left) * capacity;

            if (volume > maxVolume) {
                maxVolume = volume;
            }

            if (capacity == height[left])
                left++;
            else
                right--;
        }
        return maxVolume;
    }
};

int main() {
    vector<vector<int>> testCases = {{1, 8, 6, 2, 5, 4, 8, 3, 7}, {1, 1}};

    for (int i = 0; i < testCases.size(); ++i) {
        auto testCase = testCases[i];
        int result = Solution::maxArea(testCase);
        cout << i + 1 << ": " << PrintContainer(testCase) << " -> " << result << endl;
    }

    return 0;
}
