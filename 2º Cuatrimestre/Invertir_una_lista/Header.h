//Inés Prieto Centeno

#include <iostream>
#include "queue_eda.h"

template <class T>
class AñadirLista: public queue<T>{
private:
	using Nodo = typename queue<T>::Nodo;
public:
	void invertir() {
		Nodo *pointer, *aux, *copia;
		pointer = this->prim;
		aux = pointer;
		copia = pointer;
		while (aux != nullptr) {
			aux = aux->sig;
			if (pointer->elem == this->prim->elem) {
				pointer->sig = NULL;
			}
			else pointer->sig = copia;
			copia = pointer;
			pointer = aux;
		}
		this->prim = copia;
	}

	void insertar(AñadirLista<int> *b,int pos) {
		Nodo *pointer = this->prim;
		Nodo *aux = pointer;
		while (aux != nullptr) {
			aux = aux->sig;
			if (pos <= 1) {
				if (pos == 0) {
					b->ult->sig = pointer;
					this->prim = b->prim;
					break;
				}
				b->ult->sig = aux;
				pointer->sig = b->prim;
				break;
			}
			else {
				pointer = aux;
			}
			pos--;
		}
	}

	void print() {
		Nodo *aux = this->prim;
		while (aux != nullptr) {
			std::cout << aux->elem << " ";
			aux = aux->sig;
		}
		std::cout << "\n";
		delete aux;
	}

};


