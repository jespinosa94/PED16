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
	TAVLPoro b;
	TAVLPoro c;
	TPoro a1(1, 1, 1);
	TPoro a2(2, 2, 2);
	TPoro a3(3, 3, 3);
	TPoro a4(4, 4, 4);
	TPoro a5(5, 5, 5);
	TPoro a6(6, 6, 6);
	TPoro a7(7, 7, 7);
	TPoro a8(8, 8, 8);
	TPoro a9(9, 9, 9);
	TPoro a10(10, 10, 10);
	TPoro a11(11, 11, 11);

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
	comp.str( std::string() );
	comp.clear();

	if(a.Insertar(a4))
		cout << "P3- OK\n";
	else cout << "P3- NOPE\n";
	a.Insertar(a5);
	a.Insertar(a7);
	if(a.Insertar(a2))
		cout << "P4- OK\n";
	else cout << "P4- NOPE\n";
	a.Insertar(a1);
	a.Insertar(a5);
	a.Insertar(a3);
	a.Insertar(a6);

	comp << a;
	esperado = "[1 (1, 1) 1.00 - 2 (2, 2) 2.00 - 3 (3, 3) 3.00 - 4 (4, 4) 4.00 - 5 (5, 5) 5.00 - 6 (6, 6) 6.00 - 7 (7, 7) 7.00 -]";
	if(esperado.compare(comp.str())==0)
		cout << "P5- OK\n";
	else cout << "P6- NOPE\n";
	//Limpia el contenido del buffer
	comp.str( std::string() );
	comp.clear();

	if(b.Insertar(a1) && b.Insertar(a2) && b.Insertar(a3) && b.Insertar(a4) && b.Insertar(a5)
			&& b.Insertar(a6) && b.Insertar(a7) && !b.Insertar(a1))
		cout << "P6- OK\n";
	else cout << "P6- NOPE\N";
	if(b == a)
		cout << "P7- OK\n";
	else cout << "P7- NOPE\n";

	b.~TAVLPoro();
	if(b.EsVacio() && !a.EsVacio() && b==c)
		cout << "P8- OK\n";
	else cout << "P8- NOPE\n";
	b.Insertar(a5);
	b.Insertar(a3);
	b.Insertar(a8);
	b.Insertar(a2);
	b.Insertar(a4);
	b.Insertar(a7);
	b.Insertar(a10);
	b.Insertar(a1);
	b.Insertar(a6);
	b.Insertar(a9);
	b.Insertar(a11);

	if(b.Borrar(a4) && !b.Borrar(a4) && b.Borrar(a8) && b.Borrar(a6) && b.Borrar(a5) && b.Borrar(a2) && b.Borrar(a1) && !b.Borrar(a8) && b.Borrar(a7))
		cout << "P9- OK\n";
	else cout << "P9- NOPE\n";

	comp << b;
	esperado = "[1 (3, 3) 3.00 - 2 (9, 9) 9.00 - 3 (10, 10) 10.00 - 4 (11, 11) 11.00 -]";
	if(esperado.compare(comp.str())==0)
		cout << "P10- OK\n";
	else cout << "P10- NOPE\n";
	//Limpia el contenido del buffer
	comp.str( std::string() );
	comp.clear();

	b.Borrar(a10);
	b.Borrar(a11);
	b.Borrar(a3);
	b.Borrar(a9);
	if(b.EsVacio())
		cout << "P11- OK\n";
	else cout << "P11- NOPE\n";

	c = a;
	if(c==a && b!=a && b!= c)
		cout << "P12- OK\n";
	else cout << "P12- NOPE\n";

	TAVLPoro d(c);
	if(d==a)
		cout << "P13- OK\n";
	else cout << "P13- NOPE\n";
	b.~TAVLPoro();
	comp << b.Raiz() << a.Raiz();
	esperado = "()(4, 4) 4.00 -";
	if(esperado.compare(comp.str())==0)
		cout << "P14- OK\n";
	else cout << "P14- NOPE\n";
	//Limpia el contenido del buffer
	comp.str( std::string() );
	comp.clear();

	if(a.NodosHoja()==4 && b.NodosHoja()==0)
		cout << "P15- OK\n";
	else cout << "P15- NOPE\n";

	cout << "\nFin de las pruebas :)";
}




