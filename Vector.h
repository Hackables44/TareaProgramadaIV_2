#ifndef VECTOR
#define VECTOR
#include "Elemento.h"
class Vector : public Elemento{
	private:
		double parOrdenado[2];
	public:
		Vector();
		Vector(double,double);
		Elemento(const Elemento&); 
	    Elemento* clonar();	   
 	    double distancia(Elemento*);
		ostream & imprimir(ostream&);
	    istream & cargar(istream&);
		void setOrdenada(double);
		double getOrdenada();
		void setAbscisa(double);
		double getAbscisa();
		void setValores(double,double);
};
#endif