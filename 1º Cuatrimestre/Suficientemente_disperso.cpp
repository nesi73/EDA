// Inés Prieto Centeno

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
bool resolver(std::vector <int> const&v, int ini, int fin, int num) {
	if (ini == fin) return true;
	else if (ini + 1 == fin) {
		if (abs(v[ini] - v[fin]) >= num) return true;
		else return false;
	}
	else {
		int m = (ini + fin) / 2;
		if (resolver(v, ini, m, num)) {
			if (resolver(v, m + 1, fin, num)) {
				if (abs(v[ini] - v[fin]) >= num)
					return true;
			}
		}
		return false;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numElem, num;
	std::cin >> numElem;
	if (!std::cin)
		return false;
	std::cin >> num;
	std::vector<int> v(numElem);
	for (int i = 0; i < numElem; ++i)
		std::cin >> v[i];
	if (resolver(v, 0, numElem - 1, num)) std::cout << "SI\n";
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
