/*
find  the minimum length unsorted subarray from the array

[10, 12, 15, 32, 18, 11, 54, 19, 70, 80, 85]

ans: 7 


Approach: 
sort the array [10, 11, 12, 15, 18, 19, 32, 54, 70, 80, 85]
compare elements from left until an unmatching element is found
then from right until unmatching is not found

then return the difference between both ends
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {10, 12, 15, 32, 18, 11, 54, 19, 70, 80, 85};
    int n = sizeof(arr) / sizeof(arr[0]);

    int ans[n];
    for(int i = 0; i < n; ++i) ans[i] = arr[i];

    sort(ans, ans + n);
    int i = 0, j = n - 1;
    while(i < n && arr[i] == ans[i]) i++;
    while(j >= 0 && arr[j] == ans[j]) j--;

    cout << "Length: " << j - i + 1;
    return 0;
}