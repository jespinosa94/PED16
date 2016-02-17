#include <iostream>
#include <cstring>
using namespace std;


#ifndef SRC_TPORO_H_
#define SRC_TPORO_H_

class TPoro {
	// Sobrecarga del operador SALIDA
	friend ostream & operator<<(ostream &, const TPoro &);
private:
	// Coordenada x de la posición
	int x;
	// Coordenada y de la posición
	int y;
	// Volumen
	double volumen;
	// Color
	char* color;
	void Copy(const TPoro &p);

public:
	// Constructor por defecto
	TPoro();
	// Constructor a partir de una posición y un volumen
	TPoro(int, int, double);
	// Constructor a partir de una posición, un volumen y un color
	TPoro(int, int, double, char *);
	// Constructor de copia
	TPoro(const TPoro &);
	// Destructor
	~TPoro();
	// Sobrecarga del operador asignación
	TPoro & operator=(const TPoro &);

	// Sobrecarga del operador igualdad
	bool operator==(const TPoro &) const;
	// Sobrecarga del operador desigualdad
	bool operator!=(const TPoro &) const;
	// Modifica la posición
	void Posicion(int, int);
	// Modifica el volumen
	void Volumen(double);
	// Modifica el color
	void Color(char *);
	// Devuelve la coordenada x de la posición
	int PosicionX();
	// Devuelve la coordenada y de la posición
	int PosicionY();
	// Devuelve el volumen
	double Volumen();
	// Devuelve el color
	char * Color();
	// Devuelve cierto si el poro está vacío
	bool EsVacio() const;
};

#endif /* SRC_TPORO_H_ */
