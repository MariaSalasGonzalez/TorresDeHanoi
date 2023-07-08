// cola.cpp
// Implementación de la clase Cola

#include "cola.h"
template<class T>
// Constructor
Cola<T>::Cola() : head{ nullptr }, tail{ nullptr } {}

// Destructor
template<class T>
Cola<T>::~Cola() {
	Nodo* tmp = head;
	while (head != nullptr) {
		head = head->next;
		delete tmp;
		tmp = head;
	}
	head = nullptr;
	tail = nullptr;
}

// Inserta un nuevo elemento en la cola si no está llena
template<class T>
void Cola<T>::enqueue(const int item) {
	Nodo* nuevo;

	try
	{
		nuevo = new Nodo;
	}
	catch (std::bad_alloc exception)
	{
		return;
	}

	nuevo->elemento = item;
	nuevo->next = nullptr;

	if (estaVacia()) {
		head = nuevo;
		tail = nuevo;
	}
	else {
		tail->next = nuevo;
		tail = nuevo;
	}
}

// Recupera el elemento de la cola si no está vacía
template<class T>
int Cola<T>::dequeue() {
	if (estaVacia())
		return -1;

	Nodo* tmp;
	int valor;

	tmp = head;
	valor = head->elemento;

	head = head->next;
	if (head == nullptr)
		tail = nullptr;

	free(tmp);
	tmp = nullptr;
	return valor;
}

// Muestra el siguiente elemento en la cola (próximo en salir)

template<class T>
int Cola<T>::siguiente() {
	if (estaVacia())
		return -1;

	return head->elemento;
}

// Retorna "true" si la cola está vacía. "false", en caso contrario
template<class T>
bool Cola<T>::estaVacia() {
	return (head == nullptr);
}
