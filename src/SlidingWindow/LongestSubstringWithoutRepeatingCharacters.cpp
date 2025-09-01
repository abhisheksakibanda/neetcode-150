#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#include "../utils/PrettyPrinter.h"

using namespace std;

class Solution {
public:
    static int lengthOfLongestSubstring(string s) {
        int maxLength = 0, i = 0;
        unordered_map<char, int> seen;

        for (int j = 0; j < s.length(); ++j) {
            if (seen.find(s[j]) != seen.end()) {
                i = max(i, seen[s[j]] + 1);
            }
            seen[s[j]] = j;
            maxLength = max(maxLength, j - i + 1);
        }
        return maxLength;
    }
};

int main() {
    vector<string> testCases = {"abcabcbb", "bbbbb", "pwwkew"};

    for (int i = 0; i < testCases.size(); ++i) {
        auto& testCase = testCases[i];
        int result = Solution::lengthOfLongestSubstring(testCase);
        cout << i + 1 << ": " << PrintContainer(testCase) << " -> " << result << endl;
    }

    return 0;
}
