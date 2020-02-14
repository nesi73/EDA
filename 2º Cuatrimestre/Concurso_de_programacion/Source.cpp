// Ines Prieto Centeno
// E46
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>

using nombreEquipo = std::string;
using nombreEjer = std::string;

typedef struct {
	int tiempo;
	bool valido;
}tPrueba;

typedef struct {
	int ejer;
	int tiempo;
}tSol;

typedef struct {
	std::string nombre;
	tSol p;
}tSol2;

bool ordenar(tSol2 s1, tSol2 s2) {
	return (s1.p.ejer > s2.p.ejer) || (s1.p.ejer == s2.p.ejer && s1.p.tiempo < s2.p.tiempo) || (s1.p.ejer==s2.p.ejer && s1.p.tiempo == s2.p.tiempo && s1.nombre< s2.nombre);
}

void mostrarSolucion(std::vector<tSol2> ordenar) {
	for (auto const& sol : ordenar) std::cout << sol.nombre << " " << sol.p.ejer << " " << sol.p.tiempo << "\n";
}

void resuelveCaso() {
	std::map<nombreEjer, tPrueba> ejer;
	std::map<nombreEquipo, std::map<nombreEjer, tPrueba>> equipo;
	std::string linea, palabra, ejercicio, bm;
	int tiempo;
	std::cin >> palabra;
	while (palabra != "FIN" && std::cin) {
		std::cin >> ejercicio;
		std::cin >> tiempo;
		std::cin >> bm;
		auto elem = equipo.find(palabra);
		tPrueba p;
		if (elem == equipo.end()) {
			std::map<nombreEjer, tPrueba> nuevo;
			if (bm == "AC") {
				p.tiempo = tiempo;
				p.valido = true;
				nuevo[ejercicio] = p;
				equipo[palabra] = nuevo;
			}
			else {
				p.valido = false;
				p.tiempo = 20;
				nuevo[ejercicio] = p;
				equipo[palabra] = nuevo;
			}
		}
		else {
			auto elem2 = elem->second.find(ejercicio);
			if (elem2 == elem->second.end()) {
				if (bm == "AC") {
					p.tiempo = tiempo;
					p.valido = true;
					elem->second[ejercicio] = p;
					equipo[palabra] = elem->second;
				}
				else {
					p.valido = false;
					p.tiempo = 20;
					elem->second[ejercicio] = p;
					equipo[palabra] = elem->second;
				}
			}
			else {
				if (bm == "AC") {
					elem2->second.tiempo = tiempo + elem2->second.tiempo;
					elem2->second.valido = true;
					elem->second[ejercicio] = elem2->second;
					equipo[palabra] = elem->second;
				}
				else {
					elem2->second.tiempo = 20 + elem2->second.tiempo;
					elem2->second.valido = false;
					elem->second[ejercicio] = elem2->second;
					equipo[palabra] = elem->second;
				}
			}
		}
		std::cin >> palabra;
	}

	std::vector<tSol2> v;
	for (auto const& sol : equipo) {
		tSol2 s;
		s.nombre = sol.first;
		int i = 0, sumaTotal = 0;
		for (auto const& s : sol.second) {
			if (s.second.valido) {
				i++;
				sumaTotal += s.second.tiempo;
			}
		}
		s.p.ejer = i;
		s.p.tiempo = sumaTotal;
		v.push_back(s);
	}

	std::sort(v.begin(), v.end(), ordenar);

	mostrarSolucion(v);

	std::cout << "----\n";
}


int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
