// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con cadenas
// Autor: Alba Pérez Rodríguez
// Correo: alu0101513768@ull.edu.es
// Fecha: 22/09/2023
// Archivo Simbolo.cc: 
// Contiene la implementación de todos los métodos de la clase simbolo.
// Lo constituyen los constructores y la sobrecarga de los operadores << y >>, 
// así como la sobrecarga de == y < para la comparación en cadenas y su ordenación
// Historial de revisiones:
// 22/09/23 - Creación (primera versión) del código. Creación de la función usage y clases
// 23/09/23 - Realización de la implementacion de los metodos de las
// clases, asi como las funciones de inversa y longitud. Implementacion
// del main para poder ir probando si funciona 
// 24/09/23 - Realización de las funciones Sufijo y prefijo de la clase cadena
// 25/09/23 - Correción de errores y finalización del main para correcto funcionamiento.
// Finalización de toda la correcta identacion y comentarios./*+

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