#include <bits/stdc++.h>
using namespace std;


bool knows(vector<vector<int>> &M, int A, int B) {
    return (M[A][B] == 1);
}


int findCelebrity(vector<vector<int>> &M, int n) {

 	stack<int> s;

    // push all elements inside the stack.
    for(int i = 0; i < n ; i++) {
        s.push(i);
    }

    while(s.size() != 1) {
        int A = s.top();
        s.pop();

        int B = s.top();
        s.pop();

        if(knows(M, A, B)) {
            s.push(B);
        } else {
            s.push(A);
        }
    }


    int candidate = s.top();

    // single element in stack is the potential celebrity 
    // thus, verifying it

    bool rowCheck = false;
    int rowCount = 0;
    for (int i = 0 ; i<n ; i++) {
        if(M[candidate][i] == 0) {
            rowCount++;
        }
    }

    // all zeroes ?
    if (rowCount == n) {
        rowCheck = true;
    }

    // column check;
    bool colCheck = false;
    int colCount = 0;
    for (int i = 0 ; i<n ; i++) {
        if(M[i][candidate] == 1) {
            colCount++;
        }
    }

    // all ones and one zero ?
    if (colCount == n - 1) {
        colCheck = true;
    }

    return (rowCheck == true && colCheck == true) ? candidate : -1;
}

// No need of bool checks in the above code but, like rowCheck and all


int main() {

    int n;
    cout << "Enter the size of the matrix : ";
    cin >> n;

    vector<vector<int>> M(n, vector<int>(n));

    cout << "Enter the elements of the matrix (each row separated by space) : ";
    for (int i = 0 ; i<n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            cin >> M[i][j];
        }
    }

    int celebrity = findCelebrity(M, n);

    if(celebrity == -1) {
        cout << "No celebrity found !";
    } else {
        cout << "Celebrity found at index : " << celebrity << endl;
    }

    return 0;
}

// TC = O(n)
// SC = O(n)
// more approaches on this problem