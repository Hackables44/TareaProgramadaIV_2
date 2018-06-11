/** Fabricakmeans.h		Cabecera de la clase Fabricakmeans */
#ifndef _FABRICA_KMEANS_H
#define _FABRICA_KMEANS_H

#include "Fabrica.h" /** importa la superclase */
#include "Producto.h" /** importa la clase de la cual creará objetos */

class FabricaKmeans : public Fabrica{
	public:
		/** Asigna los valores que servirán de entrada para poder identificar esta fábrica. */
		FabricaKmeans(const char * tipoProducto="Elemento", const char * nombreProducto="Kmeans");
		Producto * producir(); /** Devuelve, en este caso, el puntero del objeto Hilera */
		~FabricaKmeans(); /** Destructor donde si los punteros tienen alguna referencia, elimina la cadena de caracteres. */
};

#endif
