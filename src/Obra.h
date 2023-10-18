/*
 * Obra.h
 *
 *  Created on: 18 oct. 2023
 *      Author: Alumno
 */

#ifndef OBRA_H_
#define OBRA_H_
#include <iostream>
#include <string>
using namespace std;

class Obra {
	static long int serial;
	unsigned long int codigo;
	string nombre;
	string creador;
	float monto_sugerido;
public:
	Obra();
	Obra(string nombre, string creador, float monto_sugerido);
	float montoSugerido();
	void listarInfo();
	virtual ~Obra();
	Obra(const Obra &other);
};

#endif /* OBRA_H_ */
