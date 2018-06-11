/** FabricaHilera.h		Cabecera de la clase FabricaHilera */
#ifndef _FABRICA_HILERA_H
#define _FABRICA_HILERA_H

#include "Fabrica.h" /** importa la superclase */
#include "Producto.h" /** importa la clase de la cual creará objetos */

class FabricaHilera : public Fabrica{
	public:
		/** Asigna los valores que servirán de entrada para poder identificar esta fábrica. */
		FabricaHilera(const char * tipoProducto="Elemento", const char * nombreProducto="Hilera");
		Producto * producir(); /** Devuelve, en este caso, el puntero del objeto Hilera */
		~FabricaHilera(); /** Destructor donde si los punteros tienen alguna referencia, elimina la cadena de caracteres. */
};

#endif
