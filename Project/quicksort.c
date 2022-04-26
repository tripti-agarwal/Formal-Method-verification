/* C implementation of QuickSort */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*@
predicate Swap{L1,L2}(int* a, integer i, integer j) =
     \at(a[i],L1) == \at(a[j],L2)
     && \at(a[j],L1) == \at(a[i],L2)
     && \forall integer k; k != i && k != j ==> \at(a[k],L1) == \at(a[k],L2);
*/

/*@
predicate sorted{L}(int* a, integer low, integer high) =
	\forall int k;
		low <= k < high ==> a[k] <= a[k+1];
*/
/*@ 
predicate equal{L1, L2}(int* a, integer i) = \at(a[i], L1) == \at(a[i], L2);
*/
/*@
predicate equality{L1, L2}(int* a, integer l, integer h) = \forall int i; l <= i <= h ==> equal{L1, L2}(a,i);
*/
/*@
inductive Permut{L1,L2}(int* a, integer l, integer h) {
    case Permut_refl{L}:
    	\forall int* a, integer l, h; Permut{L,L}(a, l, h) ;
    case Permut_sym{L1,L2}:
      \forall int* a, integer l, h;
        Permut{L1,L2}(a, l, h) ==> Permut{L2,L1}(a, l, h) ;
    case Permut_trans{L1,L2,L3}:
      \forall int* a, integer l, h;
        Permut{L1,L2}(a, l, h) && Permut{L2,L3}(a, l, h) ==>
         Permut{L1,L3}(a, l, h) ;
    case Permut_swap{L1,L2}:
      \forall int* a, integer l, h, i, j;
         l <= i <= h && l <= j <= h && Swap{L1,L2}(a, i, j) ==>
       Permut{L1,L2}(a, l, h) ;
}
*/

// A utility function to swap two elements


/*@
requires \valid(a) && \valid(b);
assigns *a, *b;
ensures \at(*a,Old) == \at(*b,Here) && \at(*b,Old) == \at(*a,Here);
*/


void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/* This function takes last element as pivot, places the pivot element at its correct position in sorted array, and places all smaller (smaller than pivot) to left of pivot and all greater elements to right
of pivot */

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */


/*@
requires \valid(arr + (low .. high)) && \separated(arr + (low ..high));
requires 0 <= low < INT_MAX;
requires 0 <= high < INT_MAX;
decreases high - low;
assigns *(arr + (low .. high));
*/


void quickSort(int *arr, int low, int high)
{
	
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place*/

        	int pivot = arr[high]; // pivot
		//@ assert equality{Pre, Here}(arr, low, high) && (pivot == arr[high]) && Permut{Pre, Here}(arr, low, high);
        	int i = low; // Index of smaller element and indicates the right position of pivot found so far
	        
		/*@
        		loop assigns j, i, *(arr + (low .. high));
	        	loop invariant 0 <= low <= j <= high + 1;
        		loop invariant 0 <= low <= i <= j;
	        	loop invariant \forall integer j; low <= j < i ==> arr[j] <= pivot;
        		loop variant high - j;
        	*/
        	for (int j = low; j <= high; j++)
        	{
                	// If current element is smaller than the pivot
                	if (arr[j] <= pivot)
                	{
                        	//@ assert \valid(&arr[i]);
                        	//@ assert \valid(&arr[j]);
			
                        	swap(&arr[i], &arr[j]);

                        	i++; // increment index of smaller element
                	}
			
        	}
		 
		// Separately sort elements before
		// partition and after partition
		if(i >= 2){
			
			quickSort(arr, low, i - 2);
		}
		if(i < INT_MAX){
			
	       		quickSort(arr, i, high);
		}
	}

}


// Driver Code


/*@
requires \true;
assigns \nothing;
ensures \result == 0;
*/


int main()
{
	int arr1[] = {10, 7, 8, 9, 1, 5};
	int n1 = sizeof(arr1) / sizeof(arr1[0]);
	quickSort(arr1, 0, n1 - 1);

	int arr2[] = {1, 2, 3, 4, 5};
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	quickSort(arr2, 0, n2 - 1);

	int arr3[] = {5, 4, 3, 2, 1};
        int n3 = sizeof(arr3) / sizeof(arr3[0]);
        quickSort(arr3, 0, n3 - 1);
	
	int arr4[] = {1, 1, 1, 1, 1};
	int n4 = sizeof(arr4) / sizeof(arr4[0]);
	quickSort(arr4, 0, n4 -1);
	return 0;
}
