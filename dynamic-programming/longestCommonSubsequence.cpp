// find longest common subsequence 
/*
given two strings: 
s1: ABCBDE
s2: ACDBDCDBCCEDE

ans: 5
*/

#include <iostream>
#include <vector>
using namespace std;

int lcs(string s1, string s2, int i, int j, vector<vector<int> > &dp) {
    if(i >= s1.length() || j >= s2.length()) {
        return 0;
    } 

    if(s1[i] == s2[j]) {
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
    string s1 = "ABCBDE";
    string s2 = "ACDBDCDBCCEDE";
    
    vector<vector<int> > dp (s1.length(), vector<int> (s2.length(), -1));
    lcs(s1, s2, 0, 0, dp);
    cout << dp[0][0] << endl;
}