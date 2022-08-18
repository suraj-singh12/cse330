// print all the possible strings of length k from given n characters using recursion

#include <iostream>
using namespace std;


void getSubsetsOfLenK(int *characters, int n, int k, int indx = 0) {
    // abcd , k = 2
    // aa, bb, cc, dd, ab, ac, ad, ba, bc, bd, ca, cb, cd, da, db, dc
    // permutation

    for(int i = 0; i < n; ++i) {
        cout << characters[indx] + 
    }
}

int main() 
{

    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Enter n characters: ";
    int characters[n] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> characters[i];
    }

    int k;
    cout << "Enter k: ";
    cin >> k;

    getSubsetsOfLenK(characters, n, k);
}