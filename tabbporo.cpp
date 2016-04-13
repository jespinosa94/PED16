/*
 * tabbporo.cpp
 *
 *  Created on: Apr 5, 2016
 *      Author: jorge
 */

#include "../include/tabbporo.h"

TNodoABB::TNodoABB():iz(), de() {}

TNodoABB::TNodoABB(TNodoABB &origen){

}

TNodoABB::~TNodoABB() {}

TNodoABB& TNodoABB::operator =(TNodoABB &origen) {
	if(this != &origen)
	{
		(this)->~TNodoABB();

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

TABBPoro& TABBPoro::operator =(TABBPoro&) {
}

bool TABBPoro::operator ==(TABBPoro&) {
}

bool TABBPoro::EsVacio() {
}

bool TABBPoro::BarreVolumen(int volumen) {

}

bool TABBPoro::Insertar(TPoro &poro) {
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
