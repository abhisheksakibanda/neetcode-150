#include <bits/stdc++.h>
#include "../utils/PrettyPrinter.h"

using namespace std;

class Solution {
public:
    static string encode(vector<string>& strs) {
        string result;

        for (string& word : strs) {
            result += to_string(word.size()) + "#" + word;
        }
        return result;
    }

    static vector<string> decode(string s) {
        vector<string> wordList;
        size_t i = 0;
        while (i < s.size()) {
            int length = 0;
            while (s[i] != '#') {
                length = length * 10 + s[i] - '0';
                i++;
            }
            i++;
            wordList.push_back(s.substr(i, length));
            i += length;
        }
        return wordList;
    }
};

int main() {
    vector<vector<string>> testCases = {{"neet", "code", "love", "you"}, {"we", "say", ":", "yes"}, {"we","say",":","yes","!@#$%^&*()"}};

    for (int i = 0; i < testCases.size(); ++i) {
        vector<string> testCase = testCases[i];
        string encodedResult = Solution::encode(testCase);
        vector<string> decodedResult = Solution::decode(encodedResult);
        cout << i + 1 << ": " << PrintContainer(testCase) << " -> " << "Encoded: " << encodedResult << "; Decoded: " <<
            PrintContainer(decodedResult) << endl;
    }

    return 0;
}
