#ifndef _FABRICA_HAC_H
#define _FABRICA_HAC_H

#include "Fabrica.h" /** importa la superclase */
#include "Producto.h" /** importa la clase de la cual creará objetos */

class FabricaHac : public Fabrica{
	public:
		/** Asigna los valores que servirán de entrada para poder identificar esta fábrica. */
		FabricaHac(const char * tipoProducto="Agrupador", const char * nombreProducto="Hac");
		Producto * producir(); /** Devuelve, en este caso, el puntero del objeto Hac */
		~FabricaHac(); /** Destructor donde si los punteros tienen alguna referencia, elimina la cadena de caracteres. */
};

#endif