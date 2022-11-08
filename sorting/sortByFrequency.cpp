/*
Sort the array by freqency of elements

[1,3,2,1,4,5]
*/

#include <bits/stdc++.h>
using namespace std;

bool myComp(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second > b.second;
}
int main()
{
    int arr[] = {1,3,2,1,1,3,5,5,5,4,5};
    int n = sizeof(arr) / sizeof(arr[0]);

    unordered_map<int, int> mpp;
    for(int i = 0; i < n; ++i) {
        mpp[arr[i]]++;
    }

    vector<pair<int, int>> vc;
    for(auto x : mpp) {
        vc.push_back(x);
    }

    sort(vc.begin(), vc.end(), myComp);

    vector<int> ans;
    for(auto x : vc) {
        int val = x.second;
        while(val--) {
            ans.push_back(x.first);
        }
    }
    for(auto i : ans) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

