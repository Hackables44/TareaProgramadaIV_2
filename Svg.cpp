#include <fstream>
#include <iostream>
#include "Svg.h"
#include <string>
#include "Lista.h"
using namespace std;

Svg::Svg(){};

void Svg::visualizar(Lista* lista){
    std::ofstream archivo("salida.svg");
    archivo << "<svg  xmlns=\"http://www.w3.org/2000/svg\" xmlns:xlink=\"http://www.w3.org/1999/xlink\">\n";
	Lista::Iterator f = lista->end();
	for(Lista::Iterator i = lista->begin(); i != f ; ++i){
		//archivo << "<text y=\"" <<  3.9 * 19 << "\"  x=\"" << 30 + 55 << "\"> " << *i <<"</text>";
		archivo << "<rect y=\"" <<  3 * 25 <<"\" x=\"" << 10 + 55  << "\" height=\"50\" width=\"50\" style=\"stroke:#ff0000; fill:#ffffff\"/>";	
		archivo << "<text y=\"" << 3 * 31 << "\" x=\"" << 30 + 55  << "\" style=\"fill:#ff0000;\"> " << *i <<"</text>";	
    }
	archivo << "</svg>";
}	