// Ines Prieto Centeno.....
// E46 ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using pelis = std::string;
using fechas = std::string;

struct cine {
	int cont;
	std::vector<fechas> f;
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int numFechas, numPelis;
	std::map<pelis, cine> tabla;
	std::string fecha, peli;
	std::cin >> numFechas;
	if (!std::cin) return false;
	for (int i = 0; i < numFechas; ++i) {
		std::cin >> fecha >> numPelis;
		for (int j = 0; j < numPelis; ++j) {
			getline(std::cin, peli);
			auto elem = tabla.find(peli);
			if (elem == tabla.end()) {
				tabla[peli].f.push_back(fecha);
				tabla[peli].cont = 1;
			}
			else {
				if (elem->second.f.back() == fecha) elem->second.cont++;
				else {
					elem->second.cont++;
					elem->second.f.push_back(fecha);
				}
			}
		}
	}
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
