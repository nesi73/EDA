// Inés Prieto Centeno

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
void resolver(std::vector <int> const&coste, std::vector <int> const&superficie, std::vector <bool> &sol,int k, int precio, int tam, int &tamMax, int presupuesto) {
	sol[k] = true;
	precio = precio + coste[k];
	tam = tam + superficie[k];
	if (precio <= presupuesto) {
		if (k == sol.size() - 1) {
			if (tam > tamMax) {
				tamMax = tam;
			}
		}
		else resolver(coste, superficie, sol, k + 1, precio, tam, tamMax, presupuesto);
	}
	precio = precio - coste[k];
	tam = tam - superficie[k];
	sol[k] = false;
	if (k == sol.size() - 1) {
		if (tam > tamMax) {
			tamMax = tam;
		}
	}
	else resolver(coste, superficie, sol, k + 1, precio, tam, tamMax, presupuesto);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numElem, presupuesto, precio = 0, tam = 0, tamMax = 0;
	std::cin >> numElem;
	if (!std::cin)
		return false;
	std::cin >> presupuesto;
	std::vector <int> coste(numElem);
	for (int &i : coste) std::cin >> i;
	std::vector <int> superficie(numElem);
	std::vector <bool> sol(numElem);
	for (int &i : superficie) std::cin >> i;
	resolver(coste, superficie,sol, 0, precio, tam, tamMax, presupuesto);
	std::cout << tamMax << "\n";
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
