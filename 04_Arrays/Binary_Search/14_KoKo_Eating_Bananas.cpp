#include <iostream>
#include <bits/stdc++.h>
using namespace std;


bool isPossible(vector<int> &piles, int h, int mid) {

    vector<int> hrs;

    for(int i=0; i<piles.size() ; i++) {

        int ans = -1;

        if (piles[i] % mid == 0) {

            ans = piles[i] / mid;
            hrs.push_back(ans);

        } else {
            ans = piles[i] / mid;
            hrs.push_back(ans + 1);
        }
    }

    int sum = 0;
    for(int elem : hrs) {
        sum += elem;
    }

    if (sum <= h) {
        return true;
    }

    return false;
    
}


int minEatingSpeed(vector<int>& piles, int h) {
    
    int start = 1;

    int maxi = -1;
    for(int i=0; i<piles.size(); i++) {
        maxi = max(maxi, piles[i]);
    }

    int end = maxi;

    int ans = -1;

    int mid = start + (end - start) / 2;

    while(start <= end) {

        if(isPossible(piles, h, mid)) {
            ans = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }

        mid = start + (end - start) / 2;
    }

    return ans;
}



int main() {

    vector<int> piles = {30, 11, 23, 4, 20};

    int h;
    cout << "Enter the number of hours : ";
    cin >> h;

    cout << minEatingSpeed(piles, h);
    
    return 0;
}