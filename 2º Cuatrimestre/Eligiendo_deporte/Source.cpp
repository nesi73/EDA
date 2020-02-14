//Ines Prieto Centeno
//E46

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using deporte = std::string;
using participantes = int;

typedef struct {
	std::string nombre;
	int valor;
}tSol;

typedef struct {
	std::string nombreDeporte;
	bool marcado;
}tPersona;

bool o(tSol s1, tSol s2) {
	return (s1.valor > s2.valor) || (s1.valor == s2.valor && s1.nombre < s2.nombre);
}		

void mostrarSolucion(std::vector<tSol> ordenar) {
	for (auto const& sol : ordenar) std::cout << sol.nombre << " " << sol.valor << "\n";
}

bool mayuscula(std::string &s) {
	if ('A' <= s[0] && s[0] <= 'Z')
		return true;
	return false;
}

bool resuelveCaso() {
	tPersona p;
	std::string leer, depor;
	std::unordered_map<deporte, participantes> m;
	std::unordered_map <std::string, tPersona> gente;
	std::vector<tSol> ordenar;
	std::cin >> leer;
	if (!std::cin) return false;
	while (leer != "_FIN_") {
		if (mayuscula(leer)) {
			m[leer] = 0;
			depor = leer;
		}
		else {
			auto elem = gente.find(leer);
			if (elem == gente.end()) {
				m[depor]++;
				gente[leer] = { depor,false };
			}
			else {
				if (elem->second.nombreDeporte != depor && !elem->second.marcado) {
					m[elem->second.nombreDeporte]--;
					gente[leer].marcado = true;
				}
			}
		}
		std::cin >> leer;
	}
	

	for (auto const& sol : m) {
		tSol s = { sol.first, sol.second };
		ordenar.push_back(s);
	}

	std::sort(ordenar.begin(), ordenar.end(), o);

	mostrarSolucion(ordenar);

	if(!m.empty()) 	std::cout << "***\n";
	return true;
}


int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif	

	while(resuelveCaso());

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
