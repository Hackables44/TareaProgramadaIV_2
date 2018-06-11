#include "Animal.h"
#include <iostream>
#include <string>
using namespace std;


int main(){
	Animal* perro = new Animal("Bruno");
	Animal* gato = new Animal("Tomy");
	perro->setTresColores("Blanco","Negro","Rojo");
	gato->setTresColores("Azul","Blanco","Celeste");
	cout << perro->distancia(gato) << endl;
	delete perro;
	delete gato;

	return 0;
}