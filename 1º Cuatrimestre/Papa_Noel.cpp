// Inés Prieto Centeno

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

typedef struct {
	int numJug, numNiños, minSatisfaccion;
	int sumaMax = 0;
}tDatos;

bool esValida(std::vector <int> const&dis,std::vector <int> const&sol, std::vector <std::string> const&t, int k, tDatos d, int i, int j, int suma) {
	if (d.minSatisfaccion > suma) return false;
	else if (t[sol[k]] == t[sol[k - 1]]) return false;
	else if (dis[i] < 0) return false;
	else if (dis[j] < 0)return false;
	else return true;
}

void actualizarSol(std::vector <int> const &sol, tDatos d) {
	for (int i = 0; i < d.numNiños * 2; ++i) std::cout << sol[i] << " ";
	std::cout << "\n";
}

// función que resuelve el problema
void resolver(std::vector <int> &dis, std::vector <std::string> const&t, std::vector <int> &sol, std::vector <std::vector <int>> const&m, std::vector <std::vector <bool>> &marcas, tDatos d, int k, bool &existe, int suma) {
	for (int i = 0; i < d.numJug; ++i) {
		if (!marcas[k][i]) {
			for (int j = 0; j < d.numJug; ++j) {
				sol[k] = i;
				sol[k + 1] = j;
				suma += m[k/2][j] + m[k / 2][i];
				dis[i]--;
				dis[j]--;
				if (esValida(dis, sol, t, k+1, d, i, j, suma) && !marcas[k + 1][j]) {
					marcas[k][j] = true;
					marcas[k + 1][i] = true;
					if (k + 2 == (d.numNiños * 2)) {
						existe = true;
						actualizarSol(sol, d);
					}
					else {
						resolver(dis, t, sol, m, marcas, d, k + 2,existe, 0);
					}
				}
				dis[i]++;
				dis[j]++;
				suma -= m[k / 2][j] + m[k / 2][i];
			}
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	tDatos d;
	std::cin >> d.numJug;
	if (!std::cin)
		return false;
	std::cin >> d.numNiños;
	std::cin >> d.minSatisfaccion;
	std::vector <int> disponibles(d.numJug);
	std::vector <std::string> tipo(d.numJug);
	std::vector <int> sol(d.numNiños*2);
	std::vector <std::vector<int>> m(d.numNiños, std::vector<int> (d.numJug));
	std::vector <std::vector<bool>> marcas(d.numNiños*2, std::vector<bool> (d.numJug));
	bool existe = false;
	for (int i = 0; i < d.numJug; ++i)
		std::cin >> disponibles[i];
	for (int i = 0; i < d.numJug; ++i)
		std::cin >> tipo[i];
	for (int i = 0; i < d.numNiños; ++i) {
		for (int j = 0; j < d.numJug; ++j)
			std::cin >> m[i][j];
	}
	resolver(disponibles, tipo,sol,m,marcas,d, 0, existe,0);
	if (!existe) std::cout << "SIN SOLUCION\n";
	std::cout << "\n";
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
