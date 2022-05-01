#include <limits.h>
/*@
requires x <= INT_MAX && y <= INT_MAX;
 ensures (\result == x+y) && (\result <= INT_MAX) && (\result >= INT_MIN);
 */
  
int add(int x, int y){
	return x+y;
}
int main(){
	int a = 0;
	int b = INT_MIN - 1;
	/* preconditions of add:
	 requires a <= INT_MAX && b <= INT_MAX;
	 requires a >= INT_MIN && b >= INT_MIN;
	 */
	int c = add(a, b);
}
