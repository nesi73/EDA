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
		int suma;
		int numTramosNavegables;
	}rio;

	size_t altura() const {

		return altura(this->raiz);

	}

	int resolver() {
		if (this->raiz == nullptr) return 0;
		rio sol = agua(this->raiz);
		return sol.numTramosNavegables;
	}

private:

	rio agua(Link const&p) {
		if (p->left == nullptr && p->right == nullptr) { //hoja
			return { 1,0 };
		}
		else if (p->left == nullptr) { //izq vacio
			rio nod = agua(p->right);
			int tramo = nod.numTramosNavegables;
			if (nod.suma >= 3) tramo++;
			if (p->elem == 0) return { nod.suma,tramo};
			int resta = nod.suma - p->elem;
			if (resta <= 0) return { 0,tramo };
			return { resta, tramo };
		}
		else if (p->right == nullptr) { //drch vacio
			rio nod = agua(p->left);
			int tramo = nod.numTramosNavegables;
			if (nod.suma >= 3) tramo++;
			if (p->elem == 0) return { nod.suma,tramo };
			int resta = nod.suma - p->elem;
			if (resta <= 0) return { 0,tramo };
			return { resta, tramo };
		}
		else { //los dos correctos
			rio izq = agua(p->left);
			rio drch = agua(p->right);
			int suma = izq.suma + drch.suma;
			int tramo = 0;
			if (izq.suma >= 3) tramo++;
			if (drch.suma >= 3) tramo++;
			tramo += izq.numTramosNavegables + drch.numTramosNavegables;
			if (p->elem == 0) return { suma, tramo };
			int resta = suma - p->elem;
			if (resta < 0) return { 0,tramo };
			else return { resta, tramo };
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
	bintree_ext<int> tree = leerArbol(-1);
	std::cout << tree.resolver() << "\n";
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
