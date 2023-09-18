// Universidad de La Laguna
// Escuela Superior de Ingenier´ıa y Tecnolog´ıa
// Grado en Ingenier´ıa Inform´atica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Contenedores asociativos
// Autor: Alba Pérez Rodríguez
// Correo: alu0101513768@ull.edu.es
// Fecha: 14/09/2023
// Archivo Estudiantes.cc: 
// Contiene las funciones de la clase Estudiantes. 
// La función usage que muestra el funcionamiento por pantalla si se introducen mal los parámetros
// El constructor por defecto sin parámetros. El constructor por parámetros que recibe el fichero
// de entrada, lo abre y almacena los valores en el map. Y por último la función que se encarga de 
// de mostrar por pantalla.
// Historial de revisiones:
// 13/09/2023 - Creación (primera versión) del código. Creación de la función usage
// 14/09/2023 - Modificación del código. Creación del constructor y resto de funciones
// 15/09/2023 - Finalización del código con la total documentación

#include "Estudiantes.h"

/**
 * @brief Función que muestra el funcionamiento del programa si no se realiza de forma correcta
 * @param argc cantidad de argumentos pasados al programa desde la línea de comandos, incluyendo el nombre del propio programa como el primer argumento.
 * @param argv posicion de los argumentos pasados al programa.  
 */
void Usage(int argc, char* argv[]) {
  if (argc == 1 || (argc == 2 && std::string(argv[1]) == "--help")) {
    std::cout << "Modo de empleo: " << argv[0] << " grades.txt" << std::endl;
    if (argc == 1) {
        std::cout << "Pruebe con '" << argv[0] << " --help' para más información" << std::endl;
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
  } else if (argc != 2) {
    std::cout << "Pruebe con '" << argv[0] << " --help' para más información" << std::endl;
    exit(EXIT_FAILURE);
  }
}

/**
 * @brief Constructor por defecto sin parámetros
 */
Estudiantes::Estudiantes() {}

/**
 * @brief Constructor por parámetros
 * Constructor que abre el fichero y almacena los valores en el multimapmap
 * @param fichero fichero a abrir, en el que se encuentran los allus y sus notas.
 */
Estudiantes::Estudiantes(std::ifstream& fichero) {
  if (!fichero.is_open()) { // si no se abrió el fichero
    std::cerr << "No se pudo abrir el archivo " << std::endl;
    exit(EXIT_FAILURE);
  }    
  while (!fichero.eof()) { // lectura linea a linea
    std::string linea; 
    std::getline(fichero, linea);
    std::string alu_estudiante;
    double nota_estudiante;
    std::stringstream estudiante{linea};
    estudiante >> alu_estudiante >> nota_estudiante; 
    estudiantes_.insert(std::pair<std::string, double>(alu_estudiante, nota_estudiante));
  }
  fichero.close(); // al llegar al final lo cerramos
}

/**
 * @brief Inserta un estudiante con su calificación en el mapa de estudiantes.
 * Esta función inserta un estudiante junto con su calificación en el mapa de estudiantes.
 * Si el estudiante ya existe en el mapa, no se realiza ninguna acción, manteniendo
 * la calificación existente. Si el estudiante no existe, se inserta en el mapa con la
 * calificación proporcionada.
 * @param alu_estudiante Estudiante a insertar nota
 * @param nota_estudiante Nota a insertar
 */

void Estudiantes::InsertarEstudiante(const std::string& alu_estudiante, double nota_estudiante) {
  // Elimina los ceros iniciales del número de estudiante.
  // Busca el estudiante en el map.
    estudiantes_.insert(std::pair<std::string, double>(alu_estudiante, nota_estudiante));
}

/**
 * @brief Método que se encarga de mostrar las calificaciones de los e
 * studiantes de manera ordenada por alu.
 * Esta función recorre el multimap de estudiantes y muestra las calificaciones
 * de manera acumulativa para cada estudiante, separando las notas de estudiantes
 */
void Estudiantes::MostrarEstudiantes() {
  std::string alu_actual_estudiante = "";
  for (const auto& estudiante : GetEstudiantes()) {
    if (estudiante.first != alu_actual_estudiante) { // detectar cuando se pasa de un estudiante a otro
      std::cout << std::endl;
      std::cout << estudiante.first << ": " << estudiante.second; // imprime alu
    } else {
      std::cout << " " << estudiante.second;
    }
    alu_actual_estudiante = estudiante.first;
  }
  std::cout << std::endl;
}