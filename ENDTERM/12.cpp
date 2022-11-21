// Primes sum

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
   bool isPrime(int n) {
        if(n <= 1) return false;
        if(n <= 3) return true;
        if(n % 2 == 0 || n % 3 == 0) return false;
        for(int i = 5; i * i <= n; i += 6) {
            if(n % i == 0 || n % (i + 2) == 0) return false;
        }
        return true;
    }
    string isSumOfTwo(int N){
        if(N < 2) return "No";
        if(N % 2 == 0) return "Yes";
        else return isPrime(N - 2) ? "Yes" : "No";
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.isSumOfTwo(N) << endl;
    }
    return 0;
}
