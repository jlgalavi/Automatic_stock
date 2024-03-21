
all: main.cpp box.o container.o Algorithms.o
	g++ -o main main.cpp box.o container.o Algorithms.o

Algorithms.o: Algorithms.cpp Algorithms.h container.o box.o
	g++ -c Algorithms.cpp

container.o: container.cpp container.h box.o
	g++ -c container.cpp 

box.o: box.cpp box.h
	g++ -c box.cpp

.PHONY: clean

clean:
	rm -f main	