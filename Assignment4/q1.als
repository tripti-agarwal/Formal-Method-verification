sig S {pre : set S}
fact {some pre}
run {} for exactly 4 S
fact reflexive { all x, y : S | ( (x -> y in pre) and (y -> x in pre) )}
fact trasitive {all x, y, z : S |  ( (x -> y in pre) and (y -> z in pre)) implies (x -> z in pre) }
assert preAndPreinvIden { pre & ~pre = iden}
check preAndPreinvIden for exactly 3 S
run {} for exactly 4 S