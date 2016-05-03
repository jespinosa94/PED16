/*
 * tavlporo.cpp
 *
 *  Created on: May 2, 2016
 *      Author: jorge
 */

#include "../include/tavlporo.h"

TNodoAVL::TNodoAVL(): item(), iz(), de() {
	fe = 0;
}

TNodoAVL::TNodoAVL(TNodoAVL &origen) {
	Copiar(origen);
}

TNodoAVL::~TNodoAVL() {
	fe = 0;
}

TNodoAVL& TNodoAVL::operator =(TNodoAVL &origen) {
	if(this != &origen)
	{
		(*this).~TNodoAVL();
		Copiar(origen);
	}
	return *this;
}
void TNodoAVL::Copiar(const TNodoAVL &origen) {
	(this)->item = origen.item;
	if(!origen.de.EsVacio())
		(this)->de = origen.de;
	if(!origen.iz.EsVacio())
		(this)->iz = origen.iz;
	fe = origen.fe;
}

/*************************************************************************
 *************************************************************************
 *************************************************************************/

void TAVLPoro::InordenAux(TVectorPoro &vector, int &posicion) {
	if(!EsVacio())
	{
		raiz->iz.InordenAux(vector, posicion);
		vector[posicion] = raiz->item;
		posicion++;
		raiz->de.InordenAux(vector, posicion);
	}
}

void TAVLPoro::PreordenAux(TVectorPoro &vector, int &posicion) {
	if(!EsVacio())
	{
		vector[posicion] = raiz->item;
		posicion++;
		raiz->iz.PreordenAux(vector, posicion);
		raiz->de.PreordenAux(vector, posicion);
	}
}

void TAVLPoro::PostordenAux(TVectorPoro &vector, int &posicion) {
	if(!EsVacio())
	{
		raiz->iz.PostordenAux(vector, posicion);
		raiz->de.PostordenAux(vector, posicion);
		vector[posicion] = raiz->item;
		posicion++;
	}
}

TAVLPoro::TAVLPoro() {
	raiz = NULL;
}

TAVLPoro::TAVLPoro(TAVLPoro&) {
}

TAVLPoro::~TAVLPoro() {
}

TAVLPoro& TAVLPoro::operator =(const TAVLPoro&) {
}

bool TAVLPoro::operator ==(const TAVLPoro&) {
}

bool TAVLPoro::operator !=(const TAVLPoro&) {
}

bool TAVLPoro::EsVacio() const {
	return raiz==NULL;
}

bool TAVLPoro::FiltraVolumen(const int &volumen) {
	if(raiz->item.Volumen() == volumen)
		return false;
	else if(volumen < raiz->item.Volumen() && !raiz->iz.EsVacio())
		raiz->iz.FiltraVolumen(volumen);
	else if(volumen > raiz->item.Volumen() && !raiz->de.EsVacio())
		raiz->de.FiltraVolumen(volumen);
	else
		return true;
}

void TAVLPoro::BuscaInserta(TNodoAVL *nuevo){
	//Comprobar recursivamente que sea menor o mayor que el elemento nodo de la raiz e introducir donde quepa
	if(nuevo->item.Volumen() < raiz->item.Volumen())
	{
		//recursión hacia la izquierda del árbol
		if(!raiz->iz.EsVacio())
			raiz->iz.BuscaInserta(nuevo);
		else
			raiz->iz.raiz = nuevo;
	}
	else if(nuevo->item.Volumen() > raiz->item.Volumen())
	{
		//recursión hacia la derecha del árbol
		if(!raiz->de.EsVacio())
			raiz->de.BuscaInserta(nuevo);
		else
			raiz->de.raiz = nuevo;
	}
}

bool TAVLPoro::Insertar(const TPoro &poro) {
	TNodoAVL *nuevo = new TNodoAVL();
	nuevo->item = poro;
	if(EsVacio())
	{
		raiz = nuevo;
		return true;
	}
	else if(FiltraVolumen(poro.Volumen()))
	{
		//Insertar donde toque
		BuscaInserta(nuevo);
		//Calcular el factor de equilibrio de todo el arbol
		//Reordenar
		return true;
	}
	return false;
}

bool TAVLPoro::BuscarAux(const TPoro &poro) const
{
	if(raiz->item == poro)
		return true;
	else if(poro.Volumen() < raiz->item.Volumen() && !raiz->iz.EsVacio())
		raiz->iz.Buscar(poro);
	else if(poro.Volumen() > raiz->item.Volumen() && !raiz->de.EsVacio())
		raiz->de.Buscar(poro);
	else
		return false;
}

bool TAVLPoro::Buscar(const TPoro &poro) const {
	if(EsVacio())
		return false;
	else
		return BuscarAux(poro);
}

int TAVLPoro::Altura() const{
	int a1, a2;
	if(!EsVacio())
	{
		a1 = raiz->iz.Altura();
		a2 = raiz->de.Altura();
		return (1 + (a1<a2 ? a2:a1));
	}
	else return 0;
}

int TAVLPoro::NodosAux(int total) const {
	if(!EsVacio())
	{
		total = 1 + raiz->iz.NodosAux(total) + raiz->de.NodosAux(total);
	}
	return total;
}

int TAVLPoro::Nodos() const {
	return NodosAux(0);
}

int TAVLPoro::NodosHoja() const{
}

TVectorPoro TAVLPoro::Inorden() {
	//Posición en el vector que almacena el recorrido
	int posicion = 1;
	//Vector del tamaño adecuado para almacenar todos los nodos
	TVectorPoro v(Nodos());
	InordenAux(v, posicion);
	return v;
}

TVectorPoro TAVLPoro::Preorden() {
	//Posición en el vector que almacena el recorrido
	int posicion = 1;
	//Vector del tamaño adecuado para almacenar todos los nodos
	TVectorPoro v(Nodos());
	PreordenAux(v, posicion);
	return v;
}

TVectorPoro TAVLPoro::Postorden() {
	//Posición en el vector que almacena el recorrido
	int posicion = 1;
	//Vector del tamaño adecuado para almacenar todos los nodos
	TVectorPoro v(Nodos());
	PostordenAux(v, posicion);
	return v;
}

bool TAVLPoro::Borrar(const TPoro&) {
}

TPoro TAVLPoro::Raiz() {
}

ostream & operator<<(ostream &os, TAVLPoro &avl) {
	os << avl.Inorden();
	return os;
}

