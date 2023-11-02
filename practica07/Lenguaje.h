// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Algoritmo de construccion de subconjuntos
// Autor: Alba Pérez Rodríguez
// Correo: alu0101513768@ull.edu.es
// Fecha: 14/10/2023
// Archivo Lenguaje.h:
// Contiene la clase Lenguaje para representar un lenguaje.
// Consta de dos constructores, uno por parámetros y otro por defecto.
// De un atributo privado y su respectivo getter.
// El lenguaje será de tipo set y almacenará las cadenas del lenguaje.
// Además contiene la definicion de los métodos a implementar y la sobrecarga de entrada y salida.
// Por último encontramos la sobrecarga de == y < que nos servirán para comparar lenguajes
// Historial de revisiones:
//  13/10/2023 --> comienzo de la práctica. Creación (primera versión) del código.
//  Creación de la clase Estado .h y su implementación en el .cc
//  14/10/2023 --> Creación de la clase Autómata y su desarrollo en el .cc
//  15/10/2023 --> Desarrollo del código de la clase Autómata. Método EsAceptado y método ImprimirCadena.
//  16/10/2023 --> Corrección del código y finalización de la práctica.

#ifndef LENGUAJE_H
#define LENGUAJE_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <set>
#include <sstream>

#include "Simbolo.h"
#include "Cadena.h"

class Cadena; // Definición de la clase Cadena

/**
 * @brief Clase Leguaje.
 * Esta clase contiene tanto el constructor por defecto como el que contiene parámetros
 * Encontramos un getter que se encarga de devolver los valores de set de cadenas
 * Un método denominado cardinal que devuelve el tamaño del lenguaje y por último,
 * una función de sobrecarga para imprimir el lenguaje
 */
class Lenguaje {
 public:
  Lenguaje();
  Lenguaje(std::set<Cadena> lenguaje) : lenguaje_{lenguaje} {}
  std::set<Cadena> GetLenguaje() const { return lenguaje_; }
  int Cardinal() const;   
  friend std::ostream& operator<<(std::ostream& out, const Lenguaje& lenguaje);
 private:
  std::set<Cadena> lenguaje_;
};

// Defincion de la sobrecarga de operadores
std::ostream& operator<<(std::ostream& out, const Lenguaje& lenguaje);

#endif // LENGUAJE_H