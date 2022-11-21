
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

#define ll long long 
class Solution{
    vector<ll> primes;
public:

    bool isPrime(ll n) {
        if(n <= 1) return false;
        if(n <= 3) return true;
        if(n % 2 == 0 || n % 3 == 0) return false;
        
        for(int i = 5; i * i <= n; i += 6) {
            if(n % i == 0 || n % (i + 2) == 0) return false;
        }
        return true;
    }
    long long primeProduct(long long L, long long R){
        ll mod = 1e9 + 7;
        ll ans = 1;
        
        for(int i = L; i <= R; ++i) {
            if(isPrime(i)) {
                ans = ( (ans % mod) * (i % mod) )% mod;
            }
        }
        
        return ans % mod;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        long long L, R;
        cin>>L>>R;
        
        Solution ob;
        cout<<ob.primeProduct(L, R)<<"\n";
    }
    return 0;
}