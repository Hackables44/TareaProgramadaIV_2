#include "Palabra.h"
#include <iostream>
#include <string>

using namespace std;


int main(){
	//AUN NO HE TOMADO EN CUENTA LA DIFERENCIA ENTRE MAYUSCULAS Y MUNUSCULAS
	Palabra* palabra1 = new Palabra("nada");
	Palabra* palabra2 = new Palabra("hada");
	cout << palabra1->distancia(palabra2) << endl;
	delete palabra1;
	delete palabra2;

	return 0;
}