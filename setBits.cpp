#include <iostream>
using namespace std;

int main() 
{
    int x = 100;
    for(int i = 0; i < 26; ++i) {
        cout << (1 & (x >> i)) << " ";
    }
}