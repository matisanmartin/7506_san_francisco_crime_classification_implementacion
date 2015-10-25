#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <cstring>
#include <sstream>
#include <ostream>
#include "EntradaSalida.hpp"

using namespace std;

int main(int argc, char * argv[])
{
	istream * entrada;
	fstream fEntrada;

	fEntrada.open("prueba_train.csv",ifstream::in);
	entrada= &fEntrada;

	EntradaSalida::leerArchivoTrain(entrada);

	fEntrada.close();

	fEntrada.open("prueba_test.csv",ifstream::in);
	entrada = &fEntrada;

	EntradaSalida::leerArchivoTest(entrada);

	fEntrada.close();
}