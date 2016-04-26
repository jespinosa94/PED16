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
using namespace std;
/*-Si no se va a modificar la variable de dentro de la función poner const
 *-Si no se va a modificar ningún valor dentro de la funcion poner const al final de la funcion
 */
int main(){
	{
		TABBPoro a;
		TPoro p1(20, 20, 20);
		TPoro p2(10, 10, 10);
		TPoro p3(30, 30, 30);
		TPoro p4(40, 40, 40);
		TPoro p5(5, 5, 5);
		TPoro p6(15, 15, 15);
		TPoro p7(50, 50, 50);
		TPoro p8(22, 22, 22);
		TPoro p9(25, 25, 25);
		TPoro p10(24, 24, 24);
		TPoro p11(26, 26, 26);
		TPoro p12(3, 3, 3);
		TPoro p13(35, 35, 35);
		TPoro p14(38, 38, 38);
		TPoro p15(39, 39, 39);
		TPoro p16(37, 37, 37);

		TPoro p17(9, 9, 9);

		if(a.EsVacio())
			cout << "P1- OK\n";
		else cout << "P1- NOPE\n";
		if(!a.Buscar(p5) && !a.Buscar(p1) && !a.Buscar(p9) && !a.Buscar(p17))
			cout << "P2- OK\n";
		else
			cout << "P2- NOPE\n";

		a.Insertar(p1);
		a.Insertar(p2);
		a.Insertar(p3);
		a.Insertar(p4);
		a.Insertar(p5);
		a.Insertar(p6);
		a.Insertar(p7);
		a.Insertar(p8);
		a.Insertar(p9);
		a.Insertar(p10);
		a.Insertar(p11);
		a.Insertar(p12);
		a.Insertar(p13);
		a.Insertar(p14);
		a.Insertar(p15);
		a.Insertar(p16);



		if(a.Buscar(p5) && a.Buscar(p1) && a.Buscar(p9) && !a.Buscar(p17))
			cout << "P3- OK\n";
		else
			cout << "P3- NOPE\n";

		stringstream buffer;
		buffer << a.Nodos();
		string esperado = "16";
		if(esperado.compare(buffer.str()) ==0)
			cout << "P4- OK\n";
		else
			cout << "P4- NOPE\n";

		//Limpia el contenido del buffer
		buffer.str( std::string() );
		buffer.clear();

		if(!a.Insertar(p7) && !a.Insertar(p1) && !a.Insertar(p16) && a.Insertar(p17))
			cout << "P5- OK\n";
		else
			cout << "P5- NOPE\n";
		buffer << a.Inorden();
		esperado = "[1 (3, 3) 3.00 - 2 (5, 5) 5.00 - 3 (9, 9) 9.00 - 4 (10, 10) 10.00 - 5 (15, 15) 15.00 - 6 (20, 20) 20.00 - 7 (22, 22) 22.00 - 8 (24, 24) 24.00 - 9 (25, 25) 25.00 - 10 (26, 26) 26.00 - 11 (30, 30) 30.00 - 12 (35, 35) 35.00 - 13 (37, 37) 37.00 - 14 (38, 38) 38.00 - 15 (39, 39) 39.00 - 16 (40, 40) 40.00 - 17 (50, 50) 50.00 -]";
		if(esperado.compare(buffer.str())==0)
			cout << "P5- OK\n";
		else
			cout << "P5- NOPE \n";
		//Limpia el contenido del buffer
		buffer.str( std::string() );
		buffer.clear();

		buffer << a.Preorden();
		esperado = "[1 (20, 20) 20.00 - 2 (10, 10) 10.00 - 3 (5, 5) 5.00 - 4 (3, 3) 3.00 - 5 (9, 9) 9.00 - 6 (15, 15) 15.00 - 7 (30, 30) 30.00 - 8 (22, 22) 22.00 - 9 (25, 25) 25.00 - 10 (24, 24) 24.00 - 11 (26, 26) 26.00 - 12 (40, 40) 40.00 - 13 (35, 35) 35.00 - 14 (38, 38) 38.00 - 15 (37, 37) 37.00 - 16 (39, 39) 39.00 - 17 (50, 50) 50.00 -]";
		if(esperado.compare(buffer.str())==0)
			cout << "P6- OK\n";
		else
			cout << "P6- NOPE\n";
		//Limpia el contenido del buffer
		buffer.str( std::string() );
		buffer.clear();

		buffer << a.Postorden();
		esperado = "[1 (3, 3) 3.00 - 2 (9, 9) 9.00 - 3 (5, 5) 5.00 - 4 (15, 15) 15.00 - 5 (10, 10) 10.00 - 6 (24, 24) 24.00 - 7 (26, 26) 26.00 - 8 (25, 25) 25.00 - 9 (22, 22) 22.00 - 10 (37, 37) 37.00 - 11 (39, 39) 39.00 - 12 (38, 38) 38.00 - 13 (35, 35) 35.00 - 14 (50, 50) 50.00 - 15 (40, 40) 40.00 - 16 (30, 30) 30.00 - 17 (20, 20) 20.00 -]";
		if(esperado.compare(buffer.str())==0)
			cout << "P7- OK\n";
		else
			cout << "P7- NOPE\n";
		//Limpia el contenido del buffer
		buffer.str( std::string() );
		buffer.clear();

		TABBPoro b;
		b.Insertar(p1);
		b.Insertar(p2);

		if(a == b)
			cout << "P8- NOPE\n";
		else cout << "P8- OK\n";

		b.~TABBPoro();
		if(b.EsVacio())
			cout << "P9- OK\n";
		else
			cout << "P9- NOPE\n";


		TABBPoro c(a);
		b = c;
		if(a == b)
			cout << "P10- OK\n";
		else cout << "P10- NOPE\n";

		//SE INTERCAMBIA EL ORDEN DE LOS DOS ULTIMOS ELEMENTOS PARA COMPARAR
		a.~TABBPoro();
		a.Insertar(p1);
		a.Insertar(p2);
		a.Insertar(p3);
		a.Insertar(p4);
		a.Insertar(p5);
		a.Insertar(p6);
		a.Insertar(p7);
		a.Insertar(p8);
		a.Insertar(p9);
		a.Insertar(p10);
		a.Insertar(p11);
		a.Insertar(p12);
		a.Insertar(p13);
		a.Insertar(p14);
		a.Insertar(p16);
		a.Insertar(p15);
		if(a==c)
			cout << "P11- NOPE\n";
		else
			cout << "P11- OK\n";

		buffer << c.Niveles();
		esperado = "[1 (20, 20) 20.00 - 2 (10, 10) 10.00 - 3 (30, 30) 30.00 - 4 (5, 5) 5.00 - 5 (15, 15) 15.00 - 6 (22, 22) 22.00 - 7 (40, 40) 40.00 - 8 (3, 3) 3.00 - 9 (9, 9) 9.00 - 10 (25, 25) 25.00 - 11 (35, 35) 35.00 - 12 (50, 50) 50.00 - 13 (24, 24) 24.00 - 14 (26, 26) 26.00 - 15 (38, 38) 38.00 - 16 (37, 37) 37.00 - 17 (39, 39) 39.00 -]";
		if(esperado.compare(buffer.str())==0)
			cout << "P12- OK\n";
		else
			cout << "P12- NOPE\n";
		//Limpia el contenido del buffer
		buffer.str( std::string() );
		buffer.clear();

	}
}
//	{
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
//cout << t4 << endl;}
//	{
//		/*
//		 * Prueba insertar en cabeza y comparar TPoros, también inserta en la lista vacía
//		 */
//		TPoro p1;
//		TPoro p2(1, 2, 3.2432423);
//		TPoro p3(3, 4, -5.456, "rojo");
//		TPoro p4(4, 5, 5, "VERDE");
//		TListaPoro l1;
//
//		l1.Insertar(p4);
//		l1.Insertar(p2);
//		l1.Insertar(p2);
//		l1.Insertar(p3);
//		stringstream buffer;
//		buffer << l1;
//		string expected = "((3, 4) -5.46 rojo (1, 2) 3.24 - (4, 5) 5.00 verde)";
//		if(expected.compare(buffer.str()) == 0)
//			cout << "P7- OK\n";
//		else
//			cout << "P7- NOPE\n";
//
//	}
//	{
//		/*
//		 * Prueba insertar en la cola de la lista
//		 */
//		TPoro p1;
//		TPoro p2(1, 2, 3.2432423);
//		TPoro p3(3, 4, -5.456, "rojo");
//		TPoro p4(4, 5, 5, "VERDE");
//		TListaPoro l1;
//
//		l1.Insertar(p1);
//		l1.Insertar(p2);
//		l1.Insertar(p4);
//		stringstream p8;
//		p8 << l1;
//		string e = "(() (1, 2) 3.24 - (4, 5) 5.00 verde)";
//		if(e.compare(p8.str()) == 0)
//			cout << "P8- OK\n";
//		else
//			cout << "P8- NOPE\n";
//	}
//	{
//		/*
//		 * Inserción en el centro de la lista
//		 */
//				TPoro p1;
//				TPoro p2(1, 2, 3.2432423);
//				TPoro p3(3, 4, -5.456, "rojo");
//				TPoro p4(4, 5, 5, "VERDE");
//				TListaPoro l1;
//				l1.Insertar(p3);
//				l1.Insertar(p4);
//				l1.Insertar(p1);
//				l1.Insertar(p2);
//			stringstream p9;
//			p9 << l1;
//			string ep9 = "((3, 4) -5.46 rojo () (1, 2) 3.24 - (4, 5) 5.00 verde)";
//			if(ep9.compare(p9.str())==0)
//				cout << "P9- OK\n";
//			else
//				cout << "P9- NOPE\n";
//
//	}
//	{
//		/*
//		 * Operaciones de borrado sobre listas
//		 */
//		TPoro p1;
//		TPoro p2(1, 2, 3.2432423);
//		TPoro p3(3, 4, -5.456, "rojo");
//		TPoro p4(4, 5, 5, "VERDE");
//		TListaPoro l1;
//		l1.Insertar(p3);
//		l1.Insertar(p4);
//		l1.Insertar(p1);
//		l1.Insertar(p2);
//		cout << l1 << endl;
//		l1.Borrar(p3);
//		cout << l1 << endl;
//		l1.Borrar(p2);
//		cout << l1 << endl;
//		l1.Borrar(p4);
//		cout << l1 << endl;
//		l1.Borrar(p1);
//		cout << l1 << endl;
//	}
//	{
//		/*
//		 * Prueba del constructor de copia y la sobrecarga del operador =
//		 */
//		TPoro p1;
//		TPoro p2(1, 2, 3.2432423);
//		TPoro p3(3, 4, -5.456, "rojo");
//		TPoro p4(4, 5, 5, "VERDE");
//		TPoro p5(1, 1, -5.456, "amariLLo");
//		TListaPoro l1, l3;
//		l1.Insertar(p3);
//		l1.Insertar(p4);
//		l1.Insertar(p1);
//		l1.Insertar(p2);
//		l1.Insertar(p5);
//		cout << l1 << endl;
//
//		TListaPoro l2(l1);
//		cout << l1 << endl << l2 << endl;
//
//		l3 = l1;
//		cout << l3 << endl;
//	}
//	{
//		/*
//		 * Prueba de los operadores + y -
//		 */
//				TPoro p1;
//				TPoro p2(1, 2, 3.2432423);
//				TPoro p3(3, 4, -5.456, "rojo");
//				TPoro p4(4, 5, 5, "VERDE");
//				TPoro p5(1, 1, -5.456, "amariLLo");
//				TListaPoro l1, l2, l3;
//				l1.Insertar(p3);
//				l1.Insertar(p4);
//				l3.Insertar(p3);
//				l3.Insertar(p2);
//				l3.Insertar(p5);
//		l2 = l1 - l3;
//		cout << l1 << endl << l3 << endl << l2 << endl;
//	}
//	{
//		TPoro p1;
//		TPoro p2(1, 2, 3.2432423);
//		TPoro p3(3, 4, -5.456, "rojo");
//		TPoro p4(4, 5, 5, "VERDE");
//		TPoro p5(1, 1, -5.456, "amariLLo");
//		TListaPoro l1, l2;
//		l1.Insertar(p3);
//		l1.Insertar(p4);
//		l1.Insertar(p3);
//		l1.Insertar(p2);
//		l1.Insertar(p5);
//		l2 = l1.ExtraerRango(1, 3);
//		cout << l1 << endl << l2 << endl;
//	}
//}



