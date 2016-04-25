/*
 * tabbporo.cpp
 *
 *  Created on: Apr 5, 2016
 *      Author: jorge
 */

#include "../include/tabbporo.h"

TNodoABB::TNodoABB():iz(), de(), item() {}

TNodoABB::TNodoABB(TNodoABB &origen){
	Copia(origen);
}

TNodoABB::~TNodoABB() {} //Llama a los destructores de cada tipo de dato automáticamente

void TNodoABB::Copia(const TNodoABB &origen){
	(this)->item = origen.item;
	if(!origen.de.EsVacio())
		(this)->de = origen.de;
	if(!origen.iz.EsVacio())
		(this)->iz = origen.iz;
}
TNodoABB& TNodoABB::operator =(const TNodoABB &origen) {
	if(this != &origen)
	{
		(this)->~TNodoABB();
		Copia(origen);
	}
	return *this;
}

/*
 * ****************************************************************************
 */
void TABBPoro::InordenAux(TVectorPoro &vector, int &posicion) {

}

void TABBPoro::PreordenAux(TVectorPoro&, int&) {
}

void TABBPoro::PostordenAux(TVectorPoro&, int&) {
}

TABBPoro::TABBPoro() {
	nodo = NULL;
}

TABBPoro::TABBPoro(TABBPoro &) {
}

TABBPoro::~TABBPoro() {
}

TABBPoro& TABBPoro::operator =(const TABBPoro &origen) {
}

bool TABBPoro::operator ==(TABBPoro&) {
}

bool TABBPoro::EsVacio() const{
	return nodo == NULL;
}

bool TABBPoro::FiltraVolumen(const int &volumen) {
	if(nodo->item.Volumen() == volumen)
		return false;
	else if(volumen < nodo->item.Volumen() && !nodo->iz.EsVacio())
		nodo->iz.FiltraVolumen(volumen);
	else if(volumen > nodo->item.Volumen() && !nodo->de.EsVacio())
		nodo->de.FiltraVolumen(volumen);
	else
		return true;
}

void TABBPoro::BuscaInserta(TNodoABB *nuevo){
	//Comprobar recursivamente que sea menor o mayor que el elemento nodo de la raiz e introducir donde quepa
	if(nuevo->item.Volumen() < nodo->item.Volumen())
	{
		//recursión hacia la izquierda del árbol
		if(!nodo->iz.EsVacio())
			nodo->iz.BuscaInserta(nuevo);
		else
			nodo->iz.nodo = nuevo;
	}
	else if(nuevo->item.Volumen() > nodo->item.Volumen())
	{
		//recursión hacia la derecha del árbol
		if(!nodo->de.EsVacio())
			nodo->de.BuscaInserta(nuevo);
		else
			nodo->de.nodo = nuevo;
	}
}

bool TABBPoro::Insertar(const TPoro &poro) {
	//se crea el nodo a insertar
	TNodoABB *aux = new TNodoABB;;
	aux->item = poro;
	if(EsVacio())
	{
		nodo = aux;
		return true;
	}
	else if(FiltraVolumen(poro.Volumen()))
	{
		BuscaInserta(aux);
		return true;
	}
//	if(FiltraVolumen(poro.Volumen()))
//	{
//		//se crea el nodo a insertar
//		TNodoABB *aux = new TNodoABB;;
//		aux->item = poro;
//		//se busca e inserta el nodo
//		if(EsVacio())
//			nodo = aux;
//		else
//			BuscaInserta(aux);
//
//		return true;
//	}
	return false;
}

bool TABBPoro::Borrar(TPoro&) {
}

bool TABBPoro::Buscar(const TPoro &poro) {
	if(EsVacio())
		return false;
	else
		return BuscarAux(poro);
}

bool TABBPoro::BuscarAux(const TPoro &poro)
{
	if(nodo->item == poro)
		return true;
	else if(poro.Volumen() < nodo->item.Volumen() && !nodo->iz.EsVacio())
		nodo->iz.Buscar(poro);
	else if(poro.Volumen() > nodo->item.Volumen() && !nodo->de.EsVacio())
		nodo->de.Buscar(poro);
	else
		return false;
}

TPoro TABBPoro::Raiz() {
}

int TABBPoro::Altura() {
}

int TABBPoro::Nodos() {
	return NodosAux(0);
}
int TABBPoro::NodosAux(int total)
{
	if(!EsVacio())
	{
		total = 1 + nodo->iz.NodosAux(total) + nodo->de.NodosAux(total);
	}
	return total;
}

int TABBPoro::NodosHoja() {
}

TVectorPoro TABBPoro::Inorden() {
	//Posición en el vector que almacena el recorrido
	int posicion = 1;
	//Vector del tamaño adecuado para almacenar todos los nodos
	TVectorPoro v(Nodos());
	InordenAux(v, posicion);
	return v;
}

TVectorPoro TABBPoro::Preorden() {
	//Posición en el vector que almacena el recorrido
	int posicion = 1;
	//Vector del tamaño adecuado para almacenar todos los nodos
	TVectorPoro v(Nodos());
	PreordenAux(v, posicion);
	return v;
}

TVectorPoro TABBPoro::Postorden() {
	//Posición en el vector que almacena el recorrido
	int posicion = 1;
	//Vector del tamaño adecuado para almacenar todos los nodos
	TVectorPoro v(Nodos());
	PostordenAux(v, posicion);
	return v;
}

TVectorPoro TABBPoro::Niveles() {
}

TABBPoro TABBPoro::operator +(TABBPoro&) {
}

TABBPoro TABBPoro::operator -(TABBPoro&) {
}
