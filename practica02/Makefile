CXX = g++
CXXFLAGS = -Wall -pedantic -std=c++17 -g -fsanitize=address
LDFLAGS =  -fsanitize=address

SRC = Alfabeto.cc Cadena.cc Cliente.cc Lenguaje.cc Simbolo.cc
OBJ = $(SRC:.cc=.o)
EXEC =  p02_strings 

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $(OBJ) $(LBLIBS)

clean:
	rm -rf $(OBJ) $(EXEC)