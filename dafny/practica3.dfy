//Inés Prieto Centeno
//E46

3.1
method swap (v:array<int>, i:int, j:int)
requires 0<=i<v.Length && 0<=j<v.Length && i != j
ensures v[i] == old(v[j]) && v[j] == old(v[i])
modifies v
{
	assert v[i]==old(v[i]) && v[j]==old(v[j]);
	v[i]:=v[i]-v[j];
	assert v[i]+v[j]==old(v[i]) && v[j]==old(v[j]);
	v[j]:=v[i]+v[j];
  assert v[j]==old(v[i])&& v[j]-v[i]==old(v[j]);
	v[i]:=v[j]-v[i];
  assert v[i]==old(v[j]) && v[j]==old(v[i]);
}


3.2
function Fib (n : int) : int
requires n >= 0
{ if (n < 2) then n else Fib(n -2) + Fib(n -1) }

// Metodo que calcula el n-esimo termino de la sucesion
method Fibonacci (n : int) returns (f : int)
requires n>=0
ensures f == Fib(n)
{
    // Resolver el problema para los casos n == 0 y n == 1 antes de entrar en el bucle
    if (n == 0) { f := 0; }
    else if (n == 1) {f := 1;}
    else {
    
        // Inicializar las variables
        var i := 1;
    var f1 := 0;
    f := 1;
        // Bucle con invariante y funcion cota
        while (i <= n) 
        invariant 0 <= i <= n +1 && Fib(i) == f && Fib(i-1) == f1 
    decreases n-i
        {
            // Cuerpo del bucle
            f, f1 := f + f1, f; 
            i := i+1;
        }
    f := f1;
    }
}


3.3
function suma (s : seq<int>) : int
{if (s==[]) then 0 else s[0] + suma(s[1..])}

// Realizar un bucle que recorre el vector de derecha a izquierda
// Comenzar con el calculo de w[v.Length-1]
method acumulado (v : array<int>) returns (w : array<int>)
requires v != null && v.Length > 0
ensures w != null && w.Length == v.Length
ensures forall k :: 0 <= k < v.Length ==> w[k] == suma(v[k..])
{
    w := new int[v.Length];  // Reserva memoria para el vector
    // Inicializacion de las variable
    var i := v.Length -1;
    w[v.Length - 1] := v[v.Length - 1]; 
    // Bucle que recorre el vector de derecha a izquierda
    while (i > 0)
    invariant 0 <= i < v.Length
  invariant forall k :: i <= k < v.Length ==> w[k] == suma(v[k..])
    decreases i
    {
         w[i-1] := v[i-1] +w[i];
       i := i-1;
    
    }
}


3.4
predicate espico(s:seq<int>,i:int)
requires |s| > 0 && 0 <= i < |s|
ensures espico(s,i) == forall k :: 0 <= k < i ==> s[k] <= s[i] 

function CountPicos(s:seq<int>,i:int):nat 
requires 0<=i<|s| && |s| > 0
ensures i == 0 ==> CountPicos(s,i) == 1
ensures i > 0 && espico(s,i) ==> CountPicos(s,i) == CountPicos(s,i - 1) + 1
ensures i > 0 && !espico(s,i) ==> CountPicos(s,i) == CountPicos(s,i - 1)

method numPicos(v:array<int>) returns (n:int) 
requires v.Length > 0  && v.Length>0
ensures n==CountPicos(v[..],v.Length-1)
{
	// Inicializacion de las variables
	var j:=1;
  var max := 0;
	// Bucle con invariante funcion cota
	while (j<v.Length)
	invariant 1 <= j <=v.Length 
  invariant n == CountPicos(v[..], j-1)
	decreases v.Length - j
	{
		// Cuerpo del bucle
		if(v[j] >= max){
      max:=v[j];
      n:=n+1;
    }
    j:=j+1;
	}
}
