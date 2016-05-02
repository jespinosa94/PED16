/*
 * tavlporo.h
 *
 *  Created on: May 2, 2016
 *      Author: jorge
 */
#include "tvectorporo.h"
#ifndef INCLUDE_TAVLPORO_H_
#define INCLUDE_TAVLPORO_H_
class TNodoAVL;

class TAVLPoro {
	friend class TNodoAVL;
	// Sobrecarga del operador salida
//	friend ostream & operator<<(ostream &, TAVLPoro &);
private:
	// Puntero al nodo raíz
	TNodoAVL *raiz;
	// Devuelve el recorrido en inorden
	void InordenAux(TVectorPoro &, int &);
	// Devuelve el recorrido en preorden
	void PreordenAux(TVectorPoro &, int &);
	// Devuelve el recorrido en postorden
	void PostordenAux(TVectorPoro &, int &);

public:
	//Constructor por defecto
	TAVLPoro ();
	//Constructor copia
	TAVLPoro (TAVLPoro &);
	//Destructor
	~ TAVLPoro ();
	// Sobrecarga del operador asignación
	TAVLPoro & operator=( TAVLPoro &);

	// Sobrecarga del operador igualdad
	bool operator==( TAVLPoro &);
	// Sobrecarga del operador desigualdad
	bool operator!=( TAVLPoro &);
	// Devuelve TRUE si el árbol está vacío, FALSE en caso contrario
	bool EsVacio();
	// Inserta el elemento en el árbol
	bool Insertar(TPoro &);
	// Devuelve true si el elemento está en el árbol, false en caso contrario
	bool Buscar(TPoro &);
	// Devuelve la altura del árbol (la altura de un árbol vacío es 0)
	int Altura();
	// Devuelve el número de nodos del árbol (un árbol vacío posee 0 nodos)
	int Nodos();
	// Devuelve el número de nodos hoja en el árbol (la raíz puede ser nodo hoja)
	int NodosHoja();
	// Devuelve el recorrido en inorden sobre un vector
	TVectorPoro Inorden();
	// Devuelve el recorrido en preorden sobre un vector
	TVectorPoro Preorden();
	// Devuelve el recorrido en postorden sobre un vector
	TVectorPoro Postorden();
	// Borra un TPoro del árbol AVL
	bool Borrar(TPoro &);
	// Devuelve el elemento TPoro raíz del árbol AVL
	TPoro Raiz();
};
class TNodoAVL {
private:
	// El elemento del nodo
	TPoro item;
	// Subárbol izquierdo y derecho
	TAVLPoro iz, de;
	// Factor de equilibrio
	int fe;
public:
	//Constructor por defecto
	TNodoAVL ();
	//Constructor copia
	TNodoAVL (TNodoAVL &);
	//Destructor
	~TNodoAVL ();
	// Sobrecarga del operador asignación
	TNodoAVL & operator=( TNodoAVL &);
};
#endif /* INCLUDE_TAVLPORO_H_ */
