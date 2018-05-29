#include "Elemento.h"
#include "Vector.h"
#include <iostream>
using namespace std;

Vector::Vector(){
	parOrdenado[0] = 0;
	parOrdenado[1] = 0;
}
Vector::Vector(double x,double y){
	parOrdenado[0] = x;
	parOrdenado[1] = y;
}

Elemento* Vector::clonar(){
	Vector* vectorPtr = new Vector(this->parOrdenado[0],this->parOrdenado[1]);
	return vectorPtr;
} //ni de este	   
 	    
double Vector::distancia(Elemento* otro){
	// separar por funciones el pitágoras, la distancia máxima y división general
	//distancia entre puntos en el plano cartesiano
	double pendiente = 0.0; // m = (y2-y1)/(x2-x1)
	// idea: obtener la distancia máxima por medio de una función aparte que comprare las distancias de todos los elementos
	double distanciaMax = 0.0; // la distancia mayor entre 2 elementos en el plano cartesiano
	double cuadrado1 = (otro->parOrdenado[0] - this->parOrdenado[0])*(otro->parOrdenado[0] - this->parOrdenado[0]);
	double cuadrado2 = (otro->parOrdenado[1] - this->parOrdenado[1])*(otro->parOrdenado[1] - this->parOrdenado[1]);
	pendiente = sqrt(cuadrado1+cuadrado2);
	
	return pendiente;
}
		
ostream& Vector::imprimir(ostream& salida){
	salida << "(" << parOrdenado[0] << ", " << parOrdenado[1] << ")" << endl;
}
	    
istream& Vector::cargar(istream& entrada){  //no se si lo hice bien, ya que nunca he implementado cargar
	entrada >> parOrdenado[0];
	entrada >> parOrdenado[1];
	return entrada;
}
		
void Vector::setOrdenada(double y){
	parOrdenado[1] = y;
}
		
double Vector::getOrdenada(){
	return parOrdenado[1];
}
		
void Vector::setAbscisa(double x){
	parOrdenado[0] = x;
}
		
double Vector::getAbscisa(){
	return parOrdenado[0];
}

void Vector::setValores(double x, double y){
	parOrdenado[0] = x;
	parOrdenado[1] = y;
}