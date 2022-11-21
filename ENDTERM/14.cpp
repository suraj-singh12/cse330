// Find the highest occurring digit in prime numbers in a range

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
    
    void findMax(int n, vector<int> &v) {
        while(n) {
            int lstDgt = n % 10;
            v[lstDgt]++;
            n /= 10;
        }
    }
    int maxDigit(int L, int R)  {
        // code here
        vector<int> v (10, 0);
        for(int i = L; i <= R; ++i) {
            if(isPrime(i)) {
                findMax(i, v);
            }
        }
        
        int digit = -1, freq = 0;
        for(int i = 0; i < 10; ++i) {
            if(v[i] >= freq) {
                digit = i;
                freq = v[i];
            }
        }
        if(freq == 0) return -1;
        return digit;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int L, R;
        cin >> L >> R;
        Solution ob;
        cout<<ob.maxDigit(L,R)<<endl;
    }
    return 0;
}
