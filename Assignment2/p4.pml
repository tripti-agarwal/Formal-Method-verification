// Code the most general Kripke Structure

bit x,y;
bit ready;

active proctype p() {
  do
  :: break
  :: x = !x
  :: y = !y
  od;
  ready = 1;
  do
  :: x = x
  :: y = y
  :: x = !x
  :: y = !y
  od
}

ltl  { [](ready -> ((<>[]x -> []<>y) -> ([]<>x -> []<>y))) }


