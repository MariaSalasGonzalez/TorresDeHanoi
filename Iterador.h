#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <Windows.h>
#include "Lista.h"
using namespace std;

template<class T>
class Iterador{
private:
    Nodo<T>* cursor;
public:
    Iterador(Nodo<T>*);
    virtual bool masElementos();
    virtual T* proximoElemento();
    ~Iterador();
};

//Este método es para la creación de un iterador, para efecto de recorrer la lista
template<class T>
Iterador<T>::Iterador(Nodo<T>* elNod){
    cursor = elNod;
}

//Este método es para saber si se encuentran más elementos en la lista
template<class T>
bool Iterador<T>::masElementos(){
    if (cursor != NULL) {
        return true;
    }
    else
        return false;
}

//Este método es para colocar el iteradoren el siguiente elemento
template<class T>
T* Iterador<T>::proximoElemento(){
    T* aux;
    if (masElementos() == true) {
        aux = cursor->getInfo();
        cursor = cursor->getSig();
        return aux;
    }
    return NULL;
}

//Destructor
template<class T>
Iterador<T>::~Iterador(){
}

