/*@

assigns \nothing
ensures \result == 0 || \result == 1;
behavior vowel:
    assumes c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    ensures \result == 0;
behavior cons:
    assumes c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u';
    ensures \result == 1;
complete behaviors;
disjoint behaviors;
*/
enum Kind {VOWEL, CONSONANT};
enum Kind kind_of_letter(char c){
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
        return VOWEL;
    }
    else return CONSONANT;
}
void main(){
    int val = kind_of_letter('s');
}