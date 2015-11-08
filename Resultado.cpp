#include <iostream>
#include <cstdlib>
#include <string>
#include <map>
#include <stdexcept>
#include "Resultado.hpp"

using namespace std;

Resultado::Resultado(){}
Resultado::~Resultado(){}

/*
 Devuelve el valor asociado a una clave cualquiera
 Si no encuentra la clave, tira excepción.
*/
double Resultado::buscarResultado(string clave)
{
	map<string,double>::iterator it;

	it = resultados.find(clave);

	if(it!=resultados.end())
		return it->second; //en second se almacena el value
	else
		throw logic_error("No se encontró la clave buscada.");
}

/*
 Setea un par clave valor en el arreglo de resultados
*/
void Resultado::setResultado(string clave, double valor)
{
	resultados[clave] = valor;
}
