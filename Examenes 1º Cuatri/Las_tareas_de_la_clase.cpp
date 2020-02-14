// Inés Prieto Centeno

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

typedef struct {
	int numTareas, numAlumnos,MaxTareas;
}tDatos;

bool esValida(std::vector<int> const&sol, std::vector<int> const&cont, int i, tDatos d, int k) {
	if (cont[i] > d.MaxTareas) return false;
	else if (k % 2 != 0 && sol[k] == sol[k - 1])return false;
	else return true;
}

// función que resuelve el problema
void resolver(std::vector<std::vector<int>> const&m, std::vector<int> &sol, std::vector<int> &cont, tDatos d, int k, int suma, int &sumaMax) {
	for (int i = 0; i < d.numAlumnos; ++i) {
		sol[k] = i;
		cont[i]++;
		suma = suma + m[i][k/2];
		if (esValida(sol,cont,i,d, k)) {
			if (k == (d.numTareas * 2) - 1){
				if (suma > sumaMax) sumaMax = suma;
			}
			else resolver(m,sol,cont,d,k+1,suma,sumaMax);
		}
		cont[i]--;
		suma = suma - m[i][k / 2];
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	tDatos d;
	int sumaMax = 0;
	std::cin >> d.numTareas;
	std::cin >> d.numAlumnos;
	std::cin >> d.MaxTareas;
	int suma = 0;
	if (d.numAlumnos == 0 && d.numTareas == 0 && d.MaxTareas == 0)
		return false;
	std::vector<std::vector<int>>m(d.numAlumnos, std::vector <int>(d.numTareas));
	std::vector<int> sol(d.numTareas * 2);
	std::vector<int> cont(d.numAlumnos);
	for (int i = 0; i < d.numAlumnos; ++i) {
		for (int j = 0; j < d.numTareas; ++j)
			std::cin>> m[i][j];
	}
	resolver(m,sol,cont,d,0,suma, sumaMax);
	std::cout << sumaMax << "\n";
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
