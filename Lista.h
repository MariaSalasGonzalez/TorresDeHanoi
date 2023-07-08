#ifndef LISTA_H
#define LISTA_H


#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include<fstream>
#include <Windows.h>
#include "Nodo.h"
#include "Iterador.h"
using namespace std;

template<class T>
class Lista//Clase listaGenerica sirve para poder crear diferentes tipos de listas
{ //como por ejemplo, gracias a esta clase se puede crear la lista de puestos,
protected: //empleados, entre otras
	Nodo<T>* primero;
	int size;
public:
	Nodo<T>* getPrimero();
	Lista();
	Lista(Lista&);
	virtual ~Lista();
	bool esVacia();

	void insertarInicio(T*);
	void insertarFinal(T*);
	string toString();
	bool buscar(T* aux);
	T* retornaPuesto(T* aux);
	T* inicioLinkedList();
	void eliminarInicio();
	bool eliminarFinal();
	bool eliminarEspecifico(int);
	T* buscar(int aux);

	int getSize();
	Lista& operator=(Lista&);
	Iterador<T>* obtenerIterador();
	void guardar1(ofstream& salida);
};
template <class T>
Lista<T>::Lista(Lista& aux) {
	while (!esVacia())
	{
		eliminarInicio();
	}
	primero = NULL;
	size = 0;
	Nodo<T>* actual = aux.primero;
	while (actual)
	{
		insertarFinal(actual->getInfo());
		actual = actual->getSig();
	}
}


template<class T>
bool Lista<T>::esVacia() {
	return (primero == NULL);
}

template<class T>
inline Nodo<T>* Lista<T>::getPrimero()
{
	return primero;
}

template<class T>
Lista<T>::Lista() {
	primero = NULL;
	size = 0;
}

template<class T>
string Lista<T>::toString()
{
	stringstream s;
	Nodo<T>* actual = primero;
	int contador = 1;
	while (actual != NULL)
	{
		s << "---------------------------------------------------------" << endl;
		s << endl;
		s << contador << ")" << *actual->getInfo();
		contador++;
		actual = actual->getSig();
		s << endl;
	}
	return s.str();
}
template<class T>
inline T* Lista<T>::inicioLinkedList(){
	Nodo<T>* aux = primero;
	if (aux->getSig() != nullptr) {
		aux = aux->getSig();
		return aux->getInfo();
	}
	return nullptr;
}

template<class T>
void Lista<T>::insertarInicio(T* dato) {
	Nodo<T>* actual;
	actual = new Nodo<T>(dato);
	actual->setSig(primero);
	primero = actual;
	size++;
}

template <class T>
void Lista<T>::insertarFinal(T* dato) {
	Nodo<T>* actual = primero;
	if (esVacia()) {
		insertarInicio(dato);
	}
	else {
		while (actual->getSig() != NULL)
		{
			actual = actual->getSig();

		}
		actual->setSig(new Nodo<T>(dato));
		size++;
	}
}
template<class T>
bool Lista<T>::buscar(T* aux)
{
	Nodo<T>* actual = primero;
	while (actual)
	{
		if ((*actual->getInfo()) == (*aux))
		{
			return true;
		}
		actual = actual->getSig();
	}
	return false;
}

template<class T>
 T* Lista<T>::retornaPuesto(T* aux)
{
	//nodoGenerico<T> *actual = primero;
	//while (actual)
	//{
	// if (*(actual->getInfo()) == (*aux))
	// {
	// T = actual->getInfo();
	// }
	// actual = actual->getSig();
	//}
	//return T;
}

template<class T>
void Lista<T>::eliminarInicio() {
	Nodo<T>* actual = primero;
	if (primero == NULL)
	{
		cout << "La lista esta vacia" << endl;
	}
	else
	{
		actual = primero;
		primero = primero->getSig();
		delete actual;
		size--;
	}
}
template<class T>
bool Lista<T>::eliminarFinal() {
	Nodo<T>* actual = primero;

	if (primero == NULL)
	{
		return false;
	}
	else
	{
		if (primero->getSig() == NULL)
		{
			delete primero;
			size--;
			primero = NULL;
		}
		else
		{

			while (actual->getSig()->getSig() != NULL)
			{
				actual = actual->getSig();
			}
			delete actual->getSig();
			size--;
			actual->setSig(NULL);
		}
		return true;
	}
}

template<class T>
bool Lista<T>::eliminarEspecifico(int position) {
	if (getPrimero() == nullptr) {
		return false;
	}
	else {
		Nodo<T>* eliminar;
		if (position == 0) {
			eliminar = getPrimero();
			primero = primero->getSig();
			delete eliminar;
			return 1;
		}
		else {
			Nodo<T>* auxiliar = primero;
			for (int i = 0; auxiliar->getSig() != nullptr && i < position - 1; i++) {
				auxiliar = auxiliar->getSig();
			}
			if (auxiliar->getSig() != nullptr) {
				eliminar = auxiliar->getSig();
				auxiliar->setSig(eliminar->getSig());
				delete eliminar;
				return 1;
			}
		}
		return 0;
	}
	return 0;
}

template<class T>
inline int Lista<T>::getSize() {
	return size;
}

template <class T>
Lista<T>& Lista<T>::operator=(Lista& aux)
{
	while (!esVacia())
	{
		eliminarInicio();
	}
	primero = NULL;
	size = 0;
	Nodo<T>* actual = aux.primero;
	while (actual)
	{
		insertarFinal(actual->getInfo());
		actual = actual->getSig();
	}
	return *this;
}

template<class T>
Lista<T>::~Lista()
{
	while (!esVacia())
		eliminarInicio();
	size = 0;
}

/*template<class T>
Iterador<T>* Lista<T>::obtenerIterador(){
	return new Lista<T>(primero);
}*/

template<class T>
inline void Lista<T>::guardar1(ofstream& salida)
{
	T* _t;
	Nodo<T>* actual = primero;
	while (actual != NULL) {
		_t = actual->getInfo();
		if (_t != NULL) {
			_t->autoGuardar2(salida);
		}
		actual = actual->getSig();
	}
}

template<class T>
T* Lista<T>::buscar(int lug) {
	int cont = 1;
	Nodo<T>* p = primero;
	while (p != NULL && cont < lug) {
		p = p->getSig();
		cont++;
	}
	if (p == NULL)
		return NULL;
	if (cont == lug) {
		return p->getInfo();
	}
	return 0;
};

#endif // !LISTA_H