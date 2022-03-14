sig Queue { root: Node }
sig Node { next: lone Node }
fact nextNotReflexive { no n:Node | n = n.next }
fact allNodesBelongToSomeQueue {
    all n:Node | some q:Queue | n in q.root.*next 
}
//fact nextNotCyclic { no n:Node | n in n.^next }
pred show() {}
run show for 2
