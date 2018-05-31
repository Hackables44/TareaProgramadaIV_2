#include "Fabrica.h"
#define MAXIMO 100  // SOLO PUEDEN CAMBIAR 

// DEBE HABER UN .H PARA CADA FABRICA 3 DE CADA TIPO
// Por cada Fabrica que implementen deben incluir su .h 
// #include "FabricaVectorEC.h"
// #include "FabricaHilera_OPCIONAL_INICIALES.h"
// #include "FabricaPalabra_INICIALES.h"
// #include "FabricaHAC_INICIALES.h"
// #include "FabricaKMeans_INICIALES.h"
// #include "FabricaAgrupador_HAPPYFACE_INICIALES.h"
// #include "FabricaSVG_INICIALES.h"
// #include "FabricaXML_INICIALES.h"
// #include "FabricaJSON_INICIALES.h"

/** - Función que recibe un puntero a Fabrica y lo agrega al atributo "fabricas" (vector con punteros a instancias de Fabrica)
	si la cantidad de fabricas es menor que el máximo de fábricas, agrega el puntero  */
void ZonaFranca::agregar(Fabrica * fabrica){ /** Recibe un puntero a Fabrica */
	/** si la cantidad de fábricas es menor que la cantidad máxima de fábricas */
	if(cantidadDeFabricas < MAXIMO){
		/** Agregue la fabrica al vector */
       fabricas[cantidadDeFabricas++]= fabrica;
	   /** Ojo con el toque, el posincremento aumenta en 1 (cambia el estado de la variable) y devuelve el estado de la variable antes de sumarle 1. */
	}
}

/** - Constructor de la clase ZonaFranca
	Asigna un vector de punteros al (atributo "fabricas") puntero de punteros objetos Fabrica
	Inicializa los punteros de fabrica y "cantidadDeFabricas" en 0 */
ZonaFranca::ZonaFranca(){
	/** Al puntero de punteros de Fabrica le asigno un vector de punteros Fabrica de length MAXIMO */
	fabricas = new Fabrica * [MAXIMO];
	/** Inicializa en 0 los punteros del vector "fabricas" */
	for(int i=0;i<MAXIMO; ++i){
		fabricas[i]=0;
	}
	/** Inicializo la cantidad de fábricas en 0 */
	cantidadDeFabricas=0;
	// SI HAY MAS QUE LO QUE INDICA EL VALOR "MAXIMO" DEBE AUMENTARLO EN EL .H
    // USTED AGREGAR INSTANCIAS DE FABRICA ESPECIFICAS 
	//agregar(new FabricaVectorEC());
	//agregar(new FabricaHAC());
	//agregar(new FabricaSVG());
	// 3 Fabricas de Elemento
	// 3 Fabricas de Agrupador
	// 3 Fabricas de Visualizador
	
}

/** - Destructor de la clase ZonaFranca
	Elimina las instancias de Fabrica y elimina el vector al que apunta el atributo "fabrica" */
ZonaFranca::~ZonaFranca(){
	/** Recorre el vector asignado a "fabricas" para eliminar todas las instancias de Fabrica */
	for(int i=0; i< cantidadDeFabricas;++i){
		delete fabricas[i];
	}
	/** Elimina el vector con punteros a objetos Fabrica */
	delete [] fabricas;
}

/** - Función get que devuelve un puntero a instancia de Fabrica
	Recibe como parámetros 2 literales string que corresponden al tipo y nombre, busca si en el (atributo) vector de instancias Fabrica
	está la fábrica de tipo y nombre recibidos, devuelve un puntero a Fabrica */
Fabrica * ZonaFranca::getFabrica(const char * tipo, const char * nombre){ /** Recibe como parámetro 2 literales string */
	int i=0; /** Declaro e inicializo una variable local "i" de tipo entero */
	Fabrica * fabricaRetornada = 0; /** Declaro e inicializo en nulo un puntero a instancias de Fabrica llamado "fabricaRetornada" */
	/** Mientras el puntero sea nulo e "i" sea menor que la cantidad de fábricas:
		Si la fábrica en la posición "i" en el vector de fábricas tiene el tipo y nombre recibidos como parámetro lo asigna al puntero
		y finalmente lo devuelve */
	while(!fabricaRetornada && i< cantidadDeFabricas){
		if(fabrica[i]->esDeTipo(tipo) && fabrica[i]->produce(nombre)){
			fabricaRetornada = fabrica[i];			
		}
        ++i;
	}	
	return fabricaRetornada;
}
