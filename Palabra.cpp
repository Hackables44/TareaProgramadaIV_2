#include "Palabra.h"
#include <iostream>
#include <string.h> //libreria para poder utilizar los strings 
#include <fstream>
#include <stdio.h>
#include <ctype.h>


using namespace std;

		//Constructor de la clase Palabra
		Palabra::Palabra(){
			palabra = new char[1];
			palabra[0] = '\0';
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
			double distanciaDeBiagramas = 0.0;
			Palabra* local1 = dynamic_cast<Palabra*>(otro);
			distanciaDeBiagramas = 1 - /* esto no agarra valor decimal y le es restado a 1 si si estan llegando los valores necesarios arriba y abajo */ (((2 * this->calcularInterseccion(local1)) / (this->calcularCardinalidad() + local1->calcularCardinalidad())));
			cout << distanciaDeBiagramas;  //no se porque no imprime un double.... .-.
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

		int Palabra::calcularCardinalidad(){ 
				string palabraAnalizar[longitud - 1];
				string local = palabra;
				for(int i = 0; i < longitud - 1; ++i){
					palabraAnalizar[i] = local.substr(i,2);
					cout << palabraAnalizar[i] << endl;
				}
				int count = 0;
				string buffer[longitud - 1];
				for(int i = 0; i < longitud - 1; ++i){
					for(int n = 0; n < longitud - 1 && palabraAnalizar[i] != palabraAnalizar[n] && buffer[n] != palabraAnalizar[n]; ++n){
						++count;
						buffer[i] = palabraAnalizar[i];
					}
				}
				return count + 1; //sinceramente no se porque pero para que de bien tiene que estar ese +1
			} 
			
		int Palabra::calcularInterseccion(Palabra* otra){ 
			int result = 0;
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
			int controlador = 0;
			for(int i = 0; i < this->longitud; ++ i){
				for(int n = 0; n < otra->longitud; ++n){
					if(vector1[i] == vector2[n]){
						buffer[i] = vector1[i];
						for(int f = 0; f < 25; ++f){
							if(buffer[f] == vector1[n] && controlador == 0 ){
								++result;
								controlador = 1;
							}
						}
						controlador = 0;
					}	
				}
			}
			return result;
		}	
		
