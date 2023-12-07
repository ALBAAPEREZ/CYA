// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 11: 
// Autor: Alba Pérez Rodríguez
// Correo: alu0101513768@ull.edu.es
// Fecha: 05/12/2023
// Archivo main.cc : contiene el programa principal
// Contiene el programa principal.

#include <iostream>
#include <fstream>
#include <string>

#include "SetPuntos.h"
#include "SubArbol.h"
#include "TiposDePuntos.h"


/**
 * @brief Funcion principal del programa
 * Funcion principal del programa, que lee un fichero de texto con un conjunto de puntos
 * @param argc numero de argumentos
 * @param argv argumentos
 * @return int retorna 0 si se ha ejecutado correctamente
 */
int main(int argc, char* argv[]) {
  std::ifstream file(argv[1]);
  if (!file) {
    std::cerr << "Error: El fichero no existe." << std::endl;
    return 0;
  }
  int numero_puntos;
  file >> numero_puntos;
  CyA::VectorDePuntos puntos;
  // Leemos los puntos del fichero
  for (int i = 0; i < numero_puntos; ++i) {
    double x, y;
    file >> x >> y;
    CyA::Punto punto(x, y);
    puntos.push_back(punto);
  }
  file.close();
  // Creamos un objeto de la clase SetPuntos
  std::ofstream file_out("EMST.txt");
  SetPuntos set_puntos(puntos);
  /*set_puntos.EMST();
  set_puntos.MostrarArbol(file_out);
  file_out.close();
  */
  // set_puntos.MostrarArbol(file_out);
  // Mostrar el coste según la distancia seleccionada
  if (std::string(argv[2]) == "1") {
    std::cout << "Coste utilizando distancia Manhattan: " << std::endl;
    set_puntos.MostrarManhattan(file_out);
  } else {
    std::cout << "Coste utilizando distancia Euclidiana: " << std::endl;
    set_puntos.MostrarArbol(file_out);
  }
  file_out.close();
  return 0;
}

