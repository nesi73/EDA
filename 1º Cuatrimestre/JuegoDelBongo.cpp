// Inés Prieto Centeno

/*COSTE DE ESTE ALGORITMO
O(logn)
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
int resolver(std::vector <int> const&v, int ini, int fin, int num) {
	if (ini == fin) return v[ini];
	else if (ini + 1 == fin) {
		if (v[ini] == num + ini) return v[ini];
		else if (v[fin] == num + fin) return v[fin];
		else return -1;
	}
	else {
		int m = (ini + fin) / 2;
		if (v[m] == num + m) return v[m];
		else if (v[m] > num + m) return resolver(v, ini, m, num);
		else return resolver(v, m, fin, num);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int numElem, num;
	std::cin >> numElem;
	std::cin >> num;
	std::vector <int> v(numElem);
	for (int i = 0; i < numElem; ++i)
		std::cin >> v[i];
	int sol = resolver(v, 0, numElem - 1, num);
	if (sol == -1) std::cout << "NO\n";
	else std::cout << sol << "\n";
	// escribir sol
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
