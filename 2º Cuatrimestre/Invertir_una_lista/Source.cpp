// Inés Prieto Centeno
//E46


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Header.h"

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int num, elem, numInsertar, pos;
	std::cin >> num;
	if (!std::cin) return false;
	AñadirLista<int> *a = new AñadirLista<int>();
	std::cin >> elem;
	while (num > 0) {
		a->push(elem);
		std::cin >> elem;
		num--;
	}

	numInsertar = elem;
	std::cin >> pos;

	AñadirLista<int> *b = new AñadirLista<int>();
	while (numInsertar > 0) {
		std::cin >> elem;
		b->push(elem);
		numInsertar--;
	}
	a->insertar(b, pos);
	a->print();
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
