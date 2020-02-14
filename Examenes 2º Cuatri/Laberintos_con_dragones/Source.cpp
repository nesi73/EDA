// Inés Prieto Centeno
//E46


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "bintree.h"

template <typename T>

bintree<T> leerArbol(T vacio) {
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

typedef struct {
	std::string nombre;
	int dragones;
}tSol;

tSol resolver(bintree<std::string> tree) {
	if (tree.left().empty() && tree.right().empty()) {
		if (tree.root() == "Dragon") return { " ", 1 };
		return { tree.root(),0 };
	}
	else if (tree.left().empty()) {
		tSol dr = resolver(tree.right());
		if (tree.root() == "Dragon") return { dr.nombre, dr.dragones + 1};
		return { dr.nombre, dr.dragones };
	}
	else if (tree.right().empty()) {
		tSol iz = resolver(tree.left());
		if (tree.root() == "Dragon") return { iz.nombre, iz.dragones + 1 };
		return { iz.nombre, iz.dragones };
	}
	else {
		int cont = 0;
		tSol iz = resolver(tree.left());
		tSol dr = resolver(tree.right());
		if (tree.root() == "Dragon") cont = 1;
		if (iz.dragones <= dr.dragones) return { iz.nombre, iz.dragones + cont };
		return { dr.nombre, dr.dragones + cont };
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	// escribir sol	
	std::string vacio = "...";
	bintree<std::string> tree = leerArbol(vacio);
	if (tree.empty()) std::cout << "  0" << std::endl;
	else {
		tSol sol = resolver(tree);
		std::cout << sol.nombre << " " << sol.dragones << std::endl;
	}
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
