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
	return primero == ultimo == NULL;
}

bool TListaPoro::BuscaLista(const TPoro &poro) {
	return false;
}
void TListaPoro::InsertaCabeza(const TPoro &poro) {
	TListaNodo *aux = new TListaNodo;
	aux->e = poro;
	aux->siguiente = primero;
	primero->anterior = aux;
	aux = primero;
}
bool TListaPoro::Insertar(const TPoro &poro) {
	TListaNodo *nuevoPoro;

	if(EsVacia())
	{
		nuevoPoro = new TListaNodo;
		nuevoPoro->e = poro;
		primero = nuevoPoro;
		ultimo = nuevoPoro;
		return true;
	}
	else if(!BuscaLista(poro))
	{
		if(poro.Volumen() < primero->e.Volumen())
			InsertaCabeza(poro);
		return true;
	}
	return false;
}

bool TListaPoro::Borrar(TPoro&) {
}

bool TListaPoro::Borrar(TListaPosicion&) {
}

TPoro TListaPoro::Obtener(const TListaPosicion &obtenerPos) {
	return obtenerPos.pos->e;
}

bool TListaPoro::Buscar(const TPoro&) {
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
	}
	os << ")";
	return os;
}
