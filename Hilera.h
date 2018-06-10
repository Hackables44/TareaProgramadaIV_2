#ifndef _HILERA_H
#define _HILERA_H

#include <string>
#include "Elemento.h"

class Hilera : public Elemento{
	private:
		int length; /** length de la línea recibida */
		string * palabrasDiferentes; /** puntero a un vector que contiene en cada celda una de las palabras de una línea  */
		int * frecuenciaPalabras; /** puntero a vector que almacenará las frecuencias de las palabras */
		
		/** los siguientes 3 métodos son para calcular */
		double similitudCoseno(Hilera * hilera2); /** - Este método calcula la similitud que existe entre 2 vectores */
		double calcularProductoPunto(Hilera * hilera2); /** - Calcula y devuelve el producto punto de 2 vectores */
		double calcularNorma(Hilera * hilera); /** - Calcula la norma del vector recibido como parámetro, recibe */
		
	public:
		Hilera(); /** - constructor, inicializa la variable de tipo entero en 0, y los punteros en nulo */
		~Hilera(); /** - destructor, si los punteros son válidos, elimina el objeto al que apuntan (en este caso un vector) y pone la variable length en 0 */
		Hilera * clonar(); /** - devuelve un puntero a un objeto con los mismo datos que este objeto hilera */
		double distancia(Elemento * otro); /** - Calcula la distancia entre ambos vectores restandole a 1 la similitud coseno obtenido entre ambos vectores */
	
		void setPalabras(string * palabras, int length); /** - recibe un puntero a vector de string y la cantidad de celdas que posee */
		void setLength(int length); /** - establece el cantidad de celdas de los vectores de palabras y sus frecuencias; recibe un entero como parámetro */
		void setPalabrasDiferentes(string * palabrasDiferentes, int length); /** - establece el vector de palabras diferentes por medio de un puntero a vector de string y su cantidad de celdas, el strign recibido lo pasa a minúscula */
		void setFrecuenciaPalabras(int * frecuenciaPalabras, int length); /** - establece el vector de palabras diferentes por medio de un puntero a vector de entero y su cantidad de celdas */
	
		int getLength(); /** - devuelve el length de los vectores(palabras y sus frecuencias) */
		int operator[](int indice); /** - método sobrecargado para usar la función getFrecuencia */
		int getFrecuencia(int indice); /** - obtiene la frecuencia de una palabra acorde con su posición en el vector de strings */
		string getPalabra(int indice); /** - obtiene la palabra en el vector de strings */

		ostream & imprimir(ostream & salida); /** - recibe como parámetro un objeto para salida de flujo, y así imprime las palabras que almacena el vector y sus respectivas frecuencias */
		istream & cargar(istream & entrada); /** - recibe como entrada el objeto ifstream que contiene los bytes del archivo cargado de hileras */
};

#endif