
#ifndef _HAC_H
#define _HAC_H
#include "Elemento.h"
#include "Lista.h"
#include "Agrupador.h"
class Hac : public Agrupador{
	
	private:
		double** matriz; //matriz de distancias 
		int tamayoLista; //variable del tamayo de lista que se esta utilizando
		Lista* listaDefinitiva; //es el puntero a lista que se planea devolver como resultado del agrupador
		void obtenerTamayoLista(Lista*); //metodo necesario ya que el tamayo de la lista es conveniente tenerlo a mano
		void crearMatrizDistancias(Lista*); // metodo que crea una matriz con la informacion de las distancias para acceso rapido
		Lista* mejorVecino(Lista*); //obtiene los mejores vecinos de la vuelta y los agrupa 
	public:
		Hac();//constructor del agrupador Hac
		~Hac(); //destructor del agrupador Hac, destruye su estructura dinamica matriz
		Lista* agrupar(Lista*); //metodo heredado de agrupador que agrupa siguiendo los pasos de su algoritmo
		
};
#endif
