#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;


// simple sieve to get primes upto sqrt(R)
vector<int> simpleSieve(int limit) {

    vector<bool> isPrime(limit + 1, true);
    vector<int> primes;

    isPrime[0] = isPrime[1] = false;

    for(int i=2; i<= limit ; i++) {
        if (isPrime[i]) {
            primes.push_back(i);

            for(int j = i*i ; j <= limit ; j += i) {
                isPrime[j] = false;
            }
        }
    }

    return primes;
}


// segmented sieve to find primes in the range [L, R]
void segmentedSieve(long long L, long long R) {

    int limit = sqrt(R) + 1;
    vector<int> primes = simpleSieve(limit);

    vector<bool> isPrime(R - L + 1, true);

    for (long long p : primes) {
        long long start = max(p * p, ((L + p - 1) / p) * p);
        for (long long j = start; j <= R; j += p)
            isPrime[j - L] = false;
    }

    if (L == 1) isPrime[0] = false;

    for (long long i = 0; i <= R - L; ++i) {
        if (isPrime[i])
            cout << (i + L) << " ";
    }
    cout << endl;
}



int main() {

    long long L = 10, R = 50;
    cout << "Primes in range [" << L << ", " << R << "] are:\n";
    segmentedSieve(L, R);
    return 0;    

    return 0;
}