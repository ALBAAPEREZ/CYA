// Universidad de La Laguna
// Escuela Superior de Ingenier´ıa y Tecnolog´ıa
// Grado en Ingenier´ıa Inform´atica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Contenedores asociativos
// Autor: Alba Pérez Rodríguez
// Correo: alu0101513768@ull.edu.es
// Fecha: 14/09/2023
// Archivo Estudiantes.h: 
// Contiene la clase Estudiantes en la que tenemos como atributi privado el contenedor map
// en el que almacenaremos por pares los estudiantes. Tendremos tanto el alu como la nota
// de cada estudiante. 
// Como métodos públicos disponemos del constructor por defecto, por parámetros al que se
// se le pasa el fichero para abrirlo y el propio getter del map.
// Historial de revisiones:
// 13/09/2023 - Creación (primera versión) del código. Se realizo la función usage y la clase.
// 14/09/2023 - Desarrollo de los métodos de la clase 
// 15/09/2023 - Finalización del código con la documentacion de este.

#ifndef NOTAS_H
#define NOTAS_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <sstream>

/**
 * @brief Clase Estudiante con atributos privados: 
 * el contenedor map para almacenar ambos valores (alu único y nota)
 * Constructor por defecto. Constructor de la clase denominado de la misma manera que esta.
 * Getter para acceder al map privado y método para mostrar por pantalla
 */
class Estudiantes {
 public:
  Estudiantes();
  Estudiantes(std::ifstream& fichero); // Constructor
  std::map<std::string, double> GetEstudiantes() const { return estudiantes_;}
  void MostrarEstudiantes();
  void InsertarEstudiante(const std::string& alu_estudiante, double nota_estudiante);

 private: 
  std::map<std::string, double> estudiantes_;
};

void Usage(int argc, char *argv[]);

#endif // NOTAS_H