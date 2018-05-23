#include "Lista.h"
#include "Elemento.h"

using namespace std;
// CELDA
Lista::Celda::Celda( Elemento * elemento){
	this->elemento = elemento->clonar();
}
Lista::Celda::~Celda(){ 
// Warning:Destructor recursivo, para eliminar una celda individual 
// debe primero asignarle un 0 a su siguiente y luego hacer delete
	if(siguiente!=0){
		delete siguiente;
	}
	delete elemento;
}			

ostream & Lista::imprimir(ostream & salida){
	if(primera!=0){
  	   Lista::Iterador elFinal = this->end();
	   for(Lista::Iterador i = this->begin() ; i != elFinal ; ++i){
		   salida << *i << " ";
	   }
	}
	else {
	   salida << "LISTA_NULA";	
	}
	return salida;
}

istream & Lista::cargar(istream & entrada){
	if(primera!=0){
  	   Lista::Iterador elFinal = this->end();
	   for(Lista::Iterador i = this->begin() ; i != elFinal ; ++i){
		   entrada >> *i;
	   }
	}
	return entrada;	
}

Lista::Iterator::Iterator(){
	actual = 0;
}		      

Lista::Iterator::Iterator( Celda * actual){
	this->actual = actual;	
}

Elemento * Lista::Iterator::operator*(){
   Elemento * resp = 0;
   if(actual!=0){
	   resp = actual->elemento;
   }   
   return resp;			  
}

              Iterator &Lista::Iterator::operator++(){}
              Iterator &Lista::Iterator::operator--(){}
             
			 Iterator Lista::Iterator::operator++(int noSeUsa){
				  Iterator copia(actual);
				  if(actual!=0){
					  actual = actual->siguiente;
				  }
				  return copia;
			  }
			  
              Iterator Lista::Iterator::operator--(int noSeUsa){}
			  int Lista::Iterator::operator==(const Iterator &){}
		

	   Lista::Iterator Lista::begin(){
		   Lista::Iterator elPrimero( primera );
		   return elPrimero;
	   }
	   
	   Lista::Iterator Lista::end(){
		   Lista::Iterator elFinal(); // El final es una posición después del último que siempre es nula
		   return elFinal;
	   }
	   
	   Lista::Lista(){
		   
	   }

Lista::Lista( Elemento * elemento, const char * archivo){
   ifstream entrada(archivo);
   do {
      entrada >> elemento;
	  (*this)+= elemento;
   }while(!entrada.eof());		   
} // Carga elementos desde el archivo y rellena la lista

Lista::Lista( const Lista & ){
	
}
Lista::~Lista(){
	
}

Lista * Lista::clonar(){
	
}	   

double Lista::distancia(Elemento *){
	
}

Lista & Lista::operator+=(Elemento *){
	
}  // Es un push_back que agrega al final de la lista 
	   
Lista & Lista::insertar(Lista::Iterator& i, Elemento * elemento){
	
} // inserta una copia del elemento
	   
	   
Lista & Lista::borrar(Lista::Iterator&){
	
}

Lista & Lista::push_front(Elemento *){
	
}

Elemento * Lista::pop_front(){
	
	
}

Elemento * Lista::pop_back(){
	
} // Retorna el último 	   
