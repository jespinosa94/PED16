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

	if(a.EsVacio())
		cout << "P1- OK\n";
	else
		cout << "P1- NOPE\n";






//	{
//		TABBPoro a;
//		TPoro p1(20, 20, 20);
//		TPoro p2(10, 10, 10);
//		TPoro p3(30, 30, 30);
//		TPoro p4(40, 40, 40);
//		TPoro p5(5, 5, 5);
//		TPoro p6(15, 15, 15);
//		TPoro p7(50, 50, 50);
//		TPoro p8(22, 22, 22);
//		TPoro p9(25, 25, 25);
//		TPoro p10(24, 24, 24);
//		TPoro p11(26, 26, 26);
//		TPoro p12(3, 3, 3);
//		TPoro p13(35, 35, 35);
//		TPoro p14(38, 38, 38);
//		TPoro p15(39, 39, 39);
//		TPoro p16(37, 37, 37);
//		TPoro p17(9, 9, 9);
//		TPoro p18(8, 8, 8);
//		TPoro p19(17, 17, 17);
//		TPoro p20(11, 11, 11);
//
//		if(a.EsVacio())
//			cout << "P1- OK\n";
//		else cout << "P1- NOPE\n";
//		if(!a.Buscar(p5) && !a.Buscar(p1) && !a.Buscar(p9) && !a.Buscar(p17))
//			cout << "P2- OK\n";
//		else
//			cout << "P2- NOPE\n";
//
//		a.Insertar(p1);
//		a.Insertar(p2);
//		a.Insertar(p3);
//		a.Insertar(p4);
//		a.Insertar(p5);
//		a.Insertar(p6);
//		a.Insertar(p7);
//		a.Insertar(p8);
//		a.Insertar(p9);
//		a.Insertar(p10);
//		a.Insertar(p11);
//		a.Insertar(p12);
//		a.Insertar(p13);
//		a.Insertar(p14);
//		a.Insertar(p15);
//		a.Insertar(p16);
//
//
//
//		if(a.Buscar(p5) && a.Buscar(p1) && a.Buscar(p9) && !a.Buscar(p17))
//			cout << "P3- OK\n";
//		else
//			cout << "P3- NOPE\n";
//
//		stringstream buffer;
//		buffer << a.Nodos();
//		string esperado = "16";
//		if(esperado.compare(buffer.str()) ==0)
//			cout << "P4- OK\n";
//		else
//			cout << "P4- NOPE\n";
//
//		//Limpia el contenido del buffer
//		buffer.str( std::string() );
//		buffer.clear();
//
//		if(!a.Insertar(p7) && !a.Insertar(p1) && !a.Insertar(p16) && a.Insertar(p17))
//			cout << "P5- OK\n";
//		else
//			cout << "P5- NOPE\n";
//		buffer << a.Inorden();
//		esperado = "[1 (3, 3) 3.00 - 2 (5, 5) 5.00 - 3 (9, 9) 9.00 - 4 (10, 10) 10.00 - 5 (15, 15) 15.00 - 6 (20, 20) 20.00 - 7 (22, 22) 22.00 - 8 (24, 24) 24.00 - 9 (25, 25) 25.00 - 10 (26, 26) 26.00 - 11 (30, 30) 30.00 - 12 (35, 35) 35.00 - 13 (37, 37) 37.00 - 14 (38, 38) 38.00 - 15 (39, 39) 39.00 - 16 (40, 40) 40.00 - 17 (50, 50) 50.00 -]";
//		if(esperado.compare(buffer.str())==0)
//			cout << "P5- OK\n";
//		else
//			cout << "P5- NOPE \n";
//		//Limpia el contenido del buffer
//		buffer.str( std::string() );
//		buffer.clear();
//
//		buffer << a.Preorden();
//		esperado = "[1 (20, 20) 20.00 - 2 (10, 10) 10.00 - 3 (5, 5) 5.00 - 4 (3, 3) 3.00 - 5 (9, 9) 9.00 - 6 (15, 15) 15.00 - 7 (30, 30) 30.00 - 8 (22, 22) 22.00 - 9 (25, 25) 25.00 - 10 (24, 24) 24.00 - 11 (26, 26) 26.00 - 12 (40, 40) 40.00 - 13 (35, 35) 35.00 - 14 (38, 38) 38.00 - 15 (37, 37) 37.00 - 16 (39, 39) 39.00 - 17 (50, 50) 50.00 -]";
//		if(esperado.compare(buffer.str())==0)
//			cout << "P6- OK\n";
//		else
//			cout << "P6- NOPE\n";
//		//Limpia el contenido del buffer
//		buffer.str( std::string() );
//		buffer.clear();
//
//		buffer << a.Postorden();
//		esperado = "[1 (3, 3) 3.00 - 2 (9, 9) 9.00 - 3 (5, 5) 5.00 - 4 (15, 15) 15.00 - 5 (10, 10) 10.00 - 6 (24, 24) 24.00 - 7 (26, 26) 26.00 - 8 (25, 25) 25.00 - 9 (22, 22) 22.00 - 10 (37, 37) 37.00 - 11 (39, 39) 39.00 - 12 (38, 38) 38.00 - 13 (35, 35) 35.00 - 14 (50, 50) 50.00 - 15 (40, 40) 40.00 - 16 (30, 30) 30.00 - 17 (20, 20) 20.00 -]";
//		if(esperado.compare(buffer.str())==0)
//			cout << "P7- OK\n";
//		else
//			cout << "P7- NOPE\n";
//		//Limpia el contenido del buffer
//		buffer.str( std::string() );
//		buffer.clear();
//
//		TABBPoro b;
//		b.Insertar(p1);
//		b.Insertar(p2);
//
//		if(a == b)
//			cout << "P8- NOPE\n";
//		else cout << "P8- OK\n";
//
//		b.~TABBPoro();
//		if(b.EsVacio())
//			cout << "P9- OK\n";
//		else
//			cout << "P9- NOPE\n";
//
//
//		TABBPoro c(a);
//		b = c;
//		if(a == b)
//			cout << "P10- OK\n";
//		else cout << "P10- NOPE\n";
//
//		//SE INTERCAMBIA EL ORDEN DE LOS DOS ULTIMOS ELEMENTOS PARA COMPARAR
//		a.~TABBPoro();
//		a.Insertar(p1);
//		a.Insertar(p2);
//		a.Insertar(p3);
//		a.Insertar(p4);
//		a.Insertar(p5);
//		a.Insertar(p6);
//		a.Insertar(p7);
//		a.Insertar(p8);
//		a.Insertar(p9);
//		a.Insertar(p10);
//		a.Insertar(p11);
//		a.Insertar(p12);
//		a.Insertar(p13);
//		a.Insertar(p14);
//		a.Insertar(p16);
//		a.Insertar(p15);
//		if(a==c)
//			cout << "P11- NOPE\n";
//		else
//			cout << "P11- OK\n";
//
//		buffer << c.Niveles();
//		esperado = "[1 (20, 20) 20.00 - 2 (10, 10) 10.00 - 3 (30, 30) 30.00 - 4 (5, 5) 5.00 - 5 (15, 15) 15.00 - 6 (22, 22) 22.00 - 7 (40, 40) 40.00 - 8 (3, 3) 3.00 - 9 (9, 9) 9.00 - 10 (25, 25) 25.00 - 11 (35, 35) 35.00 - 12 (50, 50) 50.00 - 13 (24, 24) 24.00 - 14 (26, 26) 26.00 - 15 (38, 38) 38.00 - 16 (37, 37) 37.00 - 17 (39, 39) 39.00 -]";
//		if(esperado.compare(buffer.str())==0)
//			cout << "P12- OK\n";
//		else
//			cout << "P12- NOPE\n";
//		//Limpia el contenido del buffer
//		buffer.str( std::string() );
//		buffer.clear();
//
//		c.~TABBPoro();
//		buffer << c;
//		esperado = "[]";
//		if(esperado.compare(buffer.str())==0)
//			cout << "P13- OK\n";
//		else cout << "P13- NOPE\n";
//		//Limpia el contenido del buffer
//		buffer.str( std::string() );
//		buffer.clear();
//
//
////		/******************************************13.5*********************************************/
////		a.~TABBPoro();
////		a.Insertar(p19);
////		a.Insertar(p18);
////		a.Insertar(p11);
////		a.Insertar(p5);
////		a.Insertar(p20);
////		a.Insertar(p4);
////		a.Borrar(p11);
////		cout << a;
////
////
////
////
////
////
////
////
////
////		/****************************************************************/
//
//		a = b; //a vuelve a ser el arbol de prueba
//		TABBPoro d(a);
//		//este es el de la rallada de la lista ordenada en el arbol
//		b.Borrar(p5);
//		b.Borrar(p12);
//		b.Borrar(p16);
//		b.Borrar(p13);
//		buffer << b;
//		esperado = "[1 (20, 20) 20.00 - 2 (10, 10) 10.00 - 3 (30, 30) 30.00 - 4 (9, 9) 9.00 - 5 (15, 15) 15.00 - 6 (22, 22) 22.00 - 7 (40, 40) 40.00 - 8 (25, 25) 25.00 - 9 (38, 38) 38.00 - 10 (50, 50) 50.00 - 11 (24, 24) 24.00 - 12 (26, 26) 26.00 - 13 (39, 39) 39.00 -]";
//		if(esperado.compare(buffer.str())==0)
//			cout << "P14- OK\n";
//		else cout << "P14- NOPE\n";
//		//Limpia el contenido del buffer
//		buffer.str( std::string() );
//		buffer.clear();
//
//		a.Borrar(p5);
//		a.Borrar(p12);
//		a.Borrar(p3);
//		a.Borrar(p8);
//		a.Borrar(p15);
//		buffer << a;
//		esperado = "[1 (20, 20) 20.00 - 2 (10, 10) 10.00 - 3 (26, 26) 26.00 - 4 (9, 9) 9.00 - 5 (15, 15) 15.00 - 6 (25, 25) 25.00 - 7 (40, 40) 40.00 - 8 (24, 24) 24.00 - 9 (35, 35) 35.00 - 10 (50, 50) 50.00 - 11 (38, 38) 38.00 - 12 (37, 37) 37.00 -]";
//		if(esperado.compare(buffer.str())==0)
//			cout << "P15- OK\n";
//		else cout << "P15- NOPE\n";
//		//Limpia el contenido del buffer
//		buffer.str( std::string() );
//		buffer.clear();
//
////		cout << a << endl;
//		a.Borrar(p1);
//		a.Borrar(p2);
//		a.Borrar(p3);
//		a.Borrar(p4);
//		a.Borrar(p5);
//		a.Borrar(p6);
//		a.Borrar(p7);
//		a.Borrar(p8);
//		a.Borrar(p9);
//		a.Borrar(p10);
//		a.Borrar(p11);
//		a.Borrar(p12);
//		a.Borrar(p13);
//		a.Borrar(p14);
//		a.Borrar(p15);
//		a.Borrar(p16);
//		a.Borrar(p17);
//
//		if(a.EsVacio())
//			cout << "P16- OK\n";
//		else cout << "P16- NOPE\n";
//		if(d.NodosHoja()==8 && b.NodosHoja()==6 && c.NodosHoja()==0)
//			cout << "P17- OK\n";
//		else cout << "P17- NOPE\n";
//
//		buffer << b.Raiz() << c.Raiz();
//		esperado = "(20, 20) 20.00 -()";
//		if(esperado.compare(buffer.str())==0)
//			cout << "P18- OK\n";
//		else cout << "P18- NOPE\n";
//		//Limpia el contenido del buffer
//		buffer.str( std::string() );
//		buffer.clear();
//
//		TABBPoro e(d); //arboles de prueba
//		if(d == e)
//			cout << "P19- OK\n";
//		else cout << "P19- NOPE\n";
//		if(d==c)
//			cout << "P20- NOPE\n";
//		else cout << "P20- OK\n";
//		e.~TABBPoro();
//		if(c == e)
//			cout << "P21- OK\n";
//		else cout << "P21- NOPE\n";
//
//		if(a.Altura()==0 && b.Altura()==5 && d.Altura()==6)
//			cout << "P22- OK\n";
//		else
//			cout << "P22- NOPE\n";
//
//		b.~TABBPoro();
//		a.Insertar(p1);
//		a.Insertar(p2);
//		a.Insertar(p3);
//		b.Insertar(p5);
//		b.Insertar(p12);
//		b.Insertar(p3);
//		b.Insertar(p8);
//		b.Insertar(p4);
//		b.Insertar(p6);
//		a = a+b;
//		buffer << a;
//		esperado = "[1 (20, 20) 20.00 - 2 (10, 10) 10.00 - 3 (30, 30) 30.00 - 4 (3, 3) 3.00 - 5 (15, 15) 15.00 - 6 (22, 22) 22.00 - 7 (40, 40) 40.00 - 8 (5, 5) 5.00 -]";
//		if(esperado.compare(buffer.str())==0)
//			cout << "P23- OK\n";
//		else cout << "P23- NOPE\n";
//		//Limpia el contenido del buffer
//		buffer.str( std::string() );
//		buffer.clear();
//
//		a = a-b;
//		buffer << a;
//		esperado = "[1 (10, 10) 10.00 - 2 (20, 20) 20.00 -]";
//		if(esperado.compare(buffer.str())==0)
//			cout << "P24- OK\n";
//		else cout << "P24- NOPE\n";
//		//Limpia el contenido del buffer
//		buffer.str( std::string() );
//		buffer.clear();
//
//	}
}




