Var 
    m, w, g, c : boolean;

Function safe(m, w, g, c : boolean) : boolean;
begin
    return ((m = g) & (m = w) & (m = c) | ((w != g) & (g != c)));
end;

Rule "M and G move safely"
    safe(!m, w, !g, c) & (m = g)
==>
    m := !m;
    g := !g;   
Endrule;

Rule "M and W move safely"
    safe(!m, !w, g, c) & (m = w)
==>
    m := !m;
    w := !w;   
Endrule;

Rule "M and C move safely"
    safe(!m, w, g, !c) & (m = c)
==>
    m := !m;
    c := !c;   
Endrule;


Rule "M move safely"
    safe(!m, w, g, c)
==>
    m := !m;  
Endrule;

Invariant 
    !(m & w & g & c);
    
Startstate
    m := false;
    w := false;
    g := false;
    c := false;
End;