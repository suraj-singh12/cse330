// find how many minimum unique character we can have in the given string X
// x = abcabc
// Y = aadadd

// by replacing characters from X by Y's corresponding characters.

#include <bits/stdc++.h>
using namespace std;


// using bruteforce
void findMinCount(string x, string y, int indx, int n, int &ans) {
    if(indx == n) {
        // push
        int bits = 0;
        for(int i = 0; i < x.length(); ++i) {
            bits |= (1 << (x[i] - 'a'));
        }
        int count = 0;
        for(int i = 0; i < 26; ++i) {
            count += (1 & (bits >> i));
        }
        // cout << count << " ";
        ans = min(ans, count);
        return;
    }
    
    // once replace
    char tmp = x[indx];
    x[indx] = y[indx];
    findMinCount(x, y, indx + 1, n, ans);
    // once don't replace
    x[indx] = tmp;
    findMinCount(x, y, indx + 1, n, ans);

    // string lft = x.substr(0, indx);
    // string rgt = x.substr(indx + 1);
    // string tmp = lft + y[indx] + rgt;

    // if(tmp != x) {
    //     // once replace (if different)
    //     findMinCount(tmp, y, indx + 1, n, ans);
    // }
    // // once don't replace
    // findMinCount(x, y, indx + 1, n, ans);
}

int main() 
{
    string x = "abcabcc";
    string y = "aadadd";
    int ans = INT_MAX;
    findMinCount(x, y, 0, min(x.length(), y.length()), ans);
    cout << "min unique count: " << ans << endl;
}

