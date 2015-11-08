all: tp

tp: main.o entrada_salida.o evento.o evento_test.o resultado.o 
	g++ -Wall -pedantic -o tp main.o entrada_salida.o evento.o evento_test.o resultado.o

entrada_salida.o: EntradaSalida.cpp EntradaSalida.hpp evento.hpp
	g++ -Wall -pedantic -c -o entrada_salida.o EntradaSalida.cpp

evento.o: evento.cpp evento.hpp
	g++ -Wall -pedantic -c -o evento.o Evento.cpp

evento_test.o: EventoTest.cpp EventoTest.hpp Resultado.hpp
	g++ -Wall -pedantic -c -o evento_test.o EventoTest.cpp

resultado.o: Resultado.cpp Resultado.hpp
	g++ -Wall -pedantic -c -o resultado.o Resultado.cpp

main.o: main.cpp Evento.hpp EntradaSalida.hpp
	g++ -Wall -pedantic -c -o main.o main.cpp

clean:
	rm *.o *.exe