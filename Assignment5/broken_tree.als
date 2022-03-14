sig Node {
  tree: set Node
}

one sig root extends Node {} // root is a subset of Node
pred GGTree{
 no n : Node | root in n.*tree //no node in the tree that points to the root
 -- 
 no n : Node | n in n.^tree //no node in the tree that points to another node such that it makes a loop (non-transitive)
 --
 all n : Node - root | n in root.^tree //all the nodes except the root has a root, there is only one root and the tree is one connected tree.
 -- 
 all n : Node | 
 all disj n1, n2 : n.tree |  
   no (n1.*tree & n2.*tree)  //o node points to itself (non-reflexive)
}

pred DJTree {
    Node in root.*tree // all reachable
    no iden & ^tree // no cycles
    tree in  Node lone -> Node //no transitive relation between nodes
    }

pred CostelloTree {
    // No node above root (no node maps to root)
    no tree.root
    // Can reach all nodes from root                
    all n: Node - root | n in root.^tree
    // No node maps to itself (irreflexive) 
    no iden & tree
    // No cycles                    
    no n: Node | Node in n.^tree
    // All nodes are distinct (injective)           
    tree.~tree in iden -- need this
}
run GGTree for 5

//check {GGTree iff DJTree} for 5
//check {CostelloTree iff DJTree} for 5
