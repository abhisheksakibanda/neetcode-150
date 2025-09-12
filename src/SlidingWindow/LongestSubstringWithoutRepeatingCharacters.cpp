// 3. Longest Substring Without Repeating Characters (https://leetcode.com/problems/longest-substring-without-repeating-characters)

#include <bits/stdc++.h>
#include "PrettyPrinter.h"

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0, start = 0;
        unordered_map<char, int> seen;

        for (int end = 0; end < s.length(); ++end) {
            if (seen.find(s[end]) != seen.end()) {
                start = max(start, seen[s[end]] + 1);
            }
            seen[s[end]] = end;
            maxLength = max(maxLength, end - start + 1);
        }
        return maxLength;
    }
};

int main() {
    vector<string> testCases = {"abcabcbb", "bbbbb", "pwwkew"};

    for (int i = 0; i < testCases.size(); ++i) {
        auto& testCase = testCases[i];
        int result = Solution().lengthOfLongestSubstring(testCase);
        cout << i + 1 << ": " << PrintContainer(testCase) << " -> " << result << endl;
    }

    return 0;
}
