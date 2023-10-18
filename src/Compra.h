/*
 * Compra.h
 *
 *  Created on: 18 oct. 2023
 *      Author: Alumno
 */

#ifndef COMPRA_H_
#define COMPRA_H_
#include <iostream>
#include "Transaccion.h"

using namespace std;

class Compra: public Transaccion {

public:
	Compra();
	Compra(int dia, int mes, int anio, Obra* obra, float monto);
	float ganancia();
	void listarInfo();
	void absFn();
	virtual ~Compra();
	Compra(const Compra &other);
};

#endif /* COMPRA_H_ */
