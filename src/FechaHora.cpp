/*
 * FechaHora.cpp
 *
 *  Created on: 21 nov 2023
 *      Author: crist
 */

#include "FechaHora.h"

#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

FechaHora::FechaHora() {
	setFechaActual();
}
FechaHora::FechaHora(short int dd, short int mm, short int aa) {
	setFechaHora(dd, mm, aa, 0, 0, 0);
}
FechaHora::FechaHora(short int d, short int m, short int a, short int H, short int M, short int S) {
	setFechaHora(d, m, a, H, M, S);
}
FechaHora::FechaHora(const FechaHora &f) :
	dia(f.dia), mes(f.mes), anio(f.anio),hora(f.hora), minuto(f.minuto), segundo(f.segundo) {
}

void FechaHora::setFechaActual(void) {
	struct tm *ptr;
	time_t sec;

	time(&sec);
	ptr = localtime(&sec);
	dia = (short) ptr->tm_mday;
	mes = (short) ptr->tm_mon + 1;
	anio = (short) ptr->tm_year + 1900;
	hora = (short) ptr->tm_hour;
	minuto = (short) ptr->tm_min;
	segundo = (short) ptr->tm_sec;
}

void FechaHora::setFecha(const short d, const short m, const short a) {
	dia = d;
	mes = m;
	anio = a;
	if(!esAnioValido() || !esMesValido() || !esDiaValido()){
		setFechaActual();
	}
}

void FechaHora::setFechaHora(const short dd, const short mm, const short aa, const short H, const short M, const short S) {
	dia = dd;
	mes = mm;
	anio = aa;
	hora = H;
	minuto = M;
	segundo = S;
	if(!esAnioValido() || !esMesValido() || !esDiaValido()){
		setFechaActual();
	}
}

bool FechaHora::esHoraValida() const {
	return (hora >= 0 && hora < 24);
}
bool FechaHora::esMinutoValido() const {
	return (minuto >= 0 && minuto < 60);
}
bool FechaHora::esSegundoValido() const {
	return (minuto >= 0 && minuto < 60);
}

bool FechaHora::esAnioValido() const {
	return (anio > 0);
}
bool FechaHora::esMesValido() const {
	return (mes >= 1 && mes <= 12);
}
bool FechaHora::esDiaValido() const {
	return (dia >= 1 && dia <= diasEnMes(mes));
}

short FechaHora::diasEnMes(const short m) const{
	short cantidadDias = 0;
	switch (m) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			cantidadDias = 31;
			break;
		case 2:
			if (esAnioBisiesto()) {
				cantidadDias = 29;
			} else {
				cantidadDias = 28;
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			cantidadDias = 30;
			break;
	}
	return cantidadDias;
}


bool FechaHora::esAnioBisiesto() const {
	return ((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0);
}

short FechaHora::getDia() const {
	return dia;
}
short FechaHora::getMes() const {
	return mes;
}
short FechaHora::getAnio() const {
	return anio;
}

short FechaHora::getHora() const {
	return hora;
}
short FechaHora::getMinuto() const {
	return minuto;
}
short FechaHora::getSegundo() const {
	return segundo;
}

long int FechaHora::cantidadDiasDelAnio(){
	long int cantidadDias = 0;
	int febrero=28 + esAnioBisiesto();
		switch (mes) {
			case 1:cantidadDias=dia;break;
			case 2:cantidadDias=31+dia;break;
			case 3:cantidadDias=31+febrero+dia;break;
			case 4:cantidadDias=31+febrero+31+dia;break;
			case 5:cantidadDias=31+febrero+31+30+dia;break;
			case 6:cantidadDias=31+febrero+31+30+31+dia;break;
			case 7:cantidadDias=31+febrero+31+30+31+30+dia;break;
			case 8:cantidadDias=31+febrero+31+30+31+30+31+dia;break;
			case 9:cantidadDias=31+febrero+31+30+31+30+31+31+dia;break;
			case 10:cantidadDias=31+febrero+31+30+31+30+31+31+30+dia;break;
			case 11:cantidadDias=31+febrero+31+30+31+30+31+31+30+31+dia;break;
			case 12:cantidadDias=31+febrero+31+30+31+30+31+31+30+31+30+dia;break;
		}
		return cantidadDias;
}
void FechaHora::imprimir(){
	cout << dia << "/" << mes << "/" << anio << " " << hora << ":" << minuto << ":" << segundo << endl;
}

unsigned short FechaHora::difHorasMismoDia(unsigned short h1,unsigned short m1,unsigned short s1,unsigned short h2,unsigned short m2,unsigned short s2){
	unsigned short diff = 0; unsigned short aux = 0;
	if(h1 >= h2){//23,59,10 //00:59:11
		aux = h1 - h2;
		if(aux == 1){
			if(m1 >= m2){
				if(s1 >= s2){
					diff++;
				}
			}
		}else{
			diff = aux;
			if(m2 > m1){
				diff--;
			}else if(m2 == m1){
				if(s2 < s1){
					diff++;
				}
			}
		}
	}
	return diff;
}

bool esAnioBisiestoP(int anio){
	return ((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0);
}
long int cantidadDiasAniosCompletosP(int anioBase, int anio){

	long int dias=0;
	if(anioBase<anio){
		for(int i=anioBase;i<anio;i++){
			if(esAnioBisiestoP(i))
				dias+=366;
			else
				dias+=365;
		}
	}
	return dias;
}


unsigned short difHD(FechaHora f1, FechaHora f2){
	unsigned short diff = 0; unsigned short aux = 0;
		if(f1.getHora() >= f2.getHora()){//23,59,10 //00:59:11
			aux = f1.getHora() - f2.getHora();
			if(aux == 1){
				if(f1.getMinuto() >= f2.getMinuto()){
					if(f1.getSegundo() >= f2.getSegundo()){
						diff++;
					}
				}
			}else{
				diff = aux;
				if(f2.getMinuto() > f1.getMinuto()){
					diff--;
				}else if(f2.getMinuto() == f1.getMinuto()){
					if(f2.getSegundo() < f1.getSegundo()){
						diff++;
					}
				}
			}
		}
		return diff;

}

bool operator>=(FechaHora fecha1, FechaHora fecha2){
	return ((fecha1.anio>fecha2.anio) || (fecha1.anio==fecha2.anio && (fecha1.mes>fecha2.mes || (fecha1.mes==fecha2.mes && fecha1.dia>=fecha2.dia))) );
}

long int operator-(FechaHora &fecha1, FechaHora &fecha2){
	long int dif=0;
	if(fecha1>=fecha2){// 21,11,2025 - 21,11,2023
		long int diasAnios = cantidadDiasAniosCompletosP(fecha2.getAnio(), fecha1.getAnio());
		long int dias2=fecha2.cantidadDiasDelAnio();
		long int dias1 =fecha1.cantidadDiasDelAnio() + diasAnios;
		dif=dias1-dias2;
	}

	if(fecha1.difHorasMismoDia(fecha1.getHora(), fecha1.getMinuto(), fecha1.getSegundo(), fecha2.getHora(), fecha2.getMinuto(), fecha2.getSegundo())){
		dif++;
	}
	/*if(diferenciaHoras(fecha1, fecha2) == 24){
		dif++;
	}*/
	return dif;
}



ostream& operator<<(ostream &salida,const FechaHora &f) {
	salida.fill('0');
	salida << setw(2) << f.getDia() << "/" << setw(2) << f.getMes() << "/" << setw(4)
			<< f.getAnio();
	return salida;
}
