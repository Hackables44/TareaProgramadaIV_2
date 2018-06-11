#ifndef SGV
#define SVG
#include "Lista.h"
#include "Visualizador.h"

class Svg : public Visualizador{
	public:
		Svg();
		void visualizar(Lista*);
};
#endif