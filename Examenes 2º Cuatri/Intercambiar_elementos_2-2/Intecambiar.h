#ifndef Intercambiar
#define Intercambiar

#include "queue_eda.h"
#include <iostream>
#include <fstream>

class Intercamb : public queue<int> {

public:

	Intercamb() {};

	void cambiar() {
		Nodo *aux, *pointer, *aux2, *next;
		pointer = this->prim;
		aux = pointer;
		if (aux->sig == nullptr) {
			pointer = this->prim;
		}
		else if (aux->sig->sig == nullptr) {
			pointer = this->prim->sig;
			pointer->sig = aux;
			aux->sig->sig = NULL;
		}
		else {
			pointer = pointer->sig;
			aux2 = pointer->sig->sig;
			next = pointer->sig;
			while (next != nullptr && aux2 != nullptr) {
				pointer->sig = aux;
				aux->sig = aux2;
				aux2->sig = next;
				aux = next;
				pointer = aux2;
				next = pointer->sig;
				aux2 = pointer->sig->sig;
			}
		}
	}

	void print() {
		Nodo * aux = prim;
		while (aux != nullptr) {
			std::cout << aux->elem << " ";

			aux = aux->sig;
		}
		std::cout << "\n";
		delete aux;
	}
};

#endif
