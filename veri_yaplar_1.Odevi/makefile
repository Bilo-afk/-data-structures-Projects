all: compile run

compile:
	g++ -I ./include/ -o ./lib/main.o -c ./src/main.cpp
	g++ -I ./include/ -o ./lib/Uygulama.o -c ./src/Uygulama.cpp
	g++ -I ./include/ -o ./lib/AnaListe.o -c ./src/AnaListe.cpp
	g++ -I ./include/ -o ./lib/AnaListeDugum.o -c ./src/AnaListeDugum.cpp
	g++ -I ./include/ -o ./lib/Ekran.o -c ./src/Ekran.cpp
	g++ -I ./include/ -o ./lib/SekilListesi.o -c ./src/SekilListesi.cpp
	g++ -I ./include/ -o ./lib/SekilDugum.o -c ./src/SekilDugum.cpp
	g++ -I ./include/ -o ./lib/Shape.o -c ./src/Shape.cpp
	g++ -I ./include/ -o ./lib/Triangle.o -c ./src/Triangle.cpp
	g++ -I ./include/ -o ./lib/Rectangle.o -c ./src/Rectangle.cpp
	g++ -I ./include/ -o ./lib/Star.o -c ./src/Star.cpp

	g++ -I ./include/ -o ./bin/Program \
	./lib/main.o ./lib/Uygulama.o ./lib/AnaListe.o ./lib/AnaListeDugum.o \
	./lib/Ekran.o ./lib/SekilListesi.o ./lib/SekilDugum.o ./lib/Shape.o \
	./lib/Triangle.o ./lib/Rectangle.o ./lib/Star.o

run:
	./bin/Program
