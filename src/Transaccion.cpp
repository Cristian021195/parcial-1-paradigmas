/*
 * Transaccion.cpp
 *
 *  Created on: 18 oct. 2023
 *      Author: Alumno
 */

#include "Transaccion.h"

long int Transaccion::serial = 0;

Transaccion::Transaccion(){}

Transaccion::Transaccion(int dia, int mes, int anio, Obra* obra,float monto)
:fecha(dia, mes, anio), obra(obra), monto(monto), codigo(serial){
	serial++;
	//cout << "asd" << obra->montoSugerido() << endl;
}

void Transaccion::listarInfo(){
	cout << "TRANSACCION #" << codigo << " ,Fecha: " << fecha.getDia() << "/" << fecha.getMes() << "/" << fecha.getAnio() << " Ganancia: " << ganancia() << endl;
}

Fecha Transaccion::getFecha(){return fecha;}
float Transaccion::getMonto(){return monto;}
Obra * Transaccion::getObra(){return obra;}

float Transaccion::ganancia(){
	return 0;
}

void Transaccion::absFn(){}

Transaccion::~Transaccion() {
	serial--;
}

Transaccion::Transaccion(const Transaccion &other) {}

