#ifndef PALABRA
#define PALABRA
#include <iostream>
#include <fstream>
#include "Elemento.h"
class Palabra : public Elemento{


	private:
		char* palabra; //puntero a char utilizado para representar la palabra
		int longitud; //longitud de la palabra, util tenerla a la mano 
		
	public:
		//Constructor de la clase Palabra
		Palabra();
		
		//Constructor por parametro de la clase Palabra
		Palabra(const char*);
		
		//Constructor por copia de la clase Palabra
		Palabra(const Palabra&);
		
		//destructor de la clase palabra que destruye su estructura dinamica de char
		~Palabra();
		
		//metodo heredado de elemento que clona los atributos de this
		Palabra* clonar();
		
		//metodo que obtiene la distancia por medio de la formula de distancia de digramas 
		double distancia(Elemento*);
		
		//Retorna el atributo palabra de la clase Palabra
		 char* getPalabra();
		
		//Asigna un nuevo valor al atributo palabra de la clase Palabra
		void setPalabra(const char*);
		
		//Metodo que me devuelve la longitud de la palabra en la clase Palabra
		int getLongitud();
		
		//metodo heredado de elemento que me obliga a saber como imprimirme 
		std::ostream& imprimir(std::ostream&);
		
		//metodo heredado de la clase elemento que me obliga a saber como cargarme 
		std::istream& cargar(std::istream&);
		
		//metodo que calcula la cantidad de bigramas diferentes que conforman la palabra
		double calcularCardinalidad();
		
		//calcula el total de bigramas en comun que hay con la otra palabra
		double calcularInterseccion(Palabra*);
	
};
#endif