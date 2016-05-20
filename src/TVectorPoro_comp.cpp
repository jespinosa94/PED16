#include <iostream>

using namespace std;

#include "../include/tporo.h"
#include "../include/tvectorporo.h"

int
main(void)
{
	{
	  TPoro a, b, c;
	  TVectorPoro d, e, f;

	  cout << "No hace nada" << endl;
	}
	{
	  TPoro auxOK;
	  TVectorPoro a, b(5), c(10);

	  cout << a.Longitud() << endl;
	  cout << b.Longitud() << endl;
	  cout << c.Longitud() << endl;
	}
	{
	  TVectorPoro a;

	  cout << a << endl;
	}
	{
	  TVectorPoro a(5);
	  TVectorPoro b;

	  if(a == b)
	    cout << "SI"  << endl;
	  else
	    cout << "NO" << endl;
	}
	{
	  TPoro a(1, 2, 3, "rojo");
	  TVectorPoro v(5);

	  v[1] = a;
	  v[2] = a;
	  v[3] = a;
	  v[4] = a;
	  v[5] = a;

	  cout << v << endl;
	}
	{
	  TPoro a(1, 2, 3, "rojo");
	  TVectorPoro v(5), w;

	  v[1] = a;
	  v[2] = a;
	  v[3] = a;
	  v[4] = a;
	  v[5] = a;

	  w = v;

	  cout << v << endl;
	  cout << w << endl;
	}
	{
	  TPoro a(1, 2, 3, "rojo");
	  TVectorPoro v(5);

	  cout << "Cantidad: " << v.Cantidad() << endl;

	  v[1] = a;
	  cout << "Cantidad: " << v.Cantidad() << endl;

	  v[2] = a;
	  cout << "Cantidad: " << v.Cantidad() << endl;

	  v[3] = a;
	  cout << "Cantidad: " << v.Cantidad() << endl;

	  v[4] = a;
	  cout << "Cantidad: " << v.Cantidad() << endl;

	  v[5] = a;
	  cout << "Cantidad: " << v.Cantidad() << endl;
	}
	{
	  TPoro a(1, 2, 3, "rojo");
	  TVectorPoro v(5), w;

	  cout << "Longitud: " << v.Longitud() << endl;
	  cout << "Longitud: " << w.Longitud() << endl;

	  w = v;

	  cout << "Longitud: " << v.Longitud() << endl;
	  cout << "Longitud: " << w.Longitud() << endl;
	}
	{
	  TPoro a(1, 2, 3, "rojo");
	  TVectorPoro v(5), w;

	  v[1] = a;
	  v[2] = a;
	  v[3] = a;
	  v[4] = a;
	  v[5] = a;

	v.Redimensionar(-1);
	  cout << v << endl;
	}
	{
	  TPoro a(1, 2, 3, "rojo");
	  TVectorPoro v(5), w;

	  v[1] = a;
	  v[2] = a;
	  v[3] = a;
	  v[4] = a;
	  v[5] = a;

	v.Redimensionar(5);
	  cout << v << endl;
	}
	{
	  TPoro a(1, 2, 3, "rojo");
	  TVectorPoro v(5), w;

	  v[1] = a;
	  v[2] = a;
	  v[3] = a;
	  v[4] = a;
	  v[5] = a;

	v.Redimensionar(1);
	  cout << v << endl;
	}
}
