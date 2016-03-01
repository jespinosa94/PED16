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
}

TListaNodo::TListaNodo(const TListaNodo &tln) {
}

TListaNodo::~TListaNodo() {
}

TListaNodo& TListaNodo::operator =(TListaNodo&) {
}

/***************************************************************************************************************
 ***************************************************TListaPosicion**********************************************
 ****************************************************************************************************************/
TListaPosicion::TListaPosicion() {
}

TListaPosicion::TListaPosicion(TListaPosicion&) {
}

TListaPosicion::~TListaPosicion() {
}

TListaPosicion& TListaPosicion::operator =(TListaPosicion&) {
}

bool TListaPosicion::operator ==(TListaPosicion&) {
}

TListaPosicion TListaPosicion::Anterior() {
}

TListaPosicion TListaPosicion::Siguiente() {
}

bool TListaPosicion::EsVacia() {
}

/***************************************************************************************************************
 ***************************************************TListaPoro**************************************************
 ****************************************************************************************************************/
TListaPoro::TListaPoro() {
}

TListaPoro::TListaPoro(TListaPoro&) {
}

TListaPoro::~TListaPoro() {
}

TListaPoro& TListaPoro::operator =(TListaPoro&) {
}

bool TListaPoro::operator ==(TListaPoro&) {
}

TListaPoro TListaPoro::operator +(TListaPoro&) {
}

TListaPoro TListaPoro::operator -(TListaPoro&) {
}

bool TListaPoro::EsVacia() {
}

bool TListaPoro::Insertar(TPoro&) {
}

bool TListaPoro::Borrar(TPoro&) {
}

bool TListaPoro::Borrar(TListaPosicion&) {
}

TPoro TListaPoro::Obtener(TListaPosicion&) {
}

bool TListaPoro::Buscar(TPoro&) {
}

int TListaPoro::Longitud() {
}

TListaPosicion TListaPoro::Primera() {
}

TListaPosicion TListaPoro::Ultima() {
}

TListaPoro TListaPoro::ExtraerRango(int n1, int n2) {
}
