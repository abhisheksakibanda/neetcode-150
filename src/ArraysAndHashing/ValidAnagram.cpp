// 242. Valid Anagram (https://leetcode.com/problems/valid-anagram)

#include <bits/stdc++.h>
#include "../utils/PrettyPrinter.h"

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;

        unordered_map<char, int> charMap;

        for (char& letter : s)
            charMap[letter]++;

        for (char& letter : t) {
            if (charMap[letter] == 0)
                return false;
            --charMap[letter];
        }
        return true;
    }
};

int main() {
    vector<pair<string, string>> testCases = {
        make_pair("anagram", "nagaram"),
        make_pair("rat", "car"),
    };

    for (int i = 0; i < testCases.size(); ++i) {
        auto& testCase = testCases[i];
        bool result = Solution().isAnagram(testCase.first, testCase.second);
        cout << i + 1 << ": " << PrintElement(testCase) << " -> " << (result ? "true" : "false") << endl;
    }
    return 0;
}