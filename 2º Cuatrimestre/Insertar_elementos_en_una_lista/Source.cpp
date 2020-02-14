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
	if (!std::cin) return false;
	InsertarLista<int> *cola = new InsertarLista<int>();
	for (int i = 0; i < max; ++i) {
		std::cin >> num;
		cola->push(num);
	}
	int numInser, prin;
	std::cin >> numInser;
	std::cin >> prin;
	InsertarLista<int> *cola2 = new InsertarLista<int>();
	for (int i = 0; i < numInser; ++i) {
		std::cin >> num;
		cola2->push(num);
	}
	cola->insertar(cola2, prin);
	cola->print();
	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while(resuelveCaso());


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
