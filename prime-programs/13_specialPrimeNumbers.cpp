// special prime numbers
// a prime is special prime if it can be expressed as sum of three integers: two neighbouring prime numbers and 1.
// e.g.: 19 =  7 + 11 + 1


/*
approach: 
use sieve to generate primes till given number
then find two smaller primes, and sum them + 1
see if that's equal to number, if yes then fine
if that's greater, go more down,
if it's lesser than not possible
*/

#include <bits/stdc++.h>
using namespace std;


void sieve(int n, vector<int> &primes) 
{
    vector<int> prime (n + 1, true);

    for(int p = 2; p * p <= n; ++p) {
        if(prime[p]) {
            for(int i = p * p; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }

    for(int i = 2; i <= n; ++i) {
        if(prime[i]) 
            primes.push_back(i);
    }
}

bool isSpecialPrime(int n, int k) {
    // k defines how many special prime pairs are asked
    vector<int> primes;
    sieve(n, primes);

    int count = 0;
    for(int i = 0; i < primes.size(); ++i) {
        for(int j = 0; j < i -1; j++) {
            if(primes[j] + primes[j + 1] + 1 == primes[i]) {
                // increment count
                count++;
                // break out now
                break;
            }
        }
        if(count == k) 
            return true;
    }
    return false;
    // int first = -1, second = -1;
    // for(int i = n -1; i >= 2; i--) {
        // if(prime[i]) {
            // if(first == -1)
                // first = i;
            // else if(second == -1) 
                // second = i;
            // else {
                // int sum = first + second + 1;
                // if(sum == n) {
                    // cout << "yes, it is special prime" << endl;
                    // cout << first << " + " << second << " + " << 1 << " = " << n << endl;
                    // return;
                // } else {
                    // cout << "Not special prime\n";
                    // return;
                // }
            // }
        // }

    // }

}

int main() 
{
    int n = 27, k = 2;
    cout << (isSpecialPrime(n, k) ? "YES" : "NO") << endl;
    return 0;
}