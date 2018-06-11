/** Clase Abstracta Fabrica */

#ifndef _FABRICA_ABSTRACTA
#define _FABRICA_ABSTRACTA
#include <cstring>
#include "Producto.h"
class Fabrica {
	protected:
	/** - variables protegidas que heredan las clases derivadas, almacenan el nombre y tipo de producto hecho en la fábrica */
	   char  * nombreProducto;
	   char  * tipoProducto;
	   
	private:
	/** - método utilizado por la funciones set para inicializar ambos atributos "nombreProducto" y "tipoProducto", según sea el caso */
	   void _initHilera(char ** atributoPtr, const char * nombre){ /** Recibe referencia a un puntero de char (es un puntero de puntero) y un literal string */
			/** si ya hay un literal, lo elimina*/
		      if(*atributoPtr){
			      delete [] *atributoPtr;
		      }
			  /** Almacena la longitud del literal recibido, más 1 (porque agregaremos el caracter nulo, que es bandera de fin en la hilera) */
	          int tamanyo = strlen(nombre)+1;
			  /** al puntero al atributo le asignamos un vector de caracteres con el tamaño anterios calculado como length */
			  *atributoPtr = new char [tamanyo];
			  /** el método strcopy recibe como parámetros el puntero a char al que copiará y luego el literal string recibido "nombre" */
		      strcpy(*atributoPtr,nombre);
			  /** Al la última celda del vector de caracteres le asigna el valor nulo */
			  (*atributoPtr)[tamanyo-1]='\0';
	   }

	public:
	   
	   /** - función set para asignar una cadena de caracteres que representa al tipo del producto
	   asigna el literal recibido a "tipoProducto" y si está vacío, asigna "SIN_TIPO"; lo hace utilizando el método _init(char ** atributoPtr, const char * nombre)*/
	   void setTipoProducto(const char * nombre){ /** recibe como parámetro una cadena de caracteres que representa el tipo del producto */
		   if(nombre){ /** si nombre es válido */
				/** le pasa al método "_initHilera" la referencia del puntero a char "tipoProducto" y el literal recibido */
			   _initHilera(&(this->tipoProducto),nombre);
		   }
		   else { /** si es vacío */
				/** en vez de pasar el literal, pasa la hilera "SIN_TIPO" */
			   _initHilera(&(this->tipoProducto),"SIN_TIPO");
		   }
	   }
	   
	   	/** - función set para asignar una cadena de caracteres que representa al nombre del producto
		asigna el literal recibido a "nombreProducto" y si está vacío, asigna "SIN_NOMBRE"; lo hace utilizando el método _init(char ** atributoPtr, const char * nombre)*/
	   void setNombreProducto(const char * nombre){ /** recibe como parámetro una cadena de caracteres que representa el nombre del producto */

		   if(nombre){ /** recibe como parámetro una cadena de caracteres que representa el nombre del producto */
				/** le pasa al método "_initHilera" la referencia del puntero a char "nombreProducto" y el literal recibido */
			   _initHilera(&(this->nombreProducto),nombre);
		   }
		   else { /** si es vacío */
				/** en vez de pasar el literal, pasa la hilera "nombreProducto" */
			   _initHilera(&(this->nombreProducto),"nombreProducto");
		   }
	   }	
	   
	   /** - constructor de la clase Fabrica
			inicializa los atributos en null, y hace pase por copia de los literales string recibidos como parámetros a los métodos respectivos
			para establecer las cadenas que representa nombre y tipo de producto */
	   Fabrica(const char * tipoProducto, const char * nombreProducto){ /** recibe 2 literales que representan el tipo y nombre del producto */
			/** incializa los puntero a char en nulo */
		   this->tipoProducto = 0;
		   this->nombreProducto = 0;
		   /** funciones set para establecer el nombre y tipo de producto */
           this->setNombreProducto(nombreProducto);
		   this->setTipoProducto(tipoProducto);
	   }
	   
	   /** - Destructor de la clase Fábrica
		Verifica si el puntero a char "nombreProducto" es válido, elimina el literal string. Deigual forma con el atributo "tipoProducto"
	   */
	   virtual ~Fabrica(){
		   if(nombreProducto){
  		      delete [] nombreProducto;
		   }
		   if(tipoProducto){
  		      delete [] tipoProducto;
		   }
	   }

	   /** - Devuelve el literal que corresponde al nombre del producto */
	   virtual const char * getNombreProducto(){
		   return nombreProducto; /** Devuelve el atributo nombreProducto */
	   }
		
		/** - Devuelve el literal que corresponde al tipo del producto */
	   virtual const char * getTipoProducto(){
		   return tipoProducto; /** Devuelve el atributo tipoProducto */
	   }
	   
	   /** - Método virtual puro que se encarga de crear objetos de sus clases derivadas, le deja la implementación a estas últimas */
   	   virtual Producto * producir()=0;
	   
	   /** - Método que devuelve falso(0) o verdadero(entero diferente de 0), indicando si produce un producto que tiene como nombre el literal recibido */
	   virtual int produce(const char * nombreProducto){
		   /** verifica si el nombre del objeto producido en ésta fábrica es igual al recibido como parámetro*/
		   return strcmp(this->nombreProducto,nombreProducto)==0;
		   /** strcomp devuelve 0 si los 2 literales son iguales */
	   }
	   
	   /** - Método que devuelve falso(0) o verdadero(entero diferente de 0), indicando si produce un producto que tiene como tipo literal recibido */
	   virtual int esTipo(const char * tipoProducto){
		   /** verifica si el tipo del objeto producido en ésta fábrica es igual al recibido como parámetro*/
		   return strcmp(this->tipoProducto,tipoProducto)==0;
	   }	   

};

#endif
