//
// Created by abhis on 31-08-2025.
//
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <array>
#include "../utils/PrettyPrinter.h"

using namespace std;

class Solution {
public:
    static vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> countMap;

        for (auto& word : strs) {
            string key;
            array<int, 26> count = {0};

            for (char& letter : word)
                count[letter - 'a']++;

            for (auto& freq : count)
                key += to_string(freq) + "|";

            countMap[key].push_back(word);
        }

        vector<vector<string>> result;
        for (auto& entry : countMap)
            result.push_back(entry.second);
        return result;
    }
};

int main() {
    vector<vector<string>> testCases = {
        {"eat", "tea", "tan", "ate", "nat", "bat"},
        {""},
        {"a"}
    };

    for (int i = 0; i < testCases.size(); ++i) {
        auto& testCase = testCases[i];
        vector result = Solution::groupAnagrams(testCase);
        cout << i + 1 << ": " << PrintContainer(testCase) << " -> " << PrintContainer(result) << endl;
    }
    return 0;
}
