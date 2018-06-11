#ifndef _FABRICA_PALABRA_H
#define _FABRICA_PALABRA_H

#include "Fabrica.h" /** importa la superclase */
#include "Producto.h" /** importa la clase de la cual creará objetos */

class FabricaPalabra : public Fabrica{
	public:
		/** Asigna los valores que servirán de entrada para poder identificar esta fábrica. */
		FabricaPalabra(const char * tipoProducto="Elemento", const char * nombreProducto="Palabra");
		Producto * producir(); /** Devuelve, en este caso, el puntero del objeto Palabra */
		~FabricaPalabra(); /** Destructor donde si los punteros tienen alguna referencia, elimina la cadena de caracteres. */
};

#endif