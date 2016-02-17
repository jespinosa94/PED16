/*
 * TPoro.cpp
 *
 *  Created on: 15 de feb. de 2016
 *      Author: jorge
 */

#include "TPoro.h"

TPoro::TPoro() {
	x = y = 0;
	volumen = 0;
	color = NULL;
}

TPoro::TPoro(int x, int y, double vol) {
	this->x = x;
	this->y = y;
	volumen = vol;
}

TPoro::TPoro(int x, int y, double vol, char* color) {
	this->x = x;
	this->y = y;
	volumen = vol;

}

TPoro::TPoro(const TPoro& poro) {
	Copy(poro);
}

TPoro::~TPoro() {
	x = y = volumen = 0;
	if(color != NULL){
		delete color;	//Se borra
		color = NULL;
	}


}

TPoro& TPoro::operator =(const TPoro &p) {
	if(this != &p)
	{
		(*this).~TPoro();
		Copy(p);
	}
	return *this;
}

bool TPoro::operator ==(const TPoro &p) const {
	return (x==p.x && y==p.y && volumen==p.volumen && color==p.color);
}

bool TPoro::operator !=(const TPoro &p) const {
	return ! (*this==p);
}

void TPoro::Posicion(int int1, int int2) {
}

void TPoro::Volumen(double double1) {
}

void TPoro::Color(char*) {
}

int TPoro::PosicionX() {
	return x;
}

int TPoro::PosicionY() {
	return y;
}

double TPoro::Volumen() {
	return volumen;
}

char* TPoro::Color() {
	return color;  ///¿Y si es null hacer que controle y devuelva vacio?
}

void TPoro::Copy(const TPoro& p) {
	x = p.x;
	y = p.y;
	volumen = p.volumen;
	color = p.color;	//Si falla en las pruebas cambiarlo por (comprobar si color es null, si lo es igualar el nuevo a null y
						//con strcpy copiar el color
}

bool TPoro::EsVacio() const{
	return (x==0 && y==0 && volumen==0 && color==NULL);
}

ostream& operator<<(ostream &os, const TPoro &p){
	if(!p.EsVacio()){
		os.setf(ios::fixed);
		os.precision(2);
		os << "(" << p.x << ", " << p.y << ")";
		if(p.color != NULL)
			os << p.color;
		else
			os << "-";
	}
	else
		os << "()";

	return os;
}
