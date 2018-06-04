// Hac.cpp
#include "Hac.h"
#include "Vector.h"

/** - Calcula la distancia entre ambos vectores restandole a 1 la similitud coseno obtenido entre ambos vectores */
double Hac::distanciaDeVectores(Vector * v1, Vector * v2){
	return 1-similitudCoseno(v1, v2);/** devuelve el valor obtenido de restar la similitud coseno de los vectores a 1 */
}

/** - Este método calcula la similitud que existe entre 2 vectores */
double Hac::similitudCoseno(Vector * v1, Vector * v2){
	double productoPunto = calcularProductoPunto(v1, v2); /** invoca al método que calcula el producto punto ambos vectores y almacena el resultado */
	double normaV1 = calcularNorma(v1); /** almacena la norma del primer vector */
	double normaV2 = calcularNorma(v2); /** almacena la norma del segundo vector */
	double productoDeNormas = normaV1*normaV2; /** almacena la multiplicación de ambas normas obtenidas */
	double coseno = productoPunto/productoDeNormas; /** efectua la división para calcular el coseno */
	return coseno; /** devuelve el coseno obtenido */
}

/** - Calcula y devuelve el producto punto de 2 vectores */
double Hac::calcularProductoPunto(Vector * v1, Vector * v2){ /** Recibe los punteros de los vectores. */
	double productoPunto = 0.0; /** Variable que almacenará el producto punto de los 2 vectores */
	double lengthV1 = v1->getLength(); /** Almacena el length del primer vector */
	double lengthV2 = v2->getLength(); /** Almacena el length del segundo vector */
	
	if( lengthV1==lengthV2 ){ /** Si ambos vectores tienen el mismo tamaño */
		for(int i=0; i<length; ++i){ /** Recorre ambos vectores */
			productoPunto += v1[i]*v2[i]; /** almacena el producto de los valores en ambas celdas */
		}
	}
	else{ /** Si el length de los vectores difiere, lo indica al usuario */
		cerr << "Los vectores conparados difieren de tamaño. Devuelve 0.0 por omision." << endl;
	}
	return productoPunto; /** Devuelve el producto punto de los vectores o en su defecto 0.0 */
}

/** - Calcula la norma del vector recibido como parámetro, recibe */
double Hac::calcularNorma(Vector * v){ /** recibe el puntero del vector al cual calcular la norma */
	/** declaración de las variables locales a utilizar */
	double raizCuadrada = 0.0; /** almacenará la raíz cuadrada, para calcular la norma del vector*/
	double sumaCuadrados = 0.0; /** almacenará la suma de los cuadrados de los números en la celda del vector si hay */
	double cuadrado = 0.0; /** almacenará el cuadrado del valor en determinada celda */
	double valor = 0.0; /** almacena temporalmente el valor de la celda tipo double */
	int length = v->getLength(); /** almacena el length del vector */
	
	for(int i=0; i<length; ++i){ /** recorre el vector */
		valor = v[i]; /** obtiene el valor de la celda en el vector */
		sumaCuadrados += (valor*valor); /** almacena el cuadrado del número, se multiplica el double por sí mismo */
	}
	
	raizCuadrada = sqrt(sumaCuadrados); /** calcula y almacena la raíz cuadrada del total de los números obtenidos elevados a la 2 */
	return raizCuadrada; /** Devuelve la norma obtenida */
}
