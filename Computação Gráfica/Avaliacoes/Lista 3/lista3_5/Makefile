CC = g++
FLAGS= -g -lglut -lGL -lGLU -lSOIL -lSDL2 -lSDL2_mixer
OUTPUT= main
allt:
		$(CC) -g -std=c++11 -O2 -Wall *.cpp $(FLAGS) -o $(OUTPUT)
		
all:
		$(CC) -g *.cpp $(FLAGS) -o $(OUTPUT)

run: all
	./$(OUTPUT)

runt: allt
	./$(OUTPUT)

clean:
		rm *.o -f