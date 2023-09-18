// Universidad de La Laguna
// Escuela Superior de Ingenier´ıa y Tecnolog´ıa
// Grado en Ingenier´ıa Inform´atica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Contenedores asociativos
// Autor: Alba Pérez Rodríguez
// Correo: alu0101513768@ull.edu.es
// Fecha: 14/09/2023
// Archivo ClienteEstudiantes.cc: 
// Contiene la función main del proyecto que usa la clase estudiantes. 
// Toma argumentos de línea de comandos para abrir un archivo de entrada
// y crea un objeto Estudiantes para procesar y mostrar información sobre los estudiantes.
// Tiene un menú que sirve para añadir nuevos usuarios o modificar ya los existente, 
// ademas de poder visualizar las notas de todos
// Historial de revisiones
// 13/09/2023 - Creación (primera versión) del código. 
// 14/09/2023 - Modificación del código. Corrección del main para que funcione correctamente
// 15/09/2023 - Finalización del código con la completa documentación.

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>

#include "Estudiantes.h"

/**
 * @brief Función principal main. Toma argumentos de línea de comandos
 * para abrir un archivo de entrada y crea un objeto Estudiantes para procesar y mostrar
 * información sobre los estudiantes.
 * @param argc Cantidad de argumentos de línea de comandos.
 * @param argv ector de cadenas que contiene los argumentos de línea de comandos.
 *             El primer argumento (argv[0]) es el nombre del programa.
 *             El segundo argumento (argv[1]) debe ser el nombre del archivo de entrada.
 * @return int, 0 si el programa se ejecuta con éxito.
 */
int main(int argc, char *argv[]) {
  Usage(argc, argv); // funcion de uso
  std::string fichero_entrada(argv[1]);
  std::ifstream fichero;  
  fichero.open(fichero_entrada, std::ios::in);
  Estudiantes estudiantes{fichero};
  // menú de opciones
  while (true) {
    std::cout << std::endl;
    std::cout << "Seleccione una opción:" << std::endl;
    std::cout << "1. Mostrar calificaciones" << std::endl;
    std::cout << "2. Insertar estudiante y calificación" << std::endl;
    std::cout << "3. Mostrar estado final de las calificaciones" << std::endl;
    std::cout << "4. Salir" << std::endl;

    char opcion;
    std::cin >> opcion;
    switch (opcion) {
      case '1': // mostrar calificaciones ordenadas alfabeticamente
        estudiantes.MostrarEstudiantes();
        break;
      case '2': { // aladir nuevo alu o actualizar la nota del ya existente
        std::string alu_estudiante;
        double nota_estudiante;
        std::cout << "Ingrese el nombre del estudiante: ";
        std::cin >> alu_estudiante;
        std::cout << "Ingrese la calificación: ";
        std::cin >> nota_estudiante;
        estudiantes.InsertarEstudiante(alu_estudiante, nota_estudiante);
        break;
      }
      case '3': // mostrar notas finales
        estudiantes.MostrarEstudiantes();
        break;
      case '4': // salir del programa
        return 0;
      default:
        std::cout << "Opción no válida. Intente de nuevo." << std::endl;
    }
  }
  return 0;
}
