#ifndef EVENTO_H
#define EVENTO_H

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

/*
 Clase que modela un "evento", un row del archivo de entrenamiento
 Posee como atributos todos los datos que se consideran utiles
 a la hora de realizar calculos,
 según lo definido en el modelo desarrollado.
*/
class Evento 
{
	private:
		string fecha;
		string categoria;
		string dia;
		string distrito;
		string coordenadaX;
		string coordenadaY;

	public:
		Evento();
		string getFecha() const;
		string getCategoria() const;
		string getDia() const;
		string getDistrito() const ;
		string getCoordenadaX() const;
		string getCoordenadaY() const;
		void setFecha(string nuevaFecha);
		void setCategoria(string nuevaCategoria);
		void setDia(string nuevoDia);
		void setDistrito(string nuevoDistrito);
		void setCoordenadaX(string nuevaCoordenadaX);
		void setCoordenadaY(string nuevaCoordenadaY);
		~Evento();
};

istream& operator>>(istream& is, Evento &ev);
ostream& operator<<(ostream& os, Evento &ev);

#endif