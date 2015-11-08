#ifndef EVENTO_TEST_H
#define EVENTO_TEST_H

#include "Evento.hpp"
#include "Resultado.hpp"
/*
	Esta clase modela un evento proveniente del archivo de test
	Hereda sus atributos de Evento y la idea es reutilizar todo
	lo que se pueda salvo los operadores >> y <<, que se redefiniran.
*/
class EventoTest : public Evento
{
	protected:
		string id;
		Resultado res;
	public:
		EventoTest();
		~EventoTest();
		string getId() const;
		void setId(string nuevoId);
		void setResultado(string clave, double valor);
		Resultado getResultado();
};

istream& operator>>(istream& is, EventoTest &ev);
ostream& operator<<(ostream& os, EventoTest &ev);

#endif