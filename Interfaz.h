#ifndef INTERFAZ_H
#define INTERFAZ_H
#include "Control.h"
#include"Lista.h"
#include"Pila.h"
#include"Nivel.h"
#define ENDL '\n'
#define TAB '\t'
#define SPACE ' '
#define leftcornerUp '\311'
#define rightcornerUp '\273'
#define leftcornerDown '\310'
#define rightcornerDown '\274'
#define Vline '\272'
#define Hline '\315'

class Interfaz{
public:
	Interfaz();
	virtual ~Interfaz();
		//SMS
	static void instrucciones();

	static void inicio();
	static void pausa();
	static void continuar();
	static void atras();
	static void salir();
	static void error();
	static string solicitarClave();
	static void datosUsar();
	//MENU PRINCIPAL
	static char MenuPrincipal();

	//OPCION 1
	static char ingresarAlJuego();

	//OPCION 2 
	//Mostrar el mínimo número de movimientos para ganar
	static string movimientosGanar();

	//OPCION 3
	//Mostrar el algoritmo completo paso a paso de la solución.
	static string algoritmoSolucion();

};
#endif // !INTERFAZ_H




