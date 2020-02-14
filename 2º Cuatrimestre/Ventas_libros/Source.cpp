//Ines Prieto Centeno

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <list>
using namespace std;

#include "libros.h"

bool resuelveCaso() {

	std::string x, orden;
	int numCasos;
	int n;
	std::cin >> numCasos;
	if (!std::cin)
		return false;

	libros l;

	while (numCasos > 0) {
		std::cin >> orden;
			if (orden == "nuevoLibro") {
				cin >> n;
				std::cin.get();
				getline(cin, x);
				l.nuevoLibro(n, x);
			}
			else if (orden == "comprar") {
				try {
					std::cin.get();
					getline(cin, x);
					l.comprar(x);
				}
				catch (std::invalid_argument e) {
					std::cout << e.what() << '\n';
					std::cout << "---\n";
				}
				catch (std::out_of_range e) {
					std::cout << e.what() << '\n';
					std::cout << "---\n";
				}
			}
			else if (orden == "estaLibro") {
				std::cin.get();
				getline(cin, x);
				if (l.estaLibro(x)) std::cout << "El libro " << x << " esta en el sistema" << "\n";
				else std::cout << "No existe el libro " << x << " en el sistema" << "\n";
				cout << "---" << "\n";
			}
			else if (orden == "elimLibro") {
				std::cin.get();
				getline(cin, x);
				l.elimLibro(x);
			}
			else if (orden == "numEjemplares") {
				try {
					std::cin.get();
					getline(cin, x);
					int numEjem = l.numEjemplares(x);
					cout << "Existen " << numEjem << " ejemplares del libro " << x << "\n";
					cout << "---" << "\n";
				}
				catch (std::invalid_argument e) {
					std::cout << "No existe el libro " << x << " en el sistema" << "\n";
					std::cout << "---\n";
				}
			}
			else if (orden == "top10") {
				std::list<std::string> lista = l.top10();
				for (auto const& sol : lista) {
						std::cout << sol << "\n";
				}
				cout << "---" << "\n";
			}
			else
				cout << "OPERACION DESCONOCIDA\n";
		numCasos--;
	}
	std::cout << "------\n";
	return true;
}

int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	// _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}
