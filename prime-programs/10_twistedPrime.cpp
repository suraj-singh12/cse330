// a number is twisted prime number if it is prime, and reverse of it is also prime.

// given n: find whether n is twisted prime.

#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n, int i = 2) {
    if(n <= 2 ) 
       return (n == 2? true: false);
    
    if(n % i == 0) return false;

    if(i * i > n) return true;

    return isPrime(n, i + 1);
}

bool isTwistedPrime(int n) {
    if(isPrime(n) == false) return false;
    
    int reverse = 0;
    while(n) {
        reverse = reverse * 10 + n % 10;
        n = n / 10;
    }

    if(isPrime(reverse) == false) return false;
    return true;
}

void checkTwistedPrimesInRange(int n) {
    for(int i = 2; i < n; ++i) {
        if(isTwistedPrime(i))
            cout << i << " ";
    }
    cout << endl;
}
int main()
{
    int n = 97;   // yes : 97, 79 is a twisted prime
    // 13, 17, 7, 5 are also twisted primes
    cout << "Enter a number: ";
    cin >> n;

    cout << (isTwistedPrime(n)? "Yes" : "No") << endl;
    checkTwistedPrimesInRange(n);
    return 0;
}