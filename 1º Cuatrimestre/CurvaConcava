// Inés Prieto Centeno


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

/* COSTE DE LA FUNCION

	   |t(1) = v[0]
	   |
T(n) = |t(n/2) ---> log n
	   |
*/

// función que resuelve el problema
int resolver(std::vector<int> const&v, int ini, int fin) {
	if (ini == fin) return v[ini];
	else if (ini + 1 == fin) {
		if (v[ini] < v[fin]) return v[ini];
		else return v[fin];
	}
	else {
		int m = (ini + fin) / 2;
		if (v[m] < v[m - 1] && v[m] < v[m + 1]) return v[m];
		else if (v[m] < v[m - 1]) return resolver(v, m + 1, fin);
		else return resolver(v, ini, m);
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numElem;
	std::cin >> numElem;
	if (!std::cin)
		return false;
	std::vector<int> v(numElem);
	for (int i = 0; i< numElem; ++i)
		std::cin >> v[i];
	int sol = resolver(v, 0, numElem - 1);
	std::cout << sol << "\n";
	// escribir sol


	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso());


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
