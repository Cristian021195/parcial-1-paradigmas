/*
 * Transaccion.h
 *
 *  Created on: 18 oct. 2023
 *      Author: Alumno
 */

#ifndef TRANSACCION_H_
#define TRANSACCION_H_
#include <iostream>
#include "Fecha.h"
#include "Obra.h"


class Transaccion {
	static long int serial;
	unsigned long int codigo;
	Fecha fecha;
	float monto;
	Obra* obra;

public:
	Transaccion();
	Transaccion(int dia, int mes, int anio, Obra* obra, float monto);
	Fecha getFecha();
	float getMonto();
	Obra * getObra();
	void listarInfo();
	virtual float ganancia();
	virtual void absFn() = 0;
	virtual ~Transaccion();
	Transaccion(const Transaccion &other);
};

#endif /* TRANSACCION_H_ */
