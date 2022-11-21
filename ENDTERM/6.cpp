// Primorial of a number

//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution {

public:
    void precompute()
    {
        // isPrime() function
        // return if this is prime
    }
    long long primorial(long long n){
        // ll ans = 1;
        // ll mod = 1e9 + 7;
        // iterate [2->n]
        //      if(isPrime(i)) ans  = ((ans % mod) * (i % mod)) % mod;
        // return ans;

        // OR use sieve();
    }
};

//{ Driver Code Starts.

int main()
{
    Solution ob;
    ob.precompute();
    int t; cin >> t;
    while(t--)
    {
        long long n;
        cin>>n;
        cout << ob.primorial(n) << endl;
    }
    return 0;
} 
// } Driver Code Ends