// k-primes: number with k distinct prime factors 

// given 3 integers: A, B, k
// find k-prime numbers in a range [A, B]
#include <bits/stdc++.h>
using namespace std;

// optimized way using sieve
// TC: O(b^2)
// Auxiliary Space: O(b)
void printkPrimes(int a, int b, int k) {
    bool primes[b + 1] = {false};
    int p_factors[b + 1] = {0};

    for(int p = 2; p <= b; p++) {
        if(p_factors[p] == 0) {
            // this ensures we enter 2, 3, 5, 7, 11, ... i.e. prime nos only
            for(int i = p; i <= b; i += p) {
                p_factors[i]++;
            }
        }
    }

    // print all the numbers with k prime factors
    for(int i = a; i <= b; ++i) {
        if(p_factors[i] == k) 
            cout << i << " ";
    }
    cout << endl;
}

int main()
{
    int a = 14, b = 18, k = 2;
    printkPrimes(a, b, k);
    return 0;
}