PROJECTNAME=lab3
CFLAGS=-c -Wall -Wextra -DDEBUG -g -std=c++14

all: Star.o Star.h Planet.o Planet.h $(PROJECTNAME).o 
	g++ Star.o Star.h Planet.o Planet.h $(PROJECTNAME).o -o $(PROJECTNAME)
Star.o: Star.cpp
	g++ ${CFLAGS} Star.cpp -o Star.o
Planet.o: Planet.cpp
	g++ ${CFLAGS} Planet.cpp -o Planet.o
$(PROJECTNAME).o: $(PROJECTNAME).cpp
	g++ ${CFLAGS} $(PROJECTNAME).cpp -o $(PROJECTNAME).o
run: all
	./$(PROJECTNAME)
memcheck: all
	valgrind ./$(PROJECTNAME)

clean:
	rm -rf Star.o
	rm -rf Star
	rm -rf Planet.o
	rm -rf Planet
	rm -rf $(PROJECTNAME).o
	rm -rf $(PROJECTNAME)
