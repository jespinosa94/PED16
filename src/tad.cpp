/*
 * main.cpp
 *
 *  Created on: 3 de feb. de 2016
 *      Author: jorge
 */
#include <iostream>
#include <cstring>
#include <sstream>
#include "../include/tporo.h"
#include "../include/tvectorporo.h"
#include "../include/tlistaporo.h"
#include "../include/tabbporo.h"
#include "../include/tavlporo.h"
using namespace std;
/*-Si no se va a modificar la variable de dentro de la función poner const
 *-Si no se va a modificar ningún valor dentro de la funcion poner const al final de la funcion
 */
int main(){
	cout << "Comienzo de las pruebas del cuadernillo 3...\n";

	TAVLPoro a;
	TPoro a4(4, 4, 4);
	TPoro a5(5, 5, 5);
	TPoro a7(7, 7, 7);

	if(a.EsVacio())
		cout << "P1- OK\n";
	else
		cout << "P1- NOPE\n";
	stringstream comp;
	string esperado;

	comp << a;
	esperado = "[]";
	if(esperado.compare(comp.str())==0)
		cout << "P2- OK\n";
	else
		cout << "P2- NOPE\n";
	//Limpia el contenido del buffer
//	comp.str(std::string());
	comp.clear();

	a.Insertar(a4);
	a.Insertar(a5);
	a.Insertar(a7);

	cout << a;

	cout << "\nFin de las pruebas :)";
}




