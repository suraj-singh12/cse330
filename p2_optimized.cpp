#include <iostream>
using namespace std;

int getGCD(int n, int m) {
    if(m == 0) return n;
    return getGCD(m, n % m);
}

int main()
{
    int m, n;
    cin >> m >> n;

    int gcd = getGCD(n, m);

    int number = n / gcd;

    if(m % number == 0) 
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;
    
    return 0;
}