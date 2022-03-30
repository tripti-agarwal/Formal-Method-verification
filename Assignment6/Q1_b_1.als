
-- This presumably matches the first Huth-Ryan formula I'm giving you to encode in Asg6 --

one sig a extends U { }
sig S1, S2, S3 in U {}
some sig U { f : U }
pred P[x,y,z:U] { x in S1 and y in S2 and z in S3 }

assert EA { ( ( (all x:U | P[a,x,x] )
                and
	        (all x,y,z:U | P[x,y,z] => P[f[x], y, f[z]])
	      )
	      =>
	      (some z:U | P[f[a],z,f[a]])
	    )}

assert nEA {!( ( (all x:U | P[a,x,x] )
                and
	        (all x,y,z:U | P[x,y,z] => P[f[x], y, f[z]])
	      )
	      =>
	       (some z:U | P[f[a],z,f[a]])
	    )}
check EA 
check nEA



 
