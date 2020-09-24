CFLAGS = -g -Wall -O
LIBS_PATH = ../lib/
LIBS = -lGL -lGLU -lglut 
CC = g++
SRC = main.cpp $(LIBS_PATH)colors.cpp
OBJ = $(SRC:.cpp=.o)

default: examples

examples: $(OBJ)
	$(CC) $(CFLAGS) -o examples.out $(OBJ) $(LIBS)

clean:
	$(RM) examples *.o *~ $(LIBS_PATH)*.o