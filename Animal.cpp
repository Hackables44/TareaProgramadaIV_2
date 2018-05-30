#include "Animal.h"
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

Animal::Animal(){
	nombre = "";
	colores = 0;
}

Animal::Animal(string nombre){
	this->nombre = nombre;
	colores = 0;
}
/*
void Animal::setUnColor(string color1){
	if(!colores){
		colores = new string[3];
		colores[0] = color1;
		colores[1] = "";
		colores[2] = "";
	}
}

void Animal::setDosColores(string color1, string color2){
	if(!colores){
		colores = new string[3];
		colores[0] = color1;
		colores[1] = color2;
		colores[2] = "";
	}
}

void Animal::setTresColores(string color1, string color2, string color3){
	if(!colores){
		colores = new string[3];
		colores[0] = color1;
		colores[1] = color2;
		colores[2] = color3;
	}
}
*/
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

/*
string Animal::getColor1(){
	return colores[0];
}

string Animal::getColor2(){	
	return colores[1];	
}

string Animal::getColor3(){
	return colores[2];
}
*/

Animal::~Animal(){
	cout << "Se entro al destructor" << endl;
	delete[] colores;
}

