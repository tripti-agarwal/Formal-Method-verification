
-- This presumably matches the first Huth-Ryan formula I'm giving you to encode in Asg6 --

one sig b extends U { }
sig S1, S2, S3 in U {}
some sig U { s : U }
---pred P[x,y,z:U] { x in S1 and y in S2 and z in S3 }
pred Q[x,y:U] {x in S1 and y in S2}
assert EA { ( ( (all y:U | Q[b,y] )
                and
	        (all x,y:U | Q[x,y] => Q[s[x], s[y]])
	      )
	      =>
	      (some z:U | Q[b,z] and Q[z,s[s[b]]])
	    )}

assert nEA {!( ( (all y:U | Q[b,y] )
                and
	        (all x,y:U | Q[x,y] => Q[s[x], s[y]])
	      )
	      =>
	      (some z:U | Q[b,z] and Q[z,s[s[b]]])
	    )}
check EA 
check nEA



 
