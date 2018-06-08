// Hac.h

#ifndef _HAC_H
#define _HAC_H

#include "Elemento.h"
#include "Lista.h"
class Hac : public Agrupador{
	private:
		void crearMatrizDistancias(Elemento*,Elemento*);
		double** matriz;
		int tamayoLista;
		void obtenerTamayoLista(Lista*);
	public:
		Hac();
		~Hac();
		Lista* agrupar(Lista*);
};

#endif
