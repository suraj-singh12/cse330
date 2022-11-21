// Sum of K Primes

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
    bool isSumOfKprimes(int n, int k)
    {
        if(n < 2 * k) return false;
        else if(k == 1) return isPrime(n);
        else if(k == 2) {
            if(n % 2 == 0) return true;
            return isPrime(n - 2);
        }
        else return true;
    }
};


int main()
{
    Solution ob;
	int t;
	cin>>t;
	while(t--)
	{
		int N,K;
		cin>>N>>K;
        if(ob.isSumOfKprimes(N,K))
		    cout<<"1\n";
        else
             cout<<"0\n";
	}
	return 0;
}
