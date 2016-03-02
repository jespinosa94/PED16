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
TListaNodo::TListaNodo() {
	anterior = NULL;
	siguiente = NULL;
}

TListaNodo::TListaNodo(const TListaNodo &tln) {
	e = tln.e;
	anterior = NULL;
	siguiente = NULL;
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
	if(pos == tlp.pos)
		return true;
	return false;
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
}

TListaPoro::TListaPoro(TListaPoro &) {
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
}

bool TListaPoro::Insertar(const TPoro&) {
}

bool TListaPoro::Borrar(TPoro&) {
}

bool TListaPoro::Borrar(TListaPosicion&) {
}

TPoro TListaPoro::Obtener(const TListaPosicion&) {
}

bool TListaPoro::Buscar(const TPoro&) {
}

int TListaPoro::Longitud() const{
}

TListaPosicion TListaPoro::Primera() {
}

TListaPosicion TListaPoro::Ultima() {
}

TListaPoro TListaPoro::ExtraerRango(int n1, int n2) {
}
