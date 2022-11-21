// Find sum of divisors

#include<bits/stdc++.h> 
using namespace std; 

class Solution
{
public:

    vector<int> findDivisors(int n) {
        vector<int> ans {1};
        if(n == 1) return ans;
        for(int i = 2; i * i <= n; ++i) {
            if(n % i == 0) {
                if(n / i == i) {
                    ans.push_back(n/i);
                } else {
                    ans.push_back(n / i);
                    ans.push_back(i);
                }
            }
        }
        ans.push_back(n);
        return ans;
    }
    
    int findSumOfDivisors(vector<int> &divisors) {
        int ans = 0;
        for(auto d: divisors) {
            auto tmp = findDivisors(d);
            for(auto i : tmp) {
                ans += i;
            }
        }
        return ans;
    }
    int sumOfDivisors(int n)
    {
        auto divisors = findDivisors(n);
        return findSumOfDivisors(divisors);
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        int ans  = ob.sumOfDivisors(N);
        cout<<ans<<endl;
    }
    return 0;
}
