all: main.cpp ./libs/Algorithms.o ./libs/container.o ./libs/box.o
	g++ -o ./bin/main main.cpp libs/box.o libs/container.o libs/Algorithms.o

libs/Algorithms.o: ./src/bodies/Algorithms.cpp ./src/headers/Algorithms.h ./libs/container.o ./libs/box.o
	g++ -c ./src/bodies/Algorithms.cpp -o ./libs/Algorithms.o


libs/container.o: ./src/bodies/container.cpp ./src/headers/container.h ./libs/box.o
	g++ -c ./src/bodies/container.cpp -o ./libs/container.o

libs/box.o: ./src/bodies/box.cpp ./src/headers/box.h
	g++ -c ./src/bodies/box.cpp -o ./libs/box.o

.PHONY: clean

clean:
	rm -f main	