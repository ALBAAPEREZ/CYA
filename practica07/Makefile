CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++17 -g -fsanitize=address
LDFLAGS =  -fsanitize=address

SRC = Alfabeto.cc Cadena.cc Cliente.cc Gramatica.cc Lenguaje.cc Simbolo.cc
OBJ = $(SRC:.cc=.o)
EXEC = Grammar2CNF

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $(OBJ) $(LBLIBS)

clean:
	rm -rf $(OBJ) $(EXEC)