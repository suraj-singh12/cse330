// check if a number is full prime
// full prime: if number and all its digits are prime, then full prime.

#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if(n <= 1) return false;
    if(n <= 3) return true;
    if(n % 2 == 0 || n % 3 == 0) return false;

    for(int i = 5; i * i <= n; i += 6) {
        if(n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

// efficient one
bool isDigitsPrime(int n) {
    while(n) {
        int digit = n % 10;
        if(!(n == 2 || n == 3 || n == 5 || n == 7)) 
            return false;
        n /= 10;
    }
    return true;
}
bool isFullPrime(int n) {
    
    // bool isNumPrime = isPrime(n);
    
    // if(isNumPrime) {
    //     // if number is prime,
    //     // check if all its digits are also prime
    //     while(n) {
    //         if(!isPrime(n % 10)) return false;
    //         n /= 10;
    //     }
    // } else {
    //     // if number was not prime, then return false
    //     return false;
    // }
    // // return true, if number passed all checks.
    // return true;

    // efficient one
    // check the digits first, then the number
    if(isDigitsPrime(n) && isPrime(n)) 
        return true;
    return false;
    
}

int main()
{
    int n = 53;
    cout << (isFullPrime(n)? "YES" : "NO") << endl;
    return 0;
}