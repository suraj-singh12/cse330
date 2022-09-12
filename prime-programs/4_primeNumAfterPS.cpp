// given 3 numbers : sum S, prime P, and n (no of primes)
// find n prime numbers after prime P that sum to S

#include <iostream>
#include <vector>
using namespace std;

// function to return prime number
bool isPrime(int n) {
    if(n <= 1) return false;
    if(n == 2 || n == 3) return true;
    if(n % 2 == 0 || n % 3 == 0) return false;

    for(int i = 5; i * i <= n; i += 6) {
        if(n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

bool generateAllPrimes(int n, int p, int s, vector<int> &primes) {
    
    for(int i = p + 1; i <= s; ++i) {
        if(isPrime(i))
            primes.push_back(i);
    }

    // if generated primes are less than n, then no need to proceed
    if(primes.size() < n) 
        return false;
    return true;    
}

void printAns(vector<int> &v) {
    for(int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
}

// function to find those n prime numbers which sum up to S
void findRequiredPrimes(int indx, int total, int n, int s, vector<int> &ans, const vector<int> &primes) {
    // use pick non pick algo
    if(total > s || indx == primes.size()) {
        // that means you are on wrong path
        return; 
    }
    if(total == s && ans.size() == n) {
        // if you found n primes, and total is equal to required sum, 
        // then this is the answer.
        printAns(ans);
        cout << endl;
        return;
    }

    // pick 
    ans.push_back(primes[indx]);
    findRequiredPrimes(indx + 1, total + primes[indx], n, s, ans, primes);
    ans.pop_back();

    // don't pick
    findRequiredPrimes(indx + 1, total, n, s, ans, primes);
}
int main() 
{
    int s = 54, n = 2, p = 3;
    vector<int> primes;
    int reply = generateAllPrimes(n, p, s, primes);
    if(reply == false) {
        cout << "given combination did not generate n primes, so can't proceed" << endl;
        return 0;
    }

    vector<int> ans;
    findRequiredPrimes(0, 0, n, s, ans, primes);
    return 0;
}


