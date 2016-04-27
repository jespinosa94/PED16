/*
 * tabbporo.cpp
 *
 *  Created on: Apr 5, 2016
 *      Author: jorge
 */

#include "../include/tabbporo.h"
#include <queue>

TNodoABB::TNodoABB():iz(), de(), item() {}

TNodoABB::TNodoABB(TNodoABB &origen){
	Copia(origen);
}

TNodoABB::~TNodoABB() {} //Llama a los destructores de cada tipo de dato automáticamente

void TNodoABB::Copia(const TNodoABB &origen){
	(this)->item = origen.item;
	if(!origen.de.EsVacio())
		(this)->de = origen.de;
	if(!origen.iz.EsVacio())
		(this)->iz = origen.iz;
}
TNodoABB& TNodoABB::operator =(const TNodoABB &origen) {
	if(this != &origen)
	{
		(this)->~TNodoABB();
		Copia(origen);
	}
	return *this;
}

/*
 * ****************************************************************************
 */
void TABBPoro::InordenAux(TVectorPoro &vector, int &posicion) {
	if(!EsVacio())
	{
		nodo->iz.InordenAux(vector, posicion);
		vector[posicion] = nodo->item;
		posicion++;
		nodo->de.InordenAux(vector, posicion);
	}
}

void TABBPoro::PreordenAux(TVectorPoro &vector, int &posicion) {
	if(!EsVacio())
	{
		vector[posicion] = nodo->item;
		posicion++;
		nodo->iz.PreordenAux(vector, posicion);
		nodo->de.PreordenAux(vector, posicion);
	}
}

void TABBPoro::PostordenAux(TVectorPoro &vector, int &posicion) {
	if(!EsVacio())
	{
		nodo->iz.PostordenAux(vector, posicion);
		nodo->de.PostordenAux(vector, posicion);
		vector[posicion] = nodo->item;
		posicion++;
	}
}

void TABBPoro::NivelesAux(TVectorPoro &vector, int &posicion)
{
	TNodoABB *aux;
	queue<TNodoABB *> cola;
	cola.push((*this).nodo);
	while(!cola.empty())
	{
		aux = cola.front();
		vector[posicion] = cola.front()->item;
		posicion++;
		cola.pop();
		if(!aux->iz.EsVacio())
			cola.push(aux->iz.nodo);
		if(!aux->de.EsVacio())
			cola.push(aux->de.nodo);
	}
}

TABBPoro::TABBPoro(): error() {
	nodo = NULL;
}

TABBPoro::TABBPoro(TABBPoro &origen) {
	Copiar(origen);
}

TABBPoro::~TABBPoro() {
	if(!EsVacio())
	{
		nodo = NULL;
		delete nodo;
	}
}

void TABBPoro::Copiar(const TABBPoro &origen){
	if(origen.nodo != NULL)
	{
		TNodoABB *aux = new TNodoABB();
		aux->item = origen.nodo->item;
		nodo = aux;
		nodo->iz.Copiar(origen.nodo->iz);
		nodo->de.Copiar(origen.nodo->de);
	}
	else
		nodo = NULL;
}

TABBPoro& TABBPoro::operator =(const TABBPoro &origen) {
	if(this != &origen)
	{
		(*this).~TABBPoro();
		Copiar(origen);
	}
	return *this;
}

bool TABBPoro::CompruebaNodos(const TABBPoro &otroArbol)
{
	if(EsVacio())
		return true;
	else
	{
		return (otroArbol.Buscar(nodo->item) && nodo->iz.CompruebaNodos(otroArbol) && nodo->de.CompruebaNodos(otroArbol));
	}
//	if(esteArbol.Nodos() == otroArbol.Nodos())
//	{
//		if(esteArbol.EsVacio())
//			return true;
//		else
//		{
//			return (otroArbol.Buscar(esteArbol.nodo->item) && esteArbol.CompruebaNodos()
//		}
//	}
//	else
//		return false;
//	if(esteArbol.EsVacio() && otroArbol.EsVacio())
//		return true;
//	else if(!esteArbol.EsVacio() && !otroArbol.EsVacio())
//	{
//		if(esteArbol.nodo->item == otroArbol.nodo->item && CompruebaNodos(esteArbol.nodo->iz, otroArbol.nodo->iz) &&
//				CompruebaNodos(esteArbol.nodo->de, otroArbol.nodo->de))
//			return true;
//	}
//	else
//		return false;
}

bool TABBPoro::operator ==(const TABBPoro &otroArbol) {
//	return CompruebaNodos((*this), otroArbol);
	if(Nodos() == otroArbol.Nodos())
		return CompruebaNodos(otroArbol);
	else
		return false;
}

bool TABBPoro::EsVacio() const{
	return nodo == NULL;
}
bool TABBPoro::EsHoja() const{
	return (nodo->de.EsVacio() && nodo->iz.EsVacio());
}

bool TABBPoro::FiltraVolumen(const int &volumen) {
	if(nodo->item.Volumen() == volumen)
		return false;
	else if(volumen < nodo->item.Volumen() && !nodo->iz.EsVacio())
		nodo->iz.FiltraVolumen(volumen);
	else if(volumen > nodo->item.Volumen() && !nodo->de.EsVacio())
		nodo->de.FiltraVolumen(volumen);
	else
		return true;
}

void TABBPoro::BuscaInserta(TNodoABB *nuevo){
	//Comprobar recursivamente que sea menor o mayor que el elemento nodo de la raiz e introducir donde quepa
	if(nuevo->item.Volumen() < nodo->item.Volumen())
	{
		//recursión hacia la izquierda del árbol
		if(!nodo->iz.EsVacio())
			nodo->iz.BuscaInserta(nuevo);
		else
			nodo->iz.nodo = nuevo;
	}
	else if(nuevo->item.Volumen() > nodo->item.Volumen())
	{
		//recursión hacia la derecha del árbol
		if(!nodo->de.EsVacio())
			nodo->de.BuscaInserta(nuevo);
		else
			nodo->de.nodo = nuevo;
	}
}

bool TABBPoro::Insertar(const TPoro &poro) {
	//se crea el nodo a insertar
	TNodoABB *aux = new TNodoABB;;
	aux->item = poro;
	if(EsVacio())
	{
		nodo = aux;
		return true;
	}
	else if(FiltraVolumen(poro.Volumen()))
	{
		BuscaInserta(aux);
		return true;
	}
//	if(FiltraVolumen(poro.Volumen()))
//	{
//		//se crea el nodo a insertar
//		TNodoABB *aux = new TNodoABB;;
//		aux->item = poro;
//		//se busca e inserta el nodo
//		if(EsVacio())
//			nodo = aux;
//		else
//			BuscaInserta(aux);
//
//		return true;
//	}
	return false;
}

bool TABBPoro::Borrar(TPoro &poro) {
	if(!EsVacio())
	{
		if(Buscar(poro))
		{
			if(nodo->item == poro && EsHoja())
			{
				(*this).~TABBPoro();
				return true;
			}
			else if(nodo->item == poro && !EsHoja())
			{
				/*
				 * A partir del nodo donde se encuentra el item se busca el mayor de la izquierda,
				 * se sustituyen los valores del nodo hoja y del nodo a borrar
				 * y se llama a la recursión para borrar el item que ahora será un nodo hoja
				 * Entremedias hay que borrar el poro hoja que seguirá teniendo el mismo resultado
				 * Ver si la idea de los punteros funciona, sino cambiarlo a referencias normales loki
				 */
				TNodoABB aux;
				aux = BuscaMayorIzq((*this));
				Borrar(aux.item);
				TPoro poroApoyo = aux.item;
				aux.item = nodo->item;
				nodo->item = poroApoyo;

				Borrar(poro);
			}
			else if(poro.Volumen() < nodo->item.Volumen() && !nodo->iz.EsVacio())
				nodo->iz.Borrar(poro);
			else if(poro.Volumen() > nodo->item.Volumen() && !nodo->de.EsVacio())
				nodo->de.Borrar(poro);
		}
		else
			return false;
	}
	else return false;
}
TNodoABB TABBPoro::BuscaMayorIzq(const TABBPoro &arbol)
{
	/*
	 * BuscaMayor puede devolver un *nodo, pero siempre será un nodo normal en otras funciones
	 * Si es una raiz o nodo hoja los devuelve sin mas, el problema es cuando el nodo borrado no tiene hijos izquierdos,
	 * entonces hay que buscar el MayorIzq del hijo derecho, que puede ser recursivo a la derecha y al final devolver un nodo hoja si
	 * es una lista ordenada del modo 1->3->5->7 y borrar el 3
	 * PD: vaya rallada
	 */
	TNodoABB *aux = arbol.nodo;
	if(!arbol.nodo->iz.EsVacio())
	{
		aux = arbol.nodo->iz.nodo;
		while(!aux->de.EsVacio())
		{
			aux = aux->de.nodo;
		}
		return *aux;
	}
	else if(!arbol.nodo->de.EsVacio())
	{
		/*
		 * BuscaMayor devuelve un nodo normal y por eso se puede hacer de esta manera
		 */
//		TNodoABB aux2;
//		aux2 = BuscaMayorIzq(arbol.nodo->de);
//		return aux2;
		aux = arbol.nodo->de.nodo;
//		return *aux;
	}
//	else
		return *aux;

}

bool TABBPoro::Buscar(const TPoro &poro) const {
	if(EsVacio())
		return false;
	else
		return BuscarAux(poro);
}

bool TABBPoro::BuscarAux(const TPoro &poro) const
{
	if(nodo->item == poro)
		return true;
	else if(poro.Volumen() < nodo->item.Volumen() && !nodo->iz.EsVacio())
		nodo->iz.Buscar(poro);
	else if(poro.Volumen() > nodo->item.Volumen() && !nodo->de.EsVacio())
		nodo->de.Buscar(poro);
	else
		return false;
}

TPoro TABBPoro::Raiz() {
	if(!EsVacio())
		return nodo->item;
	else
		return error;
}

int TABBPoro::Altura() {
	int a1, a2;
	if(!EsVacio())
	{
		a1 = nodo->iz.Altura();
		a2 = nodo->de.Altura();
		return (1 + (a1<a2 ? a2:a1));
	}
	else return 0;
}

int TABBPoro::Nodos() const {
	return NodosAux(0);
}
int TABBPoro::NodosAux(int total) const
{
	if(!EsVacio())
	{
		total = 1 + nodo->iz.NodosAux(total) + nodo->de.NodosAux(total);
	}
	return total;
}

int TABBPoro::NodosHoja() {
	int a1=0;
	if(!EsVacio())
	{
		a1 = a1 + nodo->iz.NodosHoja() + nodo->de.NodosHoja();
		if(EsHoja())
			a1++;
	}
	return a1;
}

TVectorPoro TABBPoro::Inorden() {
	//Posición en el vector que almacena el recorrido
	int posicion = 1;
	//Vector del tamaño adecuado para almacenar todos los nodos
	TVectorPoro v(Nodos());
	InordenAux(v, posicion);
	return v;
}

TVectorPoro TABBPoro::Preorden() {
	//Posición en el vector que almacena el recorrido
	int posicion = 1;
	//Vector del tamaño adecuado para almacenar todos los nodos
	TVectorPoro v(Nodos());
	PreordenAux(v, posicion);
	return v;
}

TVectorPoro TABBPoro::Postorden() {
	//Posición en el vector que almacena el recorrido
	int posicion = 1;
	//Vector del tamaño adecuado para almacenar todos los nodos
	TVectorPoro v(Nodos());
	PostordenAux(v, posicion);
	return v;
}


TVectorPoro TABBPoro::Niveles() {
	TVectorPoro recorrido;
	if(!EsVacio())
	{
		recorrido.Redimensionar(Nodos());
		int pos = 1;
		NivelesAux(recorrido, pos);
	}

	return recorrido;
}

TABBPoro TABBPoro::operator +(TABBPoro &arbol) {
	TABBPoro aux((*this));
	TVectorPoro vectorArbol(arbol.Inorden());
	for(int i=0; i<vectorArbol.Longitud(); i++)
		aux.Insertar(vectorArbol[i]);
	return aux;
}

TABBPoro TABBPoro::operator -(TABBPoro &arbol) {
	TVectorPoro vectorThis = Inorden();
	TABBPoro aux;
	for (int i=0; i<vectorThis.Longitud(); i++)
	{
		if(!arbol.Buscar(vectorThis[i]))
			aux.Insertar(vectorThis[i]);
	}
	return aux;
}

ostream & operator<<(ostream &os, TABBPoro &arbol)
{
	os << arbol.Niveles();
	return os;
}
