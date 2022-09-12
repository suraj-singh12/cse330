// check if a number can be written as sum of k primes.
// given n : number, k

#include<bits/stdc++.h>
using namespace std;

/*
idea: Goldbach's conjecture:    
        it says that every even integer can be expressed as a sum of two primes.
        .....
        https://www.geeksforgeeks.org/check-number-can-written-sum-k-prime-numbers/
*/

// overall TC: O(sqrt(n))

// function to check if a number is prime 
// TC: O(sqrt(n))
bool isPrime(int n) 
{
    if(n <= 1) return false;
    if(n <= 3) return true;
    if(n % 2 == 0 || n % 3 == 0) return false;

    for(int i = 5; i * i <= n; i+=6) {
        if(n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

// function to check if number can be written as sum of k primes
// TC: O(1)
bool isSumOfKPrimes(int n, int k) {

    // if n < 2k , then it is not
    if(n < 2*k) return false;

    // if k is 1, and n is prime, then possible else not.
    if(k == 1) return isPrime(n);

    // if k is 2
    if(k == 2) {
        // if n is even, then it is (acc. to Goldbach conjecture)
        if(n % 2 == 0) return true;

        // if n is odd, then one prime must be 2
        // all other primes are odd, and can't have a pair sum as even
        return isPrime(n - 2);
    }

    //  if k is >= 3, then always true
    return true;
}

int main() 
{
    int n = 10, k = 2;
    cout << (isSumOfKPrimes(n, k) ? "YES" : "NO") << endl;
    return 0;
}