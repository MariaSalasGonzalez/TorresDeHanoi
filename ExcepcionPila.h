#pragma once
#include<iostream>
using namespace std;

class PilaExcepcion {
private:
	string errorMessage;
public:
	PilaExcepcion(const string& error) {
		errorMessage = error;
	}
	string getMensajeError() {
		return errorMessage;
	}
};

class PilaVacia : public PilaExcepcion {
public:
	PilaVacia(const string& error) : PilaExcepcion(error) {
	}
};

class PilaLlena : public PilaExcepcion {
public:
	PilaLlena(const string& error) : PilaExcepcion(error) {

	}

};