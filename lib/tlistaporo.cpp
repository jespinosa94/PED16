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
		pos = tlp.pos;
	}
	return *this;
}

bool TListaPosicion::operator ==(const TListaPosicion &tlp) const {
	return pos == tlp.pos;
}

TListaPosicion TListaPosicion::Anterior() const {
	TListaPosicion aux;
	if(pos->anterior != NULL)
		aux.pos = pos->anterior;

	return aux;
}

TListaPosicion TListaPosicion::Siguiente() const {
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
	primero = NULL;
	ultimo = NULL;
	Copia(poroLista);
}

void TListaPoro::Copia(const TListaPoro &poroLista)
{
	TListaPosicion posLista = poroLista.Primera();
	while(!posLista.EsVacia())
	{
		(*this).Insertar(posLista.pos->e);
		posLista = posLista.Siguiente();
	}
}

TListaPoro::~TListaPoro() {
	TListaPosicion p, q;
	q = Primera();
	while(!q.EsVacia())
	{
		p = q;
		q = q.Siguiente();
		delete p.pos;
	}
	primero = NULL;
	ultimo = NULL;
}

TListaPoro& TListaPoro::operator =(const TListaPoro &poroLista) {
	if(this != &poroLista)
	{
		Copia(poroLista);
	}
	return *this;
}

bool TListaPoro::operator ==(const TListaPoro &poroLista) const{
	TListaPosicion estaLista = Primera();
	TListaPosicion listaP = poroLista.Primera();
	if(EsVacia() && poroLista.EsVacia())
		return true;
	else if(!EsVacia() && !poroLista.EsVacia())
	{
		while(!estaLista.EsVacia())
		{
			if(estaLista.pos->e != listaP.pos->e)
				return false;
			estaLista = estaLista.Siguiente();
			listaP = listaP.Siguiente();
		}
		return true;
	}
	return false;
}

TListaPoro TListaPoro::operator +(const TListaPoro &poroLista) {
	TListaPoro nuevaLista(*this);
	TListaPosicion posLista = poroLista.Primera();
	while(!posLista.EsVacia())
	{
		nuevaLista.Insertar(posLista.pos->e);
		posLista = posLista.Siguiente();
	}
	return nuevaLista;
}

TListaPoro TListaPoro::operator -(const TListaPoro &poroLista) {
	TListaPoro nuevaLista(*this);
	TListaPosicion posLista = poroLista.Primera();
	while(!posLista.EsVacia())
	{
		nuevaLista.Borrar(posLista.pos->e);
		posLista = posLista.Siguiente();
	}
	return nuevaLista;
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
	if(EsVacia())
	{
		InsertaCabeza(poro);
		return true;
	}
	else if(!Buscar(poro))
	{
		if(poro.Volumen() < primero->e.Volumen())
			InsertaCabeza(poro);
		else if(poro.Volumen() >= ultimo->e.Volumen())
			InsertaCola(poro);
		else
			InsertaCentro(poro);
		return true;
	}
	return false;
}

TListaPosicion TListaPoro::ObtenerPosicion(const TPoro &poro)
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
void TListaPoro::BorrarCabeza(const TListaPosicion &aux) {
	if(Longitud() == 1)
	{
		(*this).~TListaPoro();
	}
	else
	{
		primero = primero->siguiente;
		aux.pos->~TListaNodo();
		delete aux.pos;
	}

}

void TListaPoro::BorrarCentro(const TListaPosicion &borraPos) {
	//La declaración de abajo es simplemente para simplificar que si a b c (queremos borrar b
	//a sería anterior y c siguiente)
	TListaNodo *anterior = borraPos.Anterior().pos;
	TListaNodo *siguiente = borraPos.Siguiente().pos;
	anterior->siguiente = siguiente;
	siguiente->anterior = anterior;
	borraPos.pos->~TListaNodo();
	delete borraPos.pos;
}

void TListaPoro::BorrarCola(const TListaPosicion &aux) {
	ultimo = ultimo->anterior;
	ultimo->siguiente = NULL;
	aux.pos->~TListaNodo();
	delete aux.pos;
}

bool TListaPoro::Borrar(const TPoro &poro) {
	if(Buscar(poro))
	{
		TListaPosicion borraPos = ObtenerPosicion(poro);
		Borrar(borraPos);
		return true;
	}
	return false;
}

bool TListaPoro::Borrar(const TListaPosicion &borraPos) {
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

bool TListaPoro::Buscar(const TPoro &poro) const {
	TListaNodo *aux = primero;
	while(aux)
	{
		if(aux->e == poro)
			return true;
		else
			aux = aux->siguiente;
	}
	return false;
}

int TListaPoro::Longitud() const{
	int cont = 0;
	TListaPosicion aux = Primera();
	while(!aux.EsVacia())
	{
		cont++;
		aux = aux.Siguiente();
	}

	return cont;
}

TListaPosicion TListaPoro::Primera() const{
	TListaPosicion aux;
	if(primero != NULL)
		aux.pos = primero;
	else
		aux.pos = NULL;
	return aux;
}

TListaPosicion TListaPoro::Ultima() const{
	TListaPosicion aux;
	if(ultimo != NULL)
		aux.pos = ultimo;
	else
		aux.pos = NULL;
	return aux;
}

TPoro TListaPoro::ObtenerPoro(int n)
{
	TListaPosicion elemento = Primera();
	for(int i=1; i<n; i++)
	{
		elemento = elemento.Siguiente();
	}
	return elemento.pos->e;
}

TListaPoro TListaPoro::ExtraerRango(int n1, int n2) {
	TListaPoro nuevaLista;
	TPoro aux;

	if(n1>n2)
		return nuevaLista;
	else if(n1==n2)
	{
		aux = ObtenerPoro(n1);
		nuevaLista.Insertar(aux);
	}
	else
	{
		if(n1<=0)
			n1 = 1;
		if(n2>Longitud())
			n2 = Longitud();
		for(int i=n1; i<=n2; i++)
		{
			aux = ObtenerPoro(i);
			nuevaLista.Insertar(aux);
		}
	}
	/*
	 * No me deja utilizar el operador - dentro de un módulo de la clase
	 */
	TListaPosicion posLista = nuevaLista.Primera();
	while(!posLista.EsVacia())
	{
		(*this).Borrar(posLista.pos->e);
		posLista = posLista.Siguiente();
	}

	return nuevaLista;
}

ostream & operator<<(ostream &os, const TListaPoro &lista) {
	TListaPosicion aux;
	aux = lista.Primera();

	os << "(";
	if(!lista.EsVacia())
	{
		os << lista.Obtener(aux);
		aux = aux.Siguiente();
		while(!aux.EsVacia())
		{
			os << " ";
			os << lista.Obtener(aux);
			aux = aux.Siguiente();
		}
	}
	os << ")";
	return os;
}
