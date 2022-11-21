// Prime number of set bits

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    bool isPrime(int n) {
        if(n <= 1) return false;
        if(n <= 3) return true;
        if(n % 2 == 0 || n % 3 == 0) return false;
        
        for(int i = 5; i * i <= n; i += 6) {
            if(n % i == 0 || n % (i + 2) == 0) 
                return false;
        }
        return true;
    }
    
    int countBits(int n) {
        int cnt = 0;
        while(n) {
            if(n & 1) cnt++;
            n = n >> 1;
        }
        // cout << "cnt: " << cnt << " ";
        return isPrime(cnt);
    }
    int primeSetBits(int L, int R){
        int ans = 0;
        for(int i=L; i<=R; ++i) {
            ans += countBits(i);
        }
        return ans;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int L, R;
        cin >> L >> R;
        Solution ob;
        cout<<ob.primeSetBits(L,R)<<endl;
    }
    return 0;
}

