// Hac.cpp
#include "Hac.h"
#include "Lista.h"
#include "Elemento.h"
#include <iostream>
using namespace std;

Hac::Hac(){
	matriz = 0; //inicializacion de de la matriz en cero;
	tamayoLista = 0;  //inicializacion del tamayo de la lista con 0
	listaDefinitiva = 0; //inicializacion de la lista definitiva con 0
}

void Hac::crearMatrizDistancias(Lista* lista){
	obtenerTamayoLista(lista); //modifica la variable tamayoLista que es un atributo para tener facil acceso al tamayo con el que estamos trabajando
	matriz = new double*[tamayoLista];
	int count1 = 0; //dimension 1 de la matriz
	int count2 = 0; // dimension 2 de la matriz
	Lista::Iterator f = lista->end();
	for(Lista::Iterator i = lista->begin(); i != f; ++i){
		matriz[count1] = new double[tamayoLista];
		for(Lista::Iterator n = lista->begin(); n != f; ++n){
			matriz[count1][count2] = (*i)->distancia(*n); //voy agregando los valores de las distancias en los lugares correspondientes
			//cout << "matriz: " <<  matriz[count1][count2] << "   ";    PARA FUTURAS PRUEBAS LA PODRIA DESCOMENTAR CON LO DE 3 LINEAS ABAJO
			++count2; // se aumenta el contador para ubicarnos en otra columna
		}
		//cout << endl; // PARA FUTURAS PRUEBAS DESCOMENTAR CON LO DE 3 LINEAS ARRIBA
		count2 = 0; // se reinicia el contador de columnas y se pasa a la siguiente fila 
		++count1; //aqui se pasaria a la siguiente fila
	}
}

void Hac::obtenerTamayoLista(Lista* lista){
	int count = 0; //se ira aumentando conforme avanza el for que va desde el principio de la lista hasta el fin
	Lista::Iterator f = lista->end();
	for(Lista::Iterator i = lista->begin(); i != f; ++i){
		++count; //aumento del contador de elementos de la lista
	}
	tamayoLista = count; //devuelve el tamayo de la lista por medio del resultado del for anterior que la recorrio por medio de los iteradores 
}

Lista* Hac::agrupar(Lista* lista){ 
	if(listaDefinitiva == 0){ //si este metodo se esta haciendo por primera vez inicializo el puntero de la lista definitiva
		Lista* listaDefinitiva = new Lista; //inicializacion de la lista que quedara agrupada
	}
	crearMatrizDistancias(lista); // crea la matriz con las distancias de acceso rapido
	if(tamayoLista > 1){ //condicion de parada del recursivo, significa que ya la lista tiene todos los elementos agrupados
	listaDefinitiva = mejorVecino(lista); //voy a hacer que esto me retorne una lista y la seguire utilizando en el metodo de forma recursiva
	agrupar(listaDefinitiva); //llamada al recursivo con la nueva lista, se volvera a hacer todo el proceso pero variando los valores ya que depende de la lista que se ingresa
	}
	return listaDefinitiva; //retorna el resultado final 
}

Hac::~Hac(){ 
	if(matriz){ //si la matriz es diferente de cero entra
		for(int i = 0; i < tamayoLista ; ++i){ 
			delete [] matriz[i]; //elimina el vector de punteros a double de la matriz 
		}
		delete matriz; //elimina el puntero de punteros a double
		matriz = 0; //elimino los rastros de a quien le apuntaba el puntero
	}
}

Lista* Hac::mejorVecino(Lista* listaOriginal){
	double almacenDeVecinos[tamayoLista]; //almacena el valor de la distancia mas cercana del mejor vecino
	Lista* listaConNuevosValores = new Lista; // esta sera la lista a la que le agregue todas las listas creadas y los elementos que no se agruparon en esta vuelta
	double buscadorDeMejorVecino = 1.0; //distancia por default del vecino ya que es la maxima
	int referenciaDeQuienFueElVecino[tamayoLista]; //para saber quien es el mejor vecino de cada elemento
	for(int f = 0; f < tamayoLista; ++f){
		for(int c = 0; c < tamayoLista; ++c){
			if(matriz[f][c] < buscadorDeMejorVecino && f != c){
				buscadorDeMejorVecino = matriz[f][c]; //.asignacion del valor de la distancia del mejor vecino
				referenciaDeQuienFueElVecino[f] = c; //asiggnacion de la referencia del mejor vecino
			}
		}
		almacenDeVecinos[f] = buscadorDeMejorVecino; //se asigna en el vector el valor oficial del mejor vecino
		buscadorDeMejorVecino = 1; //lo vuelvo a tomar como 1 por ser la mayor distancia posible por default
	}
	int ubicacionDelIterador = 0; //variable entero utilizada para saber en el numero de posicion de la lista que se encuentra el iterator
	int totalDeListasUtilizadas = 0; //variable que me sirve para manipular el buffer de listas
	Lista** bufferDeListas; //buffer de listas, porque no se cuantas listas ocupare en en la realizacion
	int controlador = 0; //variable que me permite controlar por cual iteracion de agregar el elemento que agrupare para asi pasar al siguiente puntero en el vector de punteros de buffer
	bufferDeListas = new Lista*[25]; //le asigno al puuntero a punteros de lista un vector de punteros a lista 
	Lista::Iterator i = listaOriginal->begin(); //el valor begin de la lista original que entra en el metodo
	for(int f = 0; f < tamayoLista; ++f){
		if(f == referenciaDeQuienFueElVecino[referenciaDeQuienFueElVecino[f]]){ //quiere decir que si el mejor vecino es mutuo entra, ATENCIOOOONNNNNN ESTE ALGORITMO ES EL QUE ME ESTA DANDO PROBLEMAS YA QUE ENTRA 2 VECES CON LOS MISMO VALORES PORQUE SI EL 2 Y EL 3 SU DISTANCIA DE MEJOR ES MUTUA ENTRA PARA CUANDO NOS REFERIMOS AL 2 Y TAMBIEN PARA EL 3
			while(ubicacionDelIterador < referenciaDeQuienFueElVecino[f]){ //while que me permite ubicar el iterator en el lugar exacto donde lo necesito
				++ubicacionDelIterador; //aumento de la variable que me dice la posicion del iterator para mantenerlo ubicado
				++i; //aumento de la posicion del iterator
			}
			while(ubicacionDelIterador > referenciaDeQuienFueElVecino[f]){ //while que me permite ubicar el iterator en el lugar exacto donde lo necesito
				--ubicacionDelIterador; //decremento de la variable que me dice la posicion del iterator para mantenerlo ubicado
				--i; //decremento de la posicion del iterator
			}
			if(ubicacionDelIterador == referenciaDeQuienFueElVecino[f]){ //me sirve para berificar si el while correspondiente realizo bien su trabajo
				++controlador; // controlar por cual iteracion voy para llevar control de la accion a tomar
				if(controlador == 1){ //cuando es uno significa que debo hacerle un new a la casilla correspondiente del vector de punteros a lista
					bufferDeListas[totalDeListasUtilizadas] = new Lista; //necesitoo crear la instancia de lista nueva a la que apunta el puntero dentro del vector a punteros a lista 
				}
				*bufferDeListas[totalDeListasUtilizadas] += *i; //se agrega el elemento a la lista correspondiente del buffer
				if(controlador == 2){ //cuando es 2 debo aumentar el contador de total de lista utilizadas y reiniciar el controlador
					controlador = 0; //se reinicia
					++totalDeListasUtilizadas; //para pasar al siguiente puntero en el vector de punteros a lista del buffer 
				}
			}
		}else{ //para tomar en cuenta los elementos que no se pudieron agrupar
			while(ubicacionDelIterador > f){ //while que me permite ubicar el iterator en el lugar exacto donde lo necesito
				--ubicacionDelIterador; //decremento de la variable que me dice la posicion del iterator para mantenerlo ubicado
				--i; //decremento de la posicion del iterator
			}
			while(ubicacionDelIterador < f){ //while que me permite ubicar el iterator en el lugar exacto donde lo necesito
				++ubicacionDelIterador; //aumento de la variable que me dice la posicion del iterator para mantenerlo ubicado
				++i; //aumento de la posicion del iterator
			}
			if(ubicacionDelIterador == f){  //me sirve para berificar si el while correspondiente realizo bien su trabajo
				*listaConNuevosValores += *i; //agregando el valor correspondiente a la lista definitiva
			}
		}
	}
	for(int i = 0; i < totalDeListasUtilizadas; ++i){
		*listaConNuevosValores += bufferDeListas[i]; //aqui se agrega las listas
		delete bufferDeListas[i]; //destruyo todas las listas a las que les hice new en el buffer
	}
	delete bufferDeListas; //destruyo al buffer
	bufferDeListas = 0; //no dejo rastro a lo que le apuntaba el buffer
	// -----------------------------------------------------------------DESCOMENTAR SI SE QUIERE VER COMO SE VAN AGRUPANDO -----------------------------------------------------------
	/* Lista::Iterator finalDefinitivo = listaConNuevosValores->end();
	int count = 0;
	cout << "Lista Definitiva: \n"; 
	for(Lista::Iterator inicioDefinitivo = listaConNuevosValores->begin(); inicioDefinitivo != finalDefinitivo; ++inicioDefinitivo){
		cout << "elemento numero " << count << ": " << *inicioDefinitivo << endl; 
		++count;	
	}
	cout << "\n\n\n"; */
	return listaConNuevosValores; //retorna la lista nueva con los valores ya agrupados
}

