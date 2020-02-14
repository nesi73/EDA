// Inés Prieto Centeno

#include <iostream>
#include <iomanip>
#include <fstream>

#include "new_queue.h"

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada

	int num;
	std::cin >> num;

	if (!std::cin)
		return false;

	cola<int> * c = new cola<int>();
	
	while (num != 0) {
		c->push(num);
		std::cin >> num;
	}

	c->duplicar();
	c->print();

	std::cin >> num;
	while (num != 0) { //meter n elementos a la cola
		c->push(num);
		std::cin >> num;
	}

	std::cin >> num;
	while (num > 0) { //quitar n elementos de la cola
		c->pop();
		num--;
	}

	c->print();
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
