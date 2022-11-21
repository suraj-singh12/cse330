// Mysterious Series

#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
  vector<int> primes;
  
  public:
    
    void sieve() {
        
        int n = 1e6;
        
        bool prime[n + 1];
        for(int i = 0; i <= n; i++) 
            prime[i] = true;
        
        for(int i  = 2; i * i <= n; i++) {
            if(prime[i]) {
                for(int j = i * i; j <= n; j += i) {
                    prime[j] = false;
                }
            }
        }
        
        for(int i = 2; i <= n; ++i) {
            if(prime[i]) primes.push_back(i);
        }
    }
    long long nthMysterious(long long N){
        sieve();
        long long ans = primes[N -1] * primes[N - 1] + 1;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        long long N;
        cin >> N;
        Solution ob;
        cout << ob.nthMysterious(N) << endl;
    }
    return 0;
}