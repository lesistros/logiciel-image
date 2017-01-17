CC=g++
CFLAGS = `pkg-config --cflags opencv` -Wall -Wextra -ansi -pedantic -O3 -std=c++11
LIBS = `pkg-config --libs  opencv`

prog : main.o imageIO.o
	 $(CC) main.o imageIO.o  $(LIBS)  -o prog

main.o : main.cpp 
	$(CC) $(CFLAGS) -c main.cpp  

imageIO.o : imageIO.cpp imageIO.h
	 $(CC) $(CFLAGS) -c imageIO.cpp

clean:
	rm -rf *.o prog

