/*
Count all distinct pairs with difference of K

1 4 3 5 2
k = 3

ans: (1,4), (5,2)
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr {1, 4, 3, 5, 2, 4, 1, 5, 8, 2, 5, 11, 8};
    int k = 3;
    int n = arr.size();
    unordered_map<int, int> mpp;

    for(int i = 0; i < n; i++) {
        mpp[arr[i]]++;
    }

    int ans = 0;
    int i = 0;

    // stuck up at current ip
    while(true) {
        if(mpp[arr[i]] != 0 && mpp.find(arr[i] + k) != mpp.end()) {
            ans++;
            mpp[arr[i]]--;
            mpp[arr[i] + k]--;
        } else if(mpp[arr[i]] != 0 && mpp.find(arr[i] - k) != mpp.end()) {
            ans++;
            mpp[arr[i]]--;
            mpp[arr[i] - k]--;
        } else {
            i++;
        }
        cout << i << " ";
        if(i >= n -1) break;
    }
    cout << ans << " ";
    return 0;
}
