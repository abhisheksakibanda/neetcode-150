// 1249. Minimum Remove to Make Valid Parentheses (https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses)

#include <bits/stdc++.h>
#include "../utils/PrettyPrinter.h"

using namespace std;

class Solution {
public:
    static string minRemoveToMakeValid(string s) {
        stack<char> seen;
        string result;

        for (char letter : s) {
            if (letter == '(') {
                seen.push(')');
                result += letter;
            }
            else if (letter == ')') {
                if (seen.empty())
                    continue;
                result += ')';
                seen.pop();
            }
            else {
                result += letter;
            }
        }

        if (find(result.begin(), result.end(), ')') == result.end()) return "";
        return result;
    }
};

int main() {
    vector<string> testCases = {"lee(t(c)o)de)", "a)b(c)d", "))(("};

    for (int i = 0; i < testCases.size(); ++i) {
        string& testCase = testCases[i];
        string result = Solution::minRemoveToMakeValid(testCase);
        cout << i + 1 << ": " << PrintElement(testCase) << " -> " << PrintElement(result) << endl;
    }

    return 0;
}
