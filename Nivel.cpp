#include "Nivel.h"

Nivel::Nivel(double nivel):nivel(0.0){
	 pila1 = new Pila<double>; pilaAux = new Pila<double>; pilaFinal = new Pila<double>;
}


Nivel::~Nivel(){
	delete pila1;
	delete pilaAux;
	delete pilaFinal;
}

double Nivel::getNivel()
{
	return nivel;
}

//Opcion 3
void Nivel::Movimiento(double nivel, Pila<double>* pila1, Pila<double>* pilaAux, Pila<double>* pilaFinal){
	if (nivel == 1) {
		cout << "MOVER DISCO DE LA PILA \t" << pila1 << "A LA PILA\t" << pilaFinal << "\n";
	}
	else {
		Movimiento(nivel - 1, pila1, pilaFinal, pilaAux);
		cout << "MOVER DISCO DE LA TORRE:\t" << pilaFinal << "A LA PILA:\t" << pilaAux << "\n";
		Movimiento(nivel - 1, pilaAux, pila1, pilaFinal);
	}
}

void Nivel::setNivel(double nivel)
{
	this->nivel = nivel;
}

//opcion 2
string Nivel::minimoMovimientos(){
	stringstream a;
	double minimo = pow(2, nivel) - 1;
	a << "CANTIDAD MINIMA MOVIMIENTOS: " << minimo << endl;
	return a.str();
}

double Nivel::llenarPila()
{
	double p;
	for (int i = numDiscos; i > 0; i--) {
		p = pow((i + 10), (i + 1));
		pila1->push(new double(p));
	}
	return p;
}

string Nivel::toString() {
    stringstream a;
        //Torre 1
        if (pila1->empty()) {
            a << "Torre 1 "  <<endl;
        } else {
            a << "*pila1->top()" <<endl;
            a << "Torre 1 " << endl;
        }
        //Torre 2
        if (pilaAux->empty()) {
            a << " Torre 2 "   << endl;
            
        } else {
            a << *pilaAux->top()<< endl;
            a << "Torre 2 " <<   endl;
        }
        //Torre 3
        if (pilaFinal->empty()) {
            a << "Torre 3 " << endl;
        } else {
            a << *pilaFinal->top() << endl;
            a << "Torre 3 "  << endl;
        }
	return a.str();
}

int Nivel::getMovimientos() {
	return movimientos;
}

void Nivel::setMovimientos() {
	movimientos = movimientos + 1;
}

string Nivel::cambio1() {
	if (pila1->empty() == 0) {
		if (pilaAux->empty() == 1) {
			pilaAux->push(pila1->top());
			pila1->pop();
			setMovimientos();
			return toString();
		}
		else {
			if (pilaAux->top() < pila1->top()) {
				return "CAMBIO NO PERMITIDO /n/n" + toString();
			}
			else {
				pilaAux->push(pila1->top());
				pila1->pop();
				setMovimientos();
				return toString();
			}
		}
	}
	else {
		return "PILA SIN NIVELES \n\n" + toString();
	}
}

string Nivel::cambio2() {
	if (pila1->empty() == 0) {
		if (pilaFinal->empty() == 1) {
			pilaFinal->push(pila1->top());
			pila1->pop();
			setMovimientos();
			return toString();
		}
		else {
			if (pilaFinal->top() < pila1->top()) {
				return "CAMBIO NO PERMITIDO /n/n" + toString();
			}
			else {
				pilaFinal->push(pila1->top());
				pila1->pop();
				setMovimientos();
				return toString();
			}
		}
	}
	else {
		return "PILA SIN NIVELES \n\n" + toString();
	}
}

string Nivel::cambio3() {
	if (pilaAux->empty() == 0) {
		if (pila1->empty() == 1) {
			pila1->push(pila1->top());
			pilaAux->pop();
			setMovimientos();
			return toString();
		}
		else {
			if (pila1->top() < pilaAux->top()) {
				return "CAMBIO NO PERMITIDO /n/n" + toString();
			}
			else {
				pila1->push(pilaAux->top());
				pilaAux->pop();
				setMovimientos();
				return toString();
			}
		}
	}
	else {
		return "PILA SIN NIVELES \n\n" + toString();
	}
}

string Nivel::cambio4() {
	if (pilaAux->empty() == 0) {
		if (pilaFinal->empty() == 1) {
			pilaFinal->push(pilaAux->top());
			pilaAux->pop();
			setMovimientos();
			return toString();
		}
		else {
			if (pilaFinal->top() < pilaAux->top()) {
				return "CAMBIO NO PERMITIDO /n/n" + toString();
			}
			else {
				pilaFinal->push(pilaAux->top());
				pilaAux->pop();
				setMovimientos();
				return toString();
			}
		}
	}
	else {
		return "PILA SIN NIVELES \n\n" + toString();
	}
}

string Nivel::cambio5() {
	if (pilaFinal->empty() == 0) {
		if (pila1->empty() == 1) {
			pila1->push(pilaFinal->top());
			pilaFinal->pop();
			setMovimientos();
			return toString();
		}
		else {
			if (pila1->top() < pilaFinal->top()) {
				return "CAMBIO NO PERMITIDO /n/n" + toString();
			}
			else {
				pila1->push(pilaFinal->top());
				pilaFinal->pop();
				setMovimientos();
				return toString();
			}
		}
	}
	else {
		return "PILA SIN  NIVELES \n\n" + toString();
	}
}

string Nivel::cambio6() {
	if (pilaFinal->empty() == 0) {
		if (pilaAux->empty() == 1) {
			pilaAux->push(pilaFinal->top());
			pilaFinal->pop();
			movimientos++;
			return toString();
		}
		else {
			if (pilaAux->top() < pilaFinal->top()) {
				return "CAMBIO NO PERMITIDO/n/n" + toString();
			}
			else {
				pilaAux->push(pilaFinal->top());
				pilaFinal->pop();
				movimientos++;
				return toString();
			}
		}
	}
	else {
		return "PILA SIN NIVELES \n\n" + toString();
	}
}

string Nivel::volveraAJugar() {
	while (pila1->empty() == 0) {
		pila1->pop();
	}
	while (pilaAux->empty() == 0) {
		pilaAux->pop();
	}
	while (pilaFinal->empty() == 0) {
		pilaFinal->pop();
	}
	llenarPila();
	movimientos = 0;
	return toString();
}


bool Nivel::Gano() {
	if (pilaFinal->size() == 4) {
		return 1;
	}
	return 0;
}

/*
string Nivel::torres(double nivel)
{
	stringstream a;
	a << "TORRE 1" << endl;
	if (nivel == nivel) {
		a << "*" << endl;
		a << "**" << endl;
		a << "***" << endl;
		a << "****" << endl;
	}
	else {
		if (nivel != nivel) {
			a << "|" << endl;
			a << "|" << endl;
			a << "|" << endl;
			a << "---" << endl;
		}
		else {
			if (nivel==1 ) {
				a << "|" << endl;
				a << "|" << endl;
				a << "*" << endl;
				a << "---" << endl;
			}
			else {
				if (nivel == 2) {
					a << "|" << endl;
					a << "*" << endl;
					a << "**" << endl;
					a << "---" << endl;
				}
				else {
					if (nivel == ) {
						a << "|" << endl;
						a << "*" << endl;
						a << "**" << endl;
						a << "---" << endl;
					}
				}
			}
			}
		}
	}
	return a.str();
}*/










