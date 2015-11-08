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

map<string,double> Resultado::getResultados() const
{
	return resultados;
}

/*
 Imprime la salida de resultados por ostream
 Se asume que en std::map las keys estan ordenadas,
 por ello se imprime directamente en el ciclo for,
 respetando el formato del archivo de salida
 http://www.cplusplus.com/reference/map/map/
*/
ostream& operator<<(ostream& os, const Resultado &res)
{
	string resultado = "";

	map<string,double> resultados = res.getResultados();
	map<string,double>::iterator it;

	for(it = resultados.begin();
		it != resultados.end();
		it++)
	{
		resultado += it->second;

		// Esto no es lo mas lindo, pero es lo unico que se me ocurrio
		// por ahora para evitar meter la ',' al final de la linea
		// buscar si hay alguna manera de hacerlo haciendo un peek
		// o algo por el estilo
		//if(it->first != "WEAPON LAWS")
			resultado += ",";
		//else
			//resultado += "\n";
	}

	//alternativa más linda, la dejo comentada
	//borra el ultimo caracter
	resultado.erase(resultado.end()-1);
	resultado += "\0\n";//por las dudas le meto el \0\n


	os << resultado;

	return os;
}
