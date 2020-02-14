// Inés Prieto Centeno
//E46


#include <iostream>
#include <iomanip>
#include <fstream>
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
	bool genealogico;
	int nivel;
}tSol;

tSol genealogico(bintree<int> const&tree, int altura) {
	if (tree.left().empty() && tree.right().empty()) return { false,0 };
	else if (tree.left().empty()) {
		tSol dr = genealogico(tree.right(), altura + 1);
		if (dr.genealogico) {
			if (tree.root() - tree.right().root() < 18) return { false, -1 };
			else return { true, dr.nivel };
		}
		return { false,-1 };
	}
	else if (tree.right().empty()) {
		tSol iz = genealogico(tree.left(), altura + 1);
		if (iz.genealog	ico) {
			if (tree.root() - tree.left().root() < 18) return { false, -1 };
			else return { true, iz.nivel};
		}
		return { false,-1 };
	}
	else {
		tSol sol = { false, 0 };
		tSol iz = genealogico(tree.left(), altura + 1);
		tSol dr = genealogico(tree.right(), altura + 1);
		if (tree.root() - tree.left().root() < 18) return { false,-1 };
		else if (tree.root() - tree.right().root() < 18) return { false, -1 };
		else if (tree.left().root() - tree.right().root() < 2) return { false, -1 };
		else return { true, altura + 1};
	}
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	// escribir sol	
	int altura = 1;
	bintree<int> tree = leerArbol(-1);
	if (!tree.empty()) {
		tSol sol = genealogico(tree, altura);
		if (sol.genealogico) std::cout << "SI " << sol.nivel << "\n";
		else std::cout << "NO \n";
	}
	else std::cout << "SI 0" << " \n";
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
