#include <iostream>
#include "../include/tporo.h"
#include "../include/tvectorporo.h"
#include "../include/tlistaporo.h"
#include "../include/tabbporo.h"
using namespace std;

int
main(void)
{
  {
/*******************************************************************/
/***************** CONSTR. COPIA , "=" ; posible copia de punteros */
/*******************************************************************/

  TABBPoro a;

  TPoro p1(1,2,1,(char *) "rojo");
  TPoro p2(1,2,2,(char *) "verde");

  a.Insertar(p1);

  TABBPoro b(a), c;
  c=b;

  a.Insertar(p2);
  if( a.Inorden() == b.Inorden() )
        cout << "MAL! SE HAN COPIADO PUNTEROS" << endl;
  else
	cout << "CORRECTO CONSTRUCTOR DE COPIA" << endl;


  b.Insertar(p2);
  if( b.Inorden() == c.Inorden() )
        cout << "MAL! SE HAN COPIADO PUNTEROS" << endl;
  else
	cout << "CORRECTA ASIGNACION " << endl;


}
{
/*******************************************************************/
/********** ASIGNACION , "<<" ; posible problema de CONST 	   */
/*******************************************************************/

  TABBPoro a,b,c;

  TPoro p1(1,2,1,(char *) "rojo");

  b.Insertar(p1);


  cout << (a = b).Inorden() << endl;

  cout << (a = c).Inorden() << endl;



}
{
/*******************************************************************/
/***************** EsVacio() ; 					   */
/*******************************************************************/

  TABBPoro a ;

  if( a.EsVacio() )
        cout << "VACIO" << endl;
  else
	cout << "INCORRECTO EsVacio()" << endl;

  TPoro p1(1,2,1,(char *) "rojo");

  a.Insertar(p1);
  if( a.EsVacio() )
        cout << "INCORRECTO EsVacio()" << endl;
  else
	cout << "NO VACIO" << endl;

  a.Borrar(p1);
  if( a.EsVacio() )
        cout << "VACIO" << endl;
  else
	cout << "INCORRECTO Borrar()" << endl;



}
{
/*******************************************************************/
/***************** Insertar(), Borrar() */
/*******************************************************************/

  TABBPoro a;

  TPoro p1(1,2,1,(char *) "rojo");
  TPoro p2(1,2,2,(char *) "rojo");
  TPoro p3(1,2,3,(char *) "rojo");
  TPoro p4(1,2,4,(char *) "rojo");
  TPoro p5(1,2,5,(char *) "rojo");
  TPoro p6(1,2,6,(char *) "rojo");
  TPoro p7(1,2,7,(char *) "rojo");

  a.Insertar(p5);
  a.Insertar(p2);
  a.Insertar(p1);
  a.Insertar(p3);
  a.Insertar(p6);

  if(a.Insertar(p7))
        cout << "Insertado" << endl;
  else
	cout << "Error NO INSERCION" << endl;

  if(a.Insertar(p7))
        cout << "Error INSERCION" << endl;
  else
	cout << "No insertado" << endl;

  if(a.Borrar(p7))
        cout << "Borrado" << endl;
  else
	cout << "Error NO BORRADO" << endl;

  if(a.Borrar(p7))
        cout << "Error BORRADO" << endl;
  else
	cout << "No borrado" << endl;

  if(a.Insertar(p7))
        cout << "Insertado" << endl;
  else
	cout << "Error NO INSERCION" << endl;




}
{
/*******************************************************************/
/***************** INSERCION MULTIPLE; posible desborde de memoria */
/*******************************************************************/

TABBPoro a;

for(int i=1; i<=2; i++)
//for(int i=1; i<=100; i++)
{
  for( int num=1; num<=5; num++)
//  for( int num=1; num<=1000; num++)
  {
  	TPoro p1(1,2,(double) num,(char *) "rojo");
  	if(!a.Insertar(p1))
		cout << "Error NO INSERCION" << endl;
	p1.~TPoro();
  }
  a.~TABBPoro();
}

cout << "CORRECTA INSERCION MULTIPLE" << endl;


}

{
/************************************************************************/
/***************** INSERCION MULTIPLE (2) ; posible desborde de memoria */
/************************************************************************/

TABBPoro a;

for(int i=1; i<=100; i++)
{
  int num;
  for(num=1; num<=10; num++)
//  for(num=1; num<=1000; num++)
  {
  	TPoro p1(1,2,(double) num,(char *) "rojo");
  	if(!a.Insertar(p1))
		cout << "Error NO INSERCION" << endl;
	p1.~TPoro();
  }
  for(num=1; num<=10; num++)
//  for(num=1; num<=1000; num++)
  {
  	TPoro p1(1,2,(double) num,(char *) "rojo");
  	if(!a.Borrar(p1))
		cout << "Error NO BORRADO" << endl;
	p1.~TPoro();
  }
}

cout << "CORRECTA INSERCION MULTIPLE" << endl;


}

{
/************************************/
/***************** INORDEN, BORRADO */
/************************************/

  TABBPoro a;

  TPoro p1(1,2,20,(char *) "rojo");
  TPoro p2(1,2,10,(char *) "rojo");
  TPoro p3(1,2,24,(char *) "rojo");
  TPoro p4(1,2,8,(char *) "rojo");
  TPoro p5(1,2,12,(char *) "rojo");
  TPoro p6(1,2,26,(char *) "rojo");
  TPoro p7(1,2,28,(char *) "rojo");

  a.Insertar(p1);
  a.Insertar(p2);
  a.Insertar(p3);
  a.Insertar(p4);
  a.Insertar(p5);
  a.Insertar(p6);
  a.Insertar(p7);

  if(!a.Borrar(p7))
  	cout << "Error NO BORRADO" << endl;
  if(!a.Borrar(p6))
  	cout << "Error NO BORRADO" << endl;
  if(!a.Borrar(p3))
  	cout << "Error NO BORRADO" << endl;

  cout << a.Inorden() << endl;

  if(!a.Borrar(p5))
  	cout << "Error NO BORRADO" << endl;
  if(!a.Borrar(p4))
  	cout << "Error NO BORRADO" << endl;
  if(!a.Borrar(p2))
  	cout << "Error NO BORRADO" << endl;
  if(!a.Borrar(p1))
  	cout << "Error NO BORRADO" << endl;

  cout << a.Inorden() << endl;




}
{
/************************************/
/***************** BORRADO CON HIJO */
/************************************/

  TABBPoro a;

  TPoro p1(1,2,20,(char *) "rojo");
  TPoro p2(1,2,10,(char *) "rojo");
  TPoro p3(1,2,24,(char *) "rojo");
  TPoro p4(1,2,8,(char *) "rojo");
  TPoro p5(1,2,12,(char *) "rojo");
  TPoro p6(1,2,26,(char *) "rojo");
  TPoro p7(1,2,28,(char *) "rojo");

  a.Insertar(p1);
  a.Insertar(p2);
  a.Insertar(p3);
  a.Insertar(p4);
  a.Insertar(p5);
  a.Insertar(p6);
  a.Insertar(p7);

  if(!a.Borrar(p3))
  	cout << "Error NO BORRADO" << endl;
  if(!a.Borrar(p6))
  	cout << "Error NO BORRADO" << endl;

  cout << a.Inorden() << endl;



}
{
/***************************************/
/***************** BORRADO CON 2 HIJOS */
/***************************************/

  TABBPoro a;

  TPoro p1(1,2,20,(char *) "rojo");
  TPoro p2(1,2,10,(char *) "rojo");
  TPoro p3(1,2,24,(char *) "rojo");
  TPoro p4(1,2,8,(char *) "rojo");
  TPoro p5(1,2,12,(char *) "rojo");
  TPoro p6(1,2,26,(char *) "rojo");
  TPoro p7(1,2,28,(char *) "rojo");
  TPoro p8(1,2,11,(char *) "rojo");

  a.Insertar(p1);
  a.Insertar(p2);
  a.Insertar(p3);
  a.Insertar(p4);
  a.Insertar(p5);
  a.Insertar(p6);
  a.Insertar(p7);

  if(!a.Borrar(p1))
  	cout << "Error NO BORRADO" << endl;

  if(!a.Borrar(p5))
  	cout << "Error NO BORRADO" << endl;

  if(!a.Borrar(p8))
  	cout << "Error NO BORRADO" << endl;

  if(!a.Borrar(p2))
  	cout << "Error NO BORRADO" << endl;

  if(!a.Borrar(p4))
  	cout << "Error NO BORRADO" << endl;

  cout << a.Inorden() << endl;



}
{
/**********************************************/
/***************** Buscar()               */
/**********************************************/

  TABBPoro a;

  TPoro p1(1,2,1,(char *) "rojo");
  TPoro p2(1,2,2,(char *) "rojo");
  TPoro p3(1,2,3,(char *) "rojo");
  TPoro p4(1,2,4,(char *) "rojo");
  TPoro p5(1,2,5,(char *) "rojo");
  TPoro p6(1,2,6,(char *) "rojo");
  TPoro p7(1,2,7,(char *) "rojo");

  a.Insertar(p5);
  a.Insertar(p2);
  a.Insertar(p1);
  a.Insertar(p3);
  a.Insertar(p6);

  bool busc = a.Buscar(p7);
  cout <<"Encontrado = "<<busc<<endl;
  bool ins = a.Insertar(p7);
  cout <<"Insertado = "<<ins<<endl;
  busc = a.Buscar(p7);
  cout <<"Encontrado = "<<busc<<endl;


  bool busc2 = a.Buscar(p1);
  cout <<"Encontrado = "<<busc2<<endl;
  bool ins2 = a.Insertar(p1);
  cout <<"Insertado = "<<ins2<<endl;
  bool bor2 = a.Borrar(p1);
  cout <<"Borrado = "<<bor2<<endl;
  busc2 = a.Buscar(p1);
  cout <<"Encontrado = "<<busc2<<endl;


}

{
/**********************************************/
/***************** ALTURA, NODOS, NODOSHOJA   */
/**********************************************/

  TABBPoro a;

  TPoro p100(1,2,100,(char *) "rojo");
  TPoro p50(1,2,50,(char *) "rojo");
  TPoro p20(1,2,20,(char *) "rojo");
  TPoro p110(1,2,110,(char *) "rojo");

  cout <<"Altura: "<<a.Altura()<<endl;
  cout <<"Nodos: "<<a.Nodos()<<endl;
  cout <<"NodosHoja: "<<a.NodosHoja()<<endl;
  cout <<"Raiz: "<<a.Raiz()<<endl;

  a.Insertar(p100);
  cout <<"Altura: "<<a.Altura()<<endl;
  cout <<"Nodos: "<<a.Nodos()<<endl;
  cout <<"NodosHoja: "<<a.NodosHoja()<<endl;
  cout <<"Raiz: "<<a.Raiz()<<endl;

  a.Insertar(p50);
  cout <<"Altura: "<<a.Altura()<<endl;
  cout <<"Nodos: "<<a.Nodos()<<endl;
  cout <<"NodosHoja: "<<a.NodosHoja()<<endl;
  cout <<"Raiz: "<<a.Raiz()<<endl;

  a.Insertar(p20);
  cout <<"Altura: "<<a.Altura()<<endl;
  cout <<"Nodos: "<<a.Nodos()<<endl;
  cout <<"NodosHoja: "<<a.NodosHoja()<<endl;
  cout <<"Raiz: "<<a.Raiz()<<endl;

  a.Insertar(p110);
  cout <<"Altura: "<<a.Altura()<<endl;
  cout <<"Nodos: "<<a.Nodos()<<endl;
  cout <<"NodosHoja: "<<a.NodosHoja()<<endl;
  cout <<"Raiz: "<<a.Raiz()<<endl;

  a.Borrar(p20);
  cout <<"Altura: "<<a.Altura()<<endl;
  cout <<"Nodos: "<<a.Nodos()<<endl;
  cout <<"NodosHoja: "<<a.NodosHoja()<<endl;
  cout <<"Raiz: "<<a.Raiz()<<endl;




}
{
/*******************************************************************/
/***************** Insertar(), Borrar() */
/*******************************************************************/

  TABBPoro a,b;

  TPoro p1(1,2,1,(char *) "rojo");
  TPoro p2(1,2,2,(char *) "rojo");
  TPoro p3(1,2,3,(char *) "rojo");
  TPoro p4(1,2,4,(char *) "rojo");
  TPoro p5(1,2,5,(char *) "rojo");
  TPoro p6(1,2,6,(char *) "rojo");
  TPoro p7(1,2,7,(char *) "rojo");

  a.Insertar(p1);
  a.Insertar(p2);

  b.Insertar(p1);
  b.Insertar(p2);

  if (a==b)
	cout << "IGUALES" << endl;




}
{
/*******************************************************************/
/***************** Insertar(), Borrar() */
/*******************************************************************/

  TABBPoro a,b;

  TPoro p1(1,2,1,(char*) "rojo");
  TPoro p2(1,2,2,(char*) "rojo");
  TPoro p3(1,2,3,(char*) "rojo");
  TPoro p4(1,2,4,(char*) "rojo");
  TPoro p5(1,2,5,(char*) "rojo");
  TPoro p6(1,2,6,(char*) "rojo");
  TPoro p7(1,2,7,(char*) "rojo");

  a.Insertar(p1);
  a.Insertar(p2);

  b.Insertar(p2);
  b.Insertar(p1);

  if (a==b)
	cout << "IGUALES" << endl;





}
}
