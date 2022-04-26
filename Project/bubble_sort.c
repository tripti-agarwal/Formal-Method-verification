// C program for implementation of Bubble sort
#include <stdio.h>
#include <limits.h>
//Predicate for sorted array
/*@
predicate sorted{L}(int* a, integer low, integer high) = 
	\forall int k;
		low <= k < high ==> a[k] <= a[k+1];
*/


//This predicate is for the permutations when we a swap is performed
/*@
predicate Swap{L1,L2}(int* a, integer i, integer j) =
     \at(a[i],L1) == \at(a[j],L2)
     && \at(a[j],L1) == \at(a[i],L2)
     && \forall integer k; k != i && k != j ==> \at(a[k],L1) == \at(a[k],L2);
*/


//These are certain rules that needs to be followed when performing sorting. 
//Reflexive, transitve, and symmetric. Finally we also might have to swap at certain point
//The last case is about swaping
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



/*@
requires \valid(xp) && \valid(yp);
requires \separated(xp, yp);
assigns *xp, *yp;
ensures \at(*xp,Old) == \at(*yp,Here) && \at(*yp,Old) == \at(*xp,Here);
*/
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
/*@
requires INT_MAX >= n >= 0;
requires \valid(arr+(0..n-1));
assigns arr[0 .. n-1];
behavior sort:
	ensures sorted{Here}(arr, 0, n-1);
behavior permute: 
	ensures Permut{Old,Here}(arr, 0, n-1);
complete behaviors;
*/
//a ghost variable is just used so that the permuatation in the second for loop is performed only when swap is performed
void bubbleSort(int arr[], int n)
{
   int i, j;
   i = j = 0;
   //@ ghost int swap_var = 0;
   /*@
   loop invariant 0 <= i < n;
   loop assigns i;
   loop invariant sorted{Here}(arr, n-i-1, n-1);
   loop invariant 0 < i < n ==> (\forall int a, b; 0 <= b <= n-i-1 <= a < n ==> arr[a] >= arr[b]);
   loop invariant 0 < i < n ==> (Permut{Pre,Here}(arr,0,n-1));
   loop variant n-i;
   */
   for (i = 0; i < n-1; i++)    
   //@ ghost swap_var = 0;  
/*@
    loop invariant 0 <= j < n-i;
    loop assigns j;
    loop invariant 0 < j < n-i ==> \forall int a; 0 <= a <= j ==> arr[a] <= arr[a+1];
    loop invariant 0 < j < n-i ==> (swap_var == 1) ==> Permut{Pre,Here}(arr, 0, n-1);
    loop variant n-i-1-j;   
    */
       for (j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1]){
		//@ ghost swap_var = 1;  
              swap(&arr[j], &arr[j+1]);
	   }
}
 
// Driver program to test above functions
/*@
requires \true;
assigns \nothing;
ensures \result == 0;
*/
int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    bubbleSort(arr, n);
    //@ assert \forall int k; 0 <= k < n-1 ==> \at(arr[k], Here) <= \at(arr[k+1], Here);
    return 0;
}
