#include "Palabra.h"
#include <iostream>
#include <string.h> //libreria para poder utilizar los strings 
#include <fstream>
#include <stdio.h>
#include <ctype.h>

// ME SIGUEN DANDO PROBLEMAS ALGUNAS REFERENCIAS DE LOS METODOS VIRTUALES PUROS

using namespace std;

		//Constructor de la clase Palabra
		Palabra::Palabra(){
			palabra = new char[1];
			palabra[0] = '\0';
			longitud = 0;
			cout << "se entro al constructor por omision" << endl;
		}
		
		//Constructor por parametro de la clase Palabra
		Palabra::Palabra(const char* palabra){
			this->setPalabra(palabra);
			cout << "se entro al constructor por parametro" << endl;
		}
		
		//Constructor por copia de la clase Palabra
		Palabra::Palabra(const Palabra& otro){
			this->setPalabra(otro.palabra);
			cout << "se entro al constructor por copia" << endl;
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
		
		double Palabra::distancia(Elemento*){
			
			
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
			newPalabra[i] = '\0';
			Palabra palabra(newPalabra);
			return palabra;
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
			}
			int frecuenciaTotal = longitud - 1;
			for(int i = 0; i < longitud - 1; ++i){
				for(int n = 0; n < longitud - 1; ++n){
					if(i != n && palabraAnalizar[i] == palabraAnalizar[n]){
						--frecuenciaTotal; // aqui tengo un problema y es que si el par de string se repite se baja 2 veces y tiene que ser una vez 
											//	es porque se analiza por ejemplo "papa" con "papa" la primera "pa" se compara con la segunda se decrementa lo cual esta bien
											//  pero cuando pasa a la segunda "pa" y se compara con la primera se vuelve a decrementar no se como arreglarlo
					}
				}	
			}
			return frecuenciaTotal;
		}