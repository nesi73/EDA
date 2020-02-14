//Ines Prieto Centeno

#include <iostream>
#include "queue_eda.h"

template <class T>
class afortunado : public queue<T> {
	using Nodo = typename queue<T>::Nodo; // para poder usar Nodo aquís
public:
	int descartar(int num) {
		this->ult->sig = this->prim;
		Nodo *aux = this->prim;
		int size = this->size();
		while (size> 1) {
			int i = 0;
			while (i < num - 1) {
				aux = aux->sig;
				++i;
			}
			aux->sig = aux->sig->sig;
			aux = aux->sig;
			size--;
		}
		return aux->elem;
	}
	
};
