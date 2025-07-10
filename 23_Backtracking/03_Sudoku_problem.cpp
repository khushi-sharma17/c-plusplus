#include <iostream>
#include <bits/stdc++.h>
using namespace std;


bool isSafe(int row, int col, vector<vector<int>> &board, int val, int n) {

    for (int i=0 ; i<n ; i++) {
        
        if (board[row][i] == val) return false;     // row check 
        if (board[i][col] == val) return false;     // col check

        // 3*3 matrix check
        if (board[3*(row/3) + i/3][3*(col/3) + i%3] == val) return false;
    }

    return true;
}


bool solve(vector<vector<int>> &board) {

    int n = board[0].size();
    for (int row=0 ; row<n ; row++) {
        for (int col=0 ; col<n ; col++) {

            if (board[row][col] == 0) {
                
                for (int val=1 ; val<=9 ; val++) {
                    if (isSafe(row, col, board, val, n)) {
                        board[row][col] = val;

                        // recursive call
                        bool nextSolPossible = solve(board);

                        if (nextSolPossible) {
                            return true;
                        } else {
                            // backtrack
                            board[row][col] = 0;
                        }
                    }
                }

                return false;
            }
        }
    }

    return true;

}


void solveSudoku(vector<vector<int>> &mat) {
    bool solved = solve(mat);
}


int main() {

    vector<vector<int>> mat = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };

    solveSudoku(mat);

    // Output solved board
    for (auto &row : mat) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}

// TC = 9**m
// SC = O(1) ex:= 9*9 = 81