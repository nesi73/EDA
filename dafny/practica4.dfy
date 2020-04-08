//INES PRIETO CENTENO
//E46
1.
method problema3 (a : array<int>, p : int) returns (b : bool)
requires a.Length > 0
requires 0 <= p < a.Length
ensures b == forall u, w :: 0 <= u <= p < w < a.Length ==> a[u] < a[w]
{
	// calculo del maximo de la parte izquierda
	// Inicializacion
	var max := a[0];
  var i :=0;

	// Bucle
	while (i <= p) 
	invariant 0 <= i <= p+1
	invariant forall k:: 0<= k < i ==> max >= a[k]
	invariant max in a[..p+1]
	{
		// Instrucciones del bucle
	
      if(a[i]>max) {
        max:=a[i];
      }
 
		 i:= i+1;
	}
	// probar que la variable max tiene el maximo de la parte izquierda
	assert forall k :: 0 <= k <= p ==> max >= a[k];
	assert max in a[..p+1];
	// Bucle para comprobar que el maximo de la parte izquierda es menos que 
	// todos los valores de la derecha
  
  bool correcto;
	while (correcto && i < a.Length) 
	invariant p <= i <= a.Length
  invariant b ==> forall u, w :: 0 <= u <= p < w < i ==> a[u] < a[w]
	{
		// Instrucciones del bucle
    if (max >= a[i])
    {
      correcto := false;
    }
    
    i:= i +1;
	}
	// Posibles instrucciones de finalizacion
  b := correcto;

}

2.
// Implementar un metodo que cuente el numero de valores de un vector que son mayores 
// que todos los valores a su derecha

// Definir un predicado que sea cierto todos los valores a la derecha de la posicion i
// son menores que el valor de la posicion i
predicate esMirador(s:seq<int>,i:int)
requires 0<=i<|s|
{ forall k::i<k<|s| ==> s[i]>=s[k]}

// definir una funcion que cuente el numero de miradores de una secuencia
function CountMiradores(s:seq<int>,i : int):nat
requires 0<=i<|s| && |s| > 0
decreases |s|-i
{
	if (i == |s| - 1) then 1
	else if (i < |s| - 1 && esMirador(s,i)) then 1 + CountMiradores(s,i+1)
	else CountMiradores(s,i+1)
}

3.
// Implementar un metodo que cuente el numero de miradores de un vector
method numMiradores(v:array<int>) returns (n:int)
requires v.Length>0
ensures n==CountMiradores(v[..],0)
{
	// Inicializar variables
	var i := v.Length-1;
  var max :=v[i];
  n := 1;
	
	// Bucle
	while (i>0)
	invariant 0<= i< v.Length;
  invariant forall k:: i<=k < v.Length ==> max >= v[k];
  invariant max in v[..]
  invariant forall k:: 0 < i <= k < v.Length - 1 ==> n == CountMiradores(v[k..],1)
	{
		// Cuerpo del bucle
    if(max< v[i-1])
    {
     max := v[i-1];
    }
    else
    {
      n:= n+1;
    }
		
		i := i -1;
	}
}
4.
// Implementar un metodo que elimine los valores iguales a x de un vector v
// Debe resolverse con complejidad lineal
// tam :  numero de elemento diferentes de x en el vector v de entrada. 
// El vector modificado debe tener estos elementos en las tam primeras posiciones
// Se probará primero que el valor x no aparece en las tam primeras posiciones
// Despues escribir otra postcondicion que indique que los tam primeros valores del 
// vector modificado estan en el vector original
method eliminar (v : array<int>, x : int) returns (tam : int)
requires v.Length > 0
ensures 0 <= tam < v.Length
modifies v
{
	// Inicializar las variables
	var i := 0;
  var j := 0;
	//bucle
	while (i < v.Length) 
	invariant 0<= i <= v.Length
  invariant forall k:: 0 <= k <= j < v.Length ==> v[k]!=x
	{
		//Cuerpo del bucle
		if(v[i] != x){
      v[j] := v[i];
      j:= j + 1;
    }
    i:=i+1;
}
v.Length := j + 1;
tam := j;
}


// Implementar un metodo que calcule el n-esimo numero de Jacobsthal
// Funcion que define los numeros de Jacobsthal
function Jacob (n : int) : int
requires n >= 0
ensures n < 2 ==> Jacob(n) == n
ensures n >= 2 ==> Jacob(n) == Jacob(n-1) + 2 * Jacob(n-2)
{
	if (n < 2) then n
	else Jacob(n-1) + 2 * Jacob(n-2)
}

// Implementar el metodo
method Jacobsthal (n : int) returns (j : int)
requires n >= 0
ensures j == Jacob(n)
{
	// Resolver los casos n == 0 y n == 1
  if(n == 0 || n == 1) {
    j:= n;
  }

	// Inicializar las variables para el caso > 2
  var j1:= 0;
  var j2:=0;
	// Bucle para realizar el calculo
	while (n > 2)
	invariant 1 < n
	{
		// Cuerpo del bucle
		j1 := n - 1;
    j2 := n - 2;
    j := j1 + 2*j2;
		n := n - 1;
	} 
}
