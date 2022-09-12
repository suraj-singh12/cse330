// k almost prime number
// A k-Almost Prime Number is a number having exactly k prime factors (not necessarily distinct).
// given n, k : find how many k almost prime numbers exist

#include <bits/stdc++.h>
using namespace std;

// count the no of factors of given number
int noOfFactors(int n)
{
    int count = 0;
    while(n % 2 == 0) {
        n /= 2;
        count++;
    }

    for(int i = 3; i * i <= n; i += 2) {
        while(n % i == 0) {
            n /= i;
            count++;
        }
    }
    if(n > 2) count++;
    return count;
}

// function to return k almost prime numbers
void kPrime(int n, int k) {
    //  n = number of such primes to print.
    // k defines 'k' in k-primes

    int number = 2;
    for(int i = 0; i < n;) {
        if(noOfFactors(number) == k) {
            cout << number << " ";
            // increment count of primes printed so far
            i++;
        }
        // increment the number being checked.
        number++;
    }

    cout << endl;
}

int main()
{
    int n = 10, k = 2;
    kPrime(n, k);
    return 0;
}