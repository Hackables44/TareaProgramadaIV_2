#ifndef _PRODUCTO_ABSTRACTO
#define _PRODUCTO_ABSTRACTO
#include <cstring>
class Producto {
   public:
   /** - Destructor virtual que puede ser utilizado por las clases derivadas de las clases Elemento, Agrupador y Visualizador que son
   subclases de esta clase abstracta Producto */
      virtual ~Producto(){};	
};
#endif
