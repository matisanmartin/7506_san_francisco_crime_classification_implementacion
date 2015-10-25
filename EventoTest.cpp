#include <string>
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <cstring>
#include <sstream>
#include <ostream>
#include "EventoTest.hpp"

using namespace std;

EventoTest::EventoTest(){}
EventoTest::~EventoTest(){}

string EventoTest::getId() const{return id;}
void EventoTest::setId(string nuevoId){id=nuevoId;}

istream& operator>>(istream& is, EventoTest &evento)
{	
	
	string ev;
	getline(is,ev,'\n');

	string comma=",";

	//Obtengo id
	string id = ev.substr(0,ev.find(comma));
	ev.erase(0,id.length()+1);
	evento.setId(id);

	//Obtengo la fecha
	string fecha = ev.substr(0,ev.find(comma));
	ev.erase(0,fecha.length()+1);
	evento.setFecha(fecha);

	//Obtengo el día de la semana
	string dia = ev.substr(0,ev.find(comma));
	ev.erase(0,dia.length()+1);
	evento.setDia(dia);

	//Obtengo el distrito
	string distrito = ev.substr(0,ev.find(comma));
	ev.erase(0,distrito.length()+1);
	evento.setDistrito(distrito);
	
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

ostream& operator<<(ostream& os, EventoTest &ev)
{
	os << ev.getId() + ","
		  + ev.getFecha() + ","
		  + ev.getDia() + ","
		  + ev.getDistrito() + ","
		  + ev.getCoordenadaX() + ","
		  + ev.getCoordenadaY() + '\n';

	return os;

}