/** ArbolRojiNegro.h */
#ifndef _ArbolRojiNegro
#define _ArbolRojiNegro

#define IZQ 0
#define DER 1

class ArbolRN{
	private:
		
		class Nodo{
			public:
				char color; /**  */
				int key; /** llave del nodo*/
				int /** T */ dato; /** almacena el valor según el tipo de dato (T) */ // tentativo
				
				Nodo(){ /** constructor por omisión */
					/** inicializa los valores */
					dato = 0;
					key = 0;
					color = '\0';
				}

				
				Nodo(int key, int dato){ /** constructor con parámetros de la clase nodo */
					/** inicializa los valores con los atributos recibidos*/
					this->key=key;
					this->dato=dato;
					color = '\0';
				}
				
				void setColor(char color){
					this->color = color;
				}
				
				void setDato(int dato){
					this->dato = dato;
				}

				void setKey(int key){
					this->key = key;
				}
				
				char getColor(){
					return color;
				}

				int /** T */ getDato(){
					return dato;
				}

				int getKey(){
					return key;
				}

		};
		
		Nodo * raiz;
		
	public:
	
		class Iterator;
		friend class Iterator;
		class Iterator{ /** con cuatro punteros */
		  friend class ArbolRN;
		  private:
			Nodo * actual; /** se toma como nodo hijo, y en base a este, se asignan los nodos padre, abuelo y bisAbuelo */
			Nodo * padre;
			Nodo * abuelo;
			Nodo * bisAbuelo;
			
			/* Cada vez que baje, que mueva cada puntero hacia arriba. Ejem
				
				bisAbuelo = abuelo;
				abuelo = padre;
				padre = actual; // actual es el hijo
				actual = ... ; // bajé en el árbol por tanto el hijo cambió
				
			*/     	      			 
		  public:
		      Iterator();	
		      Iterator( Nodo * );
              int /** Elemento * */ operator*();
              Iterator &operator++();
              Iterator &operator--();
              Iterator operator++(int noSeUsa);
              Iterator operator--(int noSeUsa);
			  int operator==(const Iterator &);
			  int operator!=(const Iterator & otro){
				  return !(*this==otro);
			  } 
			  Iterator & operator=(Elemento *);
	   };
		
		
		
	
		void cambioColorRaiz(){ /** cambia el color de la raíz de Rojo a Negro */
			if( 'R' == raiz.color ){ /** si la raiz es de color Rojo */
				raiz.color = 'N'; /** cambiar la raíz a color Negro */
			}
		}
		
		void colorFlip(Nodo * padre){ /** recibe el puntero del nodo padre */
			int ambos = 0; /** */
			/** si el hijo izquierdo y el hijo derecho son rojos lo almacena en la variable local */
			if( ('R' == padre->hijo[IZQ]->getColor()) && ('R' == padre->hijo[DER]->getColor()) ){
				ambos = 1;
			}

			if(ambos){ /** si ambos son rojos */
				/** pinta de Negro los nodos */
				padre->hijo[IZQ]->setColor('N');
				padre->hijo[DER]->setColor('N');
				padre->setColor('R'); /** y el padre se vuelve rojo */
			}
		}
		
		void rotacionSimpleIzquierda(){ /** se puede pasar a las siglas RSI */
		/** rotación de punteros */ /** si debe asignar el hijo derecho del bisAbuelo */
			abuelo->hijo[DER] = padre->hijo[IZQ]; /** le damos el hijo izquierdo al abuelo */
			padre->hijo[IZQ] = abuelo; /** el abuelo se vuelve hijo izquierdo del padre */
			bisAbuelo->hijo[DER] = padre; /** el bisAbuelo toma al nodo de mayor jerarquía */
			
		/** rotación de punteros */ /** si debe asignar el hijo derecho del bisAbuelo */
			abuelo->hijo[DER] = padre->hijo[IZQ]; /** le damos el hijo izquierdo al abuelo */
			padre->hijo[IZQ] = abuelo; /** el abuelo se vuelve hijo izquierdo del padre */
			bisAbuelo->hijo[IZQ] = padre; /** el bisAbuelo toma al nodo de mayor jerarquía */
			
		}
		
		void rotacionSimpleDerecha(){ /** se puede pasar a las siglas RSD */
		/** rotación de punteros */ /** si debe asignar el hijo derecho del bisAbuelo */
			abuelo->hijo[IZQ] = padre->hijo[DER]; /** le damos el hijo izquierdo al abuelo */
			padre->hijo[DER] = abuelo; /** el abuelo se vuelve hijo izquierdo del padre */
			bisAbueloPtr->hijo[DER] = padre; /** el bisAbuelo toma al nodo de mayor jerarquía */
			
		/** rotación de punteros */ /** si debe asignar el hijo derecho del bisAbuelo */
			abuelo->hijo[IZQ] = padre->hijo[DER]; /** le damos el hijo izquierdo al abuelo */
			padre->hijo[DER] = abuelo; /** el abuelo se vuelve hijo izquierdo del padre */
			bisAbueloPtr->hijo[IZQ] = padre; /** el bisAbuelo toma al nodo de mayor jerarquía */
		}
		
		void rotacionDobleIzquierda(){
			/** rotación de punteros */ /** si debe asignar el hijo derecho del bisAbuelo */
			padrePtr->hijo[IZQ] = padre->hijo[IZQ]->hijo[DER]; /** la llave izquierda le da su hijo derecho al padre */
			hijoLlavePtr->hijo[DER] = padre; /** El iterador tendrá referencia del bisAbueloPtr, abueloPtr, padrePtr, hijoLlavePtr */
			// -> actualizar los punteros del iterador 
			// revisar si se puede quitar ArbolRN::
			ArbolRN::Iterador iterador->bisAbuelo = abuelo;
			/** el abuelo es el mismo */
			padre = hijoLlave; /** el hijo pasa a ser padre */
			hijoLlave = abuelo->hijo[DER]; /** el primer padre pasa a ser hijo */
			rotacionSimpleIzquierda();
		}
		
		void rotacionDobleDerecha(){
			/** rotación de punteros */ /** si debe asignar el hijo izquierdo del bisAbuelo */
			padrePtr->hijo[DER] = padre->hijo[DER]->hijo[IZQ]; /** la llave derecha le da su hijo izquierdo al padre */
			/** El iterador tendrá referencia del bisAbueloPtr, abueloPtr, padrePtr, hijoLlavePtr */
			hijoLlavePtr->hijo[IZQ] = padre; /** el hijo se hace padre de su padre */ // jajaja...
			// -> actualizar los punteros del iterador 
			// revisar si se puede quitar ArbolRN::
			ArbolRN::Iterador iterador->bisAbuelo = abuelo;
			/** el abuelo es el mismo */
			padre = hijoLlave; /** el hijo pasa a ser padre */
			hijoLlave = abuelo->hijo[IZQ]; /** el primer padre pasa a ser hijo */
			rotacionSimpleDerecha();
		}
};

#endif