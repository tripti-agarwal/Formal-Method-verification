/*@
ensures (\result == a - b) || (\result == b - a);
*/
int distance (int a, int b){
	if(a < b) return b - a;
	else return a - b;
}
