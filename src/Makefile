CC=g++
CFLAGS = `pkg-config --cflags opencv` -Wall -Wextra -ansi -pedantic -g -std=c++11
LIBS = `pkg-config --libs  opencv`



prog : main.o imageIO.o Bibliotheque.o
	 $(CC) main.o imageIO.o Bibliotheque.o $(LIBS)  -o prog

main.o : main.cpp 
	$(CC) $(CFLAGS) -c main.cpp  

imageIO.o : imageIO.cpp imageIO.h
	 $(CC) $(CFLAGS) -c imageIO.cpp

Bibliotheque.o : Bibliotheque.cpp Bibliotheque.h
	 $(CC) $(CFLAGS) -c Bibliotheque.cpp

clean:
	rm -rf *.o prog

