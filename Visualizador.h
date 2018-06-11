#ifndef _VISUALIZADOR_ABSTRACTO
#define _VISUALIZADOR_ABSTRACTO
#include "Producto.h"
#include "Lista.h"

class Visualizador : public Producto {
	public:
   	   virtual void visualizar( Lista * )=0;
};

#endif