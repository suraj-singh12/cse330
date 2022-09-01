// print all the possible strings of length k from given n characters using recursion

#include <iostream>
using namespace std;


void getSubsetsOfLenK(int indx, char *characters, int n, int k, string subsets) {
    // abcd , k = 2
    // aa, bb, cc, dd, ab, ac, ad, ba, bc, bd, ca, cb, cd, da, db, dc
    // permutation
    if(k == 0) {
        cout << subsets << endl;
        return;
    }

    for(int i = 0; i < n; ++i) {
        // suppose k = 2, for abcd characters
        // push a
        // subsets += characters[i];
        // call k - 1 = 1
        if(i == indx) 
            continue;
        getSubsetsOfLenK(i, characters, n, k - 1, subsets + characters[i]);
        // subsets.pop_back();
    }

    // for k - 1 = 1, i = 0 again, we take a in consideration and call k - 1 = 0, return subsets 'aa'
    // coming back in k-1 = 1 loop, (previous recursion), push b, call k - 1 = 0, return subsets 'ab'
    // and so on 
}

int main() 
{

    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Enter n characters: ";
    char characters[n] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> characters[i];
    }

    int k;
    cout << "Enter k: ";
    cin >> k;

    string ans;
    getSubsetsOfLenK(-1,characters, n, k, ans);
}