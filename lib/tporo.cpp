/*
 * TPoro.cpp
 *
 *  Created on: 15 de feb. de 2016
 *      Author: jorge
 */

#include "../include/tporo.h"

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
	VerifyLowerCase(c);
	this->x = x;
	this->y = y;
	volumen = vol;
	if(c == NULL)
		color = NULL;
	else{
		color = new char[strlen(c) + 1];
		strcpy(color, c);
	}
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

void TPoro::Posicion(int newX, int newY) {
	x = newX;
	y = newY;
}

void TPoro::Volumen(double newVol) {
	volumen = newVol;
}

void TPoro::Color(char *newColor) {
	VerifyLowerCase(newColor);
	if(newColor == NULL)
		color = NULL;
	else
	{
		color = new char[strlen(newColor) + 1];
		strcpy(color, newColor);
	}
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
	if(p.color == NULL)
		color = NULL;
	else
	{
		color = new char[strlen(p.color) + 1];
		strcpy(color, p.color);
	}
}

bool TPoro::EsVacio() const{
	return(x==0 && y==0 && volumen==0 && color==NULL);
}

void TPoro::VerifyLowerCase(char *&c){
	char* aux;
	if(c==NULL)
		aux = NULL;
	else
	{
		aux = new char[strlen(c) + 1];
		for(int i=0; i<strlen(c); i++)
			aux[i] = tolower(c[i]);
		c = new char[strlen(aux) +1];
		strcpy(c, aux);
	}

}

ostream& operator<<(ostream &os, const TPoro &p){
	if(!p.EsVacio()){
		os.setf(ios::fixed);
		os.precision(2);
		os << "(" << p.x << ", " << p.y << ") " << p.volumen << " ";
		if(p.color != NULL)
			os << p.color;
		else
			os << "-";
	}
	else
		os << "()";

	return os;
}
