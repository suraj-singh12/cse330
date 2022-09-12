// insert minimum number in the array so the sum of array becomes prime.
// return the number to be inserted, if sum is already prime, return 0

#include <bits/stdc++.h>
using namespace std;

// use sieve of eratosthenes to generate primes till max 
// then use it to return the difference between number and the nearest prime

bool isPrime(int n, int i = 2) {
    if(n <= 2)
        return (n == 2 ? true : false);
    
    if(n % i == 0) return false;
    
    if(i * i > n) return true;

    return isPrime(n, i+1);
}

int getNearestPrime(int sum) {
    bool primes[100005];
    for(int i = 0; i < 100005; i++)
        primes[i] = true;
    
    for(int p = 2; p * p  < 100005; p++) {
        if(primes[p]) {
            for(int i = p * p; i < 100005; i += p)
                primes[i] = false;
        }
    }
    
    for(int i = sum + 1; i < 100005; ++i) {
        if(primes[i]) return i;
    }
    return -1;
}

int minElementToBeInserted(int *arr, int n) {
    int sum = 0;
    for(int i = 0; i < n; ++i) 
        sum += arr[i];
    
    if(isPrime(sum)) 
        return 0;
    else {
        // only now proceed for sieve, 
        // this is optimization
        int nearestPrime = getNearestPrime(sum);
        // this will almost never happen
        if(nearestPrime == -1) return -1;

        int diff = nearestPrime - sum; 
        return diff;
    }
    return 0;
}

int main()
{
    int arr[] = {2, 4, 6, 8, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << minElementToBeInserted(arr, n) << endl;
    return 0;
}