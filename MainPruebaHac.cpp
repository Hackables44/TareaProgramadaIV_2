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
	Enterito * treinta = new Enterito(30); //Prototipo
	Enterito* cuarenta = new Enterito(40);	//Prototipo	
	Enterito * sesenta = new Enterito(60); // Protipo
	Enterito * setenta = new Enterito(70); // Protipo
	Enterito * ochenta = new Enterito(80); //Prototipo
	Enterito* noventa = new Enterito(90);	//Prototipo	
//  int n;
//  cout << "Digite cuantos enteritos hay en cada lista y despues digitelos: "; 
//  cin >> n;
//  cout << "\nDigite los valores de la lista 1:";
  lista = new Lista();

  *lista += diez;
  *lista += treinta;
  *lista += cuarenta;
  *lista += sesenta;
  *lista += setenta;
  *lista += noventa;
    
//  lista = new Lista(enterito , cin , n);
//  cout << "\nDigite los valores de la lista 2:";
//  otra = new Lista(enterito , cin , n);
  /* otra = new Lista();
  *otra+= diez;
  *otra+= v;
  *otra+= veinte;
  *otra+= veinte;

  cout << "LISTA 1"<< endl;
  cout << lista << endl;
  cout << "LISTA 2"<< endl;  
  cout << otra << endl; */
  
  /* Lista::Iterator finalLista = lista->end();
for( Lista::Iterator i = lista->begin(); i!= finalLista ; ++i){
	cout << "<text>" << *i << "</text>" << endl;
	
} */
  
 /*  cout << "\nDistancia entre ellas :" << lista->distancia(otra) << endl; */
  
  /* Lista nula;

  nula+= &nula;
  nula+= &nula;
  nula+= &nula;
      
  cout << &nula << endl; */
  Hac hac;
  Lista* listaPrueba = new Lista;
  //hac.crearMatrizDistancias(lista);
  listaPrueba = hac.agrupar(lista);
  delete lista;
  delete otra;
  delete diez;
  delete veinte;
  delete treinta;
  delete cuarenta;
  delete sesenta;
  delete setenta;
  delete ochenta;
  delete noventa;
  delete listaPrueba;
  return 0;
}