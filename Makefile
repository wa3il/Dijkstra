
execute : Prog
	./Prog

Prog : Main.o Graphe.o Dijkstra.o
	g++ -Wall  Main.o Graphe.o Dijkstra.o -o Prog

Main.o : Main.cpp	
	g++ -c -Wall Main.cpp 

Graphe.o : Graphe.cpp Graphe.h
	g++ -c -Wall  Graphe.cpp

Dijkstra.o : Dijkstra.cpp  Dijkstra.h
	g++ -c -Wall -ggdb Dijkstra.cpp

clean :
	rm *.o