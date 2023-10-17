// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 5: Simulación de autómatas finitos
// Autor: Alba Pérez Rodríguez
// Correo: alu0101513768@ull.edu.es
// Fecha: 14/10/2023
// Archivo Automata.h:
// Contiene la clase Automata, que representa un autómata finito. 
// Continene 3 constructores, uno por parámetros, otro por defecto y otro que genera el autómata a partir de un fichero de entrada.
// De 3 atributos privados y sus respectivos getters.
// El conjunto de estados será de tipo set y almacenará los estados del autómata.
// El estado de arranque será de tipo Estado y almacenará el estado de arranque del autómata.
// El número de estados será de tipo int y almacenará el número de estados del autómata.
// Las transiciones serán de tipo multimap y almacenaran el símbolo y el estado siguiente
// Historial de revisiones:
//  13/10/2023 --> comienzo de la práctica. Creación (primera versión) del código.
//  Creación de la clase Estado .h y su implementación en el .cc
//  14/10/2023 --> Creación de la clase Autómata y su desarrollo en el .cc
//  15/10/2023 --> Desarrollo del código de la clase Autómata. Método EsAceptado y método ImprimirCadena.
//  16/10/2023 --> Corrección del código y finalización de la práctica.

#ifndef AUTOMATA_H
#define AUTOMATA_H

#include <iostream>
#include <set>

#include "Estado.h"
#include "Simbolo.h"
#include "Alfabeto.h"
/**
 * @brief Clase automata para representar un autómata finito.
 * Consta de tres constructores, uno por parámetros, otro por defecto y otro que genera el autómata a partir de un fichero de entrada.
 * De 3 atributos privados y sus respectivos getters. 
 * El conjunto de estados será de tipo set y almacenará los estados del autómata.
 * El estado de arranque será de tipo Estado y almacenará el estado de arranque del autómata.
 * El número de estados será de tipo int y almacenará el número de estados del autómata.
 * Las transiciones serán de tipo multimap y almacenaran el símbolo y el estado siguiente
 */
class Automata {
 public:
  // Constructor por parámetros
  Automata(std::map<int, Estado> estados, Estado estado_arranque, int numero_estados) : estados_{estados}, estado_arranque_{estado_arranque}, numero_estados_{numero_estados} {}
  // constructor que genere automata a partir del fichero
  Automata(std::ifstream& fichero_entrada);
  Automata() {}
  // Getters
  std::map<int, Estado> GetEstados() const { return estados_; }
  Estado GetEstadoArranque() const { return estado_arranque_; }
  int GetNumeroEstados() const { return numero_estados_; }
  // Sobrecarga de operadores de entrada y salida
  friend std::istream& operator>>(std::istream& is, Automata& automata);
  friend std::ostream& operator<<(std::ostream& output, const Automata& automata);
  // Sobrecarga de operadores
  bool operator==(const Automata& otro_automata) const;
  bool operator<(const Automata& otro_automata) const;
  // Método que dice que una cadena es aceptada o no por el autómata 
  bool EsAceptado(Cadena& cadena, Estado& estado, size_t iterador);
  // Método que imprime la cadena y dice si es aceptada o no por el autómata
  void ImprimirCadena(Cadena& cadena);
 private: 
  std::map<int, Estado> estados_;  // identificador -> estado
  Estado estado_arranque_;
  int numero_estados_;
};

#endif // AUTOMATA_H