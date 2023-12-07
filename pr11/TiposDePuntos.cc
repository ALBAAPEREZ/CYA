// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 11: 
// Autor: Alba Pérez Rodríguez
// Correo: alu0101513768@ull.edu.es
// Fecha: 05/12/2023
// Archivo TiposDePuntos.cc: contiene la implementación de los tipos de puntos
// Contiene la implementación de los tipos de puntos que se van a utilizar en la práctica 

#include "TiposDePuntos.h"

/**
 * @brief Sobrecarga del operador de salida para imprimir vectores de puntos
 * Se imprime el número de puntos y cada punto
 * @param os flujo de salida
 * @param vector_puntos  vector de puntos que queremos imprimir
 * @return std::ostream&  flujo de salida
 */
std::ostream& operator<<(std::ostream& os, const CyA::VectorDePuntos& vector_puntos) {
  // Imprimimos el número de puntos
  os << vector_puntos.size() << std::endl;
  for (const CyA::Punto& punto : vector_puntos) {
    os << punto << std::endl;
  }
  return os;
}

/**
 * @brief Sobrecarga del operador de salida para imprimir puntos
 * Se imprime el punto
 * @param os flujo de salida
 * @param punto punto que queremos imprimir
 * @return std::ostream&  flujo de salida
 */
std::ostream& operator<<(std::ostream& os, const CyA::Punto& punto) {
  // Imprimimos el punto
  os << std::setw(MAX_SZ) << std::fixed << std::setprecision(MAX_PREC)
     << punto.first << "\t" << std::setw(MAX_SZ) << std::fixed
     << std::setprecision(MAX_PREC) << punto.second;
  return os;
}

/**
 * @brief Sobrecarga del operador de entrada para leer vectores de puntos
 * Se lee el número de puntos y cada punto, se añaden al vector de puntos
 * @param is flujo de entrada
 * @param vector_puntos vector de puntos que queremos leer
 * @return std::istream& flujo de entrada
 */
std::istream& operator>>(std::istream& is, CyA::VectorDePuntos& vector_puntos) {
  int n;
  is >> n;
  vector_puntos.clear();
  // recorremos el vector de puntos para leer cada punto y añadirlo al vector
  for (int i = 0; i < n; ++i) {
    CyA::Punto punto;
    is >> punto;
    vector_puntos.emplace_back(punto);
  }
  return is;
}

/**
 * @brief Sobreacarga del operador de entrada para leer puntos
 * Se lee el punto y se devuelve el flujo de entrada
 * @param is flujo de entrada
 * @param punto punto que queremos leer
 * @return std::istream& flujo de entrada
 */
std::istream& operator>>(std::istream& is, CyA::Punto& punto) {
  is >> punto.first >> punto.second;
  return is;
}