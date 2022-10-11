#include <bits/stdc++.h>
using namespace std;

void getMaxPairs(int indx, vector<pair<int, int>> &v,int &maxChain, vector<pair<int, int>> &ds) {
    if(indx == v.size()) {
        return;
    }
    if(v[indx].first > ds[0].second) {
        ds.pop_back();              // remove previous
        ds.push_back(v[indx]);      // store this; will be used next time
        maxChain++;                 // increment the chain length, if this is a valid pair
    }
    getMaxPairs(indx + 1, v, maxChain, ds);
}

bool comparator(pair<int, int> p1, pair<int, int> p2) {
    return p1.second < p2.second;
}
int main()
{
    vector<pair<int, int> > v = { {4,10}, {5,15}, {20,30}, {12,19}, {26, 29}, {34, 58} };
    // vector<pair<int, int>> v = {{1,2}, {7,8}, {4,5}};
    // vector<pair<int, int>> v = {{1,2},{2,3},{3,4}};

    sort(v.begin(), v.end(), comparator);
    for(auto x : v) {
        cout << "{" << x.first << ", " << x.second << "}, ";
    }
    cout << endl;

    vector<pair<int, int>> ds {{v[0].first, v[0].second}};
    int maxChain = 1;
    
    getMaxPairs(1, v, maxChain, ds);
    cout << maxChain << endl;
    return 0;
}