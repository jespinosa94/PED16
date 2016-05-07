/************************************************************
** CONSTRUCTORES, = CON ARBOLES VACIOS
*************************************************************/
#include <iostream>
#include <cstring>
#include <sstream>
#include "../include/tporo.h"
#include "../include/tvectorporo.h"
#include "../include/tlistaporo.h"
#include "../include/tabbporo.h"
#include "../include/tavlporo.h"
using namespace std;

int
main(void)
{
  {
    TAVLPoro a,c;
TAVLPoro b(a);

c=b;

cout << "No hace nada" << endl;
  }
  {
  TAVLPoro a;

  TPoro p1(1,2,1,(char *) "rojo");
  TPoro p2(1,2,2,(char *) "rojo");
  TPoro p3(1,2,3,(char *) "rojo");
  TPoro p4(1,2,4,(char *) "rojo");

  a.Insertar(p1);
  a.Insertar(p2);
  a.Insertar(p3);
  if (a.Insertar(p4))
	cout<<"Insertado"<<endl;
  else cout<<"No insertado"<<endl;

  if (a.Insertar(p3))
	cout<<"Insertado"<<endl;
  else cout<<"No insertado"<<endl;

  cout << "Altura: " << a.Altura() << endl;
  cout << a.Preorden() <<endl;
}
{
  TAVLPoro a,b;

  TPoro p1(1,2,1,(char *) "rojo");
  TPoro p2(1,2,2,(char *) "rojo");
  TPoro p3(1,2,3,(char *) "rojo");
  TPoro p4(1,2,4,(char *) "rojo");
  TPoro p5(1,2,5,(char *) "rojo");

  a.Insertar(p1);
  a.Insertar(p2);
  a.Insertar(p3);
  a.Insertar(p4);

  TAVLPoro c(a);

  b.Insertar(p1);
  b.Insertar(p2);
  b.Insertar(p3);
  b.Insertar(p4);

  if ( a==c )
  	cout << "IGUALES" << endl;
  else
	cout << "DISTINTOS" << endl;

  if ( c==b )
  	cout << "IGUALES" << endl;
  else
	cout << "DISTINTOS" << endl;

  b = a;
  cout << b.Preorden() <<endl;
  a.Insertar(p5);
  if ( a==b )
  	cout << "IGUALES" << endl;
  else
	cout << "DISTINTOS" << endl;

  cout << "Altura: " << b.Altura() << endl;
  cout << b.Preorden() <<endl;
}
{
  TAVLPoro a;
TPoro p1(1,2,1,(char *) "rojo");

a.Insertar(p1);

cout << "Altura: " << a.Altura() << endl;
cout << "Nodos: " << a.Nodos() << endl;
cout << "NodosHoja: " << a.NodosHoja() << endl;
}
{
  TAVLPoro a;

TPoro p1(1,2,1,(char *) "rojo");
TPoro p2(1,2,2,(char *) "rojo");
TPoro p3(1,2,3,(char *) "rojo");
TPoro p4(1,2,4,(char *) "rojo");

TVectorPoro v;

a.Insertar(p4);
a.Insertar(p3);
a.Insertar(p2);
a.Insertar(p1);

v = a.Inorden();
cout << "Inorden: " << v << endl;

v = a.Preorden();
cout << "Preorden: " << v << endl;

v = a.Postorden();
cout << "Postorden: " << v << endl;
}
{
  TAVLPoro arb1, arb2;

TPoro bd(1,1,1,(char *)"rojo");
TPoro bc(2,2,2,(char *)"rojo");
TPoro be(3,3,3,(char *)"rojo");
TPoro bn(4,4,4,(char *)"rojo");
TPoro ba(5,5,5,(char *)"rojo");
TPoro bm(6,6,6,(char *)"rojo");

arb1.Insertar(ba);
arb1.Insertar(bc);
arb1.Insertar(bd);
arb1.Insertar(be);
arb1.Insertar(bm);


arb2 = arb1;
if(arb2 != arb1)
  cout << "No iguales" <<endl;
else
  cout << "Iguales" << endl;

cout << "Altura: " << arb2.Altura() << endl;
cout << "Nodos: " << arb2.Nodos() << endl;
cout << "NodosHoja: " << arb2.NodosHoja() << endl;
}
{
  TAVLPoro arb1;


TPoro c1(1,1,1,(char *)"rojo");
TPoro c2(2,2,2,(char *)"rojo");
TPoro c3(3,3,3,(char *)"rojo");
TPoro c4(4,4,4,(char *)"rojo");
TPoro c5(5,5,5,(char *)"rojo");
TPoro c6(6,6,6,(char *)"rojo");
TPoro otro(10,10,10,(char *)"rojo");


arb1.Insertar(c5);
arb1.Insertar(c2);
arb1.Insertar(c3);
arb1.Insertar(c1);
arb1.Insertar(c6);

if(arb1.Buscar(otro))
  cout << "Encontrado" << endl;
else
  cout << "No encontrado" << endl;

if(arb1.Buscar(c1))
  cout << "Encontrado" << endl;
else
  cout << "No encontrado" << endl;
}
{
  TAVLPoro arb1;

TPoro c1(1,1,1,(char *)"rojo");
TPoro c2(2,2,2,(char *)"rojo");
TPoro c3(3,3,3,(char *)"rojo");
TPoro c4(4,4,4,(char *)"rojo");
TPoro c5(5,5,5,(char *)"rojo");
TPoro c6(6,6,6,(char *)"rojo");

arb1.Insertar(c5);
arb1.Insertar(c2);
arb1.Insertar(c1);
arb1.Insertar(c3);
arb1.Insertar(c6);

cout << arb1.Raiz()<<endl;

cout<<arb1<<endl;
}
{
  TAVLPoro arb1;
TVectorPoro vec;

TPoro p1(1,2,1,(char *) "rojo");

if (arb1.EsVacio())
cout<<"Arbol vacio"<<endl;
else cout<<"Arbol no vacio"<<endl;

if (arb1.Borrar(p1))
  cout<<"Elemento borrado"<<endl;
else cout<<"Elemento no borrado"<<endl;

arb1.Insertar(p1);

if (arb1.EsVacio())
cout<<"Arbol vacio"<<endl;
else cout<<"Arbol no vacio"<<endl;

if (arb1.Borrar(p1))
  cout<<"Elemento borrado"<<endl;
else cout<<"Elemento no borrado"<<endl;

if (arb1.EsVacio())
cout<<"Arbol vacio"<<endl;
else cout<<"Arbol no vacio"<<endl;
}
{
  TAVLPoro arb1, arb2;
TVectorPoro vec, vec2;

TPoro p1(1,2,1,(char *) "rojo");
TPoro p2(1,2,2,(char *) "rojo");
TPoro p3(1,2,3,(char *) "rojo");
TPoro p4(1,2,4,(char *) "rojo");
TPoro p5(1,2,5,(char *) "rojo");
TPoro p6(1,2,6,(char *) "rojo");

arb1.Insertar(p5);
arb1.Insertar(p2);
arb1.Insertar(p1);
arb1.Insertar(p3);
arb1.Insertar(p6);
cout<<arb1.Preorden()<<endl;
if (arb1.Borrar(p4))
  cout<<"Elemento borrado"<<endl;
else cout<<"Elemento no borrado"<<endl;

if (arb1.Borrar(p1))
  cout<<"Elemento borrado"<<endl;
else cout<<"Elemento no borrado"<<endl;

cout<<arb1.Raiz()<<endl;
cout<<arb1.Preorden()<<endl;
cout<<arb1.Inorden()<<endl;
cout<<arb1.Postorden()<<endl;
}
{
  TAVLPoro arb1, arb2;
TVectorPoro vec, vec2;

TPoro p1(1,2,1,(char *) "rojo");
TPoro p2(1,2,2,(char *) "rojo");
TPoro p3(1,2,3,(char *) "rojo");
TPoro p4(1,2,4,(char *) "rojo");
TPoro p5(1,2,5,(char *) "rojo");
TPoro p6(1,2,6,(char *) "rojo");

arb1.Insertar(p6);
arb1.Insertar(p4);
arb1.Insertar(p2);
arb1.Insertar(p1);
arb1.Insertar(p3);
cout<<arb1.Preorden()<<endl;
if (arb1.Borrar(p5))
  cout<<"Elemento borrado"<<endl;
else cout<<"Elemento no borrado"<<endl;

if (arb1.Borrar(p6))
  cout<<"Elemento borrado"<<endl;
else cout<<"Elemento no borrado"<<endl;

cout<<arb1.Raiz()<<endl;
cout<<arb1.Preorden()<<endl;
cout<<arb1.Inorden()<<endl;
cout<<arb1.Postorden()<<endl;
}
}
