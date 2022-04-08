#include<limits.h>
/*@
requires \valid(p) && \valid(q);
requires \separated(p, q);
requires INT_MIN <= *p + *q <= INT_MAX;
assigns *p, *q;
ensures \result == *p + *q;
ensures INT_MIN <= \result <= INT_MAX;
*/
int add(int *p, int *q){
	return *p + *q;
}

int main(){
	int a = 24;
	int b = 42;
	int x;
	x = add(&a, &b);
	//@ assert x == a + b;
	//@ assert x == 66;
	x = add(&a, &a);
	//@ assert x == a + a;
	//@ assert x == 48;
}
