#include <iostream>
#include <vector>
using namespace std;

void updateFreq(int n, vector<int> &freq) {
    int number = n;
    while(number) {
        int tmp = number % 10;
        freq[tmp]++;
        number /= 10;
    }
}

bool isPrime(int n, int i) {
    if(n <= 2)
        return (n == 2 ? true : false);
    
    if(n % i == 0)
        return false;

    if(i * i > n) 
        return true;
    
    return isPrime(n, i+1);
}

void generatePrimes(int l, int r, vector<int> &freq ) {
    for(int i = l; i <= r; ++i) {
        if(isPrime(i, 2)) {
            updateFreq(i, freq);
        }
    }
}
int main()
{
    int l = 1, r = 20;
    vector<int> freq(10,0);
    generatePrimes(l,r, freq);

    int maxFreq = 0;
    for(int i = 0; i < 10; ++i) {
        if(freq[i] > maxFreq)
            maxFreq = freq[i];
    }

    if(maxFreq == 0) {
        cout << "No primes found" << endl;
    } else {
        for(int i = 0; i < 10; ++i) {
            if(freq[i] == maxFreq) 
                cout << i << " has the highest frequency of " << freq[i] << "\n";
        }
    }
    return 0;
}