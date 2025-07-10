#include <iostream>
using namespace std;


int modularExponentiation(int x, int n, int m) {

	int res = 1;

	while (n > 0) {

		if(n & 1) {		// odd
			res = ( 1LL * (res) * (x) % m) % m;
		}	
		// here, 1LL --> 1 Long Long and we are typecasting the values over here

		x = (1LL * (x) % m * (x) % m) % m;
		n = n>>1;
	}

	return res;
}



int main() {

    int x, n, m;
	cin >> x >> n >> m;

    int ans = modularExponentiation(x, n, m);

    cout << "The answer is : " << ans << endl;

    return 0;
}


// Pigeonhole Principle 
// Catalan number 
// Inclusion - Exclusion Principle 

// Fcatorial of number = like 212! % m, here m = 10**9 + 7