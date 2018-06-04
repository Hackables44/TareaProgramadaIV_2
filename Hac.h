// Hac.h

#ifndef _HAC_H
#define _HAC_H

#include "Vector.h"

class HAC{
	private:
		double similitudCoseno(Vector * v1, Vector * v2); /** - Este método calcula la similitud que existe entre 2 vectores */
		double calcularProductoPunto(Vector * v1, Vector * v2); /** - Calcula y devuelve el producto punto de 2 vectores */
		double calcularNorma(Vector * v); /** - Calcula la norma del vector recibido como parámetro, recibe */
		
	public:
		double distanciaDeVectores(Vector * v1, Vector * v2); /** - Calcula la distancia entre ambos vectores restandole a 1 la similitud coseno obtenido entre ambos vectores */
};

#endif
