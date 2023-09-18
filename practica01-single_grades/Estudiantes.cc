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
// de entrada, lo abre y almacena los valores en el map. Seguidamente tenemos una función que se encarga 
// de añadir nuevos usuarios o ver si ya existen. Y por último la función que se encarga de 
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
 * Constructor que abre el fichero y almacena los valores en el map
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
    // si el alu_estudiantes no ha llegado al final --> está en el map. Y si la nota del alu_estudiante es menor a la nota que acabamos de leer
    if (GetEstudiantes().find(alu_estudiante) != GetEstudiantes().end() && GetEstudiantes()[alu_estudiante] < nota_estudiante) { 
      estudiantes_[alu_estudiante] = nota_estudiante;
    } else { // Si no está el alu en el map --> lo insertamos 
      estudiantes_.insert(std::pair<std::string, double>(alu_estudiante, nota_estudiante)); // insertamos el alu y la nota en el map
    }
  }
  fichero.close(); // al llegar al final lo cerramos
}

/**
 * @brief  Inserta un estudiante y su calificación en el mapa de estudiantes.
 * Si el estudiante ya existe en el mapa, actualiza su calificación.
 * @param alu_estudiante  Nombre del estudiante.
 * @param nota_estudiante Clificacion del estudiante
 */
void Estudiantes::InsertarEstudiante(const std::string& alu_estudiante, double nota_estudiante) {
  // Elimina los ceros iniciales del nombre del estudiante antes de buscar en el mapa.
  std::string alu_sin_ceros = alu_estudiante;
  alu_sin_ceros.erase(0, alu_sin_ceros.find_first_not_of('0'));
  // para encontrar el primer carácter diferente de '0'
  auto estudiante_nuevo = estudiantes_.find(alu_sin_ceros);
  if (estudiante_nuevo != estudiantes_.end()) {
    std::cout << "El estudiante ya existe. Actualiza la calificación. " << std::endl;
    estudiante_nuevo->second = nota_estudiante; // si el estudiante ya existe actualiza la nota
  } else { // sino se rellena como nuevo
    estudiantes_.insert(std::pair<std::string, double>(alu_sin_ceros, nota_estudiante));
  }
}

/**
 * @brief Función que muestra por pantalla los alumnos y sus notas.
 */
void Estudiantes::MostrarEstudiantes() {
  for (const auto& estudiante : GetEstudiantes()) {
    std::cout << estudiante.first <<  " " << estudiante.second << std::endl;
  }
}






