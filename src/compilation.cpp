#include <iostream>

using namespace std;

#include "TPoro.h"

int
main(void)
{
{
  TPoro a, b, c;

  cout << "No hace nada" << endl;
}
{
  TPoro a;

  cout << a << endl;
}
{
  TPoro a(1, 2, 3, "rojo");

  cout << a << endl;
}
{
  TPoro a;

  a.Posicion(10, 20);

  cout << a << endl;
}
{
  TPoro a(1, 2, 3, "rojo");
  TPoro b;

  b = a;

  cout << a << endl;
  cout << b << endl;
}
{
  TPoro a(1, 2, 3, "rojo");

  cout << "PosicionX: " << a.PosicionX() << endl;
  cout << "PosicionY: " << a.PosicionY() << endl;
  cout << "Volumen: " << a.Volumen() << endl;
}
{
  TPoro a(1, 2, 3, "rojo");

  if(a.PosicionX() == 1)
    cout << "SI" << endl;
  else
    cout << "NO" << endl;

  if(a.PosicionY() == 2)
    cout << "SI" << endl;
  else
    cout << "NO" << endl;
}
{
  TPoro a;

  if(a.EsVacio())
    cout << "VACIO" << endl;
  else
    cout << "NO VACIO" << endl;

  a.Color("rojo");

  if(a.EsVacio())
    cout << "VACIO" << endl;
  else
    cout << "NO VACIO" << endl;
}
{
  TPoro a;

  if(a.EsVacio())
    cout << "VACIO" << endl;
  else
    cout << "NO VACIO" << endl;

  a.Color("rojo");

  if(a.EsVacio())
    cout << "VACIO" << endl;
  else
    cout << "NO VACIO" << endl;

  a.~TPoro();

  if(a.EsVacio())
    cout << "VACIO" << endl;
  else
    cout << "NO VACIO" << endl;
}
{
  TPoro a, b(0, 0, 0, NULL);
  TPoro c(a), d(b);

  if(a.EsVacio())
    cout << "VACIO" << endl;
  else
    cout << "NO VACIO" << endl;

  if(b.EsVacio())
    cout << "VACIO" << endl;
  else
    cout << "NO VACIO" << endl;

  if(c.EsVacio())
    cout << "VACIO" << endl;
  else
    cout << "NO VACIO" << endl;

  if(d.EsVacio())
    cout << "VACIO" << endl;
  else
    cout << "NO VACIO" << endl;
}
}
