Var 
    m, w, g, c, l : boolean;

Function safe(m, w, g, c, l : boolean) : boolean;
begin
    return ((m = g) & (m = l) & (m = w) & (m = c) & (m = m)| ((w != g) & (g != c) & (l != w) ));
end;

Rule "M and G move safely"
    safe(!m, w, !g, c, l) & (m = g)
==>
    m := !m;
    g := !g;   
Endrule;

Rule "M and W move safely"
    safe(!m, !w, g, c, l) & (m = w)
==>
    m := !m;
    w := !w;   
Endrule;

Rule "M and C move safely"
    safe(!m, w, g, !c, l) & (m = c)
==>
    m := !m;
    c := !c;   
Endrule;

Rule "M and L move safely"
    safe(!m, w, g, c, !l) & (m = l)
==>
    m := !m;
    l := !l;   
Endrule;

Rule "M move safely"
    safe(!m, w, g, c, l)
==>
    m := !m;  
Endrule;

Invariant 
    !(m & w & g & c & l);
    
Startstate
    m := false;
    w := false;
    g := false;
    c := false;
    l := false;
End;