#include "Palabra.h"
#include <iostream>
#include <string.h> 
#include <fstream>
#include <stdio.h>
#include <ctype.h>


using namespace std;

		//Constructor de la clase Palabra
		Palabra::Palabra(){
			palabra = 0; // inicializa por omision el puntero de char palabra
			longitud = 0; //inicializa por omision el int de la longitud de la palabra
		}
		
		//Constructor por parametro de la clase Palabra
		Palabra::Palabra(const char* palabra){
			this->setPalabra(palabra);
		}
		
		//Constructor por copia de la clase Palabra
		Palabra::Palabra(const Palabra& otro){
			this->setPalabra(otro.palabra);
		}
		
		//Destructor de la clase palabra que destruye su puntero a char dinamico
		Palabra::~Palabra(){
			if(palabra){
				delete palabra;
				palabra = 0;
			}
		}
		
		//metodo clonar de la clase palabra, heredado por la clase Elemento
		Palabra* Palabra::clonar(){
			Palabra* palabraPtr = new Palabra(this->palabra); //crea un nuevo puntero con los valores de el elemento this
			return palabraPtr; //Retorna la nueva copia 
		}
		
		
		
		double Palabra::distancia(Elemento* otro){ // En si ya este metodo esta completo no se porque....
			double distanciaDeBiagramas = 1.0; //distancia mas larga posible asi que se toma por omision
			Palabra* local1 = dynamic_cast<Palabra*>(otro); //le hago un dinamic cast al elmento para poder usar los metodos de la clase palabra
			distanciaDeBiagramas = 1 - ((2 * this->calcularInterseccion(local1)) / (this->calcularCardinalidad() + local1->calcularCardinalidad())); //aplicacion del algoritmo de distancia de bigramas
			return distanciaDeBiagramas; //retorna el resultado del algoritmo de distancia
		}
		
		void Palabra::setPalabra(const char* palabra){
			this->palabra = new char [99]; //buffer de la palabra porque la cantidad de caracteres es indeterminada
			int i = 0; //variable utilizada como contador 
			while(i < 99 && palabra[i]){ //while utilizado con el plan de salirse hasta que llegue al elemento /0 del puntero de char
				this->palabra[i] = palabra[i]; //le asigno uno por uno cada caracter 
				++i; //incremento del contador
			}
			this->palabra[i] = '\0'; //colocacion manual del elemento /0
			this->longitud = i; //asigno la longitud para saber con que tamayo trabajamos 
		}
		
		char* Palabra::getPalabra(){	
			return palabra; //metodo que me retorna el puntero a char de la clase 
		}
		
		int Palabra::getLongitud(){	
			return longitud; //me retorna la longitud total del puntero a char
		}
		
		std::ostream& Palabra::imprimir(std::ostream& salida){
			for(int i = 0; i < longitud; ++i){
				salida << palabra[i] << endl; // me imprime uno por uno cada caracter del puntero a char palabra
			}
			salida << "Con una frecuencia de: " << calcularCardinalidad() << endl;
			return salida; //retorna cout 
		}
		
		std::istream& Palabra::cargar(std::istream& entrada){
			entrada >> longitud; //carga la longitud de la palabra 
			palabra = new char[longitud];
			for(int i=0; i < longitud; ++i){
				entrada >> this->palabra[i]; //va cargando uno por uno cada caracter 
			}
			return entrada;	
		}

		double Palabra::calcularCardinalidad(){ 
			double count = 0.0; //contador de la cardinalidad total obtenida 
			int controlador = 0; //variable que me controla que accion tomar 
			if(palabra){ //entra si el puntero no es null
				string palabraAnalizar[longitud - 1]; //creo un vector a string para guardar en formato bigrama 
				string local = palabra; //paso el puntero a char a string para utilizar el metodo substr
				for(int i = 0; i < longitud - 1; ++i){
					palabraAnalizar[i] = local.substr(i,2); //corto el estring en bigramas
				}
				string buffer[25]; //creo un buffer para si ya agregue un tipo de combinacion no contarlo 2 veces
				for(int n = 0; n < 25; ++n){
					buffer[n] = "0"; //le inicializo todos las posiciones en 0
				}
				for(int i = 0; i < longitud - 1; ++i){
					for(int n = 0; n < 25; ++n){
						if(palabraAnalizar[i] == buffer[n]){ //si la palabra existe en el buffer le aviso al controlador para que no la vuelva a agregar
							controlador = 1;
						}
					}
					if(controlador == 0){ //si el controlador es iguala 0, en otras palabras que el bigrama aun no estaba en el buffer, aunmento el contador y inserto el bigrama en el buffer 
						buffer[i] = palabraAnalizar[i];
						++count;
					}
					controlador = 0; //la vuelvo cero de nuevo para repetir el proceso n veces 
				}			
				
			} 
			return count; //retorno el total de cardinalidad 
		}
			
		double Palabra::calcularInterseccion(Palabra* otra){ 
			double result = 0.0; //contador de los bigramas en comun
			string local1 = this->palabra; //paso la primer palabra a string para realizar el metodo substr
			string local2 = otra->palabra; //paso la segunda palabra a string para realizar el metodo substr
			string vector1[this->longitud - 1]; //vector en el cual voy a guardar los bigramas 
			string vector2[otra->longitud - 1]; //vector en el cual voy a guardar los bigramas
			for(int i = 0; i < this->longitud - 1; ++i){
				vector1[i] = local1.substr(i,2); //voy cortando el primer string en bigramas 
			}
			for(int i = 0; i < otra->longitud - 1; ++i){
				vector2[i] = local2.substr(i,2); //voy cortando el segundo string en bigramas
			}
			string buffer[25];//creo un buffer para almacenar las palabras en comun y no contar 2 veces la misma pareja
			for(int f = 0; f < 25; ++f){
				buffer[f] = "0"; //inicializo todas sus posiciones en 0
			}
			int controlador = 0; //variable con la que manejo por que camino trabajar 
			for(int i = 0; i < this->longitud - 1; ++ i){
				for(int n = 0; n < otra->longitud - 1; ++n){
					if(vector1[i] == vector2[n]){ //si su bigrama es igual 
						for(int f = 0; f < 25; ++f){
							if(buffer[f] == vector2[n]){ //pregunto si en el buffer ya la agregue 
								controlador = 1; //como ya la agregue cambio el controlador para no realizar nada 
							}
						}
						if(controlador == 0){ //si no la hubiera agregado al buffer, la agrego y aumento el result, que seria el contador de bigramas en comun
							buffer[i] = vector1[i];
							++result;
						}
						controlador = 0; //la vuelvo cero de nuevo para repetir el proceso n veces 
					}	
				}
			}
			return result; //retorno el contador de palabras en comun de forma existosa 
		}	
		
		
		