// 36. Valid Sudoku (https://leetcode.com/problems/valid-sudoku)

#include <bits/stdc++.h>
#include "PrettyPrinter.h"

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9][9] = {0};
        int cols[9][9] = {0};
        int boxes[9][9] = {0};

        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {
                char value = board[row][col];

                if (value == '.')
                    continue;

                int num = value - '1';
                int boxIndex = (row / 3) * 3 + (col / 3);

                if (rows[row][num] || cols[col][num] || boxes[boxIndex][num])
                    return false;

                rows[row][num] = cols[col][num] = boxes[boxIndex][num] = 1;
            }
        }
        return true;
    }
};

int main() {
    vector<vector<vector<string>>> testCases = {
        {
            {"5", "3", ".", ".", "7", ".", ".", ".", "."},
            {"6", ".", ".", "1", "9", "5", ".", ".", "."},
            {".", "9", "8", ".", ".", ".", ".", "6", "."},
            {"8", ".", ".", ".", "6", ".", ".", ".", "3"},
            {"4", ".", ".", "8", ".", "3", ".", ".", "1"},
            {"7", ".", ".", ".", "2", ".", ".", ".", "6"},
            {".", "6", ".", ".", ".", ".", "2", "8", "."},
            {".", ".", ".", "4", "1", "9", ".", ".", "5"},
            {".", ".", ".", ".", "8", ".", ".", "7", "9"}
        },
        {
            {"8", "3", ".", ".", "7", ".", ".", ".", "."},
            {"6", ".", ".", "1", "9", "5", ".", ".", "."},
            {".", "9", "8", ".", ".", ".", ".", "6", "."},
            {"8", ".", ".", ".", "6", ".", ".", ".", "3"},
            {"4", ".", ".", "8", ".", "3", ".", ".", "1"},
            {"7", ".", ".", ".", "2", ".", ".", ".", "6"},
            {".", "6", ".", ".", ".", ".", "2", "8", "."},
            {".", ".", ".", "4", "1", "9", ".", ".", "5"},
            {".", ".", ".", ".", "8", ".", ".", "7", "9"}
        }
    };

    for (int i = 0; i < testCases.size(); ++i) {
        vector board(9, vector<char>(9));
        for (int r = 0; r < 9; ++r)
            for (int c = 0; c < 9; ++c)
                board[r][c] = testCases[i][r][c][0];

        bool result = Solution().isValidSudoku(board);
        cout << i + 1 << ": " << PrintContainer(board) << " -> " << (result ? "true" : "false") << endl;
    }
    return 0;
}
