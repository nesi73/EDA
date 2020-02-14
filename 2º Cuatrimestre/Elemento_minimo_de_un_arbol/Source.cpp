// Inés Prieto Centeno
//E46


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "bintree_ext.h"


template <typename T>


bintree_ext<T> leerArbol(T vacio) {

	T raiz;
	std::cin >> raiz;
	if (raiz == vacio) { // es un árbol vacío
		return {};
	}
	else { // leer recursivamente los hijos
		auto iz = leerArbol(vacio);
		auto dr = leerArbol(vacio);
		return { iz, raiz, dr };
	}

}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	// escribir sol	
	std::string tipo, vacio = "#";
	std::cin >> tipo;
	if (!std::cin) return false;
	if (tipo == "N") {
		bintree_ext<int> tree = leerArbol(-1);
		int menor = tree.resolver();
		std::cout << menor << "\n";
	}
	else {
		bintree_ext<std::string> tree = leerArbol(vacio);
		std::string menor = tree.resolver();
		std::cout << menor << "\n";
	}
	
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
