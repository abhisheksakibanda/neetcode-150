#include<bits/stdc++.h>
#include "../utils/PrettyPrinter.h"

using namespace std;

class Solution {
public:
    static vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqCount;

        for (auto& num : nums) {
            freqCount[num]++;
        }

        vector<vector<int>> buckets(nums.size() + 1);
        for (auto& [num, count] : freqCount) {
            buckets[count].push_back(num);
        }

        vector<int> result;

        for (int f = buckets.size() - 1; f >= 0; --f) {
            if (!buckets[f].empty()) {
                for (auto num : buckets[f]) {
                    result.push_back(num);
                    if (result.size() == k) {
                        return result;
                    }
                }
            }
        }
        return {-1};
    }
};

int main() {
    vector testCases = {
        make_pair<vector<int>, int>({1, 1, 1, 2, 2, 3}, 2),
        make_pair<vector<int>, int>({1}, 1),
        make_pair<vector<int>, int>({1, 2, 1, 2, 1, 2, 3, 1, 3, 2}, 2)
    };

    for (int i = 0; i < testCases.size() - 1; ++i) {
        pair<vector<int>, int> testCase = testCases[i];
        vector<int> result = Solution().topKFrequent(testCase.first, testCase.second);
        cout << i + 1 << ": " << PrintElement(testCase) << " -> " << PrintElement(result) << endl;
    }
}
