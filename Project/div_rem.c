/*@
requires \valid(q) && \valid(r);
requires \separated(q, r);
requires y != 0;
assigns *q, *r;
ensures *q == x / y;
ensures *r == x % y;
*/

void div_rem(unsigned x, unsigned y, unsigned* q, unsigned* r){
	*q = x / y;
	*r = x % y;
}
void main(){
	unsigned q;
	unsigned r;
	unsigned x = 5;
	unsigned y = 0;
	div_rem(x, y, &q, &r);
}
