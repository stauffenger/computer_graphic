CFLAGS = -g -Wall -O
LIBS_PATH = ./lib/
EXAMPLE_PATH = ./code_examples/
LIBS = -lGL -lGLU -lglut 
CC = g++
SRC = main.cpp $(LIBS_PATH)colors.cpp
SRC_EXAMPLE = $(EXAMPLE_PATH)main.cpp $(EXAMPLE_PATH)drawSimpleShapes.cpp $(LIBS_PATH)colors.cpp
OBJ = $(SRC:.cpp=.o)
OBJ_EXAMPLE = $(SRC_EXAMPLE:.cpp=.o)

default: chemex

chemex: $(OBJ)
	$(CC) $(CFLAGS) -o chemex.out $(OBJ) $(LIBS)

examples: $(OBJ_EXAMPLE)
	$(CC) $(CFLAGS) -o examples.out $(OBJ_EXAMPLE) $(LIBS)
clean:
	$(RM) chemex *.o *~ $(LIBS_PATH)*.o $(EXAMPLE_PATH)*.o