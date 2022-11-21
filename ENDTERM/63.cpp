// Quick Sort
/*

works on the idea that, an element is in a sorted position 
    if all the elements before that element are smaller than it, and 
    all the elements after that are greater than it.

choose a pivot
and place it at its sorted position by doing partitioning (below steps)

then keep two pointers i, and j
move i until any element > pivot is not found,  (i++)
and move j untill any element <= pivot is not found (j--)
as soon these stop, swap the elements,
do it till i <= j

at the end, j is the position at which pivot element is in its sorted form
then the list is partitioned into two parts 
    one left side of pivot, 
    another right side of pivot



note: minimum two elements should be there for performing two quicksort

quick sort is recursive in nature, and uses partitioning procedure for sorting elements

TC worst case : O(n^2) when array is sorted in ascending or descending order
Best case TC: O(nlogn) when unsorted array and is divided into 2 halves from middle every time
Average case : O(nlogn)


in selection sort, we select the first position,
find the smallest element and put it there
then we select second position, and 
find the next smallest element and put it there,
and so on till end.


Quick sort is also called 
-> selection exchange sort
-> partition exchange sort
-> quick sort
*/


#include <bits/stdc++.h>
using namespace std;

#define ll            long long

void swap(int *a, int *b) {
    int tmp = *a; 
    *a = *b;
    *b = tmp;
}

int partition(int A[], int l, int h) {
    int pivot = A[l];
    int i = l, j = h;
    do {
        do{ i++; }while(A[i] <= pivot);
        do{ j--; }while(A[j] > pivot);
        if(i < j) {
            swap(&A[i], &A[j]);
        }
    }while(i < j);
    swap(&A[l], &A[j]);

    return j;
}

void quickSort(int A[], int l, int h) {
    if(l < h) {
        int j = partition(A, l, h);
        quickSort(A, l, j);
        quickSort(A, j + 1, h);
    }
}
int main() {
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3, INT_MAX};
    int n = sizeof(A) / sizeof(A[0]);
    
    quickSort(A, 0, n - 1);

    for(int i = 0; i < n -1; ++i) {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}