function gcd(x: nat, y: nat) : nat
requires x >= 0 && y >= 0
decreases x+y
{
    if (x == 0) then y
    else if (y == 0) then x
    else if (x == y) then y
    else if (x > y) then gcd(x-y, y)
    else gcd(x, y-x)
}
method gcdm(x : nat, y: nat) retuens (G: nat)
requires x >= 0
requires y >= 0
ensures G == gcd(x, y)
{
    var X, Y := x, y;
    while (X != Y && X > 0 && Y > 0)
    decreases X+Y
    invariant gcd(X, Y) == gcd(x, y)
    {
        if (X > Y){
            X := X - Y;
        }
        else {
            Y := Y - X;
        }
    }
    if (X == 0){
        G := Y;
    }
    else{
        G := X;
    }
}