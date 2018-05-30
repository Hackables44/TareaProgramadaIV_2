#ifndef ANIMAL
#define ANIMAL
#include <iostream>
#include <string>
using namespace std;
class Animal{
	friend ostream& operator<<(ostream & salida, Animal* animal){
		return animal->imprimir(salida); // invoca al método polimorfico
	}
	
	protected:
		string nombre;
		string* colores;
	public:
		Animal();
		Animal(string);
		virtual ~Animal();
		void _init(string color1, string color2, string color3);
		void setUnColor(string);
		void setDosColores(string,string);
		void setTresColores(string,string,string);
		string operator[](int i);
		virtual ostream& imprimir(ostream&) = 0;

};
#endif


