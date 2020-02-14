//Ines Prieto Centeno
//E46

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Intercambiar.h"

bool resuelveCaso() {
	int numElem, elem;
	Intercamb cola;

	std::cin >> numElem;

	if (numElem == 0) return false;

	for (int i = 0; i < numElem; ++i) {
		std::cin >> elem;

		cola.push(elem);
	}

	cola.cambiar();
	cola.print();

	return true;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso())
		;

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
