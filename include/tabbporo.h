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
	friend ostream & operator<<(ostream &, const TABBPoro &);
private:
	// Puntero al nodo
	TNodoABB *nodo;
	TPoro error;
	// AUXILIAR : Devuelve el recorrido en inorden
	void InordenAux(TVectorPoro &, int &) const;
	// AUXILIAR : Devuelve el recorrido en preorden
	void PreordenAux(TVectorPoro &, int &) const;
	// AUXILIAR : Devuelve el recorrido en postorden
	void PostordenAux(TVectorPoro &, int &) const;
	void NivelesAux(TVectorPoro &, int &) const;
	//Comprueba que no haya nodos con el mismo volument en el arbol
	bool FiltraVolumen(const int &);
	//Busca e inserta un nodo en un árbol
	void BuscaInserta(TNodoABB *);
	//Auxiliar para calcular el numero de nodos
	int NodosAux(int ) const;
	//Auxiliar para buscar un poro en el árbol
	bool BuscarAux(const TPoro &) const;
	//Auxiliar para copiar el árbol
	void Copiar(const TABBPoro &);
	//Auxiliar para comprobar si dos árboles son iguales
	bool CompruebaNodos(const TABBPoro &) const;
	//Comprueba si un nodo es un nodo hoja
	bool EsHoja() const;
	//Busca el mayor nodo hijo de la izquierda y lo sustituye por el nodo a borrar
	void SustituyeMayorIzq();
	//Sustituye un nodo por su hijo para borrar
	void SustituyePorHijo();
public:
	// Constructor por defecto
	TABBPoro();
	// Constructor de copia
	TABBPoro(const TABBPoro &);
	// Destructor
	~TABBPoro();
	// Sobrecarga del operador asignación
	TABBPoro & operator=(const TABBPoro &);

	// Sobrecarga del operador igualdad
	bool operator==(const TABBPoro &) const;
	// Devuelve TRUE si el árbol está vacío, FALSE en caso contrario
	bool EsVacio() const;
	// Inserta el elemento en el árbol
	bool Insertar(const TPoro &);
	// Borra el elemento en el árbol
	bool Borrar(const TPoro &);
	// Devuelve TRUE si el elemento está en el árbol, FALSE en caso contrario
	bool Buscar(const TPoro &) const;
	// Devuelve el elemento en la raíz del árbol
	TPoro Raiz() const;
	// Devuelve la altura del árbol (la altura de un árbol vacío es 0)
	int Altura() const;
	// Devuelve el número de nodos del árbol (un árbol vacío posee 0 nodos)
	int Nodos() const;
	// Devuelve el número de nodos hoja en el árbol (la raíz puede ser nodo hoja)
	int NodosHoja() const;
	// Devuelve el recorrido en inorden
	TVectorPoro Inorden() const;
	// Devuelve el recorrido en preorden
	TVectorPoro Preorden() const;
	// Devuelve el recorrido en postorden
	TVectorPoro Postorden() const;
	// Devuelve el recorrido en niveles
	TVectorPoro Niveles() const;
	// Suma de dos ABB
	TABBPoro operator+(const TABBPoro
	&);
	// Resta de dos ABB
	TABBPoro operator-(const TABBPoro
	&);
};

class TNodoABB {
	friend class TABBPoro;
private:
	// El elemento del nodo
	TPoro item;
	// Subárbol izquierdo y derecho
	TABBPoro iz, de;
	void Copia(const TNodoABB &);
public:
	// Constructor por defecto
	TNodoABB ();
	// Constructor de copia
	TNodoABB (const TNodoABB &);
	// Destructor
	~ TNodoABB ();
	// Sobrecarga del operador asignación
	TNodoABB & operator=(const TNodoABB &);
};
#endif /* INCLUDE_TABBPORO_H_ */
