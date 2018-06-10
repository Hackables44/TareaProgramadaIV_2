#include "Hilera.h"
#include "Elemento.h"
#include <math.h> /** para efectuar la raíz cuadrada */
#include <stdio.h> /** biblioteca que se importa de forma predeterminada */
#include <iostream> /** para realizar operaciones de entrada y salida */
using namespace std;

/** - constructor, inicializa la variable de tipo entero en 0, y los punteros en nulo */
Hilera::Hilera():length(0), palabrasDiferentes(0), frecuenciaPalabras(0){ }

/** - destructor, si los punteros son válidos, elimina el objeto al que apuntan (en este caso un vector) y pone la variable length en 0 */
Hilera::~Hilera(){
	/** si los punteros son válido, eliminan el objeto al que apuntan */
	if(palabrasDiferentes){
		delete [] palabrasDiferentes;
	}
	
	if(frecuenciaPalabras){
		delete [] frecuenciaPalabras;
	}
	
	/** limpio las variables, colocando el length en 0 y asignando valor nulo a cada puntero */
	length = 0;
	palabrasDiferentes = 0;
	frecuenciaPalabras = 0;
}
	
/** - devuelve un puntero a un objeto con los mismo datos que este objeto hilera */
Hilera * Hilera::clonar(){
	Hilera * ptrHilera= new Hilera(); /** crea un objeto en la memoria dinámica, y almacena su referencia por medio de un puntero */
	
	/** copia los datos */
	int length = this->getLength(); /** obtiene el length */
	ptrHilera->setLength(length); /** copia la cantidad de celdas de sus vectores (es la misma cantidad) */
	ptrHilera->setPalabrasDiferentes(this->palabrasDiferentes, length); /** copia las palabras del vector de strings de este objeto */
	ptrHilera->setFrecuenciaPalabras(this->frecuenciaPalabras, length); /** copia las frecuencias de palabras del vector de enteros de este objeto */
		
	/** devuelve el puntero del nuevo objeto */
	return ptrHilera;
}

/** - recibe un puntero a vector de string y la cantidad de celdas que posee */
void Hilera::setPalabras(string * palabras, int length){
	if(palabras){ /** si el puntero es válido */
		if(length){ /** si el length es un número positivo, muestra en pantalla la cantidad de celdas que tomará en cuenta */
			// cout << "Se indica que hay una cantidad de " << length << " celdas." << endl; /** imprime en pantalla el mensaje */ /** debugging */
			
			/** variables que tomarán las palabras filtradas de forma que las repetidas solo aumenten el vector de frecuencia */
			string auxString[length];
			int auxFrecuencia[length];
			int auxLength = length;
			
			/* El código de este método está probado */
			// cout << "Se declaran las variables auxiliares." << endl; /** debugging */
			
			/** inicializa el vector de strings con hileras vacías y el vector de frecuencias en 0 */
			for(int iAux=0; iAux<length; ++iAux){
				auxString[iAux] = "";
				auxFrecuencia[iAux] = 0;
			}
			// cout << "Se inciailizaron las variables auxiliares." << endl; /** debugging */
			
			/** analizará las celdas del vector recibido y guardará el vector auxiliar, las palabras sin que se repitan, solo aumentando su frecuencia */
			int iPalabras=0; /** índice del vector de palabras recibido como parámetro */
			int iAux=0; /** índice de los vectores auxiliares de palabra y su respectiva frecuencia */
			
			// cout << "A punto de recorrer el vector." << endl; /** debugging */
			
			/** recorre el vector recibido como parámetro "palabras" */
			while(iPalabras<length){ /** mientras el indice no supere la cantidad de "palabras" */
			// cout << "\n\niPalabras=" << iPalabras << endl; /** debugging */
			// cout << "Analiza celda: " << iAux << endl; /** debugging */
			// cout << "Palabra analizada: " << palabras[iPalabras] << "\tEn celda: " << auxString[iAux] << endl; /** debugging */
				/** Agrega palabras, aumenta frecuencia o sigue buscando en el vector auxiliar */
				if(auxString[iAux]==""){ /** si la celda está vacía */
					// cout << "Celda Vacia." << endl; /** debugging */
					auxString[iAux] = palabras[iPalabras]; /** guarde la palabra en la celda */
					// cout << "Asignado: " << auxString[iAux] << endl; /** debugging */
					++auxFrecuencia[iAux]; /** aumento en 1 la frecuencia de la palabra */
					// cout << "Frecuencia: " << auxFrecuencia[iAux] << endl; /** debugging */
					++iPalabras; /** analiza la siguiente palabra */
					iAux=0; /** reinicia el índice para analizar con la próxima palabra desde el principio del vector de palabras diferentes entre ambos vectores */
				}
				else{ /** si la celda ya tiene una hilera */
					// cout << "Celda con hilera." << endl; /** debugging */
					if(auxString[iAux]==palabras[iPalabras]){ /** si la palabras son iguales, si el string analizado es el mismo que está en la celda */
						--auxLength; /** resto el length, porque como una palabra ya se repite, se necesita una celda menos */
						// cout << "La palabra ya esta en la celda." << endl; /** debugging */
						++auxFrecuencia[iAux]; /** aumento en 1 la frecuencia de la palabra */
						// cout << "Frecuencia: " << auxFrecuencia[iAux] << endl; /** debugging */
						++iPalabras; /** analizará la siguiente palabra */
						iAux=0; /** reinicia el índice para analizar con la próxima palabra desde el principio del vector de palabras diferentes entre ambos vectores */
					}
					else{ /** si las palabras son diferentes */
						// cout << "La palabra en la celda es diferente." << endl; /** debugging */
						++iAux; /** aumenta en 1 el índice para analizar con la próxima palabra desde el principio del vector de palabras diferentes */
						// cout << "Analizar siguiente celda: " << iAux << endl; /** debugging */
					}
					
				}
				
				
				// if(iPalabras>3){
					// cout << "iPalabras=" << iPalabras << endl; /** debugging */
				// }
				
			}
			
			/** asigno los valores de los atributos */
			setLength(auxLength); /** asigno el valor al atributo que almacena la cantidad de celdas necesarias para guardas las palabras diferentes */
			setPalabrasDiferentes(auxString, auxLength); /** crea el vector con las palabras diferentes */
			setFrecuenciaPalabras(auxFrecuencia, auxLength);
			
		}
		else{ /** imprime en pantalla que se le indicó que analizara 0 cantidad de celdas */
			cerr << "Warning: El length del vector recibido es 0." << endl;
		}
	}
	else{ /** si el puntero es inválido, lo indica al usuario */
		cerr << "Warning: El puntero recibido no es valido." << endl;
	}
	
	
}

/** - establece el cantidad de celdas de los vectores de palabras y sus frecuencias; recibe un entero como parámetro */
void Hilera::setLength(int length){
	this->length = length; /** asigno el valor al atributo que almacena la cantidad de celdas necesarias para guardas las palabras diferentes */
}

/** - establece el vector de palabras diferentes por medio de un puntero a vector de string y su cantidad de celdas, el strign recibido lo pasa a minúscula */
void Hilera::setPalabrasDiferentes(string * palabrasDiferentes, int length){

	if(this->palabrasDiferentes){ /** si el vector atributo apunta a algo */
		delete [] this->palabrasDiferentes; /** elimina el objeto y devuelve la memoria previamente usada */
	}
	
	// intento de hacer aplicar un toLowerCase
	// /** variables utilizadas para pasar un string a letras minúsculas */
	// locale loc;
	// string palabra = "";
	// string palabraToLowerCase = "";
	
	// cout << "Asigna las diferentes palabras." << endl; /** Debugging */

	if(palabrasDiferentes){ /** si el puntero a las palabras es válido */
		this->palabrasDiferentes = new string[length]; /** creo un vector de strings con las celdas necesarias para guardar palabras no duplicadas y almaceno su puntero */
		for(int i=0; i<length; ++i){ /** recorre el vector */
		this->palabrasDiferentes[i]=palabrasDiferentes[i]; /** almacena la palabra en el atributo */
			// palabra=palabrasDiferentes[i]; /** almacena la palabra para pasarla a minúscula */
			// for(std::string::size_type c=0; c<length; ++c){ /** recorre sus caracteres */ /** se colocan los operadores de resolución de ámbito para saber de donde proviene la variable */
				// palabraToLowerCase+=tolower(palabra[c],loc); /** concatena el caracter en minúscula a la hilera "palabraToLowerCase" */
			// }
			
			// this->palabrasDiferentes[i]=palabraToLowerCase; /** asigna la palabra en minúscula */
			
		}
	}
	else{ /** si es inválido imprime un mensaje */
		cerr << "Warning: El puntero ingresado es invalido." << endl;
	}
	
}

/** - establece el vector de palabras diferentes por medio de un puntero a vector de entero y su cantidad de celdas */
void Hilera::setFrecuenciaPalabras(int * frecuenciaPalabras, int length){
	if(this->frecuenciaPalabras){ /** si el vector atributo apunta a algo */
		delete [] this->frecuenciaPalabras; /** elimina el objeto y devuelve la memoria previamente usada */
	}
	
	if(frecuenciaPalabras){ /** si el puntero a las frecuencias es válido */
		this->frecuenciaPalabras = new int[length]; /** creo un vector de enteros con las celdas necesarias para guardar la frecuencia de las palabras y almaceno su puntero */
		for(int i=0; i<length; ++i){ /** recorre el vector */
			this->frecuenciaPalabras[i]=frecuenciaPalabras[i]; /** asigna las frecuencias */
		}
	}
	else{ /** si es inválido imprime un mensaje */
		cout << "Warning: El puntero ingresado es invalido." << endl;
	}
	
}

/** - devuelve el length del vector, que representa la cantidad de palabras diferentes */
int Hilera::getLength(){
	return length; /** devuelve el atributo length */
}

/** - método sobrecargado que invoca la función getFrecuencia, pasandole el índice para buscar la frecuencia en el vector de enteros */
int Hilera::operator[](int indice){
	return getFrecuencia(indice); /** devuelve el número que representa la frecuencia determinada para una palabra de acuerdo a la posición del vector de strings */
}

/** - función que obtiene la frecuencia de la palabra almacenada en un vector de enteros en la posición indicada que en el vector de strings */
int Hilera::getFrecuencia(int indice){ /** recibe el índice con el cual buscar */
	int frecuencia = 0; /** declaro e inicializo la variable local que almacenará el valor de frecuencia de la palabra */
	
	if(palabrasDiferentes){ /** si el puntero a las palabras es válido, no es nulo */
	
		if(frecuenciaPalabras){ /** si el puntero a la frecuencia de palabras existe */
		
			if( indice>=0 && indice<length ){ /** si el índice recibido como parámetro está en el rango del vector */
				frecuencia = frecuenciaPalabras[indice]; /** almacena el valor de la celda con el indice recibido */
			}
			else{
				/** si el índice se sale del rango del vector, muestra un mensaje de error en pantalla */
				cerr << "El rango del vector es de 0 a " << length << ", el indice ingresado fue " << indice << "." << endl;
			}
			
		}
		else{
			/** indica al usuario que no hay un vector de frecuencias asignado */
			cerr << "No hay vector de frecuancia de palabras (int) asignado. Devuelve 0 por omision." << endl;
		}
		
	}
	else{
		/** indica al usuario que no hay un vector de strings asignado */
		cerr << "No hay vector de palabras (strings) asignado. Devuelve 0 por omision." << endl;
	}
	
	return frecuencia; /** devuelve el valor de la celda, o en su defecto 0 */
}

/** - función que obtiene la palabra almacenada en un vector strings en la posición indicada por medio de la entrada "indice" */
string Hilera::getPalabra(int indice){ /** recibe el índice con el cual buscar */
	string palabra = ""; /** declaro e inicializo la variable local que almacenará la palabra de la celda del vector */
	
	if(palabrasDiferentes){ /** si el puntero a las palabras es válido, no es nulo */
		
		if( indice>=0 && indice<length ){ /** si el índice recibido como parámetro está en el rango del vector */
			palabra = palabrasDiferentes[indice]; /** almacena la palabra en la celda del vector de strings */
		}
		else{
			/** si el índice se sale del rango del vector, muestra un mensaje de error en pantalla */
			cerr << "El rango del vector es de 0 a " << length << ", el indice ingresado fue " << indice << "." << endl;
		}
		
	}
	else{
		/** indica al usuario que no hay un vector de strings asignado */
		cerr << "No hay vector de palabras (strings) asignado. Devuelve "" (una hilera vacia) por omision." << endl;
	}
	
	return palabra; /** devuelve el valor de la celda, o en su defecto "" (una hilera vacia) */
}


/** - calcula la distancia entre ambos vectores restandole a 1 la similitud coseno obtenido entre ambos vectores */
double Hilera::distancia(Elemento * otro){ /** recibe un puntero a Elemento */
	/** si al puntero recibido se le puede aplicar un casting dinámico a puntero de vector, lo que indica que si apunta a un objeto Hilera
		devuelve ese puntero convertido, pero si no es un objeto Hilera, devuelve 0 (como false)*/
	// cout << "Entra al metodo distancia " << endl; /** debugging */
	Hilera * hilera2 = dynamic_cast<Hilera *>(otro);
	double distancia = 1.0; /** inicializamos la distancia en 1.0 (tomando de forma predeterminada que son completamente diferentes) */
	
	if(hilera2){ /** si el puntero a la segunda hilera es válido */
		// cout << "El puntero hilera2 es valido. " << endl; /** debugging */
		distancia = 1-similitudCoseno(hilera2); /** asigna el valor obtenido de restar, a 1, la similitud coseno con el otro vector de palabras */
	}
	else{ /** si el puntero es inválido, lo indica en pantalla */
		cerr << "Warning: El puntero recibido es invalido." << endl;
	}
	cout << "distancia: " << distancia << endl;
	return distancia;
}

/** - Este método calcula la similitud que existe entre 2 vectores */
double Hilera::similitudCoseno(Hilera * hilera2){
	// cout << "Entra al metodo similitudCoseno " << endl; /** debugging */
	double productoPunto = calcularProductoPunto(hilera2); /** invoca al método que calcula el producto punto ambos vectores y almacena el resultado */
	cout << "Producto Punto: " << productoPunto << endl;
	double normaV1 = calcularNorma(this); /** almacena la norma del primer vector */
	cout << "NormaHilera1: " << normaV1 << endl;
	double normaV2 = calcularNorma(hilera2); /** almacena la norma del segundo vector */
	cout << "NormaHilera2: " << normaV2 << endl;
	double productoDeNormas = normaV1*normaV2; /** almacena la multiplicación de ambas normas obtenidas */
	cout << "Producto de ambas normas: " << productoDeNormas << endl;
	double coseno = productoPunto/productoDeNormas; /** efectua la división para calcular el coseno */
	cout << "Coseno: " << coseno << endl;
	return coseno; /** devuelve el coseno obtenido */
}

/** - Calcula y devuelve el producto punto de 2 vectores de palabras */
double Hilera::calcularProductoPunto(Hilera * hilera2){ /** Recibe los punteros de los vectores. */
	// cout << "Entra al metodo calcularProductoPunto. " << endl; /** debugging */
	double productoPunto = 0.0; /** Variable que almacenará el producto punto de los 2 vectores */

	int lengthV1 = this->getLength(); /** Almacena el length del primer vector */
	int lengthV2 = hilera2->getLength(); /** Almacena el length del segundo vector */
	int lengthTotal = lengthV1+lengthV2;
	
	/** en este caso no se necesita la comprobación del length de los vectores, los homogenizaremos */
	/** calcula las celdas necesarias para hacer un vector con las palabras diferentes */
	
	/** crea el vector de palabras diferentes y el sus frecuencias respectivas para las 2 hileras comparadas */
	/** variables locales necesarias para filtrar las palabras repetidas, inciamos tomando la posibilidad en que todas sean diferentes */
	string auxStringTotal[lengthTotal];
	int auxFrecuenciaTotalV1[lengthTotal];
	int auxFrecuenciaTotalV2[lengthTotal];
	
	/** inicializa el los vectores auxiliares de frecuencia en 0 */
	for(int i=0; i<lengthTotal; ++i){
		auxFrecuenciaTotalV1[i] = 0;
		auxFrecuenciaTotalV2[i] = 0;
	}
			
	/** inicializa el tercer vector de strings con hileras vacías */
	for(int i=0; i<lengthTotal; ++i){
		auxStringTotal[i] = "";
	}
	
	/** analizará las celdas del vector de palabras de este objeto Hilera y del otro recibido como parámetro. Guardará en un tercer vector, las palabras sin que se repitan */
	int iHilera1=0; /** índice del vector de palabras 1 (el de este objeto hilera) */
	int iHilera2=0; /** índice del otro vector de palabras 2 (el objeto recibido como parámetro) */
	int iAuxTotal=0; /** índice que servirá para recorrer el vector interno */
	
	/** Procesa el primer vector */
	// cout << "\nProcesa el primer vector" << endl; /** debugging */
	while(iHilera1<lengthV1){ /** mientras el indice no supere la cantidad de "palabras" */
		// cout << "\n\niPalabras=" << iHilera1 << endl; /** debugging */
		// cout << "Analiza celda: " << iAuxTotal << endl; /** debugging */
		// cout << "Palabra analizada: " << this->getPalabra(iHilera1) << "\tEn celda: " << auxStringTotal[iAuxTotal] << endl; /** debugging */
		/** Agrega palabras, aumenta frecuencia o sigue buscando en el vector auxiliar */
		if(auxStringTotal[iAuxTotal]==""){ /** si la celda está vacía */
			// cout << "Celda Vacia." << endl; /** debugging */
			auxStringTotal[iAuxTotal] = this->getPalabra(iHilera1); /** guarde la palabra en la celda */
			// cout << "Asignado: " << auxStringTotal[iAuxTotal] << endl; /** debugging */
			auxFrecuenciaTotalV1[iAuxTotal] = (*this)[iHilera1]; /** asigno la frecuencia que ya tengo de la palabra */
			// cout << "Frecuencia: " << auxFrecuenciaTotalV1[iAuxTotal] << endl; /** debugging */
			++iHilera1; /** analiza la siguiente palabra */
			iAuxTotal=0; /** reinicia el índice para analizar con la próxima palabra desde el principio del vector de palabras diferentes entre ambos vectores */
		}
		else{ /** si la celda ya tiene una hilera */
			// cout << "Celda con hilera." << endl; /** debugging */
			if(auxStringTotal[iAuxTotal]==this->getPalabra(iHilera1)){ /** si la palabras son iguales, si el string analizado es el mismo que está en la celda */
				--lengthTotal; /** resto el length, porque como una palabra ya se repite, se necesita una celda menos */
				// cout << "La palabra ya esta en la celda." << endl; /** debugging */
				auxFrecuenciaTotalV1[iAuxTotal] = (*this)[iHilera1]; /** asigno la frecuencia que ya tengo de la palabra */
				// cout << "Frecuencia: " << auxFrecuenciaTotalV1[iAuxTotal] << endl; /** debugging */
				++iHilera1; /** analizará la siguiente palabra */
				iAuxTotal=0; /** reinicia el índice para analizar con la próxima palabra desde el principio del vector de palabras diferentes entre ambos vectores */
			}
			else{ /** si las palabras son diferentes */
				// cout << "La palabra en la celda es diferente." << endl; /** debugging */
				++iAuxTotal; /** aumenta en 1 el índice para analizar con la próxima palabra desde el principio del vector de palabras diferentes */
				// cout << "Analizar siguiente celda: " << iAuxTotal << endl; /** debugging */
			}		
		}	
	}
	
	/** Procesa el segundo vector */
	// cout << "\nProcesa el segundo vector" << endl; /** debugging */
	iAuxTotal=0; /** índice que servirá para recorrer el vector interno */
	
	while(iHilera2<lengthV2){ /** mientras el indice no supere la cantidad de "palabras" */
		// cout << "\n\niPalabras=" << iHilera2 << endl; /** debugging */
		// cout << "Analiza celda: " << iAuxTotal << endl; /** debugging */
		// cout << "Palabra analizada: " << hilera2->getPalabra(iHilera2) << "\tEn celda: " << auxStringTotal[iAuxTotal] << endl; /** debugging */
		/** Agrega palabras, aumenta frecuencia o sigue buscando en el vector auxiliar */
		if(auxStringTotal[iAuxTotal]==""){ /** si la celda está vacía */
			// cout << "Celda Vacia." << endl; /** debugging */
			auxStringTotal[iAuxTotal] = hilera2->getPalabra(iHilera2); /** guarde la palabra en la celda */
			// cout << "Asignado: " << auxStringTotal[iAuxTotal] << endl; /** debugging */
			auxFrecuenciaTotalV2[iAuxTotal] = (*hilera2)[iHilera2]; /** asigno la frecuencia que ya tengo de la palabra */
			// cout << "Frecuencia: " << auxFrecuenciaTotalV2[iAuxTotal] << endl; /** debugging */
			++iHilera2; /** analiza la siguiente palabra */
			iAuxTotal=0; /** reinicia el índice para analizar con la próxima palabra desde el principio del vector de palabras diferentes entre ambos vectores */
		}
		else{ /** si la celda ya tiene una hilera */
			// cout << "Celda con hilera." << endl; /** debugging */
			if(auxStringTotal[iAuxTotal]==hilera2->getPalabra(iHilera2)){ /** si la palabras son iguales, si el string analizado es el mismo que está en la celda */
				--lengthTotal; /** resto el length, porque como una palabra ya se repite, se necesita una celda menos */
				// cout << "La palabra ya esta en la celda." << endl; /** debugging */
				auxFrecuenciaTotalV2[iAuxTotal] = (*hilera2)[iHilera2]; /** asigno la frecuencia que ya tengo de la palabra */
				// cout << "Frecuencia: " << auxFrecuenciaTotalV2[iAuxTotal] << endl; /** debugging */
				++iHilera2; /** analizará la siguiente palabra */
				iAuxTotal=0; /** reinicia el índice para analizar con la próxima palabra desde el principio del vector de palabras diferentes entre ambos vectores */
			}
			else{ /** si las palabras son diferentes */
				// cout << "La palabra en la celda es diferente." << endl; /** debugging */
				++iAuxTotal; /** aumenta en 1 el índice para analizar con la próxima palabra desde el principio del vector de palabras diferentes */
				// cout << "Analizar siguiente celda: " << iAuxTotal << endl; /** debugging */
				}
					
		}	
	}
	
	/** Imprime en pantalla lo que hay en los vectores */
	
	cout << "Imprime en pantalla lo que hay en los vectores." << endl; /** debugging */
	
	cout << "Palabras diferentes totales: " << endl;
	cout << "{";
	for(int i=0; i<lengthTotal; ++i){
		cout << " " << auxStringTotal[i];
	}
	cout << " }" << endl;
	
	cout << "Frecuencia del primer vector: " << endl;
	cout << "{";
	for(int i=0; i<lengthTotal; ++i){
		cout << " " << auxFrecuenciaTotalV1[i];
	}
	cout << " }" << endl;
	
	cout << "Frecuencia del segundo vector: " << endl;
	cout << "{";
	for(int i=0; i<lengthTotal; ++i){
		cout << " " << auxFrecuenciaTotalV2[i];
	}
	cout << " }" << endl;	
	
	cout << endl << endl;
	
	/** Procede a calcular el producto punto de las frecuencias de palabras de cada hilera */
	for(int i=0; i<lengthTotal; ++i){ /** Recorre ambos vectores */
		//double d = 1.0;
		//cout << d << endl;
		//cout << "valores1:" << valores[i] << " valores2: " << vector2->getValor(i) << endl;
		productoPunto += auxFrecuenciaTotalV1[i]*auxFrecuenciaTotalV2[i]; /** almacena (sumando) el producto de los valores en ambas celdas */
	}
	
	return productoPunto; /** Devuelve el producto punto de los vectores o en su defecto 0.0 */
}

/** - Calcula la norma del vector recibido como parámetro, recibe */
double Hilera::calcularNorma(Hilera * hilera){ /** recibe el puntero del vector al cual calcular la norma */
	/** declaración de las variables locales a utilizar */
	double raizCuadrada = 0.0; /** almacenará la raíz cuadrada, para calcular la norma del vector*/
	int sumaCuadrados = 0; /** almacenará la suma de los cuadrados de los números en la celda del vector si hay */
	int frecuencia = 0; /** almacena temporalmente el valor de frecuencia de la celda tipo int */
	int length = hilera->getLength(); /** almacena el length del vector */
	
	for(int i=0; i<length; ++i){ /** recorre el vector de frecuencia de las palabras */
		frecuencia = hilera->getFrecuencia(i); /** obtiene la frecuencia de alguna palabra */
		sumaCuadrados += (frecuencia*frecuencia); /** almacena el cuadrado del número, se multiplica el int por sí mismo */
	}
	
	raizCuadrada = sqrt(sumaCuadrados); /** calcula y almacena la raíz cuadrada del total de los números obtenidos elevados a la 2 */
	return raizCuadrada; /** Devuelve la norma obtenida */
}

/** - recibe como parámetro un objeto para salida de flujo, y así imprime las palabras que almacena el vector y sus respectivas frecuencias */
ostream & Hilera::imprimir(ostream & salida){
	salida << "Palabras:\t{";
	/** indice para recorrer el vector y así imprimir las palabras */
	for(int i=0; i<length ; ++i){
		if(0!=i){
			salida << "\t";
		}
		salida << this->getPalabra(i); /** imprime la palabra que le devuelve la función */
	}
	salida << " }" << endl;
	
	/** indice para recorrer el vector y así imprimir las frecuencias */
	salida << "Frecuencias:\t{";
	for(int i=0; i<length ; ++i){
		if(0!=i){
			salida << "\t";
		}
		salida << (*this)[i];/** imprime la frecuencia que le devuelve la función get con el método sobrecargado[] */
		
	}
	salida << " }" << endl;
	return salida;
}

/** - recibe como entrada el objeto ifstream que contiene los bytes del archivo cargado de hileras */
istream & Hilera::cargar(istream & entrada){
	int length = 0; /** declaro la variable length y la inicializo en 0 */
	entrada >> length; /** guardo el length del vector */
	string * vectorDeHileras = new string[length]; /** genero un vector en el stack/pila */
	
	for(int i=0; i<length; ++i){ /** recorre el vector */
		entrada >> vectorDeHileras[i]; /** asigno las palabras al vector */
	}
	
	// Hilera * ptr = &vectorDeHileras;
	setPalabras(vectorDeHileras, length);/** invoco al método para asignar valores al atributo vector de palabras */
	
	return entrada; /** devuelvo el objeto, podría aún necesitarse si aún contiene los flujos de bytes para otro objetos de tipo Hilera */
}