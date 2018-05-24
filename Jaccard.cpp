#include "Jaccard.h"
#include "Perro.h"
#include <iostream>
#include <string>
using namespace std;

Jaccard::Jaccard(){

}

Jaccard::~Jaccard(){
	cout << "Se entro al metodo destructor" << endl;
}

int Jaccard::sacarInterseccion(Animal* animal1, Animal* animal2){
	int interseccion = 0;
	string local1[] = {animal1->getColor1(), animal1->getColor2(), animal1->getColor3()};
	string local2[] = {animal2->getColor1(), animal2->getColor2(), animal2->getColor3()};
	
	for(int n = 0; n < 3; ++n){
		for(int i = 0; i < 3; ++i){
			if(local1[n] == local2[i]){
				if(local1[n] != ""){
					++interseccion;
				}
			}
		}
	}
	cout << "La interseccion es: " << interseccion << endl;
	return interseccion;
}

int Jaccard::sacarUnion(Animal* animal1, Animal* animal2){
	string local1[] = {animal1->getColor1(), animal1->getColor2(), animal1->getColor3()};
	string local2[] = {animal2->getColor1(), animal2->getColor2(), animal2->getColor3()};
	int unionn = 0;
	for(int f = 0;f < 3; ++f){
		if(local1[f] != ""){
			++unionn;
		}
		if(local2[f] != ""){
			++unionn;
		}
	}
	for(int n = 0; n < 3; ++n){
		for(int i = 0; i < 3; ++i){
			if(local1[n] == local2[i]){
				--unionn;
			}
		}
	}	
	cout << "La Union es: " << unionn << endl;
	return unionn;
}

double Jaccard::aplicarAlgoritmo(Animal* animal1, Animal* animal2){
	return sacarInterseccion(animal1,animal2) / sacarUnion(animal1,animal2);
}