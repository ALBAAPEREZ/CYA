// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 5: Simulación de autómatas finitos
// Autor: Alba Pérez Rodríguez
// Correo: alu0101513768@ull.edu.es
// Fecha: 14/10/2023
// Archivo Estado.h:
// Contiene la clase Estado para representar un estado en un autómata finito.
// Consta de dos constructores, uno por parámetros y otro por defecto.
// De 4 atributos privados y sus respectivos getters.
// Las transiciones serán de tipo multimap y almacenaran el símbolo y el estado siguiente
// El identificador será de tipo int y almacenará el identificador del estado.
// El booleano aceptado será de tipo bool y almacenará si el estado es de aceptación o no.
// El número de estados será de tipo int y almacenará el número de estados del autómata.
// Historial de revisiones:
//  13/10/2023 --> comienzo de la práctica. Creación (primera versión) del código.
//  Creación de la clase Estado .h y su implementación en el .cc
//  14/10/2023 --> Creación de la clase Autómata y su desarrollo en el .cc
//  15/10/2023 --> Desarrollo del código de la clase Autómata. Método EsAceptado y método ImprimirCadena.
//  16/10/2023 --> Corrección del código y finalización de la práctica.

#ifndef ESTADO_H
#define ESTADO_H

#include <map>
#include <string>
#include "Simbolo.h"

/**
 * @brief Clase Estado para representar un estado en un autómata finito.
 * Consta de dos constructores, uno por parámetros y otro por defecto. 
 * De 4 atributos privados y sus respectivos getters.
 * Las transiciones serán de tipo multimap y almacenaran el símbolo y el estado siguiente
 * El identificador será de tipo int y almacenará el identificador del estado.
 * El booleano aceptado será de tipo bool y almacenará si el estado es de aceptación o no.
 * El número de estados será de tipo int y almacenará el número de estados del autómata.
 */
class Estado {
 public:
  // Constructor por parámetros
  Estado(int identificador, bool aceptado) : identificador_{identificador}, aceptado_{aceptado} {}
  Estado() {}
  //Getters
  int GetIdentificador() const { return identificador_; }
  bool GetAceptado() const { return aceptado_; }
  std::multimap<Simbolo, Estado> GetEstadosSiguientes() const { return transiciones_; }
  void AgregarTransicion(Simbolo simbolo, Estado estado);
  // Sobrecarga de operadores de entrada y salida
  friend std::istream& operator>>(std::istream& input, Estado& estado);
  friend std::ostream& operator<<(std::ostream& output, const Estado& estado);
  // Sobrecarga de operadores 
  Estado operator=(const Estado& otro_estado);
  bool operator==(const Estado& otro_estado) const;
  bool operator<(const Estado& otro_estado) const;
 private:
  int identificador_;
  bool aceptado_;
  std::multimap<Simbolo, Estado> transiciones_;  // Mapa de transiciones (símbolo -> estado siguiente)
};

#endif //ESTADO_H