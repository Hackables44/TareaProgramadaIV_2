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
		Vector(double*);
	    Vector* clonar();	   
 	    double distancia(Elemento*);
		ostream& imprimir(ostream&);
	    istream& cargar(istream&);
		double getValor(int);
		void setValor(double, int);
};
#endif