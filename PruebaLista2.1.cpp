#include "Lista.h"
#include "Enterito.h"
#include "Hac.h"
#include<iostream>
using namespace std;

int main(){
	Lista * lista;
	Lista * otra;
	Enterito * diez = new Enterito(10); // Protipo
	Enterito * veinte = new Enterito(20); // Protipo
	Enterito * treinta = new Enterito(30);
	Enterito* cuarenta = new Enterito(40);		
//  int n;
//  cout << "Digite cuantos enteritos hay en cada lista y despues digitelos: "; 
//  cin >> n;
//  cout << "\nDigite los valores de la lista 1:";
  lista = new Lista();

  *lista += diez;
  *lista += diez;
  *lista += veinte;
  *lista += treinta;
  *lista += cuarenta;
    
//  lista = new Lista(enterito , cin , n);
//  cout << "\nDigite los valores de la lista 2:";
//  otra = new Lista(enterito , cin , n);
  otra = new Lista();
  *otra+= veinte;
  *otra+= veinte;
  *otra+= veinte;
  *otra+= veinte;

  cout << "LISTA 1"<< endl;
  cout << lista << endl;
  cout << "LISTA 2"<< endl;  
  cout << otra << endl;
  
  /* Lista::Iterator finalLista = lista->end();
for( Lista::Iterator i = lista->begin(); i!= finalLista ; ++i){
	cout << "<text>" << *i << "</text>" << endl;
	
} */
  
  cout << "\nDistancia entre ellas :" << lista->distancia(otra) << endl;
  
  /* Lista nula;

  nula+= &nula;
  nula+= &nula;
  nula+= &nula;
      
  cout << &nula << endl; */
  Hac hac;
  hac.crearMatrizDistancias(lista);
  
  delete lista;
  delete otra;
  delete diez;
  delete veinte;
  delete treinta;
  delete cuarenta;
  return 0;
}