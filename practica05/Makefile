CXX = g++
CXXFLAGS = -Wall -pedantic -std=c++17 -g -fsanitize=address
LDFLAGS =  -fsanitize=address

SRC = Alfabeto.cc Automata.cc Cadena.cc Cliente.cc Estado.cc Lenguaje.cc Simbolo.cc
OBJ = $(SRC:.cc=.o)
EXEC = p05_automata_simulator

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $(OBJ) $(LBLIBS)

clean:
	rm -rf $(OBJ) $(EXEC)