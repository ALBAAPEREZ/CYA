// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Algoritmo de construccion de subconjuntos
// Autor: Alba Pérez Rodríguez
// Correo: alu0101513768@ull.edu.es
// Fecha: 22/10/2023
// Archivo Cliente.cc:
// Contiene la función principal main donde se abren los ficheros de entrada del programa
// La función Usage que muestra el funcionamiento del programa si no se realiza de forma correcta
// Se abren dos archivos pasados como argumentos en la línea de comandos, uno conteniendo la definición de un autómata finito y el otro conteniendo cadenas a simular.
// Luego, 
// Historial de revisiones:
// 22/10/2023 --> comienzo de la práctica. Creación (primera versión) del código.
//

#include <iostream>
#include <sstream>
#include <fstream>

#include "Alfabeto.h"
#include "Cadena.h"
#include "Lenguaje.h"
#include "Simbolo.h"
#include "Gramatica.h"


/**
 * @brief Función que muestra el funcionamiento del programa si no se realiza de
 * forma correcta
 * @param argc cantidad de argumentos pasados al programa desde la línea de
 * comandos, incluyendo el nombre del propio programa como el primer argumento.
 * @param argv posicion de los argumentos pasados al programa.
 */
void Usage(int argc, char* argv[]) {
  if (argc == 1 || (argc == 2 && std::string(argv[1]) == "--help")) {
    std::cout << "Modo de empleo: " << argv[0] << " input.gra output.gra" << std::endl;
    if (argc == 1) {
      std::cout << "Pruebe con '" << argv[0] << " '--help' para más información" << std::endl;
    } else {
      std::cout << "Este programa genera a partir de un fichero de entrada con la especificación " << std::endl;
      std::cout << "de una gramática libre de contexto, un fichero de salida con la misma gramática en forma normal de Chomsky." << std::endl;
    }
    exit(EXIT_SUCCESS);
  } else if (argc != 3) {
    std::cout << "Pruebe con '" << argv[0] << " '--help' para más información" << std::endl;
    exit(EXIT_FAILURE);
  }
}

/**
 * @brief Función principal main
 * @param argc cantidad de argumentos pasados al programa desde linea de comando
 * @param argv posicion de los argumentos pasados al programa
 * Esta función principal abre dos archivos pasados como argumentos en la línea de comandos,
 * uno conteniendo la definición de un autómata finito y el otro conteniendo cadenas a simular.
 * Luego, simula el autómata con las cadenas y muestra los resultados.
 * @return int devuelve 0 si el programa se ejecuto con exito
 */
int main(int argc, char* argv[]) {
  Usage(argc, argv);
  // nombre de los archivos de entrada
  std::string fichero_entrada = argv[1];
  std::string fichero_salida = argv[2];
  // crear gramatica a partir nombre de fichero
  Gramatica gramatica(fichero_entrada);
  gramatica.ConvertirAFormaNormalChomsky().ImprimirGramatica(fichero_salida);
  return 0;
}