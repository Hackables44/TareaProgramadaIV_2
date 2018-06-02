#ifndef ANIMAL
#define ANIMAL
#include <iostream>
#include <string>
#include "Elemento.h"
using namespace std;
class Animal : public Elemento{
	
	protected:
		string nombre;
		string* colores;
		void _init(string color1, string color2, string color3);
	public:
		Animal();
		Animal(string);
		virtual ~Animal();
		void setUnColor(string);
		void setDosColores(string,string);
		void setTresColores(string,string,string);
		ostream& imprimir(ostream&);
		istream& cargar(istream&);
		double distancia(Elemento*);
		Animal* clonar();
		string operator[](int);
};
#endif


