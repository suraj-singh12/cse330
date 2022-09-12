// find 2 prime numbers with given sum

/*
Approach: 
generate prime numbers till sum
then use two pointer approach to find the numbers
*/
#include <bits/stdc++.h>
using namespace std;

void sieve(int n, vector<int> &primes) {
    bool prime[n];
    for(int i = 2; i < n; i++)
        prime[i] = true;

    for(int p = 2; p * p <= n; p++) {
        if(prime[p]) {
            for(int i = p * p; i < n; i += p)  
                prime[i] = false;
        }
    }

    for(int i = 2; i < n; i++) {
        if(prime[i]) {
            primes.push_back(i);
        }
    }
}

vector<int> primeNumToSum(int sum) {
    vector<int> primes;
    sieve(sum, primes);
    vector<int> ans {-1, -1};
    int start = 0, end = primes.size() - 1;
    while(start < end) {
        int total = primes[start] + primes[end];
        if(total > sum)
            end--;
        else if(total < sum)
            start++;
        else {
            ans[0] = primes[start];
            ans[1] = primes[end];
            return ans;
        }
    }
    return ans;
}

int main() 
{
    int n = 74;
    auto ans = primeNumToSum(n);
    for(auto x : ans) {
        cout << x << " ";
    }
    cout << endl;
}