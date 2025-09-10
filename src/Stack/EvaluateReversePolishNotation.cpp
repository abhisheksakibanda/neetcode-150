// 150. Evaluate Reverse Polish Notation (https://leetcode.com/problems/evaluate-reverse-polish-notation)

#include <bits/stdc++.h>
#include "../utils/PrettyPrinter.h"

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> operands;

        for (string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int operand2 = operands.top(); operands.pop();
                int operand1 = operands.top(); operands.pop();

                switch (token[0]) {
                    case '+': operands.push(operand1 + operand2); break;
                    case '-': operands.push(operand1 - operand2); break;
                    case '*': operands.push(operand1 * operand2); break;
                    case '/': operands.push(operand1 / operand2); break;
                }
            } else {
                operands.push(stoi(token));
            }
        }

        return operands.top();
    }
};

int main() {
    vector<vector<string>> testCases = {
        {"2", "1", "+", "3", "*"},
        {"4", "13", "5", "/", "+"},
        {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"}
    };

    for (int i = 0; i < testCases.size(); ++i) {
        auto testCase = testCases[i];
        int result = Solution().evalRPN(testCase);
        cout << i + 1 << ": " << PrintContainer(testCase) << " -> " << result << endl;
    }

    return 0;
}
