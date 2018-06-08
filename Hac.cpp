// Hac.cpp
#include "Hac.h"
#include "Lista.h"
#include "Elemento.h"

Hac::Hac(){
	m = 0;
};

Hac::crearMatrizDistancias(Lista* lista){
	int local = obtenerTamayoLista(lista);
	m = new double[local]
	int count1 = 0; //dimension 1 de la matriz
	int count2 = 0; // dimension 2 de la matriz
	Lista::Iterator f = lista->end();
	for(Lista::Iterator i = lista->begin(); i != f; ++i){
		m[local] = new double[local];
		for(Lista::Iterator n = lista->begin(); n != f; ++n){
			m[count1][count2] = *i->distancia(*n); //voy agregando los valores de las distancias en los lugares correspondientes
			++count2; // se aumenta el contador para ubicarnos en otra columna
			cout << "Matriz: " m[count1][count2] << "   ";
		}
		cout << endl;
		count2 = 0; // se reinicia el contador de columnas y se pasa a la siguiente fila 
		++count1;
	}
}

int Hac::obtenerTamayoLista(Lista* lista){
	int count 0; //se ira aumentando conforme avanza el for que va desde el principio de la lista hasta el fin
	Lista::Iterator f = lista->end();
	for(Lista::Iterator i = lista->begin(); i != f; ++i){
		++count;
	}
	return count;
}

Lista* Hac::agrupar(Lista* lista){ //falta implementar 
	return lista;
}

Hac::~Hac(){ //aun me falta de implementar 
	if(m){
		for(int i = 0; i < noSeQueIntPoner; ++i){ //no se como obtener el valor de elementos de la lista aqui 
			delete [] m[i];
		}
		delete m;
		m = 0;
	}
}

