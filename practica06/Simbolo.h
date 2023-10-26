// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Algoritmo de construccion de subconjuntos
// Autor: Alba Pérez Rodríguez
// Correo: alu0101513768@ull.edu.es
// Fecha: 14/10/2023
// Archivo Simbolo.h:
// Contiene la clase Simbolo. Esta clase representa un símbolo, que es un carácter individual.
// Proporciona funcionalidad para obtener y comparar símbolos.
// Contiene el constructor tanto por defecto como por parámetros.
// El getter que obtiene el atributo privado de la clase y la sobrecarga de operadores
// para la ordenación de los simbolos en cadenas.
// Historial de revisiones:
//  13/10/2023 --> comienzo de la práctica. Creación (primera versión) del código.
//  Creación de la clase Estado .h y su implementación en el .cc
//  14/10/2023 --> Creación de la clase Autómata y su desarrollo en el .cc
//  15/10/2023 --> Desarrollo del código de la clase Autómata. Método EsAceptado y método ImprimirCadena.
//  16/10/2023 --> Corrección del código y finalización de la práctica.

#ifndef SIMBOLO_H
#define SIMBOLO_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>

/**
 * @brief Clase Simbolo. Esta clase representa un símbolo, que es un carácter individual.
 * Proporciona funcionalidad para obtener y comparar símbolos.
 * Contiene el constructor tanto por defecto como por parámetros.
 * El getter que obtiene el atributo privado de la clase y la sobrecarga de operadores
 * para la ordenación de los simbolos en cadenas. 
 */
class Simbolo {
 public:
  Simbolo(); // Constructor por defecto
  Simbolo(std::string simbolo) : simbolo_{simbolo} {} 
  std::string GetSimbolo() const { return simbolo_; } // Getter
  // Sobrecarga de operadores de entrada y salida
  friend std::istream& operator>>(std::istream& input, Simbolo& simbolo);
  friend std::ostream& operator<<(std::ostream& output, const Simbolo& simbolo);
  // Sobrecarga de operador == y < para la ordenación de cadenas
  bool operator==(const Simbolo& otro_simbolo) const;
  bool operator<(const Simbolo& otro_simbolo) const;

 private:
  std::string simbolo_; //atributo privados
};

// Definición de la sobrecarga de extracción e insercción
std::istream& operator>>(std::istream& input, Simbolo& simbolo);
std::ostream& operator<<(std::ostream& output, const Simbolo& simbolo);

#endif // SIMBOLO_H