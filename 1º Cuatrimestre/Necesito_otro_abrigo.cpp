// Inés Prieto Centeno

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

bool esValida(std::vector <int> const&p, std::vector <int> const&a, std::vector <int> &sol, std::vector <int> &cont, int k, int i) {
	if (p[k] > a[i]) return false; //no aguanta la lluvia
	else if (k > 0 && sol[k] == sol[k - 1]) return false;
	else if (cont[i] > 2 + k / 3) return false;
	else return true;
}

// función que resuelve el problema
void resolver(std::vector <int> const&p, std::vector <int> const&a,std::vector <int> &sol, std::vector <int> &cont, int numDias, int numAbrigos, int k, bool &existe, int &dias) {
	for (int i = 0; i < numAbrigos; ++i) {
		sol[k] = i;
		cont[i]++;
		if (esValida(p,a,sol,cont, k, i)) {
			if (k == numDias - 1) {
				if (sol[k] != sol[0]) {
					dias++;
					existe = true;
				}
			}
			else resolver(p, a, sol, cont, numDias, numAbrigos, k + 1, existe, dias);
		}
		cont[i]--;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada

	int numDias, numAbrigos, dias = 0;
	bool existe = false;
	std::cin >> numDias;
	std::cin >> numAbrigos;
	if (numDias == 0 && numAbrigos == 0)
		return false;
	std::vector <int> prec(numDias);
	std::vector <int> sol(numDias);
	std::vector <int> aguan(numAbrigos);
	std::vector <int> cont(numAbrigos);
	for (int &i : prec) std::cin >> i;
	for (int &i : aguan) std::cin >> i;
	resolver(prec, aguan,sol,cont, numDias, numAbrigos, 0, existe, dias);
	if (!existe) std::cout << "Lo puedes comprar\n";
	else std::cout << dias << "\n";
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
