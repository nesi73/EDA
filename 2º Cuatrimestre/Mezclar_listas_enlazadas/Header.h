//Ines Prieto Centeno

#include <iostream>
#include "queue_eda.h"

template <class T>
class MezclarLista : public queue<T> {
	using Nodo = typename queue<T>::Nodo; // para poder usar Nodo aquís
public:
	void mezclar(MezclarLista<int> *cola2) {
		Nodo *aux, *pointer, *aux2, *pointer2, *intercambio;
		if (this->prim == nullptr) this->prim = cola2->prim;
		else if (cola2->prim == nullptr) cola2->prim = this->prim;
		else {
			if (this->prim->elem > cola2->prim->elem) {
				intercambio = this->prim;
				this->prim = cola2->prim;
				cola2->prim = intercambio;
			}
				pointer = this->prim;
				aux = pointer;
				pointer2 = cola2->prim;
				aux2 = pointer2;
				
			while (pointer != nullptr || pointer2 != nullptr) {
				if (pointer != nullptr && pointer2 != nullptr) {
					if (pointer->elem <= pointer2->elem) {
						if (pointer->sig == nullptr && pointer2 == cola2->prim) {
							pointer->sig = pointer2;
							aux = pointer;
							pointer = nullptr;
							pointer2 = nullptr;
						}
						else pointer = pointer->sig;
					}
					else {
						aux->sig = aux2;
						aux = aux->sig;
						aux2 = pointer;
						pointer2 = pointer2->sig;
						intercambio = pointer;
						pointer = pointer2;
						pointer2 = intercambio;
					}
				}
				else if (pointer == nullptr && pointer2 != nullptr) {
						aux->sig = pointer2;
						pointer2 = pointer2->sig;
				}
				else if (pointer2 == nullptr && pointer != nullptr) {
					aux->sig = pointer;
					pointer = pointer->sig;
				}
			}
		}
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
