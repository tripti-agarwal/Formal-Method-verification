// C program for fast inverse sqaure root
#include<math.h>  
// function to find the inverse square root
/*@
requires \is_finite(number); 
requires number > 0;
requires sqrt((float)number) != 0;
ensures \result == 1/sqrt((float)number) && sqrt((float)number) != 0;
 */
float inverse_rsqrt( float number )
{
    const float threehalfs = 1.5F;
  
    float x2 = number * 0.5F;
    float y = number;
      
    // evil floating point bit level hacking
    long i = * ( long * ) &y;
      
    // value is pre-assumed
    i = 0x5f3759df - ( i >> 1 );
    y = * ( float * ) &i;
      
    // 1st iteration
    y = y * ( threehalfs - ( x2 * y * y ) );
      
    // 2nd iteration, this can be removed
    // y = y * ( threehalfs - ( x2 * y * y ) );
  
    return y;
}
  
// driver code
int main(){
      
    int n = 256;
    float f = inverse_rsqrt(n);
      
    return 0;
}
