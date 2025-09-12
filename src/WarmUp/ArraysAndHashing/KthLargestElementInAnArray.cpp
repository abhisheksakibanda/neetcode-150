#include<bits/stdc++.h>
#include "../PrettyPrinter.h"

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k)
                minHeap.pop();
        }
        return minHeap.top();
    }
};

int main() {
    vector testCases = {
        make_pair<vector<int>, int>({}, 0)
    };

    for (int i = 0; i < testCases.size(); ++i) {
        pair<vector<int>, int> testCase = testCases[i];
        int result = Solution().findKthLargest(testCase.first, testCase.second);
        cout << i + 1 << ": " << PrintElement(testCase) << " -> " << PrintElement(result) << endl;
    }
}
