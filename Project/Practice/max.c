/*@
ensures \result >= a && \result >= b;
ensures \result == a || \result == b;
*/
int max(int a, int b){
	return (a > b) ? a : b;
}
void main(){
	int a = 3;
	int b = 5;
	int c = max(a, b);
	//@ assert c == a || c == b;
}
