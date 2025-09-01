//
// Created by abhis on 31-08-2025.
//
#include <iostream>
#include <vector>
#include <map>

#include "../utils/PrettyPrinter.h"

using namespace std;

class Solution {
public:
    static vector<int> twoSum(vector<int>& numbers, int target) {
        map<int, int> freqMap;

        for (int i = 0; i < numbers.size(); ++i) {
            int complement = target - numbers[i];
            if (freqMap.count(complement))
                return {freqMap[complement], i + 1};
            freqMap[numbers[i]] = i + 1;
        }
        return {};
    }
};

int main() {
    vector testCases = {
        make_pair<vector<int>, int>({2, 7, 11, 15}, 9),
        make_pair<vector<int>, int>({2, 3, 4}, 6),
        make_pair<vector<int>, int>({-1, 0}, -1),
    };

    for (int i = 0; i < testCases.size(); ++i) {
        auto& testCase = testCases[i];
        vector<int> result = Solution::twoSum(testCase.first, testCase.second);
        cout << i + 1 << ": " << PrintElement(testCase) << " -> " << PrintContainer(result) << endl;
    }
    return 0;
}
