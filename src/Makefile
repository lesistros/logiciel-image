CC=g++
CFLAGS = `pkg-config --cflags opencv` -Wall -Wextra -ansi -pedantic -O3
LIBS = `pkg-config --libs  opencv`

test : main.o 
	 $(CC) main.o $(LIBS) -o test

main.o : main.cpp 
	$(CC) $(CFLAGS) -c main.cpp  

imageIO.o : imageIO.cpp
	 $(CC) $(CFLAGS) -c imageIO.cpp

clean:
	rm -rf *.o test

