CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++17 -g -fsanitize=address
LDFLAGS =  -fsanitize=address

SRC = Alfabeto.cc Automata.cc Cadena.cc Cliente.cc Estado.cc Lenguaje.cc Simbolo.cc
OBJ = $(SRC:.cc=.o)
EXEC = NFA2DFA

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $(OBJ) $(LBLIBS)

clean:
	rm -rf $(OBJ) $(EXEC)