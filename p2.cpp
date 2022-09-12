// check the  number is divisible by all the prime factors of another number
// given n; check if n is divisible by all prime factors of m
#include <iostream>

using namespace std;

int main() {
    int m;
    cin >> m;
    int n;
    cin >> n;

    // generate prime factors of m and check if n is divisible by every prime factor that you generate
    // if at any place it fails, break out and return yes/no
    bool isDivisibleByAll = true;

    if(m % 2 == 0) {
        // if 2 is a prime factor of m
        // and n is not divisible by 2
        if(n % 2 != 0) {
            cout << "NO";
            return 0;
        } 

        // else reduce m
        while(m % 2 == 0) m /= 2;
    }

    for(int i = 3; i * i <= m; i += 2) {
        if(m % i == 0) {
            // if current no is a prime factor of m
            if(n % i != 0) {
                cout << "NO";
                return 0;
            }
            while(m % i == 0) m /= i;
        }
    }

    // if you have reached here, that means m is divisible by all prime factors of m
    cout << "YES" << endl;

    return 0;
}


// optimized: 
// gcd of (m,n)
// if gcd != 1
// and if m is divisible by n/gcd, then m is divisible by all prime factors of n
// 
// else if gcd == 1
// then m is prime and is not divisible by any prime factors of n

// m   n
// 27 18
// gcd 9                [find lcm , m * n / lcm = hcf or gcd]
// 18/9 = 2             num = [n / gcd]
// 27 not divisible by 2    if n is divisible by num then yes else no
// so ans: NO

