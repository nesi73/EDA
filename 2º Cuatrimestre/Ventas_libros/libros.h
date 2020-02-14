//Ines Prieto Centeno

#ifndef libros_h
#define libros_h

#include <iostream>
#include <unordered_map>
#include <map>
#include <list>
#include <functional>

using nombreLibro = std::string;
using ejemplaresVendidos = int;
using ejemplaresExistentes = int;

struct datos {
	ejemplaresVendidos numVendido;
	ejemplaresExistentes numEjem;
	std::list<nombreLibro>::iterator it;
};

class libros {
private:
	std::unordered_map<nombreLibro, datos> tabla;
	std::map<ejemplaresVendidos, std::list<nombreLibro>, std::greater<int>> top;
public:
	libros(){}

	void nuevoLibro(int ejem, nombreLibro nombre) {
		if (tabla.count(nombre)) tabla[nombre].numEjem += ejem;
		else tabla[nombre].numEjem = ejem;
	}

	void comprar(nombreLibro nombre) {
		if (!tabla.count(nombre)) throw std::invalid_argument("Libro no existente");
		if (tabla[nombre].numEjem == 0) throw std::out_of_range("No hay ejemplares");
		if (tabla[nombre].numVendido != 0) top[tabla[nombre].numVendido].erase(tabla[nombre].it);
		tabla[nombre].numVendido++;
		tabla[nombre].numEjem--;
		top[tabla[nombre].numVendido].push_front(nombre);
		tabla[nombre].it = top[tabla[nombre].numVendido].begin();
	}

	bool estaLibro(nombreLibro nombre) {
		if (tabla.count(nombre)) return true;
		return false;
	}

	void elimLibro(nombreLibro nombre) {
		if (tabla.count(nombre)) {
			datos &d = tabla[nombre];
			if(!top.empty() && !top[d.numVendido].empty() && d.it != top[d.numVendido].end())top[d.numVendido].erase(d.it);
			tabla.erase(nombre);
		}
	}

	int numEjemplares(nombreLibro nombre) {
		if (!tabla.count(nombre)) throw std::invalid_argument("Libro no existente");
		return tabla[nombre].numEjem;
	}

	std::list<nombreLibro> top10() {
		std::list<nombreLibro> lista;
		auto it1 = top.begin();
		int i = 0;
		while(it1 != top.end() && i < 10) {
			auto ite = it1->second.begin();
			while( ite != it1->second.end() && i < 10) {
				lista.push_back(*ite);
				i++;
				ite++;
			}
			it1++;
		}
		return lista;
	}
};

#endif
