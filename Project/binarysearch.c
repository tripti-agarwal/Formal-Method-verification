// C program to implement iterative Binary Search
#include <stdio.h>
 
// A iterative binary search function. It returns
// location of x in given array arr[l..r] if present,
// otherwise -1
//
/*@
predicate sorted{L}(int *arr, integer l, integer r) =
	\forall integer i, j; l <= i <= j <= r && \valid_read(arr+i) && \valid_read(arr+j) && \separated(arr+i, arr+j) ==> arr[i] <= arr[j];
*/

/*@
requires length >= 0 && \valid_read(arr + (0 .. length-1));
requires \separated(arr + (0 ..length-1));
requires \forall integer i, j; 0 <= i <= j < length  ==> arr[i] <= arr[j];
assigns \result;
ensures -1 <= \result <= length-1;
behavior success :
	ensures \result >= 0 ==> arr[\result] == x;
behavior failure :
	assumes sorted(arr, 0, length-1);
	ensures \result == -1 ==>
		\forall integer k; 0 <= k <= length-1 ==> arr[k] != x;
complete behaviors;
*/
int binarySearch(int arr[], int length, int x)
{  int l = 0;
   //@ assert l == 0;
   int r = length - 1;
   //@ assert r == length -1;



   /*@
   loop invariant 0 <= l &&  r <= length-1;  
   for failure:
   	loop invariant 
		\forall integer k; 0 <= k < length && arr[k] == x ==> l <= k <= r; 
   loop assigns l, r;
   loop variant r - l;
    */
    while (l <= r) {
        //@ assert 0 <= l <= r <= length -1;	
       int m = l + (r - l) / 2;
       
        // Check if x is present at mid
        if (arr[m] == x)
	    //@ assert arr[m] == x;
            return m;
 
        // If x greater, ignore left half
        if (arr[m] < x){
	    //@ assert arr[m] < x;
            l = m + 1;
	    //@ assert l == m+1;
	 }
 
        // If x is smaller, ignore right half
        else{
	    //@ assert arr[m] > x;
            r = m - 1;
	    //@ assert r == m-1;
	 }
    }
    //@ assert \forall integer k; 0 <= k < length ==> arr[k] != x;
 
    // if we reach here, then element was
    // not present
    return -1;
}
/*@
requires \true;
assigns \nothing;
ensures \result == 0;
*/
int main(void){
    int arr[] = { 2, 3, 4, 10, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    //@ assert \valid_read(arr+(0..n-1));
   
    int x = 100;
    int result = binarySearch(arr, n, x);
    //@ assert result == -1;
    x = 10;

    result = binarySearch(arr, n, x);
    //@ assert result == 3;
    return 0;
}
