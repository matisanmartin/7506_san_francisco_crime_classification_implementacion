#ifndef RESULTADO_H
#define RESULTADO_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <map>

using namespace std;

/*
 Esta clase encapsula al arreglo de resultados luego de calcular
 la probabilidad de la ocurrencia de un delito
 Es un map<string,double> al cual se podrá ir accediendo
 a traves de su clave, que será el tipo de delito
 bajo la definición literal que se encuentra
 en el archivo de salida.
*/
class Resultado{

	private:
		map<string,double> resultados;

	public:
		Resultado();
		~Resultado();
		double buscarResultado(string clave);
		void setResultado(string clave, double valor);
};

#endif
