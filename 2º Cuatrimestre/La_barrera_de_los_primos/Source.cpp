// Inés Prieto Centeno
//E46


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
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

std::vector<bool> primo(5002,true);

typedef struct {
	int num;
	int level;
}tSol;

tSol resolver(bintree<int> const&tree, std::vector<bool> const&primo,int altura) {
	if (!tree.empty()) {
		tSol sol = { 0,0 };
		tSol iz = resolver(tree.left(),primo,altura + 1);
		tSol dr = resolver(tree.right(), primo, altura + 1);
		if (tree.root() % 7 == 0 && primo[tree.root()] == false) {
			sol.num = tree.root();
			sol.level = altura;
		}
		if (primo[tree.root()] == true) return { 0,0 };
		if (iz.level == 0 && dr.level == 0) return sol;
		else if (iz.level == 0 && dr.level != 0) {
			if (sol.level > dr.level || sol.level == 0) return dr;
			else return sol;
		}
		else if (iz.level != 0 && dr.level == 0) {
			if (sol.level > iz.level || sol.level == 0) return iz;
			else return sol;
		}
		else {
			if (iz.level <= dr.level) {
				if (sol.level > iz.level || sol.level == 0) return iz;
				else return sol;
			}
			else {
				if (sol.level > dr.level || sol.level == 0) return dr;
				else return sol;
			}
		}
		return sol;
	}
	return { 0,0 };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	// escribir sol	
	bintree<int> tree = leerArbol(-1);
	int altura = 1;
	tSol sol;
	sol = resolver(tree, primo, altura);
	if (sol.level == 0 && sol.num == 0) std::cout << "NO HAY" << std::endl;
	else std::cout << sol.num << " " << sol.level << std::endl;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	for (int i = 2; i*i <= 5001; ++i) {
		if (primo[i]) {
			for (int j = 2 * i; j <= 5001; j += i) {
				primo[j] = false;
			}
		}
	}

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
