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

void TAVLPoro::InordenAux(TVectorPoro&, int&) {
}

void TAVLPoro::PreordenAux(TVectorPoro&, int&) {
}

void TAVLPoro::PostordenAux(TVectorPoro&, int&) {
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

bool TAVLPoro::operator ==(TAVLPoro&) {
}

bool TAVLPoro::operator !=(const TAVLPoro&) {
}

bool TAVLPoro::EsVacio() const {
	return raiz==NULL;
}

bool TAVLPoro::Insertar(TPoro&) {
}

bool TAVLPoro::Buscar(TPoro&) {
}

int TAVLPoro::Altura() {
}

int TAVLPoro::Nodos() {
}

int TAVLPoro::NodosHoja() {
}

TVectorPoro TAVLPoro::Inorden() {
}

TVectorPoro TAVLPoro::Preorden() {
}

TVectorPoro TAVLPoro::Postorden() {
}

bool TAVLPoro::Borrar(TPoro&) {
}

TPoro TAVLPoro::Raiz() {
}

