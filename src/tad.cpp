/*
 * main.cpp
 *
 *  Created on: 3 de feb. de 2016
 *      Author: jorge
 */
#include <iostream>
#include <cstring>
#include "../include/tporo.h"
#include "../include/tvectorporo.h"
using namespace std;
/*-Si no se va a modificar la variable de dentro de la función poner const
 *-Si no se va a modificar ningún valor dentro de la funcion poner const al final de la funcion
 */
int main(){
	TPoro p1;
	TPoro p2(1, 2, 3.2432423);
	TPoro p3(3, 4, -5.456, "rojo");
	TPoro p4(4, 5, 5, "VERDE");
	TPoro p5(p1);
	TPoro p6(1, 1, 1.1111);
/**************************************PRUEBAS BÁSICAS DE LA CLASE TPORO************************************/
//Prueba que EsVacio funciona y que los Poros se construyen correctamente
	if(p1.EsVacio())
		cout << "P1- OK\n";
	else
		cout << "P1- NOPE\n";
/*_____________________________________________________________________________________________________*/
	if(!p2.EsVacio())
		cout << "P2- OK \n";
	else
		cout << "P1- NOPE\n";
/*_____________________________________________________________________________________________________*/
	p2.Posicion(3, 3);
	p2.Volumen(1);
	p2.Color("olaKase");
		if(p2.PosicionX() == 3 && p2.PosicionY() == 3 && p2.Volumen() == 1 &&
				!strcmp(p2.Color(), "olakase"))
			cout << "P3- OK\n";
		else
			cout << "P3- NOPE\n";
/*_____________________________________________________________________________________________________*/

cout << p1 << endl << p2 << endl << p3 << endl << p4 << endl << p6 << endl;

cout << "________________________PRUEBAS DE TVectorPoro________________________\n";

TVectorPoro t1;
TVectorPoro t2(-5);
TVectorPoro t3(4);
TVectorPoro t4(3);
t3[3] = p2;
t4[1] = p2;
t4[2] = p3;
t4[3] = p4;
cout << t1 << endl << t2 << endl << t3 << endl;
cout << t1.Cantidad() << endl << t2.Cantidad() << endl << t3.Cantidad() << endl << t4.Cantidad();
}



