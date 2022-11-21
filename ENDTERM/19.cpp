// Collection of pens
#include <bits/stdc++.h>
using namespace std;


#define ll long long
class Solution {
  public:
  vector<ll> primes;  
    void sieve() {
        ll n = 1e4;
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
    
    ll binarySearch(ll target) {
        ll start = 0, end = primes.size();
        while(start <= end) {
            ll mid = start + (end - start ) / 2;
            if(primes[mid] > target) end = mid - 1;
            else start = mid + 1;
        }
        return primes[start];
    }
    int minThirdPiles(int A, int B)  {
        sieve();
        ll target = A + B;
        return binarySearch(target) - target;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.minThirdPiles(A, B) << endl;
    }
    return 0;
}
