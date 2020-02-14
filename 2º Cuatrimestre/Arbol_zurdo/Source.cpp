// Inés Prieto Centeno
//E46


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "bintree.h"

template <class T>

class bintree_ext : public bintree<T> {

	using Link = typename bintree<T>::Link;

public:

	bintree_ext() : bintree<T>() {}

	bintree_ext(bintree_ext<T> const& l, T const& e, bintree_ext<T> const& r) : bintree<T>(l, e, r) {}

	typedef struct {
		bool sol;
		int hijos;
	}tSol;

	size_t altura() const {

		return altura(this->raiz);

	}

	tSol resolver() {
		if (this->raiz == nullptr) return { true,0 };
		return zurdo(this->raiz);
	}

private:

	tSol zurdo(Link const&p) {
		if (p->left == nullptr && p->right == nullptr) return { true, 0 };
		else if (p->left == nullptr) {
			return { false, 1 };
		}
		else if (p->right == nullptr) {
			tSol iz = zurdo(p->left);
			return { iz.sol, iz.hijos + 1 };
		}
		else {
			tSol sol = { false,0 };
			tSol iz = zurdo(p->left);
			tSol dr = zurdo(p->right);
			if (iz.sol && dr.sol) {
				if (iz.hijos > dr.hijos) return { iz.sol, iz.hijos + dr.hijos + 1};
				return sol;
			}
			return sol;
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
void resuelveCaso() {
	// leer los datos de la entrada
	// escribir sol	
	bintree_ext<char> tree = leerArbol('.');
	if (tree.resolver().sol) std::cout << "SI" << std::endl;
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
