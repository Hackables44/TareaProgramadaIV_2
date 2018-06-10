
#ifndef _HAC_H
#define _HAC_H

#include "Elemento.h"
#include "Lista.h"
#include "Agrupador.h"
class Hac : public Agrupador{
	
	private:
		void crearMatrizDistancias(Lista*); // metodo que crea una matriz con la informacion de las distancias para acceso rapido
		double** matriz; //matriz de distancias 
		int tamayoLista; //variable del tamayo de lista que se esta utilizando
		Lista* listaDefinitiva; //es el puntero a lista que se planea devolver como resultado del agrupador
		void obtenerTamayoLista(Lista*); //metodo necesario ya que el tamayo de la lista es conveniente tenerlo a mano
	public:
		Hac();
		~Hac();
		Lista* agrupar(Lista*);
		Lista* mejorVecino(Lista*); //por cuestion de prueba lo tengo publico pero finalizada la clase se pondra privado
};

#endif
