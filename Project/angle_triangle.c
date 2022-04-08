/*@
 ensures (first + second + \result == 180);
 */
int last_angle(int first, int second){
	int third = 180 - first - second;
	return third;
}
int main(){
	int first = 30;
	int second = 40;
	int third = last_angle(first, second);
	//@ check (first + second + third == 180);
	//@ admit (first + second + third == 180);
	return 0;
}
