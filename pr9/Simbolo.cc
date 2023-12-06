// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 9: Simulacion de Máquinas de Turing
// Autor: Alba Pérez Rodríguez
// Correo: alu0101513768@ull.edu.es
// Fecha: 14/11/2023
// Archivo Simbolo.cc:
// Contiene la implementación de los métodos de la clase Simbolo.
// El constructor por defecto y el constructor por parámetros.
// La sobrecarga de operadores de entrada y salida.
// La sobrecarga de operador == y < para la ordenación de cadenas.
// Historial de revisiones:
//  13/10/2023 --> comienzo de la práctica. Creación (primera versión) del código.
//  Creación de la clase Estado .h y su implementación en el .cc
//  14/10/2023 --> Creación de la clase Autómata y su desarrollo en el .cc
//  15/10/2023 --> Desarrollo del código de la clase Autómata. Método EsAceptado y método ImprimirCadena.
//  16/10/2023 --> Corrección del código y finalización de la práctica.

#include "Simbolo.h"

/**
 * @brief Construct a new Simbolo:: Simbolo object
 * Constructor sin parámetros
 */
Simbolo::Simbolo() {}

/**
 * @brief Sobrecarga del operador de entrada para la clase Simbolo.
 * Permite la lectura de un objeto Simbolo desde un flujo de entrada (istream).
 * @param is El flujo de entrada desde el cual se leerá el símbolo.
 * @param simbolo El objeto Simbolo en el cual se almacenará el carácter leído.
 * @return std::istream& flujo de entrada para permitir operaciones
 */
std::istream& operator>>(std::istream& is, Simbolo& simbolo) {
  is >> simbolo.simbolo_;
  return is;
}

/**
 * @brief Sobrecarga del operador de salida para la clase Simbolo.
 * Permite la escritura de un objeto Simbolo en un flujo de salida (ostream).
 * @param os El flujo de salida en el cual se escribirá el símbolo.
 * @param simbolo El objeto Simbolo que se escribirá en el flujo de salida.
 * @return La referencia al flujo de salida para permitir operaciones en cadena. 
 */
std::ostream& operator<<(std::ostream& os, const Simbolo& simbolo) {
  os << simbolo.simbolo_;
  return os;
}

/**
 * @brief Sobrecarga del operador ==
 * Servirá para la comparación de simbolos a la hora de ordenar cadenas
 * @param otro_simbolo otro simbolo a comparar
 * @return true si son iguales ambos simbolos
 * @return false si no son iguales los simbolos
 */
bool Simbolo::operator==(const Simbolo& otro_simbolo) const {
  const std::string caracter_auxiliar = GetSimbolo();
  return caracter_auxiliar == otro_simbolo.GetSimbolo();
}

/**
 * @brief Sobrecarga del operador <
 * Servirá para la comparación de símbolos a la hora de ordenar cadenas, saber si un elemento es
 * mayor o menor que otro.
 * @param otro_simbolo simbolo de la cadena a comparar
 * @return true si el simbolo dado es menor a otro
 * @return false si el simbolo dado es mayor a otro
 */
bool Simbolo::operator<(const Simbolo& otro_simbolo) const {
  const std::string caracter_auxiliar = GetSimbolo();
  return caracter_auxiliar < otro_simbolo.GetSimbolo();
}