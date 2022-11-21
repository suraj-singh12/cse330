#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
  public:
    vector<ll> primes;  
    void sieve() {
        ll n = 1e5;
        vector<bool> prime(n +1, true);
        
        for(int i = 2; i * i <= n; ++i) {
            if(prime[i]) {
                for(int j = i * i; j <= n; j += i)
                    prime[j] = false;
            }
        }
        for(int i = 2; i <= n; ++i) {
            if(prime[i]) primes.push_back(i);
        }
    }
    int nthTerm(int n){
        // code here
        // n * nthPrime + n
        sieve();
        return n * primes[n - 1] + n;
        
    }
};