// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 9: Simulacion de Máquinas de Turing
// Autor: Alba Pérez Rodríguez
// Correo: alu0101513768@ull.edu.es
// Fecha: 14/11/2023
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
#include "Estado.h"
#include "Cinta.h"
#include "Maquina_Turing.h"

/**
 * @brief Función que muestra el funcionamiento del programa si no se realiza de
 * forma correcta
 * @param argc cantidad de argumentos pasados al programa desde la línea de
 * comandos, incluyendo el nombre del propio programa como el primer argumento.
 * @param argv posicion de los argumentos pasados al programa.
 */
void Usage(int argc, char* argv[]) {
  if (argc == 1 || (argc == 2 && std::string(argv[1]) == "--help")) {
    std::cout << "Modo de empleo: " << argv[0] << " input.tm input.tape" << std::endl;
    if (argc == 1) {
      std::cout << "Pruebe con '" << argv[0] << " '--help' para más información" << std::endl;
    } else {
      std::cout << "Funcionalidades del programa:" << std::endl;
      std::cout << " Este programa consistirá en la realización de un programa que lea desde" << std::endl;
      std::cout << " un fichero las especificaciones de una máquina de turing, simule el " << std::endl;
      std::cout << " comportamiento de la máquina." << std::endl;
      std::cout << std::endl;
      std::cout << "El programa recibirá como argumentos de entrada el nombre de dos fichero" << std::endl;
      std::cout << "Línea 1: entero indicando el número de estados de la máquina." << std::endl;
      std::cout << "Línea 2: entero indicando el estado de arranque." << std::endl;
      std::cout << "Línea 3: enteros separados por espacios en blanco indicando qué estados de la máquina son finales o de aceptación." << std::endl;
      std::cout << "Línea 4: entero indicando el número de tuplas que componen la máquina." << std::endl;
      std::cout << "Líneas sucesivas: una tupla en cada línea. Los elementos de cada tupla vendrán separados por espacios en blanco " << std::endl;
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
 * Luego, simula la máquina de turing y muestra los resultados.
 * @return int devuelve 0 si el programa se ejecuto con exito
 */
int main(int argc, char* argv[]) {
  Usage(argc, argv);
  std::string nombre_fichero_turing = argv[1], nombre_fichero_cinta = argv[2];
  MaquinaTuring maquina_turing{nombre_fichero_turing, nombre_fichero_cinta};
  char opcion;
  std::cout << "¿Desea ver la Maquina de Turing? (s/n) ";
  std::cin >> opcion;
  if (opcion == 's' || opcion == 'S') {
    std::cout << maquina_turing << std::endl;
  }
  maquina_turing.EsAceptada();
  return 0;
}