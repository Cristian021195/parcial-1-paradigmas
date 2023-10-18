/*
 * Obra.cpp
 *
 *  Created on: 18 oct. 2023
 *      Author: Alumno
 */

#include "Obra.h"

long int Obra::serial = 0;

Obra::Obra() {}

Obra::Obra(string nombre, string creador, float monto_sugerido)
:nombre(nombre), creador(creador), monto_sugerido(monto_sugerido), codigo(serial){
	serial++;
}

float Obra::montoSugerido(){
	return monto_sugerido;
}

void Obra::listarInfo(){
	cout << "Obra #" << codigo << ": " << nombre << ", Creador: " << creador << ", Monto Sug: " << monto_sugerido << endl;
}

Obra::~Obra(){
	serial--;
}

Obra::Obra(const Obra &other) {}

