CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++17 -g -fsanitize=address
LDFLAGS =  -fsanitize=address

SRC = Alfabeto.cc Cadena.cc Cinta.cc Cliente.cc Estado.cc Lenguaje.cc Maquina_Turing.cc Simbolo.cc
OBJ = $(SRC:.cc=.o)
EXEC = SimulacionTuring

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $(OBJ) $(LBLIBS)

clean:
	rm -rf $(OBJ) $(EXEC)