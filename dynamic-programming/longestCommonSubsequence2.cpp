// find the longest common subsequence
/*
given a string 
s: ABCBDCAD

find lcs in it, don't consider a match when index is same
*/

#include <iostream>
#include <vector>
using namespace std;

int lcs(string s1, string s2, int i, int j, vector<vector<int> > &dp) {
    if(i >= s1.length() || j >= s2.length()) {
        return 0;
    } 

    if(s1[i] == s2[j] && i != j) {
        if(dp[i][j] != -1)
            return dp[i][j]; 
        return dp[i][j] = (1 + lcs(s1, s2, i + 1, j + 1, dp));
    }
    if(dp[i][j] != -1) 
        return dp[i][j];
    return dp[i][j] = max(lcs(s1, s2, i + 1, j, dp), lcs(s1, s2, i, j + 1, dp));
}


int main()
{
    // string s1 = "ABCBDE";
    // string s2 = "ACDBDCDBCCEDE";

    string s1 = "abcbdcad";
    string s2 = "abcbdcad";
    vector<vector<int> > dp (s1.length(), vector<int> (s2.length(), -1));
    lcs(s1, s2, 0, 0, dp);
    cout << dp[0][0] << endl;
}