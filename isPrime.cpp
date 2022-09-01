#include <iostream>
using namespace std;


bool isPrime(int n) {
    if(n <= 1) return false;
    
    for(int i = 2; i * i <= n; ++i) {
        if(n % i == 0) return false;
    }
    return true;
}

int main()
{
    int number = 2;
    cin >> number;
    auto ans = (isPrime(number) == true) ? "PRIME" : "NOT PRIME";
    cout << ans << endl;
}