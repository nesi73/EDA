// Inés Prieto Centeno


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector> 
// función que resuelve el problema
char resolver(std::vector<char> const&v,int ini, int fin) {
	if (ini == fin) return v[ini];
	else if (ini + 1 == fin) {
		if (v[ini] + 1 == v[fin]) return v[fin] + 1;
		else return v[ini] + 1;
	}
	else {
		int m = (ini + fin) / 2;
		if (v[m] - v[ini] == m - ini) resolver(v, m, fin);
		else resolver(v, ini, m);
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	char ini, fin;
	std::cin >> ini;
	std::cin >> fin;
	int numElem = fin - ini;
	std::vector<char> v(numElem);
	for (int i = 0; i < numElem; ++i)
		std::cin >> v[i];
	if (ini != v[0]) std::cout << ini << "\n";
	else if (fin != v[numElem - 1]) std::cout << fin << "\n";
	else {
		char sol = resolver(v, 0, numElem - 1);
		std::cout << sol << "\n";
	}
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	int num;
	std::cin >> num;
	for (int i = 0; i < num; i++) {
		resuelveCaso();
	}

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
