// 30/08/2022
// Find minimum steps required to reach to the destination.
// In ith step we need to move i time.

// example: 
// -inf ... -4 -3 -2 -1 0 1 2 3 4 5 6 7 8 .... +inf
// reach 4 
// required steps = 4 (0 -1, -1 -3, -3 0, 0 4)

// reach 5
// required steps = 5 (0 1, 1 -1, -1 -4, -4 0, 0 5)

#include <iostream> 
using namespace std;


// retry
// int giveMinSteps(int reach, int steps = 1) {
//     if(steps > reach || reach < 0)      // for positive case
//     {
//         reach = reach + steps;
//         return giveMinSteps(reach, steps +1);
//     }
//     // for negative case
//     if(reach == steps) {
//         // cout << steps << "\n";
//         return steps;
//     }
    
//     return min(giveMinSteps(reach - steps, steps + 1), giveMinSteps(reach + steps, steps + 1));
// }


void giveMinSteps2(int destination, int x, int steps) {
    if(x < destination || (x - destination) % 2 != 0) {
        giveMinSteps2(destination, x + steps, steps + 1);
    } else {
        cout << steps -1 << "\n";
        return;
    }
}

int main() {
    int reach = 4;  
    // reach = 5;
    giveMinSteps2(reach, 0, 1);
    return 0;
}


/*
x < destination
x = destination
x > destination
d = x - destination

keep on going ahead till this is true 
    x < destination || x - destination is odd

if difference is even (x - destination is even) cout then
*/