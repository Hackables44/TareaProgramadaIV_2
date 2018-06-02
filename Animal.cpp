#include "Animal.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include "Jaccard.h"
using namespace std;

Animal::Animal(){
	nombre = "";
	colores = 0;
}

Animal::Animal(string nombre){
	this->nombre = nombre;
	colores = 0;
}

void Animal::_init(string color1, string color2, string color3){
	if(!colores){
		colores = new string[3];
	}
	colores[0] = color1;
	colores[1] = color2;
	colores[2] = color3;
}

void Animal::setUnColor(string color1){
	_init(color1, "", "");
}

void Animal::setDosColores(string color1, string color2){
	_init(color1, color2, "");
}

void Animal::setTresColores(string color1, string color2, string color3){
	_init(color1, color2, color3);
}

string Animal::operator[](int i){
	string local = "";
	if(i>=0 && i<3){
		local=colores[i];
	}
	else{
		cerr << "El indice ingresado debe ser 0-2, se devuelve una hilera vacía por omision." << endl;
	}
	return local;
}


Animal::~Animal(){
	if(colores){
		delete[] colores;
	}
}

ostream& Animal::imprimir(ostream& salida){
	salida << "El nombre del animal es: " << nombre << endl;
	salida << "Sus colores son: ";
	for(int i = 0; i < 3; ++i){
		if(colores[i] != ""){
			salida << colores[i] << " ";
		}
	}
	salida << endl;
	return salida;
}

istream& Animal::cargar(istream& entrada){
	//falta el cargar 
	return entrada;
}

double Animal::distancia(Elemento* otro){
	Animal* animalPtr = dynamic_cast<Animal*>(otro);
	Jaccard jaccard;
	return jaccard.aplicarAlgoritmo(this,animalPtr);
}

Animal* Animal::clonar(){
	Animal* animalPtr = new Animal(this->nombre);
	return animalPtr;
}
