#ifndef ENTRADA_SALIDA_H
#define ENTRADA_SALIDA_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <cstring>
#include <sstream>
#include <ostream>
#include "Evento.hpp"

using namespace std;

/*
 Clase con metodos estaticos cuya función es ocuparse de la lectura
 y escritura de archivos de entrada-salida
 No es necesario instanciarla para usarla.
*/
class EntradaSalida
{
	public:
		static void leerArchivoTrain(istream * archivoEntrada);
		static void leerArchivoTest(istream * archivoEntrada);
};

#endif