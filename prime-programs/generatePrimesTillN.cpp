
#include <iostream>
using namespace std;

// this is sieve : generate prime numbers till n
void sieveOfEratosthenes(int n) {
    // mark all as primes
    bool primes[n+1];
    for(int i = 0; i <= n; i++) {
        primes[i] = true;
    }

    // go from 2 to till sqrt(n)
    for(int p = 2; p * p <= n; p++) {
        // if current number is still unmarked,
        if(primes[p]) {
            // mark all the multiples of p greater than or equal to the square of it.
            for(int i = p * p; i <= n; i += p) {
                primes[i] = false;
            }
        }
    }

    // print the primes
    for(int i = 2; i <= n; ++i) {
        if(primes[i]) cout << i << " ";
    }
}

// using check isPrime() : O(sqrt(n))
bool isPrime_rec(int n, int i = 2) 
{
    if(n <= 2) {
        return (n == 2 ? true : false);
    }

    if(n % i == 0) 
        return false;
    if(i * i > n) 
        return true;
    return isPrime_rec(n, i + 1);
}
// using check isPrime() : O(sqrt(n)); iterative
bool isPrime(int n) {
    if(n <= 1) return false;

    if(n == 2 || n == 3) return true;

    if(n % 2 == 0 || n % 3 == 0) return false;

    for(int i = 5; i * i < n; i+= 6) {
        if(n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}
// generate Primes till N using isPrime(): TC: n^3/2
void generatePrimesTillN1(int n) {
    cout << 2 << " " << 3 << " ";

    for(int i = 5; i < n; ++i) {
        if(isPrime(i))
            cout << i << " ";
    }
}


int main() 
{
    sieveOfEratosthenes(100);
    return 0;
}