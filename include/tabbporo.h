/*
 * tabbporo.h
 *
 *  Created on: Apr 5, 2016
 *      Author: jorge
 */
#include "tvectorporo.h"
class TNodoABB;

#ifndef INCLUDE_TABBPORO_H_
#define INCLUDE_TABBPORO_H_
class TABBPoro {
private:
	// Puntero al nodo
	TNodoABB *nodo;
	// AUXILIAR : Devuelve el recorrido en inorden
	void InordenAux(TVectorPoro &, int &);
	// AUXILIAR : Devuelve el recorrido en preorden
	void PreordenAux(TVectorPoro &, int &);
	// AUXILIAR : Devuelve el recorrido en postorden
	void PostordenAux(TVectorPoro &, int &);
public:
	// Constructor por defecto
	TABBPoro();
	// Constructor de copia
	TABBPoro(TABBPoro &);
	// Destructor
	~TABBPoro();
	// Sobrecarga del operador asignación
	TABBPoro & operator=(TABBPoro &);

	// Sobrecarga del operador igualdad
	bool operator==(TABBPoro &);
	// Devuelve TRUE si el árbol está vacío, FALSE en caso contrario
	bool EsVacio();
	// Inserta el elemento en el árbol
	bool Insertar(TPoro &);
	// Borra el elemento en el árbol
	bool Borrar(TPoro &);
	// Devuelve TRUE si el elemento está en el árbol, FALSE en caso contrario
	bool Buscar(TPoro &);
	// Devuelve el elemento en la raíz del árbol
	TPoro Raiz();
	// Devuelve la altura del árbol (la altura de un árbol vacío es 0)
	int Altura();
	// Devuelve el número de nodos del árbol (un árbol vacío posee 0 nodos)
	int Nodos();
	// Devuelve el número de nodos hoja en el árbol (la raíz puede ser nodo hoja)
	int NodosHoja();
	// Devuelve el recorrido en inorden
	TVectorPoro Inorden();
	// Devuelve el recorrido en preorden
	TVectorPoro Preorden();
	// Devuelve el recorrido en postorden
	TVectorPoro Postorden();
	// Devuelve el recorrido en niveles
	TVectorPoro Niveles();
	// Suma de dos ABB
	TABBPoro operator+( TABBPoro
	&);
	// Resta de dos ABB
	TABBPoro operator-( TABBPoro
	&);
	// Sobrecarga del operador salida
	friend ostream & operator<<(ostream &, TABBPoro &);
};

class TNodoABB {
private:
	// El elemento del nodo
	TPoro item;
	// Subárbol izquierdo y derecho
	TABBPoro iz, de;
public:
	// Constructor por defecto
	TNodoABB ();
	// Constructor de copia
	TNodoABB (TNodoABB &);
	// Destructor
	~ TNodoABB ();
	// Sobrecarga del operador asignación
	TNodoABB & operator=( TNodoABB &);
};
#endif /* INCLUDE_TABBPORO_H_ */
