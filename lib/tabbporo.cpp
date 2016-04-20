/*
 * tabbporo.cpp
 *
 *  Created on: Apr 5, 2016
 *      Author: jorge
 */

#include "../include/tabbporo.h"

TNodoABB::TNodoABB():iz(), de() {}

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
void TABBPoro::InordenAux(TVectorPoro&, int&) {
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

bool TABBPoro::FiltraVolumen(int volumen) {
	return true;
}

void TABBPoro::BuscaInserta(TNodoABB &nuevo){
	//Comprobar recursivamente que sea menor o mayor que el elemento nodo de la raiz e introducir donde quepa
	if(nuevo.item.Volumen() < nodo->item.Volumen())
	{

	}
}

bool TABBPoro::Insertar(const TPoro &poro) {
	if(FiltraVolumen(poro.Volumen()))
	{
		//se crea el nodo a insertar
		TNodoABB *aux = new TNodoABB();
		aux->item = poro;
		//se busca e inserta el nodo
		if(EsVacio())
			nodo = aux;
		else
			BuscaInserta(*aux);

		return true;
	}
	return false;
}

bool TABBPoro::Borrar(TPoro&) {
}

bool TABBPoro::Buscar(TPoro&) {
}

TPoro TABBPoro::Raiz() {
}

int TABBPoro::Altura() {
}

int TABBPoro::Nodos() {
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
