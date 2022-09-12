// Twin Prime Number between 1 and n
// twin primes are those prime numbers which have a gap of 2 between them

// given n, print all twin primes till n

#include <bits/stdc++.h>
using namespace std;

void sieve(int n, vector<bool> &primes) {
    for(int p = 2; p * p <= n; ++p) {
        if(primes[p]) {
            for(int i = p * p; i <= n; i += p) {
                primes[i] = false;
            }
        }
    }
}
void printTwinPrimes(int n) {
    vector<bool> primes (n, true);
    sieve(n, primes);

    for(int i = 2; i <= n - 2; i++) {
        if(primes[i] && primes[i + 2])
            cout << "(" << i << ", " << i + 2 << ")\n";
    }
}

int main()
{
    int n = 25;
    printTwinPrimes(n);
    return 0;
}