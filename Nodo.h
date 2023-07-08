#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <Windows.h>
using namespace std;



template<class T>
class Nodo
{
    T* info;
    Nodo<T>* sig;
public:
    Nodo(T*);
    Nodo<T>* getSig();
    T* getInfo();
    void setSig(Nodo<T>* info);
    Nodo<T>& operator =(const Nodo<T>& sum1);//5
};
template<class T>
Nodo<T>::Nodo(T* info)
{
    this->info = info;
    sig = NULL;
}
template<class T>
T* Nodo<T>::getInfo() {
    return info;
}
template<class T>
inline void Nodo<T>::setSig(Nodo<T>* info)
{
    sig = info;
}

template<class T>
inline Nodo<T>& Nodo<T>::operator=(const Nodo<T>& sum1)
{
    if (this != &sum1) {
        if (sum1.getInfo() != NULL) {
            this->getInfo() = sum1.getInfo();
        }
    }
    return *this;
}

template<class T>
Nodo<T>* Nodo<T>::getSig()
{
    return sig;
}