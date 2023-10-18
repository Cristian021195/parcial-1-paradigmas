/*
 * Venta.cpp
 *
 *  Created on: 18 oct. 2023
 *      Author: Alumno
 */

#include "Venta.h"

Venta::Venta() {}

Venta::Venta(int dia, int mes, int anio, Obra* obra, float monto)
:Transaccion(dia, mes, anio, obra, monto){
	//cout << obra->montoSugerido() << endl;
}

float Venta::ganancia(){
	//cout << "Monto" << getObra().montoSugerido() << endl;
	float res = 0;
	//cout << "monto sug obra: " << getObra()->montoSugerido() << endl;
	res = getMonto() - getObra()->montoSugerido();
	return res;
}
void Venta::listarInfo() {
	cout << "VENTA #" << endl;
}
void Venta:: absFn(){}

Venta::~Venta() {}

Venta::Venta(const Venta &other) {}

