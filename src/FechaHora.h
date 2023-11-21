/*
 * FechaHora.h
 *
 *  Created on: 21 nov 2023
 *      Author: crist
 */

#ifndef FECHAHORA_H_
#define FECHAHORA_H_
#include <iostream>
using namespace std;

class FechaHora {
private:
	short dia;
	short mes;
	short anio;
	short hora;
	short minuto;
	short segundo;
	bool esDiaValido() const;
	bool esMesValido() const;
	bool esAnioValido() const;
	bool esHoraValida() const;
	bool esMinutoValido() const;
	bool esSegundoValido() const;
	short diasEnMes(const short mes) const;
public:
	//Constructores
	FechaHora();
	FechaHora(const short dd, const short mm, const short aa);
	FechaHora(const short dd, const short mm, const short aa, const short H, const short M, const short S);
	FechaHora(const FechaHora &f);
	unsigned short difHorasMismoDia(unsigned short h1,unsigned short m1,unsigned short s1,unsigned short h2,unsigned short m2,unsigned short s2);

	//Setters
	void setFechaActual(void);
	void setFecha(const short dd, const short mm, const short aa);
	void setFechaHora(const short dd, const short mm, const short aa, const short H, const short M, const short S);

	//Getters
	short getDia() const;
	short getMes() const;
	short getAnio() const;
	short getHora() const;
	short getMinuto() const;
	short getSegundo() const;

	bool esAnioBisiesto(void) const;
	long int cantidadDiasDelAnio();
	void imprimir();

	//Sobrecarga de operadores
	friend unsigned short difHD(FechaHora fecha1, FechaHora fecha2);
	friend bool operator>=(FechaHora fecha1, FechaHora fecha2);
	friend long int operator-(FechaHora &fecha1, FechaHora &fecha2);//Retorna la diferencia de dias entre 2 fechas
};
ostream& operator<<(ostream &salida,const FechaHora &f);

#endif /* FECHAHORA_H_ */
