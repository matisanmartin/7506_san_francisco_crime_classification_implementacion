all: tp

tp: main.o entrada_salida.o evento.o evento_test.o
	g++ -Wall -pedantic -o tp main.o entrada_salida.o evento.o evento_test.o

entrada_salida.o: EntradaSalida.cpp EntradaSalida.hpp evento.hpp
	g++ -Wall -pedantic -c -o entrada_salida.o EntradaSalida.cpp

evento.o: evento.cpp evento.hpp
	g++ -Wall -pedantic -c -o evento.o Evento.cpp

evento_test.o: EventoTest.cpp EventoTest.hpp
	g++ -Wall -pedantic -c -o evento_test.o EventoTest.cpp

main.o: main.cpp Evento.hpp EntradaSalida.hpp
	g++ -Wall -pedantic -c -o main.o main.cpp

clean:
	rm *.o *.exe