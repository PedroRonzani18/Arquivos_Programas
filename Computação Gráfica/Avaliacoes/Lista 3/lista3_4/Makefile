CC = g++
FLAGS= -g -lglut -lGL -lGLU -lSOIL -lSDL2 -lSDL2_mixer
OUTPUT= main
all:
		$(CC) -g -std=c++11 -O2 -Wall *.cpp $(FLAGS) -o $(OUTPUT)

run: all
	./$(OUTPUT)

clean:
		rm *.o -f