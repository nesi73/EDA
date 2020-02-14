//Inés Prieto Centeno

#include <iostream>
#include "queue_eda.h"

template <class T>
class InsertarLista : public queue<T>{
	using Nodo = typename queue<T>::Nodo; // para poder usar Nodo aquís
public:
	void insertar(InsertarLista<int> *cola2, int prin) {
		Nodo *adc = this->prim;
		Nodo *ddc;
		if (prin == 0) {
			ddc = this->prim;
			this->prim = cola2->prim;
			cola2->ult->sig = ddc;
			return;
		}
		for (int j = 0; j < prin - 1; j++) adc = adc->sig;
		ddc = adc->sig;
		adc->sig = cola2->prim;
		cola2->ult->sig = ddc;
	}
	void print() {
		Nodo *aux = this->prim;
		while (aux != NULL) {
			std::cout << aux->elem << " ";
			aux = aux->sig;
		}
		std::cout << std::endl;
	}
};
