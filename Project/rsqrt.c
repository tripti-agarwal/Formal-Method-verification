#include <stdio.h>
#include <limits.h>
#include <math.h>
//maximum of float ---check
//look for the precondition warning in eva
//added the first requires from the warning of eva
//mpfr python library
/*@
requires \is_finite((float)number);
requires 0 <= number <= FLT_MAX; 
assigns \nothing;
ensures sqrt(number) != 0.0;
ensures \is_finite(\result);
*/
float rsqrt(float number){
	return 1/sqrt(number);
}
/*@
assigns \nothing;
ensures \result == 0;
*/

int main(){
	float x = 0.0;
	
	float output = rsqrt(x);
	//printf("rsqrt(%.10e) = %.10e\n", x, rsqrt(x));
	
	return 0;
}
