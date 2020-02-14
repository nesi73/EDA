// Ines Prieto Centeno.....
// E46 ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree.h"


typedef struct {
	int suma;
	int cont; 
}tSol;

template <class T>

class bintree_ext : public bintree<T> {

	using Link = typename bintree<T>::Link;

public:

	bintree_ext() : bintree<T>() {}

	bintree_ext(bintree_ext<T> const& l, T const& e, bintree_ext<T> const& r) : bintree<T>(l, e, r) {};

	size_t altura() const {
		return altura(this->raiz);
	}

	tSol explorar() {
		if (this->raiz == nullptr) return { 0,0 };
		return explorar(this->raiz);
	}


private:

tSol explorar(Link const&p) {
		if (p->left == nullptr && p->right == nullptr) {
			if (p->elem != 0) return { p->elem, 1 };
			return { p->elem, 0 };
		}
		else if (p->left == nullptr) { //no tiene hijo izq
			tSol dr = explorar(p->right);
			int tramo = dr.cont;
			if (tramo == 0 && (dr.suma != 0 || p->elem != 0)) tramo = 1;
			return { dr.suma += p->elem,tramo };
		}
		else if (p->right == nullptr) { //no tiene hijo derecho
			tSol iz = explorar(p->left);
			int tramo = iz.cont;
			if (tramo == 0 && (iz.suma != 0 || p->elem != 0)) tramo = 1;
			return { iz.suma += p->elem,tramo };
		}
		else {
			tSol iz = explorar(p->left);
			tSol dr = explorar(p->right);
			int max = std::max(iz.suma, dr.suma);
			return { max + p->elem, iz.cont + dr.cont };
		}
	}

	static size_t altura(Link r) {
		if (r == nullptr) {
			return 0;
		}
		else {
			return 1 + std::max(altura(r->left), altura(r->right));
		}
	}
};

template <typename T>

bintree_ext<T> leerArbol_ext(T vacio) {
	T raiz;
	std::cin >> raiz;
	if (raiz == vacio) { // es un árbol vacío
		return {};
	}
	else { // leer recursivamente los hijos
		auto iz = leerArbol_ext(vacio);
		auto dr = leerArbol_ext(vacio);
		return { iz, raiz, dr };
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	tSol sol;
	bintree_ext<int> tree = leerArbol_ext(-1);
	sol = tree.explorar();
	std::cout << sol.cont << " " << sol.suma << "\n";
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
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
