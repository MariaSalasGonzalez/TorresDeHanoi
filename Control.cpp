#include "Control.h"

Control::Control(){
	nivel = new Nivel(4);
	//cargarDatos();
}

Control::~Control()
{
	delete nivel;
}

void Control::CONTROLADORA()
{
	char opcion = 'A';
	Interfaz::inicio();
	while (opcion != '0') {
		opcion = MENUPRINCIPAL();
	}
}

char Control::MENUPRINCIPAL()
{
	char opcion = 'A';
	opcion = Interfaz::MenuPrincipal();
	switch (opcion){
	case'1': {//Ingresar al juego
		Interfaz::instrucciones();
		//Interfaz::ingresarAlJuego();
		Control::MENUJUGAR();
		Interfaz::pausa();
		break;
	}
	case'2': {//Mostrar el número mínimo de movimientos para ganar

		Interfaz::movimientosGanar();//Solo muestra que son los pasos para ganar
		//Aquí se llama al nivel para hacer que se muestre el paso a paso
		cout<<nivel->minimoMovimientos();
		Interfaz::pausa();
		break;
	}
	case'3': {//Mostrar solución del juego
		//Interfaz::solicitarClave();
		string clave="1234";
		if (Interfaz::solicitarClave()==clave) {
			cout << "CLAVE CORRECTA:\n";
			cout<< Interfaz::algoritmoSolucion();
		}
		else {
			cout<<"CLAVE INCORRECTA:\n";
			if (Interfaz::solicitarClave() == clave) {
				cout << "CLAVE CORRECTA:\n";
				cout << Interfaz::algoritmoSolucion();
			}
		}
		Interfaz::pausa();
		break;
	}
		   Interfaz::atras();
		   break;
	}
	return opcion;
}

char Control::MENUJUGAR()
{
	int niveles;
	char opcion = 'A';
	cout << "INGRESAR CANTIDAD DE NIVELES" << endl;
	cin >> niveles;
	
	switch (opcion)
	{
	case'1': {
		cout<<nivel->cambio1();
		break;
	}
	case'2': {
		cout<<nivel->cambio2();
		break;
	}
	case'3': {
		cout<<nivel->cambio3();
		break;
	}
	case'4': {
		cout<<nivel->cambio4();
		break;
	}
	case'5': {
		cout<<nivel->cambio5();
		break;
	}
	case'6': {
		cout<<nivel->cambio6();
		break;
	}
	default:
		break;
	}

	return opcion;
}
