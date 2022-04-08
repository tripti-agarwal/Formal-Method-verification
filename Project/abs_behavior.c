#include<limits.h>
/*@ 
 requires val > INT_MIN;
 assigns \nothing;
 ensures \result >= 0;
 behavior pos:
 	assumes 0 <= val;
	ensures \result == val;
 behavior neg:
 	assumes val < 0;
	ensures \result == -val;
 complete behaviors;
 disjoint behaviors;
*/
int abs(int val){
	if(val < 0) return -val;
	return val;
}
void main(){
	int value = abs(6);
	value = abs(-6);
}
