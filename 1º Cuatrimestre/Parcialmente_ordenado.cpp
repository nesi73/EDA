// Inés Prieto Centeno

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

typedef struct {
	int min;
	int max;
}tDatos;

// función que resuelve el problema
bool resolver(std::vector <int> const&v, int ini, int fin, tDatos &d) {
	if (ini + 1 == fin) {
		if (v[ini] <= v[fin]) {
			d.min = v[ini];
			d.max = v[fin];
			return true;
		}
		else return false;
	}
	else {
		tDatos i,de;
		int m = (ini + fin) / 2;
		if (resolver(v, ini, m, i)) {
			if (resolver(v, m+1, fin, de)) {
				if (i.min <= de.min && de.max >= i.max) {
					d.min = i.min;
					d.max = de.max;
					return true;
				}
			}
		}
		return false;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	tDatos d;
	int num, max = 0;
	std::cin >> num;
	if (num == 0)
		return false;
	std::vector<int> v;
	while (num != 0) {
		v.push_back(num);
		std::cin >> num;
	}
	if (resolver(v, 0, v.size() - 1, d)) std::cout << "SI\n";
	else std::cout << "NO\n";
	// escribir sol

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
