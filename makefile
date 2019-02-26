CFLAGS = -Wall -Wextra -DDEBUG -g -std=c++14
P = program1

all: $(P)

$(P): $(P).o Star.o Vector.o List.o Planet.o
	g++ $(CFLAGS) $(P).o Star.o Vector.o List.o Planet.o -o $(P) 

$(P).o: $(P).cpp Star.cpp Planet.cpp Star.h Planet.h
	g++ -c $(CFLAGS) $(P).cpp -o $(P).o

Star.o: Star.cpp Star.h 
	g++ -c $(CFLAGS) Star.cpp -o Star.o

Planet.o: Planet.cpp Planet.h
	g++ -c $(CFLAGS) Planet.cpp -o Planet.o

Vector.o: Vector.cpp Vector.h
	g++ -c $(CFLAGS) Vector.cpp -o Vector.o

List.o: List.cpp List.h
	g++ -c $(CLFAGS) List.cpp -o List.o

clean:
	rm -rf $(P) *.o
run: all
	./$(P)
