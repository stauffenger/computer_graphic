CFLAGS = -g -Wall -O
LIBS = -lGL -lGLU -lglut
CC = g++
SRC = main.cpp colors.cpp
OBJ = $(SRC:.cpp=.o)

default: chemex

chemex: $(OBJ)
	$(CC) $(CFLAGS) -o chemex.out $(OBJ) $(LIBS)

clean:
	$(RM) chemex *.o *~