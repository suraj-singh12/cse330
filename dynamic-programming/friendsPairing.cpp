// given n = 4; (no of friends)
// {A} {B} {C} {D}
// any two can be together, print all possible pairs
// a, b, c, d; ab, cd; bc, ad; ab, c ,d; bc, a,d;

// for n = 3
//  a,b ,c; ab, c; ac, b; bc, a;

// subsets of max size 2

// Friends Pairing Problem

#include <iostream>
#include <vector>
using namespace std;

int ans(int n, int *dp) {
    // if(n == 1 || n == 2) {
    //     return n;
    // }
    int first = 0, second = 0;
    if(dp[n -1] == 0)
        first = ans(n-1, dp);
    else first = dp[n -1];

    if(dp[n-2] == 0) 
        second = ans(n-2, dp);
    else second = dp[n-2];

    return first + second * (n-1);
}

int main()
{
    int n = 4;
    cout << "Enter n: ";
    cin >> n;
    int dp[n + 1] {0,1,2};
    cout << ans(n, dp) << endl;
    return 0;
}

//finding the maximum length of chain with given pairs
