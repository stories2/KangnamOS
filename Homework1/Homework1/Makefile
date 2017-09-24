app.out: main.o Ysera.o Nozdormu.o Malygos.o
	gcc -o a.out main.o Ysera.o Nozdormu.o Malygos.o

main.o: DeathWing.h main.cpp
	gcc -c -o main.o main.cpp

Ysera.o: DeathWing.h Ysera.cpp
	gcc -c -o Ysera.o Ysera.cpp

Nozdormu.o: DeathWing.h Nozdormu.cpp
	gcc -c -o Nozdormu.o Nozdormu.cpp

Malygos.o: DeathWing.h Malygos.cpp
	gcc -c -o Malygos.o Malygos.cpp
