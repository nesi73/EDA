// Inés Prieto Centeno

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using tMatriz = std::vector<std::vector<int>>;

// función que resuelve el problema
bool resolver(std::vector<int> const&m, int ini, int fin, int &suma) {
	if (ini + 1 == fin) {
		if (m[ini] < m[fin]) {
			suma = m[ini] + m[fin];
			return true;
		}
		else return false;
	}
	else {
		int sumaIzq, sumaDrch;
		int medio = (ini + fin) / 2;
		if (resolver(m, ini, medio, sumaIzq)) {
			if (resolver(m, medio + 1, fin, sumaDrch)) {
				if (sumaIzq < sumaDrch) {
					suma = sumaIzq + sumaDrch;
					return true;
				}
			}
		}
		return false;
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int filas, columnas, suma;
	bool degradado = true;
	std::cin >> filas;
	if (!std::cin)
		return false;
	std::cin >> columnas;
	tMatriz m(filas, std::vector<int>(columnas));
	for (int i = 0; i < filas; ++i) {
		for (int j = 0; j < columnas; ++j)
			std::cin >> m[i][j];
		if (resolver(m[i], 0, columnas - 1, suma) && degradado) degradado = true;
		else degradado = false;
	}
	// escribir sol
	if (degradado) std::cout << "SI\n";
	else std::cout << "NO\n";
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
