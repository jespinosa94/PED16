/*
 * TPoro.cpp
 *
 *  Created on: 15 de feb. de 2016
 *      Author: jorge
 */

#include "TPoro.h"

TPoro::TPoro() {
	x = y = volumen = 0;
	color = NULL;
}

TPoro::TPoro(int x, int y, double vol) {
	this->x = x;
	this->y = y;
	volumen = vol;
	color = NULL;
}

TPoro::TPoro(int x, int y, double vol, char* c) {
	this->x = x;
	this->y = y;
	volumen = vol;
	color = new char[strlen(c) + 1];
	if(color == NULL)
		return;
	strcpy(color, c);
}

TPoro::TPoro(const TPoro &poro) {
	Copy(poro);
}

TPoro::~TPoro() {
	x = y = volumen = 0;
	if(color != NULL){
		delete color;	//Se libera la memoria
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
	bool temp;
	temp = (x==p.x && y==p.y && volumen==p.volumen && !strcmp(color, p.color)) ? true : false;
	return temp;
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
	color = new char[strlen(p.color) + 1];
	if(color == NULL)
		return;
	strcpy(color, p.color);
}

bool TPoro::EsVacio() const{
	return(x==0 && y==0 && volumen==0 && color==NULL);
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
