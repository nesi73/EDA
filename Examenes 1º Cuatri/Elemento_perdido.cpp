// Inés Prieto Centeno

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//coste log(n)

// función que resuelve el problema
int resolver(std::vector <int> const&v, std::vector <int> const&v2, int ini, int fin) {
	if (ini == fin) return v[ini];
	else if (ini + 1 == fin) {
		if (v[ini] == v2[ini]) return v[fin];
		else return v[ini];
	}
	else {
		int m = (ini + fin) / 2;
		if (v[m] < v2[m]) return resolver(v, v2, ini, m-1);
		else return resolver(v, v2, m+1, fin);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int numElem;
	std::cin >> numElem;
	std::vector<int> v(numElem);
	std::vector<int> v2(numElem);
	for (int i = 0; i < numElem; ++i)
		std::cin >> v[i];
	for (int i = 0; i < numElem - 1; ++i)
		std::cin >> v2[i];
	if (v[0] != v2[0]) std::cout << v[0] << "\n";
	else {
		int sol = resolver(v,v2,0,numElem - 1);
		std::cout << sol << "\n";
	}
	// escribir sol


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
