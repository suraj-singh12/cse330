// given a 2d array containing pixels of a screen, given a coordinate and a color value
// replace that pixel and all the adjacent pixels if they have value 2
// do it in a dfs manner

#include <bits/stdc++.h>
#define ll            long long
#define rd(n)         ll n; cin >> n
#define wt(n)         cout << n 
#define nl            cout << endl
#define forI(n)          for(ll i = 0; i < n; ++i)
#define forIE(a,b)       for(ll i = a; i <= b; ++i)
#define forD(n)         for(ll i = n - 1; i >= 0; --i) 
#define pb              push_back
#define fastIO          ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;


void doChange(vector<vector<ll>> &pixels, int x, int y, int color) {
    if(x < 0 || y < 0 || x >= pixels.size() || y >= pixels[0].size()) return;

    pixels[x][y] = color;
    // go up
    if(x > 0 && pixels[x -1][y] == 2)
        doChange(pixels, x - 1, y, color);
    // go down
    if(x < pixels.size() -1 && pixels[x + 1][y] == 2)
        doChange(pixels, x + 1, y, color);
    // go left
    if(y > 0 && pixels[x][y -1] == 2)
        doChange(pixels, x, y - 1, color);
    // go right
    if(y < pixels[0].size() - 1 && pixels[x][y + 1] == 2)
        doChange(pixels, x, y + 1, color);
}

int main()
{
    vector<vector<ll>> pixels {
        {0, 1, 1, 1, 0, 1, 0},
        {2, 1, 0, 1, 2, 1, 0},
        {1, 0, 2, 2, 2, 2, 0},
        {1, 2, 1, 1, 2, 2, 1},
        {0, 1, 2, 1, 2, 3, 1},
        {1, 0, 1, 1, 2, 2, 2}
    };

    ll x = 4, y = 5;
    ll color = 3;

    doChange(pixels, x, y, color);
    for(auto row : pixels) {
        for(auto val : row) {
            wt(val);    wt(" ");
        }
        nl;
    }
    return 0;
}