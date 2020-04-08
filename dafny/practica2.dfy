//Inés Prieto Centeno
//E46

2.1
method busquedaSecuencial (v : array<int>, x : int) returns (b : bool) 
requires v.Length > 0
ensures b == exists k :: 0<= k < v.Length && v[k] == x
{
	var i := 0; 
	while (i < v.Length && v[i] != x) 
		invariant 0 <= i <= v.Length
		invariant forall k :: 0 <= k < i ==> v[k] != x
		decreases v.Length - i
		{
			 i := i + 1;
		}
		b := (i < v.Length);
}


2.2
method busquedaSecuencial (v : array<int>, x : int) returns (b : bool, p : int) 
requires v.Length > 0
ensures b == exists k:: 0<= k < v.Length && v[k] == x && p == k
{
	p := 0; b := false;
	while (p < v.Length && v[p] != x) 
		invariant 0 <= p <= v.Length
		invariant forall k :: 0 <= k < p ==> v[k] != x
		decreases v.Length - p
		{
			 p := p + 1;
		}
		b := (p < v.Length);
}


2.3
method  ordenado (v : array<int>) returns (b : bool)
requires v.Length > 0
ensures b == (forall k:: 0<= k< v.Length-1 ==> (v[k] <= v[k+1])) 
{
	var i := 0; b := true;
	while (i < v.Length - 1 && b) 
	invariant v.Length == 0 || 0 <= i < v.Length
	invariant b == forall x :: 0 <= x  < i < v.Length ==> v[x] <= v[..][x+1]
	decreases v.Length - i
	{
		if (v[i] > v[i+1]) { b := false;}
		i := i+1;
	}
}


2.4
method primeroDistinto (a : array<int>, b : array<int>) returns (r : int)
requires a.Length > 0 && b.Length > 0 && a.Length == b.Length
ensures r != a.Length  ==> exists k :: 0<= k < a.Length && a[k] != b[k]
{
	r := 0;
	while (r < a.Length && a[r] == b[r]) 
		invariant 0 <= r <= a.Length 
		invariant forall x :: 0 <= x < r ==> b[x] == a[x]
		decreases  b.Length - r 
		{
			r:= r+1;
		}
}
