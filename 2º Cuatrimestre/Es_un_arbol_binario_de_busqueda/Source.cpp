// Inés Prieto Centeno
//E46


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree.h"

typedef struct {
	bool busqueda;
	int max;
	int min;
}tSol;

template <class T>

class bintree_ext : public bintree<T> {

	using Link = typename bintree<T>::Link;

public:

	bintree_ext() : bintree<T>() {}

	bintree_ext(bintree_ext<T> const& l, T const& e, bintree_ext<T> const& r) : bintree<T>(l, e, r) {}

	size_t altura() const {

		return altura(this->raiz);

	}

	bool resolver() {
		if (this->raiz == nullptr) return true;
		tSol sol = resolver_rec(this->raiz);
		return sol.busqueda;
	}

private:

	tSol resolver_rec(Link const&p) {
		if (p->left == nullptr && p->right == nullptr) return { true, p->elem,p->elem };
		else if (p->left == nullptr) {
			tSol dr = resolver_rec(p->right);
			if (dr.busqueda && dr.min > p->elem) return { true,std::max(dr.max, p->elem), std::min(dr.min, p->elem) };
			return { false,std::max(dr.max, p->elem), std::min(dr.min, p->elem) };
		}
		else if (p->right == nullptr) {
			tSol iz = resolver_rec(p->left);
			if (iz.busqueda && iz.max < p->elem) return { true,std::max(iz.max, p->elem), std::min(iz.min, p->elem) };
			return { false,std::max(iz.max, p->elem), std::min(iz.min, p->elem) };
		}
		else {
			tSol iz = resolver_rec(p->left);
			tSol dr = resolver_rec(p->right);
			int max = std::max(iz.max, dr.max);
			int min = std::min(iz.min, dr.min);
			if (dr.busqueda && dr.min > p->elem && iz.busqueda && iz.max < p->elem) return { true,std::max(max, p->elem), std::min(min, p->elem) };
			return { false,std::max(max, p->elem), std::min(min, p->elem) };
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
	// escribir sol	
	bintree_ext<int> tree = leerArbol_ext(-1);
	int sol = tree.resolver();
	if (sol) std::cout << "SI" << std::endl;
	else std::cout << "NO" << std::endl;
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
