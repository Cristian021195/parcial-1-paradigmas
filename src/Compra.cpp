/*
 * Compra.cpp
 *
 *  Created on: 18 oct. 2023
 *      Author: Alumno
 */

#include "Compra.h"


Compra::Compra() {}

Compra::Compra(int dia, int mes, int anio, Obra* obra, float monto)
:Transaccion(dia, mes, anio, obra, monto){
	//cout << obra->montoSugerido() << endl;
}

float Compra::ganancia(){
	//cout << "Monto" << getObra().montoSugerido() << endl;
	float res = 0;
	//cout << "monto sug obra: " << getObra()->montoSugerido() << endl;
	res = getObra()->montoSugerido() - getMonto();
	return res;
}
void Compra::listarInfo() {
	cout << "Info compra" << endl;
}
void Compra:: absFn(){}
Compra::~Compra() {}

Compra::Compra(const Compra &other) {}

