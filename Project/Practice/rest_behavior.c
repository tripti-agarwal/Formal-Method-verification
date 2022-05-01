/*@
requires \valid(a) && \valid_read(b);
requires \separated(a, b);

assigns *a;
behavior old:
    assumes *b;
    ensures *a == 0 && *b == \old(*b);
behavior notold:
    assumes !(*b);
    ensures *a == \old(*a) && *b == \old(*b);
complete behaviors;
disjoint behaviors;
*/
void reset_1st_if_2nd_is_true(int* a, int const* b){
    if(*b) *a = 0;
}
void main(){
    int *a = 3;
    int const* b = 1;
    reset_1st_if_2nd_is_true(a, b);
}
