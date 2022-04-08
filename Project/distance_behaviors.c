#include <limits.h>
/*@
 ensures \result <= INT_MAX;
 assigns \nothing;
 behavior first:
 	assumes a < b;
	requires b - a <= INT_MAX;
	ensures a + \result == b;
 behavior second:
 	assumes b <= a;
	requires a - b <= INT_MAX;
	ensures a - \result == b;
 complete behaviors;
 disjoint behaviors;
*/
int distance (int a , int b){
	if(a < b) return b - a;
	else return a - b;
}
void main(){
	int max= distance(42, 34);
	max = distance(34, 42);
}
