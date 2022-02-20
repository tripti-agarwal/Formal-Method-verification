/* Five dining philosophers  */
/* See run script at the end */

mtype = {are_you_free, yes, no, release}

byte progress;

proctype phil(chan lh, rh; int philno)
{
  do
    :: philno%2==0 ->
      do 
          :: lh!are_you_free ->
              if 
                :: lh?yes -> break
                :: lh?no;
              fi
        od;
    
        do
          :: rh!are_you_free ->
              if
                :: rh?yes;
                  progress = 1; progress = 0;
                  lh!release -> 
                  rh!release;
                  break;
                :: rh?no -> lh!release;
                  break;
              fi
        od;
      :: philno%2!=0 ->
      do 
          :: rh!are_you_free ->
              if 
                :: rh?yes -> break
                :: rh?no;
              fi
        od;
    
        do
          :: lh!are_you_free ->
              if
                :: lh?yes;
                  progress = 1; progress = 0;
                  rh!release -> 
                  lh!release;
                  break;
                :: lh?no -> rh!release;
                  break;
              fi
        od;
      
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
     run phil(c5, c0, 0);
     run fork(c0, c1);
     run phil(c1, c2, 1);
     run fork(c2, c3);
     run phil(c3, c4, 2);
     run fork(c4, c5);
   };
}

never { /* Negation of []<> progress */
 do
 :: skip
 :: (!progress) -> goto accept;
 od;
 accept: (!progress) -> goto accept;
}


