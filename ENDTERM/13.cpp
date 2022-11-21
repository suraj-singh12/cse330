// Kth Prime factor of a Number

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int kthPrimeFactor(int n, int k) {
        int ctr = 0;
        if(n <= 1) return -1;
        if(n % 2 == 0) {
            while(n % 2 == 0) {
                n /= 2;
                ctr++;
                if(ctr == k) return 2;
            }
        }
        
        for(int i = 3; i * i <= n; i += 2) {
            if(n % i == 0) {
                while(n % i == 0) {
                    n /= i;
                    ctr++;
                    if(ctr == k) return i;
                }
            }
        }
        
        if(n > 1) {
            ctr++;
            if(ctr == k) return n;
        }
        return -1;
    }
    int kthPrime(int n, int k){
        return kthPrimeFactor(n, k);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        
        Solution ob;
        cout<<ob.kthPrime(n, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends