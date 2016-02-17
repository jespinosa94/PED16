/*
 * main.cpp
 *
 *  Created on: 3 de feb. de 2016
 *      Author: jorge
 */
#include <iostream>
#include "TPoro.h"
using namespace std;

int main(){
	TPoro p1;
	TPoro p2(1, 2, 3.2432423);
	TPoro p3(3, 4, 5, "rojo");
	TPoro p4(4, 5, 5, "verde");
	TPoro p5(p1);
/**************************************PRUEBAS BÁSICAS DE LA CLASE TPORO************************************/
//Prueba que EsVacio funciona y que los Poros se construyen correctamente
	if(p1.EsVacio())
		cout << "P1- OK\n";
	else
		cout << "P1- NOPE\n";

	if(!p2.EsVacio())
		cout << "P2- OK \n";
	else
		cout << "P1- NOPE\n";

	cout << p2;
	p2 = p1;
	cout << p1;
	cout << p2;
}



