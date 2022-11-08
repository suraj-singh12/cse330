// sort the array waveform

// arr: [20, 10, 8, 6, 4, 2]
// oup: [20, 8, 10, 4, 6, 2]
//        L, s,  L, s, L, s
// L : larger value;    s: smaller value

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr {20, 8, 10, 2, 6, 4};
    // vector<int> arr {20, 8, 10, 2, 6};
    sort(arr.begin(), arr.end());

    int n = arr.size();
    vector<int> ans (n);

    int half = n -1;

    for(int i = 0; i < n; i = i + 2) {
        ans[i] = arr[half--];
    }
    half = n / 2 -1;
    for(int i = 1; i < n; i = i + 2) {
        ans[i] = arr[half--];
    }
    for(auto x : ans) cout << x << " ";
    return 0;
}