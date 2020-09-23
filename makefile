CFLAGS = -g -Wall -O
LIBS_PATH = ./lib/
LIBS = -lGL -lGLU -lglut 
CC = g++
SRC = main.cpp $(LIBS_PATH)colors.cpp
OBJ = $(SRC:.cpp=.o)

default: chemex

chemex: $(OBJ)
	$(CC) $(CFLAGS) -o chemex.out $(OBJ) $(LIBS)

clean:
	$(RM) chemex *.o *~ $(LIBS_PATH)*.o