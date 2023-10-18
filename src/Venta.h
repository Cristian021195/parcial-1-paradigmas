/*
 * Venta.h
 *
 *  Created on: 18 oct. 2023
 *      Author: Alumno
 */

#ifndef VENTA_H_
#define VENTA_H_
#include <iostream>
#include "Transaccion.h"

class Venta: public Transaccion {
public:
	Venta();
	Venta(int dia, int mes, int anio, Obra* obra, float monto);
	float ganancia();
	void listarInfo();
	void absFn();
	virtual ~Venta();
	Venta(const Venta &other);
};

#endif /* VENTA_H_ */
