#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> orderedPrime(int n){
        vector<int> ans;
        
        int ctr = 0;
        int totalFactors = 1;       // (power + 1) * (power + 1) * ... 
        
        // corner case
        if(n <= 1) {
            // no prime divisors for n <= 1
            return vector<int> {totalFactors};
        }
        
        while(n % 2 == 0) {
            ctr++;
            n/=2;
        }
        if(ctr > 0) {
            ans.push_back(ctr);
            totalFactors *= (ctr + 1);          // *(power + 1)
        }
        
        // O(sqrt(n)) Time complexity
        for(int i = 3; i * i <= n; ++i) {
            ctr = 0;
            while(n % i == 0) {
                ctr++;
                n /= i;
            }
            if(ctr > 0) {
                ans.push_back(ctr);
                totalFactors *= (ctr + 1);
            }
        }
        if(n > 1) { // corner case (for eg a prime number is left) ; eg: 95 (5, 19); 19 will be caught here
            ans.push_back(1);
            totalFactors *= (1 + 1);        // * (power + 1)
        }
        
        sort(ans.begin(), ans.end());       // sort powers in ascending order
        ans.push_back(totalFactors);        // add  the no of factors
        
        return ans;     // return ans
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        Solution ob;
        vector<int> ans = ob.orderedPrime(n);
        for(int i = 0; i < ans.size(); ++i) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}