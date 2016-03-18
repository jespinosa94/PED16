#include <iostream>

using namespace std;

#include "../include/tlistaporo.h"

int
main(void)
{
  {
    TPoro a, b, c;
    TListaPoro d, e, f;

    cout << "No hace nada" << endl;
  }
  {
    TPoro p(1, 1, 1), q(2, 2, 2), r(3, 3, 3);
    TListaPoro a, b, c;

    cout << a.Longitud() << endl;
    cout << b.Longitud() << endl;
    cout << c.Longitud() << endl;

    a.Insertar(p);
    b.Insertar(p); b.Insertar(q);
    c.Insertar(p); c.Insertar(q); c.Insertar(r);

    cout << a.Longitud() << endl;
    cout << b.Longitud() << endl;
    cout << c.Longitud() << endl;
  }
  {
    TListaPoro a;

    cout << a << endl;
  }
  {
    TPoro p(1, 2, 3);
    TListaPoro a, b;

    if(a == b)
      cout << "SI"  << endl;
    else
      cout << "NO" << endl;

    a.Insertar(p);

    if(a == b)
      cout << "SI"  << endl;
    else
      cout << "NO" << endl;
  }
  {
    TPoro p(1, 1, 1), q(2, 2, 2), r(3, 3, 3);
    TListaPoro a;

    a.Insertar(p); a.Insertar(q); a.Insertar(r);

    cout << a << endl;
  }
  {
    TPoro p(1, 2, 3, (char*)"rojo");
    TListaPoro a, b;

    a.Insertar(p);
    b = a;

    cout << a << endl;
    cout << b << endl;
  }
  {
    TPoro p(1, 2, 3, (char*)"rojo");
    TListaPoro a;

    cout << "Longitud: " << a.Longitud() << endl;

    a.Insertar(p);
    cout << "Longitud: " << a.Longitud() << endl;

    a.Insertar(p);
    cout << "Longitud: " << a.Longitud() << endl;

    a.~TListaPoro();
    cout << "Longitud: " << a.Longitud() << endl;
  }
  {
    TPoro p(1, 2, 3, (char*)"rojo");
    TListaPoro a, b;

    cout << "Longitud: " << a.Longitud() << endl;
    cout << "Longitud: " << b.Longitud() << endl;

    a.Insertar(p);
    b = a;

    cout << "Longitud: " << a.Longitud() << endl;
    cout << "Longitud: " << b.Longitud() << endl;
  }
  {
    TPoro p(1, 1, 1, (char*)"rojo"), q(2, 2, 2, (char*)"verde");
    TListaPoro a;

    a.Insertar(p);
    a.Insertar(q);
    cout << a << endl;

    a.Borrar(p);
    cout << a << endl;

    a.Borrar(q);
    cout << a << endl;
  }
  {
    TPoro p(1, 1, 1, (char*)"rojo"), q(2, 2, 2, (char*)"verde"), r(3, 3, 3, (char*)"amarillo");
    TListaPoro a;

    a.Insertar(p); a.Insertar(q);

    if(a.Buscar(p))
      cout << "SI" << endl;
    else
      cout << "NO" << endl;

    if(a.Buscar(q))
      cout << "SI" << endl;
    else
      cout << "NO" << endl;

    if(a.Buscar(r))
      cout << "SI" << endl;
    else
      cout << "NO" << endl;
  }
  {
    TPoro p(1, 1, 1, (char*)"rojo"), q(2, 2, 2, (char*)"verde"), r(3, 3, 3, (char*)"amarillo");
    TListaPoro a;
    TListaPosicion pos;

    a.Insertar(p); a.Insertar(q); a.Insertar(r);

    pos = a.Primera();

    while(!pos.EsVacia())
    {
      cout << a.Obtener(pos) << endl;
      pos = pos.Siguiente();
    }
  }
  {
    TPoro p(1, 1, 1, (char*)"rojo"), q(2, 2, 2, (char*)"verde"), r(3, 3, 3, (char*)"amarillo");
    TListaPoro a;
    TListaPosicion pos;

    a.Insertar(p); a.Insertar(q); a.Insertar(r);

    pos = a.Ultima();

    while(!pos.EsVacia())
    {
      cout << a.Obtener(pos) << endl;
      pos = pos.Anterior();
    }
}
}
