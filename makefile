findtreasure: tools game 
	g++ ./lib/Tools.o ./lib/Game.o -o findtreasure
tools:
	g++ -I "./include" -c ./src/Tools.cpp -o ./lib/Tools.o
game:
	g++ -I "./include" -c ./src/Game.cpp -o ./lib/Game.o
