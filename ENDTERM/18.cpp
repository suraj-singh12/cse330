//  Least Prime Factor

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    int leastPrimeFactorOf(int n) {
        for(int i = 5; i * i <= n; i += 2) {
            if(n % i == 0) {
                return i;
            }
        }
        return n;
    }
    vector<int> leastPrimeFactor(int n) {
        vector<int> ans {0};
        if(n < 1) return ans;
        ans.push_back(1);
        if(n < 2) return ans;
        
        for(int i = 2; i <= n; ++i) {
            if(i % 2 == 0) {
                ans.push_back(2);       // for all even numbers, least prime factor is 2
            } else if(i % 3 == 0) {
                ans.push_back(3);
            } else {
                ans.push_back(leastPrimeFactorOf(i));
            }
        }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        vector<int>ans = ob.leastPrimeFactor(n);
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;  
    }
    return 0;
}
