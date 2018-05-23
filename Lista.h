#ifndef _ListaPolimorfica
#define _ListaPolimorfica
#include<iostream>
#include "Elemento.h"
// EN PROCESO DE DISEÑO
using namespace std;

class Lista : public Elemento {
   class Iterator;
   
   friend class Iterator;   	

   private:
      class Celda;
	  
      class Celda {
	     public:
            Elemento * elemento;
            Celda * anterior;
            Celda * siguiente;
            Celda( Elemento * );
            ~Celda();			
	   
      };	

      Celda * primera;
	  Celda * ultima;
	
    protected:
	   ostream & imprimir(ostream &);
	   istream & cargar(istream &);
	
	public:
	   class Iterator(){
		  friend class Lista;
		  private:
              Celda * actual;
		      Iterator();		      
			  Iterator( Celda * );
		  public:
              Elemento * operator*();
              Iterator &operator++();
              Iterator &operator--();
              Iterator operator++(int noSeUsa);
              Iterator operator--(int noSeUsa);
			  int operator==(const Iterator &);
			  int operator!=(const Iterator & otro){
				  return !(*this==otro);
			  } 
	   };
	   Iterator begin();
	   Iterator end();
	   Lista();
	   Lista( Elemento *, const char *); // Carga elementos desde el archivo y rellena la lista
	   Lista( const Lista & );
	   ~Lista();
	   Lista * clonar();	   
 	   double distancia(Elemento *);
       Lista & operator+=(Elemento *);  // Es un push_back que agrega al final de la lista 
	   Lista & insertar(Iterator&, Elemento *); // inserta una copia del elemento
	   Lista & borrar(Iterator&);
	   Lista & push_front(Elemento *);
	   Elemento * pop_front();
	   Elemento * pop_back(); // Retorna el último 	   
};
#endif