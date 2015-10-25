#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <cstring>
#include <sstream>
#include <ostream>
#include "Evento.hpp"
#include "EventoTest.hpp"
#include "EntradaSalida.hpp"

using namespace std;

void EntradaSalida::leerArchivoTrain(istream * archivoEntrada)
{
	//Leer primer linea (encabezado)
	string encabezado;
	getline(*archivoEntrada,encabezado,'\n');

	//Lectura linea a linea del archivo de entrada
	string evento;
	while(getline(*archivoEntrada,evento,'\n'))
	{
		//Convierto el string a un stringstream para luego pasarselo al operador >>
		stringstream ss(evento);

		//Instancio un objeto del tipo Evento y uso el operador >>
		//para setearle los atributos
		Evento eventoActual;
		ss>>eventoActual;

		//Procesamiento del objeto en la estructura
		cout<<eventoActual;
	}

}

void EntradaSalida::leerArchivoTest(istream * archivoEntrada)
{
	//Leer primer linea (encabezado)
	string encabezado;
	getline(*archivoEntrada,encabezado,'\n');

	//Lectura linea a linea del archivo de entrada
	string evento;
	while(getline(*archivoEntrada,evento,'\n'))
	{
		//Convierto el string a un stringstream para luego pasarselo al operador >>
		stringstream ss(evento);

		//Instancio un objeto del tipo Evento y uso el operador >>
		//para setearle los atributos
		EventoTest eventoActual;
		ss>>eventoActual;

		//Procesamiento del objeto en la estructura
		cout<<eventoActual;
	}
}

