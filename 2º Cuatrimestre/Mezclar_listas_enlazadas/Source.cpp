// Ines Prieto Centeno

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Header.h"

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int num;
	MezclarLista<int> *cola = new MezclarLista<int>();
	MezclarLista<int> *cola2 = new MezclarLista<int>();
	std::cin >> num;
	while (num != 0) {
		cola->push(num);
		std::cin >> num;
	}
	std::cin >> num;
	while (num != 0) {
		cola2->push(num);
		std::cin >> num;
	}
	cola->mezclar(cola2);
	cola->print();
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	int max;
	std::cin >> max;
	for (int i = 0; i < max; ++i) {
		resuelveCaso();
	}


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
