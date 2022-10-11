// print the items you are considering in knapsack

#include <bits/stdc++.h>
using namespace std;

struct item {
    int value;
    int weight;
    int pos;
};


bool comparator(item itm1, item itm2) {
    float val1 = itm1.value / float(itm1.weight);
    float val2 = itm2.value / float(itm2.weight);
    if(val1 >= val2) return true;
    return false;
}

int knapsack(item *items, int n, int W, vector<int> &bagItems) {

    int maxValue = 0;
    for(int i = 0; i < n; ++i) {
        if(W - items[i].weight >= 0) {
            maxValue += items[i].value;
            bagItems.push_back(items[i].pos);
            W = W - items[i].weight;
        }
    }
    return maxValue;
}

// recursively Knapsack: TC: O(2^n); SC: O(n)
int knapsackRec(int indx, int *values, int *weights, int n, int value, int W) {
    if(W == 0) return value;
    if(W < 0) return  0;
    
    if(indx == n) {
        if(W < 0) return 0;
        return value;
    }

    int pick = knapsackRec(indx + 1, values, weights, n, value + values[indx], W - weights[indx]);
    int nonPick  = knapsackRec(indx + 1, values, weights, n, value, W);
    // cout << pick << ":" << nonPick << ", ";
    return max(pick, nonPick);
}
int main() 
{
    // int values[] = {1,2,3};
    // int weights[] = {4,5,1};
    int weights[] = {3, 2, 5};
    int values[] = {30, 40, 60};
    int n = 3;
    int W = 6;

    cout << "Rec max value of knapsack: " << knapsackRec(0, values, weights, n, 0, W) << endl;

    item items[n];
    for(int i = 0; i < n; ++i) {
        items[i].value = values[i];
        items[i].weight = weights[i];
        items[i].pos = i + 1;
    }

    // sort the items by their value by weight order in descending order
    sort(items, items + n, comparator);
    // 

    vector<int> bagItems;   // will contain knapsack bag items
    cout << "Maximum value of knapsack: " << knapsack(items, n, W, bagItems) << endl;

    cout << "Items in knapsack bag: ";
    for(auto itm : bagItems) {
        cout << itm << " ";
    } 
    cout << endl;
    return 0;
}