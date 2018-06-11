/** FabricaHilera.cpp		Contiene la implementación de la clase FabricaHilera */
#include "FabricaHilera.h"
#include "Fabrica.h" /** importa la superclase */
#include "Hilera.h" /** importa la clase de la cual creará objetos */

/** - Constructor, asigna el nombre y tipo de productos que la fábrica crea, de esta forma podemos identificar si esta es la fábrica que buscamos */
FabricaHilera::FabricaHilera(const char * tipoProducto, const char * nombreProducto)
:Fabrica(tipoProducto, nombreProducto){
	/** indico que el objeto que se utiliza es de tipo string, es como hacer setTipoProducto("string");  */ 
	/** Asigno como nombre del producto, el nombre de la clase de la cual produce objetos, es como hacer setNombreProducto("Hilera"); */
}

/** - Destructor, se encarga de eliminar la cadena de caracteres a las que apuntan los punteros atributo, si los punteros tienen referencia nula, no hay necesidad de eliminar. Este método no es necesario implementarlo aquí, ya que podría usar el mismo método de su clase padre */
FabricaHilera::~FabricaHilera(){
	if(nombreProducto){ /** si el puntero "nombreProducto" es válido */
		delete [] nombreProducto; /** elimine la hilera a la que hace referencia */
	}
	if(tipoProducto){ /** si el puntero "tipoProducto" es válido */
		delete [] tipoProducto; /** elimine la hilera a la que hace referencia */
	}
}

/** - Invoca al constructor de la clase Hilera y devuelve el puntero que recibe */
Producto * FabricaHilera::producir(){
	return new Hilera(); /** invoca al constructor de la clase Hilera y devuelve el puntero que recibe */
}