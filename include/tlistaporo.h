/*
 * tlistaporo.h
 *
 *  Created on: Mar 1, 2016
 *      Author: jorge
 */
#include "../include/tporo.h"
#include "../include/tvectorporo.h"
#ifndef INCLUDE_TLISTAPORO_H_
#define INCLUDE_TLISTAPORO_H_
class TListaNodo {
	friend class TListaPosicion;
private:
	// El elemento del nodo
	TPoro e;
	// El nodo anterior
	TListaNodo *anterior;
	// El nodo siguiente
	TListaNodo *siguiente;

public:
	// Constructor por defecto
	TListaNodo ();
	// Constructor de copia
	TListaNodo (const TListaNodo &);
	// Destructor
	~TListaNodo ();
	// Sobrecarga del operador asignación
	TListaNodo & operator=(const TListaNodo &);
};

class TListaPosicion {
private:
	// Para implementar la POSICIÓN a NODO de la LISTA de TPoro
	TListaNodo *pos;
public:
	// Constructor por defecto
	TListaPosicion ();
	// Constructor de copia
	TListaPosicion (const TListaPosicion &);
	// Destructor
	~TListaPosicion ();
	// Sobrecarga del operador asignación
	TListaPosicion& operator=(const TListaPosicion &);

	// Sobrecarga del operador igualdad
	bool operator==(const TListaPosicion &) const;
	// Devuelve la posición anterior
	TListaPosicion Anterior();
	// Devuelve la posición siguiente
	TListaPosicion Siguiente();
	// Devuelve TRUE si la posición no apunta a una lista, FALSE en caso contrario
	bool EsVacia() const;
};
class TListaPoro {
private:
	// Primer elemento de la lista
	TListaNodo *primero;
	// Ultimo elemento de la lista
	TListaNodo *ultimo;
public:
	// Constructor por defecto
	TListaPoro();
	// Constructor de copia
	TListaPoro (TListaPoro &);
	// Destructor
	~TListaPoro ();
	// Sobrecarga del operador asignación
	TListaPoro & operator=(const TListaPoro &);

	// Sobrecarga del operador igualdad
	bool operator==(const TListaPoro &) const;
	// Sobrecarga del operador suma
	TListaPoro operator+(TListaPoro &);
	// Sobrecarga del operador resta
	TListaPoro operator-(TListaPoro &);
	// Devuelve true si la lista está vacía, false en caso contrario
	bool EsVacia() const;
	// Inserta el elemento en la lista
	bool Insertar(const TPoro &);
	// Busca y borra el elemento
	bool Borrar(TPoro &);
	// Borra el elemento que ocupa la posición indicada
	bool Borrar(TListaPosicion &);
	// Obtiene el elemento que ocupa la posición indicada
	TPoro Obtener(const TListaPosicion &);
	// Devuelve true si el elemento está en la lista, false en caso contrario
	bool Buscar(const TPoro &);
	// Devuelve la longitud de la lista
	int Longitud() const;
	// Devuelve la primera posición en la lista
	TListaPosicion Primera();
	// Devuelve la última posición en la lista
	TListaPosicion Ultima();
	// Extraer un rango de nodos de la lista
	TListaPoro ExtraerRango (int n1, int n2);
};

#endif /* INCLUDE_TLISTAPORO_H_ */
