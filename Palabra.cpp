#include "Palabra.h"
#include <iostream>
#include <string.h> //libreria para poder utilizar los strings 
#include <fstream>
#include <stdio.h>
#include <ctype.h>


using namespace std;

		//Constructor de la clase Palabra
		Palabra::Palabra(){
			palabra = 0;
			longitud = 0;
		}
		
		//Constructor por parametro de la clase Palabra
		Palabra::Palabra(const char* palabra){
			this->setPalabra(palabra);
		}
		
		//Constructor por copia de la clase Palabra
		Palabra::Palabra(const Palabra& otro){
			this->setPalabra(otro.palabra);
		}
		
		Palabra::~Palabra(){
			if(palabra){
				delete palabra;
				palabra = 0;
			}
		}
		
		Palabra* Palabra::clonar(){
			Palabra* palabraPtr = new Palabra(this->palabra);
			return palabraPtr;
		}
		
		//Sobrecarga del operador == para ver si la palabra ya existe o no, 0 es false y cualquier otro numero es true
		int Palabra::operator==(const Palabra& otro){
			int result = 0;
			if(strcmp(palabra,otro.palabra) != 0){
				cout << "son diferentes" << endl;
			}
			else{
				cout << "son iguales" << endl;
			}
			return result;
		}
		
		double Palabra::distancia(Elemento* otro){ // En si ya este metodo esta completo no se porque....
			double distanciaDeBiagramas = 1.0;
			Palabra* local1 = dynamic_cast<Palabra*>(otro);
			distanciaDeBiagramas = 1 - ((2 * this->calcularInterseccion(local1)) / (this->calcularCardinalidad() + local1->calcularCardinalidad()));
			//sigo sin saber porque lo de arriba no me da double pero ya los metodos se supone que estan bien 
			return distanciaDeBiagramas;	
		}
		
		//Sobrecarga del operador + que en este caso lo usaremos para concatenar Palabras
		Palabra Palabra::operator+(Palabra& otro){
			int newLongitud = this->getLongitud() + otro.getLongitud();
			char* newPalabra = new char[newLongitud];
			int i = 0;
			while(this->palabra[i]){
				newPalabra[i] = this->palabra[i];
				++i;
			}
			int lengthLocal = i;
			i = 0;
			while(otro.palabra[i]){
				newPalabra[lengthLocal] = otro.palabra[i];
				++i;
				++lengthLocal;
			}
			newPalabra[lengthLocal] = '\0';
			return newPalabra;
		}
		
		//Sobrecarga del operador = para asignar una palabra a otra
		Palabra& Palabra::operator=(const Palabra& otro){
			this->setPalabra(otro.palabra);
			return *this;	
		}
		

		void Palabra::setPalabra(const char* palabra){
			this->palabra = new char [99];
			int i = 0;
			while(i < 99 && palabra[i]){
				this->palabra[i] = palabra[i];
				++i;
			}
			this->palabra[i] = '\0';
			this->longitud = i;
		}
		
		char* Palabra::getPalabra(){	
			return palabra;
		}
		
		int Palabra::getLongitud(){	
			return longitud;
		}
		
		std::ostream& Palabra::imprimir(std::ostream& salida){
			for(int i = 0; i < longitud; ++i){
				salida << palabra[i] << endl;
			}
			salida << "Con una frecuencia de: " << calcularCardinalidad() << endl;
			return salida;
		}
		
		std::istream& Palabra::cargar(std::istream& entrada){
			entrada >> longitud;
			palabra = new char[longitud];
			for(int i=0; i < longitud; ++i){
				entrada >> this->palabra[i];
			}
			return entrada;	
		}

		double Palabra::calcularCardinalidad(){ 
			double count = 0.0;
			int controlador = 0;
			if(palabra){
				string palabraAnalizar[longitud - 1];
				string local = palabra;
				for(int i = 0; i < longitud - 1; ++i){
					palabraAnalizar[i] = local.substr(i,2);
				}
				string buffer[25];
				for(int n = 0; n < 25; ++n){
					buffer[n] = "0";
				}
				for(int i = 0; i < longitud - 1; ++i){
					for(int n = 0; n < 25; ++n){
						if(palabraAnalizar[i] == buffer[n]){
							controlador = 1;
						}
					}
					if(controlador == 0){
						buffer[i] = palabraAnalizar[i];
						++count;
					}
					controlador = 0;
				}			
				
			} 
			return count;
		}
			
		double Palabra::calcularInterseccion(Palabra* otra){ 
			double result = 0.0;
			string local1 = this->palabra;
			string local2 = otra->palabra;
			string vector1[this->longitud - 1];
			string vector2[otra->longitud - 1];
			for(int i = 0; i < this->longitud - 1; ++i){
				vector1[i] = local1.substr(i,2);
			}
			for(int i = 0; i < otra->longitud - 1; ++i){
				vector2[i] = local2.substr(i,2);
			}
			string buffer[25];
			for(int f = 0; f < 25; ++f){
				buffer[f] = "0"; 
			}
			int controlador = 0;
			for(int i = 0; i < this->longitud - 1; ++ i){
				for(int n = 0; n < otra->longitud - 1; ++n){
					if(vector1[i] == vector2[n]){
						for(int f = 0; f < 25; ++f){
							if(buffer[f] == vector2[n]){
								controlador = 1;
							}
						}
						if(controlador == 0){
							buffer[i] = vector1[i];
							++result;
						}
						controlador = 0;
					}	
				}
			}
			return result;
		}	
		
		
		