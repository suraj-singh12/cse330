#include <iostream>
using namespace std;

int main()
{
    string str = "abcdefghi";
    cout << str.substr(0,1) << endl;
    cout << str.substr(1,1) << endl;
    cout << str.substr(2) << endl;
    // cout << str.substr(2) << endl;
    // cout << to_string(534) << endl;
    return 0;
}

// 10
// 1-5  1-5
// 2, 1-5 1-4
// 3, 1-5 1-3
// 4, 1-5 1-2
// 5, 1-5 1-1