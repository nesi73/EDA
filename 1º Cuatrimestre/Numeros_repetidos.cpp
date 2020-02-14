// Inés Prieto Centeno


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
int resolver(std::vector <int> const&v, int ini, int fin) {
	if (ini == fin) return 1;
	else if (ini + 1 == fin) {
		if (v[ini] == v[fin]) return 1;
		else return 2;
	}
	else {
		if (v[ini] != v[fin]) {
			int m = (ini + fin) / 2;
			if (v[m] != v[m - 1] && v[m] != v[m + 1]) return resolver(v, ini, m-1) + resolver(v, m + 1, fin) +1;
			else if (v[m] == v[m + 1]) return resolver(v, ini, m) + resolver(v, m + 1, fin) - 1;
			else return resolver(v, ini, m - 1) + resolver(v, m + 1, fin);
		}
		else return 1;
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numElem;
	std::cin >> numElem;
	if (numElem == 0)
		return false;
	std::vector<int> v(numElem);
	for (int i = 0; i < numElem; ++i)
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


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
