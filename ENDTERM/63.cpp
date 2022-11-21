// Quick Sort
/*

works on the idea that, an element is in a sorted position 
    if all the elements before that element are smaller than it, and 
    all the elements after that are greater than it.

choose a pivot
and place it at its sorted position by doing partitioning (below steps)

then keep two pointers i, and j
move i until any element > pivot is not found,  (i++)
and move j untill any element < pivot is not found (j--)
as soon these stop, swap the elements,
do it till i <= j

at the end, j is the position at which pivot element is in its sorted form
then the list is partitioned into two parts 
    one left side of pivot, 
    another right side of pivot



note: minimum two elements should be there for performing two quicksort

quick sort is recursive in nature, and uses partitioning algo for sorting elements

*/