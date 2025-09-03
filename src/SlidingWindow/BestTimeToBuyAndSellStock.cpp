#include <bits/stdc++.h>
#include "../utils/PrettyPrinter.h"

using namespace std;

class Solution {
public:
    static int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int price : prices) {
            minPrice = min(minPrice, price);
            maxProfit = max(maxProfit, price - minPrice);
        }

        return maxProfit;
    }
};

int main() {
    vector<vector<int>> testCases = {{7, 1, 5, 3, 6, 4}, {7, 6, 4, 3, 1}, {1, 2}, {1, 2, 4, 2, 5, 7, 2, 4, 9, 0, 9}};

    for (int i = 0; i < testCases.size(); ++i) {
        auto testCase = testCases[i];
        int result = Solution::maxProfit(testCase);
        cout << i + 1 << ": " << PrintContainer(testCase) << " -> " << result << endl;
    }

    return 0;
}
