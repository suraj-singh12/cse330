// find nth ugly number

/*
ugli number: if prime factors are from 2, 3, or 5 only, then it is ugly number. if have any factor apart from any of these, then it is not ugly number.
use DP, and complexity of O(n)

n = 9, 
1 '2' '3' '4' '5' '6' 7 '8' '9' '10' 11 '12' 13 14 15 16 17 18 19 20 21 22
12 is the 9th ugly number

dp: use extra space, to save on time complexity
*/

#include <iostream>
#include <vector>
using namespace std;

// int NthUgliNumber(int n, int count) {
//     if( n == 2 || n == 3 || n == 5)  {
//         return 1;
//     }
//     if(ugliNumbers[n]) {
//         count++;
//         return;
//     } else {
//         int tmp1 = NthUgliNumber(n / 2, count+1);
//         int tmp2 = NthUgliNumber(n / 3, count + 1);
//         int tmp3 = NthUgliNumber(n / 5, count + 1);

//         if(tmp1 || tmp2 || tmp3) {
//             ugliNumbers[n] = true;
//         }
//     }
// }

void generateUgliNumbers(vector<int> &dp) {
    int i = 2, j = 3, k = 5;
    for(int i = 0; i < 2 * dp.size() + 1; i += 2) {
        dp[i] = 1;
        dp[3*i] = 1;
    }
    for(int i = 3; i < 2 * dp.size() + 1; i += 3) {
        dp[i] = 1;
    }
    for(int i = 5; i < 2 * dp.size() + 1; i += 5) {
        dp[i] = 1;
    }
}

int main()
{
    int n = 9;
    vector<int> ugliNumbers(2*n + 1, 0);
    ugliNumbers[2] = ugliNumbers[3] = ugliNumbers[5] = true;

    generateUgliNumbers(ugliNumbers);
    // vector<int> uglies;
    // cout << NthUgliNumber(n, 0);
    return 0;
}
// 12 14 

// 2*2*2    3*3*3*    5*5*5*5 
// 2*3    3*5    5*2      2*3*5
