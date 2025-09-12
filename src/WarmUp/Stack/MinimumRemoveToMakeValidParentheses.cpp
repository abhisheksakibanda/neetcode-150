// 1249. Minimum Remove to Make Valid Parentheses (https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses)

#include <bits/stdc++.h>
#include "../PrettyPrinter.h"

using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
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

        int open_needed = 0;
        string out;
        out.reserve(result.size());
        for (auto it = result.rbegin(); it != result.rend(); ++it) {
            char c = *it;
            if (c == ')') {
                ++open_needed;
                out.push_back(c);
            } else if (c == '(') {
                if (open_needed > 0) {
                    --open_needed;
                    out.push_back(c);
                }
            } else {
                out.push_back(c);
            }
        }
        std::reverse(out.begin(), out.end());
        return out;
    }
};

int main() {
    vector<string> testCases = {"lee(t(c)o)de)", "a)b(c)d", "))((", "(h(e)ll(o)"};

    for (int i = 0; i < testCases.size(); ++i) {
        string& testCase = testCases[i];
        string result = Solution().minRemoveToMakeValid(testCase);
        cout << i + 1 << ": " << PrintElement(testCase) << " -> " << PrintElement(result) << endl;
    }

    return 0;
}
