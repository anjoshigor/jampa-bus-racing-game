CC = g++

all:
	$(CC) *.cpp -lglut -lGLU -lGL -lassimp -I. -o Main 
	$ ./Main

clean:
	rm Main

