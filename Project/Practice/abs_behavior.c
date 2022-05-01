#include<limits.h>
#include <float.h>
#include <math.h>
/*@ 
 requires -5 <= (float)val <= 5;

 assigns \nothing;
 ensures FLT_MAX >= \result >= 0;
 ensures \is_finite((float) \result);
 behavior pos:
 	assumes 0 <= val;
 	ensures \result == val;
	
 behavior neg:
 	assumes val < 0;
	ensures \result == -val;
 complete behaviors;
 disjoint behaviors;
*/
int abs(float val){
	if(val < 0) return -val;
	return val;
}
void main(){
	float value = abs(5);
	value = abs(-5);
}
