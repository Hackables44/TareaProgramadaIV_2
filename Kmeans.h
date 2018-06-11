#include "Elemento.h"
#include "Lista.h"
#include "Agrupador.h"
#include <iostream>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

class Kmeans: public Agrupador{

private:
	int id_point, id_cluster;
	vector<double> values;
	int total_values;
	string name;

public:
	Kmeans(int id_point, vector<double>& values, string name = "")
	{
		this->id_point = id_point;
		total_values = values.size();

		for(int i = 0; i < total_values; i++)
			this->values.push_back(values[i]);

		this->name = name;
		id_cluster = -1;

	}
	~Kmeans(); //destructor del agrupador Hac, destruye su estructura dinamica matriz
	Lista* agrupar(Lista*); //metodo heredado de agrupador que agrupa siguiendo los pasos de su algoritmo
