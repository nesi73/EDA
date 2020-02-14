// Ines Prieto Centeno


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Header.h"

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int max, num;
	std::cin >> max;
	std::cin >> num;
	if (max == 0 && num == 0) return false;
	afortunado<int> *cola = new afortunado<int>();
	for (int i = 0; i < max; ++i) {
		cola->push(i+1);
	}
	int sol = cola->descartar(num);
	std::cout << sol << "\n";
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
