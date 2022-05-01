/*@ 
 ensures *a == \old(*b) && *b == \old(*a);
*/
void swap (int* a, int* b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void main(){
	int a = 42;
	Label_a:
	a = 45;
	//@ assert a == 45 && \at(a, Label_a) == 42;
}
