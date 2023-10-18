//============================================================================
// Name        : cristian-gramajo.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Obra.h"
//#include "Transaccion.h"
//#include "Compra.h"
//#include "Venta.h"
#include "Fecha.h"
#include "APP.h"

using namespace std;

int main() {
	APP PA;
	Obra o1("mona lisa", "no recuerdo", 1000); // es como el valor de mercado, si lo vendemos a menos de esto perdemos
	Obra o2("montanias", "fotografo", 1000); // si lo compramos a menos de esto, estariamos "ganando"

	//Compra c1(18,10,2023,&o1,500);
	//Venta v1(18,10,2023,&o2,500);
	//cout << c1.ganancia() << endl;
	//cout << v1.ganancia() << endl;

	PA.cargarCompra(17,10,2023,&o1,500);
	PA.cargarVenta(18,10,2023,&o2,500);

	//PA.listarTransacciones();
	//PA.listarTGanancia();
	//PA.listarTPerdida();
	Fecha f1(17,10,2023);
	Fecha f2(18,10,2023);
	PA.resumen(f1, f2);




	return 0;
}
