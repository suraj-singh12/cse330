// given n
// count prime numbers that can be expressed as a sum of consecutive primes
// i.e. find the number of prime numbers upto N that can be expressed as a sum of consecutive primes

/*
Approach: 
find all primes upto n (using sieve: O(nloglogn), or using isPrime() : using O(n^3/2))
store in a vector
then let sum = element at indx 0
and sum up from 1->N elements in loop
and check in every iteration if sum is prime,
if yes, then increment the count as it is a valid answer
*/

#include <bits/stdc++.h>
using namespace std;
// Overall  TC: O(max(sqrt(n), nloglogn, primes.size())) = O(nloglogn)
// Auxiliary Space: O(loglogn)

// TC: O(sqrt(n))
bool isPrime(int n, int i = 2) {
    if(n <= 2)
        return (n == 2 ? true : false);
    if(n % i == 0) return false;
    if(i * i > n) return true;
    return isPrime(n, i + 1);
}

// TC: O(nloglogn)
void sieve(int n, vector<int> &primes) {
    bool prime[n];
    for(int i= 0; i < n; ++i) 
        prime[i] = true;

    for(int p = 2; p * p <= n; ++p) {
        if(prime[p]) {
            for(int i = p * p; i < n; i+= p) 
                prime[i] = false;
        }
    }

    for(int i = 2; i < n; ++i) {
        if(prime[i]) {
            // cout << i << " ";
            primes.push_back(i);
        }
    }
}

// TC: O(primes.size())
int requiredPrimes(int n) {
    vector<int> primes;
    sieve(n, primes);

    if(primes.size() == 0)
        return 0;

    long sum = primes[0];
    int count = 0;
    for(int i = 1; i < primes.size(); ++i) {
        sum += primes[i];
        // if sum exceeds the upper limit (n), then break
        if(sum > n) 
            break;
        if(isPrime(sum)) {
            count++;
        }
    }
    return count;
}

int main()
{
    int n = 45;
    cout << requiredPrimes(n) << endl;
}