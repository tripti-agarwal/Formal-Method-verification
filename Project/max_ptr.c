#include<math.h>
/*@
requires \valid(a) && \valid(b);
requires \separated(a, b);
ensures (*a > *b ==> \result == *a) && (*b >= *a ==> \result == *b);
*/
int max_ptr(int* a,int* b){
	return (*a < *b) ? *b : *a;
}
extern int h;
void main(){
	int *a = 24;
	int *b = 42;
	int max = max_ptr(a, b);
	//@ assert max == 42;
	//@ assert h == 42;
}
