// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con cadenas
// Autor: Alba Pérez Rodríguez
// Correo: alu0101513768@ull.edu.es
// Fecha: 22/09/2023
// Archivo Cadena.h: 
// Contiene la clase Cadena. Se define el atributo privado cadena como vector de simbolos
// Además contiene tanto el constructor por parámetros como el sin parámetros. 
// A esto, le siguen los getter, uno que devuelve la cadena y otro que devuelve el tamaño de la cadena
// Tenemos un setter para modificar los valores de la cadena actual.
// Disponemos de la definción de todos los métodos a implementar (longitud, inversa, prefijo y sufijo)
// Por último tenemos la sobrecarga de funciones de entrada y salida que ayudarán al imprimir las cadenas
// Historial de revisiones:
// 22/09/23 - Creación (primera versión) del código. Creación de la función usage y clases
// 23/09/23 - Realización de la implementacion de los metodos de las
// clases, asi como las funciones de inversa y longitud. Implementacion
// del main para poder ir probando si funciona 
// 24/09/23 - Realización de las funciones Sufijo y prefijo de la clase cadena
// 25/09/23 - Correción de errores y finalización del main para correcto funcionamiento.
// Finalización de toda la correcta identacion y comentarios.

#ifndef CADENA_H
#define CADENA_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <algorithm>

#include "Simbolo.h"
#include "Lenguaje.h"

class Lenguaje; // Definición de la clase Lenguaje que usará cadenas

/**
 * @brief Clase Cadena.
 * Contiene el constructor sin parámetros, con parámetros y el que sirve para crear un objeto 
 * Cadena a partir de una cadena de texto (std::string). 
 * Getter que accede al atributo privado cadena_, un getter que obtiene el tamaño de la cadena
 * y un setter para modificar su valor.
 * Además contiene la definicion de los métodos a implementar y la sobrecarga de entrada y salida.
 * Por último encontramos la sobrecarga de == y < que nos servirán para comparar cadenas
 */
class Cadena {
 public:
  Cadena(); // Constructor
  Cadena(std::vector<Simbolo> cadena) : cadena_{cadena} {} 
  Cadena(std::string cadena);
  std::vector<Simbolo> GetCadena() const { return cadena_; }
  size_t GetSize() const { return cadena_.size(); } 
  Cadena SetCadena(const Simbolo& simbolo);
  int Longitud();
  Cadena Inversa();
  Lenguaje Prefijos();
  Lenguaje Sufijos();
  friend std::istream& operator>>(std::istream& is, Simbolo& cadena);
  friend std::ostream& operator<<(std::ostream& os, const Cadena& cadena);
  bool operator==(const Cadena& otra_cadena) const;
  bool operator<(const Cadena& otra_cadena) const;
 private: 
  std::vector<Simbolo> cadena_;
};

// Definición de la sobrecarga de extraccion e inserccion
std::istream& operator>>(std::istream& is, Simbolo& cadena);
std::ostream& operator<<(std::ostream& os, const Cadena& cadena);

#endif // CADENA_H