/* Declare states that'll be used in Kripke structures */
mtype = {s0, s1, s2, s3}
/* Declare sa,... standing for kripke structure a, ... */
mtype = {sa, sb, sd, se, sf, sg, sh}
byte state=s0; /* Init state to s0 */
bit a=1;
/* Initial values of a and b */
bit b=1;

proctype generic(mtype structure)
{ if
	:: structure==sa ->
	do
		:: d_step{state==s0;a=1;b=1} -> d_step{state=s1;a=0;b=1}
		:: d_step{state==s0;a=1;b=1} -> d_step{state=s2;a=1;b=0}
		:: d_step{state==s1;a=0;b=1} -> d_step{state=s2;a=1;b=0}
		:: d_step{state==s2;a=1;b=0} -> d_step{state=s2;a=1;b=0}
		:: d_step{state==s2;a=1;b=0} -> d_step{state=s1;a=0;b=1}
	od
	:: structure==sb ->
	do
		:: d_step{state==s0;a=1;b=1} -> d_step{state=s0;a=1;b=1}
		:: d_step{state==s0;a=1;b=1} -> d_step{state=s1;a=0;b=1}
		:: d_step{state==s0;a=1;b=1} -> d_step{state=s2;a=1;b=0}
		:: d_step{state==s1;a=0;b=1} -> d_step{state=s2;a=1;b=0}
		:: d_step{state==s2;a=1;b=0} -> d_step{state=s2;a=1;b=0}
		:: d_step{state==s2;a=1;b=0} -> d_step{state=s3;a=0;b=0}
		:: d_step{state==s3;a=0;b=0} -> d_step{state=s1;a=0;b=1}
	od
  fi
/*
:: structure==sd -> ... similar ... */
}

init
{ run generic(sb -> sa) }
//ltl p1 {( !(<>([](a && b))) -> ((<>([]a)) || (<> (!  a && !  b))))}
ltl p2 {( !(<>([](a && b))) -> ( (<>([]a)) || (<> (b)) ) )}

