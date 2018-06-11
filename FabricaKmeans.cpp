
#include "FabricaKmeans.h"
#include "Fabrica.h" /** importa la superclase */
#include "Kmeans.h" /** importa la clase de la cual creará objetos */

/** - Constructor, asigna el nombre y tipo de productos que la fábrica crea, de esta forma podemos identificar si esta es la fábrica que buscamos */
FabricaKmeans::FabricaKmeans(const char * tipoProducto, const char * nombreProducto)
:Fabrica(tipoProducto, nombreProducto){
	/** indico que el objeto que se utiliza es de tipo string, es como hacer setTipoProducto("string");  */

}


FabricaKmeans::~FabricaKmeans(){
	if(nombreProducto){ /** si el puntero "nombreProducto" es válido */
		delete [] nombreProducto; /** elimine  a la que hace referencia */
	}
	if(tipoProducto){ /** si el puntero "tipoProducto" es válido */
		delete [] tipoProducto; /** elimine a la que hace referencia */
	}
}

/** - Invoca al constructor de la clase  y devuelve el puntero que recibe */
Producto * FabricaKmeans::producir(){
	return new Kmeans(); /** invoca al constructor de la clase y devuelve el puntero que recibe */
}
