#ifndef VECTOR
#define VECTOR
#include "Elemento.h"
class Vector : public Elemento{
	private:
		double* valores;
		int length;
		double distanciaMax(Vector*);
		double distanciaPlanoCartesiano(Vector*);
	public:
		Vector();
		Vector(double*, int);
	    Vector* clonar();	   
 	    double distancia(Elemento*);
		ostream& imprimir(ostream&);
	    istream& cargar(istream&);
		double getValor(int);
		double operator[](int indice); /** Método sobrecargado para usar la función getValor */
		void setValor(double, int);
		int getLength(); /** Devuelve la cantidad de celdas del vector double */
};
#endif
