// Code the most general Kripke Structure

bit x
bool init_state = false

active proctype p() {
  if
    :: x = 0
    :: x = 1
  fi;
  //
  init_state = true;
  //
  do
  :: x = !x
  :: x = x
  od
}

ltl {  [](init_state ->  (<>x -> []x)) }  



