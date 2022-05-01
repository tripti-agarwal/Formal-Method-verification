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
requires \valid(arr + (low .. high-1)) && \separated(arr + (low ..high-1));
requires 0 <= low <= high <= INT_MAX;
decreases (high-1) - low;
assigns *(arr + (low .. high-1));
*/

// [low, high)
void quickSort(int *arr, int low, int high)
{
	if (low != high) {
		int pivot = arr[low];
		int i = low, j = low, k = low;

		/*@
		 loop assigns i, j, k, *(arr+(low..high-1));
		 loop invariant low <= i;
		 loop invariant i <= j;
		 loop invariant j <= k;
		 loop invariant k <= high;
		 loop invariant high <= INT_MAX;
		 loop invariant \forall integer x; low <= x < i ==> arr[x] < pivot;
		 loop invariant \forall integer x; i <= x < j ==> arr[x] == pivot;
		 loop invariant \forall integer x; j <= x < k ==> arr[x] > pivot;
		 loop variant (high - k) + (high - i) + (high  - j);
		*/
		
		while (k != high) {
			if (arr[k] < pivot) {
				swap(&arr[i], &arr[k]);
				++i;
				if (i > j) 
					++j;
				
				if (j > k) 
					++k;
				
			} 
			else if (arr[k] == pivot) {
				swap(&arr[j], &arr[k]);
				++j;
				if (j > k) 
					++k;
				
			} 
			else if (arr[k] > pivot) 
				++k;
			
		}
		quicksort(arr, low, i);
		quicksort(arr, j, high);
	}
	else 
		return;
	

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
        quickSort(arr1, 0, n1);

	int arr2[] = {1, 2, 3, 4, 5};
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	quickSort(arr2, 0, n2);

	int arr3[] = {5, 4, 3, 2, 1};
        int n3 = sizeof(arr3) / sizeof(arr3[0]);
        quickSort(arr3, 0, n3);
	
	int arr4[] = {1, 1, 1, 1, 1};
	int n4 = sizeof(arr4) / sizeof(arr4[0]);
	quickSort(arr4, 0, n4);
	return 0;
}/* C implementation of QuickSort */

