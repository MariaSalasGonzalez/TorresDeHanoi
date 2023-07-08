#include "Interfaz.h"

Interfaz::Interfaz() {
 }

Interfaz::~Interfaz() {
}

void Interfaz::instrucciones()
{
	cout << "\a" << ENDL;
	cout << leftcornerUp << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << rightcornerUp << ENDL;
	cout << Vline << "INSTRUCCIONES" << Vline << ENDL;
	cout << leftcornerDown << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << rightcornerDown << ENDL;

	//INSTRUCCIONES
	cout << ENDL << ENDL << ENDL;
	cout << "NO MOVER DOS NIVELES AL MISMO TIEMPO" << ENDL;
	cout << "NO COLOCAR UN NIVEL MAYOR SOBRE UNO MENOR" << ENDL;
	pausa();
}

void Interfaz::inicio()
{
	cout << leftcornerUp << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << rightcornerUp << ENDL;
	cout << Vline << "BIENVENIDO JUEGO TORRES DE HANOI" << Vline << ENDL;
	cout << leftcornerDown << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline<<rightcornerDown << ENDL;
}

void Interfaz::pausa()
{
	system("pause");
	system("cls");
}

void Interfaz::continuar()
{
	cout << leftcornerUp << Hline << Hline << Hline << Hline << rightcornerUp << ENDL;
	cout << Vline << "" << Vline << ENDL;
	cout << leftcornerDown << Hline << Hline << Hline << Hline << rightcornerDown << ENDL;
}

void Interfaz::atras()
{
	cout << leftcornerUp << Hline << Hline << Hline << Hline << Hline << Hline << Hline << rightcornerUp << ENDL;
	cout << Vline << SPACE << "ATRAS" << SPACE << Vline << ENDL;
	cout << leftcornerDown << Hline << Hline << Hline << Hline << Hline << Hline << Hline << rightcornerDown << ENDL;
	pausa();
}

void Interfaz::salir()
{
	cout << leftcornerUp << Hline << Hline << Hline << Hline << Hline << Hline << Hline << rightcornerUp << ENDL;
	cout << Vline << SPACE << "SALIR" << SPACE << Vline << ENDL;
	cout << leftcornerDown << Hline << Hline << Hline << Hline << Hline << Hline << Hline << rightcornerDown << ENDL;
	pausa();
}

void Interfaz::error()
{
	cout << leftcornerUp << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << rightcornerUp << ENDL;
	cout << Vline << "OPCION NO DISPONIBLE" << Vline << ENDL;
	cout << leftcornerDown << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << rightcornerDown << ENDL;
	pausa();
}

string Interfaz::solicitarClave()
{
	string clave;
	cout << "CLAVE" << SPACE;
	cin >> clave;
	return clave;
}

char Interfaz::MenuPrincipal()
{
	/*

	*/
	cout << ENDL;
	char opcion = 'A';
	cout << leftcornerUp << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << rightcornerUp << ENDL;
	cout << Vline << SPACE << SPACE << "MENU PRINCIPAL" << SPACE << SPACE << SPACE << SPACE << SPACE << SPACE << SPACE << SPACE << SPACE << SPACE << Vline << ENDL;
	cout << Vline << "[1] INGRESAR AL JUEGO" << TAB << SPACE << SPACE << SPACE << Vline << ENDL;
	cout << Vline << "[2] JUGADAS PARA GANAR"<< TAB << SPACE << SPACE << SPACE << Vline << ENDL;
	cout << Vline << "[3] ALGORITMO SOLUCION"<< TAB << SPACE << SPACE << SPACE << Vline << ENDL;
	cout << Vline << "[4] VOLVER A JUGAR" << TAB << SPACE << SPACE << SPACE << Vline << ENDL;
	cout << Vline << "[0] ATRAS" << TAB << SPACE << SPACE << SPACE << SPACE << SPACE << SPACE << SPACE << SPACE << SPACE << SPACE << SPACE << Vline << ENDL;
	cout << leftcornerDown << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << Hline << rightcornerDown << ENDL;
	cout << ENDL;
	cout << "Opcion: "; cin >> opcion;
	cout << ENDL;
	pausa();
	return opcion;
}

char Interfaz::ingresarAlJuego()
{
	char opcion = 'A';
	
	return opcion;
}

string Interfaz::movimientosGanar()
{
	//Nivel* nivel=nullptr;
	stringstream a;
	a << "MOVIMIENTO MINIMOS PARA GANAR EL JUEGO" << ENDL;
	//nivel->minimoMovimientos();
	return a.str();
}

string Interfaz::algoritmoSolucion(){
	stringstream a;
	a << "\t\t\t\t\tSOLUCION ALGORITMO:\t\t\t\t\t\n";
	//a << "MOVER NIVEL DESDE LA PILA:\t"<<"PONER AQUI LA PILA1"<<"A LA PILA" <<"\n" ;
	return a.str();
}

