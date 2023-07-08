#pragma once
#pragma warning( disable : 4290 )
#include "Lista.h"
#include "ExcepcionPila.h"
template <class T>
class Pila {
private:
	int n;
	Lista<T>* list;
public:
	Pila();
	virtual ~Pila();
	int size();
	bool empty()const;
	T* top()throw(PilaVacia);
	void push(T* elemento);
	void pop()throw(PilaVacia);
};

template<class T>
Pila<T>::Pila() :list(new Lista<T>), n(0){

}

template<class T>
Pila<T>::~Pila(){
	delete list;

}

template<class T>
int Pila<T>::size(){
	return n;
}

template<class T>
bool Pila<T>::empty() const{
	return n == 0;
}

template<class T>
inline T* Pila<T>::top() throw(PilaVacia)
{
	if (empty())
		throw PilaVacia("Empty stack.");
	return list->inicioLinkedList();
}

template<class T>
void Pila<T>::push(T* elemento){
	++n;
	list->insertarInicio(elemento);
}

template<class T>
void Pila<T>::pop() throw(PilaVacia){
	if (empty())
		throw PilaVacia("Empty stack.");
	list->eliminarInicio();
	n--;
}