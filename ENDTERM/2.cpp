// Find n-th Fortunate Number
#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
  public:
    vector<ll> primes;
    void sieve() {
        ll n = 1e2;
        vector<bool> prime (n + 1, true);
        
        for(ll i = 2; i * i <= n; ++i) {
            if(prime[i]) {
                for(ll j = i * i; j <= n; j += i) {
                    prime[j] = false;
                }
            }
        }
        
        for(int i = 2; i < n; ++i) {
            if(prime[i]) {
                primes.push_back(i);
            }
        }
    }
    bool isPrime(ll n) {
        if(n <= 1) return false;
        if(n == 2 || n == 3) return true;
        if(n % 2 == 0 || n % 3 == 0) return false;
        
        for(ll i = 5; i * i <= n; i += 6) {
            if(n % i == 0 || n % (i + 2) == 0) 
                return false;
        }
        return true;
    }
    
    long long nthFortunateNum(int n) {
        sieve();
        ll ans = 1;
        for(int i = 0; i < n; ++i) 
            ans  *= primes[i];
            
        ll partialAns = ans;
        ans += 2;
        
        while(true) {
            if(isPrime(ans)) {
                return ans - partialAns;
            }
            ans++;
        }
        return -1;
        // return binarySearch(ans) - (ans - 1);
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFortunateNum(n) << endl;
    }
    return 0;
}