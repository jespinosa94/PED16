/*
 * tlistaporo.cpp
 *
 *  Created on: Mar 1, 2016
 *      Author: jorge
 */

#include "../include/tlistaporo.h"

/***************************************************************************************************************
 ***************************************************TListaNodo**************************************************
 ****************************************************************************************************************/
TListaNodo::TListaNodo():e() {
	anterior = siguiente = NULL;
}

TListaNodo::TListaNodo(const TListaNodo &tln):e(tln.e) {
	anterior = siguiente = NULL;
}

TListaNodo::~TListaNodo() {
	e.~TPoro();
	if(anterior != NULL)
		anterior = NULL;
	if(siguiente != NULL)
		siguiente = NULL;
}

TListaNodo& TListaNodo::operator =(const TListaNodo &tln) {
	if(this != &tln)
	{
		e = tln.e;
		anterior->e = tln.anterior->e;
		siguiente->e = tln.siguiente->e;
	}
	return *this;
}

/***************************************************************************************************************
 ***************************************************TListaPosicion**********************************************
 ****************************************************************************************************************/
TListaPosicion::TListaPosicion() {
	pos = NULL;
}

TListaPosicion::TListaPosicion(const TListaPosicion &tlp) {
	if(tlp.pos != NULL)
		pos = tlp.pos;
	else
		pos = NULL;
}

TListaPosicion::~TListaPosicion() {
	if(pos!=NULL)
		pos = NULL;
}

TListaPosicion& TListaPosicion::operator =(const TListaPosicion &tlp) {
	if(this != &tlp)
	{
		if(tlp.pos != NULL)
			pos = tlp.pos;
	}
	return *this;
}

bool TListaPosicion::operator ==(const TListaPosicion &tlp) const {
	return pos == tlp.pos;
}

TListaPosicion TListaPosicion::Anterior(){
	TListaPosicion aux;
	if(pos->anterior != NULL)
		aux.pos = pos->anterior;

	return aux;
}

TListaPosicion TListaPosicion::Siguiente(){
	TListaPosicion aux;
	if(pos->siguiente != NULL)
		aux.pos = pos->siguiente;
	return aux;
}

bool TListaPosicion::EsVacia() const{
	return pos == NULL;
}

/***************************************************************************************************************
 ***************************************************TListaPoro**************************************************
 ****************************************************************************************************************/
TListaPoro::TListaPoro() {
	primero = ultimo = NULL;
}

TListaPoro::TListaPoro(const TListaPoro &poroLista) {

}

TListaPoro::~TListaPoro() {
//	TListaPosicion p, q;
//	q = Primera();
//	while(!q.EsVacia())
//	{
//		p = q;
//		q = q.Siguiente();
////		delete p.pos;
//	}
//	primero = NULL;
//	ultimo = NULL;
}

TListaPoro& TListaPoro::operator =(const TListaPoro&) {
}

bool TListaPoro::operator ==(const TListaPoro&) const{

}

TListaPoro TListaPoro::operator +(TListaPoro&) {
}

TListaPoro TListaPoro::operator -(TListaPoro&) {
}

bool TListaPoro::EsVacia() const{
	return primero==NULL && ultimo==NULL;
}

void TListaPoro::InsertaCabeza(const TPoro &poro) {
	TListaNodo *aux = new TListaNodo;
	aux->e = poro;
	if(EsVacia())
	{
		aux->siguiente = NULL;
		primero = aux;
		ultimo = aux;
//		primero->siguiente = ultimo;
//		ultimo->anterior = primero;
	}
	else
	{
		aux->siguiente = primero;
		primero->anterior = aux;
		primero = aux;
	}
}

void TListaPoro::InsertaCola(const TPoro &poro) {
	TListaNodo *aux = new TListaNodo;
	aux->e = poro;
	aux->anterior = ultimo;
	ultimo->siguiente = aux;
	ultimo = aux;
}

TListaPosicion TListaPoro::ObtenerAnterior(const TPoro &poro) {
	TListaPosicion aux = Primera();
	while(!aux.Siguiente().EsVacia())
	{
		if(aux.pos->siguiente->e.Volumen() >= poro.Volumen())
			return aux;
		else
			aux = aux.Siguiente();
	}
	return aux;
}

void TListaPoro::InsertaCentro(const TPoro &poro) {
	TListaPosicion poroAnterior = ObtenerAnterior(poro);
	TListaNodo *newPoro = new TListaNodo;
	newPoro->e = poro;
	newPoro->siguiente = poroAnterior.pos->siguiente;
	poroAnterior.Siguiente().pos->anterior = newPoro;
	poroAnterior.pos->siguiente = newPoro;
	newPoro->anterior = poroAnterior.pos;

}

bool TListaPoro::Insertar(const TPoro &poro) {
	TListaNodo *nuevoPoro;

	if(EsVacia())
	{
		/*
		 * Voy a suponer que ultimo y primero se enlazarán para que borrar funcione
		 */
		InsertaCabeza(poro);
		return true;
	}
	else if(!Buscar(poro))
	{
		if(poro.Volumen() < primero->e.Volumen())
			InsertaCabeza(poro);
		else if(poro.Volumen() > ultimo->e.Volumen())
			InsertaCola(poro);
		else
			InsertaCentro(poro);
		return true;
	}
	return false;
}

TListaPosicion TListaPoro::ObtenerPosicion(TPoro &poro)
{
	TListaPosicion aux = Primera();
	while(!aux.Siguiente().EsVacia())
	{
		if(aux.pos->e == poro)
			return aux;
		else
			aux = aux.Siguiente();
	}
	return aux;
}

/*
 * Se guarda en una posicion el primer nodo para despues de la asignación no perderlo y borrarlo
 */
void TListaPoro::BorrarCabeza(TListaPosicion &aux) {
	primero = primero->siguiente;
	aux.pos->~TListaNodo();
	delete aux.pos;
}

void TListaPoro::BorrarCentro(TListaPosicion &borraPos) {
	//La declaración de abajo es simplemente para simplificar que si a b c (queremos borrar b
	//a sería anterior y c siguiente)
	TListaNodo *anterior = borraPos.Anterior().pos;
	TListaNodo *siguiente = borraPos.Siguiente().pos;
	anterior->siguiente = siguiente;
	siguiente->anterior = anterior;
	borraPos.pos->~TListaNodo();
	delete borraPos.pos;
}

void TListaPoro::BorrarCola(TListaPosicion &aux) {
	ultimo = ultimo->anterior;
	aux.pos->~TListaNodo();
	delete aux.pos;
}

bool TListaPoro::Borrar(TPoro &poro) {
	if(Buscar(poro))
	{
		TListaPosicion borraPos = ObtenerPosicion(poro);
		Borrar(borraPos);
		return true;
	}
	return false;
}

bool TListaPoro::Borrar(TListaPosicion &borraPos) {
	if(Buscar(borraPos.pos->e))
	{
		if(borraPos.pos == primero)
			BorrarCabeza(borraPos);
		else if(borraPos.pos == ultimo)
			BorrarCola(borraPos);
		else
			BorrarCentro(borraPos);
		return true;
	}
	return false;
}

TPoro TListaPoro::Obtener(const TListaPosicion &obtenerPos) const {
	return obtenerPos.pos->e;
}

bool TListaPoro::Buscar(const TPoro &poro) {
	TListaNodo *aux = primero;
	while(aux)
	{
		if(aux->e == poro)
			return true;
		else
			aux = aux->siguiente;
	}
//	if(!EsVacia())
//	{
//		TListaPosicion comparaPos = Primera();
//		while(!comparaPos.Siguiente().EsVacia())
//		{
//			if(comparaPos.pos->e == poro)
//				return true;
//			else
//			{
//				comparaPos = comparaPos.Siguiente();
//			}
//
//		}
//	}
	return false;
}

int TListaPoro::Longitud() const{
}

TListaPosicion TListaPoro::Primera() {
	TListaPosicion aux;
	if(primero != NULL)
		aux.pos = primero;
	else
		aux.pos = NULL;
	return aux;
}

TListaPosicion TListaPoro::Ultima() {
}

TListaPoro TListaPoro::ExtraerRango(int n1, int n2) {
}

ostream & operator<<(ostream &os, TListaPoro &lista) {
	TListaPosicion aux = lista.Primera();

	os << "(";
	if(!lista.EsVacia())
	{
		os << lista.Obtener(aux);
		while(!aux.Siguiente().EsVacia())
		{
			aux = aux.Siguiente();
			os << " ";
			os << lista.Obtener(aux);
		}
	}
	os << ")";
	return os;
}
