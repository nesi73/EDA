//Inés Prieto Centeno

#include <iostream>
#include <algorithm>
#include "bintree.h"
template <class T>

class bintree_ext : public bintree<T> {

	using Link = typename bintree<T>::Link;

public:

	bintree_ext() : bintree<T>() {}

	bintree_ext(bintree_ext<T> const& l, T const& e, bintree_ext<T> const& r) : bintree<T>(l, e, r) {}



	size_t altura() const {

		return altura(this->raiz);

	}

	T resolver() {
		if (this->raiz == nullptr) return 0;
		return menor(this->raiz);
	}


private:

	T menor(Link p) {
		if (p->left == nullptr && p->right == nullptr) return p->elem;
		else if (p->left == nullptr) {
			T dr = menor(p->right);
			return std::min(dr, p->elem);
		}
		else if (p->right == nullptr) {
			T iz = menor(p->left);
			return std::min(iz, p->elem);
		}
		else {
			T izq = menor(p->left);
			T dr = menor(p->right);
			T minHijos = std::min(izq, dr);
			return std::min(minHijos, p->elem);
		}
	}

	static size_t altura(Link r) {

		if (r == nullptr) {

			return 0;

		}
		else {

			return 1 + std::max(altura(r->left), altura(r->right));

		}

	}

};
