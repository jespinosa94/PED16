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
using namespace std;
/*-Si no se va a modificar la variable de dentro de la función poner const
 *-Si no se va a modificar ningún valor dentro de la funcion poner const al final de la funcion
 */
int main(){
//	TPoro p1;
//	TPoro p2(1, 2, 3.2432423);
//	TPoro p3(3, 4, -5.456, "rojo");
//	TPoro p4(4, 5, 5, "VERDE");
//	TPoro p5(p1);
//	TPoro p6(1, 1, 1.1111);
///**************************************PRUEBAS BÁSICAS DE LA CLASE TPORO************************************/
////Prueba que EsVacio funciona y que los Poros se construyen correctamente
//	if(p1.EsVacio())
//		cout << "P1- OK\n";
//	else
//		cout << "P1- NOPE\n";
///*_____________________________________________________________________________________________________*/
//	if(!p2.EsVacio())
//		cout << "P2- OK \n";
//	else
//		cout << "P1- NOPE\n";
///*_____________________________________________________________________________________________________*/
//	p2.Posicion(3, 3);
//	p2.Volumen(1);
//	p2.Color("olaKase");
//		if(p2.PosicionX() == 3 && p2.PosicionY() == 3 && p2.Volumen() == 1 &&
//				!strcmp(p2.Color(), "olakase"))
//			cout << "P3- OK\n";
//		else
//			cout << "P3- NOPE\n";
///*_____________________________________________________________________________________________________*/
//
//cout << p1 << endl << p2 << endl << p3 << endl << p4 << endl << p6 << endl;
//
//cout << "________________________PRUEBAS DE TVectorPoro________________________\n";
//
//TVectorPoro t1;
//TVectorPoro t2(-5);
//TVectorPoro t3(4);
//TVectorPoro t4(3);
//t3[3] = p2;
//t4[1] = p2;
//t4[2] = p3;
//t4[3] = p4;
//
//stringstream buffer;
//buffer << t1 << t2 << t3 << t4;
//string expected = "[][][1 () 2 () 3 (3, 3) 1.00 olakase 4 ()][1 (3, 3) 1.00 olakase 2 (3, 4) -5.46 rojo 3 (4, 5) 5.00 verde]";
//if(expected.compare(buffer.str()) == 0)
//	cout << "P3.5- OK\n";
//else{
//	"P3.5- NOPE\n";
//	cout << t1 << t2 << t3 << t4;}
////cout << buffer.str() << "\n";
////cout << t1 << t2 << t3 << t4;
////cout << t1.Cantidad() << ", " << t2.Cantidad() << ", " << t3.Cantidad() << ", " << t4.Cantidad() << endl;
//
//t3 = t4;
//cout << t3 << endl;
//
//if(!t4.Redimensionar(3))
//	cout << "P4- OK\n";	else	cout << "P4- NOPE\n";
//if(!t4.Redimensionar(-3))
//	cout << "P5- OK\n";	else	cout << "P5- NOPE\n";
//if(t4.Redimensionar(5))
//	cout << "P6- OK\n";	else	cout << "P6- NOPE\n";
//if(t4.Redimensionar(2))
//	cout << "P6- OK\n";	else	cout << "P6- NOPE\n";
//cout << t4 << endl;
//	{
//		/*
//		 * PARA HACER FUNCIONAR LAS PRIMERAS PRUEBAS PONER ATRIBUTOS DE TLISTANODO A PUBLIC
//		 */
//		TPoro p1;
//		TPoro p2(1, 2, 3.2432423);
//		TPoro p3(3, 4, -5.456, "rojo");
//		TPoro p4(4, 5, 5, "VERDE");
//		TListaNodo *nodo1;
//		TListaNodo *nodo2;
//
//		/*
//		 * En *nodo1 no se inicializan los parámetros de la clase, en cambio en nodo si
//		 */
//
//		if(nodo1->e.EsVacio() && nodo1->anterior==NULL && nodo1->siguiente==NULL)
//			cout << "P1L- OK\n";
//		else cout << "P1L- NOPE\n";
//
//		nodo1->e = p1;
//		nodo2->e = p2;
//		nodo1->siguiente = nodo2;
//		nodo2->anterior = nodo1;
//		TListaNodo *nodo3(nodo1);
//		if(nodo1->siguiente->e==p2 && nodo2->anterior->e==p1 && nodo3->siguiente->e==p2)
//			cout << "P2L- OK\n";
//		else cout << "P2L- NOPE\N";
//	}
	{
		TPoro p1;
		TPoro p2(1, 2, 3.2432423);
		TPoro p3(3, 4, -5.456, "rojo");
		TPoro p4(4, 5, 5, "VERDE");
		TListaPoro l1;

		l1.Insertar(p1);
		cout << p1 << endl;
	}
}



