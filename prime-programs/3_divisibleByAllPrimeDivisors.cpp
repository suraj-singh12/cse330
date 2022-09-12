// check if a number is divisible by all prime divisors of another number

#include <iostream>
using namespace std;


// function to compute gcd
int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
}

// function to check if a number is divisible by all prime divisors of another number
bool check(int num1, int num2) {

    // if second number is 1, then clearly 1st is divisible by all prime divisors of 2nd (and we try to make the second number = 1,
    //  by dividing it by gcd of num1, num2 again and again in recursion)
    if(num2 == 1) return true;

    int gcd1 = gcd(num1, num2);
    // if gcd of both nums is 1, then it is never possible for num1 to be divisible by all prime divisors of num2
    // e.g. (23, 25); (5,6); (25, 6); (25, 30)
    if(gcd1 == 1) return false;

    // recursive call
    return check(num1, num2 / gcd1);
}
int main() 
{
    int num1, num2;
    // (50, 20):yes, (18, 12):yes, (25, 30):no, (25, 6):no ...
    cout << "Enter num1 and num2: ";
    cin >> num1 >> num2;
    cout << (check(num1, num2) ? "YES" : "NO") << endl;
}