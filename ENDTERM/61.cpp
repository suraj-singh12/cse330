/*

[8, 3, 7, 4, 9, 2, 6, 5]
Given an array containing one list of 8 elements
and we have to sort them

merge sort sees it as:
given an array containing 8 lists of 1 element
and we have to sort them

since each list has only one element, all the lists are sorted already.
So now we need to merge the lists appropriately.
    Pass1: We take two lists and merge them pair by pair
    pass2: then again merge the merged lists with each other pair by pair
    pass3: then again merge, so on
    passN: until all the lists are merged into one sorted list

https://www.youtube.com/watch?v=xleF7ykgcHY
only iterative version has Passes, recursive does not have.
it has log2(n) passes, where n= no of elements in array

TC of iterative version of two way merge sort
TC: O(nlogn)
*/

#include <bits/stdc++.h>
using namespace std;

void merge(int A[], int l, int mid, int h) {
    int i = l, j = mid + 1;
    // cout << i << " " << j << "\n";
    int tmp[h - l + 1] = {0};       // tmp array to store the sorted array A[l..h]

    int idx = 0;
    while(i <= mid && j <= h) {
        if(A[i] < A[j]) {
            tmp[idx] = A[i];
            idx++;  i++;
        } else {
            tmp[idx] = A[j];
            idx++;  j++;
        }
    }
    // copy remaining elements of A[i]
    while(i <= mid) {
        tmp[idx++] = A[i++];
    }
    // copy remaining elements of A[j]
    while(j <= h) {
        tmp[idx++] = A[j++];
    }

    // copy the sorted tmp array to A[l..h]
    idx = 0;
    i = l;
    while(idx < (h - l + 1)) {
        A[i++] = tmp[idx++];
    }
}
void iMergeSort(int A[], int n) {
    int p, i, l, mid, h;

    for(p = 2; p <= n; p *= 2) {        // log2(n) times
        for(i = 0; i + p -1 < n; i += p) {      // n times
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            merge(A, l, mid, h);
        }
    }
    if(p / 2 < n) {
        merge(A, 0, p / 2 - 1, n -1);
    }
}

int main()
{
    int arr[] = {8, 3, 7, 4, 9, 2, 6, 5, 0, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    iMergeSort(arr, n);
    for(auto x : arr) {
        cout << x << " ";
    }
    cout << endl;
}




