
#ifndef _HAC_H
#define _HAC_H

#include "Elemento.h"
#include "Lista.h"
#include "Agrupador.h"
class Hac : public Agrupador{
		
	private:
		
		double** matriz;
		int tamayoLista;
		void obtenerTamayoLista(Lista*);
	public:
		void crearMatrizDistancias(Lista*);
		Hac();
		Hac(Lista*);
		~Hac();
		Lista* agrupar(Lista*);
};

#endif
