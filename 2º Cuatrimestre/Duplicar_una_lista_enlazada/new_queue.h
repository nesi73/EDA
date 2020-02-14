//Inés Prieto Centeno

#ifndef new_queue
#define new_queue

#include "queue_eda.h"

template <class T>
class cola :public queue<T> {
private:
	using Nodo = typename queue<T>::Nodo;
public:
	void duplicar() {
		Nodo *pointer, *aux;
		pointer = this->prim;
		while (pointer != nullptr) {
			aux = pointer->sig;
			pointer->sig = new Nodo(pointer->elem);
			pointer->sig->sig = aux;
			pointer = aux;
		}
	}

	void print() {
		Nodo *aux = this->prim;
		std::cout << this->size() << "\n";
		while (aux != nullptr) {
			std::cout << aux->elem << " ";
			aux = aux->sig;
		}
		std::cout << "\n";
		delete aux;
	}
};
#endif // !new_queue
