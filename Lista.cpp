#include "Lista.h"
#include "Elemento.h"

using namespace std;
// CELDA
// En la lista al agregar elementos son clonados... Hay que destruirlos
Lista::Celda::Celda( Elemento * elemento){
	if(elemento!=0){
  	   this->elemento = elemento->clonar();
	}
	else {
	   this->elemento = 0;
	}
	siguiente = 0;
	anterior = 0;
}


Lista::Celda::~Celda(){ 
// SOLO DESTRUYE EL ELEMENTO DE LA CELDA
	delete elemento;
}			


ostream & Lista::imprimir(ostream & salida){

	if(primera!=0){
	   salida << "{ ";	
  	   Iterador elFinal = this->end();
	   Lista::Iterador i = this->begin();
	   salida << *i;
	   ++i;
	   while(i != elFinal){
		   salida << " , "<< *i;
		   ++i;
	   }
	   salida << " }";
	}
	else {
	   salida << "LISTA_VACIA";	
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
          
Lista::Iterator & Lista::Iterator::operator++(){
	if(actual!=0){
  	   actual =  actual->siguiente;
	}
	return *this;
}

Lista::Iterator &Lista::Iterator::operator--(){
	if(actual!=0){
  	   actual =  actual->anterior;
	}
	return *this;
}

Lista::Iterator Lista::Iterator::operator++(int noSeUsa){
   Iterator copia(actual);
   ++(*this);
   return copia;
}
			  
Lista::Iterator Lista::Iterator::operator--(int noSeUsa){
   Iterator copia(actual);
   --(*this);
   return copia;	
}

int Lista::Iterator::operator==(const Iterator & otro){
	return this->actual == otro.actual;
}

Lista::Iterator Lista::begin(){

   Lista::Iterator elPrimero( primera );
   return elPrimero;
}
	   
Lista::Iterator Lista::end(){
   Lista::Iterator elFinal(); // El final es una posición después del último que siempre es nula
   return elFinal;
}

Lista::Lista(){
   primera = 0;
   ultima = 0;   
}


Lista::Lista( Elemento * elemento, ifstream &entrada, int n){
   for(int i=0; i<n; ++i){
      entrada >> elemento;
	  (*this)+= elemento;
   }
} // Carga elementos desde el flujo y rellena la lista

void  Lista::destruir(){
		Celda * actual;
		Celda * victima;
		for( actual = primera; actual!=0; actual=actual->siguiente){
			victima = actual->anterior;
			if(victima!=0){
				delete victima;
			}
		} 
		if(ultima!=0){
			delete ultima;
		}
		primera=0;
		ultima=0;
}
Elemento & Lista::operator=( const Elemento & otra){
	Lista * lista2 = dynamic_cast< Lista * >( &otra );
    if(lista2!=0){
		this->destruir();
        Iterator elFinal = lista2->end();
		for(Iterator i = lista2->begin(); i!=elFinal; ++i){
			this->push_back( *i );
		} 
	}
	return *this;
}

Lista::~Lista(){
   destruir();
}

Lista * Lista::clonar(){
   Lista * nueva = new Lista();
   *nueva = *this;
   return nueva;
}	   

void Lista::aplanar(Lista & destino, Lista & origen){
	// aplana la lista origen y poner sus elementos ( que no son sub-listas ) en lista destino
   Iterador finalOrigen = origen.end();
   Lista * listaLocal = 0;
   for(Iterator i = origen.begin(); i!=finalOrigen; ++i){
	   listaLocal = dynamic_cast<Lista *>(*i);
	   if(listaLocal){
		   aplanar(destino,listaLocal);
	   }
	   else {
		   destino+= *i;
	   }
   } 
}

double Lista::distancia(Elemento * elemento){
   Lista * otraLista = dynamic_cast< Lista * >( elemento );
   Lista lista1;
   Lista lista2;
   double distanciaPromedio = 1.0;
   aplanar(lista1,*this);
   if(otraLista){
	   aplanar(lista2,otraLista);
   }
   else {
	   lista2+=elemento;
   }
   int n = 0;
   double suma = 0.0;
   Iterador final1 = lista1.end();
   Iterador final2 = lista2.end();

   for(Iterator i = lista1.begin(); i!=final1; ++i){
	    for(Iterator j = lista2.begin(); j!=final2; ++j){
	       suma+= (*i)->distancia( *j );
	       ++n;
        }   
   } 
   if(n!=0){
	   distanciaPromedio = suma/n;
   }
   return distanciaPromedio;
}

Lista & Lista::operator+=(Elemento * elemento){
   if(ultima!=0){
      ultima->siguiente = new Celda( elemento );
	  ultima->siguiente->anterior = ultima;
      ultima = ultima->siguiente;
   }
   else {
	   this->push_front(elemento);
   }
}  // Es un push_back que agrega al final de la lista 
	   
Lista & Lista::insertar(Lista::Iterator& i, Elemento * elemento){
	if(primera==0){
		if(i.actual==0){
  		   push_front(elemento);
		}
	}
	else {
	   if(i.actual==primera){
          push_front(elemento);	 
       }		  
	   else {
		   if(i.actual==0){
			   push_back(elemento);
		   }
		   else {
			   Celda * nueva = new Celda(elemento);
			   // INSERCION SEGUN ANALISIS DEL GRUPO 03
			   // i.actual->anterior->siguiente = nueva;
			   // nueva->anterior = i.actual->anterior;
			   // i.actual->anterior = nueva;
			   // nueva->siguiente = i.actual;
			   //
			   // VERSION GRUPO 04 ES MÁS LIMPIA...
			   // LA NUEVA SE COLA APUNTANDOLE A SU ANTERIOR Y SIGUIENTE...USANDO EL ITERADOR
			   // LUEGO LES DICE QUE ELLA ESTÁ ANTES Y DESPUÉS RESPECTIVAMENTE
			   // EL ITERADOR QUEDA APUNTANDO DONDE ESTABA
			   nueva->anterior = i.actual->anterior;
			   nueva->siguiente = i.actual;
			   nueva->anterior->siguiente = nueva;
			   nueva->siguiente->anterior= nueva;
		   }
		   
	   }
	}
	return *this;
} // inserta una copia del elemento
	   
	   
Lista & Lista::borrar(Lista::Iterator& i){
	Elemento * elementoQueVaMorir;
	Celda * victima = 0;
	if(primera){
		if(i.actual != 0){
			if(i.actual==primera){
				i.actual = i.actual->siguiente;
				elementoQueVaMorir = pop_front();
				delete elementoQueVaMorir;
			}
			else{
				if(i.actual==ultima){
					i.actual = i.actual->siguiente;
					elementoQueVaMorir = pop_back();
					delete elementoQueVaMorir;
				}
				else{
					i.actual->anterior->siguiente = i.actual->siguiente;
					i.actual->siguiente->anterior = i.actual->anterior;
					victima = i.actual;
					i.actual = i.actual->siguiente;
					delete victima;
				}
			}
		}
	}
    return *this;
}

Lista & Lista::push_front(Elemento * elemento){
	Celda  * nueva = new Celda(elemento);
    if(primera==0){
		primera = nueva;
		ultima = nueva;
	}
	else {
		nueva->siguiente = primera;
		primera->anterior = nueva;
		primera = nueva;
	}
}

Elemento * Lista::pop_front(){
	Elemento * copia = 0;	
	if(primera!=0){
	  	copia = primera->elemento;
		primera->elemento=0;  // Desconecté el puntero al elemento de la Celda
		if(primera->siguiente==0){
			delete primera;
			primera = 0;
			ultima = 0;
		}
		else {
			primera = primera->siguiente;
			delete primera->anterior;
			primera->anterior = 0;
		}
	}
	return copia;
}

Elemento * Lista::pop_back(){
	Elemento * copia = 0;	
	if(ultima!=0){
	  	copia = ultima->elemento;
		ultima->elemento=0;
		if(ultima->anterior==0){
			delete ultima;
			primera = 0;
			ultima = 0;
		}
		else {
			ultima = ultima->anterior;
			delete ultima->siguiente;
			ultima->siguiente = 0;
		}
	}
	return copia;	
} // Retorna el último 	   
