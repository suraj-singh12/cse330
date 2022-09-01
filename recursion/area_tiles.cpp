// having an area of N * M
// fill it with tiles of size 2^i * 2^i
// find min no of tiles required to fill it completely

#include <iostream>
using namespace std;

// 
int noOfTiles(int m, int n, int tiles = 0) {
    if(m == 0 || n == 0) return tiles;

    int i = 0;
    int minimum = min(m, n);
    while((1 << i) < minimum) i++;

    m -= (1<<i);
    n -= (1<<i);

    return noOfTiles(m, n, tiles + 1);
}

int main()
{
    int n = 6, m = 8;
    cout << noOfTiles(n,m);
    return 0;
}

