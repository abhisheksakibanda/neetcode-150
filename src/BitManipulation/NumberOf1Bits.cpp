// 191. Number of 1 Bits (https://leetcode.com/problems/number-of-1-bits)

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static int hammingWeight(int n) {
        int hammingWeight = 0;

        while (n) {
            n &= n - 1;
            ++hammingWeight;
        }

        return hammingWeight;
    }
};

int main() {
    vector testCases = {11, 128, 2147483645};

    for (int i = 0; i < testCases.size(); ++i) {
        auto testCase = testCases[i];
        int result = Solution::hammingWeight(testCase);
        cout << i + 1 << ": " << testCase << " -> " << result << endl;
    }

    return 0;
}
