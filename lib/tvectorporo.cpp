/*
 * tvectorporo.cpp
 *
 *  Created on: Feb 27, 2016
 *      Author: jorge
 */

#include "../include/tvectorporo.h"

TVectorPoro::TVectorPoro() {
	dimension = 0;
	datos = NULL;
}

TVectorPoro::TVectorPoro(int creaDim) {
	if(creaDim <= 0)
	{
		dimension = 0;
		datos = NULL;
	}
	else
	{
		dimension = creaDim;
		datos = new TPoro[dimension];
	}
}

TVectorPoro::TVectorPoro(const TVectorPoro &tvp) {
	dimension = tvp.dimension;
	datos = new TPoro[dimension];
	if(datos == NULL)
		dimension = 0;
	else
		for(int i=0; i<dimension; i++)
			datos[i] = tvp.datos[i];
}

TVectorPoro::~TVectorPoro() {
	dimension = 0;
	if(datos != NULL)
	{
		datos->~TPoro();
		datos = NULL;
	}
}

TVectorPoro& TVectorPoro::operator =(const TVectorPoro &tvp) {
	if(this != &tvp)
	{
		if(dimension != tvp.dimension)
		{
			dimension = tvp.dimension;
			if(datos != NULL)
				datos->~TPoro(); /*Si peta en algo cambiarlo*/
			datos = new TPoro[dimension];
			if(datos == NULL)
			{
				dimension = 0;
				return *this;
			}
		}
		for(int i=0; i<dimension; i++)
			datos[i] = tvp.datos[i];
	}
	return *this;
}

bool TVectorPoro::operator ==(const TVectorPoro &tvp) {
	if(dimension != tvp.dimension)
		return false;
	for(int i=0; i<dimension; i++)
		if(datos[i] != tvp.datos[i])
			return false;
	return true;
}

bool TVectorPoro::operator !=(const TVectorPoro &tvp) {
	return !(*this == tvp);
}

TPoro& TVectorPoro::operator [](int posicion) {
	if(posicion>=1 && posicion<=dimension)
		return datos[posicion-1];
	//Vaciar el TPoro error para asegurar que antes no se le ha asignado ningún TPoro
	error.~TPoro();
	return error;
}

TPoro TVectorPoro::operator [](int posicion) const {
	if(posicion>=1 && posicion<=dimension)
		return datos[posicion-1];
	//Vaciar el TPoro error para asegurar que antes no se le ha asignado ningún TPoro
	error.~TPoro();
	return error;
}

int TVectorPoro::Longitud() {
	return dimension;
}

int TVectorPoro::Cantidad() {
	int posOcupadas = 0;
	for(int i=0; i<dimension; i++){
		if(!datos[i].EsVacio())
			posOcupadas+=1;
	}
	return posOcupadas;
}

bool TVectorPoro::Redimensionar(int newSize) {
	if(newSize<=0 || dimension==newSize)
		return false;
	else if(dimension<newSize)
	{
		TVectorPoro aux;
		aux.dimension = newSize;
		aux.datos = new TPoro[aux.dimension];
		for(int i=0; i<dimension; i++)
			aux.datos[i] = datos[i];
		(*this).~TVectorPoro();
		(*this) = aux;
	}
	/*
	 *la nueva longitud es menor que la actual y se eliminan los elementos de la derecha
	 */
	else
	{
		TVectorPoro aux;
		aux.dimension = newSize;
		aux.datos = new TPoro[aux.dimension];
		for(int i=0; i<newSize; i++)
			aux.datos[i] = datos[i];
		(*this).~TVectorPoro();
		(*this) = aux;
	}
	return true;
}

ostream & operator <<(ostream &os, const TVectorPoro &tvp){
	os << "[";

	if(tvp.dimension > 0)
	{
		os << 1 << " ";
		os << tvp.operator[](1);
		for(int i=2; i<=tvp.dimension; i++)
		{
			os << " " << i << " " << tvp.operator [](i);
		}
	}

	os << "]";
	return os;
}
