all:derle bagla calistir
derle:
	g++ -c -I "./include" ./src/Number.cpp -o ./lib/Number.o
	g++ -c -I "./include" ./src/NumbersList.cpp -o ./lib/NumbersList.o
	g++ -c -I "./include" ./src/Node.cpp -o ./lib/Node.o
	g++ -c -I "./include" ./src/Digit.cpp -o ./lib/Digit.o
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
bagla:
	g++ ./lib/NumbersList.o ./lib/Node.o ./lib/Digit.o ./lib/Number.o ./lib/main.o -o ./bin/program
calistir:
	./bin/program