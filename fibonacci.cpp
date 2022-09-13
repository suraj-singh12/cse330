#include <bits/stdc++.h>
using namespace std;

int fib(int n, vector<int> &aid) {
    
    if(n == 0) {
        return 0;
    }
    if(n == 1 || n == 2) {
        return 1;
    }

    int prev = 0, prev2 = 0;
    if(aid[n-1] == 0)
        prev = fib(n - 1, aid);
    else 
        prev = aid[n -1];
    if(aid[n-2] == 0)
        prev2 = fib(n - 2, aid);
    else 
        prev2 = aid[n -2];
    
    aid[n] = prev + prev2;
    // cout << aid[n] << " ";
    return aid[n];
}
int main() 
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    vector<int> aid (n + 1, 0);
    auto ans = fib(n, aid);
    cout << "for " << n << " : " << ans << endl;

    return 0;
}