#include <bits/stdc++.h>
using namespace std;


// TC: O(sqrt(n))
bool isPrime1(int n) {
    if(n <= 1) return false;

    if(n == 2 || n == 3) return true;

    if(n % 2 == 0 || n % 3 == 0) return false;

    for(int i = 5; i * i <= n; i += 6) {
        if(n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

// i is current divisor, and n is the number
bool isPrime1_rec(int n, int i) {
    // numbers <=2 will be trapped here
    if(n <= 2) 
        return (n == 2)? true : false;
    
    // non-prime numbers will be trapped here
    if(n % i == 0) 
        return false;
    
    // numbers like 3,5,7 .. and other primes will fall in here
    if(i * i > n) 
        return true;
    
    // will go upto sqrt(n)
    return isPrime1_rec(n, i+1);
}

int main()
{
    int n = 2;
    cout << "Enter the number: ";
    cin >> n;
    cout << (isPrime1(n) ? "YES": "NO") << endl;
    cout << (isPrime1_rec(n, 2) ? "YES": "NO") << endl;
}