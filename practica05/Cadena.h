// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 5: Simulación de autómatas finitos
// Autor: Alba Pérez Rodríguez
// Correo: alu0101513768@ull.edu.es
// Fecha: 14/10/2023
// Archivo Cadena.h:
// Contiene la clase Cadena, que representa una cadena de símbolos.
// Consta de tres constructores, uno por parámetros, otro por defecto y otro que genera la cadena a partir de una cadena de texto.
// De 1 atributo privado y su respectivo getter.
// El atributo cadena_ será de tipo vector y almacenará los símbolos de la cadena.
// Además contiene la definicion de los métodos a implementar y la sobrecarga de entrada y salida.
// Por último encontramos la sobrecarga de == y < que nos servirán para comparar cadenas
// Historial de revisiones:
//  13/10/2023 --> comienzo de la práctica. Creación (primera versión) del código.
//  Creación de la clase Estado .h y su implementación en el .cc
//  14/10/2023 --> Creación de la clase Autómata y su desarrollo en el .cc
//  15/10/2023 --> Desarrollo del código de la clase Autómata. Método EsAceptado y método ImprimirCadena.
//  16/10/2023 --> Corrección del código y finalización de la práctica.

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
  Simbolo GetSimbolo(int posicion) const { return cadena_[posicion]; }
  int Longitud();
  Cadena Inversa();
  Lenguaje Prefijos();
  Lenguaje Sufijos();
  friend std::istream& operator>>(std::istream& is, Simbolo& cadena);
  friend std::ostream& operator<<(std::ostream& os, const Cadena& cadena);
  bool operator==(const Cadena& otra_cadena) const;
  bool operator<(const Cadena& otra_cadena) const;
  // MOdificación
  Lenguaje PotenciaCuboCadena();
 private: 
  std::vector<Simbolo> cadena_;
};

// Definición de la sobrecarga de extraccion e inserccion
std::istream& operator>>(std::istream& is, Simbolo& cadena);
std::ostream& operator<<(std::ostream& os, const Cadena& cadena);

#endif // CADENA_H