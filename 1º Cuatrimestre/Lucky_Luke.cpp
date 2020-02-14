// Inés Prieto Centeno

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

typedef struct {
	int ini = -1;
	int fin = -1;
}tDatos;

// función que resuelve el problema
tDatos resolver(std::vector<int> const&v, int ini, int fin, int altura, tDatos &d) {
	if (ini == fin) {
		if (v[ini] == altura) {
			d.ini = ini;
			return 	d;
		}
		else return d;
	}
	else if (ini + 1 == fin) {
		if (v[ini] == altura && v[fin] == altura) {
			d.ini = ini;
			d.fin = fin;
			return d;
		}
		else if (v[ini] == altura) {
			d.ini = ini;
			return d;
		}
		else if (v[fin] == altura) {
			d.fin = fin;
			return d;
		}
		else return d;
	}
	else {
		if (v[ini] != altura || v[fin]!=altura) {
			int m = (ini + fin) / 2;
			tDatos Izq = resolver(v, ini, m, altura, d);
			tDatos Drch = resolver(v, m + 1, fin, altura, d);
		}
		else {
			d.ini = ini;
			d.fin = fin;
			return d;
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	tDatos d;
	int numElem, altura, izq, drch;
	std::cin >> numElem;
	if (!std::cin)
		return false;
	std::vector<int> v(numElem);
	std::cin >> altura;
	for (int i = 0; i < numElem; ++i)
		std::cin >> v[i];
	tDatos sol = resolver(v, 0, numElem - 1,altura, d);
	if (d.ini == -1 && d.fin == -1) std::cout << "NO EXISTE\n";
	else if (d.fin == -1) std::cout << d.ini << "\n";
	else if (d.ini == -1) std::cout << d.fin << "\n";
	else std::cout << d.ini << " " << d.fin << "\n";
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
