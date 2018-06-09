// Hac.cpp
#include "Hac.h"
#include "Lista.h"
#include "Elemento.h"
#include <iostream>
using namespace std;

Hac::Hac(){
	matriz = 0;
	tamayoLista = 0;
}

Hac::Hac(Lista* lista){
	crearMatrizDistancias(lista);
}

void Hac::crearMatrizDistancias(Lista* lista){
	obtenerTamayoLista(lista);
	matriz = new double*[tamayoLista];
	int count1 = 0; //dimension 1 de la matriz
	int count2 = 0; // dimension 2 de la matriz
	Lista::Iterator f = lista->end();
	for(Lista::Iterator i = lista->begin(); i != f; ++i){
		matriz[count1] = new double[tamayoLista];
		for(Lista::Iterator n = lista->begin(); n != f; ++n){
			matriz[count1][count2] = (*i)->distancia(*n); //voy agregando los valores de las distancias en los lugares correspondientes
			cout << "matriz: " <<  matriz[count1][count2] << "   ";
			++count2; // se aumenta el contador para ubicarnos en otra columna
		}
		cout << endl;
		count2 = 0; // se reinicia el contador de columnas y se pasa a la siguiente fila 
		++count1;
	}
}

void Hac::obtenerTamayoLista(Lista* lista){
	int count = 0; //se ira aumentando conforme avanza el for que va desde el principio de la lista hasta el fin
	Lista::Iterator f = lista->end();
	for(Lista::Iterator i = lista->begin(); i != f; ++i){
		++count;
	}
	tamayoLista = count;
}

Lista* Hac::agrupar(Lista* lista){ //falta implementar 
	return lista;
}

Hac::~Hac(){ 
	if(matriz){
		for(int i = 0; i < tamayoLista ; ++i){ 
			delete [] matriz[i];
		}
		delete matriz;
		matriz = 0;
	}
}

