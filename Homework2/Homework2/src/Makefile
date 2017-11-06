app.out: main.o ExecuteManager.o LogManager.o
	g++ -o app.out main.o ExecuteManager.o LogManager.o

main.o: main.cpp
	g++ -c main.cpp

ExecuteManager.o: Core/ExecuteManager.cpp 
	g++ -c Core/ExecuteManager.cpp

LogManager.o: Utils/LogManager.cpp
	g++ -c Utils/LogManager.cpp
