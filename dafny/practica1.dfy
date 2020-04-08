//Inés Prieto Centeno
//E46

1.1
method swap (v : array<int>, i : int, j : int) 
requires v.Length > 0 && 0 <= i < v.Length && 0<=j<v.Length && j!=i
ensures v[i] == old(v[j]) && v[j] == old(v[i])
modifies v
{
	var aux := v[i];
	v[i] := v[j];
	v[j] := aux;
}

1.2
predicate par (n : int) 
requires n >= 0 
{n%2==0}

method verificaPar (v : array<int>) returns (b : bool)
requires v.Length > 0 && forall i:: 0 <= i < v.Length ==> v[i] > 0 //this??
ensures b == forall k :: 0 <= k < v.Length ==> (v[k]%2) == 0
{
var i := 0;
while (i < v.Length && v[i]%2 == 0)
invariant 0 <= i <= v.Length
invariant forall w :: 0 <= w < i ==> par(v[w])
{
i := i + 1;
}
b := i == v.Length;
}

1.3
method maximo (v : array<int>) returns (m : int)
requires v.Length > 0
ensures forall k:: 0 <= k < v.Length ==> m >= v[k]
{
	var i := 1;
	m := v[0];
	while (i < v.Length) 
	invariant 0 <= i <= v.Length
	invariant forall k :: 0 <= k < i ==> m >= v[k]
	invariant m in v[..i]
	decreases v.Length - i
	{
		if (m < v[i]) {m := v[i];}
		i := i+1;
	}
}
