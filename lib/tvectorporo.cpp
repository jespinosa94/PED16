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
		delete datos;
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
				delete datos;
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
		return datos[dimension-1];
	return error;
}

TPoro TVectorPoro::operator [](int posicion) const {
	if(posicion>=1 && posicion<=dimension)
		return datos[dimension-1];
	return error;
}

int TVectorPoro::Longitud() {
	return dimension;
}

int TVectorPoro::Cantidad() {
}

bool TVectorPoro::Redimensionar(int int1) {
}

ostream & operator <<(ostream &os, const TVectorPoro &tvp){
	os << "[";

	if(tvp.dimension > 0)
	{
		os << 0 << " ";
		os << tvp.datos[0];
		for(int i=1; i<tvp.dimension; i++)
		{
			os << " " << i << " " << tvp.datos[i];
		}
	}

	os << "]";
	return os;
}
