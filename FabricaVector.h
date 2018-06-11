#ifndef _FABRICA_VECTOR_H
#define _FABRICA_VECTOR_H

#include "Fabrica.h" /** importa la superclase */
#include "Producto.h" /** importa la clase de la cual creará objetos */

class FabricaVector : public Fabrica{
	public:
		/** Asigna los valores que servirán de entrada para poder identificar esta fábrica. */
		FabricaVector(const char * tipoProducto="Elemento", const char * nombreProducto="Vector");
		Producto * producir(); /** Devuelve, en este caso, el puntero del objeto Vector */
		~FabricaVector(); /** Destructor donde si los punteros tienen alguna referencia, elimina la cadena de caracteres. */
};

#endif