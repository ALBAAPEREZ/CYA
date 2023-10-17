// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 5: Simulación de autómatas finitos
// Autor: Alba Pérez Rodríguez
// Correo: alu0101513768@ull.edu.es
// Fecha: 14/10/2023
// Archivo Cliente.cc:
// Contiene la función principal main donde se abren los ficheros de entrada del programa
// La función Usage que muestra el funcionamiento del programa si no se realiza de forma correcta
// Se abren dos archivos pasados como argumentos en la línea de comandos, uno conteniendo la definición de un autómata finito y el otro conteniendo cadenas a simular.
// Luego, simula el autómata con las cadenas y muestra los resultados.
// Historial de revisiones:
// 13/10/2023 --> comienzo de la práctica. Creación (primera versión) del código.
// Creación de la clase Estado .h y su implementación en el .cc
// 14/10/2023 --> Creación de la clase Autómata y su desarrollo en el .cc
// 15/10/2023 --> Desarrollo del código de la clase Autómata. Método EsAceptado y método ImprimirCadena.
// 16/10/2023 --> Corrección del código y finalización de la práctica.

#include <iostream>
#include <sstream>
#include <fstream>

#include "Alfabeto.h"
#include "Cadena.h"
#include "Lenguaje.h"
#include "Simbolo.h"
#include "Estado.h"
#include "Automata.h"

/**
 * @brief Función que muestra el funcionamiento del programa si no se realiza de
 * forma correcta
 * @param argc cantidad de argumentos pasados al programa desde la línea de
 * comandos, incluyendo el nombre del propio programa como el primer argumento.
 * @param argv posicion de los argumentos pasados al programa.
 */
void Usage(int argc, char* argv[]) {
  if (argc == 1 || (argc == 2 && std::string(argv[1]) == "--help")) {
    std::cout << "Modo de empleo: " << argv[0] << " input.fa input.txt" << std::endl;
    if (argc == 1) {
      std::cout << "Pruebe con '" << argv[0] << " '--help' para más información" << std::endl;
    } else {
      std::cout << "Funcionalidades del programa:" << std::endl;
      std::cout << " Este programa consistirá en la realización de un programa que lea desde" << std::endl;
      std::cout << " un fichero las especificaciones de un autómata finito (FA) y, a continuación, simule el " << std::endl;
      std::cout << " comportamiento del autómata para una serie de cadenas que se suministren como entrada." << std::endl;
      std::cout << std::endl;
      std::cout << " El formato del fichero que contendrá la especificación del autómata es de la siguiente forma: " <<std::endl;
      std::cout << "Línea 1: Símbolos del alfabeto separados por espacios." << std::endl;
      std::cout << "Línea 2: Número total de estados del autómata." << std::endl;
      std::cout << "Línea 3: Estado de arranque del autómata." << std::endl;
      std::cout << "A continuación figurará una línea para cada uno de los estados. Cada línea contendrá los siguientes " << std::endl;
      std::cout << "números, separados entre sí por espacios en blanco:" << std::endl;
      std::cout << " - Número identificador del estado. Los estados del autómata se representarán " << std::endl;
      std::cout << "mediante números naturales. La numeración de los estados corresponderá a los primeros nímeros comenzando en 0." << std::endl;
      std::cout << " - Un 1 si se trata de un estado de aceptación y un 0 en caso contrario." << std::endl;
      std::cout << " - Número de transiciones que posee el estado." << std::endl;
      std::cout << " - Para cada una de las transiciones, y utilizando espacios en blanco como separadores: " << std::endl;
      std::cout << " -- Símmbolo de entrada necesario para que se produzca la transición. Para representar la cadena vacía --> &" << std::endl;
      std::cout << " -- Estado destino de la transición." << std::endl;
      std::cout << std::endl;

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
  std::string fichero_entrada_fa = argv[1];
  std::string fichero_entrada_cadenas = argv[2];
  std::ifstream entrada_fa, entrada_cadenas;
  entrada_fa.open(fichero_entrada_fa.c_str(), std::fstream::in);  // Abre los fichero que se pasan por linea de comandos
  entrada_cadenas.open(fichero_entrada_cadenas.c_str(), std::fstream::in);
  if (entrada_fa.fail()) {
    std::cout << "Error al abrir el fichero de entrada" << std::endl;
    exit(EXIT_FAILURE);
  }
  if (entrada_cadenas.fail()) {
    std::cout << "Error al abrir el fichero de entrada" << std::endl;
    exit(EXIT_FAILURE);
  }
  // Crea un objeto Automata a partir del archivo de definición
  Automata automata{entrada_fa};
  std::string cadena;
  // Lee las cadenas desde el archivo y las simula con el autómata
  while(std::getline(entrada_cadenas, cadena)) {
    Cadena cadena_aux{cadena};
    automata.ImprimirCadena(cadena_aux);
  }
  return 0;
}