/*

Recursive Merge Sort

It is a two way merge sort and follows top down approach as it is recursive

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

void mergeSort(int A[], int l, int h) {
    if(l < h) {
        int mid = (h + l) / 2;
        mergeSort(A, l, mid);
        mergeSort(A, mid + 1, h);
        merge(A, l, mid, h);
    }
}

int main()
{
    int arr[] = {8, 3, 7, 4, 9, 2, 6, 5, 0, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, n - 1);
    
    for(auto x : arr) {
        cout << x << " ";
    }
    cout << endl;
}