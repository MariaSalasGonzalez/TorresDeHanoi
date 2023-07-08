#ifndef NIVEL_H
#define NIVEL_H
#include"Pila.h"
#include"Lista.h"
#include<math.h>
#include "stdio.h"
#include <locale.h>
#include<string>
class Nivel{
private:
	Pila<double>* pila1;
	Pila<double>* pilaAux;
	Pila<double>* pilaFinal;
	double nivel;
	int movimientos;
	int numDiscos;
public:
	Nivel(double);
	virtual ~Nivel();
	double getNivel();
	void setNivel(double);

	void Movimiento(double, Pila<double>* pila1, Pila<double>* pilaAux, Pila<double>* pilaFinal);
	string minimoMovimientos();
	double llenarPila();
	
	//string torres(double nivel);
	void setNumNiveles(int);
	int getNumNiveles();
	int getMovimientos();
	void setMovimientos();
	
	string cambio1();
	string cambio2();
	string cambio3();
	string cambio4();
	string cambio5();
	string cambio6();
	string volveraAJugar();
	string toString();
	bool Gano();

};
#endif // !NIVEL_H



