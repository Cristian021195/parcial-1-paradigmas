/*
 * APP.cpp
 *
 *  Created on: 18 oct. 2023
 *      Author: Alumno
 */


#include <iostream>
#include "APP.h"
#include "Venta.h"
#include "Compra.h"

APP::APP() {}

void APP::cargarCompra(int dia, int mes, int anio, Obra* obra, float monto){
	Compra *caux = new Compra(dia, mes, anio, obra, monto);
	transacciones.push_back(caux);
}

void APP::cargarVenta(int dia, int mes, int anio, Obra* obra, float monto){
	Venta *vaux = new Venta(dia, mes, anio, obra, monto);
	transacciones.push_back(vaux);
}
void APP::listarTransacciones(){
	unsigned long int cont;
	for(cont = 0; cont < transacciones.size(); cont++){
		//cout << transacciones[cont]->ganancia() << endl;
		transacciones[cont]->listarInfo();
	}
}

void APP::listarTPerdida(){
	unsigned long int cont;
	for(cont = 0; cont < transacciones.size(); cont++){
		if(transacciones[cont]->ganancia() < 0){
			transacciones[cont]->listarInfo();
		}
	}
}
void APP::listarTGanancia(){
	unsigned long int cont;
	for(cont = 0; cont < transacciones.size(); cont++){
		if(transacciones[cont]->ganancia() >= 0){
			transacciones[cont]->listarInfo();
		}
	}
}

void APP::resumen(Fecha &fechaI, Fecha &fechaF){
	float importe=0;
	unsigned long int cont;
	for(cont = 0; cont < transacciones.size(); cont++){
		if(fechaF>= transacciones[cont]->getFecha() && transacciones[cont]->getFecha()>= fechaI){
			importe+= transacciones[cont]->ganancia();
			transacciones[cont]->listarInfo();
		}
	}
	cout << " ----------- ----------- ----------- " << endl;
	cout << " Total: " << importe << endl;
}

APP::~APP() {
	unsigned long int cont;
	unsigned long int max = transacciones.size();
	for(cont = 0; cont < max; cont++){
		delete transacciones[cont];
	}
}

APP::APP(const APP &other) {}

