#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    static void countCharacterFrequency(const string& str) {
        unordered_map<char, int> charMap;
        for (char ch : str) {
            charMap[ch] += 1;
        }

        for (auto &[letter, count] : charMap) {
            cout << letter << ": " << count << endl;
        }
    }
};

int main() {
    string str = "interview";
    Solution::countCharacterFrequency(str);
}
