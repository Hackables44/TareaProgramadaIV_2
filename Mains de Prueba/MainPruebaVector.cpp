#include "Vector.h"
#include "Elemento.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main(){
	ifstream entrada("datosVector.txt"); /** crea un objeto para entrada de flujos de bytes, el cual toma los datos de "datosVector.txt" */
	int cantidadVectores = 0; /** almacena la cantidad objetos hilera que se crearán */
	entrada >> cantidadVectores; /** toma y guarda la cantidad de vectores que almacena el archivo */
	
	Vector * vDoubles[cantidadVectores]; /** crea un vector de punteros a objetos hilera */
	
	/** le asigna a cada puntero una instancia de vector, le pasa los datos para que se inicialice, e imprime sus atributos */
	for(int i=0; i<cantidadVectores; ++i){
		cout << "i:" << i << endl;
		vDoubles[i] = new Vector(); /** crea un objeto un devuelve el puntero */
		entrada >> vDoubles[i]; /** le paso el objeto ifstream por medio del operador sobrecargado */
		cout << vDoubles[i]; /** imprime los valores del vector */
	}
	
	// double* valores = new double[3];
	// for(int n = 0; n < 3; ++n ){
		// valores[n] = 1.1; 
	// }	
	// double* valores2 = new double[3];
	// for(int n = 0; n < 3; ++n ){
		// valores2[n] = 2.1; 
	// }	
	// Vector* vector = new Vector(valores, 3);
	// Vector* vector2 = new Vector(valores2, 3);
	// vector->distancia(vector2);
	// delete vector;
	// delete vector2;
	// delete valores;
	// delete valores2;

	return 0;
}