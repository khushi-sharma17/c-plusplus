#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void addSolution(vector<vector<int>> &board, vector<vector<int>> &ans, int n) {

    vector<int> temp(n);

    for (int col=0 ; col<n ; col++) {
        for (int row=0 ; row<n ; row++) {
            if (board[row][col] == 1) {
                temp[col] = row + 1;
                break;
            }
        }
    }

    ans.push_back(temp);
}



bool isSafe(int row, int col, vector<vector<int>> &board, int n) {

    int x = row, y = col;
    
    // checking left side in the same row
    while (y >= 0) {
        if (board[x][y] == 1) return false;
        y--;
    }


    // again initializing the values of x and y to row and col
    x = row, y = col;

    // checking for the upper-left diagonal
    while (x>=0 && y>=0) {
        if (board[x][y] == 1) return false;
        x--, y--;
    }

    x = row, y = col;
    // checking for the lower-left diagonal
    while (x<n && y>=0) {
        if (board[x][y] == 1) return false;
        x++, y--;
    }

    return true;
}

 

void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n) {
    // base case
    if (col == n) {
        addSolution(board, ans, n);
        return;
    }

    // solving one case and rest recursion will handle
    for (int row = 0; row < n ; row++) {

        if (isSafe(row, col, board, n)) {

            board[row][col] = 1;
            solve(col + 1, ans, board, n);
            board[row][col] = 0;        // backtrack
        }
    }
}


vector<vector<int>> nQueen(int n) {

    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;

    solve(0, ans, board, n);
    
    return ans;
}



int main() {

    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<vector<int>> result = nQueen(n);

    if (result.empty()) {
        cout << "No solutions found for n = " << n << endl;
    } else {
        cout << "Solutions for " << n << "-Queens problem:\n";
        for (const auto& solution : result) {
            cout << "[ ";
            for (int val : solution) {
                cout << val << " ";
            }
            cout << "]\n";
        }
    }

    return 0;
}