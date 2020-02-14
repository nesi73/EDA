// Inés Prieto Centeno

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
void resolver(std::vector <std::vector<int>> const&m, std::vector<int> &sol, std::vector<bool> &marcas, int k, int suma, int &sumaMax) {
	for (int i = 0; i < sol.size(); ++i) {
		sol[k] = m[k][i];
		suma = suma + m[k][i];
		if (!marcas[i]) {
			if (k == sol.size() - 1) {
				if (suma < sumaMax) {
					sumaMax = suma;
				}
			}
			else {
				marcas[i] = true;
				resolver(m, sol, marcas, k + 1, suma, sumaMax);
				marcas[i] = false;
			}
		}
		suma = suma - m[k][i];
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numElem, suma = 0, sumaMax = 9999999;
	std::cin >> numElem;
	if (numElem == 0)
		return false;
	std::vector <std::vector<int>> m(numElem, std::vector<int>(numElem));
	std::vector <bool> marcas(numElem);
	std::vector <int> sol(numElem);
	for (int i = 0; i < numElem; ++i) {
		for (int j = 0; j < numElem; ++j)
			std::cin >> m[i][j];
	}
	resolver(m, sol, marcas, 0, suma, sumaMax);
	std::cout << sumaMax << "\n";
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
