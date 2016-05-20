#include <iostream>

using namespace std;

#include "../include/tporo.h"

int
main(void)
{
	{
	  TPoro a, b ;
	  TPoro c(a), d(b) ;
	  cout << a << endl;
	  cout << b << endl;
	  cout << c << endl;
	  cout << d << endl;

	}
	{
	  TPoro a(2, 2, 20);
	  TPoro b(2, 2, 20, NULL);

	  cout << a << endl;
	  cout << b << endl;
	}
	{
	  TPoro a(2, 2, 20,"rojo");
	  TPoro b(2, 2, 20,"RoJo");

	 if(a==b)
	    cout << "IGUALES" << endl;
	  else
	    cout << "DISTINTOS" << endl;

	}
	{

	  TPoro a(0, 0, 0);
	  TPoro a2(0, 0, 0, "");

	  TPoro b(0, 0, 0, "rojo");
	  TPoro b2(0, 0, 0, "Rojo");
	  TPoro b3(0, 0, 0, "RojO");

	  if(a == a2)
	    cout << "IGUALES" << endl;
	  else
	    cout << "DISTINTOS"  << endl;


	  if ((b == b2) && (b == b3))
	    cout << "IGUALES" << endl;
	  else
	    cout << "DISTINTOS"  << endl;
	}
	{
	  TPoro a(2,2,0,NULL);
	  TPoro b(2,2,20,"aZUL");

	  a.Volumen(20);
	  a.Color("Azul");

	  if(a!=b)
	    cout << "DISTINTOS" << endl;
	  else
	    cout << "IGUALES" << endl;
	}
	{
	  TPoro a(1,1,0,NULL);
	  TPoro b(2,2,20,"aZUL");

	  a.Posicion(2,2);
	  a.Volumen(20);
	  a.Color("Azul");

	  if(a!=b)
	    cout << "DISTINTOS" << endl;
	  else
	    cout << "IGUALES" << endl;
	}
	{
	  TPoro a(-10,-20,3,NULL);

	  cout << "PosicionX: " << a.PosicionX() << endl;
	  cout << "PosicionY: " << a.PosicionY() << endl;
	  cout << "Volumen: " << a.Volumen() << endl;
	  cout << a << endl;
	}
	{
	  TPoro a;
	  a.Color("");
	  TPoro b(0,0,0,"");
	  TPoro c(0,0,0,NULL);

	  if(a.EsVacio())
	    cout << "VACIO" << endl;
	  else
	    cout << "LLENO" << endl;
	  if(b.EsVacio())
	    cout << "VACIO" << endl;
	  else
	    cout << "LLENO" << endl;
	  if(c.EsVacio())
	    cout << "VACIO" << endl;
	  else
	    cout << "LLENO" << endl;

	}
	{
	  TPoro a;
	  TPoro b(0, 0, 0, NULL);

	  cout << a << endl;
	  cout << b << endl;
	}
	{
	  TPoro a;
	  TPoro b(0, 0, 0, NULL);

	  a.Posicion(0,0);
	  a.Volumen(0);
	  a.Color(NULL);

	 if(a==b)
	    cout << "IGUALES" << endl;
	  else
	    cout << "DISTINTOS" << endl;

	  a.Color("rojo");
	  b.Color("ROJO");

	 if(a==b)
	    cout << "IGUALES" << endl;
	  else
	    cout << "DISTINTOS" << endl;



	}
	{
	  TPoro a(2, 2, 20,"rojo");
	  TPoro b(2, 2, 20,"RoJo");
	  TPoro c(2, 2, 20,"");
	  TPoro d(2, 2, 20,NULL);

	  TPoro e(c);
	  TPoro f(d);

	 if(e==c)
	    cout << "IGUALES" << endl;
	  else
	    cout << "DISTINTOS" << endl;

	 if(f==d)
	    cout << "IGUALES" << endl;
	  else
	    cout << "DISTINTOS" << endl;

	}
	{
	  TPoro a(2, 2, 20,"rojo");
	  TPoro b(2, 2, 20,"RoJo");
	  TPoro c(2, 2, 20,"");
	  TPoro d(2, 2, 20,NULL);

	  a = c;
	  b = d;

	 if(a==c)
	    cout << "IGUALES" << endl;
	  else
	    cout << "DISTINTOS" << endl;

	 if(b==d)
	    cout << "IGUALES" << endl;
	  else
	    cout << "DISTINTOS" << endl;

	}
}
