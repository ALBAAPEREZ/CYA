// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 11: 
// Autor: Alba Pérez Rodríguez
// Correo: alu0101513768@ull.edu.es
// Fecha: 05/12/2023
// Archivo TiposDePuntos.h: contiene la declaración de los tipos de puntos
// Contiene la declaración de los tipos de puntos que se van a utilizar en la práctica

#pragma once

#include <iostream>
#include <set>
#include <utility>
#include <vector>
#include <iomanip>

#define MAX_SZ 3
#define MAX_PREC 0

/**
 * @brief Namespace para la asignatura Computabilidad y Algoritmia
 */
namespace CyA {
  // Declaración adelanta de los tipos de puntos
  typedef std::pair<double, double> Punto;
  // Declaración adelantada de los tipos de líneas
  typedef std::pair<Punto, Punto> Linea;
  // Declaración adelantada de los tipos de líneas ponderadas
  typedef std::vector<Punto> VectorDePuntos;
  // Declaración adelantada de los tipos de arcos
  typedef std::pair<Punto, Punto> Arco;
  typedef std::pair<double, Arco> ArcoPonderado;
  typedef std::vector<ArcoPonderado> ArcosPonderados;
  // Declaración adelantada de los tipos de colecciones de puntos
  typedef std::set<Punto> ColeccionDePuntos;
  typedef std::vector<Arco> Arbol;
}  // namespace CyA

// Sobrecarga de operadores '<<' y '>>' para poder imprimir y leer vectores de puntos
std::ostream& operator<<(std::ostream& os, const CyA::VectorDePuntos& vector_puntos);
std::istream& operator>>(std::istream& is, CyA::VectorDePuntos& vector_puntos);

// Sobrecarga de operadores '<<' y '>>' para poder imprimir y leer puntos
std::ostream& operator<<(std::ostream& os, const CyA::Punto& punto);
std::istream& operator>>(std::istream& is, CyA::Punto& punto);