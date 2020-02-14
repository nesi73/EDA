// Inés Prieto Centeno

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

typedef struct {
	int numColores, maxSoportado, numElem;
	int sumaMax = 0, suma = 0;
	int colores = 0;
}tDatos;

bool esValida(std::vector<int> const&sol, std::vector<int> const&cont, tDatos d, int k, int i) {
	if (k > 1 && sol[k] == sol[k - 1] && sol[k] == sol[k - 2]) return false;
	else if (k > 0 && cont[i] > d.colores - cont[i] + 1) return false;
	else if (d.suma > d.maxSoportado) return false;
	else return true;
}

void actualizarSol(std::vector<int> &sol) {
	for (int i = 0; i < sol.size(); ++i)
		std::cout << sol[i] << " ";
	std::cout << "\n";
}

// función que resuelve el problema
void resolver(std::vector<int> const&v, std::vector<int> &sol, std::vector<int> &cont, tDatos &d, int k) {
	for (int i = 0; i < d.numColores; ++i) {
		sol[k] = i;
		d.suma = v[i] + d.suma;
		cont[i]++;
		d.colores++;
		if (esValida(sol,cont, d, k,i)) {
			if (k == d.numElem - 1) {
				actualizarSol(sol);
			}
			else resolver(v, sol,cont, d, k + 1);
		}
		cont[i]--;
		d.colores--;
		d.suma = d.suma - v[i];
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	tDatos d;
	int k = 0;
	std::cin >> d.numElem;
	if (!std::cin)
		return false;
	std::cin >> d.numColores;
	std::cin >> d.maxSoportado;
	std::vector<int> v(d.numColores);
	std::vector<int> sol(d.numElem);
	std::vector<int> cont(d.numColores);
	for (int i = 0; i < d.numColores; ++i)
		std::cin >> v[i];
	resolver(v, sol,cont, d, k);
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
