/* Five dining philosophers  */
/* See run script at the end */

mtype = {are_you_free, yes, no, release}

byte progress;

proctype phil(chan lf, rf; int philno)
{
  do
    :: do 
         :: lf!are_you_free ->
            if 
              :: lf?yes -> break
              :: lf?no;
            fi
       od;
  
       do
         :: rf!are_you_free ->
            if
              :: rf?yes;
                 progress = 1; progress = 0;
                 lf!release -> 
                 rf!release;
                 break;
              :: rf?no -> lf!release;
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
     run phil(c2, c1, 1);
     run fork(c3, c2);
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


