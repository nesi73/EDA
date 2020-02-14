// Inés Prieto Centeno

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
void resolver(std::vector<std::vector<int>> const&m, std::vector<int> &sol, int k, int suma, int tiempo,int tiempo2, int tiempoI, int tiempoV, int &satisfacionMax) {
	sol[k] = 0;
	suma = suma + m[k][1];
	tiempo = tiempo + m[k][0];
	if (tiempoI >= tiempo) {
		if (k == sol.size() - 1) {
			if (tiempoI == tiempo) {
				if (tiempoV == tiempo2) {
					if (suma > satisfacionMax)
						satisfacionMax = suma;
				}
			}
		}
		else resolver(m, sol, k + 1, suma, tiempo,tiempo2, tiempoI, tiempoV,satisfacionMax);
	}

	tiempo = tiempo - m[k][0];
	sol[k] = 1;
	tiempo2 += m[k][0];
	if (tiempoI >= tiempo) {
		if (k == sol.size() - 1) {
			if (tiempoI == tiempo) {
				if (tiempoV == tiempo2) {
					if (suma > satisfacionMax)
						satisfacionMax = suma;
				}
			}
		}
			else resolver(m, sol, k + 1, suma, tiempo, tiempo2, tiempoI, tiempoV, satisfacionMax);
	}
	tiempo2 -= m[k][0];
	suma = suma - m[k][1];
	sol[k] = 2;
	if (tiempoI >= tiempo) {
		if (k == sol.size() - 1) {
			if (tiempoI == tiempo) {
				if (tiempoV == tiempo2) {
					if (suma > satisfacionMax)
						satisfacionMax = suma;
				}
			}
		}
			else resolver(m, sol, k + 1, suma, tiempo, tiempo2, tiempoI, tiempoV, satisfacionMax);
		}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numCanciones, tiempoI, tiempoV, suma = 0, tiempo = 0,tiempo2=0, satisfacionMax = 0;
	std::cin >> numCanciones;
	std::cin >> tiempoI;
	std::cin >> tiempoV;
	if (numCanciones == 0 && tiempoI == 0 && tiempoV == 0)
		return false;
	std::vector<std::vector<int>>m(numCanciones, std::vector<int>(2));
	for (int i = 0; i < numCanciones; ++i) {
		for (int j = 0; j < 2; ++j)
			std::cin >> m[i][j];
	}
	std::vector<int> sol(numCanciones);
	resolver(m,sol,0, suma, tiempo,tiempo2, tiempoI, tiempoV, satisfacionMax);
	if(satisfacionMax == 0) std::cout<< "Imposible\n";
	else 
		std::cout << satisfacionMax << "\n";
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
