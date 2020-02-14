// Ines Prieto Centeno.....
// E46 ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <list>
#include <sstream>
#include "bintree.h"

bintree<int> rellenarArbol(std::stack<int> &preO, std::stack<int> &inO) {
	if (preO.size() == 1 && inO.size() == 1)
		return bintree<int>(preO.top());
	else if (preO.size() == 0 && inO.size() == 0)
		return bintree<int>();
	int raiz = preO.top();
	preO.pop();

	std::stack<int> izquierdoPre;
	std::stack<int> derechoPre;

	std::stack<int> izquierdoIn;
	std::stack<int> derechoIn;

	while (inO.top() != raiz) {
		izquierdoIn.push(inO.top());
		inO.pop();

		izquierdoPre.push(preO.top());
		preO.pop();
	}
	inO.pop();
	while (!inO.empty()) {
		derechoIn.push(inO.top());
		inO.pop();

		derechoPre.push(preO.top());
		preO.pop();
	}

	return bintree<int>(rellenarArbol(izquierdoPre, izquierdoIn), raiz, rellenarArbol(derechoPre, derechoIn));
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int i=0, j=0, valor;
	std::string linea, linea2;
	getline(std::cin, linea);
	std::stringstream ss(linea);
	if (!ss) return false;
	getline(std::cin, linea2);
	std::stringstream ss2(linea2);
	std::stack<int> pre;
	std::stack<int> in;
	for (int i = 0; i < linea.size()/2; ++i) {
		ss >> valor;
		pre.push(valor);
	}
	for (int i = 0; i < linea2.size()/2; ++i) {
		ss2 >> valor;
		in.push(valor);
	}
	bintree<int> sol = rellenarArbol(pre, in);
	//pintarArbol(sol);
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
