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
		void setUnColor(string);
		void setDosColores(string,string);
		void setTresColores(string,string,string);
		string getColor1();
		string getColor2();
		string getColor3();
		virtual ostream& imprimir(ostream&) = 0;

};
#endif


