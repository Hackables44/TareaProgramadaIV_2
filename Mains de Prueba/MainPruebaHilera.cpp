#include "Hilera.h"
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int main(){
	
	ifstream entrada("Hilera.txt"); /** crea un objeto para entrada de flujos de bytes, el cual toma los datos de "Hilera.txt" */
	string identificadorDeArchivo = ""; /** almacena el nombre/tipo de archivo a escanear*/
	int cantidadVectores = 0; /** almacena la cantidad objetos hilera que se crearán */
	entrada >> identificadorDeArchivo; /** la primera línea en el identificador del tipo del archivo a recibir */
	/** ignora los espacios y salta según el caracter de cambio de línea, luego toma los siguientes bytes significativos */
	entrada >> cantidadVectores; /** toma y guarda la cantidad de vectores que almacena el archivo */
	
	Hilera * vHileras[cantidadVectores]; /** crea un vector de punteros a objetos hilera */
	
	/** le asigna a cada puntero una instancia de vector, le pasa los datos para que se inicialice, e imprime sus atributos */
	for(int i=0; i<cantidadVectores; ++i){
		vHileras[i] = new Hilera(); /** crea un objeto un devuelve el puntero */
		entrada >> vHileras[i]; /** le paso el objeto ifstream por medio del operador sobrecargado */
		cout << vHileras[i];
	}
	
	// /** elimina las instancias de Hilera*/
	// for(int i=0; i<cantidadVectores; ++i){
		// delete vHileras[i]; /** invoca al desconstructor */
		// /** como no se ha creado el vector en la memoria dinámica, se eliminará automáticamente cuando termine está función (en este caso el main) */
	// }
	
	// Hilera * matrizDistanciasHileras [cantidadVectores][cantidadVectores]; /** Se crea una matriz de punteros a vectores "Hilera" */
	// for(int filas=0; filas<cantidadVectores; ++filas){ /** se encarga de recorrer las filas (primera dimensión) de la matriz */
		// for(int columnas=0; columnas<cantidadVectores; ++columnas){ /** se encarga de recorrer las columnas (segunda dimensión) de la matriz */
			// matrizDistanciasHileras[f][c] = 0; /** inicializa la matriz con punteros nulos/null */
		// }
	// }
	
	// int lengthVector = 0; /** Variable que utilizaremos para saber la cantidad de celdas que forman a cada vector */
	// for(int i=0; i<cantidadVectores; ++i){
		// entrada >> lengthVector; /** el primer byte de la fila indica el length del vector */
		// for(int j=0; j<lengthVector; ++j){
			// entrada >> palabra;
			
		// }
	// }
	
	// int length = 4;
	// int cantidadHileras = 4;
	// string * palabras1 = new string [2]; 
	// string * palabras2 = new string [5];
	// string * palabras3 = new string [length];
	// string * palabras4 = new string [length];
	
	// string * palabras5 = new string [length];
	// string * palabras6 = new string [length];
	
	// // vector: { Perro, Gato }
	// palabras1 [0] = "Perro";
	// palabras1 [1] = "Gato";
	
	// // vector: { Perro, Perro, Perro, Gato, Gato }
	// palabras2 [0] = "Perro";
	// palabras2 [1] = "Perro";
	// palabras2 [2] = "Perro";
	// palabras2 [3] = "Gato";
	// palabras2 [4] = "Gato";
	
	// // vector: { Perro, Perro, Gato, Gato }
	// palabras3 [0] = "Perro";
	// palabras3 [1] = "Perro";
	// palabras3 [2] = "Gato";
	// palabras3 [3] = "Gato";
	
	// // vector: { Perro, Gato, Gato, Gato }
	// palabras4 [0] = "Perro";
	// palabras4 [1] = "Gato";
	// palabras4 [2] = "Gato";
	// palabras4 [3] = "Gato";
	// //----------------------------------------------
	// // vector: { Hola, HOLA, mundo, ! }
	// palabras5 [0] = "Hola";
	// palabras5 [1] = "HOLA";
	// palabras5 [2] = "mundo";
	// palabras5 [3] = "!";
	
	// // vector: { La, casa, verde, mundo }
	// palabras6 [0] = "La";
	// palabras6 [1] = "casa";
	// palabras6 [2] = "verde";
	// palabras6 [3] = "mundo";
	
	// Hilera hilera1;
	// Hilera hilera2;
	
	// hilera1.setPalabras(palabras2, 5);
	// hilera2.setPalabras(palabras3, 4);
	
	// /** debugging */
	// cout << "Primera hilera:" << endl;
	// hilera1.imprimir(cout);
	// cout << endl;
	// cout << "Segunda hilera: " << endl;
	// hilera2.imprimir(cout);
	// cout << "\n" << endl;
	
	// double distancia=hilera1.distancia(&hilera2);
	
	
	
	// hilera1.setPalabras(palabras5, 4);
	// hilera2.setPalabras(palabras6, 4);
	
	
	// /** debugging */
	// cout << "Primera hilera:" << endl;
	// hilera1.imprimir(cout);
	// cout << endl;
	// cout << "Segunda hilera: " << endl;
	// hilera2.imprimir(cout);
	// cout << "\n" << endl;
	
	// distancia=hilera1.distancia(&hilera2);
	
	
	// hilera1.setPalabras(palabras1, 2);
	// hilera2.setPalabras(palabras3, 4);
	
	
	// /** debugging */
	// cout << "Primera hilera:" << endl;
	// hilera1.imprimir(cout);
	// cout << endl;
	// cout << "Segunda hilera: " << endl;
	// hilera2.imprimir(cout);
	// cout << "\n" << endl;
	
	// distancia=hilera1.distancia(&hilera2);
	// /* http://www.cplusplus.com/forum/general/62277/ Error on simple math
	// That is not an error. It's a lack of precision, of approximately 0.000000000000000222045
	// Welcome to floating point numbers. This is what they do.
	// http://floating-point-gui.de/
	// */
	
	// /** Devuelvo la memoria */
	// delete palabras1;
	// delete palabras2;
	// delete palabras3;
	// delete palabras4;
	// delete palabras5;
	// delete palabras6;
	
	
	return 0;
}