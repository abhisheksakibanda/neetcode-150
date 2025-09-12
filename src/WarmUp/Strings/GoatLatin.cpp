#include <bits/stdc++.h>
#include "../../utils/PrettyPrinter.h"

using namespace std;

class Solution {
public:
    string toGoatLatin(string sentence) {
        string result;
        int wordIndex = 1, start = 0, n = sentence.size();

        while (start < n) {
            int end = start;
            while (end < n && sentence[end] != ' ') end++;

            string word = sentence.substr(start, end - start);

            char first = tolower(word[0]);
            if (first == 'a' || first == 'e' || first == 'i' || first == 'o' || first == 'u') {
                word += "ma";
            } else {
                word = word.substr(1) + word[0] + "ma";
            }

            word += string(wordIndex, 'a');
            result += word + ' ';

            wordIndex++;
            start = end + 1;
        }

        if (!result.empty()) result.pop_back(); // remove trailing space
        return result;
    }
};


int main() {
    vector<string> testCases = {"I speak Goat Latin", "The quick brown fox jumped over the lazy dog",};

    for (int i = 0; i < testCases.size(); ++i) {
        string testCase = testCases[i];
        string result = Solution().toGoatLatin(testCase);
        cout << i + 1 << ": " << PrintElement(testCase) << " -> " << PrintElement(result) << endl;
    }
}
