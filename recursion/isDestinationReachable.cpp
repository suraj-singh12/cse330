// check whether a destination is reachable from a source or not
// given destination coordinates D(d1, d2)
// given starting coordinates C(x, y)
// possible moves from C(x, y) : (x + y, y) or (x, x + y)
#include <iostream>
using namespace std;


bool isReachable(int d1, int d2, int x, int y) {
    if(x < d1 && y < d2) {
        return isReachable(d1, d2, x + y, x + y);
    }
    if(x < d1) {
        return isReachable(d1, d2, x + y, y);
    } else if(y < d2) {
        return isReachable(d1, d2, x, x + y);
    }
    if(x > d1 || y > d2) return false;
    return true;
}

int main() 
{
    int d1 = 4, d2 = 8, x = 2, y = 2;
    cout << (isReachable(d1, d2, x, y) ? "reachable" : "not-reachable");
    return 0;
}