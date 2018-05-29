#include "Elemento.h"
#include "Vector.h"
#include <iostream>
using namespace std;

Vector::Vector(){
	valores = 0;
	length = 0;
}
Vector::Vector(double* valores, int longitud){
	this->valores = valores;
	length = longitud;
}

Vector* Vector::clonar(){
	Vector* vectorPtr = new Vector(this->valores);
	return vectorPtr;
} //ni de este	   
 	    
double Vector::distancia(Elemento* otro){
	// separar por funciones el pitágoras, la distancia máxima y división general
	//distancia entre puntos en el plano cartesiano
	Vector* vectorPtr = dynamic_cast<Vector*>(otro);
	return distanciaPlanoCartesiano(vectorPtr) / distanciaMax(vectorPtr);
}
		
ostream& Vector::imprimir(ostream& salida){
	salida << "(" << parOrdenado[0] << ", " << parOrdenado[1] << ")" << endl; //mejorar porque es n dimension
}
	    
istream& Vector::cargar(istream& entrada){  //no se si lo hice bien, ya que nunca he implementado cargar
	// no se muy bien lo que se cargaria
	return entrada;
}
		
void Vector::setValor(double valor, int indice){
	if(valores){
		valores[indice] = valor;
	}
}
		
double Vector::getValor(int indice){
	if(valores){
		return valores[indice];
	}
}

double Vector::distanciaMax(Vector* otro){
	// idea: obtener la distancia máxima por medio de una función aparte que comprare las distancias de todos los elementos
	double distanciaMax = 0.0; // la distancia mayor entre 2 elementos en el plano cartesiano
	return distanciaMax;
}	

double Vector::distanciaPlanoCartesiano(Vector* otro){
	double pendiente = 0.0; // m = (y2-y1)/(x2-x1)
	double cuadrado1 = (otro->parOrdenado[0] - this->parOrdenado[0])*(otro->parOrdenado[0] - this->parOrdenado[0]);
	double cuadrado2 = (otro->parOrdenado[1] - this->parOrdenado[1])*(otro->parOrdenado[1] - this->parOrdenado[1]);
	pendiente = sqrt(cuadrado1+cuadrado2);
	return pendiente;
}