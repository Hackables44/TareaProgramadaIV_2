#include "Elemento.h"
#include "Vector.h"
#include <iostream>
#include <tgmath.h>
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
	Vector* vectorPtr = new Vector(this->valores, this->length);
	return vectorPtr;
}   
 	    
double Vector::distancia(Elemento* otro){
	// separar por funciones el pitágoras, la distancia máxima y división general
	//distancia entre puntos en el plano cartesiano
	double distancia = 1.0;
	Vector* vectorPtr = dynamic_cast<Vector*>(otro);
	if(vectorPtr->length == this->length){
		if(distanciaMax(vectorPtr) != 0){
			distancia = distanciaPlanoCartesiano(vectorPtr) / (this->length + vectorPtr->length);
		}else{
			distancia = 0.0;
		}
	}
	cout << distancia;
	return distancia;
}
		
ostream& Vector::imprimir(ostream& salida){
	for(int i = 0; i < length; ++i){
		salida << "{";
		if(i != length - 1){
			salida << valores[i] << ", ";
		}else{
			salida << valores[i] << "}" << endl;
		}
	}
	return salida;
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

/** - método sobrecargado que invoca la función getValor */
double Vector::operator[](int indice){
	return getValor(indice); /** devuelve el número en la determinada posición del vector */
}

/** - función que obtiene el valor almacenado en la posición indicada en el vector de doubles */
double Vector::getValor(int indice){ /** recibe el índice con el cual buscar */
	int valor = 0.0; /** Declaro e inicializo la variable local que almacenará el valor double del vector */
	if(valores){ /** Si el puntero a vectores es válido, no nulo */
		if( indice>=0 && indice<length ){ /** Si el índice recibido como parámetro está en el rango del vector */
			valor = valores[indice]; /** Almacena el valor de la celda con el indice recibido */
		}
		else{
			/** Si el índice se sale del rango del vector, muestra un mensaje de error en pantalla */
			cerr << "El rango del vector es de 0 a " << length << ", el indice ingresado fue " << indice << "." << endl;
		}
	}
	else{
		/** Indica al usuario que no hay un vector de doubles asignado */
		cerr << "No hay vector de numeros double asignado. Devuelve 0.0 por omision." << endl;
	}
	
	return valor; /** devuelve el valor de la celda, o en su defecto 0.0 */
}

/** - devuelve la cantidad de celdas del vector double */
int Vector::getLength(){
	return length; /** devuelve el atributo que almacena el length del vector */
}

 double Vector::distanciaMax(Vector* otro){
	// idea: obtener la distancia máxima por medio de una función aparte que comprare las distancias de todos los elementos
	double distanciaMax = 0.0; // la distancia mayor entre 2 elementos en el plano cartesiano
	double mayor = 0;
	for(int i = 0; i < length; ++i){
		distanciaMax = this->valores[i] - otro->valores[i];
		if(distanciaMax < 0){
			distanciaMax *= -1; //porque una distancia no puede ser negativa asi que le hago valor absoluto
		}
		if(distanciaMax > mayor){
			mayor = distanciaMax;
		}
	}
	return distanciaMax;
}	 

double Vector::distanciaPlanoCartesiano(Vector* otro){
	double pendiente = 0.0; // m = (y2-y1)/(x2-x1) hasta llegar a n
	double cuadrado = 0.0;
	for(int n = 0; n < length; ++n){
		cuadrado += (otro->valores[n] - this->valores[n])*(otro->valores[n] - this->valores[n]);
	}
	pendiente = sqrt(cuadrado);
	return pendiente;
}
