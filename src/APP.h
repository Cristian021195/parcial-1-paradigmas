/*
 * APP.h
 *
 *  Created on: 18 oct. 2023
 *      Author: Alumno
 */

#ifndef APP_H_
#define APP_H_
#include <iostream>
#include <vector>
#include "Transaccion.h"
#include "Compra.h"
#include "Venta.h"
#include "Fecha.h"

using namespace std;

class APP {
	vector<Transaccion*> transacciones;
public:
	APP();
	void cargarCompra(int dia, int mes, int anio, Obra* obra, float monto);
	void cargarVenta(int dia, int mes, int anio, Obra* obra, float monto);
	void listarTransacciones();
	void listarTPerdida();
	void listarTGanancia();
	void resumen(Fecha &fechaI, Fecha &fechaF);
	virtual ~APP();
	APP(const APP &other);
};

#endif /* APP_H_ */
