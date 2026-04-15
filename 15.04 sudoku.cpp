#include <iostream>
#include <vector>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    bool rows[9][9] = {false};
    bool cols[9][9] = {false};
    bool boxes[9][9] = {false};

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            char c = board[i][j];

            if (c == '.') {
                continue;
            }

            int num = c - '1'; 
            int boxIndex = (i / 3) * 3 + (j / 3);

            if (rows[i][num] || cols[j][num] || boxes[boxIndex][num]) {
                return false;
            }

            rows[i][num] = true;
            cols[j][num] = true;
            boxes[boxIndex][num] = true;
        }
    }

    return true;
}

int main() {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    if (isValidSudoku(board)) {
        cout << "Valid Sudoku";
    } else {
        cout << "Invalid Sudoku";
    }

    return 0;
}