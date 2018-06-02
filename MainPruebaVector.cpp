#include "Vector.h"
#include "Elemento.h"
#include <iostream>
#include <string>
using namespace std;


int main(){
	double* valores = new double[3];
	for(int n = 0; n < 3; ++n ){
		valores[n] = 1.1; 
	}	
	double* valores2 = new double[3];
	for(int n = 0; n < 3; ++n ){
		valores2[n] = 2.1; 
	}	
	Vector* vector = new Vector(valores, 3);
	Vector* vector2 = new Vector(valores2, 3);
	vector->distancia(vector2);
	delete vector;
	delete vector2;
	delete valores;
	delete valores2;

	return 0;
}