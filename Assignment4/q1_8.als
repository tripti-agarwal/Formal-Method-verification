sig S { prt : set S}
fact {some prt}
fact reflexive { all x, y : S | ( (x -> y in prt) and (y -> x in prt) )}
fact trasitive {all x, y, z : S |  ( (x -> y in prt) and (y -> z in prt)) implies (x -> z in prt) }
fact antisymmetry {all x, y : S | ( (x -> y in prt) and (y -> x in prt) ) implies (x = y)}
assert prtAndPrtinvIden { prt & ~prt = iden}
check prtAndPrtinvIden for exactly 1 S
run {} for exactly 1 S
