// Find whether we can divide a set into two parts having elements with equal sum

// {1, 3, 5, 2, 11}
// {1,3,2,5}  {11}

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// #defines
#define ll long long


bool solve(int indx, ll sum, ll half, vector<ll> &st, vector<ll> &ans, vector<ll> &dp) {
    if(sum > half) return false;
    else if(sum == half) {
        return true;
    }

    // pick
    ans.push_back(st[indx]);
    sum = sum + st[indx];
    if(solve(indx + 1, sum, half, st, ans, dp)) return true;
    sum -= st[indx];
    ans.pop_back();

    // not pick
    if(solve(indx + 1, sum, half, st, ans, dp)) return true;
    return false;
}
int main() 
{
    vector<ll> st {1,3,5,2,11};
    ll half = 0;
    for(auto e : st) {
        half += e;
    }
    half /= 2;

    vector<ll> ans;
    vector<ll> dp;
    solve(0, 0, half, st, ans, dp);

    // set 1
    for(auto e : ans) {
        cout << e << " ";
    }
    cout << endl;

    // set 2
    ll sz = ans.size();
    for(ll i = sz; i < st.size(); ++i) {
        cout << st[i] << " ";
    }
    cout << endl;

    cout << endl;
    return 0;
}
