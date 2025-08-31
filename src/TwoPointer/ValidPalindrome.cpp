//
// Created by abhis on 31-08-2025.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    static bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;

        while (left < right) {
            if (!isalnum(s[left])) {
                ++left;
                continue;
            }
            if (!isalnum(s[right])) {
                --right;
                continue;
            }
            if (tolower(s[left]) != tolower(s[right]))
                return false;
            ++left;
            --right;
        }
        return true;
    }
};

int main() {
    vector<string> testCases = {
        "A man, a plan, a canal: Panama",
        "race a car",
        " "
    };

    for (int i = 0; i < testCases.size(); ++i) {
        bool result = Solution::isPalindrome(testCases[i]);
        cout << i + 1 << ": " << (result ? "true" : "false") << endl;
    }
    return 0;
}