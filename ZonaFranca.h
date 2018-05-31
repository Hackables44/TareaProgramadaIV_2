#ifndef _ZONA_FRANCA
#define _ZONA_FRANCA
#include "Fabrica.h"

class ZonaFranca {
	private:
	   int cantidadDeFabricas; /** atributo que almacena la cantidad de instancias de Fabrica en el vector de fábricas */
	   void agregar(Fabrica *); /** Es usado por el constructor de la clase para agregar una fábrica al vector */
	protected:
	   Fabrica ** fabricas; /** Puntero a puntero(s) de fábrica */
	public:
	   ZonaFranca(); /** constructor por omisión */
	   ~ZonaFranca(); /** destructor */
       Fabrica * getFabrica(const char *, const char *); /** Si hay una fábrica con tipo y nombre especificados, devuelve su puntero */
};

#endif
