// given n players, two players play the match, 
// the one who wins plays with the remaining players provided difference between winner and another players's wins is 1 
// whosoever wins plays with the remaining players with above rule applied, and so on.

// find the maximum number of games played by the winner

#include <bits/stdc++.h>
using namespace std;


int maxGamesPlayed(int numberOfPlayers) {
    int first = 1, second = 2;
    numberOfPlayers -= 2;
    int ans = first + second;
    int count = 2;
    while(ans < numberOfPlayers) {
        ans = first + second;
        first = second;
        second = ans;
        count++;
    }
    return count;
}
int main()
{
    int numberOfPlayers = 10;
    for(numberOfPlayers = 10; numberOfPlayers < 20; ++numberOfPlayers)
    {
        cout << maxGamesPlayed(numberOfPlayers) << ", ";
    }
    cout << endl;
}