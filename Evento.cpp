#include <string>
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <cstring>
#include <sstream>
#include <ostream>
#include "Evento.hpp"

using namespace std;

Evento::Evento(){}
Evento::~Evento(){}

string Evento::getFecha() const {return fecha;}
string Evento::getCategoria() const {return categoria;}
string Evento::getDia() const {return dia;}
string Evento::getDistrito() const {return distrito;}
string Evento::getCoordenadaX() const {return coordenadaX;}
string Evento::getCoordenadaY() const {return coordenadaY;}

void Evento::setFecha(string nF){fecha = nF;}
void Evento::setCategoria(string nC){categoria = nC;}
void Evento::setDia(string nD){dia = nD;}
void Evento::setDistrito(string nD){distrito = nD;}
void Evento::setCoordenadaX(string nCx){coordenadaX = nCx;}
void Evento::setCoordenadaY(string nCy){coordenadaY = nCy;}

istream& operator>>(istream& is, Evento &evento)
{	
	
	string ev;
	getline(is,ev,'\n');

	string comma=",";
	//Obtengo la fecha
	string fecha = ev.substr(0,ev.find(comma));
	ev.erase(0,fecha.length()+1);
	evento.setFecha(fecha);

	//Obtengo la categoria
	string categoria = ev.substr(0,ev.find(comma));
	ev.erase(0,categoria.length()+1);
	evento.setCategoria(categoria);

	//Obtengo la descripcion (luego no se usa como atributo)
	string descripcion = ev.substr(0,ev.find(comma));
	ev.erase(0,descripcion.length()+1);

	//Obtengo el día de la semana
	string dia = ev.substr(0,ev.find(comma));
	ev.erase(0,dia.length()+1);
	evento.setDia(dia);

	//Obtengo el distrito
	string distrito = ev.substr(0,ev.find(comma));
	ev.erase(0,distrito.length()+1);
	evento.setDistrito(distrito);
	
	//Obtengo la resolucion (luego no se usa)
	//La resolución es molesta, ya que puede tener una comma en el medio
	//en dicho caso comienza con comillas
	//Si comienza con comillas, busco como separador <",> y borro el 
	//string resultante
	string resolucion;
	if(ev[0] == '"')
	{
		resolucion = ev.substr(0,ev.find("\","));
		ev.erase(0,resolucion.length()+2);
	}
	else
	{
		resolucion = ev.substr(0,ev.find(comma));
		ev.erase(0,resolucion.length()+1);
	}

	//Obtengo la direccion (no se usa)
	string direccion = ev.substr(0,ev.find(comma));
	ev.erase(0,direccion.length()+1);

	//Obtengo coordenada X
	string coordenadaX = ev.substr(0,ev.find(comma));
	ev.erase(0,coordenadaX.length()+1);
	evento.setCoordenadaX(coordenadaX);

	//Obtengo coordenada Y, es lo que resta en el string {ev}
	evento.setCoordenadaY(ev);

	return is;
}

ostream& operator<<(ostream& os, Evento &ev)
{
	os << ev.getFecha() + ","
		  + ev.getCategoria() + ","
		  + ev.getDia() + ","
		  + ev.getDistrito() + ","
		  + ev.getCoordenadaX() + ","
		  + ev.getCoordenadaY() + '\n';

	return os;

}
