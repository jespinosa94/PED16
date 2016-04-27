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
	friend ostream & operator<<(ostream &, TABBPoro &);
private:
	// Puntero al nodo
	TNodoABB *nodo;
	TPoro error;
	// AUXILIAR : Devuelve el recorrido en inorden
	void InordenAux(TVectorPoro &, int &);
	// AUXILIAR : Devuelve el recorrido en preorden
	void PreordenAux(TVectorPoro &, int &);
	// AUXILIAR : Devuelve el recorrido en postorden
	void PostordenAux(TVectorPoro &, int &);
	void NivelesAux(TVectorPoro &, int &);
	//Comprueba que no haya nodos con el mismo volument en el arbol
	bool FiltraVolumen(const int &);
	//Busca e inserta un nodo en un árbol
	void BuscaInserta(TNodoABB *);
	//Auxiliar para calcular el numero de nodos
	int NodosAux(int ) const;
	//Auxiliar para buscar un poro en el árbol
	bool BuscarAux(const TPoro &);
	//Auxiliar para copiar el árbol
	void Copiar(const TABBPoro &);
	//Auxiliar para comprobar si dos árboles son iguales
	bool CompruebaNodos(const TABBPoro &, const TABBPoro &);
	//Comprueba si un nodo es un nodo hoja
	bool EsHoja() const;
	//Busca el mayor nodo hijo de la izquierda
	TNodoABB BuscaMayorIzq(const TABBPoro &);
public:
	// Constructor por defecto
	TABBPoro();
	// Constructor de copia
	TABBPoro(TABBPoro &);
	// Destructor
	~TABBPoro();
	// Sobrecarga del operador asignación
	TABBPoro & operator=(const TABBPoro &);

	// Sobrecarga del operador igualdad
	bool operator==(const TABBPoro &);
	// Devuelve TRUE si el árbol está vacío, FALSE en caso contrario
	bool EsVacio() const;
	// Inserta el elemento en el árbol
	bool Insertar(const TPoro &);
	// Borra el elemento en el árbol
	bool Borrar(TPoro &);
	// Devuelve TRUE si el elemento está en el árbol, FALSE en caso contrario
	bool Buscar(const TPoro &);
	// Devuelve el elemento en la raíz del árbol
	TPoro Raiz();
	// Devuelve la altura del árbol (la altura de un árbol vacío es 0)
	int Altura();
	// Devuelve el número de nodos del árbol (un árbol vacío posee 0 nodos)
	int Nodos() const;
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
	TNodoABB (TNodoABB &);
	// Destructor
	~ TNodoABB ();
	// Sobrecarga del operador asignación
	TNodoABB & operator=(const TNodoABB &);
};
#endif /* INCLUDE_TABBPORO_H_ */
