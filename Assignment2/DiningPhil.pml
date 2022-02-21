/* Five dining philosophers  */
/* See run script at the end */

mtype = {are_you_free, yes, no, release}

byte progress;
bit prop1, prop2, prop3; //These help in determining whether to enter the LTL or not
proctype phil(chan lf, rf; int philno)
{
  do
  ::
    if
    :: _pid==1 -> prop1=1; prop1=0 
    :: _pid==2 -> prop2=1; prop2=0
    fi;
    do
    :: lf!are_you_free -> 
      if
        :: lf?yes -> break 
        :: lf?no
      fi
    od;
    do
    :: rf!are_you_free -> 
      if
        :: rf?yes -> 
 	    progress = 1; 
	    lf!release; 
	    rf!release;
 	    progress = 0; 
	    break
	    
        :: rf?no ->
	   lf!release;
	   break
      fi
    od     
  od
}
proctype phil1(chan lf, rf; int philno)
{
  do
  ::
    if
    :: _pid==3 -> prop3=1; prop3=0 
    fi;
    do
    :: rf!are_you_free ->
      if
        :: rf?yes -> break
        :: rf?no
      fi
    od;
    do
    :: lf!are_you_free ->
      if
        :: lf?yes ->
   	   progress = 1;
	   rf!release;
	   lf!release;
	   progress = 0;
	   break
	
        :: lf?no ->
	   rf!release;
   	   break
      fi
    od
  od
}

proctype fork(chan lp, rp)
{
  do

   :: rp?are_you_free -> rp!yes ->

        do
        :: lp?are_you_free ->
           lp!no
        :: rp?release -> break
        od

   :: lp?are_you_free -> lp!yes ->

      do
        :: rp?are_you_free ->
           rp!no
        :: lp?release -> break
      od;
  od
}

init {

   chan c0 = [0] of { mtype };
   chan c1 = [0] of { mtype };
   chan c2 = [0] of { mtype };
   chan c3 = [0] of { mtype };
   chan c4 = [0] of { mtype };
   chan c5 = [0] of { mtype };

   atomic {
     run phil1(c5, c0, 1);
     run phil(c1, c2, 2);
     run phil(c3, c4, 3);
     run fork(c0, c1);
     run fork(c2, c3);
     run fork(c4, c5);
   };
}
bool init_state = false
ltl {[](init_state -> ([]<>prop1 && []<>!prop1 &&  []<>prop2 && []<>!prop2 &&  []<>prop3 && []<>!prop3 && (<>[]!progress)))}
