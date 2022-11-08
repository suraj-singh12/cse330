#include <bits/stdc++.h>
using namespace std;

int median(vector<vector<int>> &matrix, int R, int C){
    int lo = 1, hi = 2001;
    while(lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        int cnt = 0;
        
        for(int i = 0; i < R; i++) {
            int up_bound = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            cnt += up_bound;
        }
        
        if(cnt <= (R*C-1) / 2) lo = mid + 1;
        else hi = mid - 1;
    }
    
    return lo;
}

int main()
{
    vector<vector<int>> vc {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    };
    int n = vc.size();
    int m = vc[0].size();
    cout << median(vc, m, n);
    return 0;
}