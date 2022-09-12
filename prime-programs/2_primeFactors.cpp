
// given a number, print all the prime factors of it, and their powers
#include <bits/stdc++.h>
using namespace std;

// prime factors of a big number
void primeFactors1(long long n) {

    // check for 2, how many times 2 divides the number
    int count = 0;
    while(n % 2 == 0) {
        count++;
        n = n >> 1;
    }
    if(count) cout << 2 << " " << count << endl;

    long long i = 3;
    // check all the possible prime numbers that can divide the number 
    // 3, 5, 7, 9, 11, 13, .... this is how we are looping [till sqrt(n)]
    while (i * i <= n) {
        count = 0;
        while(n % i == 0){ 
            count++;
            n = n >> 1;
        }
        if(count) cout << i << " " << count << endl;
        i += 2;
    }
    // corner case (say in case n = 3, we will fall here [in big numbers too we may fall here])
    if(n > 1) cout << n << " " << 1 << endl;
}




int main()
{
    // long long n;
    // cout << "Enter n : ";
    // cin >> n;
    // primeFactors1(n);

    long long n = 1000000000000000000;
    primeFactors1(n);
}