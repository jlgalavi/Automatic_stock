
all: main.cpp box.o container.o Algorithms.o
	g++ -o ./bin/main main.cpp box.o container.o Algorithms.o

Algorithms.o: ./src/bodies/Algorithms.cpp ./src/headers/Algorithms.h container.o box.o
	g++ -c ./src/bodies/Algorithms.cpp

container.o: ./src/bodies/container.cpp ./src/headers/container.h box.o
	g++ -c ./src/bodies/container.cpp 

box.o: ./src/bodies/box.cpp ./src/headers/box.h
	g++ -c ./src/bodies/box.cpp

.PHONY: clean

clean:
	rm -f main	