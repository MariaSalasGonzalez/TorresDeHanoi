// cola.h
// Declaración de la clase Cola

#ifndef COLA_H
#define COLA_H

#include <iostream>

#define MAX 20

template<class T>
struct Nodo {
	int elemento;
	struct Nodo* next;
};
template<class T>
class Cola {
public:
	Cola();
	~Cola();
	void enqueue(const int);
	int dequeue();
	int siguiente();
private:
	Nodo<T>* head; //salida
	Nodo<T>* tail;  //entrada
	bool estaVacia();
};

#endif


