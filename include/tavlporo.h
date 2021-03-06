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
	friend ostream & operator<<(ostream &, const TAVLPoro &);
private:
	// Puntero al nodo raíz
	TNodoAVL *raiz;
	TPoro error;
	// Devuelve el recorrido en inorden
	void InordenAux(TVectorPoro &, int &) const;
	// Devuelve el recorrido en preorden
	void PreordenAux(TVectorPoro &, int &) const;
	// Devuelve el recorrido en postorden
	void PostordenAux(TVectorPoro &, int &) const;
	//Comprueba que no haya nodos con el mismo volumen
	bool FiltraVolumen(const int &);
	//Busca la posición en la que debe ir el nuevo elemento y lo inserta
	void BuscaInserta(TNodoAVL *);
	//Auxiliar para calcular el numero de nodos con recursión por la cola
	int NodosAux(int total) const;
	//Auxiliar para buscar un poro en el árbol AVL mediante recursión por la cola
	bool BuscarAux(const TPoro &poro) const;
	//Calcula el factor de equilibrio de cada nodo y reordena el arbol
    void Reordenar();
    //Auxiliar que copia todos los elementos de un arbol en otro
    void Copiar(const TAVLPoro &origen);
    //Rotación DD de un árbol (+2, +1)
    void RotaDD();
    //Rotación II de un árbol (-2, -1)
    void RotaII();
    //Rotación ID de un árbol (-2, +1)
    void RotaID();
    //Rotación DI de un árbol (+2, -1)
    void RotaDI();
    //Auxiliar que busca los nodos de un arbol en otro
    bool CompruebaNodos(const TAVLPoro &otroArbol) const;
    //Borrado del árbol binario de búsqueda
    bool BorrarAB(const TPoro &poro);
    bool EsHoja() const;
    void SustituyePorHijo();
    void SustituyeMayorIzq();

public:
	//Constructor por defecto
	TAVLPoro ();
	//Constructor copia
	TAVLPoro (const TAVLPoro &);
	//Destructor
	~ TAVLPoro ();
	// Sobrecarga del operador asignación
	TAVLPoro & operator=(const TAVLPoro &);

	// Sobrecarga del operador igualdad
	bool operator==(const TAVLPoro &) const;
	// Sobrecarga del operador desigualdad
	bool operator!=(const TAVLPoro &) const;
	// Devuelve TRUE si el árbol está vacío, FALSE en caso contrario
	bool EsVacio() const;
	// Inserta el elemento en el árbol
	bool Insertar(const TPoro &);
	// Devuelve true si el elemento está en el árbol, false en caso contrario
	bool Buscar(const TPoro &) const;
	// Devuelve la altura del árbol (la altura de un árbol vacío es 0)
	int Altura() const;
	// Devuelve el número de nodos del árbol (un árbol vacío posee 0 nodos)
	int Nodos() const;
	// Devuelve el número de nodos hoja en el árbol (la raíz puede ser nodo hoja)
	int NodosHoja() const;
	// Devuelve el recorrido en inorden sobre un vector
	TVectorPoro Inorden() const;
	// Devuelve el recorrido en preorden sobre un vector
	TVectorPoro Preorden() const;
	// Devuelve el recorrido en postorden sobre un vector
	TVectorPoro Postorden() const;
	// Borra un TPoro del árbol AVL
	bool Borrar(const TPoro &);
	// Devuelve el elemento TPoro raíz del árbol AVL
	TPoro Raiz() const;
};
class TNodoAVL {
	friend class TAVLPoro;
private:
	// El elemento del nodo
	TPoro item;
	// Subárbol izquierdo y derecho
	TAVLPoro iz, de;
	// Factor de equilibrio
	int fe;
	//Módulo auxiliar para copiar los atributos del nodo
	void CopiarNodo(const TNodoAVL &);
public:
	//Constructor por defecto
	TNodoAVL ();
	//Constructor copia
	TNodoAVL (const TNodoAVL &);
	//Destructor
	~TNodoAVL ();
	// Sobrecarga del operador asignación
	TNodoAVL & operator=(const TNodoAVL &);
};
#endif /* INCLUDE_TAVLPORO_H_ */
