#ifndef CONTROL_H
#define CONTROL_H

//#pragma once
#include"Nivel.h"
#include"Interfaz.h"

class Control{
private:
	Nivel* nivel;
public:
	Control();
	~Control();
	void CONTROLADORA();
	char MENUPRINCIPAL();
	char MENUJUGAR();
	//void cargarDatos();
};
#endif // !CONTROL_H



