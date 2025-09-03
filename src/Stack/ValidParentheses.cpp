#include <bits/stdc++.h>
#include "../utils/PrettyPrinter.h"

using namespace std;

class Solution {
public:
    static bool isValid(string s) {
        stack<char> charStack;
        for (char& c : s) {
            if (c == '(') charStack.push(')');
            else if (c == '{') charStack.push('}');
            else if (c == '[') charStack.push(']');
            else {
                if (charStack.empty() || charStack.top() != c) return false;
                charStack.pop();
            }
        }
        return charStack.empty();
    }
};

int main() {
    vector<string> testCases = {"()", "()[]{}", "(]", "([])", "([)]"};

    for (int i = 0; i < testCases.size(); ++i) {
        string& testCase = testCases[i];
        const bool result = Solution::isValid(testCase);
        cout << i + 1 << ": " << PrintElement(testCase) << " -> " << (result ? "true" : "false") << endl;
    }

    return 0;
}
